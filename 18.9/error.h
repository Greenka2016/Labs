#pragma once

#include <string>
#include <iostream>
using namespace std;


class error //êëàññ îøèáêà
{
	string str;
public:
	//êîíñòðóêòîð, èíèöèèðóåò àòðèáóò str ñîîáùåíèåì îá îøèáêå
	error(string s) { str = s; }
	void what() { cout << str << endl; } //âûâîäèò çíà÷åíèå àòðèáóòà str
};
