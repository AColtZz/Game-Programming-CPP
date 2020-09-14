// Chapter 6 Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

/**
* 1. Improve the Mad Lib game from chapter 5  "Functions: Mad Lib", by using references to make the program more efficient
* 
* 2. What's wrong with the following program?
* int main(){
* int score;
* score = 1000;
* float& rScore = score;
* return 0;
* }
* The reference is a float referencing to and int which probably will to an error or some warning
*
* 3. What's wrong with the following function?
* int& plusThree(int number){
* int threeMore = number + 3;
* return threeMore;
* }
* 
* the function is getting a reference instead of the argument which in this case is the thing that should be referenced to.
*/
