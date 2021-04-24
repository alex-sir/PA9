/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: NSquare
*/

#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::RectangleShape
{
public:
    Player();

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
    void move(void);
private:
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
    void moveUp(void);

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
    void moveLeft(void);

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
    void moveDown(void);

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
    void moveRight(void);
};