#pragma once



const int evNothing = 0;//ïóñòîå ñîáûòèå
const int evMessage = 100;//íåïóñòîå ñîáûòèå
const int cmAdd = 1;//äîáàâèòü îáúåêò â ãðóïïó
const int cmDel = 2;//óäàëèòü îáúåêò èç ãðóïïû
const int cmGet = 3;//âûâåñòè èíôîðìàöèþ î ñðåäíåì âîçðàñòå
const int cmShow = 4;//âûâåñòè âñþ ãðóïïó
const int cmMake = 6;//ñîçäàòü ãðóïïó
const int cmQuit = 101;//âûõîä



//êëàññ ñîáûòèå
struct TEvent
{
	int what;//òèï ñîáûòèÿ
	union
	{
		int command;//êîä êîìàíäû
		struct
		{
			int message;
			int a;//ïàðàìåòð êîìàíäû
		};
	};
};
