
#include <iostream>
#include <locale>

// Задание 4*: Написать программу, проверяющую, является ли некоторое число - простым.
// Простое число — это целое положительное число, которое делится без остатка 
//только на единицу и себя само.

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int myNumber;
	bool myFlag = false;

label1:

	std::cout << "Введите целое положительное число:";
	std::cin >> myNumber;

	if (myNumber <= 0)
	{
		std::cout << "Число не положительное." << "Читайте внимательнее!" << std::endl;
		goto label1; //проверка число на положительность
	}

	for (int i = 2; i <= myNumber - 1; i++)
	{
		if (myNumber % i == 0)
		{
			std::cout << "Число " << myNumber << " НЕ является простым." << std::endl;
			myFlag = true;
			break;
		}
		else { continue; }

	}
	if (myFlag == false) //за весь цикл не было деления без остатка
	{
		std::cout << "Число " << myNumber << " является ПРОСТЫМ." << std::endl;
	}

	return 0;
}
