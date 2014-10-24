#pragma once

#include <SFML\Graphics.hpp>
#include "World.h"
#include "State.hpp"
#include "Camera.h"

class GameplayScreen : public State
{
private:
	World world;
	Camera* camera;
public:
	GameplayScreen(Game* game);
	~GameplayScreen();
	void update(sf::Time &tpf);
	void draw(sf::RenderWindow& window);
	void activate();
	int pollEvent(sf::Event &event);
};

