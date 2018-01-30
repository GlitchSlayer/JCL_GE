#pragma once

class Bullet
	: public SceneObject
{
private:
	float m_lifePoints;
	float m_speed;
	sf::Vector2f m_direction;
public:
	bool isDestroyed;

	Bullet(const sf::Vector2f& position, const float& direction);
	virtual ~Bullet();

	float getLifePoints();

	virtual void update(const float& deltaTime);
};