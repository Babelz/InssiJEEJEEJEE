#pragma once
#include "GameObjectComponent.h"

class MonsterRendererComponent : public GameObjectComponent
{
private:
	sf::Texture texture;
public:

	float sizeX;
	float sizeY;

	MonsterRendererComponent(GameObject* owner, sf::Texture &texture);

	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);

	~MonsterRendererComponent();
};

