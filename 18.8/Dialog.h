#pragma once
#include <iostream>
#include "Object.h"
#include "People.h"
#include "Abiturient.h"
#include "Event.h"
#include "Person.h"
#include "Dialog.h"
using namespace std;


class Dialog :
	public Person
{
public:
	Dialog(void);//êîíòðóêòîð
	virtual ~Dialog(void);//äåñòðóêòîð

	virtual void GetEvent(TEvent& event);//ïîëó÷èòü ñîáûòèå
	virtual int Execute();//ãëàâíûé öèêë îáðàáîòêè ñîáûòèé
	virtual void HandleEvent(TEvent& event); //îáðàáîò÷èê
	virtual void ClearEvent(TEvent& event);//î÷èñòèòü ñîáûòèå

	int Valid();//ïðîâåðêà àòðèáóòà EndState
	void EndExec();//îáðàáîòêà ñîáûòèÿ «êîíåö ðàáîòû»
protected:
	int EndState;
};
