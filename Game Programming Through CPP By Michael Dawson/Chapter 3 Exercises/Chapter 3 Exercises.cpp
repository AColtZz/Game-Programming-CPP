// Chapter 3 Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Word Jumble
// The classic word jumble game where the player can ask for a hint

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int playerScore = 0;
    const int LETTER_SCORE = 10;
    const int HINT_COST = 5;
    int hint_cost = 0;
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
    };

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];

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

    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word. \n Enter `hint` for a hint \n Enter `quit` to quit the game.\n\n The jumble is:" << jumble;
    
    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;

    while ((guess != theWord) && (guess != "quit")) {
        if (guess == "hint")
        {
            cout << theHint;
            cout << "\nYour end score has decreased by: " << HINT_COST << "points\n";
            hint_cost += HINT_COST;
        }
        else {
            cout << "Sorry, that's not it.";
        }

        cout << "\n\nYour guess: ";
        cin >> guess;
    }

    if (guess == theWord) {
        cout << "\nThat's it! You guessed it!\n";
        playerScore = LETTER_SCORE * theWord.size() - hint_cost;
        cout << "\nYou've scored: " << playerScore <<"\n";
    }

    cout << "\n Thanks for playing. \n";

    return 0;
}

/**
* 2. What's wrong with the following code?
* for (int i = 0; i <= phrase.size(); ++i)
* {
* cout << "Character at position" << i << "is: " << phrase[i] << endl;
* }
* 
* here your getting the character h instead of C at position 1 
* because the value of i becomes 1 when entering the loop. because it's being incremented prefix
* 
* 3. What’s wrong with the following code?
* const int ROWS = 2;
* const int COLUMNS = 3;
* char board[COLUMNS][ROWS] = { {’O’, ’X’, ’O’},
*                               {’ ’, ’X’, ’X’} };
* 
* Columns and rows should be reversed.
* because first you have the 2 rows and inside there are 3 columns
*/
