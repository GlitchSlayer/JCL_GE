#pragma once
#include "Enemy.h"
class Reaper :
	public Enemy
{
public:
	Reaper(std::string _name = "Default name", sf::Vector2f _pos = { 500, 500 });
	~Reaper();
};

