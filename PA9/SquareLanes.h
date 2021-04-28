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
    // Constructor
    SquareLanes();

    // Getters
    sf::Sprite& getBackground(void);
    sf::Text& getScore(void);
    std::vector<sf::RectangleShape>& getLanes(void);
    Player& getPlayer(void);

    void loadMusic(void);

    void loadFont(void);

    void loadLanes(void);

    void loadBackground(void);

    void loadScore(void);
private:
    Player player;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Font fontRaleway; // The font to be used when playing
    std::vector<sf::RectangleShape> lanes; // The dividing lines
    sf::Music music;
    sf::Text score;
    int numCoins; // Number of coins on the screen
    int numSpikes; // Max of 3 spikes on screen
    int numScore; // Total score the user has in the game
    double gameSpeed; // How fast the spawns are moving down (all spawns have the same speed)

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