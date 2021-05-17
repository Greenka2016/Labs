#pragma once

#include <iostream>

using namespace std;

const int MAX_SIZE = 30;//ìàêñèìàëüíûé ðàçìåð âåêòîðà

class Vector
{
	int size;//òåêóùèé ðàçìåð
	int* beg;//óêàçàòåëü íà íà÷àëî äèíàìè÷åñêîãî ìàññèâà public:
public:
	Vector() { size = 0; beg = 0; }//êîíñòðóêòîð áåç ïàðàìåòðîâ
	Vector(int s, int k);//êîíñòðóêòîð ñ ïàðàìåòðîì
	Vector(int s, int* mas);//êîíñòðóêòîð ñ ïàðàìåòðîì
	Vector(const Vector& v);//êîíñòðóêòîð êîïèðîâàíèÿ
	~Vector();//äåñòðóêòîð

	const Vector& operator=(const Vector& v);// îïåðàöèÿ ïðèñâàèâàíèÿ 
	int operator[](int i);//äîñòóï ïî èíäåêñó

	int operator()();
	int operator +(int i);//äîñòóï ïî èíäåêñó
	int operator * ();
	

	//äðóæåñòâåííûå ôóíêöèè ââîäà-âûâîäà
	friend ostream& operator<<(ostream& out, const Vector& v);
	friend istream& operator>>(istream& in, Vector& v);
};
