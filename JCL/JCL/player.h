#pragma once
#include "cannonBase.h"
#include "cannon.h"

class Player
{
private:
	int m_lightPoints;
	CannonBase m_cannonBase;
	Cannon m_cannon;

public:
	Player(const CannonBase& cannonBase, const Cannon& cannon);
	~Player() {}

	void draw(sf::RenderWindow& window);
	void update(const float& deltaTime);
};