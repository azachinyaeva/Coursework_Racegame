#include "Broomstick.h"

Broomstick::Broomstick()
{
	name = "Метла";
	speed = 20;
	vehicle_num = 6;
}

float Broomstick::get_race_time(float distance)
{
	coeff = 1 - (static_cast<float>((static_cast<int>(distance / 1000))) / 100);
	distance_coeff = distance * coeff;
	result_time = distance_coeff / speed;
	return result_time;
}

	