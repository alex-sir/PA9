/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "SquareLanes.h"

std::vector<sf::RectangleShape>& SquareLanes::getLanes(void)
{
    return lanes;
}

void SquareLanes::loadLanes(void)
{
    sf::RectangleShape line1;
    sf::RectangleShape line2;
    sf::RectangleShape line3;

    makeLane(line1, 480.f);
    makeLane(line2, 960.f);
    makeLane(line3, 1440.f);

    lanes.push_back(line1);
    lanes.push_back(line2);
    lanes.push_back(line3);
}

void SquareLanes::makeLane(sf::RectangleShape& line, float xPosition)
{
    line.setSize(sf::Vector2f(1.f, 1080.f));
    line.setFillColor(sf::Color::White);
    line.setPosition(xPosition, 0.f);
}