#pragma once
#ifndef ATTACK_DAMAGE_HPP
#define ATTACK_DAMAGE_HPP
#endif

#include "Entity.hpp"

class AttackDamage : public Attack {
private:
    int power, cost;
    AttackType type;
    TargetRange range;
    TargetObjective objectiveTeam;
    std::string name;
    /*
    int accuracy;
    int priority;*/
    // ... otros atributos para efectos secundarios, condiciones especiales, etc.
public:
    AttackDamage(std::string name, int power, int cost, AttackType attackType, TargetRange range, TargetObjective objTeam);
    ~AttackDamage();
    void Execute(Entity* source, Entity* objective);
    inline const AttackType& GetType() const { return this->type; }
    TargetRange getTargetType() { return this->range; }
    TargetObjective  getTargetSide() { return this->objectiveTeam; }
    //inline const int getCost() const { return this->cost; }
    inline const std::string& getName() const { return this->name; }
    
};