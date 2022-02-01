//Домашняя работа по уроку №2 Литвинов Дмитрий

#include <iostream>

int main()
{
    // Задание 1: Создать и инициализировать переменные пройденных типов данных 
    //            (short int, int, long long, char, bool, float, double).

    short shortVar = 100;        //2 байта, целое число -32768..32768

    int intVar;                  //4 байта, целое число 
    intVar = 150;                //инициализация

    long long longLongVar;       //8 байт, целое число 18 нулей.
    longLongVar = 9'000'000'000;

    char charVar{ 'Х' };           //1 байт, символ в кодировке ASCII -128..127 или0..255
    charVar = 149;

    bool boolFlag = false;       // 0 или 1, true or false

    float floatVar;              //4 байта, число с плавающей точкой -3.4Е-38..3.4Е+38
    floatVar = 3.1415;

    double doubleVar;            //8 байт, систо с плавающей точкой двойной точности до 1.7Е+308
    doubleVar = -3.141592;

    // Задание 2: Создать перечисление (enum) с возможными вариантами символов 
    //            для игры в крестики-нолики.

    enum  gameSymbols { empty, X, O };

    // Задание 3: Создать массив, способный содержать значения такого перечисления
    //            и инициализировать его.

    const short SIZE = 3;    // задаем размерность массива
    char fieldValue[SIZE][SIZE];  //создаем двумерный массив
    for (short i = 0; i < SIZE; i++)
    {
        for (short j = 0; j < SIZE; j++)
            fieldValue[i][j] = gameSymbols::empty;  //Заполняем массив значениями empty
    }

    // Задание 4: * Создать структуру (struct) данных «Поле для игры в крестики-нолики» 
    // и снабдить его всеми необходимыми свойствами (подумайте что может понадобиться).

    struct cellBoard
    {
        unsigned short cellNamber[9]; //номер поля
        char cellValue;               //значение в поля
        bool cellFlag;                //флаг, true - поле занято, false - поле свободно
    };

    return 0;
}
