#pragma once
/*#include "bullet.h"
#include <vector>*/

class Cannon
{
private:
	const float m_shootDelay;
	float m_shootDelayCounter;
	sf::Vector2f m_position;
	sf::RectangleShape m_shape;
public:
	Cannon(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 100, 50 }, const sf::Color& color = { 0, 255, 0 });
	~Cannon() {}

	sf::Vector2f getPosition() const;
	void setPosition(const sf::Vector2f& position);

	void draw(sf::RenderWindow& window);
	void update(const float& deltaTime);
};