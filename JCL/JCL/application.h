#pragma once

class App
{
private:
	static sf::View gameView;
	static const sf::Vector2f screenDismentions;
public:
	static bool isWPressed, 
				isAPressed, 
				isSPressed, 
				isDPressed, 
				isLeftMousePressed;

	static sf::Vector2i mousePosition;
	static void run();
	static void updateAll(const float& deltaTime);
	static void drawAll(sf::RenderWindow& window);
	static void eventService(sf::RenderWindow& window, sf::Event& event);
};