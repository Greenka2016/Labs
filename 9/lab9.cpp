#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int n;
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите кол-во строк: ";
	cin >> n;
	cin.ignore();
	ofstream f1("F1.txt");
	if (!f1.is_open())
	{
		cout << "Файл не открыт" << endl;
		return 0;
	}
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		f1 << str << "\n";
	}
	f1.close();
	ifstream file("F1.txt");
	if (!file.is_open())
	{
		cout << "Файл не открыт" << endl;
		return 0;
	}
	cout << "Содержание файла F1" << endl;
	for (int i = 0; i < n; i++)
	{
		getline(file, str);
		cout << str << endl;
	}
	file.close();
	ifstream f("F1.txt");
	ofstream f2("F2.txt");
	if (!f.is_open() && !f2.is_open())
	{
		cout << "Файлы не открыт	" << endl;
		return 0;
	}
	int r = 0;
	for (int i = 0; i < n; i++)
	{
        bool flag = false;
		getline(f, str);
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
                {
                   flag = true;
                }

        }
        if (flag == false)
        {
            f2 << str << "\n";
            r++;
        }
    }

	f.close();
	f2.close();
	ifstream F2("F2.txt");
	if (!F2.is_open())
	{
		cout << "Файлы не открыт	" << endl;
		return 0;
	}
	cout << "Содержание файла F2" << endl;
    int k = 0;
	for (int i = 0; i < r; i++)
	{
		getline(F2, str);
        if (str[0] == 'A')
            {
                k++;
            }
		cout << str << endl;
	}
	F2.close();
	ifstream file2("F2.txt");
	if (!file2.is_open())
	{
		cout << "Файлы не открыт	" << endl;
		return 0;
	}
	cout << "Количество строк, которые начинаются на букву «А» в файле F2: " << k << endl;
	file2.close();
	return 0;
}

