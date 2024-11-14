#undef main

#include "Game.hpp"

int main() {

    Game game;

    game.run();
    
}

/*#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameManager.hpp"
#include "RoundedRectangle.hpp"

int main() {

    sf::RenderWindow mainWindow = sf::RenderWindow(sf::VideoMode(800, 600), "Nueva Ventana", sf::Style::None);

    sf::Event ev;

    mainWindow.setFramerateLimit(60);

    GM.Initialize();


    while (mainWindow.isOpen())
    {
        GM.Update(mainWindow, ev);


    }

    GM.Quit();

    return 0;
}*/