/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: Square Lanes
*/

#include "Menu.h"

Menu::Menu()
{
    markerPosition = 0;
    minMarkerPosition = 0;
    maxMarkerPosition = 0;
}

// Must return a reference due to the way sf::Text works
sf::Font& Menu::getFontRaleway(void)
{
    return fontRaleway;
}

sf::Sprite& Menu::getBackground(void)
{
    return background;
}

std::vector<sf::Text>& Menu::getMenuText(void)
{
    return menuText;
}

std::vector<sf::RectangleShape>& Menu::getMenuRectangles(void)
{
    return menuRectangles;
}

sf::RectangleShape& Menu::getMarker(void)
{
    return marker;
}

int Menu::getMarkerPosition(void)
{
    return markerPosition;
}

int Menu::getMinMarkerPosition(void)
{
    return minMarkerPosition;
}

int Menu::getMaxMarkerPosition(void)
{
    return maxMarkerPosition;
}

void Menu::setMarkerPosition(int newMarkerPosition)
{
    markerPosition = newMarkerPosition;
}

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
void Menu::loadFont(void)
{
    fontRaleway.loadFromFile("Assets/RalewayFont/Raleway-Light.ttf");
}