#include "AttackDamage.hpp"

AttackDamage::AttackDamage(std::string id, std::string name, unsigned int power, unsigned int cost, unsigned int priority, AttackType type, TargetRange range, unsigned int accuracy) : id(id), name(name), power(power), cost(cost), priority(priority), type(type), range(range), accuracy(accuracy) {}

AttackDamage::~AttackDamage() {}

void AttackDamage::Execute(Entity* source, Entity* objective)
{

}
