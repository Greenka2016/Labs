#include <iostream>
using namespace std;

void peregruzka(string month)
{
    string zodiac[12] = {"Oven", "Telec", "Bliznetchi", "Rak", "Lev", "Deva", "Vesy", "Scorpion", "Strelec", "Kozerog", "Vodolei", "Ryby"};
    string months[12] = {"April", "May", "June", "July", "August", "Sentember", "October", "November", "December", "January", "February", "March"};
    setlocale(LC_ALL, "Rus");
    int i = 0;
    while (i < 12)
    {
    if(months[i] == month) cout << zodiac[i] << endl;
    i++;
    }
}
void peregruzka(int year)
{
    int yea= year;
    string colors[5] = {"������(��)", "�������(��)", "�����(��)", "�����(��)", "������(��)"};
    string animals[12] = {"�����", "������", "�����", "�����", "�������", "����", "������", "����", "��������", "������", "������", "������"};
    year = (year - 4) % 60;

    cout << yea << " - ��� " << colors[year / 12] << " " << animals[year % 12] << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int c;
    string m;
    cout << "������� ���: ";
    cin >> c;
    cout << endl;
    peregruzka(c);
    cout << "������� �����:";
    cin >> m;
    cout << endl;
    peregruzka(m);
    return 0;

}
