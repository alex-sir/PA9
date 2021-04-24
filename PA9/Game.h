/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: NSquare
*/

#pragma once

#include <SFML\Graphics.hpp>

#include "Player.h"

class Game
{
public:
    // Constructor
    Game();

    /*
        Function: runGame()
        Author: Alex Carbajal
        Date Created: 04/23/2021
        Date Last Modified: 04/23/2021
        Description: Runs the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The game runs.
    */
    void runGame(void);
private:
    sf::RenderWindow gameWindow;
    Player player;

    /*
        Function: startGame()
        Author: Alex Carbajal
        Date Created: 04/23/2021
        Date Last Modified: 04/23/2021
        Description: Starts the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The game starts.
    */
    void startGame(void);
};