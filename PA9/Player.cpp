/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: NSquare
*/

#include "Player.h"

Player::Player()
{
    this->setSize(sf::Vector2f(20.0f, 20.0f));
    this->setFillColor(sf::Color::Black);
    movementSpeed = 1;
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
    // WASD
    this->moveUp();
    this->moveLeft();
    this->moveDown();
    this->moveRight();
}

/*
    Function: moveUp()
    Author: Alex Carbajal
    Date Created: 04/22/2021
    Date Last Modified: 04/22/2021
    Description: Allows the player to move upwards.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The player can move upwards.
*/
void Player::moveUp(void)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sf::RectangleShape::move(0, -movementSpeed);
    }
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
        sf::RectangleShape::move(-movementSpeed, 0);
    }
}

/*
    Function: moveDown()
    Author: Alex Carbajal
    Date Created: 04/22/2021
    Date Last Modified: 04/22/2021
    Description: Allows the player to move downwards.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The player can move downwards.
*/
void Player::moveDown(void)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sf::RectangleShape::move(0, movementSpeed);
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
        sf::RectangleShape::move(movementSpeed, 0);
    }
}