#include <iostream>
using namespace std;

int min(int n, ...)
{
    int *ptr = &n;
	int result = *(++ptr);
	for(int *ptr = &n; n > 0; n--)
	{
	    if(*(++ptr) < result) result = *(++ptr);
	}
	return result;
}

int main(void)
{
    setlocale(LC_ALL, "RUS");
    cout  << "����������� ��������: ";
	cout << endl << "�� 5-�� ����������: " << endl << min(5, 2, 1, -1, 4, 7);
	cout << endl << "�� 10-�� ����������: "<< endl << min(10, 2, 2, 3, 4, 5, 2, 3, -4, -7, -1);
    cout << endl << "�� 12-�� ����������: "<< endl << min(12, -4, 51, -2, 3, 4, 7, 3, 12, 21, 13, -4, 5);
	return 0;
}
