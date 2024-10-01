#include "AttackDamage.hpp"

AttackDamage::AttackDamage(std::string name, int power, int baseDamage, AttackType attackType, TargetRange range, TargetSide objTeam) : name(name), power(power), baseDamage(baseDamage), type(attackType), range(range), objectiveTeam(objTeam) {}

AttackDamage::~AttackDamage() {}

void AttackDamage::Execute(Entity* source, std::vector<Entity*> objective) {
    int damage = 0;
    if (type == AttackType::PHYSICAL)
        damage = power * source->getPhysicAtk() / objective->getPhysicDef() + baseDamage;
    else if (type == AttackType::MAGIC)
        damage = power * source->getMagicAtk() / objective->getMagicDef() + baseDamage;
    objective->receiveDamage(damage);
}