#include "AttackDamage.hpp"

AttackDamage::AttackDamage(std::string name, int power, int cost, AttackType attackType, TargetRange range, TargetObjective objTeam) : name(name), power(power), cost(cost), type(attackType), range(range), objectiveTeam(objTeam) {}

AttackDamage::~AttackDamage() {}

void AttackDamage::Execute(Entity* source, Entity* objective) {
    int damage = 0;
    std::cout << source->getName() << " ataco con " << name << " a " << objective->getName() << std::endl;
    if (type == AttackType::PHYSICAL)
        damage = power * source->getPhysicAtk() / objective->getPhysicDef();
    else if (type == AttackType::MAGIC)
        damage = power * source->getMagicAtk() / objective->getMagicDef();
    source->reduceMana(cost);
    objective->receiveDamage(damage);
}