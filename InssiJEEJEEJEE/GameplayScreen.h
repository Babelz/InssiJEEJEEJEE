#pragma once

#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "BoxRendererComponent.h"
#include "InputMovementComponent.h"
#include "HealthComponent.h"
#include "InssiMath.h"
#include "FiniteStateMachine.h"
#include "FollowState.h"
#include "Camera.h"
#include "GameState.hpp"

class GameplayScreen : public GameState
{
private:
	World world;
	Camera* camera;
public:
	GameplayScreen();
	~GameplayScreen();
	void update(sf::Time &tpf);
	void draw(sf::RenderWindow& window);
	void activate();
	int pollEvent(sf::Event &event);
};

