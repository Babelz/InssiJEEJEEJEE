#pragma once
#include "GameObjectComponent.h"
#include "PlayerComponents.h"
class SwitchComponent : public GameObjectComponent {
private:
	MoonComponent* moonComponent;
	int currentMoonVal;
	int lastMoonVal;

	bool changed;
public:
	bool moonStateChanged();
	int getMoonStateVal();

	SwitchComponent(GameObject* owner);
	~SwitchComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& win);
	void interactWith(GameObject* gobject);
};

