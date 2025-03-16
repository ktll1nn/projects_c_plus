#include <fstream>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <sstream>
using namespace std;

int main()
{
    setlocale(0, "RUS");


    cout << "Дисциплина:\tОсновы алгоритмизации и программирования\n"
        << "Группа:\t\tИС50-2-22\n"
        << "Студент:\tСвиридова Е.К.\n"
        << "Пр. работа:\t№9 Файлы последовательного доступа\n"
        << "Вариант:\t№17\n"
        << "--------------------------------------------------------\n\n";

    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);


        ifstream inputFile("input.txt");
        ofstream outputFile("output.txt");

        {
            float x1, y1;
            char buff[100];
            string line;

            while (getline(inputFile, line))
            {
                istringstream iss(line);
                if (!(iss >> x1 >> y1))
                {
                    cout << "Ошибка чтения данных из файла" << endl;
                    return 1;
                }

                double y = -y1;

                if ((x1 >= -5.0) && (x1 <= -3.0))
                    y = 1.0;
                else if (((x1 + 1) * (x1 + 1)) + (y1 * y1) == 4.0)
                    y = -(sqrt(4.0 - ((x1 + 1) * (x1 + 1))));
                else if ((x1 >= -1.0) && (x1 <= 2.0))
                    y = -2.0;
                else if ((x1 >= 2.0) && (x1 <= 5.0))
                    y = x1 - 4.0;

                y = round(y * 1000) / 1000;
                y1 = round(y1 * 1000) / 1000;

                if (y == y1)
                    outputFile << "Точка A (" << x1 << ";" << y1 << ") принадлежит графику функции " << endl;
                else
                    outputFile << "Точка A (" << x1 << ";" << y1 << ") не принадлежит графику функции " << endl;
            }

            inputFile.close();
            outputFile.close();
        }
    }
    system("pause");
    return 0;
}
