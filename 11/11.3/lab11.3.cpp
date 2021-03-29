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
	cout << "������� ������ �������: ";
	cin >> x;
	p->data = x;
	p->prev = NULL;
	top = p;
	for (int i = 2; i <= n; i++)
	{
		Stack* h = new Stack;
		cout << "������� " << i << " �������: ";
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
		cout << "���� - ������" << endl;
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
	cout << "������� ����������� �������: ";
	cin >> l->data;
	l->prev = p;
	first = l;
	while (p->prev != NULL) {
		Stack* h = new Stack;
		cout << "������� ����������� �������: ";
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
	cout << "������� ���������� ��������� � �����: ";
	int n;
	cin >> n;
	cout << "������� �������� �����: " << endl;
	Stack* s = make_stack(n);
	cout << "����: ";
	print(s);
	add(s, n);
	cout << "���� ����� ����������: ";
	print(s);
	return 0;
}