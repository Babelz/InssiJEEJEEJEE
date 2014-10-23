#include "GameObjectComponent.h"


GameObjectComponent::GameObjectComponent(GameObject* owner)
{
	this->owner = owner;
}


GameObjectComponent::~GameObjectComponent()
{
}
