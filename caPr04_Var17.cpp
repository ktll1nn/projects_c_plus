#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int main()
{
    setlocale(LC_ALL, "RUS");
    string msg_fio = "Свиридова Е.К.";
    string grp_num = "ИС50-2-22";
    int var_num = 17;
    cout << "Дисциплина:\tОсновы алгоритмизации и программирования\n"
        << "Группа:\t\t" << grp_num << "\n"
        << "Студент:\t" << msg_fio << "\n"
        << "Пр. работа:\t№4 Составление программ разветвляющейся структуры\n"
        << "Вариант:\t№" << var_num << "\n"
        << "--------------------------------------------------------\n\n";

    float x1, y1;

    cout << "Введите координаты точки А(x1;y1):\n";
    cout << "X1= ";
    cin >> x1;


    cout << "Y1= ";
    cin >> y1;

    double y = -y1;

    if ((x1 >= -5.0) && (x1 <= -3.0))
        (y = 1.0);

    else if (((x1 + 1) * (x1 + 1)) + (y1 * y1) == 4.0)
        (y = -(sqrt(4.0 - ((x1 + 1) * (x1 + 1)))));

    else if ((x1 >= -1.0) && (x1 <= 2.0))
        (y = -2.0);

    else if ((x1 >= 2.0) && (x1 <= 5.0))
        (y = x1 - 4.0);

    y = round(y * 1000) / 1000;

    y1 = round(y1 * 1000) / 1000;

    if (y == y1)
    {
        cout << "Точка A (" << x1 << ";" << y1 << ") принадлежит графику функции " << endl;
    }
    else {
        cout << "Точка A (" << x1 << ";" << y1 << ") не принадлежит графику функции " << endl;
    }


    system("pause");
    return 0;
}

