#include "FiniteStateMachine.h"

CooldownTimer* const FiniteStateMachine::getTimers() {
	return timers;
}

FiniteStateMachine::FiniteStateMachine(GameObject* owner) :
GameObjectComponent(owner) {
	timers = new CooldownTimer(owner);
}

void FiniteStateMachine::pushState(State* state) {
	states.push(state);
}
State* FiniteStateMachine::popState() {
	if (states.size() != 0) {
		State* state = states.top();
		states.pop();

		return state;
	}

	return 0;
}
bool FiniteStateMachine::hasStates() {
	return states.size() != 0;
}

void FiniteStateMachine::update(sf::Time& tpf) {
	if (hasStates()) {
		states.top()->Update(tpf);
	}
}

void FiniteStateMachine::draw(sf::RenderWindow& window) {
}

FiniteStateMachine::~FiniteStateMachine() {
	while (hasStates()) {
		State* state = popState();

		delete(state);
	}
}
