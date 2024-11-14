#include "Attack.hpp"
#include "AlteredStates.hpp"

class AttackState : public Attack {
private:
	unsigned int cost, priority;
	float probability;
	std::string name, id;

	AttackType type;
	TargetRange range;
	AlteredState altState;

public:
	AttackState(std::string name, std::string id, int cost, float probability, TargetRange range, AlteredState aState, unsigned int priority):name(name), id(id), cost(cost), probability(probability), type(AttackType::STATE), range(range), altState(aState), priority(priority) {}
	~AttackState();

	void Execute(Entity* source, Entity* objective, BattleManager* bm);

	inline const std::string& getName() const { return this->name; }
	inline const std::string& getId() const { return this->id; }
	inline AttackType GetType() { return this->type; }
	inline TargetRange getTargetType() { return this->range; }
	inline const unsigned int getPriority() const { return this->priority; }
	inline const unsigned int getCost() const { return this->cost; }

};