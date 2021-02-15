#include <iostream>
#include <stdio.h>
using namespace std;

FILE* f;
int n;

struct customer
{
	string name;
	string home_address;
	int phone_number;
	int credit_card_number;
};

void form(int x)
{
	customer* pt = new customer[x];
	for (int i = 0; i < x; i++)
	{
		cout << "Name: ";
		cin >> pt[i].name;
		cout << endl;
		cout << "Home address: ";
		cin >> pt[i].home_address;
		cout << endl;
		cout << "Phone number: ";
		cin >> pt[i].phone_number;
		cout << endl;
		cout << "Credit card number: ";
		cin >> pt[i].credit_card_number;
		cout << endl;
	}
	if ((f = fopen("customer", "w")) == NULL)
	{
		perror("Файл не открыт");
		exit(0);
	}
	fwrite(&pt, sizeof(customer), 1, f);
	fclose(f);
}

void print(int x)
{
	customer* pt = new customer[x];
	cout << "Элементы  структуры:" << endl;
		if ((f = fopen("customer", "r")) == NULL)
		{
			perror("Ошибка открытия файла");
			exit(0);
		}
		fread(&pt, sizeof(x), 1, f);
		fclose(f);
		for (int i = 0; i < x; i++)
		{
			cout << i << " элемент:" << endl;
			cout << "Name: " << pt[i].name << " ";
			cout << "Home address: " << pt[i].home_address << "  ";
			cout << "Phone number: " << pt[i].phone_number << "  ";
			cout << "Credit card number: " << pt[i].credit_card_number << "  ";
			cout << endl;
		}
}

void del(int x)
{
	customer* pt = new customer[x];
		if ((f = fopen("customer", "r")) == NULL)
		{
			perror("Ошибка открытия файла");
			exit(0);
		}
		fread(&pt, sizeof(x), 1, f);
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
			pt[0].name = pt[3].name;
			pt[0].home_address = pt[3].home_address;
			pt[0].phone_number = pt[3].phone_number;
			pt[0].credit_card_number = pt[3].credit_card_number;
		}
		else if (x == 5)
		{
			n -= 3;
			x -= 3;
			pt[0].name = pt[3].name;
			pt[0].home_address = pt[3].home_address;
			pt[0].phone_number = pt[3].phone_number;
			pt[0].credit_card_number = pt[3].credit_card_number;
			pt[1].name = pt[4].name;
			pt[1].home_address = pt[4].home_address;
			pt[1].phone_number = pt[4].phone_number;
			pt[1].credit_card_number = pt[4].credit_card_number;
		}
		else
		{
			n -= 3;
			x -= 3;
			for (int i = 0; i < x; i++)
			{
				pt[i].name = pt[i + 3].name;
				pt[i].home_address = pt[i + 3].home_address;
				pt[i].phone_number = pt[i + 3].phone_number;
				pt[i].credit_card_number = pt[i + 3].credit_card_number;
			}
		}
		if ((f = fopen("customer", "w")) == NULL)
		{
			perror("Файл не открыт");
			exit(0);
		}
		fwrite(&pt, sizeof(customer), 1, f);
		fclose(f);
}

void add(int x)
{
	// Функция пока не написана
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите кол-во элементов: ";
	cin >> n;
	cout << endl;
	form(n);
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
