#pragma once

#include "Menu.h"
#include "RoundedRectangle.hpp"
#include "GameManager.hpp"
#define BATTLE_MENU_OPTIONS 4

class BattleMenu : public Menu {

public:
    BattleMenu();
    void draw(sf::RenderWindow& rwindow);
    void moveUp();
    void moveDown();
    void isSelected();

    int MainMenuPressed() override {
        return menuOpcSelected;
    }

    ~BattleMenu();

private:
    int menuOpcSelected;

    sf::Font fntTitle;

    RoundedRectangle baseRectangle;
    sf::Text battleMenuOpc[BATTLE_MENU_OPTIONS];

    sf::VertexArray selector;
    sf::Transform tSelector;
};