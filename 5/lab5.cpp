#include <iostream>
using namespace std;

void make_matrix (int a[10][10], int n)
{
int i, j;
for (i = 0;  i < n; i++)
{
for(j = 0; j < n; j++)
a[i][j] = rand() % 10;
}
}

void print_matrix (int a[10][10], int n)
{
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
cout << a[i][j] << " ";
cout << endl;
}
}

void transponirovanie_matrix (int a[10][10], int b[10][10], int n)
{
int i, j, p, k;
for (i = 0, p = 0; i < n, p < n; i++, p++)
{
for(j = 0, k = 0; j < n, k < n; j++, k++)
b[p][k] = a[j][i];
}
}

void opredelenie_matrix (int a[10][10], int b[10][10], int n)
{
int i, j, p, k, t;
for (i = 0, p = 0; i < n, p < n; i++, p++)
{
for(j = 0, k = 0; j < n, k < n; j++, k++)
if (a[i][j] == b[p][k]) t++;
}
if (t == n * n) cout << "Matrix simmetrichna" << endl;
else cout << "Matrix ne simmetrichna" << endl;
}

int main ()
{
int a[10][10], b[10][10], n;
cout<<"Vvedite n: ";
cin >> n;
make_matrix(a, n);
cout << endl;
print_matrix(a, n);
cout << endl;
transponirovanie_matrix(a, b, n);
cout << endl;
print_matrix(b, n);
cout << endl;
opredelenie_matrix(a, b, n);
}
