#pragma once

#include <vector>
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
class GameObjectComponent;
#include "GameObjectComponent.h"

class GameObject
{
private:
	std::vector<GameObjectComponent*> components;


public:
	b2Body *body;
	GameObject();
	~GameObject();

	void addComponent(GameObjectComponent* component);
	

	virtual void update(sf::Time &tpf);
	virtual void draw(sf::RenderWindow &window);

	// get's set's
	inline void setPosition(float x, float y) {
		body->SetTransform(b2Vec2(x, y), 0.0f);
	}

	inline const b2Vec2& getPosition() {
		return body->GetTransform().p;
	}

	
	
};

