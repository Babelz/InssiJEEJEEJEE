#pragma once
#include "GameObjectComponent.h"

class SoulComponent : public GameObjectComponent
{
private:
	int souls;
public:
	SoulComponent(GameObject* owner);
	~SoulComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& win);
	void setSouls(int souls) {
		this->souls = souls;
	}
	int getSouls() const {
		return souls;
	}
};

class MoonComponent : public GameObjectComponent
{
private:
	int moonState;
public:
	MoonComponent(GameObject* owner);
	~MoonComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& win);
	void setMoonState(int ms) {
		this->moonState = ms;
	}
	int getMoonState() const {
		return moonState;
	}
};

class InteractionComponent : public GameObjectComponent
{
public:
	InteractionComponent(GameObject* owner);
	~InteractionComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& win);
};
