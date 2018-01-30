#include "stdafx.h"

Cannon::Cannon(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color)
	: SceneObject(position, size), m_shootDelay(100), m_shootDelayCounter(100)
{
	m_shape.setFillColor(color);
}

Cannon::~Cannon()
{
	std::cout << "Cannon destroyed\n";
}

void Cannon::update(const float& deltaTime)
{
	static const sf::Vector2f initialPosition(m_position);
	const sf::Vector2f displacement = initialPosition - m_position;
	const sf::Vector2f distance = sf::Vector2f(App::mousePosition) - m_position - displacement;

	const float angle = std::atan2f(distance.y, distance.x) * 180 / phys::PI;

	m_shape.setRotation(angle);

	if (App::isLeftMousePressed && m_shootDelayCounter >= m_shootDelay)
	{
		Bullet bullet({ m_position.x, m_position.y }, m_shape.getRotation());
		AllLists::allBullets.push_back(bullet);
		m_shootDelayCounter = 0;
	}
	else if (m_shootDelayCounter >= m_shootDelay)
		m_shootDelayCounter = m_shootDelay;
	else m_shootDelayCounter += deltaTime*10;

	m_shape.setPosition(m_position);
}
