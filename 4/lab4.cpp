#include <iostream>
using namespace std;

int main()
{

	int a[100];
	int n;
	cout << "Длина массива: ";
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		a[i] = rand() % 10;
	}
	cout << endl;
	cout << "Массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << "Удаление элементов с заданным значением:" << endl;
	cout << "Введите значение: ";
	int t;
	int k =0;
	cin >> t;
	for (int i = 0; i < n ; i++)
    if (a[i] == t)
    {
        k++;
    }
    for (int i = 0; i < k; i++)
    {
    n--;
	for (int i = 0; i < n; i++)
	{
    if (a[i] == t)
        {
        int change = a[i];
        a[i] = a[i+1];
        a[i + 1] = change;
        }
	}
    }

	int temp;
	int elem;
    for (int i = 0; i < n; i++)
	{
    if (a[i] % 2 == 0)
    {
    elem = 0;
    n++;
	for (int j = i; j < n; j++)
	{
	    temp = a[j];
	    a[j] = elem;
	    elem = temp;
	}
    i++;
    }
	}

	cout << endl;
    for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

    return 0;
}
