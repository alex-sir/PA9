/*
    Programmers: Alex Carbajal, Francesco Rachetto, Brendan Nelson
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "Player.h"

Player::Player()
{
    this->setSize(sf::Vector2f(200.f, 200.f));
    this->setFillColor(sf::Color::Black);
    this->setOrigin(this->getSize().x / 2, this->getSize().y / 2);
    laneNumPosition = rand() % 4 + 1;
    maxLanePosition = 4;
    minLanePosition = 1;
    health = 1;
    spawnLocation();
}

int Player::getHealth(void) const
{
    return health;
}

void Player::setHealth(int newHealth)
{
    health = newHealth;
}

/*
    Function: moveLeft()
    Author: Alex Carbajal
    Date Created: 04/22/2021
    Date Last Modified: 04/27/2021
    Description: Allows the player to move left.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The player can move left.
*/
void Player::moveLeft(void)
{
    if (laneNumPosition > minLanePosition)
    {
        this->setPosition(this->getPosition().x - 480.f, this->getPosition().y);
        laneNumPosition--;
    }
}

/*
    Function: moveRight()
    Author: Alex Carbajal
    Date Created: 04/22/2021
    Date Last Modified: 04/27/2021
    Description: Allows the player to move right (D).
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The player can move right (D).
*/
void Player::moveRight(void)
{
    if (laneNumPosition < maxLanePosition)
    {
        this->setPosition(this->getPosition().x + 480.f, this->getPosition().y);
        laneNumPosition++;
    }
}

/*
    Function: spawnLocation()
    Author: Alex Carbajal
    Date Created: 04/27/2021
    Date Last Modified: 04/27/2021
    Description: Spawns the player in a lane that was randomly
                 chosen.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: Lane number should be 1 - 4.
    Postconditions: The player is spawned in the lane that was
                    randomly chosen.
*/
void Player::spawnLocation(void)
{
    float yPosition = 800.f;

    // Lane sizes in pixels (left to right): 480, 960, 1440, 1920
    // Midpoint of lanes: 240, 720, 1200, 1680
    // Intervals of 480 between each midpoint in adjacent lanes

    // Select the lane to put the player in
    switch (laneNumPosition)
    {
    case 1: // First lane
        this->setPosition(240.f, yPosition);
        break;
    case 2: // Second lane
        this->setPosition(720.f, yPosition);
        break;
    case 3: // Third lane
        this->setPosition(1200.f, yPosition);
        break;
    case 4: // Fourth lane
        this->setPosition(1680.f, yPosition);
        break;
    default:
        break;
    }
}