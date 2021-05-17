#pragma once
#include <iostream>
#include "Object.h"
#include "People.h"
#include "Event.h"
using namespace std;


class People :
	public Object
{
public:
	People(void);				//êîíñòðóêòîð áåç ïàðàìåòðîâ

public:
	virtual ~People(void);		//äåñòðóêòîð
	void Show();				//ôóíêöèÿ äëÿ ïðîñìîòðà àòðèáóòîâ êëàññà ñ ïîìîùüþ óêàçàòåëÿ
	void Input();				//ôóíêöèÿ äëÿ ââîäà çíà÷åíèé àòðèáóòîâ
	People(string, int);		//êîíñòðóêòîð ñ ïàðàìåòðàìè
	People(const People&);		//êîíñòðóêòîð êîïèðîâàíèÿ

	//ñåëåêòîðû
	string Get_Name() { return Name; }
	int Get_Age() { return Age; }

	//ìîäèôèêàòîðû
	void Set_Name(string);
	void Set_Age(int);

	People& operator=(const People&);		//ïåðåãðóçêà îïåðàöèè ïðèñâàèâàíèÿ
	void HandleEvent(const TEvent& e);
	void average_age(const TEvent& e);
protected:
	string Name;
	int Age;
};
