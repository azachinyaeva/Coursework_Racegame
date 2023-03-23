#pragma once

enum class RaceType
{
	Ground = 1, Air, Mixed
};

enum class TransportType
{
	Centaur = 1, Camel, HighspeedCamel, AllTerrainBoots,
	FlyingCarpet, Broomstick, Eagle
};

int choose_race();
int choose_distance();
void choose_vehicle(int RaceNum, int distance, int registered);
bool stop();
