#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct tConserv {
    char packaging[50];
    char productionDate[11];
    char factoryName[50];
    char content[50];
    double weight;
    double cost;
    int shelfLife;
};

tConserv input_data() {
    tConserv b;
    cout << "Введите тип упаковки: ";
    cin.getline(b.packaging, 50);

    cout << "Введите дату выпуска (формат: ГГГГ-ММ-ДД): ";
    cin.getline(b.productionDate, 11);

    cout << "Введите название завода: ";
    cin.getline(b.factoryName, 50);

    cout << "Введите содержимое консервов: ";
    cin.getline(b.content, 50);

    cout << "Введите вес: ";
    cin >> b.weight;
    cin.ignore();

    cout << "Введите стоимость: ";
    cin >> b.cost;
    cin.ignore();

    cout << "Введите срок хранения: ";
    cin >> b.shelfLife;
    cin.ignore();

    return b;
}

void output_data(tConserv b) {
    cout << "Тип упаковки: " << b.packaging << endl;
    cout << "Дата выпуска: " << b.productionDate << endl;
    cout << "Название завода: " << b.factoryName << endl;
    cout << "Содержимое консервов: " << b.content << endl;
    cout << "Вес: " << b.weight << endl;
    cout << "Стоимость: " << b.cost << endl;
    cout << "Срок хранения: " << b.shelfLife << endl;
    cout << "-----------------------------------------------------------------\n";
}

// Запись данных в файл
void writeDataToFile(const tConserv& conserv) {
    ofstream fout("conserv.txt", ios::app);
    if (fout.is_open()) {
        fout << conserv.packaging << endl;
        fout << conserv.productionDate << endl;
        fout << conserv.factoryName << endl;
        fout << conserv.content << endl;
        fout << conserv.weight << endl;
        fout << conserv.cost << endl;
        fout << conserv.shelfLife << endl;
        fout.close();
        cout << "Данные сохранены в файле." << endl;
    }
    else {
        cerr << "Не удалось открыть файл для записи." << endl;
    }
}

// Чтение данных из файла
void readDataFromFile() {
    ifstream fin("conserv.txt");
    if (fin.is_open()) {
        tConserv conserv;
        while (fin.getline(conserv.packaging, 50)) {
            fin.getline(conserv.productionDate, 11);
            fin.getline(conserv.factoryName, 50);
            fin.getline(conserv.content, 50);
            fin >> conserv.weight >> conserv.cost >> conserv.shelfLife;
            fin.ignore();
            output_data(conserv);
        }
        fin.close();
    }
    else {
        cout << "Файл с данными \"conserv.txt\" не может быть открыт...\n";
    }
}
double ttt(double maxCost) {
    double sum_cost = 0;
   
    ifstream fin("conserv.txt");
    if (fin.is_open()) {
        tConserv conserv;
        while (fin >> conserv.packaging >> conserv.productionDate >> conserv.factoryName >> conserv.content >> conserv.weight >> conserv.cost >> conserv.shelfLife) {
            if (conserv.shelfLife >= 24 && conserv.cost <= maxCost) {
                sum_cost += conserv.cost;
            }
        }
        fin.close();
        return sum_cost;
    }
}


int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    do {
        system("cls");

        cout << "Дисциплина:\tОсновы алгоритмизации и программирования\n"
            << "Группа:\t\tИС50-2-22\n"
            << "Студент:\tСвиридова Е.К.\n"
            << "Пр. работа:\t№11 Организация процедур. Организация функций\n"
            << "Вариант:\t№17\n"
            << "--------------------------------------------------------\n\n";

        cout << "1. Запись данных в файл\n";
        cout << "2. Чтение данных из файла\n";
        cout << "3. Расчет суммарной стоимости\n";
        cout << "4. Выход\n";
        cout << "-------------> ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        tConserv conserv1;
        ofstream fout;
        ifstream fin;
        switch (choice) {
        case 1: {
            conserv1 = input_data();
            writeDataToFile(conserv1);
            break;
        }
        case 2: {
            readDataFromFile();
            break;
        }
        case 3: {
            {
                double maxCost;
                cout << "Введите предельную стоимость: ";
                cin >> maxCost;
                double totalCost = ttt(maxCost);
                cout << "Суммарная стоимость консервов с подходящим сроком годности и стоимостью: " << totalCost << endl;
                break;
            }

        }

        case 4: {
            cout << "Выход выполнен успешно" << endl;
            break;
        }

        default:
            cout << "Неправильный выбор пункта меню." << endl;
            system("pause");
            break;
        }

        system("pause");

    } while (choice != 4);

    return 0;
}
