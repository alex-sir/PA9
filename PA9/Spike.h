/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Spawn.h"

class Spike : public Spawn, public sf::CircleShape // Multiple inheritance
{
public:
    // Constructor
    Spike() : Spawn(), sf::CircleShape(200.f, 3)
    {
        setFillColor(sf::Color::Red);
    }
private:
};