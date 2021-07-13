#pragma once
#include <iostream> // tranh dung do thu vien khi goi chong file len nhau
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <cmath>
#include <sstream>
#include <ctime> /* thu vien ho tro ve thoi gian thuc */
#include <Windows.h>
using namespace std;
//======= Lay doa do x cua con tro hien tai =============
#define KEY_NONE	-1
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= Lay doa do y cua con tro hien tai =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== dich con tro hien tai den diem co toa do (x,y) ==========
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= Dat mau cho chu =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============= Dat mau cho nen =========
void SetbgColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//=============Dieu chinh kich thuoc console ============= 
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//============== Lam an tro chuot ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

//============== Dung de phan biet phim mui ten vs phim thuong ==============
int getKey()
{
	char key;
	key = _getch();
	if (key == -32 || key == 0)
		return (-_getch());
	return key;
}
//======= Tra ve ma phim nguoi dung bam =========
int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
//=======  Xoa khoang trang ======= 
void Xoa(char* s, int vt)
{
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++)
		s[i - 1] = s[i];
	s[n - 1] = '\0';

}

void xoaKhoangTrang(char* s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')
		{
			Xoa(s, i);
			i--;
		}
	}
}
void xoaKhoangTrangDu(char* s)
{
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			Xoa(s, i);
			i--;
		}
	if (s[0] == ' ')
		Xoa(s, 0);
	if (s[strlen(s) - 1] == ' ')
		Xoa(s, strlen(s) - 1);
}
//=======  chuyen thanh chua in=======
void chuInHoa(char* s)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
	}
}
//=======  Xoa khoang trang thua vs in hoa toan bo chu cai =======
void chuanHoaString(string& s)
{
	for (size_t i = 0; i < s.length(); i++) //Xoa khoang trang thua
	{
		if (s[0] == ' ')
		{
			s.erase(0, 1);
			i--;
		}
		else if (s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
		else if (s[s.length() - 1] == ' ') 
			s.erase(s.length() - 1, 1);
	}
	for (size_t i = 0; i < s.length(); i++) //In hoa toan bo chuoi
	{
		if (s[i] >= 97 && s[i] <= 122)
			s[i] = s[i] - 32;
		
		if (s[i] == ' ')
		{
			for (size_t j = 1; j <= s.length(); j++)
				if (s[i + j] >= 97 && s[i + j] <= 122) 
					s[i + j] = s[i + j] - 32;
		}
	}
}


void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void lineW(int x, int y, int w)//nhap vao toa do diem dau, dài
{
	if (w <= 1) return;
	for (int ix = x + 1; ix < x + w; ix++)
	{
		gotoXY(ix, y); cout << char(196);
	}
}
void lineH(int x, int y, int h)//nhap vao toa do diem dau,cao
{
	if (h <= 1) return;
	for (int iy = y; iy < y + h; iy++)
	{
		gotoXY(x, iy); cout << char(179);
	}
}

void  VeHCN(int x, int y, int w, int h, int mauSet)
{
	SetColor(mauSet);
	for (int i = x; i <= w + x; i++)
	{
		gotoXY(i, y);
		if (i == x)
			cout << (char)218;
		else if (i == w + x)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = x; i <= w + x; i++)
	{
		gotoXY(i, h + y);
		if (i == x)
			cout << (char)192;
		else if (i == w + x)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = y + 1; i < h + y; i++)
	{
		gotoXY(x, i);
		cout << (char)179;
	}
	for (int i = y + 1; i < h + y; i++)
	{
		gotoXY(w + x, i);
		cout << (char)179;
	}
	SetColor(7);
}
