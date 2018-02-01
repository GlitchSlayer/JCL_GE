#include "stdafx.h"

Enemy::Enemy(const sf::Vector2f& position, const sf::Vector2f& size)
	: SceneObject(position, size), m_speed(20), m_healthPoints(10)
{
	initialPosition = m_position;
	patrolPosition = { m_position.x, (m_position.y + 1) };
}

Enemy::~Enemy()
{
	std::cout << "Enemy destroyed\n";
}

void Enemy::update(const float& deltaTime) {

	static const sf::Vector2f&& halfOfSize = m_shape.getSize() / 2.f;

	if (AllLists::allBullets.size() > 0)
	{
		for (Bullet& bullet : AllLists::allBullets)
		{
			const sf::Vector2f&& distanceToBullet = { 
				std::abs(bullet.getPosition().x - m_position.x), 
				std::abs(bullet.getPosition().y - m_position.y) 
			};

			if (distanceToBullet.x < halfOfSize.x && distanceToBullet.y < halfOfSize.y)
			{
				amIseePlayer = true;
				bullet.isDead = true;
				m_healthPoints -= 10;
			}		
		}
	}

	if (m_healthPoints <= 0)
		isDead = true;


	sf::Vector2f displacementToPlayer(obj::player.getPosition() - m_position);
	float lengthToPlayer = std::sqrt(displacementToPlayer.x * displacementToPlayer.x + displacementToPlayer.y * displacementToPlayer.y);

	if (lengthToPlayer < 300)
		amIseePlayer = true;
		
	if (amIseePlayer == true) {
		displacementToTarget = displacementToPlayer;
	}
	else {
		if (isItInitialPosition == true)
			displacementToTarget = patrolPosition;
		else
			displacementToTarget = initialPosition;
	}
	
	float lengthToTarget = std::sqrt(displacementToTarget.x * displacementToTarget.x + displacementToTarget.y * displacementToTarget.y);
	
	if (lengthToTarget != 0)
		displacementToTarget /= lengthToTarget;
	else {
		displacementToTarget = { 0, 0 };
		if (isItInitialPosition == true)
			isItInitialPosition = false;
		else
			isItInitialPosition = true;
	}

	m_position += displacementToTarget * m_speed * deltaTime;

	float angle = std::atan2(displacementToTarget.y, displacementToTarget.x) * 180 / phys::PI;

	m_shape.setRotation(angle+90);

	m_shape.setPosition(m_position);
}