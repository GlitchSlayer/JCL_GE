#include "stdafx.h"

float phys::Approach(const float& flGoal, const float& flCurrent, const float& dt)
{
	float flDiffrence = flGoal - flCurrent;

	if (flDiffrence > dt)
		return flCurrent + dt;

	if (flDiffrence < -dt)
		return flCurrent - dt;

	return flGoal;
}
