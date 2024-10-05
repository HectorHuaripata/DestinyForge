#include "Entity.hpp"

Entity::Entity(tagEntity tag = tagEntity::ENEMY, std::string name = "Desconocido", int mHealth = 0, int pAtk = 0, int pDef = 0, int mAtk = 0, int mDef = 0, int speed = 0, int mMana = 0) : tag(tag), name(name), mHealth(mHealth), cHealth(mHealth), pAtk(pAtk), pDef(pDef), mAtk(mAtk), mDef(mDef), speed(speed), cMana(mMana), mMana(mMana) {}

Entity::Entity(tagEntity tag = tagEntity::ENEMY, std::string name = "Desconocido", int mHealth = 0, int pAtk = 0, int pDef = 0, int mAtk = 0, int mDef = 0, int speed = 0, int mMana = 0, Attack* a1 = nullptr, Attack* a2 = nullptr, Attack* a3 = nullptr, Attack* a4 = nullptr) : tag(tag), name(name), mHealth(mHealth), cHealth(mHealth), pAtk(pAtk), pDef(pDef), mAtk(mAtk), mDef(mDef), speed(speed), cMana(mMana),mMana(mMana) {

    if (a1 != nullptr) attack.push_back(a1);
    if (a2 != nullptr) attack.push_back(a2);
    if (a3 != nullptr) attack.push_back(a3);
    if (a4 != nullptr) attack.push_back(a4);
}

Entity::~Entity()
{
    for (int i = 0; i < VECTOR_ATTACKS_SIZE; i++)
    {
        //TODO: Eliminar propiamente los elementos del objeto        
    }
}

void Entity::receiveDamage(int damage) {
    cHealth = std::clamp(cHealth - damage, 0, cHealth);
    std::cout << name << " ha recibido " << damage << " de danio." << std::endl;
}

void Entity::doAttack(int attackPos, Entity* objective)
{
    attack[attackPos]->Execute(this, objective);
}

void Entity::AddAttack(Attack* newAttack)
{
    bool alreadyAdded = false;
    if (attack.size() < VECTOR_ATTACKS_SIZE)
    {
        for (int i = 0; i < attack.size(); i++)
        {
            if (attack[i] == newAttack) alreadyAdded = true;
            break;
        }
        if (alreadyAdded) std::cout << "Se agrego el ataque " << newAttack->getName() << std::endl;
        else attack.push_back(newAttack);
    }
    else  std::cout << "Los ataques ya estan completos" << std::endl;
}

void Entity::RemoveAttack(int id)
{
    if (attack.size() > 0)
    {
        attack.erase(attack.begin() + id);
    }
    else  std::cout << "Nohay ningun ataque a borrar" << std::endl;
}
