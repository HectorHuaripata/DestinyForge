#pragma once

#include <vector>
#include "AttackDamage.hpp"

    //TODO: IMPLEMENTAR CLASE BATTLE MANAGER

enum class BattleState { ACTION, MAGIC, INVENTORY, SELECT_TARGET };

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

    BattleManager();
    //El siguiente inicializador se debe cambiar a tomar un archivo serializado y cargar los datos
    BattleManager(std::vector<Entity*>& group, std::vector<Entity*>& enemies, std::vector<Attack*>& attacks):
        cTurn(0), sAttack(0), cEntityInTurn(nullptr), bState(BattleState::ACTION){
        //TODO: Agregar una clase extra para las batallas
        this->group = group;
        this->enemies = enemies;
        this->attacks = attacks;
    }

    void ExecuteTurn();
    void ChangeBattleState(BattleState battleState);
    void StartBattle();
    void EndBattle();
    void DefineTurns();
    void Action();
    bool WinCondition();
    bool LoseCondition();
    //TODO: Decidir si los combates son por turnos o por rondas(grupos de turnos)
    //TODO: Implementar Funcion para apilar ataques en un turno

    Entity* getCharacter(int id) {
        if (id < 0 || id >= group.size())
        {
            std::cerr << "Index out of bounds.\n";
            //TODO: Implementar un throw para que envie un error.
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
        return enemies[id];
    }

    inline const size_t&    getGroupSize() const { return this->group.size(); }
    inline const size_t&    getEnemiesSize() const { return this->enemies.size(); }
    inline const int        getTurn() const { return this->cTurn; }
    Entity* getcCharacter() { return cEntityInTurn; }
    inline BattleState getBattleState() { return this->bState; }

};