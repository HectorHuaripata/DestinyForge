#include "ComponentsEffect.hpp"

void Components::Effect::EffectDamage::Execute(Entity* source, Entity* objective)
{
	//TODO: Arreglar sistema de ataque
	//calculateDamage(source, objective, );
	objective->receiveDamage(damage);
}

void Components::Effect::EffectDamage::Update(Entity* source){}

void Components::Effect::EffectDamage::onAcquire(Entity* source){}

void Components::Effect::EffectDamage::onRemove(Entity* source){}

int Components::Effect::EffectDamage::calculateDamage(Entity* source, Entity* objective, AttackType damageType)
{
	switch (damageType)
	{
	case AttackType::PHYSICAL:
		damage = source->getPhysicAtk() - objective->getPhysicDef();
		break;
	case AttackType::MAGIC:
		damage = source->getMagicAtk() - objective->getMagicDef();
		break;
	case AttackType::STATE:
		damage = 0;
		break;
	default:
		break;
	}
	
}
