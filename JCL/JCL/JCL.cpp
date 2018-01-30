#include "stdafx.h"

extern const float g_M_PI(3.1415);
extern bool g_isWPressed(0), g_isAPressed(0), g_isSPressed(0), g_isDPressed(0), g_isLeftMousePressed(0);
extern sf::Vector2i mousePosition({0, 0});

void updateAll(const float& deltaTime);
void drawAll(sf::RenderWindow& window);
void eventService(sf::RenderWindow& window, sf::Event& event);

int main()
{
	const sf::Vector2f screenDismentions = { 1366, 768 };
	sf::RenderWindow window(sf::VideoMode(screenDismentions.x, screenDismentions.y), "JCL project");

	AllLists::allBullets.reserve(4);

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
	obj::player.update(deltaTime);
	obj::reaper.update(deltaTime);
	obj::theRoom.update(deltaTime);

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
	obj::theRoom.draw(window);

	for (Bullet& bullet : AllLists::allBullets)
		bullet.draw(window);

	obj::player.draw(window);
	obj::reaper.draw(window);
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
		{
			mousePosition = sf::Mouse::getPosition(window);
			//std::cout << mousePosition.x << " " << mousePosition.y << '\n';
		}

		if (event.type == sf::Event::Closed)
			window.close();
	}
}