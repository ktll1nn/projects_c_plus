#include "cannedfood.h"

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    Conserv conserv;
    ifstream fin;
    char fileName[32];
    cout << "Ввведите имя файла: "; gets_s(fileName, size(fileName));

    do {
        system("cls");

        cout << "Дисциплина:\tОсновы алгоритмизации и программирования\n"
            << "Группа:\t\tИС50-2-22\n"
            << "Студент:\tСвиридова Е.К.\n"
            << "Пр. работа:\t№13 Программирование модуля. Создание библиотеки подпрограмм\n"
            << "Вариант:\t№17\n"
            << "--------------------------------------------------------\n\n";

        cout << "1. Запись данных в файл\n";
        cout << "2. Чтение данных из файла\n";
        cout << "3. Расчет суммарной стоимости\n";
        cout << "4. Вывод в файл в виде таблицы\n";
        cout << "5. Экспорт в формате .CSV\n";
        cout << "6. Выход\n";
        cout << "-------------> ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        switch (choice) {
        case 1: {
            conserv = input_data();
            ofstream fout;
            fout.open("cannedfood.dat", ios::app | ios::binary);
            fout.write((char*)&conserv, sizeof(Conserv));
            fout.close();
            system("pause");
            break;
        }

        case 2: {
            fin.open(fileName, ios::in | ios::binary);
            if (fin)
            {
                while (!fin.read((char*)&conserv, sizeof(Conserv)).eof())
                {
                    output_data(conserv);
                }
                fin.close();
            }
            system("pause");
            break;
        }


        case 3: {
            double maxCost;
            cout << "Введите предельную стоимость: ";
            cin >> maxCost;
            double totalCost = ttt(maxCost);
            cout << "Суммарная стоимость консервов с подходящим сроком годности и стоимостью: " << totalCost << endl;
            system("pause");
            break;
        }

        case 4: {
            cout << "Открыть файл? (1-да/0-нет): ";
            int openFile;
            cin >> openFile;

            if (openFile == 1)
            {
                table_conserv(txt_file, fileName);
                system(txt_file);
                system("pause");
                break;
            }
            else
                break;
        }

        case 5: {
            cout << "Открыть файл?(1-да/0-нет)";
            int openFile;
            cin >> openFile;
            if (openFile == 1)
            {
                export_data(csv_file, fileName);
                system(csv_file);
                system("pause");
                break;
            }
            else
                break;
        }

        case 6: {
            cout << "Выход выполнен успешно" << endl;
            system("pause");
            break;
        }

        default:
            cout << "Неправильный выбор пункта меню." << endl;
            system("pause");
            break;
   
        }
    }
    while (choice != 6);
    return 0;
    
}
