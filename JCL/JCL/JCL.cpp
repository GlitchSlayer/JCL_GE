#include "stdafx.h"

extern bool g_isWPressed(0), g_isAPressed(0), g_isSPressed(0), g_isDPressed(0);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "JCL project");

	Player player;

	sf::Clock gameClock;
	float deltaTime = 1 / 60.f;

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;

		float frameStart = gameClock.getElapsedTime().asSeconds();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W)
					g_isWPressed = false;

				else if (event.key.code == sf::Keyboard::S)
					g_isSPressed = false;

				if (event.key.code == sf::Keyboard::D)
					g_isDPressed = false;

				else if (event.key.code == sf::Keyboard::A)
					g_isAPressed = false;
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();

				if (event.key.code == sf::Keyboard::W)
					g_isWPressed = true;

				else if (event.key.code == sf::Keyboard::S)
					g_isSPressed = true;

				if (event.key.code == sf::Keyboard::D)
					g_isDPressed = true;

				else if (event.key.code == sf::Keyboard::A)
					g_isAPressed = true;
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.update(deltaTime);

		window.clear();
		player.draw(window);
		window.display();
		
		deltaTime = (gameClock.getElapsedTime().asSeconds() - frameStart) * 10;
	}

	return 0;
}
