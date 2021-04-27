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
    menuName = "main";
    beepUp.loadFromFile("Assets/Sound/up.flac");
    beepDown.loadFromFile("Assets/Sound/down.flac");
    beepSelect.loadFromFile("Assets/Sound/select.flac");
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
        startGame();

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
    Function: startGame()
    Author: Alex Carbajal
    Date Created: 04/23/2021
    Date Last Modified: 04/23/2021
    Description: Starts the game.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The game starts.
*/
void Game::startGame(void)
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
        gameWindow.clear();
        drawBackground(squareLanes.getBackground());
        drawPlayer();
        drawLanes();
        gameWindow.display();
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
    squareLanes.loadBackground();
    squareLanes.loadLanes();
    squareLanes.loadMusic();
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
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::A)
        {
            squareLanes.getPlayer().moveLeft();
        }

        if (event.key.code == sf::Keyboard::D)
        {
            squareLanes.getPlayer().moveRight();
        }
    }
}