#pragma once

class Bullet
	: public SceneObject
{
private:
	float m_lifePoints;
	float m_speed;
	sf::Vector2f m_direction;
public:

	Bullet(const sf::Vector2f& position, const float& direction);
	virtual ~Bullet();

	float getLifePoints();

	virtual void update(const float& deltaTime);
};