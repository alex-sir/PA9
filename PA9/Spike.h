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
    Spike() : Spawn(), sf::CircleShape(140.f, 3)
    {
        spawnChance = 7; // 70% chance of spawning
        setFillColor(sf::Color(220, 20, 60)); // Crimson red
        setOrigin(sf::Vector2f(getRadius(), getRadius())); // Middle of triangle
        setRotation(180); // Spike is facing down towards the player
    }
private:
};