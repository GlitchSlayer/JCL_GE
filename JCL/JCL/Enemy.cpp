#include "stdafx.h"

Enemy::Enemy(const sf::Vector2f& position, const sf::Vector2f& size)
	: SceneObject(position, size), m_speed(20), m_healthPoints(100)
{
	
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
				bullet.isDead = true;
				m_healthPoints -= 10;
			}		
		}
	}

	if (m_healthPoints <= 0)
		isDead = true;
	
	sf::Vector2f displacementToPlayer(obj::player.getPosition() - m_position);

	float lengthToPlayer = std::sqrt(displacementToPlayer.x * displacementToPlayer.x + displacementToPlayer.y * displacementToPlayer.y);

	if(lengthToPlayer != 0) 
		displacementToPlayer /= lengthToPlayer;
	else
		displacementToPlayer = { 0, 0 };

	m_position += displacementToPlayer * m_speed * deltaTime;

	float angle = std::atan2(displacementToPlayer.y, displacementToPlayer.x) * 180 / phys::PI;

	m_shape.setRotation(angle+90);

	m_shape.setPosition(m_position);
}