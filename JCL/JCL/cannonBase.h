#pragma once

class CannonBase
{
private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_velocityGoal;
	sf::RectangleShape m_shape;
public:
	CannonBase(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 100, 50 }, const sf::Color& color = { 255, 0, 0 });

	void draw(sf::RenderWindow& window);
	void update(const float& deltaTime);

	sf::Vector2f getPosition() const;
	void setPosition(const sf::Vector2f& position);
};