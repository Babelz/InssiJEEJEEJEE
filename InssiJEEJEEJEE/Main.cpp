#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "AStarGrid.h"
#include "AstarPathfinder.h"

int main()
{
	sf::Vector2f nodeSize;
	nodeSize.x = 32.0f;
	nodeSize.y = 32.0f;

	AStarGrid g(100, 100, nodeSize);

	g.setGoal(sf::Vector2f(64.0f, 64.0f));
	g.setStart(sf::Vector2f());

	AStarPathfinder p(&g);

	p.findPath();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}