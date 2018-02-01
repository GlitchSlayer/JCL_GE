#include "stdafx.h"

CannonBase::CannonBase(const sf::Vector2f& position, const sf::Vector2f& size)
	: SceneObject(position, size)
{
	if (m_texture.loadFromFile("Resources/Textures/CannonBase.png", { 0, 0, 64, 64}))
		m_shape.setTexture(&m_texture);
}

CannonBase::~CannonBase()
{
	std::cout << "CannonBase destroyed\n";
}

void CannonBase::update(const float& deltaTime)
{
	if (App::isDPressed)
		m_velocityGoal.x = 100;
	else if (App::isAPressed)
		m_velocityGoal.x = -100;
	else m_velocityGoal.x = 0;

	if (App::isWPressed)
		m_velocityGoal.y = -100;
	else if (App::isSPressed)
		m_velocityGoal.y = 100;
	else m_velocityGoal.y = 0;

	if (m_velocity.x != 0 && m_velocity.y != 0)
	{
		float angle = std::atan2f(m_velocity.y, m_velocity.x) * 180 / phys::PI;
		m_shape.setRotation(angle+90);
	}
	
	m_velocity.x = phys::Approach(m_velocityGoal.x, m_velocity.x, deltaTime * 50);
	m_velocity.y = phys::Approach(m_velocityGoal.y, m_velocity.y, deltaTime * 50);

	m_position += m_velocity * deltaTime;

	m_shape.setPosition(m_position);
	
}