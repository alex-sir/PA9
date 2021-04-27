/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#pragma once

#include <stdlib.h>

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "Player.h"

class SquareLanes
{
public:
    // Getters
    sf::Sprite& getBackground(void);
    std::vector<sf::RectangleShape>& getLanes(void);

    void loadMusic(void);

    void loadLanes(void);

    void loadBackground(void);
private:
    Player player;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    std::vector<sf::RectangleShape> lanes; // The dividing lines
    sf::Text spaceToPlay;
    sf::Music music;

    /*
        Function: makeLane()
        Author: Alex Carbajal
        Date Created: 04/26/2021
        Date Last Modified: 04/26/2021
        Description: Creates the divider for a lane.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The divider for a lane is created.
    */
    void makeLane(sf::RectangleShape& line, float xPosition);
};