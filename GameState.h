#pragma once
#include "State.h"
class GameState :
    public State
{
private:

    Character player;

    //Functions
    void initKeybinds();
    
public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~GameState();

    //Functions
    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

