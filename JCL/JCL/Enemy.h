#pragma once
#include "player.h"

class Enemy
{
public:
	std::string name;
	int hp, speed, damage;
	sf::Vector2f m_positon;
	sf::RectangleShape m_shape;
	Enemy(std::string _name = "Default name", sf::Vector2f _pos = { 500, 500 });
	~Enemy();
	void taunt();
	void draw(sf::RenderWindow& window);
	void update(const float& deltaTime);
};

