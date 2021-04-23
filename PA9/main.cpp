/*
    Programmer: Alex Carbajal
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 22, 2021
    Description: SquareN
*/

#include <SFML/Graphics.hpp>

#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SquareN", sf::Style::Default);

    Player player(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 200.0f));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.move();

        window.clear(sf::Color(200, 200, 200));
        window.draw(player);
        window.display();
    }

    return 0;
}