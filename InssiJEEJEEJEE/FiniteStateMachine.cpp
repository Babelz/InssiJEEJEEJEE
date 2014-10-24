#include "FiniteStateMachine.h"

CooldownTimer* const FiniteStateMachine::getTimers() {
	return timers;
}

FiniteStateMachine::FiniteStateMachine(GameObject* owner) :
GameObjectComponent(owner) {
	timers = new CooldownTimer(owner);
	timers->start();
}

void FiniteStateMachine::pushState(MachineState* state) {
	states.push(state);
}
MachineState* FiniteStateMachine::popState() {
	if (states.size() != 0) {
		MachineState* state = states.top();
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
		states.top()->update(tpf);
	}

	timers->update(tpf);
}

void FiniteStateMachine::draw(sf::RenderWindow& window) {
}

FiniteStateMachine::~FiniteStateMachine() {
	while (hasStates()) {
		MachineState* state = popState();

		delete(state);
	}
}
