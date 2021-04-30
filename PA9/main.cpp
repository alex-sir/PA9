/*
    Programmers: Alex Carbajal, Francesco Rachetto, Brendan Nelson
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "Game.h"
#include "Test.h"

// If code is correct but program is still breaking, run the project in RELEASE mode (to the left of 'Local Window Debugger')

int main()
{
    srand((unsigned int)time(NULL)); // Random seed

    Game NSquare;

    NSquare.runGame();

    //Test test;

    //test.positionOfMarker();

    return 0;
}