#include <iostream>
using namespace std;

int chessboard[8][8];
int numbchoice = 0;

void pole()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << chessboard[i][j] << " ";
		}
		cout << endl;
	}
}

bool proverka(int a, int b)
{
	for (int i = 0; i < a; i++)
	{
		if (chessboard[i][b])
			return false;
	}
	for (int i = 1; i <= a && b - i >= 0; i++)
	{
		if (chessboard[a - i][b - i])
			return false;
	}
	for (int i = 1; i <= a && b + i < 8; i++)
	{
		if (chessboard[a - i][b + i])
			return false;
	}
	return true;
}

void variants(int a)
{
	if (a == 8)
	{
		pole();

		cout << "Вариант решения: " << ++numbchoice << endl;
	}
	for (int i = 0; i < 8; i++)
	{
		if (proverka(a, i))
		{
			chessboard[a][i] = 1;

			variants(a + 1);

			chessboard[a][i] = 0;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	variants(0);
	return 0;
}
