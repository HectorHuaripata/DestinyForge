#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
    //Variables
    sf::Font font1;
    sf::RectangleShape background;

    Button* gamestate_btn;

    //Functions
    void initFonts();
    void initKeybinds();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~MainMenuState();

    //Functions
    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

