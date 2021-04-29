/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#pragma once

#include <stdlib.h>
#include <string>

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "Player.h"
#include "Spike.h"
#include "Coin.h"

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
    float getGameSpeed(void) const;
    float getMaxSpeed(void) const;
    std::vector<Spike>& getSpikeSpawns(void);
    std::vector<Coin>& getCoinSpawns(void);
    sf::Clock& getGameClock(void);
    float getRowSpawnSpeed(void);

    // Setters
    void setNumSpikes(int newNumSpikes);
    void setNumCoins(int newNumCoins);

    void loadMusic(void);

    void loadFont(void);

    void loadLanes(void);

    void loadBackground(void);

    void loadScore(void);

    void loadSpawns(void);

    /*
        Function: increaseGameSpeed()
        Author: Alex Carbajal
        Date Created: 04/28/2021
        Date Last Modified: 04/28/2021
        Description: Increases the downward movement of spawns.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The downward movement of spawns increases.
    */
    void increaseGameSpeed(void);

    /*
        Function: createRowSpawnSpeed()
        Author: Alex Carbajal
        Date Created: 04/28/2021
        Date Last Modified: 04/28/2021
        Description: Creates the spawn speed for the spawns in a row.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: A row has a spawn speed created for it.
    */
    void createRowSpawnSpeed(void);
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
    float gameSpeed; // How fast the spawns are moving down (all spawns have the same speed)
    float maxSpeed; // The maximum speed the game can run at
    double spikeSpawnChance;
    double coinSpawnChance;
    std::string laneSpawns[4]; // The spawn at each of the 4 lanes
    float rowSpawnSpeed; // The spawn speed for the spawns
    std::vector<Spike> spikeSpawns;
    std::vector<Coin> coinSpawns;
    sf::Clock gameClock; // Measures the time in the game
    sf::Time currentTime; // The current time in the game clock

    /*
        Function: makeLane()
        Author: Alex Carbajal
        Date Created: 04/26/2021
        Date Last Modified: 04/26/2021
        Description: Creates the divider for a lane.
        Input parameters: float xPosition
        Output parameters: sf::RectangleShape& line
        Returns: N/A
        Preconditions: None
        Postconditions: The divider for a lane is created.
    */
    void makeLane(sf::RectangleShape& line, float xPosition);

    /*
        Function: chooseSpawns()
        Author: Alex Carbajal
        Date Created: 04/28/2021
        Date Last Modified: 04/28/2021
        Description: Randomly picks the spawns.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: Spawns are randomly picked.
    */
    void chooseSpawns(void);

    /*
        Function: createSpawns()
        Author: Alex Carbajal
        Date Created: 04/28/2021
        Date Last Modified: 04/28/2021
        Description: Creates the spawn sprites.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: The spawn sprites are created.
    */
    void createSpawns(void);

    /*
        Function: createSpike()
        Author: Alex Carbajal
        Date Created: 04/28/2021
        Date Last Modified: 04/28/2021
        Description: Creates a spike sprite.
                     Adds it to the list of spike spawns.
        Input parameters: int lane
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: A spike sprite is created and added to the
                        list of spike spawns.
    */
    void createSpike(int lane);

    /*
        Function: createCoin()
        Author: Alex Carbajal
        Date Created: 04/28/2021
        Date Last Modified: 04/28/2021
        Description: Creates a coin sprite.
                     Adds it to the list of coin spawns.
        Input parameters: int lane
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: A coin sprite is created and added to the
                        list of coin spawns.
    */
    void createCoin(int lane);

    /*
        Function: xSpawnLocation()
        Author: Alex Carbajal
        Date Created: 04/28/2021
        Date Last Modified: 04/28/2021
        Description: Determines the x position a spawn will be in based
                     on the lane it will spawn in.
        Input parameters: int lane
        Output parameters: N/A
        Returns: float indicating the x position for the spawn
        Preconditions: None
        Postconditions: The x position for a spawn based on its lane is returned.
    */
    float xSpawnLocation(int lane);
};