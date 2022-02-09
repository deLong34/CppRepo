
#include <iostream>
#include <locale>

using namespace std;

//Задание 1. 
    // Написать функцию которая выводит массив double чисел на экран.
    // Параметры функции это сам массив и его размер.Вызвать эту функцию из main.


void myArrFan(double arr[], int size) //Выводит элементы массива double на экран (Задание 1)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
    }
}

void myArrInt(int arr[], int size) //Выводит элементы массива int на экран (Задание 2 и 3)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void myChangeFun(int arr[], int size) //меняет 0 на 1, а 1 на 0 (задание 2)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 0)
		{
			arr[i] = 1;
		}
		else if (arr[i] == 1)
		{
			arr[i] = 0;
		}
	}
}

//Задание 3:
	//Задать пустой целочисленный массив размером 8.
	//Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22.
	//Вывести массив на экран.

void myArrInit(int arr[], int size)
{
	arr[0] = 1;
	for (size_t i = 1; i < size; i++)
	{
		arr[i] = arr[i - 1] + 3;
	}
}

//Задание 4*:
	//Написать функцию, которой на вход подаётся одномерный массив и число n
	//(может быть положительным, или отрицательным), при этом метод должен циклически 
	// сместить все элементы массива на n позиций

bool myShift(int arr[], int n, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		int j = i + n;
		if ( j >= 0 && j < size )
		{
			cout << arr[j] << " ";
		}
		else if ( j >= size )
		{ 
			do
			{
				j -= size;
			} while (j >= size);
			cout << arr[j] << " ";
		}

		else if ( j < 0 )
		{
			do
			{
				j += size;
			} while (j < 0);
			cout << arr[j] << " ";
		}
	}
	return true;
}

//Задание 5*:
  //Написать функцию, которой передается не пустой одномерный
  //целочисленный массив, она должна вернуть истину если в массиве есть место,
  //в котором сумма левой и правой части массива равны.
  //Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance([2, 1, 1, 2, 1]) → false,
  //checkBalance([10, || 1, 2, 3, 4]) → true.

bool checkBalance(int arr[5])
{
	if (arr[0] == arr[1] + arr[2] + arr[3] + arr[4])
		return true;
	else if (arr[0] + arr[1] == arr[2] + arr[3] + arr[4])
		return true;
	else if (arr[0] + arr[1] + arr[2] == arr[3] + arr[4])
		return true;
	else if (arr[0] + arr[1] + arr[2] + arr[3] == arr[4])
		return true;
	else
		return false;
}
////////////////////////////////////////////////////////

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	const int MYSIZE = 9; //Задаем параметры функции
	double myArr[] = { 111.12, 222, 333.44, 444, 555.56, 666, 777, 888 };

	myArrFan(myArr, MYSIZE); //Вызываем функцию
	cout << " <- Массив напечатан успешно" << endl;
	//9-й не инициированный элемент массива, почему он не 0?

//Задание 2: 
	//Задать целочисленный массив, состоящий из элементов 0 и 1.
	//Например: [1, 1, 0, 0, 1, 0, 1, 1, 0, 0] .
	//Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0.
	//Выводить на экран массив до изменений и после.
	
	int myArr2[] = { 0, 1, 1,  1, 0, 0, 1, 1, 0, 1 };
	const int MYSIZE2 = 10;


	myArrInt(myArr2, MYSIZE2); //Печатаем массив до изменения
	cout << " <- Наш массив ДО изменения" << endl;


	myChangeFun(myArr2,MYSIZE2);

	myArrInt(myArr2, MYSIZE2); //Печатаем массив после изменения
	cout << " <- Наш массив ПОСЛЕ изменения" << endl;
	
//Задание 3:
	//Задать пустой целочисленный массив размером 8.
	//Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22.
	//Вывести массив на экран.
	
	const int MYSIZE3 = 8;
	int myArr3[MYSIZE3];
	myArrInit(myArr3, MYSIZE3);
	for (size_t i = 0; i < MYSIZE3; i++)
	{
		cout << myArr3[i] << " ";
	}
	cout << " <- Массив по заданию 3" << endl;

//Задание 4*:
    //Написать функцию, которой на вход подаётся одномерный массив и число n
    //(может быть положительным, или отрицательным), при этом метод должен циклически 
	// сместить все элементы массива на n позиций.

	const int N = -28;
	const int L = 6;
	int myArr4[L] = {10, 20, 30, 40, 50, 60};

	if (myShift(myArr4, N, L))
	{
		cout << " <- Вот сдвинутый на " << N << " массив" << endl;
	}

//Задание 5*:

	const short SIZE5 = 5;
	int myArr5[SIZE5] = { 5, 2, 3, 5, 5 };
	cout << "Массив ";
	for (size_t i = 0; i < SIZE5; i++)
	{
		cout << myArr5[i] << " ";
	}
	if (checkBalance(myArr5))
	{
		cout << "Сбаллансирован по сумме частей." << endl;
	}
	else 
		cout << "Не сбалансирован по сумме частей." << endl;

	return 0;
}
