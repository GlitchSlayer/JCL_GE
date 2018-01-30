#pragma once
#include "sceneObject.h"

class CannonBase
	: public SceneObject
{
private:
	sf::Vector2f m_velocity;
	sf::Vector2f m_velocityGoal;
public:
	CannonBase(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 100, 50 }, const sf::Color& color = { 255, 0, 0 });
	virtual ~CannonBase();

	virtual void update(const float& deltaTime);
};