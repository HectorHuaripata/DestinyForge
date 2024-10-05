#pragma once
#include "Menu.h"

#define MAX_MAIN_MENU_OPTIONS 4

class MainMenu : public Menu{

public:
    MainMenu();
    void draw(sf::RenderWindow& rwindow);
    void moveUp();
    void moveDown();
    void isSelected();

    int MainMenuPressed() override {
        return MainMenuSelected;
    }
    ~MainMenu();

private:
    int MainMenuSelected;

    sf::Font fntTitle;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text mainMenuOpc[MAX_MAIN_MENU_OPTIONS];
    sf::VertexArray selector;
    sf::Transform tSelector;
};