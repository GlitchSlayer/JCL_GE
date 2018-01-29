#include "stdafx.h"

extern const float g_M_PI(3.1415);
extern bool g_isWPressed(0), g_isAPressed(0), g_isSPressed(0), g_isDPressed(0), g_isLeftMousePressed(0);
extern sf::Vector2i mousePosition({0, 0});

CannonBase cBase({ 100, 100 }, { 64, 64 });
Cannon superCannon({}, { 64, 32 });
Player player(cBase, superCannon);
Reaper reaper("R1");

void updateAll(const float& deltaTime);
void drawAll(sf::RenderWindow& window);
void eventService(sf::RenderWindow& window, sf::Event& event);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 800), "JCL project");
	
	sf::Clock gameClock;
	float deltaTime = 1 / 60.f;

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;

		eventService(window, event);

		float frameStart = gameClock.getElapsedTime().asSeconds();

		updateAll(deltaTime);

		window.clear();
		drawAll(window);
		window.display();
		
		deltaTime = (gameClock.getElapsedTime().asSeconds() - frameStart) * 10;
	}

	return 0;
}

void updateAll(const float& deltaTime)
{
	player.update(deltaTime);
	reaper.update(deltaTime);

	for (auto i = 0u; i < AllLists::allBullets.size(); i++)
	{
		AllLists::allBullets[i].update(deltaTime);
		if (AllLists::allBullets[i].isDestroyed)
		{
			AllLists::allBullets.erase(AllLists::allBullets.begin() + i);
			i--;
		}
	}
}

void drawAll(sf::RenderWindow& window)
{
	for (Bullet& bullet : AllLists::allBullets)
		bullet.draw(window);

	player.draw(window);
	reaper.draw(window);
}

void eventService(sf::RenderWindow& window, sf::Event& event)
{
	while (window.pollEvent(event))
	{
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

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
				g_isLeftMousePressed = true;
		}
		
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.key.code == sf::Mouse::Left)
				g_isLeftMousePressed = false;
		}
		

		if (event.type == sf::Event::MouseMoved)
			mousePosition = sf::Mouse::getPosition(window);

		if (event.type == sf::Event::Closed)
			window.close();
	}
}