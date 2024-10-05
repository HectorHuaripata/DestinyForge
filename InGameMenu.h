#pragma once
#include "Menu.h"
#define MAX_INGAME_MENU_OPTIONS 7

class InGameMenu : public Menu{
	
public:
	InGameMenu();
    void draw(sf::RenderWindow& rwindow);
    void moveUp();
    void moveDown();
    void update();

    int MainMenuPressed() override {
        return menuOpcSelected;
    }
    ~InGameMenu();

private:
    int menuOpcSelected;

    sf::Font fntTitle;
    sf::Texture txtrCoin;
    sf::Sprite sptCoin;
    sf::Text ingameMenuOpc[MAX_INGAME_MENU_OPTIONS];
    sf::VertexArray selector;
    sf::Transform tSelector;
};