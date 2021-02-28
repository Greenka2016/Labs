#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int n;
string s1;
FILE * f;
struct customer
{
	string full_name;
	string home_address;
	int phone_number;
	int credit_card_number;
};
void make(int x)
{
    setlocale(LC_ALL, "Russian");
	customer * s = new customer[x];
	for (int i = 0; i < x; i++)
	{
		cout << "Surname: ";
		cin >> s[i].full_name;
		cout << endl;
		cout << "Name: ";
		cin >> s1;
		cout << endl;
		s[i].full_name.append(" ");
		s[i].full_name.append(s1);
		cout << "Patronymic: ";
		cin >> s1;
		cout << endl;
		s[i].full_name.append(" ");
		s[i].full_name.append(s1);
		cout << "Home_address: ";
		cin >> s[i].home_address;
		cout << endl;
		cout << "Phone_number: ";
		cin >> s[i].phone_number;
		cout << endl;
		cout << "Credit_card_number: ";
		cin >> s[i].credit_card_number;
		cout << endl;
	}
	if ((f = fopen("customer", "w")) == NULL)
	{
		perror("Файл не открыт");
		exit(0);
	}
	fwrite(&s, sizeof(customer), 1, f);
	fclose(f);
}

void print(int x)
{
    setlocale(LC_ALL, "Russian");
	customer * s = new customer[x];
	cout << "Элементы  структуры:" << endl;
		if ((f = fopen("customer", "r")) == NULL)
		{
			perror("Ошибка при открытии файла");
			exit(0);
		}
		fread(&s, sizeof(x), 1, f);
		fclose(f);
		for (int i = 0; i < x; i++)
		{
			cout << i << " элемент:" << endl;
			cout << "Full_name: " << s[i].full_name << " ";
			cout << "Home_address: " << s[i].home_address << "  ";
			cout << "Phone_number: " << s[i].phone_number << "  ";
			cout << "Credit_card_number: " << s[i].credit_card_number << "  ";
			cout << endl;
		}
}

void del(int x)
{
    setlocale(LC_ALL, "Russian");
	customer * s = new customer[x];
		if ((f = fopen("customer", "r")) == NULL)
		{
			perror("Ошибка при открытии файла");
			exit(0);
		}
		fread(&s, sizeof(x), 1, f);
		fclose(f);
		if (x <= 3)
		{
			cout << "Элементов меньше, либо равно 3, элементы все удалены";
			n = 0;
				return;
		}
		else if (x == 4)
		{
			n -= 3;
			x -= 3;
			s[0].full_name = s[3].full_name;
			s[0].home_address = s[3].home_address;
			s[0].phone_number = s[3].phone_number;
			s[0].credit_card_number = s[3].credit_card_number;
		}
		else if (x == 5)
		{
			n -= 3;
			x -= 3;
			s[0].full_name = s[3].full_name;
			s[0].home_address = s[3].home_address;
			s[0].phone_number = s[3].phone_number;
			s[0].credit_card_number = s[3].credit_card_number;
			s[1].full_name = s[4].full_name;
			s[1].home_address = s[4].home_address;
			s[1].phone_number = s[4].phone_number;
			s[1].credit_card_number = s[4].credit_card_number;
		}
		else
		{
			n -= 3;
			x -= 3;
			for (int i = 0; i < x; i++)
			{
				s[i].full_name = s[i + 3].full_name;
				s[i].home_address = s[i + 3].home_address;
				s[i].phone_number = s[i + 3].phone_number;
				s[i].credit_card_number = s[i + 3].credit_card_number;
			}
		}
		if ((f = fopen("customer", "w")) == NULL)
		{
			perror("Файл не открыт");
			exit(0);
		}
		fwrite(&s, sizeof(customer), 1, f);
		fclose(f);
}

void add(int x)
{
    setlocale(LC_ALL, "Russian");
	customer * s = new customer[x];
	if ((f = fopen("customer", "r")) == NULL)
	{
		perror("Ошибка при открытии файла");
		exit(0);
	}
	fread(&s, sizeof(x), 1, f);
	fclose(f);
	for (int i = x; i <= x + 2; i++)
    {
        cout << "Введите новый элемент:" << endl;
        cout << "Surname: ";
		cin >> s[i].full_name;
		cout << endl;
		cout << "Name: ";
		cin >> s1;
		cout << endl;
		s[i].full_name.append(" ");
		s[i].full_name.append(s1);
		cout << "Patronymic: ";
		cin >> s1;
		cout << endl;
		s[i].full_name.append(" ");
		s[i].full_name.append(s1);
        cout << "Home_address: ";
        cin >> s[i].home_address;
        cout << "Phone_number: ";
        cin >> s[i].phone_number;
        cout << "Credit_card_number: ";
        cin >> s[i].credit_card_number;
        cout << endl;
    }
	n+=3;
	x+=3;
	if ((f = fopen("customer", "w")) == NULL)
	{
		perror("Ошибка при открытии файла");
		exit(0);
	}
	fwrite(&s, sizeof(customer), 1, f);
	fclose(f);
}

int main()
{
    setlocale(LC_ALL, "Russian");
	cout << "Введите кол-во элементов: ";
	cin >> n;
	cout << endl;
	make(n);
	print(n);
	del(n);
	if (n == 0)
	{
		return 0;
	}
	cout << "После удаления: " << endl;
	print(n);
	add(n);
	cout << "После добавления: " << endl;
	print(n);
	return 0;
}
