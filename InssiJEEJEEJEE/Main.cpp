#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "TestiState.hpp"
#include "StateManager.hpp"

int main()
{
	StateManager tilamanageri;
	int testiState = tilamanageri.add(TestiState());
	tilamanageri.change(testiState);
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (tilamanageri.pollEvent(event) == 0)
				window.close();
		}

		window.clear();
		tilamanageri.draw(window);
		window.display();
	}

	return 0;
}