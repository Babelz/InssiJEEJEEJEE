#pragma once

#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "MonsterRendererComponent.h"
#include "InputMovementComponent.h"
#include "HealthComponent.h"
#include "InssiMath.h"
#include "FiniteStateMachine.h"
#include "FollowState.h"
#include "Camera.h"
#include "GameState.hpp"
#include "MonsterGenerator.h"
#include "soundManager.h"
#include "GameState.hpp"

class GameplayScreen : public GameState
{
private:
	World world;
	Camera* camera;
	MonsterGenerator *monsterGenerator;
	soundManager sound_manager;

public:
	GameplayScreen(Game* game);
	~GameplayScreen();
	void update(sf::Time &tpf);
	void draw(sf::RenderWindow& window);
	void activate();
	int pollEvent(sf::Event &event);
};

