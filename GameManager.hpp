#pragma once
#include "AttackDamage.hpp"
#include "BattleMenu.hpp"
#include "InGameMenu.h"

#include <vector>

class MainMenu;

enum class BattleState { ACTION, MAGIC, INVENTORY, SELECT_TARGET };

enum class GameState { START, WORLD_MAP, DUNGEON, BATTLE, DIALOGUE, SHOP };

#define MAX_TEAM_MEMBERS 5

#define GM GameManager::getInstance()

class GameManager {
private:
    std::vector<Entity*> group;
    std::vector<Entity*> enemies;
    std::vector<Attack*> attacks;
    std::vector<Entity*> ordenTurnos;
    Menu* cMenu;
    int cTurn, sAttack;
    GameState gState;
    Entity* cEntityInTurn;
    BattleState bState;

    GameManager() :cTurn(-1), sAttack(0), cEntityInTurn(nullptr), cMenu(nullptr), gState(GameState::START), bState(BattleState::ACTION) { }
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
    void StartBattle();
    void StartMap();
    void ExecuteTurn();
    void ChangeGameState(GameState gameState);
    void ChangeBattleState(BattleState battleState);

    void DefineTurns();

    Entity*     getPlayer(int id) {
        if (id < 0 || id >= group.size())
        {
            std::cerr << "Index out of bounds.\n";
            return nullptr;
        }

        return group[id];
    }
    Entity*     getEnemy(int id) {
        if (id < 0 || id >= enemies.size())
        {
            std::cerr << "Index out of bounds.\n";
            return nullptr;
        }

        return group[id];
    }

    size_t      getGroupSize() { return group.size(); }
    size_t      getEnemiesSize() { return enemies.size(); }
    int         getTurn() { return cTurn; }
    Entity*     getcCharacter() { return cEntityInTurn; }
    GameState   getGameState() const { return gState; }
    BattleState getBattleState() const { return bState; }
    Menu*       getCMenu() { return cMenu; }
    
    
    
};