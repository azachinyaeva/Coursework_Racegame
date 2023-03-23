#pragma once
#include "Vehicle.h"

class Broomstick : public Vehicle 
{
public:
	Broomstick();
	float get_race_time(float distance);
};
