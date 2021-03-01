#include<iostream>
using namespace std;
int n, m;

int** make()
{
	int** matr;
	int i, j;
	matr = new int* [n*m];
	for (i = 0; i < n; i++)
	{
		matr[i] = new int[m];
		for (j = 0; j < m; j++)
		{
			matr[i][j] = rand() % 100 - 50;
		}
	}
	return matr;
}

void print(int** a)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int K[100];
	int** a;
	cout << "Введите количество строк массива: ";
	cin >> n;
	cout << "Введите количество столбцов массива: ";
	cin >> m;
	a=make();
	cout << "Массив: "<<endl;
	print(a);
	int ns, ms;
	cout << "Введите номер строки для добавления: ";
	cin >> ns;
    if (ns > m + 1) cout << "Некорректное значение номера строки";
    else {
        cout << "Введите элементы строки:" << endl;
        for (int i = 0; i < m; i++) {
            cin >> K[i];
        }
        n++;
        cout << "Массив после добавления: "<<endl;
        for (int i = 0; i < n; i++)
        {
            if (i == ns - 1)
                {
                    for (int l = 0; l < m; l++)
                        {
                        cout << K[l] << " ";
                        }
                        cout << endl;
                }
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
	return 0;
}
