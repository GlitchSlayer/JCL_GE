#include "stdafx.h"

CannonBase::CannonBase(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color)
	: m_position(position)
{
	m_shape.setSize(size);
	m_shape.setOrigin({ m_shape.getSize().x / 2, m_shape.getSize().y / 2 });
	m_shape.setPosition(position);
	m_shape.setFillColor(color);
}

void CannonBase::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void CannonBase::update(const float& deltaTime)
{
	extern bool g_isWPressed, g_isAPressed, g_isSPressed, g_isDPressed;
	extern const float g_M_PI;

	if (g_isDPressed)
		m_velocityGoal.x = 100;
	else if (g_isAPressed)
		m_velocityGoal.x = -100;
	else m_velocityGoal.x = 0;

	if (g_isWPressed)
		m_velocityGoal.y = -100;
	else if (g_isSPressed)
		m_velocityGoal.y = 100;
	else m_velocityGoal.y = 0;

	if (m_velocity.x != 0 && m_velocity.y != 0)
	{
		float angle = std::atan2f(m_velocity.y, m_velocity.x) * 180 / g_M_PI;
		m_shape.setRotation(angle);
	}
	
	m_velocity.x = phys::Approach(m_velocityGoal.x, m_velocity.x, deltaTime * 50);
	m_velocity.y = phys::Approach(m_velocityGoal.y, m_velocity.y, deltaTime * 50);

	m_position += m_velocity * deltaTime;

	m_shape.setPosition(m_position);
	
}

sf::Vector2f CannonBase::getPosition() const
{
	return m_position;
}

void CannonBase::setPosition(const sf::Vector2f& position)
{
	m_position = position;
}
