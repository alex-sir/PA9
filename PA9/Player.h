/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#pragma once

#include <stdlib.h>

#include <SFML/Graphics.hpp>

class Player : public sf::RectangleShape
{
public:
    Player();

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
    void moveLeft(void);

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
    void moveRight(void);
private:
    int laneNumPosition; // In which lane the player currently resides
    int maxLanePosition; // The far-right lane
    int minLanePosition; // The far-left lane
    int health; // The number of hits the player can take before game over

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
    void spawnLocation(void);
};