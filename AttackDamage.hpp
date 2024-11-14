#pragma once

#include "Attack.hpp"

class BattleManager;

class AttackDamage : public Attack {
private:
    std::string id, name;
    unsigned int power, cost, priority, accuracy;
    AttackType type;
    TargetRange range;   
    // ... otros atributos para efectos secundarios, condiciones especiales, etc.
public:
    AttackDamage(std::string id, std::string name, unsigned int power, unsigned int cost, unsigned int priority, AttackType type, TargetRange range, unsigned int accuracy);
    ~AttackDamage();

    //void CalculateDamage(Entity* source, Entity* objective);
    //void ApplyEffects(std::vector<Entity*> objective); //Aplica efectos como veneno, inmunidad, etc
    //bool itFails(); //Cuando un ataque tiene probabilidades de fallar
    void Execute(Entity* source, Entity* objective);

    //Getters and Setters
    inline const std::string& getName() const { return this->name; }
    inline const std::string& getId() const { return this->id; }
    inline AttackType GetType() { return this->type; }
    inline TargetRange getTargetType() { return this->range; }
    inline const unsigned int getPriority() const { return this->priority; }
    inline const unsigned int getCost() const { return this->cost; }

    inline const unsigned int getPower() const { return this->power; }
    
    
};