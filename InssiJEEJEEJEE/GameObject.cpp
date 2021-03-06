#include "GameObject.h"
#include <algorithm>

GameObject::GameObject() : removeOnNextUpdate(false) {
}

void GameObject::addComponent(GameObjectComponent* component) {
	components.push_back(component);
}

void GameObject::update(sf::Time& tpf) {
	std::for_each(components.begin(), components.end(), [&tpf](GameObjectComponent* c) {
		c->update(tpf);
	});
}
void GameObject::draw(sf::RenderWindow& window) {
	std::for_each(components.begin(), components.end(), [&window](GameObjectComponent* c) {
		c->draw(window);
	});
}

void GameObject::destroy() {
	if (body != NULL) {
		body->GetWorld()->DestroyBody(body);
	}
}

GameObject::~GameObject() {
	components.clear();
}
