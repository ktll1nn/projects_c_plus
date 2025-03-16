#include <iostream> 
#include <set> 
#include <vector> 
#include <ctime> 
#include <cstdlib> 
#include <algorithm> 

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    char msg_fio[] = "Свиридова.Е.К";
    char grp_num[] = "ИС50-2-22";
    int var_num = 17;

    cout << "Дисциплина:\tОсновы алгоритмизации и программирования\n"
        << "Группа:\t\t" << grp_num << "\n"
        << "Студент:\t" << msg_fio << "\n"
        << "Пр. работа:\t№8 Работа с данными типа множество\n"
        << "Вариант:\t№" << var_num << "\n"
        << "--------------------------------------------------------\n";

    srand(static_cast<unsigned int>(time(0)));
    // Инициализация генератора случайных чисел 

    // общее (базовое) множество "Книги"  
    set<string> books{ "Книга1", "Книга2", "Книга3", "Книга4", "Книга5",
    "Книга6", "Книга7", "Книга8", "Книга9",
    "Книга10", "Книга11", "Книга12", "Книга13",
    "Книга14", "Книга15", "Книга16" };

    // Дочерние множества "Читатели" 
    set<string> a;
    set<string> x;
    set<string> z;

    set <string>::iterator it1;


    // Вывод содержимого «базового» множества "транспортные средства"
    cout << "Все книги:\n";
    for (it1 = books.begin(); it1 != books.end(); it1++)
        cout << *it1 << ((*it1 != *books.rbegin()) ? ", " : "");
    cout << "\n========================================================================\n";


    // Преобразуем базовое множество в вектор для доступа к элементам по индексу 
    vector<string> books_vector(books.begin(), books.end());

    // Заполняем дочерние множества случайными элементами из базового множества 
    for (size_t i = 0; i < books.size() / 3; i++) {
        a.insert(books_vector[rand() % books_vector.size()]);
        x.insert(books_vector[rand() % books_vector.size()]);
        z.insert(books_vector[rand() % books_vector.size()]);
    }


    // Выводим содержимое дочерних множеств 
    cout << "Все читатели:\n";
    for (const auto& books : a) {
        cout << books << "\n";
    }
    cout << "-------------------------\n";


    // Найдем книги, которые брали все читатели 
    set<string> all_readers_books;
    for (const auto& book : books) {
        if (a.count(book) && x.count(book) && z.count(book)) {
            all_readers_books.insert(book);
        }
    }

    // Найдем читателя(-ей), которые брали максимальное количество книг 
    set<string> max_readers;
    int max_books = std::max({ a.size(), x.size(), z.size() });
    if (a.size() == max_books) max_readers.insert("Читатель1");
    if (x.size() == max_books) max_readers.insert("Читатель2");
    if (z.size() == max_books) max_readers.insert("Читатель3");

    // Найдем книги, которые никто не брал 
    set<string> no_readers_books;
    for (const auto& book : books) {
        if (!a.count(book) && !x.count(book) && !z.count(book)) {
            no_readers_books.insert(book);
        }
    }

    // Выведем результаты 
    cout << "Книги, которые брали все читатели:\n";
    for (const auto& book : all_readers_books) {
        cout << book << "\n";
    }
    cout << "-------------------------\n";

    cout << "Читатели, которые брали максимальное количество книг:\n";
    for (const auto& reader : max_readers) {
        cout << reader << "\n";
    }
    cout << "-------------------------\n";

    cout << "Книги, которые никто не брал:\n";
    for (const auto& book : no_readers_books) {
        cout << book << "\n";
    }
    cout << "-------------------------\n";

    return 0;
}