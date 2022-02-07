
#include <iostream>
#include <locale>

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	//Задание 2: Написать программу, выводящую на экран строку “true”, если две 
	// целочисленные константы, объявленные в её начале, либо обе равны
	// десяти сами по себе, либо их сумма равна десяти. Иначе "false".

	int a2Num, b2Num;

	std::cout << "Введите первое число:";
	std::cin >> a2Num;    //вводим первое число
	std::cout << "Введите второе число:";
	std::cin >> b2Num;    //вводим второе число

	int c2Num = a2Num + b2Num; //складываем введенные числа

	if ((a2Num == 10 && b2Num == 10) || c2Num == 10)
	{
		std::cout << "true" << std::endl; //выводим true, если условие выполнено
	}
	else
	{
		std::cout << "false" << std::endl; //выводим false, если нет
	}

	return 0;
}
