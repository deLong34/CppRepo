
#include <iostream>
#include <locale>
#include <fstream>
#include <string>

using namespace std;


//Задание 1: Выделить в памяти динамический одномерный массив типа int. 
//    Размер массива запросить у пользователя. Инициализировать его числами 
//    степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 ... Вывести массив на экран.
//    Не забыть освободить память. =) Разбить программу на функции.

int myMulty(int arr[], int size, int num) //Функция инициирует массив размера size
                                          //со степенями числа num
{
    for (size_t i = 0; i < size; i++)
    {
        if (i == 0)
        {
            arr[i] = 1; //Все числа в степень 0 равны 1
        }
        else if (i == 1)
        {
            arr[i] = num; //Все числа в степени 1 равны сами себе
        }
        else
        {
            arr[i] = arr[i - 1] * num; //Умножаем предыдущую степень на заданное число
        }
    }
    return arr[size];
}


void myOutput (int arr[], int size) //Функция вывода на экран массива
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "<- Вот наш массив из " << size << " элементов" << endl;
}


inline void myFanc1()
{
    int* ptrArr;
    int n;
    int number = 2;
    cout << "Введите размер массива: ";
    cin >> n;


    if (n > 0)
    {
        ptrArr = new (nothrow) int[n];

        if (ptrArr != nullptr)
        {
            myMulty(ptrArr, n, number);
            myOutput(ptrArr, n);

            delete[] ptrArr;
            ptrArr = nullptr;
        }
    }
}

//Задание 2: Динамически выделить матрицу 4х4 типа int. 
//Инициализировать ее псевдослучайными числами через функцию rand. 
//Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.

int randArrInit(int arr[], size_t size) //Функция инициирует одномерный массив псевдослучайными числами                         
{
    const size_t SIZE = size;
    for (size_t i = 0; i < size; i++)
    { 
         arr[i] = rand() % 100;
    }
    return arr[size];
}


void myFunc2()
{
    int** ptrArr;
    const int n = 4;

    ptrArr = new int * [n]; //
    for (size_t i = 0; i < n; i++)
    {
        ptrArr[i] = new int[n]; 
        randArrInit(ptrArr[i], n); // заполняем i-й одномерный массив
    }
    for (size_t i = 0; i < n; i++) //работа с двумерным массивом
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << ptrArr[i][j] << " ";
        }
        cout << endl;
    }
    for (size_t i = 0; i < n; i++) 
    {
        delete[] ptrArr[i]; // Освобождаем одномерные массивы
    }
    delete[] ptrArr; // Удаляем массив указателей
    ptrArr = nullptr;
}

//Задание 3: Написать программу, которая создаст два текстовых файла (*.txt),
// примерно по 50-100 символов в каждом (особого значения не имеет с 
// каким именно содержимым). Имена файлов запросить у польлзователя.
 

void fileCreator(string myName)
{
    string fileName = myName + ".txt"; //создаем имя файла с расширением
    ofstream fout(fileName);           //создаем сам файл
    
    const size_t N = 50;
    int * ptrArr = new int[N];
    randArrInit(ptrArr, N); //Инициируем массив из N эвементов рандомными элементами
    for (size_t i = 0; i < N; i++)
    {
        fout << ptrArr[i] << " "; //отправляем содержимое массива в файл
        if ((i+1) % 10 == 0)
        { 
            fout <<  endl;  //после каждой 10 записи переходим на другую строку
        }
    }
    fout.close();          //закрываем файл
    delete[] ptrArr;
    ptrArr = nullptr;      //удаляем массив
}

void myFunc3()
{
    string name1, name2;
    cout << "Введите название первого файла:";
    cin >> name1;
    fileCreator(name1);
    cout <<endl << "Введите название второго файла:";
    cin >> name2;
    fileCreator(name2);
}

//Задание 4*: * Написать функцию, «склеивающую» эти файлы в третий текстовый файл
// (имя файлов спросить у пользователя).

void myRead(string fileName1, string fileName2, string fileRes)
{
    ofstream fout(fileRes);        //открываем файл для записи

    ifstream inf1(fileName1);       //открываем файл1 для чтения

    if (inf1.is_open())             //если файл открыт
    {
        ofstream fout(fileRes);
        string buf;
        while (!inf1.eof())         //пока не конец файла
           {
            getline(inf1, buf);     //читаем строку
            fout << buf << endl;     //записываем строку в итоговый файл 
            }
        inf1.close();    //закрываем файл чтения
        fout.close();   //закрываем файл записи
    }
    
    ifstream inf2(fileName2);       //открываем файл2 для чтения

    if (inf2.is_open())             //если файл открыт
    {
        ofstream fout(fileRes, ios_base::app); //запись информации в конец файла
        string buf;
        while (!inf2.eof())         //пока не конец файла
        {
            getline(inf2, buf);     //читаем строку
            fout << buf << endl;    //записываем строку в итоговый файл 
        }
        inf2.close();               //закрываем файл чтения
        fout.close();   //закрываем файл записи
    }
}


void myFunc4()
{
    string resName;
    cout << "Введите название итогового файла:";
    cin >> resName;
    string resFileName = resName + ".txt";
    myRead("11.txt","22.txt", resFileName);
}

//Задание 5*: Написать программу, которая проверяет присутствует ли 
//указанное пользователем при запуске программы слово в указанном 
//пользователем файле (для простоты работаем только с латиницей).
//Используем функцию find которая есть в строках std::string.

void myTextFileCreate()
{
    string fileName = "myFile.txt";    //задаем имя файла
    ofstream fout(fileName);           //создаем сам файл
    fout << "this is a string with a lot of words and letters." << endl << "the cat is beautiful. cats are beautiful." << endl; //записали текств файл
    fout.close();                      // Закрываем файл
}

void myFunc5()
{
    myTextFileCreate();          //создаем файл с текстом
   
    ifstream fin("myFile.txt");  //открываем файл для чтения
    if (fin.is_open())           // Если файл был успешно открыт
    {
        string buf;
        string myWord;
        bool flag = false;

        cout << "Введите СЛОВО (англ.) для поиска:";
        cin >> myWord;
        while (!fin.eof())       // Пока не конец файла
        {
            getline(fin, buf);   // Читаем из файла строку
            if (buf.find(myWord) != string::npos) // строка была найдена?
            {
                cout << "Да, в файле есть слово " << myWord << ".";
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
        if (flag = false)
        {
            cout << "Мы не нашли слово " << myWord << " в файле.";
        }
        fin.close(); // Закрываем файл
    }
}


///////////////////////////////////////////////////////////////////
int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    myFanc1(); //Вызываем функцию по 1 заданию

    myFunc2(); //Вызываем функцию по 2 заданию

    myFunc3(); //Вызываем функцию по 3 заданию

    myFunc4(); //Вызываем функцию по 4 заданию

    myFunc5(); //Вызываем функцию по 5 заданию

}

