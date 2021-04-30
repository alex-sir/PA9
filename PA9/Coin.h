/*
    Programmers: Alex Carbajal, Francesco Rachetto, Brendan Nelson
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Spawn.h"

class Coin : public Spawn, public sf::CircleShape
{
public:
    // Constructor
    Coin() : Spawn(), sf::CircleShape(100.f)
    {
        spawnChance = 3; // 30% chance of spawning
        setFillColor(sf::Color(227, 207, 32)); // Gold
        setOrigin(sf::Vector2f(getRadius(), getRadius())); // Middle of circle
    }
private:
};