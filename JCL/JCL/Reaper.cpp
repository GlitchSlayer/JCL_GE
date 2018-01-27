#include "stdafx.h"
#include "Reaper.h"


Reaper::Reaper(std::string _name, sf::Vector2f _pos)
{
	m_shape.setSize({ 50, 50 });
	m_shape.setFillColor(sf::Color::Magenta);
}


Reaper::~Reaper()
{
}
