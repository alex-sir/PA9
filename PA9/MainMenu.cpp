/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "MainMenu.h"

MainMenu::~MainMenu()
{
    music.setLoop(false);
    music.stop();
}

void MainMenu::loadBackground(void)
{
    backgroundTexture.loadFromFile("Assets/Backgrounds/MainMenuBackground.png");
    background.setTexture(backgroundTexture);
    background.setPosition(sf::Vector2f(0.0f, 0.0f));
}

void MainMenu::loadMusic(void)
{
    music.openFromFile("Assets/Music/mainMenu.flac");
    music.setLoop(true);
    music.play();
}

void MainMenu::loadText(void)
{
    makeGameTitle();
    makePlayText();
    makeInstructionsText();
    makeExitText();
}

void MainMenu::loadRectangles(void)
{
    // Main square
    sf::RectangleShape r1(sf::Vector2f(500.f, 500.f));
    r1.setOrigin(r1.getSize().x / 2, r1.getSize().y / 2);
    r1.setPosition(1250.0f, 500.0f);
    r1.setFillColor(sf::Color::Black);

    // Other squares
    makeRectangle(r2, 300.f, 45.f, 3.f, sf::Color(111, 16, 230)); // Purple
    makeRectangle(r3, 430.f, 0.f, 3.f, sf::Color(42, 219, 226)); // Cyan
    makeRectangle(r4, 460.f, 45.f, 3.f, sf::Color(233, 39, 208)); // Pink

    // Put squares into rectangles list
    menuRectangles.push_back(r1);
    menuRectangles.push_back(r2);
    menuRectangles.push_back(r3);
    menuRectangles.push_back(r4);
}

/*
    Function: makeRectangle()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/24/2021
    Description: Makes a rectangle by setting its properties.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: A rectangle is made.
*/
void MainMenu::makeRectangle(sf::RectangleShape& r, float size, float rotation, float olThickness, sf::Color olColor)
{
    r.setSize(sf::Vector2f(size, size));
    r.setOrigin(size / 2, size / 2);
    r.setPosition(1250.f, 500.f);
    r.setFillColor(sf::Color::Transparent);
    r.setRotation(rotation);
    r.setOutlineThickness(olThickness);
    r.setOutlineColor(olColor);
}

/*
    Function: makeGameTitle()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/24/2021
    Description: Make the game title (NSquare) to display on the main menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The game title is made.
*/
void MainMenu::makeGameTitle(void)
{
    // Setting all the properties for the title
    gameTitle.setFont(getFontRaleway());
    gameTitle.setString("Square Lanes");
    gameTitle.setCharacterSize(100);
    gameTitle.setFillColor(sf::Color(220, 220, 220));
    gameTitle.setPosition(sf::Vector2f(50.0f, 0.0f));

    // Adding the text to the list of texts
    menuText.push_back(gameTitle);
}

/*
    Function: makePlayText()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/24/2021
    Description: Make the 'Play' text display on the main menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The 'Play' text is displayed on the main menu.
*/
void MainMenu::makePlayText(void)
{
    // Setting all the properties for the text
    play.setFont(getFontRaleway());
    play.setString("Play");
    play.setCharacterSize(75);
    play.setFillColor(sf::Color(220, 220, 220));
    play.setPosition(sf::Vector2f(50.0f, 150.0f));

    // Adding the text to the list of texts
    menuText.push_back(play);
}

/*
    Function: makeInstructionsText()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/24/2021
    Description: Make the 'Instructions' text display on the main menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The 'Instructions' text is displayed on the main menu.
*/
void MainMenu::makeInstructionsText(void)
{
    // Setting all the properties for the text
    instructions.setFont(getFontRaleway());
    instructions.setString("Instructions");
    instructions.setCharacterSize(75);
    instructions.setFillColor(sf::Color(220, 220, 220));
    instructions.setPosition(sf::Vector2f(50.0f, 245.0f));

    // Adding the text to the list of texts
    menuText.push_back(instructions);
}

/*
    Function: makeExitText()
    Author: Alex Carbajal
    Date Created: 04/24/2021
    Date Last Modified: 04/24/2021
    Description: Make the 'Exit' text display on the main menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The 'Exit' text is displayed on the main menu.
*/
void MainMenu::makeExitText(void)
{
    // Setting all the properties for the text
    exit.setFont(getFontRaleway());
    exit.setString("Exit");
    exit.setCharacterSize(75);
    exit.setFillColor(sf::Color(220, 220, 220));
    exit.setPosition(sf::Vector2f(50.0f, 340.0f));

    // Adding the text to the list of texts
    menuText.push_back(exit);
}

void MainMenu::loadMarker(void)
{
    makeMarker();

    // Marker positions
    markerPosition = minMarkerPosition = 1;
    maxMarkerPosition = 3;
}

/*
    Function: makeMarker()
    Author: Alex Carbajal
    Date Created: 04/25/2021
    Date Last Modified: 04/25/2021
    Description: Makes the marker for the main menu.
    Input parameters: N/A
    Output parameters: N/A
    Returns: N/A
    Preconditions: None
    Postconditions: The marker for the main menu is made.
*/
void MainMenu::makeMarker(void)
{
    float size = 25.f;

    marker.setSize(sf::Vector2f(size, size));
    marker.setOrigin(size / 2, size / 2);
    marker.setPosition(25.f, 195.f);
    marker.setFillColor(sf::Color::Black);
    marker.setOutlineThickness(1.f);
    marker.setOutlineColor(sf::Color(255, 165, 0)); // Orange
    marker.setRotation(45);
}

void MainMenu::loadMiscAssets(void)
{
    // WASD
    controlsWASDTexture.loadFromFile("Assets/Misc/WASD.png");
    controlsWASD.setTexture(controlsWASDTexture);
    controlsWASD.setPosition(sf::Vector2f(0.0f, 0.0f));

    // Enter
    controlsEnterTexture.loadFromFile("Assets/Misc/Enter.png");
    controlsEnter.setTexture(controlsEnterTexture);
    controlsEnter.setPosition(sf::Vector2f(0.0f, 0.0f));

    miscAssets.push_back(controlsWASD);
    miscAssets.push_back(controlsEnter);
}