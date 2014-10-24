#pragma once
#include "GameObjectComponent.h"
#include <stack>
#include "CooldownTimer.h"

	class FiniteStateMachine;

	class MachineState
	{
	private:
		GameObject* owner;
		FiniteStateMachine* stateMachine;
	protected:
		GameObject* const getOwner() {
			return owner;
		}
		FiniteStateMachine* const getStateMachine() {
			return stateMachine;
		}
	public:
		MachineState(GameObject* owner, FiniteStateMachine* stateMachine) {
			this->owner = owner;
			this->stateMachine = stateMachine;
		}

		virtual void update(sf::Time& tpf) = 0;
	};

	class FiniteStateMachine : public GameObjectComponent
	{
	private:
		std::stack<MachineState*> states;
		CooldownTimer* timers;
	public:
		CooldownTimer* const getTimers();

		FiniteStateMachine(GameObject* owner);

		void pushState(MachineState* state);
		MachineState* popState();
		bool hasStates();

		virtual void update(sf::Time& tpf);
		virtual void draw(sf::RenderWindow& window);

		~FiniteStateMachine();
	};

