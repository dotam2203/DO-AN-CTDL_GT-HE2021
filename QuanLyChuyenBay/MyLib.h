#pragma once
#include <iostream> //tranh dung do thu vien khi goi chong file len nhau
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <ctime> //thu vien ho tro ve thoi gian thuc
#include <Windows.h>
using namespace std;
//==========================Color=========================================
#define Black			0
#define DarkBlue		1
#define DarkGreen		2
#define DarkCyan		3
#define DarkRed			4
#define DarkPink		5
#define DarkYellow		6
#define DarkWhite		7
#define Grey			8
#define Blue			9
#define Green			10
#define Cyan			11
#define Red				12
#define Pink			13
#define Yellow			14
#define White			15
//================================khai bao thao tac phim: F2-save; F4 - edit; Insert - add================================
const int Up = -72, Down = -80, Left = -75, Right = -77, Enter = 13, ESC = 27, Delete = -83, Insert = -82, F2 = -60, F4 = -62, Space = 32, Backspace = 8;
const int n = 9, x1 = 50, x2 = 0, y2 = 8, x3 = 65, x4 = 175, w1 = 60, h1 = 2;
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

void connhay_off()//con nhay bien mat
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cci);
}
void connhay_on()//con nhay xuat hien
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(hConsole, &cci);
}
//============== Lay thoi gian thuc================================
void Time()
{
	int hours, mins ,days,months,years;
	time_t baygio = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &baygio);
	years = 1900 + ltm->tm_year;
	months = 1 + ltm->tm_mon;
	days = ltm->tm_mday;
	mins = ltm->tm_min;
	hours = ltm->tm_hour;
	gotoXY(x3, y2); cout << hours;
	gotoXY(x3 + 2, y2); cout << ":" << mins << " ";
	gotoXY(x3 + 5, y2); cout << days;
	gotoXY(x3 + 7, y2); cout <<"/"<< months;
	gotoXY(x3 + 9, y2); cout << "/" << years;
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
	if (_kbhit()) //true, lenh bat phim
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

//=======  Xoa tat ca khoang trang vs in hoa toan bo chu cai - su dung voi kieu Char=======
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

	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
}

//=======  Xoa khoang trang thua vs in hoa toan bo chu cai - su dung voi kieu Char=======
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

	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
}

//=======  Xoa khoang trang thua - in hoa toan bo chu cai - su dung voi kieu String=======
//void chuanHoaString(string& s)
//{
//	for (size_t i = 0; i < s.length(); i++) //Xoa khoang trang thua
//	{
//		if (s[0] == ' ')
//		{
//			s.erase(0, 1);
//			i--;
//		}
//		else if (s[i] == ' ' && s[i + 1] == ' ')
//		{
//			s.erase(i, 1);
//			i--;
//		}
//		else if (s[s.length() - 1] == ' ') 
//			s.erase(s.length() - 1, 1);
//	}
//	for (size_t i = 0; i < s.length(); i++) //In hoa toan bo chuoi
//	{
//		if (s[i] >= 97 && s[i] <= 122)
//			s[i] = s[i] - 32;
//		
//		if (s[i] == ' ')
//		{
//			for (size_t j = 1; j <= s.length(); j++)
//				if (s[i + j] >= 97 && s[i + j] <= 122) 
//					s[i + j] = s[i + j] - 32;
//		}
//	}
//}
//================== Nhap chuoi ===================
char *chanChuoi(int k, int x, int y)
{
	int i = 0;
	char* s = new char[k];
	s[0] = '\0';
	char c;
	gotoXY(x, y);
	connhay_on();
	while (1)
	{
		c = getKey();
		if (i <= k && c >= 48 && (c >= 48 && c <= 122) || (c == Space))
		{
			if (c >= 97 && c <= 122)
			{
				gotoXY(x + i, y);
				s[i] = c - 32;
				cout << s[i];
			}
			else
			{
				gotoXY(x + i, y);
				s[i] = c;
				cout << c;
			}
			i++;
		}
		if (c == ESC)
		{
			connhay_off();
			s[0] = '.';
			s[1] = '\0';
			return s;
		}
		if (c == Backspace && i > 0)
		{
			gotoXY(x + i - 1, y);
			cout << " ";
			gotoXY(x + i - 1, y);
			i--;
		}
		if (c == Enter)
		{
			connhay_off();
			s[i] == '\0';
			return s;
		}
	}
	
}
char *chanSo(int k, int x, int y)
{
	int i = 0;
	char* s = new char[k];
	s[0] = '\0';
	char c;
	gotoXY(x, y);
	connhay_on();
	while (1)
	{
		c = getKey();
		if (i <= k && c >= 48 && c <= 57)
		{
			gotoXY(x + i, y);
			s[i] = c;
			cout << c;
			i++;
		}
		if (c == ESC)
		{
			connhay_off();
			s[0] = '.';
			s[1] = '\0';
			return s;
		}
		if (c == Backspace && i > 0)
		{
			gotoXY(x + i - 1, y);
			cout << " ";
			gotoXY(x + i - 1, y);
			i--;
		}
		if (c == Enter)
		{
			connhay_off();
			s[i] = '\0';
			return s;
		}

	}
}

void chanXuongDong(char* s)
{
	int n = strlen(s);
	if (s[n - 1] == '\n')
		s[n - 1] = '\0';
}

//==================Bat phim su kien ==============
//================== Xoa dau cach =================
void delSpace(char* s)
{
	int i, j, n;
	n = strlen(s);
	for (i = 0; i < n; i++)
	{
		if ((s[0] == ' ') || ((s[i] == ' ') && (s[i + 1] == ' ')))
		{
			for (j = i; j < n - 1; j++)
				s[j] = s[j + 1];
			n--;
			i--;
		}
	}
	s[i] = 0;
}

void TextColor(int x)
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
	for (int iy = y+1; iy < y + h; iy++)
	{
		gotoXY(x, iy); cout << char(179);
	}
}

void  box(int x, int y, int w, int h, int mauNen)
{
	SetColor(mauNen);
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
		gotoXY(i, h +1+ y);
		if (i == x)
			cout << (char)192;
		else if (i == w + x)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = y + 1; i < h +1+ y; i++)
	{
		gotoXY(x, i);
		cout << (char)179;
	}
	for (int i = y + 1; i < h+1 + y; i++)
	{
		gotoXY(w + x, i);
		cout << (char)179;
	}
	SetColor(7);
}

void VeHCN(int x, int y, int w, int h)
{
	gotoXY(x, y);
	cout << char(218);
	gotoXY(x + w, y);
	cout << char(191);
	gotoXY(x, y + h);
	cout << char(192);
	gotoXY(x + w, y + h);
	cout << char(217);

	gotoXY(x, y);
	for (int i = x + 1; i <= (x + w - 1); i++)
	{
		gotoXY(i, y);
		cout << char(196);
	}
	gotoXY(x, y + h);
	for (int i = x + 1; i <= (x + w - 1); i++)
	{
		gotoXY(i, y + h);
		cout << char(196);
	}
	gotoXY(x, y);
	for (int i = y + 1; i <= (y + h - 1); i++)
	{
		gotoXY(x, i);
		cout << char(179);
	}
	gotoXY(x + w, y);
	for (int i = y + 1; i <= (y + h - 1); i++)
	{
		gotoXY(x + w, i);
		cout << char(179);
	}
}

//==================== Thong bao ====================
void BaoLoi(string s, int x, int y)
{
	TextColor(Red);
	gotoXY(x, y);
	cout << s;
	Sleep(2000);
	gotoXY(x, y);
	for (int i = 0; i < s.length(); i++)
		cout << " ";
	TextColor(Black);
}

void ThanhCong(string s, int x, int y)
{
	TextColor(Blue);
	gotoXY(x, y);
	cout << s;
	Sleep(2000);
	gotoXY(x, y);
	for (int i = 0; i < s.length(); i++)
		cout << " ";
	TextColor(Black);
}
//============================
bool ktGioiTinh(char *s)
{
	if (strcmp(s, "NAM") == 0)
		return true;
	if(strcmp(s, "NU") == 0)
		return false;
}
//================Xoa================
void xoaLoi(int x, int y)
{
	gotoXY(x, y);
	cout << "                                                                                                                                                                  ";
}
void xoaNgayKhoiHanh(int x, int y)
{
	gotoXY(x, y);
	cout << "           ";
}
void xoaTTHK(int x, int y)
{
	gotoXY(x, y);
	cout << "                        ";
}

