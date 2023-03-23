#include <iostream>
#include "RaceDetails.h"

int choose_race() {
	int type;
	while (true) {
		std::cout << "Выберите тип гонки: \n";
		std::cin >> type;
		if (type >= 1 && type <= 3) {
			break;
		}
		else {
			std::cout << "Неверный тип гонки! \n";
		}
	}
	return type;

}

int choose_distance() {
	int distance;
	std::cout << "Укажите длину дистанции (должна быть положительна): ";
	std::cin >> distance;
	while (true)
	{
		if (distance < 1)
		{
			std::cout << "Дистанция должна быть больше нуля, попробуйте еще раз:";
			std::cin >> distance;
		}
		else
		{
			break;
		}
	}
	return distance;
}

void choose_vehicle(int RaceNum, int distance, int registered) {
	switch (RaceNum) {
	case static_cast<int>(RaceType::Ground):
		std::cout << "Вы выбрали гонку для наземного транспорта. Расстояние: " << distance << '\n';
		std::cout << "Зарегистрируйте транспортные средства: \n";
		std::cout << "1. Кентавр \n";
		std::cout << "2. Верблюд \n";
		std::cout << "3. Верблюд-быстроход \n";
		std::cout << "4. Ботинки-вездеходы \n";
		break;
	case static_cast<int>(RaceType::Air):
		std::cout << "Вы выбрали гонку для воздушного транспорта. Расстояние: " << distance << '\n';
		std::cout << "Зарегистрируйте транспортные средства: \n" << std::endl;
		std::cout << "1. Ковёр-самолёт \n";
		std::cout << "2. Метла \n";
		std::cout << "3. Орёл \n";
		break;
	case static_cast<int>(RaceType::Mixed):
		std::cout << "Вы выбрали гонку для наземного и воздушного транспорта. Расстояние: " << distance << '\n';
		std::cout << "Зарегистрируйте транспортные средства: \n";
		std::cout << "1. Кентавр \n";
		std::cout << "2. Верблюд \n";
		std::cout << "3. Верблюд-быстроход \n";
		std::cout << "4. Ботинки-вездеходы \n";
		std::cout << "5. Ковёр-самолёт \n";
		std::cout << "6. Метла \n";
		std::cout << "7. Орёл \n";
		break;
	default:
		std::cout << "Ошибка регистрации. Попробуйте ещё раз \n";
		break;
	}
	if (registered >= 2) {
		std::cout << "0. Завершить выбор и начать гонку \n";
	}
}

bool stop() 
{
	int tmp = 0;
	std::cout << "1. Провести еще одну гонку. \n";
	std::cout << "2. Выйти \n";
	std::cout << "Выберите действие: ";
	std::cin >> tmp;

	if (tmp != 1 && tmp != 2)
	{
		do
		{
			std::cout << "Можно выбрать только 1 или 2, попробуйте еще раз:  ";
			std::cin >> tmp;
		} while (!(tmp == 1 || tmp == 2));
	};
	if (tmp == 1)
	{
		return false;
	}
	return true;
}
