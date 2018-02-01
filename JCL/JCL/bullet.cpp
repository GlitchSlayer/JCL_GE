#include "stdafx.h"

Bullet::Bullet(const sf::Vector2f& position, const float& direction)
	:SceneObject(position, {20, 20}), m_speed(100), m_lifePoints(20)
{
	m_direction = { std::cos(direction * phys::PI / 180), std::sin(direction * phys::PI / 180) };
	m_shape.setFillColor(sf::Color::Yellow);
}

Bullet::~Bullet()
{
	std::cout << "Bullet destroyed\n";
}

float Bullet::getLifePoints()
{
	return m_lifePoints;
}

void Bullet::update(const float& deltaTime)
{
	m_position += m_direction * m_speed * deltaTime;

	m_lifePoints -= deltaTime;

	if (m_lifePoints <= 0)
		isDead = true;

	m_shape.setPosition(m_position);
}
