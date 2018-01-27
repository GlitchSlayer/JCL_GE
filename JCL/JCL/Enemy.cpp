#include "stdafx.h"
#include "Enemy.h"




Enemy::Enemy(std::string _name, sf::Vector2f _pos)
	:m_name(_name), m_position(_pos), m_speed(20)
{
	m_shape.setPosition(m_position);
}


Enemy::~Enemy()
{
}

void Enemy::taunt() {
	std::cout << "Die, die, die!";
}

void Enemy::draw(sf::RenderWindow& window) {
	window.draw(m_shape);
}
void Enemy::update(const float& deltaTime) {
	Cannon superCannon({800, 100}, { 100, 50 });
	sf::Vector2f cannon_position = superCannon.getPosition();
	float dirX = cannon_position.x - m_position.x;
	float dirY = cannon_position.y - m_position.y;

	float length = std::sqrt(dirX*dirX + dirY * dirY);

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
	//std::cout << cannon_position.x << " ";
}