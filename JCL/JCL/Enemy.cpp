#include "stdafx.h"

Enemy::Enemy(const sf::Vector2f& position, const sf::Vector2f& size)
	: SceneObject(position, size), m_speed(20)
{
	
}

Enemy::~Enemy()
{
	std::cout << "Enemy destroyed\n";
}

void Enemy::update(const float& deltaTime) {

	sf::Vector2f playerPosition = obj::player.getPosition();

	float dirX = playerPosition.x - m_position.x;
	float dirY = playerPosition.y - m_position.y;

	float length = std::sqrt(dirX * dirX + dirY * dirY);

	if(length != 0) {
		dirX /= length;
		dirY /= length;
	}
	else {
		dirX = 0;
		dirY = 0;
	}

	m_position.x += dirX * m_speed * deltaTime;
	m_position.y += dirY * m_speed * deltaTime;

	m_shape.setPosition(m_position);
}