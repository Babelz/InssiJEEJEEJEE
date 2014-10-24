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

	int h;
	int g;
	int mod;

	void calculateH();
	void calculateG();
public:

	// Getterit ja setterit.
	NodeType getNodeType();
	void setNodeType(NodeType nodeType);
	void setGoal(sf::Vector2f goal);
	int getF();
	int getH();
	int getG();

	sf::Vector2f getPosition();

	int getMod();
	void setMod(int mod);
	void setParent(AStarNode* const parent);
	AStarNode* getParent();

	AStarNode(sf::Vector2f position, sf::Vector2f size);
	
	void update();
	void reset();
	
	~AStarNode();
};

