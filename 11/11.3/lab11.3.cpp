#include <iostream>
using namespace std;

char x;

struct Stack {
	char data;
	Stack* prev;
};

Stack* make_stack(int n)
{
	if (n == 0)
	{
		return NULL;
	}
	Stack* top, * p;
	top = NULL;
	p = new Stack;
	cout << "Введите первый элемент: ";
	cin >> x;
	p->data = x;
	p->prev = NULL;
	top = p;
	for (int i = 2; i <= n; i++)
	{
		Stack* h = new Stack;
		cout << "Введите " << i << " элемент: ";
		cin >> x;
		h->data = x;
		h->prev = top;
		top = h;
	}
	return top;
}

void print(Stack* top)
{
	if (top == NULL)
	{
		cout << "Стек - пустой" << endl;
	}
	else {
		Stack* p = top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
}

void add(Stack*& first, int n)
{
	Stack* p = first;
	Stack* l = new Stack;
	cout << "Введите добавляемый элемент: ";
	cin >> l->data;
	l->prev = p;
	first = l;
	while (p->prev != NULL) {
		Stack* h = new Stack;
		cout << "Введите добавляемый элемент: ";
		cin >> h->data;
		h->prev = p->prev;
		p->prev = h;
		if (p->prev->prev != NULL)
		{
			p = p->prev->prev;
		}
		else {
			p = p->prev;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество элементов в стеке: ";
	int n;
	cin >> n;
	cout << "Введите элементы стека: " << endl;
	Stack* s = make_stack(n);
	cout << "Стек: ";
	print(s);
	add(s, n);
	cout << "Стек после добавления: ";
	print(s);
	return 0;
}
