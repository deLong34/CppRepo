//Задание 5
// Вариант с меняемым размером вводного массива

#include <iostream>
#include <locale>

bool fCheckBalance(int arr[], const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        int sum1 = 0, sum2 = 0;
        for (size_t j = 0; j <= i; j++)
        {
            sum1 += arr[j];
        }
        for (size_t k = 1; k < SIZE - i; k++)
        {
            sum2 += arr[k];
        }
        if (sum1 = sum2)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    const int N = 8;
    int myArr[N] = { 17,2,3,4,5,6,7,8 };
    for (size_t i = 0; i < N; i++)
    {
        std::cout << myArr[i] << " ";
    }
        if (fCheckBalance(myArr, N))
        {
        std::cout << " Массив сбалансирован." << std::endl;
        }
        else 
        {
        std::cout << " Массив не сбаллансирован" << std::endl;
        }
return 0;
}
