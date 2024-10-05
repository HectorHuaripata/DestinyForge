#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

    class Menu {
    public:
        virtual void draw(sf::RenderWindow& rwindow) = 0;
        virtual void moveUp() = 0;
        virtual void moveDown() = 0;
        virtual void update() = 0;
        virtual int MainMenuPressed() = 0;
    };