#pragma once

#include "Entity.hpp"
#include "AttackState.hpp"
#include "AttackDamage.hpp"

#include <vector>

class Attack;

enum class BattleState { ACTION, MAGIC, INVENTORY, SELECT_TARGET };

class BattleManager {
private:
    std::vector<Entity*> group;
    std::vector<Entity*> enemies;
    std::vector<Attack*> attacks;
    //TODO: crear clases de contenedores para las entidades en batalla, de manera que almacenen los buffs, debuffs y otros atributos que tienen EN BATALLA
    std::vector<Entity*> ordenTurnos;
    //State handler??
    //StatesManager stManager;
    BattleState bState;

    int cTurn, sAttack;
    Entity* cEntityInTurn;
    
    

public: 

    BattleManager();

    //El siguiente inicializador se debe cambiar a tomar un archivo serializado y cargar los datos
    //BattleManager(std::vector<Entity*>& group, std::vector<Entity*>& enemies, std::vector<Attack*>& attacks):
    //    cTurn(0), sAttack(0), cEntityInTurn(nullptr), bState(BattleState::ACTION){
    //    //TODO: Agregar una clase extra para las batallas
    //    this->group = group;
    //    this->enemies = enemies;
    //    this->attacks = attacks;
    //}

    void ExecuteTurn();
    void ChangeBattleState(BattleState battleState);
    void StartBattle();
    void EndBattle();
    void DefineTurns();
    void NextTurn();
    void Action();
    bool WinCondition();
    bool LoseCondition();
    //TODO: Decidir si los combates son por turnos o por rondas(grupos de turnos)
    //TODO: Implementar Funcion para apilar ataques en un turno

    Entity* getCharacter(int id) {
        if (id < 0 || id >= group.size())
        {
            throw - 1;
        }
        return group[id];
    }

    Entity* getEnemy(int id) {
        if (id < 0 || id >= enemies.size())
        {
            throw -1;
        }
        return enemies[id];
    }

    inline const size_t&    getGroupSize() const { return this->group.size(); }
    inline const size_t&    getEnemiesSize() const { return this->enemies.size(); }
    inline const int        getTurn() const { return this->cTurn; }
    Entity* getcCharacter() { return this->cEntityInTurn; }
    inline BattleState getBattleState() { return this->bState; }

};