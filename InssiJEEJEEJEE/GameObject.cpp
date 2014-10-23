#include "GameObject.h"
#include <algorithm>

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}


void GameObject::update(sf::Time& tpf) {
	std::for_each(components.begin(), components.end(), [&tpf](GameObjectComponent& c) {
		c.update(tpf);
	});
}


void GameObject::draw(sf::RenderWindow& window) {
	std::for_each(components.begin(), components.end(), [&window](GameObjectComponent& c) {
		c.draw(window);
	});
}
