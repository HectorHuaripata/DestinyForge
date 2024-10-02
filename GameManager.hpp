#pragma once
#include "AttackDamage.hpp"
#include "BattleMenu.hpp"
#include "BattleManager.hpp"
#include "InGameMenu.h"

#include <vector>

class MainMenu;

enum class BattleState { ACTION, MAGIC, INVENTORY, SELECT_TARGET };

enum class GameState { START, WORLD_MAP, DUNGEON, BATTLE, DIALOGUE, SHOP };

#define MAX_TEAM_MEMBERS 5

#define GM GameManager::getInstance()

class GameManager {
private:
    Menu* cMenu;
    BattleManager* bManager;
    GameState gState;
    Entity* cEntityInTurn;

    GameManager() : cEntityInTurn(nullptr), cMenu(nullptr), gState(GameState::START) { 
        bManager = new BattleManager;
    }
    ~GameManager(){}
public:

    static GameManager& getInstance() {
        static GameManager gm;
        return gm;
    }
    GameManager(GameManager const&) = delete;
    void operator=(GameManager const&) = delete;

    void Initialize(sf::RenderWindow& rwindow); //Carga toda la informacion guardada
    void Update(sf::RenderWindow& rwindow, sf::Event& ev);
    void Quit();

    

    //Cambios de Estado
    void StartMap();
    void ExecuteTurn();
    void ChangeGameState(GameState gameState);

    GameState   getGameState() const { return gState; }
    Menu*       getCMenu() { return cMenu; }
    
    
    
};