#pragma once
#include "GameObjectComponent.h"
class PlayerRendererComponent : public GameObjectComponent
{
private:
	sf::Texture texture;
public:
	PlayerRendererComponent(GameObject* owner, sf::Texture& texture);
	~PlayerRendererComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);
};

