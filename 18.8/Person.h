#pragma once
#include <iostream>
#include "Object.h"
#include "Event.h"
#include "Person.h"

using namespace std;


class Person
{
public:
	Person(int);//êîíñòðóêòîð ñ ïàðàìåòðàìè
public:
	~Person(void);//äåñòðóêòîð
	void Add();//äîáàâëåíèå ýëåìåíòà â Person
	void Del();
	void Show();
	
	int operator()();//ðàçìåð Person
	void HandleEvent(const TEvent& e);
	void average_age(const TEvent& e);
protected:
	Object** beg;//óêàçàòåëü íà ïåðâûé ýëåìåíò Person
	int size;//ðàçìåð
	int cur;//òåêóùàÿ ïîçèöèÿ
};
