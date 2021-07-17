#pragma once
#include "MyLib.h"
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
const int n = 8, x1 = 50, x2 = 0, y2 = 8, w1 = 60, h1 = 2 ;

string menu[n] = { "1. QUAN LY MAY BAY",
				   "2. QUAN LY CHUYEN BAY",
				   "3. DAT VE MAY BAY",
				   "4. HUY VE MAY BAY",
				   "5. DANH SACH HANH KHACH THUOC 1 CHUYEN BAY",
				   "6. DANH SACH CHUYEN BAY BAY CUNG NGAY VA TOI CUNG DIA DIEM",
				   "7. DANH SACH VE TRONG CUA 1 CHUYEN BAY",
				   "8. THONG KE CHUYEN BAY DA HOAN THANH" };

//================================Cau truc man hinh Console================================
void Background()//nen:den, chu:trang =>den - trang
{
	SetColor(15);
	SetbgColor(0);
}

void Begin()
{
	SetColor(Cyan);
	SetbgColor(Black);
}
void HLtext()
{
	SetColor(DarkRed);
	SetbgColor(Black);
}
void Highlight(int x, int y, int w, int h, int mauHL)//chu do, nhay trang
{
		TextColor(mauHL);
		for (int iy = y + 1; iy <= y + h - 1; iy++)
		{
			for (int ix = x + 1; ix <= x + w - 1; ix++)
			{
				gotoXY(ix, iy); cout << " ";
			}
		}
		SetColor(11);
		gotoXY(x + 1, y + 1);
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

//void boxHLtext(int x, int y, int w, int h, int mauChu, int mauHL, string nd)
//{
//	//HLtext(x, y, w, h, mauHL, nd);
//	SetColor(mauChu);
//	gotoXY(x + 1, y + 1);
//	cout << nd;
//	TextColor(1);
//	box(x, y, w, h, 11);//ve vien
//}
//void boxMenu(int x, int y, int w, int h, int mauChu, int mauNen, string nd[n])
//{
//	
//	for (int i = 0; i < n; i++)
//	{
//		boxHLtext(x, y + (i * 2), w, h, mauChu, mauNen, nd[i]);
//		if (i != 0)
//		{
//			SetColor(11);
//			gotoXY(x, y + (i * 2)); cout << char(195);
//			gotoXY(x+w, y + (i * 2)); cout << char(180);
//		}
//	}
//}

void Console()//khoi tao trang thai ban dau
{
	resizeConsole(1800, 900);//tuong duong khung 210x105
}

void TieuDe()
{
	SetColor(19);
	gotoXY(x1 , 1); cout << "   ___  _   _  _   _  _   _ __   __   ___ _  _ _   ___   _____ _  _   ___   ___   __  _  _  ___ ___   ___ ___   _  " << "\n";
	gotoXY(x1 , 2); cout << "  / _ \\| | | |/_\\ | \\| | | |\\ \\ / /  / __| || | | | \\ \\ / / __| \\| | | _ ) /_\\ \\ / / | \\| |/ _ \\_ _| |   \\_ _| /_\\ " << "\n";
	gotoXY(x1 , 3); cout << " | (_) | |_| / _ \\| .` | | |_\\ V /  | (__| __ | |_| |\\ V /| _|| .` | | _ \\/ _ \\ V /  | .` | (_) | |  | |) | | / _ \\" << "\n";
	gotoXY(x1, 4); cout << "  \\__\\_\\\\___/_/ \\_\\_|\\_| |____|_|    \\___|_||_|\\___/  |_| |___|_|\\_| |___/_/ \\_\\_|   |_|\\_|\\___/___| |___/___/_/ \\_\\" << "\n";
	box(178, 3, 30, 3, 11);
	gotoXY(180, 4); cout << "Bui Tan Sang - N18DCCN169";
	gotoXY(180, 5); cout << "Do Thi Tam - N18DCCN178";
	SetColor(11); lineW(x2, y2 - 1, 210);
}

void HuongDan()
{
	box(x2, y2, w1, 11, 11);
	gotoXY(x2 + 25, y2 + 1); SetColor(29); cout << "HUONG DAN";
	SetColor(11);
	gotoXY(x2 + 10, y2 + 3); cout << " SU DUNG 4 PHIM MUI TEN DE DI CHUYEN";
	gotoXY(x2 + 10, y2 + 4); cout << "INSERT: THEM";
	gotoXY(x2 + 10, y2 + 5); cout << "DELETE: XOA";
	gotoXY(x2 + 10, y2 + 6); cout << "F4    : SUA";

	gotoXY(x2 + 40, y2 + 4);  cout << "ENTER: CHON";
	gotoXY(x2 + 40, y2 + 5);  cout << "F2 : LUU";
	gotoXY(x2 + 40, y2 + 6);  cout << "ESC: THOAT";

	gotoXY(x2 + 25, y2 + 8); SetColor(29); cout << "THONG BAO";
}

int Menu()
{
	gotoXY(x2 + 27, y2 + 13); SetColor(29); cout << "MENU";
	box(x2, y2 + 14, w1, 10, 11);
	Begin();
	ShowCur(0);
	int i, choose = 0;
	char kytu;
	for (i = 0; i < n; i++) { gotoXY(x2 + 2, y2 + 16 + i); cout << menu[i] << endl; }
	gotoXY(x2 + 2, y2 + 16);
	HLtext();
	cout << menu[choose];
	do
	{
		kytu = getKey();
		switch (kytu)
		{
		case Up:	
		if (choose + 1 > 1)
		{
			Begin();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
			choose--;
			HLtext();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
		}
		else
		{
			Begin();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
			choose +=7;
			HLtext();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
		}break;
		case Down:	
		if (choose + 1 < n)
		{
			Begin();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
			choose++;
			HLtext();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
		}
		else
		{
			Begin();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
			choose = 0;
			HLtext();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
		}break;
		case ESC: return 12;
		case Enter: return choose + 1;
		}
	} while (1);
	
}
void Khung()
{
	TieuDe();
	HuongDan();
	Menu();
}

/*Quan ly may bay*/



