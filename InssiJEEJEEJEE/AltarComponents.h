#pragma once
#include "GameObjectComponent.h"
class SwitchComponent : public GameObjectComponent {
public:
	SwitchComponent(GameObject* owner);
	~SwitchComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& win);
	void interactWith(GameObject* gobject);

};

