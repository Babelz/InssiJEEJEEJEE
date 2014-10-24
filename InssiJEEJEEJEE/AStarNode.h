#pragma once

#include <SFML\System\Vector2.hpp>

enum NodeType
{
	UNWALKABLE = 0,
	WALKABLE = 1
};

class AStarNode {
private:
	AStarNode* parent;
	NodeType nodeType;

	sf::Vector2f position;
	sf::Vector2f size;
	sf::Vector2f goal;

	float h;
	float g;
	float mod;

	void calculateH();
	void calculateG();
public:

	// Getterit ja setterit.
	NodeType getNodeType();
	void setNodeType(NodeType nodeType);
	float getF();
	float getH();
	float getG();

	sf::Vector2f getPosition();

	float getMod();
	void setMod(float mod);
	void setParent(AStarNode* const parent);
	AStarNode* getParent();

	AStarNode(sf::Vector2f position, sf::Vector2f size);
	
	void update();
	void reset();
	
	~AStarNode();
};

