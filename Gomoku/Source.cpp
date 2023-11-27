#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<time.h>
using namespace std;
#define MAX 100
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
void Initial(char B[][MAX], int& NOP, int& wc, char ps[], int &turn, int &dimen);
void startScreen(char s);
void displayy(char B[][MAX], int dimen);
void displayyPmsg(char sym);
void PlayerTurn(int &ri, int &ci);
bool IsVal(char B[][MAX], int ri, int ci, int dimen);
void updateBoardd(char B[][MAX], int ri, int ci, char sym);
void TurnIncr(int & turnn, int nop);
bool Haswon(char B[][MAX], char sym, int dimen, int wc);
bool T2Bchecc(char B[][MAX], int C, int rs, int re, char sym);
bool B2Tchecc(char B[][MAX], int C, int rs, int re, char sym);
bool L2Rchecc(char B[][MAX], int R, int cs, int ce, char sym);
bool R2Lchecc(char B[][MAX], int R, int cs, int ce, char sym);
bool Diag1checc(char B[][MAX], int r, int c, int wc, char sym);
bool Diag2checc(char B[][MAX], int r, int c, int wc, char sym);
bool Diag3checc(char B[][MAX], int r, int c, int wc, char sym);
bool Diag4checc(char B[][MAX], int r, int c, int wc, char sym);


int main()
{
	char Board[MAX][MAX], ps[MAX];
	int NOP, scores[MAX] = { 0 }, WinC, turnn = 0, ri, ci, dimen = MAX;
	bool won;
	srand(time(0));
	Initial(Board, NOP, WinC, ps, turnn,dimen);
	startScreen('.');
	do
	{
		displayy(Board, dimen);
		do
		{
			displayyPmsg(ps[turnn]);
			PlayerTurn(ri, ci);
		} while (IsVal(Board, ri, ci, dimen) == false);
		updateBoardd(Board, ri, ci, ps[turnn]);
		won = Haswon(Board, ps[turnn], dimen, WinC);
		if (won != true)
			TurnIncr(turnn, NOP);
	} while (won!=true);
	system("cls");
	gotoRowCol(40, 40);
	cout << ps[turnn] << " WINS!!!!!!!!";


	_getch();
	return 0;
}
void Initial(char B[][MAX], int& NOP, int& wc, char ps[], int &turn, int &dimen)
{
	cout << "Dimension: ";
	cin >> dimen;
	for (int ri = 0; ri < dimen; ri++)
		for (int ci = 0; ci < dimen; ci++)
			B[ri][ci] = '-';
	cout << "No. of Players?: ";
	cin >> NOP;
	cout << NOP << " Symbols please ";
	for (int i = 0; i < NOP; i++)
		cin >> ps[i];
	cout << "Win Count: ";
	cin >> wc;
	turn = rand() % NOP;
}
void startScreen(char s)
{
	system("cls");
	gotoRowCol(40, 40);
	cout << " GOMOKU";
	gotoRowCol(41, 41);
	cout << "\Press ENTER to start";
	_getch();
}
void displayy(char B[][MAX], int dimen)
{
	system("cls");
	for (int ri = 0; ri < dimen; ri++)
	{
		for (int ci = 0; ci < dimen; ci++)
			cout << B[ri][ci];
		cout << endl;
	}

}
void displayyPmsg(char sym)
{
	cout << sym << "'s turn: ";
}
void PlayerTurn(int &ri, int &ci)
{
	getRowColbyLeftClick(ri, ci);
}
bool IsVal(char B[][MAX], int ri, int ci, int dimen)
{
	if ((ri < 0 || ri >= dimen || ci < 0 || ci >= dimen) || B[ri][ci] != '-')
		return false;
	else
		return true;
}
void updateBoardd(char B[][MAX], int ri, int ci, char sym)
{
	B[ri][ci] = sym;
}
void TurnIncr(int & turnn, int nop)
{
	turnn++;
	if (turnn == nop)
		turnn = 0;
}
bool Haswon(char B[][MAX], char sym, int dimen, int wc)
{
	for (int ri = 0; ri < dimen; ri++)
	{
		for (int ci = 0; ci < dimen; ci++)
		{
			if (B[ri][ci] == sym)
			{
				if (T2Bchecc(B, ci, ri, ri + wc - 1, sym) == true || B2Tchecc(B, ci, ri, ri - wc - 1, sym) == true ||
					L2Rchecc(B, ri, ci, ci + wc - 1, sym) == true || R2Lchecc(B, ri, ci, ci - wc - 1, sym) == true ||
					Diag1checc(B, ri, ci, wc, sym) == true || Diag2checc(B, ri, ci, wc, sym) == true ||
					Diag3checc(B, ri, ci, wc, sym) == true || Diag3checc(B, ri, ci, wc, sym) == true)
					return true;
				else continue;
			}
		}
	}
	return false;
}
bool T2Bchecc(char B[][MAX], int C, int rs, int re, char sym)
{
	for (int i = rs; i <= re; i++)
	{
		if (B[i][C] == sym)
			continue;
		else
			return false;
	}
	return true;
}
bool B2Tchecc(char B[][MAX], int C, int rs, int re, char sym)
{
	for (int i = rs; i >= re; i--)
	{

		if (B[i][C] == sym)
			continue;
		else
			return false;
	}
	return true;
}
bool L2Rchecc(char B[][MAX], int R, int cs, int ce, char sym)
{
	for (int i = cs; i <= ce; i++)
	{
		if (B[R][i] == sym)
			continue;
		else
			return false;
	}
	return true;
}
bool R2Lchecc(char B[][MAX], int R, int cs, int ce, char sym)
{
	for (int i = cs; i >= ce; i--)
	{
		if (B[R][i] == sym)
			continue;
		else
			return false;
	}
	return true;
}
bool Diag1checc(char B[][MAX], int r, int c, int wc, char sym)
{
	for (int ri = r, ci = c; ri < r + wc; ri++, ci++)
	{
		if (B[ri][ci] == sym)
			continue;
		else
			return false;
	}
	return true;
}
bool Diag2checc(char B[][MAX], int r, int c, int wc, char sym)
{
	for (int ri = r, ci = c; ri > r - wc; ri--, ci++)
	{
		if (B[ri][ci] == sym)
			continue;
		else
			return false;
	}
	return true;
}
bool Diag3checc(char B[][MAX], int r, int c, int wc, char sym)
{
	for (int ri = r, ci = c; ri > r - wc, c >= 0; ri--, ci--)
	{
		if (B[ri][ci] == sym)
			continue;
		else
			return false;
	}
	return true;
}
bool Diag4checc(char B[][MAX], int r, int c, int wc, char sym)
{
	for (int ri = r, ci = c; ri > r + wc, c >= 0; ri++, ci--)
	{
		if (B[ri][ci] == sym)
			continue;
		else
			return false;
	}
	return true;
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}







//void waitin(int T)
//{
//	for (int i = 0; i <= 1000000000 * T; T++)
//	{
//
//	}
//}
//void L2R(int R, int cs, int ce, int T, char sym)
//{
//	for (int i = cs; i <= ce; i++)
//	{
//		gotoRowCol(R, i);
//		cout << sym;
//		waitin(T);
//	}
//}
//void T2B(int C, int rs, int re, int T, char sym)
//{
//	for (int i = rs; i <= re; i++)
//	{
//		gotoRowCol(i, C);
//		cout << sym;
//		waitin(T);
//	}
//}
//void R2L(int R, int cs, int ce, int T, char sym)
//{
//	for (int i = cs; i >= ce; i--)
//	{
//		gotoRowCol(R, i);
//		cout << sym;
//		waitin(T);
//	}
//}
//void B2T(int C, int rs, int re, int T, char sym)
//{
//	for (int i = rs; i >= re; i--)
//	{
//		gotoRowCol(i, C);
//		cout << sym;
//		waitin(T);
//	}
//}