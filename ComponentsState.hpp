#pragma once

#include "Component.hpp"

namespace Component::State {
	class StateArmorStatsBuff : ComponentState {
	public:
		void Execute(Entity* source, Entity* objective){}
		void Update(Entity* source) {}
		void onAcquire(Entity* source) {}
		void onRemove(Entity* source) {}
	private:
		int buffAmount;
	};

	//class StateAddPoison : ComponentState {
	//public:
	//	void Execute(Entity* objective);
	//	void Update(Entity* source);
	//	void onAcquire(Entity* source);
	//	void onRemove(Entity* source);
	//private:

	//};
	// EstadoAlterado: Representa un estado temporal que afecta a una entidad
	// Marca: Un estado especial que puede activar efectos adicionales
	// BuffPersistente: Un buff que dura hasta que se elimina manualmente o bajo ciertas condiciones
	// DebuffPersistente: Un debuff que dura hasta que se elimina manualmente o bajo ciertas condiciones
}
