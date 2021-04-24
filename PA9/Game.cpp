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
    this->gameWindow.create(sf::VideoMode(1280, 720), "NSquare", sf::Style::Default);
}

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
void Game::runGame(void)
{
    //gameWindow.setFramerateLimit(144);

    while (gameWindow.isOpen())
    {
        sf::Event event;

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
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
    player.move();

    gameWindow.clear(sf::Color(200, 200, 200));
    gameWindow.draw(player);
    gameWindow.display();
}