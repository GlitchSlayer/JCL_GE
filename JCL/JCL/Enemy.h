#pragma once
#include "player.h"
#include "cannon.h"
#include "cannonBase.h"


class Enemy
{
public:
	std::string m_name;
	int m_hp, m_speed, m_damage;
	sf::Vector2f m_position;
	sf::RectangleShape m_shape;

	Enemy(std::string _name = "Default name", sf::Vector2f _pos = {500, 500});
	~Enemy();
	void taunt();
	void draw(sf::RenderWindow& window);
	void update(const float& deltaTime);
};

