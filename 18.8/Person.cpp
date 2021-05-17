#include "Object.h"
#include "People.h"
#include "Abiturient.h"
#include "Person.h"
#include "Event.h"



//äåñòðóêòîð
Person::~Person(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}


//êîíñòðóêòîð ñ ïàðàìåòðàìè
Person::Person(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}


//äîáàâëåíèå îáúåêòà, íà êîòîðûé óêàçûâàåò óêàçàòåëü p â Person
void Person::Add()
{
	Object* p;
	//âûáîð èç îáúåêòîâ äâóõ âîçìîæíûõ êëàññîâ
	cout << "1.People" << endl;
	cout << "2.Abiturient" << endl;
	int y;
	cin >> y;
	if (y == 1)//äîáàâëåíèå îáúåêòà êëàññà People
	{
		People* a = new (People);
		a->Input();//ââîä çíà÷åíèé àòðèáóòîâ
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//äîáàâëåíèå â Person
			cur++;
		}
	}
	else
	{
		if (y == 2) //äîáàâëåíèå îáúåêòà êëàññà Abiturient
		{
			Abiturient* b = new Abiturient;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}

		else return;
	}
}


//ïðîñìîòð Person
void Person::Show()
{
	if (cur == 0) cout << "Empty" << endl << endl;
	Object** p = beg;//óêàçàòåëü íà óêàçàòåëü òèïà Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//âûçîâ ìåòîäà Show() (ïîçäíåå ñâÿçûâàíèå)
		p++;//ïåðåäâèãàåì óêàçàòåëü íà ñëåäóþùèé îáúåêò
	}
}



//îïåðàöèÿ, êîòîðàÿ âîçâðàùàåò ðàçìåð Person
int Person::operator ()()
{
	return cur;
}


//óäàëåíèå ýëåìåíòà èç Person, ïàìÿòü íå îñâîáîæäàåòñÿ!
void Person::Del()
{
	if (cur == 0)return;//ïóñòîé
	cur--;
}



void Person::HandleEvent(const TEvent& e)
{
	if (cur == 0)
	{
		cout << "Empty" << endl << endl;
	}
	else
	{
		if (e.what == evMessage)
		{
			Object** p = beg;
			for (int i = 0; i < cur; i++)
			{
				(*p)->HandleEvent(e);//âûçîâ ìåòîäà (ïîçäíåå ñâÿçûâàíèå)
				p++;//ïåðåäâèãàåì óêàçàòåëü íà ñëåäóþùèé îáúåêò				
			}
			p = beg;
			(*p)->average_age(e);//âûçîâ ìåòîäà (ïîçäíåå ñâÿçûâàíèå)
		}
	}
}
