#pragma once
#include "sceneObject.h"

class CannonBase
	: public SceneObject
{
private:
	sf::Texture m_texture;
	sf::Vector2f m_velocity;
	sf::Vector2f m_velocityGoal;
public:
	CannonBase(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 64, 64 });
	virtual ~CannonBase();

	virtual void update(const float& deltaTime);
};