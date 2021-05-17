#include "Dialog.h"
#include "Event.h"

//êîíñòðóêòîð
Dialog::Dialog(void) :Person(0)
{
	EndState = 0;
}


//äåñòðóêòîð
Dialog::~Dialog(void)
{
}


//ïîëó÷åíèå ñîáûòèÿ
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "m+-szq"; //ñòðîêà ñîäåðæèò êîäû îïåðàöèé
	string s;
	string param;
	char code;
	cout << "Âîçìîæíûå êîìàíäû:  m+-szq" << endl << "m - ñîçäàòü ãðóïïó(íå ñîçäàøü ãðóïïó íå ñìîæåøü âçàèìîäåéñòâîâàòü ñ ëþäüìè)"
		<< endl << "+ - äîáàâàòü ÷åëîâåêà â ãðóïïó" << endl << "-  - óäàëèòü ÷åëîâåêà èç ãðóïïû" << endl
		<< "s - âûâåñòè âñåõ ëþäåé ãðóïïû" << endl << "z - ñðåäèíèé âîçðàñò ïî ãðóïïå" << endl
		<< "q - îêîí÷àíèå ïðîãðàììû" << endl << "Ââåäèòå ÷òî áóäåì äåëàòü" << endl << '>';
	cin >> s; code = s[0];//ïåðâûé ñèìâîë êîìàíäû
	if (OpInt.find(code) >= 0)//ÿâëÿåòñÿ ëè ñèìâîë êîäîì îïåðàöèè
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm':event.command = cmMake; break;//ñîçäàòü ãðóïïó
		case '+': event.command = cmAdd; break;//äîáàâèòü îáúåêò â ãðóïïó
		case '-': event.command = cmDel; break;//óäàëèòü îáúåêò èç ãðóïïû
		case 's': event.command = cmShow; break;//ïðîñìîòð ãðóïïû
		case'z': event.command = cmGet; break; //êîíåö ðàáîòû
		case'q': event.command = cmQuit; break; //êîíåö ðàáîòû		
		}
		//âûäåëÿåì ïàðàìåòðû êîìàíäû, åñëè îíè åñòü
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);

			int A = atoi(param.c_str());//ïðåîáðàçóåì ïàðìåòð â ÷èñëî
			event.a = A;//çàïèñûâàåì â ñîîáùåíèå
		}
	}
	else event.what = evNothing;//ïóñòîå ñîáûòèå
}
int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event); //ïîëó÷èòü ñîáûòèå
		HandleEvent(event); //îáðàáîòàòü ñîáûòèå
	} while (!Valid());
	return EndState;
}
int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;//ïóñòîå ñîáûòèå
}


void Dialog::EndExec()
{
	EndState = 1;
}


//îáðàáîò÷èê ñîáûòèé
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake://ñîçäàíèå ãðóïïû
			cout << "Âû ñîçäàëè ãðóïïó" << endl << endl;
			size = 10; //ðàçìåð ãðóïïû
			beg = new Object * [size];//âûäåëÿåì ïàìÿòü ïîä ìàññèâ óêàçàòåëåé
			cur = 0; //òåêóùàÿ ïîçèöèÿ
			ClearEvent(event);//î÷èùàåì ñîáûòèå
			break;
		case cmAdd://äîáàâëåíèå
			cout << "Êîãî äîáàâèì â ãðóïïó" << endl << endl;
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			cout << "Óäàëèëè ïîñëåäíåãî ÷åëîâåêà äîáîâëåííîãî â ãðóïïó" << endl << endl;
			Del(); //óäàëåíèå
			ClearEvent(event);
			break;
		case cmShow:
			cout << "Íà äàííûé ìîìåíò èìååòñÿ òàêàÿ ãðóïïà" << endl << endl;
			Show(); //ïðîñìîòð
			ClearEvent(event);
			break;
		case cmQuit:
			cout << "Âû ðåøèëè çàêîí÷èòü ñ ïðîãðàììîé" << endl << endl;
			EndExec(); //âûõîä
			ClearEvent(event);
			break;
		case cmGet:	// ñðåäíèé âîçðàñò ëþäåé
			cout << "Âîçðàñò âñåõ ëþäåé" << endl << endl;
			Person::HandleEvent(event);
			ClearEvent(event);
			break;
		default:
			cout << "Òàêîãî ñîáûòèÿ íåò" << endl << endl;
		};
	}
}
