#include "stdafx.h"

Reaper::Reaper(const sf::Vector2f& position, const sf::Vector2f& size)
	: Enemy(position, size)
{
	m_shape.setFillColor({ 255, 255, 255 });
}


Reaper::~Reaper()
{
}
