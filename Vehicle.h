#pragma once
#include <iostream>
#include <string>

class Vehicle {
public:
	int get_vehicle_num();
	std::string get_vehicle_name();
	float get_result_time();
	virtual float get_race_time(float distance);

protected:
	std::string name = "";
	int speed = 0;
	int vehicle_num = 0;
	float time_before_rest = 0;
	int count_rest = 0;
	float first_rest = 0;
	float second_rest = 0;
	float further_rest = 0;
	float coeff = 0; //коэффициент сокращения расстояния для воздушного транспорта
	float distance_coeff = 0;
	float result_time = 0;
	float distance_remained = 0; //оставшаяся до финиша дистанция
	float total_rest_time = 0; //общее время отдыха
	float time_without_rest = 0; //время без учёта отдыха
};