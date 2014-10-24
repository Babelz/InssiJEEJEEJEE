#pragma once

#include <vector>
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
class GameObjectComponent;
#include "GameObjectComponent.h"
#include <iostream>
class GameObject
{
private:
	std::vector<GameObjectComponent*> components;


public:
	b2Body *body;
	GameObject();
	~GameObject();

	void addComponent(GameObjectComponent* component);
	
	template<class T> 
	GameObjectComponent* getComponent() {

		for (int i = 0; i < components.size(); i++) {
			GameObjectComponent* c = components[i];
			//std::cout << typeid(T).name() << " -- " << typeid(*c).name() << std::endl;
			if (typeid(T) == typeid(*c))
				return c;
		}
		return NULL;
	}

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

