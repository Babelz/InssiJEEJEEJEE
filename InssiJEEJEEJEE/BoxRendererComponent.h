#pragma once
#include "GameObjectComponent.h"

class BoxRendererComponent : public GameObjectComponent
{
private:
	sf::Texture texture;
public:
	BoxRendererComponent(GameObject* owner, sf::Texture &texture);
	~BoxRendererComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);
};

