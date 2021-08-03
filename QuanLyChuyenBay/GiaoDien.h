#pragma once
#include "MyLib.h"
using namespace std;

string menu[n] = { "1. QUAN LY MAY BAY",
				   "2. QUAN LY CHUYEN BAY",
				   "3. DAT VE MAY BAY",
				   "4. HUY VE MAY BAY",
				   "5. DANH SACH HANH KHACH THUOC 1 CHUYEN BAY",
				   "6. DANH SACH CHUYEN BAY BAY CUNG NGAY VA TOI CUNG DIA DIEM",
				   "7. DANH SACH VE TRONG CUA 1 CHUYEN BAY",
				   "8. THONG KE CHUYEN BAY DA HOAN THANH",
				   "9. THOAT KHOI CHUONG TRINH!"};

//================================Cau truc man hinh Console================================
void Background()//nen:den, chu:trang =>den - trang
{
	SetColor(White);
	SetbgColor(Black);
}

void Normal()
{
	SetColor(Cyan);
	SetbgColor(Black);
}
void HLtext()
{
	SetColor(Pink);
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
	box(178, 3, 30, 2, 11);
	gotoXY(180, 4); cout << "Bui Tan Sang - N18DCCN169";
	gotoXY(180, 5); cout << "Do Thi Tam - N18DCCN178";
	SetColor(11); lineW(x2, y2 - 1, 210);
}

void HuongDan()
{
	box(x2, y2, w1, 10, 11);
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
	box(x2, y2 + 12, w1, 13, 11);
	Normal();
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
			Normal();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
			choose--;
			HLtext();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
		}
		else
		{
			Normal();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
			choose += 8;
			HLtext();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
		}break;
		case Down:	
		if (choose + 1 < n)
		{
			Normal();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
			choose++;
			HLtext();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
		}
		else
		{
			Normal();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
			choose = 0;
			HLtext();
			gotoXY(x2 + 2, y2 + 16 + choose);
			cout << menu[choose];
		}break;
		case ESC: break; return 12;
		case Enter: return choose + 1;
		}
	} while (1);
	
}

void xoaShowData()
{
	Normal();
	for (int i = 0; i < w1 + 58; i++)
	{
		for (int j = 0; j < 42; j++)
		{
			gotoXY(x3 + i, y2+j);
			cout << " ";
		}
	}
}
void Khung()
{
	TieuDe();
	HuongDan();
	Menu();
	//xoaShowData();
}




/*Quan ly may bay*/



