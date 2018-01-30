#include "stdafx.h"

Room::Room(const sf::Vector2f& position, const sf::Vector2f& size)
{
	m_shape.setPosition(position);
	m_shape.setSize(size);
	m_shape.setFillColor({ 0, 0, 255 });
}

Room::~Room()
{
	std::cout << "Room destroyed\n";
}

void Room::update(const float& deltaTime)
{
}

void Room::draw(sf::RenderWindow& window) const
{
	window.draw(m_shape);
}
