#include "AlteredStates.hpp"

void StatesManager::ExecuteState(Entity* objective, AlteredState state)
{
	switch (state)
	{
	case AlteredState::POISONED:
		objective->receiveDamage(objective->getMaxHealth() / 16);
		std::cout << objective->getName() << "ha sufrido el envenenamiento..." << std::endl;
		break;
	case AlteredState::BLEEDING:
		objective->receiveDamage(objective->getMaxHealth() / 16);
		break;
	case AlteredState::SLEEPING:

		break;
	case AlteredState::ACCELERATED_HEALING:
		break;
	case AlteredState::INJURED:
		break;
	case AlteredState::PARALIZED:
		break;
	case AlteredState::CURSED:
		break;
	default:
		break;
	}
}

void StatesManager::AddEffect(Entity* objective, int turnsRemaining, AlteredState stateToAdd)
{
	StateActive nState = { objective, stateToAdd };
	if (activeStates.find(nState) != activeStates.end())
		if (activeStates[nState] == -1) {}
		else activeStates[nState] += turnsRemaining;
	else
	{
		activeStates[nState] = turnsRemaining;
	}
}

bool StatesManager::FindActiveState(Entity* objective, int turnsRemaining)
{	
	return false;
}

void StatesManager::RemoveEffect(Entity* objective, AlteredState stateToRemove)
{
	StateActive nState = { objective, stateToRemove };
	if (activeStates.find(nState) != activeStates.end())
		if (activeStates[nState] == -1) {
		//Implementar logica para retirar estado de entidad
		}
		else activeStates.erase(nState);
	else
	{
		std::cout << "Ese efecto no existe en la lista" << std::endl;
	}
}

void StatesManager::Update()
{
	for (auto& [ent, turn] : activeStates)
	{
		ExecuteState(ent.objective, ent.state);
		if (turn == 1) {
			StateActive s{ ent };
			activeStates.erase(s);
		}
		else if (turn == -1) {}
		else turn--;
		
	}
}
