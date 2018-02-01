#pragma once
#include "sceneObject.h"

class Cannon
	: public SceneObject
{
private:
	sf::Texture m_texture;
	const float m_shootDelay;
	float m_shootDelayCounter;
public:
	Cannon(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 32, 64 });
	virtual ~Cannon();

	virtual void update(const float& deltaTime);
};