#include <SDL.h>
#undef main
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameManager.hpp"
#include "RoundedRectangle.hpp"

int main() {

    sf::RenderWindow mainWindow = sf::RenderWindow(sf::VideoMode(800, 600), "Nueva Ventana", sf::Style::None);
    
    sf::Event ev;

    GM.Initialize(mainWindow);


    while (mainWindow.isOpen())
    {
        GM.Update(mainWindow, ev);

        
    }

    GM.Quit();

    return 0;
}