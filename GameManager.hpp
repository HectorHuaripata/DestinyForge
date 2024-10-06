#pragma once
#include "AttackDamage.hpp"
#include "BattleMenu.hpp"
#include "BattleManager.hpp"
#include "InGameMenu.h"
#include "MainMenu.h"

enum class GameState { START, WORLD_MAP, DUNGEON, BATTLE, DIALOGUE, SHOP };

enum class BattleState;

#define MAX_TEAM_MEMBERS 5

#define GM GameManager::getInstance()

class GameManager {
private:
    Menu* cMenu;
    BattleManager* bManager;
    GameState gState;

    GameManager() : cMenu(nullptr), gState(GameState::START), bManager(nullptr) {}
    ~GameManager(){}
public:

    static GameManager& getInstance() {
        static GameManager gm;
        return gm;
    }
    GameManager(GameManager const&) = delete;
    void operator=(GameManager const&) = delete;

    void Initialize(); //Carga toda la informacion guardada
    void Update(sf::RenderWindow& rwindow, sf::Event& ev);
    void Quit();

    

    //Cambios de Estado
    void StartMap();
    void ChangeGameState(GameState gameState);
    void ChangeBattleState(BattleState battleState);
    void Action();

    inline const GameState& getGameState() const { return gState; }
    BattleState getBattleState() { return this->bManager->getBattleState(); }
    Menu*       getCMenu() { return this->cMenu; }
    inline Entity* getCCharacter() const { return this->bManager->getcCharacter(); }
    inline Entity* getGroupMember(int id) const { return this->bManager->getCharacter(id); }
    inline Entity* getEnemiesMember(int id) const { return this->bManager->getEnemy(id); }
    
    
    
};