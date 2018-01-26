#include "stdafx.h"

extern const float g_M_PI(3.1415926);
extern bool g_isWPressed(0), g_isAPressed(0), g_isSPressed(0), g_isDPressed(0);

void eventService(sf::RenderWindow& window, sf::Event& event);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "JCL project");

	CannonBase cBase({ 100, 100 }, { 150, 100 });
	Cannon superCannon({}, { 100, 50 });
	Player player(cBase, superCannon);

	sf::Clock gameClock;
	float deltaTime = 1 / 60.f;

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;

		eventService(window, event);

		float frameStart = gameClock.getElapsedTime().asSeconds();

		player.update(deltaTime);

		window.clear();
		player.draw(window);
		window.display();
		
		deltaTime = (gameClock.getElapsedTime().asSeconds() - frameStart) * 10;
	}

	return 0;
}

void eventService(sf::RenderWindow& window, sf::Event& event)
{
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
}