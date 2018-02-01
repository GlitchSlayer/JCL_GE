#include "stdafx.h"

Reaper::Reaper(const sf::Vector2f& position, const sf::Vector2f& size)
	: Enemy(position, size)
{
	if (m_texture.loadFromFile("Resources/Textures/EnemyCannon.png"))
		m_shape.setTexture(&m_texture);
}


Reaper::~Reaper()
{
}
