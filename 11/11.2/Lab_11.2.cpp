#include <iostream>
#include <string>

using namespace std;

struct List
{
	int data;
	List* next;
	List* prev;
};


List* make(int size)
{
	List* p = new List;
	List* first = new List;
	first = NULL;
	cout << "Введите элемент списка: ";
	cin >> p->data;
	first = p;
	p->next = NULL;
	p->prev = NULL;

	for (int i = 2; i <= size; i++)
	{
		List* r = new List;
		List* u = p;
		p->next = r;
		p = p->next;
		cout << "Введите элемент списка: ";
		cin >> p->data;
		p->next = NULL;
		p->prev = u;

	}

	return first;
}

void del(List* first, int size)
{
	List* p = first;
	List* o = first;
	int h = 0;
	int d = 0;


	for (int i = 0; i < size; i++)
	{

		if ((first->data % 2) == 0)
		{
			d = first->data;
			first = first->next;

		}
		else
		{
			first = first->next;
		}

	}
	first = p;
	for (int i = 0; i < size; i++)
	{
		if (first->data == d)
		{
			if (first->next == NULL) {
				p = first;
				p->prev->next = first->next;
				delete p;
			}
			else
			{
				p = first;
				p->prev->next = first->next;
				p->next->prev = first->prev;
				delete p;
			}
		}
		else
		{
			first = first->next;
		}
	}
}

void print(List* first)
{
	if (first == NULL)
	{
		cout << "Список пуст";
		cout << endl;
	}
	else {
		List* p = first;
		while (p != 0)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	cout << endl;
}



int main()
{
	setlocale(LC_ALL, "RUS");
	int size = -1, n = 0;
	cout << "Введите количество элементов списка: ";
	while (size <= 0)
	{
		cin >> size;

		if (size <= 0)
			cout << "Неверные вводимые данные";
	}

	List* first = make(size);
	cout << "Ваш список: ";
	print(first);

	del(first, size);
	cout << "Список после удаления: ";
	print(first);

	delete first;
	return(0);
}
