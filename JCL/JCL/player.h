#pragma once
#include "cannonBase.h"
#include "cannon.h"
#include "application.h"

class Player
	: public SceneObject
{
private:
	float m_lightPoints;
	const float m_maxLightPoints;
	sf::RectangleShape m_lightPointsShape;

	CannonBase m_cannonBase;
	Cannon m_cannon;

public:
	bool isDead;

	Player(const sf::Vector2f& position = { App::screenDismentions.x / 2, App::screenDismentions.y / 2 });
	Player(const CannonBase& cannonBase, const Cannon& cannon);
	virtual ~Player();

	void setLightPoints(const float& value);
	float getLightPoints() const;

	virtual void draw(sf::RenderWindow& window);
	virtual void update(const float& deltaTime);
};