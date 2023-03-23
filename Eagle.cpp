#include "Eagle.h"

Eagle::Eagle(){
	name = "Îð¸ë";
	speed = 8;
	vehicle_num = 7;
}

float Eagle::get_race_time(float distance)
{
	coeff = static_cast <float>(0.94);
	distance_coeff = distance * coeff;
	result_time = distance_coeff / speed;
	return result_time;
}
