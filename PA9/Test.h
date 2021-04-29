/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game.h"

class Test : public Game
{
public:
    /*
        Function: positionOfMarker()
        Author: Alex Carbajal
        Date Created: 04/29/2021
        Date Last Modified: 04/29/2021
        Description: Tests the position of the marker in the
                     main menu.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The position of the marker in the
                        main menu is tested.
    */
    void positionOfMarker(void);

    /*
        Function: menuActive()
        Author: Alex Carbajal
        Date Created: 04/29/2021
        Date Last Modified: 04/29/2021
        Description: Tests to see if isMenu is active on load.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: isMenu is tested on load.
    */
    void menuActive(void);

    /*
        Function: menuNameMain()
        Author: Alex Carbajal
        Date Created: 04/29/2021
        Date Last Modified: 04/29/2021
        Description: Tests the name of the menu on load.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The name of the menu on load is tested.
    */
    void menuNameMain(void);

    /*
        Function: gameScore()
        Author: Alex Carbajal
        Date Created: 04/29/2021
        Date Last Modified: 04/29/2021
        Description: Tests the score of the game on start.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The score of the game is tested on start.
    */
    void gameScore(void);

    /*
        Function: gameSpeedValue()
        Author: Alex Carbajal
        Date Created: 04/29/2021
        Date Last Modified: 04/29/2021
        Description: Tests the game speed when the game starts.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The game speed when the game starts is tested.
    */
    void gameSpeedValue(void);
private:
};