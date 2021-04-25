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
private:
	sf::Text gameTitle;

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
};