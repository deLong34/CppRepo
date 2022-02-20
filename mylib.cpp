#include <iostream>
using namespace std;

namespace myLib {
	void initArray(float array[], int size)  //»нициализируем массив
	{
		for (size_t i = 0; i < size; i++)
		{
			array[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 100)) - 50;   //заполн€ем массив
		}
	}

	void printArray(float array[], int size) //выводим массив на экран
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
	}

	void myCalc(float array[], int size)    //считаем положительные и отрицательные элементы массива
	{
		int m = 0, p = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] < 0)
			{
				m++;
			}
			else
			{
				p++;
			}
		}
		cout << endl << "¬ нашем массиве " << p << " положительных и " << m << " отрицательных чисел." << endl;
	}

}