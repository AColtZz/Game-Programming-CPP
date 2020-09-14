// Chapter 4 Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

namespace GList {

	namespace choices
	{
		enum myChoice {
			ADDGAME = 1,
			REMOVEGAME = 2,
			SHOWLIST = 3,
			SHUFFLELIST = 4,
			SORTLIST = 5,
			EXIT = 6,
		};
	}

	vector<string> games;
	string game;
	choices::myChoice enumVar;
	int userChoice = 0;
	vector<string>::const_iterator iter;
	bool isPlaying = false;

	void AddGame() {
		cin >> game;

		iter = find(games.begin(), games.end(), game);
		if (iter != games.end())
		{
			cout << "Game already exists in list.\n";
		}
		else
		{
			cout << "Game not found adding game!.\n";
			games.push_back(game);
		}
	}

	void RemoveGame()
	{
		cin >> game;
		iter = find(games.begin(), games.end(), game);
		if (iter != games.end())
		{
			cout << "Game exists in list.\n";
			games.erase(iter);
			cout << "Game removed from list.\n";
		}
		else
		{
			cout << "Game not found!.\n";
		}
	}

	void ShowGameList() {
		cout << "\n\n";

		for (iter = games.begin(); iter != games.end(); ++iter)
		{
			cout << *iter << endl;
		}
		cout << "\n\n";
	}

	void ShuffleList() {
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(games.begin(), games.end());
		cout << "\nGame List:\n\n";
		for (iter = games.begin(); iter != games.end(); ++iter)
		{
			cout << *iter << endl;
		}
		cout << "\n\n";
	}

	void SortList() {
		sort(games.begin(), games.end());
		cout << "\nSorted list of games:\n\n";
		for (iter = games.begin(); iter != games.end(); ++iter)
		{
			cout << *iter << endl;
		}
		cout << "\n\n";
	}

	void Exit() {
		isPlaying = false;
	}

	void Listening() {
		cout << "\nWhat would you like to do (Type in the number)\n";
		cout << "\n1. Add Game";
		cout << "\n2. Remove Game";
		cout << "\n3. Show Game List";
		cout << "\n4. Shuffle Game List";
		cout << "\n5. Sort Game List";
		cout << "\n6. Exit Game List\n\n";
		cin >> userChoice;

		switch (userChoice)
		{
		case choices::ADDGAME:
			cout << "\nAdd the game.";
			cout << "\nEnter a game to add: ";
			AddGame();
			break;
		case choices::REMOVEGAME:
			cout << "\nRemove a game.";
			cout << "\nEnter a game to remove: ";
			RemoveGame();
			break;
		case choices::SHOWLIST:
			cout << "\nYour list of Games:\n";
			ShowGameList();
			break;
		case choices::SHUFFLELIST:
			cout << "\nRandomizing games.";
			ShuffleList();
			break;
		case choices::SORTLIST:
			cout << "\nSorting your list of Games:\n";
			SortList();
			break;
		case choices::EXIT:
			cout << "\nExiting list of Games...\n";
			Exit();
			break;
		default:
			cout << "\n Defaulting..." << endl;
			Listening();
			break;
		}
	}
}

int main() {
	cout << "Starting a list of games.";
	GList::isPlaying = true;

	while (GList::isPlaying)
	{
		GList::Listening();
	}

	return 0;
}

/**
* Exercise 2:
* Assuming that scores is a vector that holds elements of type int, 
* what’s wrong with the following code snippet (meant to increment each element)?
* vector<int>::iterator iter;
* //increment each score
* for (iter = scores.begin(); iter != scores.end(); ++iter)
* {
*     iter++;
* }
* 
* This code has iter increment twice and so the iter will skip over 1 number everytime. 
* because in the for loop it increments one time so let's say iter goes from 0 to 1 and then in the list it will 
* show 1 however the second time on the iter is 2 (this happens because of the post- increment) 
* and becomes 3 and then it will show 3 instead of 2. this will go on like this.
*/


/**
* Exercise 3:
* Word Jumble PsuedoCode:
* AI picks a word to jumble from the set of words given
*    first shuffle the list of words
*    get the first word from the list this is the secret word
* if the word is picked jumble the letters in the word
* Welcome the player and explain the rules and actions the player can do
* if player chooses hint
*    give hint related to the word that has been jumbled
* if player chooses quit
*    quit the game
* if player chooses to guess the word
*    check if the word has been guessed correctly
*    if the word is not correct
*       Say that is wrong and ask for another guess
*    if the word is correct
*       Congratulate the player and tell him he guessed correctly
*       Also end the game and thank the player for playing
*/
