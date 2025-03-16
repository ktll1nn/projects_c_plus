#include <iostream> 
#include <fstream> 
#include <windows.h> 
using namespace std;

struct CannedGoods {
    char packaging[50];
    char productionDate[11];
    char factoryName[50];
    char content[50];
    double weight;
    double cost;
    int shelfLife;
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice = 0;
    CannedGoods buffer;

    do {
        system("cls");
        cout << "Дисциплина:\tОсновы алгоритмизации и программирования\n"
            << "Группа:\t\tИС50-2-22\n"
            << "Студент:\tСвиридова Е.К.\n"
            << "Пр. работа:\t№10 Типизированные и нетипизированные файлы\n"
            << "Вариант:\t№17\n"
            << "--------------------------------------------------------\n\n";

        cout << "1. Запись данных в файл\n";
        cout << "2. Чтение данных из файла\n";
        cout << "3. Выход\n";
        cout << "-------------> ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        switch (choice) {
        case 1: // Запись данных в файл 
        {
            ofstream file("canned_goods.bin", ios::app | ios::binary);
            if (!file.is_open()) {
                cout << "Ошибка открытия файла." << endl;
                return 1;
            }

            cout << "Введите тип упаковки: ";
            cin.ignore(); // добавляем игнор, чтобы очистить консольный ввод от предыдущего символа новой строки 
            cin.getline(buffer.packaging, 20);
            cout << "Введите дату выпуска: ";
            cin.getline(buffer.productionDate, 11);
            cout << "Введите название завода: ";
            cin.getline(buffer.factoryName, 50);
            cout << "Введите содержимое консервов: ";
            cin.getline(buffer.content, 50);
            cout << "Введите вес: ";
            cin >> buffer.weight;
            cout << "Введите стоимость: ";
            cin >> buffer.cost;
            cout << "Введите срок хранения: ";
            cin >> buffer.shelfLife;
            cin.ignore(); // Очищаем буфер после считывания числовых значений 

            file.write(reinterpret_cast<char*>(&buffer), sizeof(CannedGoods));

            file.close();
            system("pause");
            break;
        }
        case 2: // Чтение данных из файла 
        {
            ifstream file("canned_goods.bin", ios::binary);
            if (!file.is_open()) {
                cout << "Ошибка открытия файла." << endl;
                return 1;
            }

            int recordNumber = 1;
            while (file.read(reinterpret_cast<char*>(&buffer), sizeof(CannedGoods))) {
                // Вывод данных на экран с разделительной строкой 
                cout << "Запись " << recordNumber << ":" << endl;
                cout << "Тип упаковки: " << buffer.packaging << endl;
                cout << "Дата выпуска: " << buffer.productionDate << endl;
                cout << "Название завода: " << buffer.factoryName << endl;
                cout << "Cодержимое консервов: " << buffer.content << endl;
                cout << "Вес: " << buffer.weight << endl;
                cout << "Cтоимость: " << buffer.cost << endl;
                cout << "Cрок хранения: " << buffer.shelfLife << endl;
                cout << "---------------------------" << endl; // Добавляем разделительную строку между записями 
                recordNumber++;
            }

            file.close();
            system("pause"); // Добавляем задержку 
            break;
        }
        case 3: // Выход из программы 
            return 0;
        default:
            cout << "Неправильный выбор пункта меню." << endl;
            system("pause");
            break;
        }
    } while (choice != 3);

    return 0;
}