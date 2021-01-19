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
    string colors[5] = {"зелёной(го)", "красной(го)", "жёлтой(го)", "белой(го)", "чёрной(го)"};
    string animals[12] = {"крысы", "коровы", "тигра", "зайца", "дракона", "змеи", "лошади", "овцы", "обезьяны", "курицы", "собаки", "свиньи"};
    year = (year - 4) % 60;

    cout << yea << " - год " << colors[year / 12] << " " << animals[year % 12] << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int c;
    string m;
    cout << "Введите год: ";
    cin >> c;
    cout << endl;
    peregruzka(c);
    cout << "Введите месяц:";
    cin >> m;
    cout << endl;
    peregruzka(m);
    return 0;

}
