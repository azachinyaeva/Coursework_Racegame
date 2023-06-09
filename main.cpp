#include <iostream>
#include <string>

#include "AllTerrainBoots.h"
#include "Broomstick.h"
#include "Camel.h"
#include "Centaur.h"
#include "Eagle.h"
#include "FlyingCarpet.h"
#include "HighspeedCamel.h"
#include "Vehicle.h"
#include "RaceDetails.h"

int main() {
	setlocale(LC_ALL, "Russian");
	const int SIZE = 7;
	int RaceNum = 0;
	int distance = 0;
	do {
		std::cout << "����� ���������� � �������� ���������!\n";
		std::cout << "1. ����� ��� ��������� ���������� \n";
		std::cout << "2. ����� ��� ���������� ���������� \n";
		std::cout << "3. ����� ��� ��������� � ���������� ���������� \n";
		RaceNum = choose_race();
		system("cls");
		distance = choose_distance();

		Vehicle** arr = new Vehicle * [SIZE] {};
		int registered = 0;
		int userinput = 0;

		system("cls");
		choose_vehicle(RaceNum, distance, registered);

		do
		{
			std::cin >> userinput;
			if (userinput < 0 || userinput > 7) {
				std::cout << "������ �����������: ������� �������������� ��! \n";
				continue;
			}
			else if (userinput == 0) {
				break;
			}
			if (RaceNum == 2) {
				userinput += 4; //��������� ������ ����� ��� ����� ��������� ��
			}

			for (int i = 0; i < SIZE; i++) {
				if (arr[i] != 0) {
					if (arr[i]->get_vehicle_num() == userinput) {
						std::cout << arr[i]->get_vehicle_num() << " ��� ���������������! \n";
						break;
					}
				}
				else if (arr[i] == 0) {
					registered++;
					switch (userinput)
					{
					case static_cast<int> (TransportType::Centaur):
						arr[i] = new Centaur();
						break;
					case static_cast<int> (TransportType::Camel):
						arr[i] = new Camel();
						break;
					case static_cast<int> (TransportType::HighspeedCamel):
						arr[i] = new HighspeedCamel();
						break;
					case static_cast<int> (TransportType::AllTerrainBoots):
						arr[i] = new AllTerrainBoots();
						break;
					case static_cast<int> (TransportType::FlyingCarpet):
						arr[i] = new FlyingCarpet();
						break;
					case static_cast<int> (TransportType::Broomstick):
						arr[i] = new Broomstick();
						break;
					case static_cast<int> (TransportType::Eagle):
						arr[i] = new Eagle();
						break;
					default:
						break;
					}
					system("cls");
					std::cout << arr[i]->get_vehicle_name() << " ������� ���������������! \n";
					choose_vehicle(RaceNum, distance, registered);
					break;
				}
			}

		} while (userinput != 0);
		system("cls");

		bool swapped = false;
		do {
			bool swapped = false;
			Vehicle* tmp;
			for (int i = 0; i < registered - 1; i++) {
				for (int j = 0; j < (registered - 1); j++) {
					if (arr[j + 1]->get_race_time(static_cast<float>(distance)) < arr[j]->get_race_time(static_cast<float>(distance))) {
						tmp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = tmp;
						swapped = true;
					}
				}
			}
		} while (swapped);

		std::cout << "���������� �����: \n";
		int num = 1;
		for (int i = 0; i < registered; i++) {
			std::cout << num << ". " << arr[i]->get_vehicle_name() << ". �����: " << arr[i]->get_race_time(static_cast<float>(distance)) << '\n';
			num++;
		}
		std::cout << std::endl;

		delete[] arr;

	} while (!stop());
	
	return 0;
}




