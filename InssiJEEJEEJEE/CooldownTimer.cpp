#include "CooldownTimer.h"


CooldownTimer::CooldownTimer(GameObject* owner) : 
GameObjectComponent(owner) {
}


Timer* CooldownTimer::getTimer(std::string name) {
	for (int i = 0; i < timers.size(); i++) {
		if (timers[i]->name == name) {
			return timers[i];
		}
	}
}

void CooldownTimer::update(sf::Time& tpf) {
	if (!running) {
		return;
	}

	int elapsed = tpf.asMicroseconds();

	for (int i = 0; i < timers.size(); i++) {
		timers[i]->elapsed += elapsed;
	}
}

void CooldownTimer::draw(sf::RenderWindow& window) {
}

void CooldownTimer::addTimer(std::string name) {
	Timer* timer = getTimer(name);

	if (timer == 0) {
		timers.push_back(new Timer());
	}
}
void CooldownTimer::removeTimer(std::string name) {
	Timer* timer = getTimer(name);

	if (timer != 0) {
		timers.erase(std::remove(timers.begin(), timers.end(), timer), timers.end());
	}
}
int CooldownTimer::getTimerValue(std::string name) {
	Timer* timer = getTimer(name);

	if (timer != 0) {
		return timer->elapsed;
	} else {
		return 0;
	}
}

bool CooldownTimer::expired(std::string name) {
	Timer* timer = getTimer(name);

	if (timer != 0) {
		return timer->elapsed > timer->max;
	} else {
		return false;
	}
}
bool CooldownTimer::resetTimer(std::string name) {
	Timer* timer = getTimer(name);

	if (timer != 0) {
		timer->elapsed = 0;
	}

	return timer != NULL;
}

void CooldownTimer::stop() {
	running = false;
}
void CooldownTimer::start() {
	running = true;
}
bool CooldownTimer::isMeasuring() {
	return running;
}

CooldownTimer::~CooldownTimer() {
}
