#include "stdafx.h"

Player::Player(const CannonBase& cannonBase, const Cannon& cannon)
	: m_cannonBase(cannonBase), m_cannon(cannon)
{
	
}

void Player::draw(sf::RenderWindow& window)
{
	m_cannonBase.draw(window);
	m_cannon.draw(window);
}

void Player::update(const float& deltaTime)
{
	m_cannonBase.update(deltaTime);
	m_cannon.setPosition(m_cannonBase.getPosition());
	m_cannon.update(deltaTime);
}