#pragma once
#include "SFML\System\Vector2.hpp"

enum HorizontalDirection 
{
	LEFT = -1,
	HORSTILL = 0,
	RIGHT = 1
};

enum VerticalDirection
{
	UP = -1,
	VERSTILL = 0,
	DOWN = 1
};

class DirectionHandler
{
private:
	VerticalDirection vertical;
	HorizontalDirection horizontal;
	
	sf::Vector2f goal;
	sf::Vector2f position;
	sf::Vector2f offset;

	bool checkVertical();
	bool checkHorizontal();
public:
	void setOffset(sf::Vector2f offset);

	DirectionHandler();

	bool passedGoal(sf::Vector2f currentPosition);
	void changeDirection(sf::Vector2f position, sf::Vector2f goal);
	sf::Vector2f translate();

	~DirectionHandler();
};

