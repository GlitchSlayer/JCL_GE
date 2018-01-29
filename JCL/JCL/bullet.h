#pragma once

class Bullet
{
private:
	float m_lifePoints;
	float m_speed;
	sf::CircleShape m_shape;
	sf::Vector2f m_position;
	sf::Vector2f m_direction;

public:
	bool isDestroyed;

	Bullet(const sf::Vector2f& position, const float& direction);
	~Bullet() {}

	float getLifePoints();

	void draw(sf::RenderWindow& window) const;
	void update(const float& deltaTime);
};