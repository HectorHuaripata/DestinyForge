#include "ComponentsEffect.hpp"

EffectDamage::EffectDamage(int damage): damage(damage)
{
	
}

EffectDamage::~EffectDamage()
{
}

void EffectDamage::Execute(Entity* source, Entity* objective)
{
	//TODO: Arreglar sistema de ataque
	//calculateDamage(source, objective, );
	objective->receiveDamage(damage);
}

void EffectDamage::Update(Entity* source){}

void EffectDamage::onAcquire(Entity* source){}

void EffectDamage::onRemove(Entity* source){}

int EffectDamage::calculateDamage(Entity* source, Entity* objective, AttackType damageType)
{
	switch (damageType)
	{
	case AttackType::PHYSICAL:
		this->damage = source->getPhysicAtk() - objective->getPhysicDef();
		break;
	case AttackType::MAGIC:
		this->damage = source->getMagicAtk() - objective->getMagicDef();
		break;
	case AttackType::STATE:
		this->damage = 0;
		break;
	default:
		break;
	}
	
}
