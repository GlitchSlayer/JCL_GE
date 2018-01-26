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
	m_shape.setPosition(m_position);
}
