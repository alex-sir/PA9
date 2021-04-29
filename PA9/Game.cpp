/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "Game.h"

Game::Game()
{
    gameWindow.create(sf::VideoMode(1920, 1080), "Square Lanes", sf::Style::Default);
    changingMenu = true;
    changeToPlay = false;
    isMenu = true;
    isPlay = false;
    isGameOver = false;
    menuName = "main";
    beepUp.loadFromFile("Assets/Sound/up.flac");
    beepDown.loadFromFile("Assets/Sound/down.flac");
    beepSelect.loadFromFile("Assets/Sound/select.flac");
    coin.loadFromFile("Assets/Sound/coin.flac");
}

/*
    Function: runGame()
    Author: Alex Carbajal
    Date Created: 04/23/2021
    Date Last Modified: 04/24/2021
    Description: Runs the game.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The game runs.
*/
void Game::runGame(void)
{
    // Prevents tearing in the game
    gameWindow.setVerticalSyncEnabled(true);

    // Set the game window in the middle of the screen (assumes windows taskbar is at the bottom)
    gameWindow.setPosition(sf::Vector2i(
        (sf::VideoMode::getDesktopMode().width / 2) - (gameWindow.getSize().x / 2),
        (sf::VideoMode::getDesktopMode().height / 2) - (gameWindow.getSize().y / 2) - 45));

    // User can't hold down a key. Not wanted in the gameplay.
    gameWindow.setKeyRepeatEnabled(false);

    while (gameWindow.isOpen())
    {
        playGame();

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();

            if (isMenu)
                runMenuProcesses();

            if (isPlay)
                runPlayProcesses();
        }
    }
}

/*
    Function: playGame()
    Author: Alex Carbajal
    Date Created: 04/23/2021
    Date Last Modified: 04/28/2021
    Description: Plays the game.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The game is plays.
*/
void Game::playGame(void)
{
    // Execute a menu change if there is a new menu to be displayed
    if (changingMenu)
    {
        loadMenu();
        changingMenu = false;
    }
    else if (changeToPlay)
    {
        loadPlay();
        changeToPlay = false;
    }

    // Run a menu
    if (isMenu)
    {
        // Menu is main
        if (menuName == "main")
        {
            gameWindow.clear();
            drawBackground(currentMenu->getBackground());
            drawMenuText();
            drawRectangleArtMainMenu();
            drawMiscAssets();
            gameWindow.draw(currentMenu->getMarker());
            gameWindow.display();
        }
        else if (menuName == "instructions") // Menu is instructions
        {
            gameWindow.clear();
            gameWindow.display();
        }
    }
    else if (isPlay) // Play the game
    {
        if (!isGameOver) // Game isn't over
        {
            gameWindow.clear();
            drawBackground(squareLanes.getBackground());
            checkUpdateGameSpeed();
            checkRemoveSpawns();
            checkNewSpawns();
            drawPlayer();
            drawSpawns();
            drawScore();
            drawLanes();
            checkCollision();
            checkGameOver();
            gameWindow.display();
        }
        else // Game is over
        {
            gameWindow.clear();
            drawBackground(squareLanes.getBackground());
            drawPlayer();
            drawSpawns();
            drawScore();
            drawLanes();
            drawGameOver();
            gameWindow.display();
        }
    }
}

/*
    Function: loadMenu()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/24/2021
    Description: Loads all the assets for the current menu in the game.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: All the assets for the current menu are loaded.
*/
void Game::loadMenu(void)
{
    // Set the current menu to be the next menu to be displayed
    if (menuName == "main")
    {
        currentMenu = new MainMenu;

        // Load all the assets
        currentMenu->loadFont();
        currentMenu->loadText();
        currentMenu->loadMusic();
        currentMenu->loadBackground();
        currentMenu->loadRectangles();
        currentMenu->loadMarker();
        currentMenu->loadMiscAssets();
    }
    else if (menuName == "instructions")
    {
        //currentMenu = new Instructions;
    }
}

/*
    Function: loadPlay()
    Author: Alex Carbajal
    Date Created: 04/26/2021
    Date Last Modified: 04/26/2021
    Description: Loads the assets for the game.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The assets for the game are loaded.
*/
void Game::loadPlay(void)
{
    squareLanes.loadFont();
    squareLanes.loadBackground();
    squareLanes.loadScore();
    squareLanes.loadLanes();
    squareLanes.loadMusic();
    squareLanes.getGameClock().restart();
}

/*
    Function: runMenuProcesses()
    Author: Alex Carbajal
    Date Created: 04/26/2021
    Date Last Modified: 04/26/2021
    Description: Runs processes for a menu based on the currently
                 active menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: Processes for the current menu run.
*/
void Game::runMenuProcesses(void)
{
    if (menuName == "main")
    {
        markerMovementMainMenu();
        selectMainMenuOption();
    }
    else if (menuName == "instructions")
    {

    }
}

/*
    Function: drawMenuText()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/24/2021
    Description: Draws all the text for the current menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: All the text for the current menu is displayed.
*/
void Game::drawMenuText(void)
{
    // Draw all the text for the current menu
    for (int i = 0; i < currentMenu->getMenuText().size(); ++i)
    {
        gameWindow.draw(currentMenu->getMenuText()[i]);
    }
}

/*
    Function: drawBackground()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/24/2021
    Description: Draws the background for the current menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The background for the current menu gets draw.
*/
void Game::drawBackground(sf::Sprite& background)
{
    gameWindow.draw(background);
}

/*
    Function: drawRectangleArtMainMenu()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/25/2021
    Description: Draws rectangle art on the main menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: Rectangle art is drawn on the main menu.
*/
void Game::drawRectangleArtMainMenu(void)
{
    // Draw all the rectangles for the main menu
    for (int i = 0; i < currentMenu->getMenuRectangles().size(); ++i)
    {
        currentMenu->getMenuRectangles()[i].rotate(0.05f);
        gameWindow.draw(currentMenu->getMenuRectangles()[i]);
    }
}

/*
    Function: drawMiscAssets()
    Author: Alex Carbajal
    Date Created: 04/29/2021
    Date Last Modified: 04/29/2021
    Description: Draws miscellaneous assets on a menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: Miscellaneous assets are drawn on a menu.
*/
void Game::drawMiscAssets(void)
{
    // Draw all the misc assets
    for (int i = 0; i < currentMenu->getMiscAssets().size(); ++i)
    {
        gameWindow.draw(currentMenu->getMiscAssets()[i]);
    }
}

/*
    Function: markerMovementMainMenu()
    Author: Alex Carbajal
    Date Created: 04/25/2021
    Date Last Modified: 04/25/2021
    Description: Allows for marker movement on the main menu.
                 Plays sounds for the marker.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: Marker movement is allowed on the main menu.
*/
void Game::markerMovementMainMenu(void)
{
    // A key press
    if (event.type == sf::Event::KeyPressed)
    {
        // Marker goes down when 'S' is pressed
        if ((event.key.code == sf::Keyboard::S) &&
            currentMenu->getMarkerPosition() < currentMenu->getMaxMarkerPosition())
        {
            currentMenu->getMarker().setPosition(sf::Vector2f(25.f,
                currentMenu->getMarker().getPosition().y + 97.f));

            beep.setBuffer(beepDown);
            beep.play();

            currentMenu->setMarkerPosition(currentMenu->getMarkerPosition() + 1);
        }

        // Marker goes up when 'W' is pressed
        if ((event.key.code == sf::Keyboard::W) &&
            currentMenu->getMarkerPosition() > currentMenu->getMinMarkerPosition())
        {
            currentMenu->getMarker().setPosition(sf::Vector2f(25.f,
                currentMenu->getMarker().getPosition().y - 97.f));

            beep.setBuffer(beepUp);
            beep.play();

            currentMenu->setMarkerPosition(currentMenu->getMarkerPosition() - 1);
        }
    }
}

/*
    Function: selectMainMenuOption()
    Author: Alex Carbajal
    Date Created: 04/25/2021
    Date Last Modified: 04/25/2021
    Description: Allows for selection of a main menu option.
                 Plays sounds for the selection.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: Selection of a main menu option is allowed.
*/
void Game::selectMainMenuOption(void)
{
    if (event.type == sf::Event::KeyPressed)
    {
        // Select a menu option ('Enter')
        if (event.key.code == sf::Keyboard::Enter && isMenu)
        {
            switch (currentMenu->getMarkerPosition())
            {
            case 1: // Play
                changeToPlay = true;
                isMenu = false;
                isPlay = true;
                break;
            case 2: // Instructions
                changingMenu = true;
                menuName = "instructions";
                break;
            case 3: // Exit
                gameWindow.close();
                break;
            default:
                std::cout << "Error: Invalid marker position in main menu" << std::endl;
                break;
            }

            beep.setBuffer(beepSelect);
            beep.play();

            delete currentMenu;
        }
    }
}

/*
    Function: drawScore()
    Author: Alex Carbajal
    Date Created: 04/27/2021
    Date Last Modified: 04/27/2021
    Description: Draws the score in the game.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The score is drawn in the game.
*/
void Game::drawScore(void)
{
    gameWindow.draw(squareLanes.getScore());
}

/*
    Function: drawLanes()
    Author: Alex Carbajal
    Date Created: 04/26/2021
    Date Last Modified: 04/26/2021
    Description: Draws the lanes for the game.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The lanes for the game are drawn.
*/
void Game::drawLanes(void)
{
    // Draw all the lanes
    for (int i = 0; i < squareLanes.getLanes().size(); ++i)
    {
        gameWindow.draw(squareLanes.getLanes()[i]);
    }
}

/*
    Function: drawPlayer()
    Author: Alex Carbajal
    Date Created: 04/27/2021
    Date Last Modified: 04/27/2021
    Description: Draws the player in the game.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The player is drawn in the game.
*/
void Game::drawPlayer(void)
{
    gameWindow.draw(squareLanes.getPlayer());
}

/*
    Function: drawSpawns()
    Author: Alex Carbajal
    Date Created: 04/28/2021
    Date Last Modified: 04/28/2021
    Description: Draws the spawns in the game.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The spawns are drawn in the game.
*/
void Game::drawSpawns(void)
{
    // Spikes
    for (int i = 0; i < squareLanes.getSpikeSpawns().size(); ++i)
    {
        gameWindow.draw(squareLanes.getSpikeSpawns()[i]);
        squareLanes.getSpikeSpawns()[i].move(0.f, squareLanes.getGameSpeed());
    }

    // Coins
    for (int i = 0; i < squareLanes.getCoinSpawns().size(); ++i)
    {
        gameWindow.draw(squareLanes.getCoinSpawns()[i]);
        squareLanes.getCoinSpawns()[i].move(0.f, squareLanes.getGameSpeed());
    }
}

/*
    Function: runPlayProcesses()
    Author: Alex Carbajal
    Date Created: 04/27/2021
    Date Last Modified: 04/27/2021
    Description: Runs processes relating to playing the game.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: Processes relating to playing the game run.
*/
void Game::runPlayProcesses(void)
{
    if (!isGameOver)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            // Move right
            if (event.key.code == sf::Keyboard::A)
            {
                squareLanes.getPlayer().moveLeft();
            }

            // Move left
            if (event.key.code == sf::Keyboard::D)
            {
                squareLanes.getPlayer().moveRight();
            }
        }
    }
}

/*
    Function: checkUpdateGameSpeed()
    Author: Alex Carbajal
    Date Created: 04/28/2021
    Date Last Modified: 04/28/2021
    Description: Checks if the speed of the game should be increased.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: A check is performed to see if the game speed should
                    be increased.
*/
void Game::checkUpdateGameSpeed(void)
{
    /* Sources
        static_cast: https://www.geeksforgeeks.org/static_cast-in-c-type-casting-operators/
    */

    if (!(squareLanes.getGameSpeed() >= squareLanes.getMaxSpeed()))
    {
        float secondsElapsedGame = squareLanes.getGameClock().getElapsedTime().asSeconds();
        float secondsElapsedRestart = restartGameSpeedCheck.getElapsedTime().asSeconds();
        int increaseInterval = 5;

        // Increase game speed every 5 seconds
        if ((static_cast<int>(secondsElapsedRestart) % 1 == 0) && (secondsElapsedRestart >= 1))
        {
            if (((static_cast<int>(secondsElapsedGame)) % increaseInterval == 0) && (secondsElapsedGame > 1))
            {
                squareLanes.increaseGameSpeed();
                squareLanes.createRowSpawnSpeed();
                restartGameSpeedCheck.restart();
            }
        }
    }
}

/*
    Function: checkRemoveSpawns()
    Author: Alex Carbajal
    Date Created: 04/28/2021
    Date Last Modified: 04/28/2021
    Description: Checks if the spawns should be removed from the screen.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: Checks are performed to see if spawns should be removed
                    from the screen.
*/
void Game::checkRemoveSpawns(void)
{
    /* Sources
        Erase element from vector: https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index
    */

    // Spikes
    for (int i = 0; i < squareLanes.getSpikeSpawns().size(); ++i)
    {
        // Remove the spawn once it reaches the bottom of the screen (should not be visible when removed)
        if (squareLanes.getSpikeSpawns()[i].getPosition().y > 1080 + squareLanes.getSpikeSpawns()[i].getRadius())
        {
            squareLanes.getSpikeSpawns().erase(squareLanes.getSpikeSpawns().begin() + i);
        }
    }

    // Coins
    for (int i = 0; i < squareLanes.getCoinSpawns().size(); ++i)
    {
        // Remove the spawn once it reaches the bottom of the screen (should not be visible when removed)
        if (squareLanes.getCoinSpawns()[i].getPosition().y > 1080 + squareLanes.getCoinSpawns()[i].getRadius())
        {
            squareLanes.getCoinSpawns().erase(squareLanes.getCoinSpawns().begin() + i);
        }
    }
}

/*
    Function: checkNewSpawns()
    Author: Alex Carbajal
    Date Created: 04/28/2021
    Date Last Modified: 04/28/2021
    Description: Checks if a new row of spawns should be created.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: A check is performed to see if a new row of
                    spawns should be created.
*/
void Game::checkNewSpawns(void)
{
    float secondsElapsedLastSpawn = lastSpawn.getElapsedTime().asSeconds();

    // Check if a new row should spawn
    if (squareLanes.getRowSpawnSpeed() < secondsElapsedLastSpawn)
    {
        squareLanes.setNumSpikes(0);
        squareLanes.setNumCoins(0);
        squareLanes.loadSpawns();

        lastSpawn.restart();
    }
}

/*
    Function: checkCollision()
    Author: Alex Carbajal
    Date Created: 04/28/2021
    Date Last Modified: 04/28/2021
    Description: Checks if a collision with a spawn occured.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: A check is performed to see if a collision
                    with a spawn occured.
*/
void Game::checkCollision(void)
{
    // Check for collision with a spike
    for (int i = 0; i < squareLanes.getSpikeSpawns().size(); ++i)
    {
        if (squareLanes.getPlayer().getGlobalBounds().intersects(squareLanes.getSpikeSpawns()[i].getGlobalBounds()))
        {
            // Reduce player health by 1
            squareLanes.getPlayer().setHealth(squareLanes.getPlayer().getHealth() - 1);

            // Remove the spike if the player still has some health and the game isn't over
            if (!(squareLanes.getPlayer().getHealth() <= 0))
            {
                squareLanes.getSpikeSpawns().erase(squareLanes.getSpikeSpawns().begin() + i);
            }
        }
    }

    // Check for collision with a coin
    for (int i = 0; i < squareLanes.getCoinSpawns().size(); ++i)
    {
        if (squareLanes.getPlayer().getGlobalBounds().intersects(squareLanes.getCoinSpawns()[i].getGlobalBounds()))
        {
            // Update score
            squareLanes.setNumScore(squareLanes.getNumScore() + 1);
            squareLanes.updateScore();

            // Play coin get sound
            coinGet.setBuffer(coin);
            coinGet.play();

            // Remove coin from screen
            squareLanes.getCoinSpawns().erase(squareLanes.getCoinSpawns().begin() + i);
        }
    }
}

/*
    Function: checkGameOver()
    Author: Alex Carbajal
    Date Created: 04/28/2021
    Date Last Modified: 04/28/2021
    Description: Checks if the player has lost the game by
                 losing all their health.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: A check is performed to see if the player has
                    lost the game.
*/
void Game::checkGameOver(void)
{
    // Player has lost all health
    if (squareLanes.getPlayer().getHealth() <= 0)
    {
        isGameOver = true;
        squareLanes.loadGameOver();
        squareLanes.getGameOver().setPosition(sf::Vector2f(gameWindow.getSize().x / 2.f,
                                              gameWindow.getSize().y / 2.f));
    }
}

/*
    Function: drawGameOver()
    Author: Alex Carbajal
    Date Created: 04/29/2021
    Date Last Modified: 04/29/2021
    Description: Draws the assets for the game over screen.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The assets for the game over screen are drawn.
*/
void Game::drawGameOver(void)
{
    gameWindow.draw(squareLanes.getGameOverBackground());
    gameWindow.draw(squareLanes.getGameOver());
}