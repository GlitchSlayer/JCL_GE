#include "stdafx.h"

Player::Player(const CannonBase& cannonBase, const Cannon& cannon)
	: SceneObject(cannonBase.getPosition()), m_cannonBase(cannonBase), m_cannon(cannon)
{
	
}

Player::~Player()
{
	std::cout << "Player destroyed\n";
}

void Player::draw(sf::RenderWindow& window)
{
	m_cannonBase.draw(window);
	m_cannon.draw(window);
}

void Player::update(const float& deltaTime)
{
	m_cannonBase.update(deltaTime);
	const sf::Vector2f&& cannonBasePosition = m_cannonBase.getPosition();
	m_cannon.setPosition(cannonBasePosition);
	m_cannon.update(deltaTime);
	m_position = cannonBasePosition;
}