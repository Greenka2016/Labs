#include <iostream>
using namespace std;

struct Queue {
	int data;
	Queue* next;
};

Queue* make_Queue(int n, Queue*& first, Queue*& last)
{
	if (n == 0) return NULL;
	Queue* p = new Queue;
	int a;
	cout << "Введите элемент очереди: ";
	cin >> a;
	p->data = a;
	p->next = NULL;
	first = p;
	last = p;
	for (int i = 2; i <= n; i++)
	{
		Queue* h = new Queue;
		cout << "Введите элемент очереди: ";
		cin >> a;
		h->data = a;
		h->next = p;
		last = h;
		p = last;
	}
	return first;
}

Queue* push(int n, Queue*& last)
{
	Queue* p = new Queue;
	p->data = n;
	p->next = last;
	last = p;
	return last;
}

void print_Queue(Queue* last)
{
	Queue* p = last;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}




int pop(Queue*& first, Queue*& last)
{
	Queue* p = last;
	int k = 0;
	while (p != NULL)
	{
		k++;
		p = p->next;
	}
	p = last;
	if (k == 1)
	{
		int t = last->data;
		delete p;
		last = NULL;
		first = NULL;
		return t;
	}
	else {
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		Queue* t = p;
		int e = p->next->data;
		p = p->next;
		t->next = NULL;
		first = t;
		delete p;
		return e;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество элементов в очереди: ";
	int n;
	cin >> n;
	int k;
	Queue* first, * last;
	make_Queue(n, first, last);
	print_Queue(last);
	int* mas = new int[n];

	for (int i = 0; i < n; i++)
	{
		int t = pop(first, last);
		mas[i] = t;
		if (t % 2 == 0)
		{
			k = t;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (mas[i] != k)
		{
			push(mas[i], last);
		}
	}

	cout << "Очередь после удаления: ";
	print_Queue(last);
	return 0;
}