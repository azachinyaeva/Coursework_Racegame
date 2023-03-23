#include "Vehicle.h"


int Vehicle::get_vehicle_num()
{
	return vehicle_num;
}

std::string Vehicle::get_vehicle_name()
{
	return name;
}

float Vehicle::get_result_time()
{
	return result_time;
}

float Vehicle::get_race_time(float distance)
{
	float distance_before_rest = static_cast<float>(speed * time_before_rest);
	int rests = static_cast<int>(distance / distance_before_rest);
	distance_remained = distance - rests * distance_before_rest;

	if (rests == 0)
	{
		total_rest_time = 0;
	}
	else if (rests == 1)
	{
		total_rest_time = first_rest;
	}
	else if (rests == 2)
	{
		total_rest_time = first_rest + second_rest;
	}
	else
	{
		if (distance_remained == 0)
		{
			total_rest_time = (rests - 2) * further_rest + first_rest;
		}
		else
		{
			total_rest_time = (rests - 2) * further_rest + first_rest + second_rest;
		}
	}

	time_without_rest = time_before_rest * rests + distance_remained / speed;
	result_time = time_without_rest + total_rest_time;

	return result_time;
}