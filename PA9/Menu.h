/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: NSquare
*/

#pragma once

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/* Menu Types
    MainMenu
    Play
        World1
        World2
        World3
        PauseMenu (?)
    Instructions
    Credits
*/

class Menu
{
public:
    // Getters
    // Must return a reference due to the way sf::Text works
    sf::Font& getFontRaleway(void);
    std::vector<sf::Text> getMenuText(void) const;

    /*
        Function: loadFont()
        Author: Alex Carbajal
        Date Created: 04/24/2021
        Date Last Modified: 04/24/2021
        Description: Loads a font for the menu.
        Input parameters: N/A
        Output parameters: N/A
        Returns: N/A
        Preconditions: None
        Postconditions: A font is loaded for the menu.
    */
    void loadFont(void);

    virtual void loadBackground(void) = 0;
    virtual void loadMusic(void) = 0;
    virtual void loadText(void) = 0;
protected:
    sf::Font fontRaleway; // The font to be used in the game
    sf::Music music; // Music that will be playing when the user is in the menu
    std::vector<sf::Text> menuText; // Dynamic array containing all the text for a menu
private:
};