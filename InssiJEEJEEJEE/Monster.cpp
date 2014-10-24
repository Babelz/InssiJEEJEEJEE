#include "Monster.h"

Monster::Monster() : 
GameObject() {
	this->addComponent(new FiniteStateMachine(this));
	this->addComponent(new CooldownTimer(this));
}

void Monster::update(sf::Time &tpf) {
}
void Monster::draw(sf::RenderWindow &window) {
}

Monster::~Monster() {
}
