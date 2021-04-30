/*
    Programmers: Alex Carbajal, Francesco Rachetto, Brendan Nelson
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "Spawn.h"

Spawn::Spawn()
{
    spawnChance = 0.0;
    speed = 0.0;
    spawnLane = 0;
}

void Spawn::setSpawnLane(int newSpawnLane)
{
    spawnLane = newSpawnLane;
}

void Spawn::setSpeed(int newSpeed)
{
    speed = newSpeed;
}