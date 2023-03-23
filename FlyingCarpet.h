#pragma once
#include "Vehicle.h"

class FlyingCarpet : public Vehicle
{
public:
	FlyingCarpet();
	float get_race_time(float distance);
};