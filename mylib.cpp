#include <iostream>
using namespace std;

namespace myLib {
	void initArray(float array[], int size)  //�������������� ������
	{
		for (size_t i = 0; i < size; i++)
		{
			array[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 100)) - 50;   //��������� ������
		}
	}

	void printArray(float array[], int size) //������� ������ �� �����
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
	}

	void myCalc(float array[], int size)    //������� ������������� � ������������� �������� �������
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
		cout << endl << "� ����� ������� " << p << " ������������� � " << m << " ������������� �����." << endl;
	}

}