#pragma once
#include "sceneObject.h"

class Cannon
	: public SceneObject
{
private:
	const float m_shootDelay;
	float m_shootDelayCounter;
public:
	Cannon(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 100, 50 }, const sf::Color& color = { 0, 255, 0 });
	virtual ~Cannon();

	virtual void update(const float& deltaTime);
};