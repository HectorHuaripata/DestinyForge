#pragma once

#include <vector>
#include "GameManager.hpp"

    //TODO: IMPLEMENTAR CLASE BATTLE MANAGER

class BattleManager {
private:
    std::vector<Entity*> group;
    std::vector<Entity*> enemies;
    std::vector<Attack*> attacks;
    std::vector<Entity*> ordenTurnos;
    int cTurn, sAttack;
    Entity* cEntityInTurn;
    BattleState bState;
public:

    

    BattleManager():cTurn(0), sAttack(0), cEntityInTurn(nullptr), bState(BattleState::ACTION){}
    //El siguiente inicializador se debe cambiar a tomar un archivo serializado y cargar los datos
    BattleManager(std::vector<Entity*> group, std::vector<Entity> enemies, std::vector<Attack*> attacks):
        cTurn(0), sAttack(-1), cEntityInTurn(nullptr), bState(BattleState::ACTION){
        //TODO: Agregar una clase extra para las batallas
        this->group = group;
    }

    void ExecuteTurn();
    void ChangeBattleState(BattleState battleState);
    void StartBattle();
    void EndBattle();
    void DefineTurns();
    void Action(int attackID, int objective = 0, bool toRival);

    Entity* getCharacter(int id) {
        if (id < 0 || id >= group.size())
        {
            std::cerr << "Index out of bounds.\n";
            return nullptr;
        }
        return group[id];
    }

    Entity* getEnemy(int id) {
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
    Entity* getcCharacter() { return cEntityInTurn; }
    BattleState getBattleState() const { return bState; }

};