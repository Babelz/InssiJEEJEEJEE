#pragma once

#include "GameObject.h"
#include "SFML\Graphics\Text.hpp"
#include "Box2D\Dynamics\b2Body.h"
#include "TileModel.h"

class Tile : public GameObject
{
private:
	int modelId;
	TileModel* model;
	sf::Sprite sprite;
public:
	int getModelId();
	void setModel(TileModel* const model);

	Tile(int modelId, sf::Vector2f position, b2Body* body);

	virtual void update(sf::Time &tpf);
	virtual void draw(sf::RenderWindow &window);

	~Tile();
};

