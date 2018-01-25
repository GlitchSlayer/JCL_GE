#pragma once

class Player
{
private:
	int m_healthPoints;
	sf::RectangleShape m_shape;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_velocityGoal;

public:
	Player(const sf::Vector2f& position = {0, 0});
	~Player() {}

	void draw(sf::RenderWindow& window) const;
	void update(const float& deltaTime);
};