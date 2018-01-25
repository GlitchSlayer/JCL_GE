#include "stdafx.h"

Player::Player(const sf::Vector2f& position)
	: m_position(position)
{
	m_shape.setPosition(m_position);
	m_shape.setSize({ 100, 100 });
	m_shape.setFillColor({ 255, 0,0 });
}

void Player::draw(sf::RenderWindow& window) const
{
	window.draw(m_shape);
}

void Player::update(const float& deltaTime)
{
	extern bool g_isWPressed, g_isAPressed, g_isSPressed, g_isDPressed;

	if (g_isWPressed)
		m_velocityGoal.y = -100;
	else if(g_isSPressed)
		m_velocityGoal.y = 100;
	else m_velocityGoal.y = 0;

	if(g_isAPressed)
		m_velocityGoal.x = -100;
	else if (g_isDPressed)
		m_velocityGoal.x = 100;
	else m_velocityGoal.x = 0;

	m_velocity.x = phys::Approach(m_velocityGoal.x, m_velocity.x, deltaTime * 70);
	m_velocity.y = phys::Approach(m_velocityGoal.y, m_velocity.y, deltaTime * 70);

	m_position += m_velocity * deltaTime;

	m_shape.setPosition(m_position);
}