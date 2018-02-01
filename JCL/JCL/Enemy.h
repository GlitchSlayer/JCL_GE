#pragma once

class Enemy
	: public SceneObject
{
private:
	std::string m_name;
	float m_healthPoints;
	float m_speed;
	float m_strength;
	bool amIseePlayer = false;
	sf::Vector2f displacementToTarget;
	sf::Vector2f initialPosition;
	sf::Vector2f patrolPosition;
	bool isItInitialPosition = true;

public:

	Enemy(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 10, 10 });
	virtual ~Enemy();
	
	virtual void update(const float& deltaTime);
};

