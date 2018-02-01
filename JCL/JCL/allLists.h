#pragma once
#include <vector>
#include "bullet.h"

class AllLists
{
public:
	static std::vector<SceneObject> livingSceneObjects;
	static std::vector<Bullet> allBullets;
};