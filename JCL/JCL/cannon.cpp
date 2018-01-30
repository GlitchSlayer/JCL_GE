#include "stdafx.h"

Cannon::Cannon(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color)
	: SceneObject(position, size), m_shootDelay(50), m_shootDelayCounter(0)
{
	m_shape.setFillColor(color);
}

Cannon::~Cannon()
{
	std::cout << "Cannon destroyed\n";
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
		Bullet bullet({ m_position.x, m_position.y }, m_shape.getRotation());
		AllLists::allBullets.emplace_back(bullet);
		m_shootDelayCounter = 0;
	}
	else if (m_shootDelayCounter >= m_shootDelay)
		m_shootDelayCounter = m_shootDelay;
	else m_shootDelayCounter += deltaTime*10;

	m_shape.setPosition(m_position);
}
