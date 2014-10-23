#pragma once

#include <vector>
#include <GameObjectComponent.h>
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

class GameObject
{
private:
	std::vector<GameObjectComponent> components;
	b2BodyDef body;

public:
	GameObject();
	~GameObject();

	void addComponent(GameObjectComponent &component);
	

	virtual void update(sf::Time &tpf);
	virtual void draw(sf::RenderWindow &window);

	// get's set's
	inline void setPosition(float x, float y) {
		body.position = b2Vec2(x, y);
	}

	inline b2Vec2& getPosition() {
		return body.position;
	}

	
	
};

