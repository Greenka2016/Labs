#include <iostream>
using namespace std;

void sort(int *a, int n, int t = 0){
    if (t != n){
        for (int i = n - 1; i > t; i--)
        if (a[i] < a[i - 1]){
            int tmp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = tmp;
        }
        sort(a, n, t++);
    }
}

int main()
{
    int a[100];
    int n;
    cout << "Vvedite dlinu massiva" << endl;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Vvedite element massiva" << endl;
        cin >> a[i];
    }
    sort(a, n);
    for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
    return 0;
}
