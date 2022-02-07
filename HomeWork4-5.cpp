//Задание 5*: Пользователь вводит с клавиатуры число(год) : от 1 до 3000.
//Написать программу, которая определяет является ли этот год високосным.
//Каждый 4-й год является високосным, кроме каждого 100-го, 
//при этом каждый 400-й – високосный. 
//Вывести результаты работы программы в консоль.

#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    unsigned int myYear;

    std::cout << "Введите число от 1 до 3000:";
    std::cin >> myYear;
    if (myYear < 1 || myYear > 3000)
    {
        std::cout << "Вы ввели число, не удовлетворяющее условию.";
        return 0;
    }
    else if (myYear % 400 == 0)
    {
        std::cout << myYear << " год является високосным.";
        return 0;
    }
    else if (myYear % 100 == 0)
    {
        std::cout << myYear << " год НЕ является високосным.";
        return 0;
    }
    else if (myYear % 4 == 0)
    {
        std::cout << myYear << " год является високосным.";
        return 0;
    }
    else 
    {
        std::cout << myYear << " год НЕ является високосным.";
        return 0;
    }

    return 0;
}
