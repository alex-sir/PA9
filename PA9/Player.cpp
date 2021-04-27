/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "Player.h"

Player::Player()
{
    this->setSize(sf::Vector2f(200.0f, 200.0f));
    this->setFillColor(sf::Color::Black);
    laneNumPosition = rand() % 4 + 1;
    health = 1;
}

/*
    Function: move()
    Author: Alex Carbajal
    Date Created: 04/22/2021
    Date Last Modified: 04/22/2021
    Description: Allows the player to move using keyboard inputs (WASD).
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The player can move using keyboard inputs (WASD).
*/
void Player::move(void)
{
    // AD
    this->moveLeft();
    this->moveRight();
}

/*
    Function: moveLeft()
    Author: Alex Carbajal
    Date Created: 04/22/2021
    Date Last Modified: 04/22/2021
    Description: Allows the player to move left.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The player can move left.
*/
void Player::moveLeft(void)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //sf::RectangleShape::move(-movementSpeed, 0);
    }
}

/*
    Function: moveRight()
    Author: Alex Carbajal
    Date Created: 04/22/2021
    Date Last Modified: 04/22/2021
    Description: Allows the player to move right.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The player can move right.
*/
void Player::moveRight(void)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //sf::RectangleShape::move(movementSpeed, 0);
    }
}

void Player::spawnLocation(void)
{
    switch (laneNumPosition)
    {
    case 1: // First lane
        this->setPosition(0.f, 0.f);
        break;
    case 2: // Second lane
        break;
    case 3: // Third lane
        break;
    case 4: // Fourth lane
        break;
    default:
        break;
    }
}