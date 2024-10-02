#pragma once

#include <vector>
#include "MainMenu.h"

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

    

    BattleManager():cTurn(0), sAttack(0), cEntityInTurn(nullptr), bState(BattleState::ACTION){
        attacks.push_back(new AttackDamage("Ataque fisico", 8, 5, AttackType::PHYSICAL, TargetRange::SINGLE, TargetObjective::RIVAL));
        attacks.push_back(new AttackDamage("Ataque magico", 10, 7, AttackType::MAGIC, TargetRange::SINGLE, TargetObjective::RIVAL));
        attacks.push_back(new AttackDamage("Tormenta", 12, 10, AttackType::MAGIC, TargetRange::TEAM, TargetObjective::RIVAL));

        group.push_back(new Entity(tagEntity::HERO, "Hector", 50, 8, 6, 4, 4, 10, 20, attacks[0], attacks[1], nullptr, nullptr));
        group.push_back(new Entity(tagEntity::HERO, "Miguel", 60, 10, 4, 4, 6, 8, 12, attacks[0], attacks[1], attacks[2], nullptr));

        enemies.push_back(new Entity(tagEntity::ENEMY, "Liche", 60, 7, 5, 6, 6, 8, 18, attacks[0], attacks[1], nullptr, nullptr));
        enemies.push_back(new Entity(tagEntity::ENEMY, "Huargo", 40, 7, 5, 3, 3, 8, 18, attacks[0], attacks[1], attacks[2], nullptr));
    }
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