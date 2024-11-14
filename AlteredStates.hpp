#pragma once
#include "Entity.hpp"
#include <unordered_map>

enum class AlteredState{ POISONED, BLEEDING, SLEEPING, ACCELERATED_HEALING, INJURED, PARALIZED,
					CURSED};

struct StateActive
{
	Entity* objective;
	AlteredState state;

	bool operator==(const StateActive& other) const {
		return this->objective == other.objective && this->state == other.state;
	};
};

namespace std {
	template<>
	struct hash<StateActive>
	{
		size_t operator()(const StateActive& key) const
		{
			return hash<int>()(5); //hash<Entity*>()(key.objective) ;//^ hash<AlteredState>()(key.state);
		}
	};
}


class StatesManager {
private:
	std::unordered_map<StateActive, int> activeStates;

	void ExecuteState(Entity* objective,AlteredState state);


public:

	void AddEffect(Entity* objective, int turnsRemaining, AlteredState stateToAdd);
	bool FindActiveState(Entity* objective, int turnsRemaining);
	void RemoveEffect(Entity* ojective, AlteredState stateToRemove);
	void Update();
};