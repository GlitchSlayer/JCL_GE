#pragma once
#include "cannonBase.h"
#include "cannon.h"

class Player
	: public SceneObject
{
private:
	int m_lightPoints;
	CannonBase m_cannonBase;
	Cannon m_cannon;

public:
	Player(const CannonBase& cannonBase, const Cannon& cannon);
	virtual ~Player();

	virtual void draw(sf::RenderWindow& window);
	virtual void update(const float& deltaTime);
};