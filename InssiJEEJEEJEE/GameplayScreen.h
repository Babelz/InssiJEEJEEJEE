#pragma once

#include <SFML\Graphics.hpp>
#include "World.h"
#include "State.hpp"
#include "Camera.h"
#include "MonsterGenerator.h"
class GameplayScreen : public State
{
private:
	World world;
	Camera* camera;
	MonsterGenerator *monsterGenerator;
public:
	GameplayScreen(Game* game);
	~GameplayScreen();
	void update(sf::Time &tpf);
	void draw(sf::RenderWindow& window);
	void activate();
	int pollEvent(sf::Event &event);
};

