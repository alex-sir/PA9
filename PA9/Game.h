/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: NSquare
*/

#pragma once

#include <iostream>
#include <string>

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "Player.h"
#include "Menu.h"
#include "MainMenu.h"

class Game
{
public:
    // Constructor
    Game();

    /*
        Function: runGame()
        Author: Alex Carbajal
        Date Created: 04/23/2021
        Date Last Modified: 04/24/2021
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
    Menu* currentMenu;
    MainMenu mainMenu;
    bool changingMenu; // Whether the game will be changing to another menu
    std::string nextMenu; // What the next menu to be displayed will be

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

    /*
        Function: loadMenu()
        Author: Alex Carbajal
        Date Created: 04/24/2021
        Date Last Modified: 04/24/2021
        Description: Loads all the assets for the current menu in the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: All the assets for the current menu are loaded.
    */
    void loadMenu(void);

    /*
        Function: drawMenuText()
        Author: Alex Carbajal
        Date Created: 04/24/2021
        Date Last Modified: 04/24/2021
        Description: Draws all the text for the current menu.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: All the text for the current menu is displayed.
    */
    void drawMenuText(void);
};