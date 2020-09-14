// Chapter 1 Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.

/**
* 1. Create a list of six legal variable names—three good choices and three bad choices. 
* Explain why each name falls into the good or bad category.
* 
* Good:
* health (keeping things simple is most of the time the best ones)
* shipVelocity (is clear to read and uses camelCasing for the naming convention)
* ship_velocity (is clear to read because of the underscore)
* Bad:
* shipspeedforwardmaximum (this is unreadable and too much for a name keeping it less than 15 characters is best)
* ssfm (too simpel is not always good did you guess that this is the name for the variable name above but shorter)
* bool don't (a boolean is an name where you can answer true or false so make the variable name a verb like isPlaying or hasWon) names-
* where you can answer true or false to
*/

/**
* 2. What’s displayed by each line in the following code snippet? Explain each result.
* 
* cout << "Seven divided by three is " << 7 / 3 << endl;
* (for the first one we are getting a 2 as answer even though it should be 2.333... the reasen we get 2 is because there is no float
* number given so it's getting rounded to an integer)
* cout << "Seven divided by three is " << 7.0 / 3 << endl;
* (for the second one we are getting a 2.333333 this is because one of the 2 digits is a float number with a 0 after the . )
* cout << "Seven divided by three is " << 7.0 / 3.0 << endl;
* (for the third one we are getting exactly the same as 2 because once again there is at least 1 where there is a number after the . )
*/

//3. Write a program that gets three game scores from the user and displays the average.

#include <iostream>

int main()
{
    float num1;
    float num2;
    float num3;
    float average;

    std::cout << "Hello Player please give me 3 numbers and I will get you the average of the three given values:!\n";
    std::cout << "\nNumber 1: ";
    std::cin >> num1;
    std::cout << "\nNumber 1: ";
    std::cin >> num2;
    std::cout << "\nNumber 1: ";
    std::cin >> num3;

    average = (num1 + num2 + num3) / 3;

    std::cout << "Hello player thank you for putting in 3 numbers and the average is: " << average << std::endl;
}
