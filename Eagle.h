#pragma once
#include "Vehicle.h"

class Eagle : public Vehicle
{
public:
	Eagle();
	float get_race_time(float distance);
};