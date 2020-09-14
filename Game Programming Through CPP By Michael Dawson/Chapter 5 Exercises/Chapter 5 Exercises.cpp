// Chapter 5 Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

namespace games {
    enum gameChoice {
        HANGMAN = 1,
        ASKFORNUMBER = 2,
    };
}

// Hangman game variables
vector<string> words;
const int MAX_WRONG = 8;
const string THE_WORD = words[0];
int wrong = 0;
string soFar(THE_WORD.size(), '_');
string used = "";

void ChooseAGame(string prompt);
void GetPlayerGuess();
void HangmanGame();
void CheckPlayerGuess(char guess);

int main()
{
    ChooseAGame("Choose your game\n 1. Hangman\n2. Ask for number\n\n Your choice: ");
    return 0;
}

void ChooseAGame(string prompt) {
    cout << prompt;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case games::HANGMAN:
        HangmanGame();
        break;
    case games::ASKFORNUMBER:

        break;
    default:
        break;
    }
}

void HangmanGame() {
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());

    cout << "Welcome to Hangman Good luck!\n";

    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;
        GetPlayerGuess();
        if (wrong == MAX_WRONG)
        {
            cout << "You've been hanged!";
        }
        else {
            cout << "\nYou guessed it!";
        }
    }
}

void CheckPlayerGuess(char guess) {
    if (THE_WORD.find(guess) != string::npos)
    {
        cout << "That's right!" << guess << " is in the word.\n";
        //Update soFar to include newly guessed letter
        for (int i = 0; i < THE_WORD.length(); ++i)
        {
            if (THE_WORD[i] == guess)
            {
                soFar[i] = guess;
            }
        }
    }
    else {
        cout << "Sorry, " << guess << " isn't in the word.\n";
        ++wrong;
    }

    cout << "\nThe word was " << THE_WORD << endl;
}

void GetPlayerGuess() {
    char guess;
    cout << "\n\nEnter your guess: ";
    cin >> guess;
    guess = toupper(guess);

    while (used.find(guess) != string::npos) {
        cout << "\nYou've already guessed " << guess << endl;
        cout << "Enter your guess: ";
        cin >> guess;
        guess = toupper(guess);
    }

    used += guess;
    CheckPlayerGuess(guess);
}
/**
* What’s wrong with the following prototype?
* int askNumber(int low = 1, int high);
* 
* if you give an argument a default value the rest of the given arguments behind that should also be given one.
* 
* 2. Rewrite the Hangman game from Chapter 4, “The Standard Template
* Library: Hangman,” using functions. Include a function to get the
* player’s guess and another function to determine whether the player’s
* guess is in the secret word.
*/