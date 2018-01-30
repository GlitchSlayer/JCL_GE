#include "stdafx.h"

bool App::isWPressed(0),
	 App::isAPressed(0),
	 App::isSPressed(0),
	 App::isDPressed(0),
	 App::isLeftMousePressed(0);

const sf::Vector2f App::screenDismentions({ 1366, 768 });

sf::Vector2i App::mousePosition(sf::Mouse::getPosition());

sf::View App::gameView({ screenDismentions.x / 2, screenDismentions.y / 2, screenDismentions.x, screenDismentions.y });

void App::run()
{
	sf::RenderWindow window(sf::VideoMode(screenDismentions.x, screenDismentions.y), "JCL project");

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
		gameView.reset({ obj::player.getPosition().x - (screenDismentions.x / 2), obj::player.getPosition().y - (screenDismentions.y / 2), screenDismentions.x, screenDismentions.y });
		window.setView(gameView);
		window.display();

		deltaTime = (gameClock.getElapsedTime().asSeconds() - frameStart) * 10;
	}
}

void App::updateAll(const float & deltaTime)
{
	obj::player.update(deltaTime);
	obj::reaper.update(deltaTime);
	obj::theRoom.update(deltaTime);

	for (auto i = 0u; i < AllLists::allBullets.size(); i++)
	{
		AllLists::allBullets[i].update(deltaTime);
		if (AllLists::allBullets[i].isDestroyed)
		{
			AllLists::allBullets.erase(i + AllLists::allBullets.begin());
			i--;
		}
	}
}

void App::drawAll(sf::RenderWindow& window)
{
	obj::theRoom.draw(window);

	for (Bullet& bullet : AllLists::allBullets)
		bullet.draw(window);

	obj::player.draw(window);
	obj::reaper.draw(window);
}

void App::eventService(sf::RenderWindow& window, sf::Event& event)
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				window.close();

			if (event.key.code == sf::Keyboard::W)
				isWPressed = true;

			else if (event.key.code == sf::Keyboard::S)
				isSPressed = true;

			if (event.key.code == sf::Keyboard::D)
				isDPressed = true;

			else if (event.key.code == sf::Keyboard::A)
				isAPressed = true;
		}

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::W)
				isWPressed = false;

			else if (event.key.code == sf::Keyboard::S)
				isSPressed = false;

			if (event.key.code == sf::Keyboard::D)
				isDPressed = false;
			else if (event.key.code == sf::Keyboard::A)
				isAPressed = false;
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
				isLeftMousePressed = true;
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.key.code == sf::Mouse::Left)
				isLeftMousePressed = false;
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
