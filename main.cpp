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
		std::cout << "Добро пожаловать в гоночный симулятор!\n";
		std::cout << "1. Гонка для наземного транспорта \n";
		std::cout << "2. Гонка для воздушного транспорта \n";
		std::cout << "3. Гонка для наземного и воздушного транспорта \n";
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
				std::cout << "Ошибка регистрации: выбрано несуществующее ТС! \n";
				continue;
			}
			else if (userinput == 0) {
				break;
			}
			if (RaceNum == 2) {
				userinput += 4; //присвоить верный номер для гонки воздушных ТС
			}

			for (int i = 0; i < SIZE; i++) {
				if (arr[i] != 0) {
					if (arr[i]->get_vehicle_num() == userinput) {
						std::cout << arr[i]->get_vehicle_num() << " уже зарегистрирован! \n";
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
					std::cout << arr[i]->get_vehicle_name() << " успешно зарегистрирован! \n";
					choose_vehicle(RaceNum, distance, registered);
					break;
				}
			}

		} while (userinput != 0);
		system("cls");

		bool swapped = false;
		do {
			bool swapped = false;
			for (int i = 0; i < registered - 1; i++) {
				if (arr[i + 1]->get_race_time(static_cast<float>(distance)) < arr[i]->get_race_time(static_cast<float>(distance))) {
					std::swap(arr[i + 1], arr[i]);
					swapped = true;
				}
			}
		} while (swapped);

		std::cout << "Результаты гонки: \n";
		int num = 1;
		for (int i = 0; i < registered; i++) {
			std::cout << num << ". " << arr[i]->get_vehicle_name() << ". Время: " << arr[i]->get_race_time(static_cast<float>(distance)) << '\n';
			num++;
		}
		std::cout << std::endl;

		delete[] arr;

	} while (!stop());
	
	return 0;
}




