#pragma once
#include <string>
#include <map>
#include "AttackDamage.hpp"

class GameEntity {

private:
	std::string name;
	int level, strength, dexterity, constitution, intelligence, wisdom, charisma, speed, mHealth, cHealth, mana;
	float hitRate, critRate, evasion;
	Attack* magicSet[4];
	std::multimap<int, int> magicPerLevel;
};