#pragma once
#include <vector>
#include "Item.h"
#include "GameObjectComponent.h"

class InventoryComponent : public GameObjectComponent
{
private:
	std::vector<Item*> items;

public:
	InventoryComponent(GameObject *owner);
	~InventoryComponent();

	void addItem(Item *item);

	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);
};