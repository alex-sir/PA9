/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "Player.h"

class SquareLanes
{
public:
    // Getters
    std::vector<sf::RectangleShape>& getLanes(void);

    void loadLanes(void);
private:
    Player player;
    std::vector<sf::RectangleShape> lanes; // The dividing lines

    void makeLane(sf::RectangleShape& line, float xPosition);
};