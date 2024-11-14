#pragma once

#include "Attack.hpp"
#include "Entity.hpp"
#include "Component.hpp"

	class EffectDamage : public Component {
	public:
		EffectDamage(int damage);
		~EffectDamage();

		void Execute(Entity* source, Entity* objective);
		void Update(Entity* source);
		void onAcquire(Entity* source);
		void onRemove(Entity* source);

		int calculateDamage(Entity* source, Entity* objective, AttackType damageType);
	private:
		int damage;
	};

	//Implementar Componente Atacar
	//Implementar Componente HacerDanioCritico
	//Implementar Componente Aniadir estado
	//Implementar Componente MenuSeleccionable
