#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	// В строке 08 заменить значение на ФИО студента
	char msg_fio[] = "Свиридова Екатерина Константиновна";
	char msg_var[] = "Вариант № ";
	int var_num;

	// В строке 13 заменить значение на номер варианта
	var_num = 17;

	cout << msg_fio << endl;
	cout << msg_var;

	// На строке 23 поставить контрольную точку,
	// отобразить в «окне переменных» (рис.8) значения
	// переменных msg_fio, msg_var, msg_var, сделать снимок
	// экрана с «окном переменных» и текстом программы таким
	// образом, чтобы было видно признак контрольной точки
	cout << var_num << endl;

	system("pause");
	return 0;
}
