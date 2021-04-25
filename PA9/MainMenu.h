/*
	Programmer: Alex Carbajal
	Class: CptS 122, Spring 2021; Lab Section 03
	Programming Assignment: Programming Assignment 9
	Date: April 22, 2021
	Description: NSquare
*/

#pragma once

#include "Menu.h"

class MainMenu : public Menu
{
public:
	void loadBackground(void);
	void loadMusic(void);
	void loadText(void);
	void loadRectangles(void);
private:
	sf::Text gameTitle;
	sf::Text play;
	sf::Text instructions;
	sf::Text exit;
	sf::RectangleShape r1;
	sf::RectangleShape r2;
	sf::RectangleShape r3;
	sf::RectangleShape r4;

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
	void makeGameTitle(void);

	/*
		Function: makePlayText()
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
	void makePlayText(void);

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
	void makeInstructionsText(void);

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
	void makeExitText(void);

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
	void makeRectangle(sf::RectangleShape& r, float size, float rotation, float olThickness, sf::Color olColor);
};