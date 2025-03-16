#include <iostream>
#include <Windows.h>

using namespace std;

int MaxDiv(int n, int m) {
    if (n == m) {
        return n;
    }
    else if (n > m) {
        return MaxDiv(n - m, m);
    }
    else {
        return MaxDiv(n, m - n);
    }
}

void main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Дисциплина:\tОсновы алгоритмизации и программирования\n"
        << "Группа:\t\tИС50-2-22\n"
        << "Студент:\tСвиридова Е.К.\n"
        << "Пр. работа:\t№12 Применение рекурсивных функций\n"
        << "Вариант:\t№17\n"
        << "--------------------------------------------------------\n\n";

    int num1, num2;
    cout << "Введите число n: ";
    cin >> num1;
    cout << "Введите число m: ";
    cin >> num2;
    int result = MaxDiv(num1, num2);
    cout << "Наибольший общий делитель: " << result << endl;

    system("pause");
}
