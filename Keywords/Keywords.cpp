// Keywords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//1.Choice - Ability to pick what you want to do
//2.Anarchy - A state of no government control
//3.Quit - To give up, what you currently want to do
//4.Live - Not dead or inanimate
//5.Destroy - To take something that works and smash it until it is unable to function 
//6.Die - A state in the middle of life and death
//7.Fight - A violent confrontation to defend your beliefs
//8.Prom - High schools generally host this event
//9.Genuine - The real object and not a fake
//10.Triangle - An object with three angles

//libraries
#include "pch.h"
#include <iostream>
#include <string>
#include "pch.h"
#include <stdlib.h>
#include <stdio.h>   
#include <time.h>       
#include <cstdlib>
#include <ctime>


//shortcut commands
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{
	//give user information on how to play
	cout << "\t\t\tWelcome to the scrambler of words.\nWhere it is your job to take the words that i have scrambled and turn them into the original words. \nI wish you the best of luck!\n";
	cout << "If you are confused enter the word hint for a hint, although that is basically giving up!\n";
	cout << "If you feel like actually giving up type quit to be a sore loser.\n";

	//set the play to 3 times
	for (int i = 0; i < 3; i++) {
		// setup fot the variables of words and location within the fields
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		const string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			// words and hints for the jumbled game
			{"choice", "Ability to pick what you want to do."},
			{"anarchy", "A state of no government control."},
			{"quit", "To give up, what you currently want to do with this game."},
			{"live", "Not dead or inanimate."},
			{"destroy", "To take something that works and turn it into something that is non-workable anymore."},
			{"die", "A state in the middle of life and death."},
			{"fight", "A violent confrontation to defend ones beliefs."},
			{"prom", "High schools generally host these events."},
			{"genuine", "The real object and not a fake."},
			{"triangle", "An object with three angles."}
		};
		// setup the index for the words and hints
		int number = 0;
		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD];
		string theHint = WORDS[choice][HINT];
		// jumble the word
		string jumble = theWord;
		int length = jumble.size();
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		//player knows scrambled word
		cout << "\nYour word to unscramble is: " << jumble;

		//enter in the guess
		string guess;
		cout << "\n\nYour guess: ";
		cin >> guess;
		// setup to play the game if the word is incorrect and player has not quit
		while ((guess != theWord) && (guess != "quit"))
		{
			// show hint
			if (guess == "hint")
			{
				cout << theHint;
			}
			else
			{
				//tell them they are wrong
				cout << "Muahahahaha, you are wrong!";
			}
			cout << "\n\nYour guess: ";
			cin >> guess;
		}
		// show the user if they are right
		if (guess == theWord)
		{
			cout << "You have found the word congratulations.\n";
			number += 1;
			system("pause");

		}
		cout << "Thank you for playing\n";
		
	}
	//endgame
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
