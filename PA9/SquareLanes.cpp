/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "SquareLanes.h"

SquareLanes::SquareLanes()
{
    numCoins = 0;
    numSpikes = 0;
    numScore = 0;
    gameSpeed = 1.0;
    spawnSpeed = 1.0;
}

sf::Sprite& SquareLanes::getBackground(void)
{
    return background;
}

sf::Text& SquareLanes::getScore(void)
{
    return score;
}

std::vector<sf::RectangleShape>& SquareLanes::getLanes(void)
{
    return lanes;
}

Player& SquareLanes::getPlayer(void)
{
    return player;
}

void SquareLanes::loadMusic(void)
{
    music.openFromFile("Assets/Music/squareLanes.flac");
    music.setLoop(true);
    //music.play();
}

void SquareLanes::loadFont(void)
{
    fontRaleway.loadFromFile("Assets/RalewayFont/Raleway-Light.ttf");
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
void SquareLanes::makeLane(sf::RectangleShape& line, float xPosition)
{
    line.setSize(sf::Vector2f(2.f, 1080.f));
    line.setFillColor(sf::Color::White);
    line.setPosition(xPosition, 0.f);
}

void SquareLanes::loadBackground(void)
{
    backgroundTexture.loadFromFile("Assets/Backgrounds/SquareLanesBackground.png");
    background.setTexture(backgroundTexture);
    background.setPosition(sf::Vector2f(0.0f, 0.0f));
}

void SquareLanes::loadScore(void)
{
    score.setFont(fontRaleway);
    score.setString("Score: " + std::to_string(numScore));
    score.setCharacterSize(40);
    score.setFillColor(sf::Color::White);
    score.setPosition(sf::Vector2f(10.f, 5.f));
}

void SquareLanes::chooseSpawns(void)
{
    /* Spawn Chance
        Spike: 70%
        Coin: 30%
    */

    int spawnNum = 0;
    std::string spawn = "";

    for (int i = 0; i < 4; ++i)
    {
        spawnNum = rand() % 10 + 1; // 1 - 10

        // 70% chance of a spike spawning
        if (spawnNum >= 1 && spawnNum <= 7)
        {
            spawn = "spike";
        }
        else // 30% chance of a coin spawning
        {
            spawn = "coin";
        }

        laneSpawns[i] = spawn;
    }
}