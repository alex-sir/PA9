/*
    Programmers: Alex Carbajal, Francesco Rachetto, Brendan Nelson
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "Test.h"

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
void Test::positionOfMarker(void)
{
    float yMarkerPosition = 195.f;

    while (gameWindow.isOpen())
    {
        playGame();

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();

            if (isMenu)
                runMenuProcesses();
        }

        // Check the initial position of the marker
        if (currentMenu->getMarkerPosition() == 1)
        {
            if (currentMenu->getMarker().getPosition().y == yMarkerPosition)
            {
                std::cout << "Passed: Marker is at correct first position" << std::endl;
            }
            else
            {
                std::cout << "Failed: Marker is at correct first position" << std::endl;
            }
        }

        delete currentMenu;

        return;
    }
}

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
void Test::menuActive(void)
{
    while (gameWindow.isOpen())
    {
        playGame();

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();

            if (isMenu)
                runMenuProcesses();
        }

        // Check for isMenu on load
        if (isMenu)
        {
            std::cout << "Passed: isMenu active on load" << std::endl;
        }
        else
        {
            std::cout << "Failed: isMenu active on load" << std::endl;
        }

        delete currentMenu;

        return;
    }
}

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
void Test::menuNameMain(void)
{
    while (gameWindow.isOpen())
    {
        playGame();

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();

            if (isMenu)
                runMenuProcesses();
        }

        // Check menuName on load
        if (menuName == "main")
        {
            std::cout << "Passed: Menu is 'main' on load" << std::endl;
        }
        else
        {
            std::cout << "Failed: Menu is 'main' on load" << std::endl;
        }

        delete currentMenu;

        return;
    }
}

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
void Test::gameScore(void)
{
    while (gameWindow.isOpen())
    {
        playGame();

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();

            if (isMenu)
                runMenuProcesses();
        }

        // Check score on play start
        if (squareLanes.getNumScore() == 0)
        {
            std::cout << "Passed: Score is 0 on start" << std::endl;
        }
        else
        {
            std::cout << "Failed: Score is 0 on start" << std::endl;
        }

        delete currentMenu;

        return;
    }
}

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
void Test::gameSpeedValue(void)
{
    while (gameWindow.isOpen())
    {
        playGame();

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();

            if (isMenu)
                runMenuProcesses();
        }

        // Check game speed on start
        if (squareLanes.getGameSpeed() == 1.5)
        {
            std::cout << "Passed: Game speed is 1.5 on start" << std::endl;
        }
        else
        {
            std::cout << "Failed: Game speed is 1.5 on start" << std::endl;
        }

        delete currentMenu;

        return;
    }
}