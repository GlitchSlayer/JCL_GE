#include "stdafx.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "JCL project");
	sf::RectangleShape shape({ 100, 100 });
	shape.setFillColor({ 255, 0, 0 });

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
