#include "People.h"
#include "Event.h"


//êîíñòðóêòîð áåç ïàðàìåòðîâ
People::People(void)
{
	Name = "";
	Age = 0;
}


//äåñòðóêòîð
People::~People(void)
{}


//êîíñòðêòîð ñ ïàðàìåòðàìè
People::People(string N, int A)
{
	Name = N;
	Age = A;;
}


//êîíñòðóêòîð êîïèðîâàíèÿ
People::People(const People& car)
{
	Name = car.Name;
	Age = car.Age;
}


//ñåëåêòîðû
void People::Set_Age(int A)
{
	Age = A;
}
void People::Set_Name(string N)
{
	Name = N;
}

//îïåðàòîð ïðèñâàèâàíèÿ
People& People::operator=(const People& c)
{
	if (&c == this)return *this;
	Name = c.Name;
	Age = c.Age;
	return *this;
}


//ìåòîä äëÿ ïðîñìîòðà àòðèáóòîâ
void People::Show()
{
	cout << "\nName : " << Name;
	cout << "\nAge : " << Age;
	cout << endl << endl;
}


//ìåòîä äëÿ ââîäà çíà÷åíèé àòðèáóòîâ
void People::Input()
{
	cout << "\nName:"; cin >> Name;
	cout << "\nAge:"; cin >> Age;
	cout << endl << endl;
}


int sum = 0;
int k = 0;

void People::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//ñîáûòèå-ñîîáùåíèå
	{
		switch (e.command)
		{
		case cmGet:
			sum = sum + Get_Age();
			k++;
			cout << "Âîçðàñò ÷åëîâåêà" << endl << Get_Age() << endl << endl;
			break;
		}
	}
}


void People::average_age(const TEvent& e)
{
	cout << "Îáùèé âîçðàñò" << endl << sum << endl << endl;
	sum = sum / k;
	cout << "Ñðåäíèé âîçðàñò" << endl << sum << endl << endl;
}
