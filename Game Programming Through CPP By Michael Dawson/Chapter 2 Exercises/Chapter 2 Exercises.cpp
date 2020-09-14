// Chapter 2 Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.

/**
* 1. Rewrite the Menu Chooser program from this chapter using an enumeration to represent difficulty levels. 
* The variable choice will still be of type int.
*/

// Menu Chooser
// Demonstrates the switch statement
#include <iostream>
#include <ctime>

using namespace std;
int playerChoice;

namespace difficulties {
	enum games {
		DIFFICULTYPICKER = 1,
		GUESSMYNUMBER = 2,
	};

	enum higherOrLower {
		HIGHER = 1,
		LOWER = 2,
	};

	enum difficulty {
		EASY = 1,
		NORMAL = 2,
		HARD = 3,
	};
}

void DifficultyPicker() {
	cout << "Difficulty Levels\n\n";
	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n\n";
	int choice;
	cout << "Choice: ";
	cin >> choice;
	switch (choice)
	{
	case difficulties::EASY:
		cout << "You picked Easy.\n";
		break;
	case difficulties::NORMAL:
		cout << "You picked Normal.\n";
		break;
	case difficulties::HARD:
		cout << "You picked Hard.\n";
		break;
	default:
		cout << "You made an illegal choice.\n";
	}
}

void ChooseDecision() {
	playerChoice = 0;
	cout << "So is it Higher or Lower\n";
	cout << "1. Higher\n";
	cout << "2. Lower\n\n";
	cout << "Choice: ";
	cin >> playerChoice;
	switch (playerChoice)
	{
	case difficulties::HIGHER:
		cout << "You picked higher.\n";
		break;
	case difficulties::LOWER:
		cout << "You picked lower.\n";
		break;
	default:
		break;
	}
}

void GuessMyNumber() {
	int secretNumber = 1;
	int guess = 0;
	int lastGuess = 0;
	int highestGuessedNumber = 0;
	int lowestGuessedNumber = 0;
	int tries = 0;
	bool firstguess = true;
	bool doOnce = true;

	cout << "Hello player welcome to Guess my number\n";
	cout << "Today our beautiful and intelligent AI Jarvis will take it to challenge you in guess the number!\n";

	cout << "Now please if you could enter a number between 1 and 100, btw Jarvis isn't looking so be fast!\n\n";
	cout << "SECRET NUMBER: ";
	cin >> secretNumber;

	do
	{
		cout << "Number of tries: " << tries << "\n\n";
		srand(static_cast<unsigned int>(time(0)));
		if (firstguess)
		{
			guess = rand() % 100 + 1;
		}

		if (playerChoice == 1)
		{
			// Higher than guessed number
			if (doOnce)
			{
				lowestGuessedNumber = lastGuess;
				doOnce = false;
			}
			if (lowestGuessedNumber <= lastGuess)
			{
				lowestGuessedNumber = lastGuess;
			}
			do
			{
				guess = rand() % 100 + 1;
			} while (guess <= lowestGuessedNumber);
		}
		if (playerChoice == 2)
		{
			// Lower than guessed number
			if (doOnce)
			{
				highestGuessedNumber = lastGuess;
				doOnce = false;
			}
			if (highestGuessedNumber >= lastGuess)
			{
				highestGuessedNumber = lastGuess;
			}
			do
			{
				guess = rand() % 100 + 1;
			} while (guess >= highestGuessedNumber);
		}

		if (tries <= 3)
		{
			cout << "JARVIS (AI): You think you're smart eh here's my guess: " << guess << "\n";
			lastGuess = guess;
			firstguess = false;
			ChooseDecision();
			++tries;
		}
		else if (tries > 3 && tries <= 6)
		{
			cout << "JARVIS (AI): oh you're iq is still not high enough haha, my guess: " << guess << "\n";
			lastGuess = guess;
			ChooseDecision();
			++tries;
		}
		else if (tries > 6 && tries <= 10)
		{
			cout << "JARVIS (AI): look please tell me I got it now I look stupid, my guess: " << guess << "\n";
			lastGuess = guess;
			ChooseDecision();
			++tries;
		}
		else if (tries > 10)
		{
			cout << "JARVIS (AI): my guess: " << guess << " you're not trolling me are you just because I can't detect that doesnt mean you should do this\n";
			lastGuess = guess;
			ChooseDecision();
			++tries;
		}

	} while (guess != secretNumber);

}

int main()
{
	cout << "Hello player choose the game you want to play.\n";
	cout << "1 - Difficulty Picker\n";
	cout << "2 - Guess my number\n\n";
	cout << "Choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case difficulties::DIFFICULTYPICKER:
		DifficultyPicker();
		break;
	case difficulties::GUESSMYNUMBER:
		GuessMyNumber();
		break;
	default:
		break;
	}
	return 0;
}

/**
* What’s wrong with the following loop?
* int x = 0;
* while (x) {
* ++x;
* cout << x << endl;
* }
* 
* I don't know what it is supposed to do but why do I have to press enter to get the next number each time it loops.
* this thing will never end btw.
* 
* 3. Write a new version of the Guess My Number program in which the player and the computer switch roles. 
* That is, the player picks a number and the computer must guess what it is.
* 
* PSUEDO FOR GUESS NUMBER VS AI
* The player picks a number between 0 and 100.
* The AI then chooses a random number between 0 and 100.
* player has 2 options
* number is lower
* number is higher
* if the number is lower than given number 
* guess again a number in between 0 and last given number
* if the number is higher than given number than last given number and 100
* the game continues until the guess has been made.
*/