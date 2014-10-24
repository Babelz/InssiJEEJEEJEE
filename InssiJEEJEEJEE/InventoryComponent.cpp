#include "InventoryComponent.h"

InventoryComponent::InventoryComponent(GameObject *owner) : GameObjectComponent(owner)
{
}

InventoryComponent::~InventoryComponent()
{
}

void InventoryComponent::addItem(Item *item)
{
	items.push_back(item);
}

void InventoryComponent::update(sf::Time& tpf)
{
}

void InventoryComponent::draw(sf::RenderWindow& window)
{
}