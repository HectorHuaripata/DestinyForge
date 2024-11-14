#pragma once

#include <algorithm>
#include <vector>
#include <string>
#include "Attack.hpp"

#define VECTOR_ATTACKS_SIZE 4

enum class tagEntity { HERO, ENEMY, NONE };

enum class entityStat {CURRENT_HEALTH, MAX_HEALTH, PHYSIC_ATTACK, PHYSIC_DEFENSE, MAGIC_ATTACK, MAGIC_DEFENSE, SPEED, CURRENT_MANA, MAX_MANA};

class Entity {
private:
    std::string name;
    int cHealth, mHealth, pAtk, pDef, mAtk, mDef, speed, cMana, mMana;
    std::vector<Attack*> attack;
    tagEntity tag;

public:
    Entity();
    Entity(tagEntity tag, std::string name, int mHealth, int pAtk, int pDef, int mAtk, int mDef, int speed, int mMana);
    ~Entity();

    void receiveDamage(int);
    void reduceMana(int n);
    void doAttack(int attackPos, Entity* objective);
    void AddAttack(Attack* newAttack);
    void RemoveAttack(int id);

    //Getters
    tagEntity getTag() { return this->tag; }
    std::string getName() { return this->name; }
    inline const int getCurrentHealth() const { return this->cHealth; }
    inline const int getMaxHealth() const { return this->mHealth; }
    inline const int getPhysicAtk() const { return this->pAtk; }
    inline const int getPhysicDef() const { return this->pDef; }
    inline const int getMagicAtk() const { return this->mAtk; }
    inline const int getMagicDef() const { return this->mDef; }
    inline const int getSpeed() const { return this->speed; }
    inline const int getMaxMana() const{ return this->mMana; }
    inline const int getCurrentMana() const { return this->cMana; }
    inline const size_t getAttacksKnown() const { return this->attack.size(); }
    //Attack* getAttack(int i) { return this->attack[i]; }
    std::string getAttackName(int i) { return this->attack.at((size_t)i)->getName(); }
};