#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP
#endif

#include <algorithm>
#include "Attack.hpp"
#include <vector>

#define VECTOR_ATTACKS_SIZE 4

enum class tagEntity { HERO, ENEMY };
enum class entityStat {CURRENT_HEALTH,MAX_HEALTH,PHYSIC_ATTACK, PHYSIC_DEFENSE, MAGIC_ATTACK, MAGIC_DEFENSE, SPEED, CURRENT_MANA, MAX_MANA};

class Entity {
private:
    std::string name;
    int cHealth, mHealth, pAtk, pDef, mAtk, mDef, speed, cMana, mMana;
    std::vector<Attack*> attack;
    tagEntity tag;

public:
    Entity(tagEntity tag, std::string name, int mHealth, int pAtk, int pDef, int mAtk, int mDef, int speed, int mMana);
    Entity(tagEntity tag, std::string name, int mHealth, int pAtk, int pDef, int mAtk, int mDef, int speed, int mMana, Attack* a1, Attack* a2, Attack* a3, Attack* a4);
    ~Entity();

    void receiveDamage(int);
    void doAttack(int attackPos, std::vector<Entity*> objective);
    void AddAttack(Attack* newAttack);
    void RemoveAttack(int id);



    //Getters
    tagEntity getTag() { return tag; }
    std::string getName() { return name; }
    int getCurrentHealth() { return cHealth; }
    int getMaxHealth() { return mHealth; }
    int getPhysicAtk() { return pAtk; }
    int getPhysicDef() { return pDef; }
    int getMagicAtk() { return mAtk; }
    int getMagicDef() { return mDef; }
    int getSpeed() { return speed; }
    int getMaxMana() { return mMana; }
    int getCurrentMana() { return cMana; }
    size_t getAttacksKnown() { return attack.size(); }
    Attack* getAttack(int i) { return attack[i]; }
};