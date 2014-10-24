#pragma once
#include "GameObjectComponent.h"
#include <stack>
#include "CooldownTimer.h"

namespace AI 
{
	class FiniteStateMachine;

	class State
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
		State(GameObject* owner, FiniteStateMachine* stateMachine) {
			this->owner = owner;
			this->stateMachine = stateMachine;
		}

		virtual void Update(sf::Time& tpf) = 0;
	};

	class FiniteStateMachine : public GameObjectComponent
	{
	private:
		std::stack<State*> states;
		CooldownTimer* timers;
	public:
		CooldownTimer* const getTimers();

		FiniteStateMachine(GameObject* owner);

		void pushState(State* state);
		State* popState();
		bool hasStates();

		virtual void update(sf::Time& tpf);
		virtual void draw(sf::RenderWindow& window);

		~FiniteStateMachine();
	};
}

