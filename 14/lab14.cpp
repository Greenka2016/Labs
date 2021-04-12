#include <iostream>
#include <string>
using namespace std;
struct info
{
    string fio;
	string phone;
	string address;
};

bool knut_morris_pratt(string s, string t)
{
	int i, j, k;
	bool res = 0;
	int d = s.size();
	int e = t.size();
	if (d == 0)
		cout << "Cтрока неверно задана\n";
	else if (e == 0)
		cout << "Подстрока неверно задана\n";
	else
	{
		j = 0;
		k = -1;
	}
	int* pf = new int[1000];
	pf[0] = -1;
	while (j < e - 1) {
		while (k >= 0 && t[j] != t[k])
			k = pf[k];
		j++;
		k++;
		if (t[j] == t[k])
			pf[j] = pf[k];
		else
			pf[j] = k;
	}
	i = 0;
	j = 0;
	while (j < e && i < d) {
		while (j >= 0 && s[i] != t[j])
			j = pf[j];
		i++;
		j++;
	}
	delete[] pf;
	if (j == e)
		res = 1;
	return res;
}
bool boyer_moor(string s, string t) {
	int d = s.size();
	int e = t.size();
	if (d == 0)
		cout << "Cтрока неверно задана\n";
	else if (e == 0)
		cout << "Подстрока неверно задана\n";
	else
	int  i, Pos;
	int  bmt[256];
	for (int i = 0; i < 256; i++)
		bmt[i] = e;
	for (int i = e - 1; i >= 0; i--)
		if (bmt[(short)(t[i])] == e)
				bmt[(short)(t[i])] = e - i - 1;
	int pos = e - 1;
	while (pos < d)
		if (t[e - 1] != s[pos])
			pos += bmt[(short)(s[pos])];
		else
			for (int i = e - 2; i >= 0; i--) {
				if (t[i] != s[pos - e + i + 1]) {
					pos += bmt[(short)(s[pos - e + i + 1])] - 1;
					break;
				}
				else
					if (i == 0)
					{
						return true;
					}
			}
	return false;
}
void boyer(info* st, string key, int n)
{
	bool l;
	bool p = 0;
	for (int i = 0; i < n; i++)
	{
		l = boyer_moor(st[i].fio, key);
		if (l != 0)
		{
			cout << "Элемент найден под номером: " << i << endl;
			cout << "ФИО: " << st[i].fio << endl;
			cout << "Номер телефона: " << st[i].phone << endl;
			cout << "Адрес: " << st[i].address << endl;
			p = 1;
		}
	}
	if (p == 0)
	{
		cout << "Такого элемента не найдено" << endl;
	}
}
void knut(info* st, string key, int n)
{
	bool l;
	bool p = 0;
	for (int i = 0; i < n; i++)
	{
		l = knut_morris_pratt(st[i].fio, key);
		if (l != 0)
		{
			cout << "Элемент найден под номером: " << i << endl;
			cout << "ФИО: " << st[i].fio << endl;
			cout << "Дата рождения: " << st[i].phone << endl;
			cout << "Номер телефона: " << st[i].address << endl;
			p = 1;
		}
	}
	if (p == 0)
	{
		cout << "Такого элемента не найдено" << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	string key;
	cout << "Кол-во элементов: ";
	cin >> n;
	cin.ignore();
	cout << "Ключ для поиска: ";
	getline(cin, key);
	info* st = new info[n];
	for (int i = 0; i < n; i++)
	{
		cout << "ФИО: ";
		getline(cin, st[i].fio);
		cout << "Дата рождения: ";
		getline(cin, st[i].phone);
		cout << "Номер телефона: ";
		getline(cin, st[i].address);

	}
	bool a;
	cout << "Введите 0, если хотите произвести поиск алгоритмом Бойера-Мура.\nВведите 1, если хотите произвести поиск алгоритмом Кнута-Морриса-Пратта." << endl;
	cin >> a;
	switch (a)
	{
	case 0: boyer(st, key, n); break;
	case 1: knut(st, key, n); break;
	default: cout << "Неизвестная операция. Поиск не выполнен." << endl;
	}
	return 0;
}
