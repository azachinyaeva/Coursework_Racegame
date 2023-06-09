#include <iostream>
#include "RaceDetails.h"

int choose_race() {
	int type;
	while (true) {
		std::cout << "�������� ��� �����: \n";
		std::cin >> type;
		if (type >= 1 && type <= 3) {
			break;
		}
		else {
			std::cout << "�������� ��� �����! \n";
		}
	}
	return type;

}

int choose_distance() {
	int distance;
	std::cout << "������� ����� ��������� (������ ���� ������������): ";
	std::cin >> distance;
	while (true)
	{
		if (distance < 1)
		{
			std::cout << "��������� ������ ���� ������ ����, ���������� ��� ���:";
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
		std::cout << "�� ������� ����� ��� ��������� ����������. ����������: " << distance << '\n';
		std::cout << "��������������� ������������ ��������: \n";
		std::cout << "1. ������� \n";
		std::cout << "2. ������� \n";
		std::cout << "3. �������-��������� \n";
		std::cout << "4. �������-��������� \n";
		break;
	case static_cast<int>(RaceType::Air):
		std::cout << "�� ������� ����� ��� ���������� ����������. ����������: " << distance << '\n';
		std::cout << "��������������� ������������ ��������: \n" << std::endl;
		std::cout << "1. ����-������ \n";
		std::cout << "2. ����� \n";
		std::cout << "3. ��� \n";
		break;
	case static_cast<int>(RaceType::Mixed):
		std::cout << "�� ������� ����� ��� ��������� � ���������� ����������. ����������: " << distance << '\n';
		std::cout << "��������������� ������������ ��������: \n";
		std::cout << "1. ������� \n";
		std::cout << "2. ������� \n";
		std::cout << "3. �������-��������� \n";
		std::cout << "4. �������-��������� \n";
		std::cout << "5. ����-������ \n";
		std::cout << "6. ����� \n";
		std::cout << "7. ��� \n";
		break;
	default:
		std::cout << "������ �����������. ���������� ��� ��� \n";
		break;
	}
	if (registered >= 2) {
		std::cout << "0. ��������� ����� � ������ ����� \n";
	}
}

bool stop() 
{
	int tmp = 0;
	std::cout << "1. �������� ��� ���� �����. \n";
	std::cout << "2. ����� \n";
	std::cout << "�������� ��������: ";
	std::cin >> tmp;

	if (tmp != 1 && tmp != 2)
	{
		do
		{
			std::cout << "����� ������� ������ 1 ��� 2, ���������� ��� ���:  ";
			std::cin >> tmp;
		} while (!(tmp == 1 || tmp == 2));
	};
	if (tmp == 1)
	{
		return false;
	}
	return true;
}
