#pragma once
#include <map>
#include "GameObjectComponent.h"

typedef struct {
	std::string name;

	int max;
	int elapsed;
} Timer;

class CooldownTimer : public GameObjectComponent
{
private:
	std::vector<Timer*> timers;
	bool running;

	Timer* getTimer(std::string name);
public:
	CooldownTimer(GameObject* owner);

	void addTimer(std::string name);
	void removeTimer(std::string name);

	int getTimerValue(std::string name);

	bool expired(std::string name);
	bool resetTimer(std::string name);
	
	void stop();
	void start();
	bool isMeasuring();

	virtual void update(sf::Time& tpf);
	virtual void draw(sf::RenderWindow& window);
	
	~CooldownTimer();
};

