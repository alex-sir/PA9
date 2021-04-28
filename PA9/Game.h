/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "Menu.h"
#include "MainMenu.h"
#include "Instructions.h"
#include "SquareLanes.h"

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
    sf::Event event;
    Menu* currentMenu;
    SquareLanes squareLanes;
    bool changingMenu; // Whether the game will be changing to another menu
    bool changeToPlay; // Whether the game is in the process of changing to play mode
    bool isMenu;
    bool isPlay; // Whether the user entered into play mode
    std::string menuName; // The menus name
    sf::Sound beep; // Blip sound in the menu
    sf::SoundBuffer beepUp;
    sf::SoundBuffer beepDown;
    sf::SoundBuffer beepSelect;

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
        Function: loadPlay()
        Author: Alex Carbajal
        Date Created: 04/26/2021
        Date Last Modified: 04/26/2021
        Description: Loads the assets for the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The assets for the game are loaded.
    */
    void loadPlay(void);

    /*
        Function: runMenuProcesses()
        Author: Alex Carbajal
        Date Created: 04/26/2021
        Date Last Modified: 04/26/2021
        Description: Runs processes for a menu based on the currently
                     active menu.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: Processes for the current menu run.
    */
    void runMenuProcesses(void);

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

    /*
        Function: drawBackground()
        Author: Alex Carbajal
        Date Created: 04/24/2021
        Date Last Modified: 04/27/2021
        Description: Draws the background for the current menu.
        Input parameters: N/A
        Output parameters: sf::Sprite& background
        Returns: N/A
        Preconditions: None
        Postconditions: The background for the current menu gets draw.
    */
    void drawBackground(sf::Sprite& background);

    /*
        Function: drawRectangleArtMainMenu()
        Author: Alex Carbajal
        Date Created: 04/24/2021
        Date Last Modified: 04/25/2021
        Description: Draws rectangle art on the main menu.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: Rectangle art is drawn on the main menu.
    */
    void drawRectangleArtMainMenu(void);

    /*
        Function: markerMovementMainMenu()
        Author: Alex Carbajal
        Date Created: 04/25/2021
        Date Last Modified: 04/25/2021
        Description: Allows for marker movement on the main menu.
                     Plays sounds for the marker.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: Marker movement is allowed on the main menu.
    */
    void markerMovementMainMenu(void);

    /*
        Function: selectMainMenuOption()
        Author: Alex Carbajal
        Date Created: 04/25/2021
        Date Last Modified: 04/25/2021
        Description: Allows for selection of a main menu option.
                     Plays sounds for the selection.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: Selection of a main menu option is allowed.
    */
    void selectMainMenuOption(void);

    /*
        Function: drawScore()
        Author: Alex Carbajal
        Date Created: 04/27/2021
        Date Last Modified: 04/27/2021
        Description: Draws the score in the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The score is drawn in the game.
    */
    void drawScore(void);

    /*
        Function: drawLanes()
        Author: Alex Carbajal
        Date Created: 04/26/2021
        Date Last Modified: 04/26/2021
        Description: Draws the lanes for the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The lanes for the game are drawn.
`   */
    void drawLanes(void);

    /*
        Function: drawPlayer()
        Author: Alex Carbajal
        Date Created: 04/27/2021
        Date Last Modified: 04/27/2021
        Description: Draws the player in the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The player is drawn in the game.
    */
    void drawPlayer(void);

    /*
        Function: runPlayProcesses()
        Author: Alex Carbajal
        Date Created: 04/27/2021
        Date Last Modified: 04/27/2021
        Description: Runs processes relating to playing the game.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: Processes relating to playing the game run.
    */
    void runPlayProcesses(void);
};