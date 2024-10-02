#pragma once
#ifndef ATTACK_DAMAGE_HPP
#define ATTACK_DAMAGE_HPP
#endif

#include "Entity.hpp"

class AttackDamage : public Attack {
private:
    int power, baseDamage;
    AttackType type;
    TargetRange range;
    TargetObjective objectiveTeam;
    std::string name;
public:
    AttackDamage(std::string name, int power, int baseDamage, AttackType attackType, TargetRange range, TargetObjective objTeam);
    ~AttackDamage();
    void        Execute(Entity* source, std::vector<Entity*> objective);
    AttackType  GetType() { return type; }
    TargetRange getTargetType() { return range; }
    TargetObjective  getTargetSide() { return objectiveTeam; }
    std::string getName() { return name; }
};