#pragma once
#include "Enemy.h"

class Reaper :
	public Enemy
{
public:
	Reaper(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 10, 10 });
	~Reaper();
};

