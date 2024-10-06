#pragma once

#include "Menu.h"
#include "RoundedRectangle.hpp"
#define BATTLE_MENU_OPTIONS 4
#define BAR_MAX_SIZE 200

class BattleMenu : public Menu {

public:
    BattleMenu();
    void draw(sf::RenderWindow& rwindow);
    void moveUp();
    void moveDown();
    void update();

    int MainMenuPressed() override {
        return menuOpcSelected;
    }

    ~BattleMenu();

private:
    int menuOpcSelected;

    sf::Font fntTitle;

    RoundedRectangle baseRectangle;
    sf::Text battleMenuOpc[BATTLE_MENU_OPTIONS];

    sf::Text nameMemberGroup;
    sf::RectangleShape healthBarGroup;
    sf::RectangleShape manaBarGroup;

    sf::Text nameMemberEnemies;
    sf::RectangleShape healthBarEnemies;
    sf::RectangleShape manaBarEnemies;

    sf::Text cEntityName;

    sf::VertexArray selector;
    sf::Transform tSelector;
};