#include "Entity.hpp"

Entity::Entity() : name(""), cHealth(0), mHealth(0), pAtk(0), pDef(0), mAtk(0), mDef(0), speed(0), cMana(0), mMana(0), tag(tagEntity::NONE)
{

}

Entity::Entity(tagEntity tag = tagEntity::ENEMY, std::string name = "Desconocido", int mHealth = 0, int pAtk = 0, int pDef = 0, int mAtk = 0, int mDef = 0, int speed = 0, int mMana = 0) : tag(tag), name(name), mHealth(mHealth), cHealth(mHealth), pAtk(pAtk), pDef(pDef), mAtk(mAtk), mDef(mDef), speed(speed), cMana(mMana), mMana(mMana) {
    attack.size();
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
    std::cout << name << " ha recibido " << damage << " de danio.\n";
}

void Entity::reduceMana(int amount)
{
    cMana = std::clamp(cMana - amount, 0, cMana);
    std::cout << name << " ha consumido " << amount << " de mana.\n";
}

void Entity::doAttack(int attackPos, Entity* objective)
{
}

void Entity::AddAttack(Attack* newAttack)
{
    if (attack.empty())
    {
        attack.push_back(newAttack);
    }
    else if (attack.size() < VECTOR_ATTACKS_SIZE)
    {
        bool alreadyAdded = false;
        for (int i = 0; i < attack.size(); i++)
        {
            if (attack[i] == newAttack) alreadyAdded = true;
            break;
        }
        if (alreadyAdded) std::cout << "Se agrego el ataque " << newAttack->getName() << "\n";
        else attack.push_back(newAttack);
    }
    else  std::cout << "Los ataques ya estan completos\n";
}

void Entity::RemoveAttack(int id)
{
    if (attack.size() > 0)
    {
        attack.erase(attack.begin() + id);
    }
    else  std::cout << "Nohay ningun ataque a borrar\n";
}
