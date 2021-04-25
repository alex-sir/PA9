/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: NSquare
*/

#include "MainMenu.h"

void MainMenu::loadBackground(void)
{

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
    gameTitle.setString("NSquare");
    gameTitle.setCharacterSize(100);
    gameTitle.setFillColor(sf::Color::Black);
    gameTitle.setPosition(sf::Vector2f(25.0f, 0.0f));

    // Adding the text to 
    menuText.push_back(gameTitle);
}