#include "FlyingCarpet.h"

FlyingCarpet::FlyingCarpet()
{
	name = "Ковёр-самолёт";
	speed = 10;
	vehicle_num = 5;
}

float FlyingCarpet::get_race_time(float distance)
{
	
	if (distance < 1000)
	{
		coeff = 1;
	}
	else if (distance >= 1000 && distance < 5000)
	{
		coeff = static_cast <float>(0.97);
	}
	else if (distance >= 5000 && distance < 10000)
	{
		coeff = static_cast <float>(0.9);
	}
	else if (distance >= 10000)
	{
		coeff = static_cast <float>(0.95);
	}
	distance_coeff = distance * coeff;
	result_time = distance_coeff / speed;
	return result_time;
}