/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: NSquare
*/

#include "Game.h"

Game::Game()
{
    gameWindow.create(sf::VideoMode(1920, 1080), "NSquare", sf::Style::Default);
    changingMenu = true;
    menuName = "main";
}

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
void Game::runGame(void)
{
    // Prevents tearing in the game
    gameWindow.setVerticalSyncEnabled(true);

    // Set the game window in the middle of the screen (assumes windows taskbar is at the bottom)
    gameWindow.setPosition(sf::Vector2i(
        (sf::VideoMode::getDesktopMode().width / 2) - (gameWindow.getSize().x / 2),
        (sf::VideoMode::getDesktopMode().height / 2) - (gameWindow.getSize().y / 2) - 45));

    while (gameWindow.isOpen())
    {
        sf::Event event;

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();

            // You can exit the game using the escape key. Will later be changed to pause the game.
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                gameWindow.close();
        }

        startGame();
    }
}

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
void Game::startGame(void)
{
    // Execute a menu change if there is a new menu to be displayed
    if (changingMenu)
    {
        loadMenu();
        changingMenu = false;
    }

    if (menuName == "main")
    {
        gameWindow.clear();
        drawBackground();
        drawRectanglesMainMenu();
        drawMenuText();
        gameWindow.display();
    }
}

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
void Game::loadMenu(void)
{
    // Set the current menu to be the next menu to be displayed
    if (menuName == "main")
    {
        currentMenu = &mainMenu;

        // Load all the assets
        currentMenu->loadFont();
        currentMenu->loadText();
        currentMenu->loadMusic();
        currentMenu->loadBackground();
        currentMenu->loadRectangles();
    }
}

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
void Game::drawMenuText(void)
{
    // Draw all the text for the current menu
    for (int i = 0; i < currentMenu->getMenuText().size(); ++i)
    {
        gameWindow.draw(currentMenu->getMenuText()[i]);
    }
}

/*
    Function: drawBackground()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/24/2021
    Description: Draws the background for the current menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The background for the current menu gets draw.
*/
void Game::drawBackground(void)
{
    gameWindow.draw(currentMenu->getBackground());
}

/*
    Function: drawRectanglesMainMenu()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/24/2021
    Description: Draws rectangles on the current menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: Rectangles are drawn on the current menu.
*/
void Game::drawRectanglesMainMenu(void)
{
    // Draw all the rectangles for the main menu
    for (int i = 0; i < currentMenu->getMenuRectangles().size(); ++i)
    {
        currentMenu->getMenuRectangles()[i].rotate(0.05f);
        gameWindow.draw(currentMenu->getMenuRectangles()[i]);
    }
}