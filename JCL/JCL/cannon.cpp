#include "stdafx.h"

Cannon::Cannon(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color)
	: m_position(position), m_shootDelay(50), m_shootDelayCounter(0)
{
	m_shape.setSize(size);
	m_shape.setOrigin({ m_shape.getSize().x / 2, m_shape.getSize().y / 2 });
	m_shape.setPosition(position);
	m_shape.setFillColor(color);
}

sf::Vector2f Cannon::getPosition() const
{
	return m_position;
}

void Cannon::setPosition(const sf::Vector2f& position)
{
	m_position = position;
}

void Cannon::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void Cannon::update(const float& deltaTime)
{
	extern sf::Vector2i mousePosition;
	extern bool g_isLeftMousePressed;
	extern const float g_M_PI;

	float distanceX = mousePosition.x - m_position.x;
	float distanceY = mousePosition.y - m_position.y;

	float angle = std::atan2f(distanceY, distanceX) * 180 / g_M_PI;

	m_shape.setRotation(angle);

	if (g_isLeftMousePressed && m_shootDelayCounter >= m_shootDelay)
	{
		Bullet bullet( { m_position.x, m_position.y }, m_shape.getRotation() );
		AllLists::allBullets.push_back(bullet);
		m_shootDelayCounter = 0;
	}
	else if (m_shootDelayCounter >= m_shootDelay)
		m_shootDelayCounter = m_shootDelay;
	else m_shootDelayCounter += deltaTime*10;

	m_shape.setPosition(m_position);
}
