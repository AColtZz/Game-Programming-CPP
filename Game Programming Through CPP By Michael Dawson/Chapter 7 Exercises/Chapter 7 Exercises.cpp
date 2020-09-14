// Chapter 7 Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.

/**
* 1. Write a program with a pointer to a pointer to a string object. 
* Use the pointer to the pointer to call the size() member function of the string object.
*/

#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string* name, string* noun, int* number, string* bodyPart, string* verb);

void MadLib();
void StringSize();

enum programChoices {
    MADLIB = 1,
    STRINGSIZE = 2,
};

int main()
{
    cout << "1 - MadLib\n2 - StringSize\n\nYour Choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case MADLIB:
        MadLib();
        break;
    case STRINGSIZE:
        StringSize();
        break;
    default:
        break;
    }
}

void StringSize() {
    string str = "SizeMember Test";
    string* pStr = &str;
    cout << "pStr->size(): " << pStr->size() << endl;
}

/**
* 2. Rewrite the Mad Lib Game project from Chapter 5, "Functions: Mad Lib," 
* so that no string objects are passed to the function that tells the story. 
* Instead, the function should accept pointers to string objects.
*/

void MadLib() {
    cout << "Welcome to Mad Lib.\n\n";
    cout << "Answer the following questions to help create a new story.\n";

    string name = askText("Please enter a name: ");
    string noun = askText("Please enter a plural noun: ");
    int number = askNumber("Please enter a number: ");
    string bodyPart = askText("Please enter a body part: ");
    string verb = askText("Please enter a verb: ");

    string* pName = &name;
    string* pNoun = &noun;
    int* pNumber = &number;
    string* pBodypart = &bodyPart;
    string* pVerb = &verb;

    tellStory(pName, pNoun, pNumber, pBodypart, pVerb);
}

string askText(string prompt)
{
    string text;
    cout << prompt;
    cin >> text;
    return text;
}

int askNumber(string prompt)
{
    int num;
    cout << prompt;
    cin >> num;
    return num;
}

void tellStory(string* name, string* noun, int* number, string* bodyPart, string* verb)
{
    cout << "\nHere's your story:\n";
    cout << "The famous explorer ";
    cout << *name;
    cout << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of ";
    cout << *noun;
    cout << " when one day, the ";
    cout << *noun;
    cout << " found the explorer.\n";
    cout << "Surrounded by ";
    cout << *number;
    cout << " " << *noun;
    cout << ", a tear came to ";
    cout << *name << "'s ";
    cout << *bodyPart << ".\n";
    cout << "After all this time, the quest was finally over. ";
    cout << "And then, the ";
    cout << *noun << "\n";
    cout << "promptly devoured ";
    cout << *name << ". ";
    cout << "The moral of the story? Be careful what you ";
    cout << *verb;
    cout << " for.";
}