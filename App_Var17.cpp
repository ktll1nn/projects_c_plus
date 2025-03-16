#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int k;
	int p;
	int s;
	cout << "Введите k(начальный капитал):";
	cin >> k;
	cout << "Введите p(процент):";
	cin >> p;
	cout << "Введите s(итоговую сумму):";
	cin >> s;
	int n = 0;
	int l = 0;
	if (k < s) {
		l = k * p / 100;
		k = l + k;
		n = n + 1;
	}
	else int n1;
		int n2{};
	n1 = n / 12;
	n2 = n % 12;
	cout << n1 << " год и " << n2 << " месяца(ев)";
	system("pause");
	return 0;
}