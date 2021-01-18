#include <iostream>
using namespace std;


int main()
{
    int a[100];
    int n;
    cout << "Vvedite dliny massiva: " << endl;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        a[i] = rand() % 10;
    }
    cout << endl;
    cout << "Nachalniy massiv: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl << endl;

    cout << "Udalyaem elementy s nechetnimy indexami: ";
    if (n % 2 != 0)
    {
    for (int i = 1; i <= n / 2; i++)
    {
    a[i] = a[i * 2];
    }
    n = (n / 2);
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
    cout << a[i] << ' ';
    }
    cout << endl << endl;
    n++;
    }
    else
    {
    for (int i = 1; i < n / 2; i++)
    {
    a[i] = a[i * 2];
    }
    n /= 2;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
    cout << a[i] << ' ';
    }
    cout << endl << endl;
    }

    cout << endl << "Index elementa dlya dobavlenia: " << endl;
	int k, elem;
	cin >> k;
	cout << endl;
	cout << "Element: " << endl;
	cin >> elem;
	cout << endl;
	n++;
	for (int i = k; i <= n; i++)
	{
		int tmp = a[i];
		a[i] = elem;
		elem = tmp;
	}
	cout << "Massiv posle dobavlenya elementa: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	cout << "Perestanovka - perevernyt massiv: " << endl;
	int t;
	for (int i = 0; i < n / 2; i++)
	{
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
	cout << "Perevernytyi massiv: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;

	cout << "Poisk elementa, ravnyi srednemu arifmeticheskomu elementov massiva: " << endl;
	int sr = 0, nsr = -1, nsravn = 0;
	for (int i = 0; i < n; i++)
	{
		sr += a[i];
	}
	sr /= n;
	for (int i = 0; i < n; i++)
	{
		nsravn++;
		if (a[i] == sr)
		{
			nsr = i;
			break;
		}
	}
	cout << endl;
	if (nsr == -1)
	{
		cout << "Element, ravnyi srednemu arifmeticheskomu elementov massiva: " << endl;
	}
	else
	{
		cout << "Naidennyi element: " << sr << endl;
		cout << "Index naidennogo elementa: " << nsr << endl;
		cout << "Kolichestvo sravneniy: " << nsravn << endl;
	}
	cout << endl;

	cout << "Sortiruem massiv prostim vuborom: " << endl;
	int srav = 0;
	for (int i = 0; i < n; i++)
    {
    int k = i;
    int x = a[i];
    for (int j = i + 1; j < n; j++)
    {
    if (a[j] < x)
    {
    srav++;
    k = j;
    x = a[k];
    }
    }
    a[k] = a[i];
    a[i] = x;
    }
    for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;
	cout << "Kolichestvo sravneniy dlya sortirovki: " << srav;
    return 0;
}
