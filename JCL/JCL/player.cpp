#include "stdafx.h"

Player::Player(const sf::Vector2f& position)
	:   SceneObject(position),
		m_cannonBase(position),
		m_cannon(position), 
		m_maxLightPoints(100),
		m_lightPoints(100),
		isDead(0)
{
	m_lightPointsShape.setFillColor({ 255, 255, 0 });
}

Player::Player(const CannonBase& cannonBase, const Cannon& cannon)
	:	SceneObject(cannonBase.getPosition()), 
		m_cannonBase(cannonBase),
		m_cannon(cannon), 
		m_maxLightPoints(100),
		m_lightPoints(100),
		isDead(0)
{
	m_lightPointsShape.setFillColor({ 255, 255, 0 });
}

Player::~Player()
{
	std::cout << "Player destroyed\n";
}

void Player::setLightPoints(const float& value)
{
	m_lightPoints = value;
}

float Player::getLightPoints() const
{
	return m_lightPoints;
}

void Player::draw(sf::RenderWindow& window)
{
	m_cannonBase.draw(window);
	m_cannon.draw(window);
	window.draw(m_lightPointsShape);
}

void Player::update(const float& deltaTime)
{
	m_cannonBase.update(deltaTime);
	const sf::Vector2f&& cannonBasePosition = m_cannonBase.getPosition();
	m_cannon.setPosition(cannonBasePosition);

	m_cannon.update(deltaTime);

	m_position = cannonBasePosition;

	m_lightPoints -= deltaTime / 10;

	if (m_lightPoints <= 0)
		isDead = true;

	m_lightPointsShape.setSize({ m_lightPoints/m_maxLightPoints * 64, 16 });
	m_lightPointsShape.setPosition(m_position - sf::Vector2f(30.f, 50.f));
}