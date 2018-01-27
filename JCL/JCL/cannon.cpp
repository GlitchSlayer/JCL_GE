#include "stdafx.h"


Cannon::Cannon(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color)
	: m_position(position)
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

	float displacementX = mousePosition.x - m_position.x;
	float displacementY = mousePosition.y - m_position.y;

	static const float offset = m_shape.getSize().x/2;

	if (displacementX > offset)
	{
		if (displacementY > offset)
			m_shape.setRotation(45);
		else if (displacementY < -offset)
			m_shape.setRotation(-45);
		else m_shape.setRotation(0);
	}
	else if (displacementX < 0)
	{
		if (displacementY > offset)
			m_shape.setRotation(-225);
		else if (displacementY < -offset)
			m_shape.setRotation(225);
		else m_shape.setRotation(0);
	}
	else if (displacementX <= offset)
	{
		m_shape.setRotation(90);
	}

	m_shape.setPosition(m_position);
}
