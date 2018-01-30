#include "stdafx.h"

SceneObject::SceneObject(const sf::Vector2f& position, const sf::Vector2f& size)
	: m_position(position)
{
	m_shape.setPosition(position);
	m_shape.setSize(size);
	m_shape.setOrigin(size/2.f);
}


sf::Vector2f SceneObject::getPosition() const
{
	return m_position;
}

void SceneObject::setPosition(const sf::Vector2f& position)
{
	m_position = position;
}

void SceneObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_shape);
}
