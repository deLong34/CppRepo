#include <iostream>
#include <locale>

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
//Задание 1: Написать программу, проверяющую что сумма двух(введенных с клавиатуры)
//  чисел лежит в пределах от 10 до 20 (включительно), если да – вывести строку "true",
//  в противном случае – "false".

	unsigned int aNum, bNum;

	std::cout << "Введите первое число:";
	std::cin >> aNum;    //вводим первое число
	std::cout << "Введите второе число:";
	std::cin >> bNum;    //вводим второе число

	int cNum = aNum + bNum; //складываем введенные числа

	if (10 <= cNum <= 20)
	{
		std::cout << "true" << std::endl; //выводим true, если условие выполнено
	}
	else 
	{
		std::cout << "false" << std::endl; //выводим false, если нет
	}
	


	return 0;
}
