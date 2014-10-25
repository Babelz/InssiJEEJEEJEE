#pragma once
#include "GameObjectComponent.h"

class DropComponent : public GameObjectComponent
{
private:
	sf::Texture &itemTexture;
public:
	DropComponent(GameObject *owner, sf::Texture &texture);
	~DropComponent();

	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);

	void dropItem(float x, float y, World *world);
};