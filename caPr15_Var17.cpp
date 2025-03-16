#include <iostream> 
#include <fstream>
#include <set>
#include <Windows.h>
#include "cannedfood.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    tConserv* Conserv = new tConserv;
    tConservNode* ConservRoot = new tConservNode;
    tConservList* conservList1 = new tConservList;

    char choice = 0;
    ofstream fout;
    ifstream fin;
    do {
        system("cls");
        cout << "Дисциплина:\tОсновы алгоритмизации и программирования\n"
            << "Группа:\t\tИС50-2-22\n"
            << "Студент:\tСвиридова Е.К.\n"
            << "Пр. работа:\t№15 Классы ООП.Использование классов.\n"
            << "Вариант:\t№17\n"
            << "--------------------------------------------------------\n\n";

        cout << "1. Запись данных в файл\n";
        cout << "2. Чтение данных из файла\n";
        cout << "3. Расчет суммарной стоимости\n";
        cout << "4. Вывод в файл таблицы" << endl;
        cout << "5. Экспорт в формате .CSV" << endl;
        cout << "----------------------------------------" << endl;
        cout << "6. Сформировать список (из файла)" << endl;
        cout << "7. Показать список" << endl;
        cout << "8. Очистить список" << endl;
        cout << "----------------------------------------" << endl;
        cout << "9. Выход" << endl;
        cout << "-------------> ";
        cin >> choice; cin.ignore();
        cout << endl;

        switch (choice) {
        case '1':

            conservList1->input_data();
            fout.open("cannedfood.dat", ios::app | ios::binary);
            fout.write(reinterpret_cast<char*>(Conserv), sizeof(tConserv));
            fout.close();
            break;
            system("pause");
            break;
        case '2':
            conservList1->output_all();
            system("pause");
            break;
        case '3': {
            double maxCost;
            cout << "Введите предельную стоимость: ";
            cin >> maxCost;
            conservList1->ttt(maxCost);

            system("pause");
            break;
        }
        case '4':
            conservList1->table_conserv();
            system("pause");
            break;
        case '5':
            conservList1->export_data();
            system("pause");
            break;
        case '6':
            conservList1->ConservList_Create();
            system("pause");
            break;
        case '7':
            conservList1->ConservList_Show();
            system("pause");
            break;
        case '8':
            conservList1->ConservList_Clear();
            system("pause");
            break;
        }
    } while (choice != '9');

    conservList1->ConservList_Clear();
    conservList1->done();
    delete conservList1;
    return 0;
}