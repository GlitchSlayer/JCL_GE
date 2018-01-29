#include "stdafx.h"

Bullet::Bullet(const sf::Vector2f& position, const float& direction)
	:m_position(position), m_speed(100), m_lifePoints(20), isDestroyed(false)
{
	extern const float g_M_PI;

	m_direction = { std::cos(direction * g_M_PI / 180), std::sin(direction * g_M_PI / 180) };
	m_shape.setPosition(m_position);
	m_shape.setRadius(10);
	m_shape.setFillColor(sf::Color::Yellow);
}

float Bullet::getLifePoints()
{
	return m_lifePoints;
}

void Bullet::draw(sf::RenderWindow& window) const
{
	window.draw(m_shape);
}

void Bullet::update(const float& deltaTime)
{
	m_position += m_direction * m_speed * deltaTime;

	m_lifePoints -= deltaTime;

	if (m_lifePoints <= 0)
		isDestroyed = true;

	m_shape.setPosition(m_position);
}
