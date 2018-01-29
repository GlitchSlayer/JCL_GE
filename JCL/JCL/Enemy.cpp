#include "stdafx.h"
#include "Enemy.h"




Enemy::Enemy(std::string _name, sf::Vector2f _pos)
{
	m_shape.setPosition(_pos);
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

}