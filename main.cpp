
#include <iostream>
#include <fstream>
#include "mylib.h"
#include <locale>
using namespace std;

//Задание 2
#define CHECK(num1,num2) ((num1>=0 && num1<num2) ? true : false)



void myFunc2()
{
	int a = 100, myNum;
	cout << "Введите число: ";
	cin >> myNum;
	if (CHECK(myNum, a))
	{
		cout << endl << "Ваше число " << myNum << " попало в диапазон от 0 до " << a << endl;
	}
	else
	{
		cout << endl << "Увы. Ваше число " << myNum << " не попало в диапазон от 0 до " << a << endl;
	}
}


//Задание 3
#define ARRAY_SIZE 5
#define SwapInt(a, b) (swap(a,b))

void initArrayArm(int array[], size_t size)
{
	int myInt;
	for (size_t i = 0; i < size; i++)
	{
		cout << "Введите целое число - " << i + 1 << "-й элемент массива:";
		cin >> myInt;
		array[i] = myInt;  //Заполняем массив вводом с клавиатуры
	}
}

void printIntArr(int array[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

void sortArray(int array[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (array[i] < array[j]) 
			{
				SwapInt(array[i], array[j]);
			}
		}
	}
}

void myFunc3()
{
	int myArr[ARRAY_SIZE];
	initArrayArm(myArr, ARRAY_SIZE);
	cout << "Наш массив до сотритовки:" << endl;
	printIntArr(myArr, ARRAY_SIZE);
	sortArray(myArr, ARRAY_SIZE);
	cout << endl << "Наш массив после сотритовки:" << endl;
	printIntArr(myArr, ARRAY_SIZE);
}


//Задание 4

void myFunc4()
{
	string fileName = "MyStrFile.txt";
#pragma pack(push, 1)       //побайтовое выраснивание структуры
	struct Employee         //создаем новый тип Сотрудник
	{
		long id;            // ID сотрудника
		string name;        // его ФИО
		unsigned short age; // его возраст
		double salary;      // его зарплата
	};
#pragma pack(pop)           //прекращаем выравнивание

	Employee* pEmployee = new Employee;  //создаем динамическую переменную типа Сотрудник
	
	pEmployee->id = 23445;
	pEmployee->name = "Литвинов Д.А.";
	(*pEmployee).age = 40;
	pEmployee->salary = 120'000;         // Заполняем переменную

	//выводим на экран данные сотрудника
	cout << endl << "Наш новый сотрудник: " << pEmployee->name << " (ID " << pEmployee->id << ")" << endl << "Его возраст - " << pEmployee->age << " лет" << endl << "Его ЗП = " << pEmployee->salary << "р." << endl;
	
	//Выводим на экран размер этой структуры
	cout << "Размер этой структуры = " << sizeof(pEmployee) << endl;
	
	//Создаем файл и записываем в него данные сотрудника
	ofstream fout(fileName);
	fout << "Наш новый сотрудник: " << pEmployee->name << " (ID " << pEmployee->id << ")" << endl << "Его возраст - " << pEmployee->age << " лет" << endl << "Его ЗП = " << pEmployee->salary << "р.";
	fout.close();

	delete pEmployee; //Освобождаем память

}


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	//Задание 1 и 5
	const size_t SIZE = 8;
	float array[SIZE] = { 0,0,0,0,0,0,0,0 };
	myLib::initArray(array, SIZE); //заполняем
	myLib::printArray(array, SIZE);//печатаем на экран
	myLib::myCalc(array, SIZE);    //считаем + и -

	//////////////////////////////////
	myFunc2();   //Задание 2
	myFunc3();   //Задание 3
	myFunc4();   //Задание 4
}

//Задание 1: Создайте проект из 2х cpp файлов и заголовочного
//  (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 
//  3 функции: для инициализации массива(типа float), печати его на экран
//  и подсчета количества отрицательных и положительных элементов.
//  Вызывайте эти 3 функции из main для работы с массивом.

//Задание 2: Описать макрокоманду (через директиву define), проверяющую,
//  входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля 
//  (включительно) до переданного ей второго аргумента (исключительно) и 
//  возвращает true или false, вывести на экран «true» или «false».

//Задание 3: Задайте массив типа int. Пусть его размер задается через директиву
//  препроцессора #define. Инициализируйте его через ввод с клавиатуры. 
//  Напишите для него свою функцию сортировки (например Пузырьком). 
//  Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). 
//  Вызывайте ее из цикла сортировки.

//Задание 4*: Объявить структуру Сотрудник с различными полями. 
//  Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. 
//  Выделите динамически переменную этого типа. Инициализируйте ее. 
//  Выведите ее на экран и ее размер с помощью sizeof. 
//  Сохраните эту структуру в текстовый файл.

//Задание 5*: Сделайте задание 1 добавив свой неймспейс во втором модуле
//  (первое задание тогда можно не делать).