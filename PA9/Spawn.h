/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#pragma once

class Spawn
{
public:
    // Constructor
    Spawn();
private:
    int spawnLane; // The lane in which the spawn appears
    double spawnChance; // A percentage
    double speed; // How fast it moves down the screen
};