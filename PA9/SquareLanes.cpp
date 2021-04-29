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
    gameSpeed = 1.5;
    maxSpeed = 10.0;
    spikeSpawnChance = 7;
    coinSpawnChance = 3;
    createRowSpawnSpeed();
    currentTime = gameClock.getElapsedTime();
}

SquareLanes::~SquareLanes()
{
    stopMusic();
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

int SquareLanes::getNumScore(void) const
{
    return numScore;
}

float SquareLanes::getGameSpeed(void) const
{
    return gameSpeed;
}

float SquareLanes::getMaxSpeed(void) const
{
    return maxSpeed;
}

std::vector<Spike>& SquareLanes::getSpikeSpawns(void)
{
    return spikeSpawns;
}

std::vector<Coin>& SquareLanes::getCoinSpawns(void)
{
    return coinSpawns;
}

sf::Clock& SquareLanes::getGameClock(void)
{
    return gameClock;
}

float SquareLanes::getRowSpawnSpeed(void)
{
    return rowSpawnSpeed;
}

sf::Text& SquareLanes::getGameOver(void)
{
    return gameOver;
}

sf::Sprite& SquareLanes::getGameOverBackground(void)
{
    return gameOverBackground;
}

void SquareLanes::setNumSpikes(int newNumSpikes)
{
    numSpikes = newNumSpikes;
}

void SquareLanes::setNumCoins(int newNumCoins)
{
    numCoins = newNumCoins;
}

void SquareLanes::setNumScore(int newNumScore)
{
    numScore = newNumScore;
}

void SquareLanes::loadMusic(void)
{
    music.openFromFile("Assets/Music/squareLanes.flac");
    music.setLoop(true);
    music.play();
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
    Input parameters: float xPosition
    Output parameters: sf::RectangleShape& line
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

/*
    Function: updateScore()
    Author: Alex Carbajal
    Date Created: 04/28/2021
    Date Last Modified: 04/28/2021
    Description: Updates the score text to represent the player's
                 current score.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The score text is updated to represent the player's
                    current score.
*/
void SquareLanes::updateScore(void)
{
    score.setString("Score: " + std::to_string(numScore));
}

void SquareLanes::loadSpawns(void)
{
    chooseSpawns();
    createSpawns();
}

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
void SquareLanes::chooseSpawns(void)
{
    /* Spawn Chance
        Spike: 70%
        Coin: 30%
        Can add powerup later
    */

    /* Todo
        Make the time interval for spawns semi-random and different for each lane
        Use the height (y) of the player to make sure the player can switch lanes and the game doesn't become impossible
            Minimum height in between new spawns in a lane
    */

    int spawnNum = 0;
    std::string spawn = "";

    for (int i = 0; i < 4; ++i)
    {
        spawnNum = rand() % 10 + 1; // 1 - 10

        // 70% chance of a spike spawning
        // Max spikes is in 3 lanes, otherwise guaranteed game over
        if ((spawnNum >= 1 && spawnNum <= spikeSpawnChance) && (numSpikes < 3))
        {
            spawn = "spike";
            numSpikes++;
        }
        else // 30% chance of a coin spawning
        {
            spawn = "coin";
            numCoins++;
        }

        laneSpawns[i] = spawn;
    }
}

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
void SquareLanes::createSpawns(void)
{
    // Go through the spawns
    for (int i = 0; i < 4; ++i)
    {
        // Create a spike
        if (laneSpawns[i] == "spike")
        {
            createSpike(i + 1);
        }
        else if (laneSpawns[i] == "coin") // Create a coin
        {
            createCoin(i + 1);
        }
    }
}

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
void SquareLanes::createSpike(int lane)
{
    Spike spikeSpawn;

    spikeSpawn.setSpawnLane(lane);
    spikeSpawn.setPosition(sf::Vector2f(xSpawnLocation(lane), -spikeSpawn.getRadius()));

    spikeSpawns.push_back(spikeSpawn);
}

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
void SquareLanes::createCoin(int lane)
{
    Coin coinSpawn;

    coinSpawn.setSpawnLane(lane);
    coinSpawn.setPosition(sf::Vector2f(xSpawnLocation(lane), -coinSpawn.getRadius()));

    coinSpawns.push_back(coinSpawn);
}

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
float SquareLanes::xSpawnLocation(int lane)
{
    // Select the lane for the spawn
    switch (lane)
    {
    case 1: // First lane
        return 240.f;
        break;
    case 2: // Second lane
        return 720.f;
        break;
    case 3: // Third lane
        return 1200.f;
        break;
    case 4: // Fourth lane
        return 1680.f;
        break;
    default:
        return 0.f;
        break;
    }
}

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
void SquareLanes::createRowSpawnSpeed(void)
{
    /*
        gameSpeed 1: 3.5 seconds
        gameSpeed 1.5: 2.5 seconds
        gameSpeed 2: 1.65 seconds
        gameSpeed 3: 1.35 seconds
        gameSpeed 4: 0.9 seconds
    */

    if (gameSpeed >= 1.5 && gameSpeed < 2) // Easy
    {
        rowSpawnSpeed = 2.5;
    }
    else if (gameSpeed >= 2 && gameSpeed < 3) // Medium
    {
        rowSpawnSpeed = 1.65;
    }
    else if (gameSpeed >= 3 && gameSpeed < 4) // Hard
    {
        rowSpawnSpeed = 1.35;
    }
    else if (gameSpeed >= 4) // Extreme
    {
        rowSpawnSpeed = 0.9;
    }
}

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
void SquareLanes::increaseGameSpeed(void)
{
    gameSpeed += 0.2f;
}

void SquareLanes::loadGameOver(void)
{
    /* Sources
        Centering text in SFML: https://en.sfml-dev.org/forums/index.php?topic=24161.0
    */

    // Lower volume
    music.setVolume(25);

    // Transparent background
    gameOverBackgroundTexture.loadFromFile("Assets/Backgrounds/GameOverBackground.png");
    gameOverBackground.setTexture(gameOverBackgroundTexture);
    gameOverBackground.setColor(sf::Color(255, 255, 255, 150));
    gameOverBackground.setPosition(sf::Vector2f(0.f, 0.f));

    // Game Over text
    gameOver.setFont(fontRaleway);
    gameOver.setString("GAME OVER");
    gameOver.setCharacterSize(170);
    gameOver.setFillColor(sf::Color::White);
    gameOver.setOrigin(sf::Vector2f(gameOver.getLocalBounds().left + gameOver.getLocalBounds().width / 2.0f,
                       gameOver.getLocalBounds().top + gameOver.getLocalBounds().height / 2.0f));

    // Setting game speed to 0
    gameSpeed = 0.f;
}

void SquareLanes::stopMusic(void)
{
    music.setLoop(false);
    music.stop();
}