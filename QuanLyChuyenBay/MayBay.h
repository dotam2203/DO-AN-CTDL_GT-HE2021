#pragma once
#include"KhaiBao.h"
#include <iomanip>
#include<cstring>
#include "Box.h"
#include "DocGhiFileSang.h"
#include "GiaoDien.h"
#include "XuLyChuoiSang.h"
#include <exception>

using namespace std;

#define xMove 60
#define yMove 8
//void delete_plane(DS_MAYBAY& mb, DS_CHUYEN_BAY& First);
void delete_plane(DS_MAYBAY& mb, DS_CHUYEN_BAY& First);
void connhay_off1();
void connhay_on1();
void boxThongBao1();
void deleteThongBao1();
void ButtonSua1(int color);
void ButtonThem1(int color);
void ButtonXoa1(int color);
void ButtonESC1(int color);
void search_edit(DS_MAYBAY& mb, DS_CHUYEN_BAY& First);
void clearSearch();
void clearThongBao();
void thongBaoString(string input);
/*======================= Quan ly may bay - Mang con tro ======================*/



void result_plane(DS_MAYBAY& mb)
{
	//connhay_off();
	//box(xMove, yMove, 80, 21, 11);


	readfile_plane(mb);
	//Time();
	int trang = 0;
	int tong = 0;
	if (mb.sl - 2 == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (mb.sl - 2) / 18 + 1;
	}
	int dem = 0;
	char c;

	gotoXY(5 + xMove, 5 + yMove);
	cout << "STT";
	gotoXY(20 + xMove, 5 + yMove);
	cout << "Loai may bay";
	gotoXY(74 + xMove, 5 + yMove);
	cout << "So hieu";
	gotoXY(101 + xMove, 5 + yMove);
	cout << "so cho";
	//while (1)
	//{
back:
	int j = 6;
	for (int i = 0 + trang * 18; i < mb.sl - 1 && i <= 18 + trang * 18; i++)
	{
		j++;
		gotoXY(6 + xMove, j + yMove);
		cout << i;
		gotoXY(20 + xMove, j + yMove);
		cout << mb.dsmaybay[i]->loaimaybay;
		gotoXY(75 + xMove, j + yMove);
		cout << mb.dsmaybay[i]->sohieu;
		gotoXY(103 + xMove, j + yMove);
		cout << mb.dsmaybay[i]->socho;
	}

}

void  box1(int x, int y, int w, int h, int mauNen)
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


void TableList1()
{
	int x2 = 0;
	int y2 = 8;
	int w1 = 60;
	box1(x2 + 65 - 1, y2 + 5 - 1, w1 + 30 + 15, 18 + 4, 19);
	box1(x2 + 65 - 1, y2 + 5 - 1, 5, 18 + 4, 19);
	box1(x2 + 65 - 1, y2 + 5 - 1, 60, 18 + 4, 19);
	box1(x2 + 65 - 1, y2 + 5 - 1, 95, 18 + 4, 19);
	box1(x2 + 65 - 1, y2 + 5 - 1, w1 + 30 + 15, 2, 19);
}

int same_test(DS_MAYBAY& mb, int a)
{
	for (int i = 0; i < mb.sl - 1; i++)
	{
		if (i != a)
		{
			if (_stricmp(mb.dsmaybay[a]->sohieu, mb.dsmaybay[i]->sohieu) == 0 /*&& _stricmp(mb.dsmaybay[a]->loaimaybay, mb.dsmaybay[i]->loaimaybay) == 0*/)return 1;
		}
	}
	return 0;
}

int insert_plane(DS_MAYBAY& mb)
{

	clearSearch();
	clearThongBao();


	int n = 9, x1 = 50, x2 = 0, y2 = 8, w1 = 60, h1 = 2;
	int pointX, pointY1, pointY2, pointY3;
	pointX = x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2 + 2;
	pointY1 = y2 + 5 - 1 + 5 + 1;
	pointY2 = y2 + 5 - 1 + 5 + 4 + 1;
	pointY3 = y2 + 5 - 1 + 5 + 8 + 1;

	readfile_plane(mb);


	int i = 0;
	int a;
	char c;
	int k = 1;
	char* tmp = new char[100];
	mb.dsmaybay[mb.sl - 1] = new MAY_BAY;
	a = mb.sl - 1;
	gotoXY(x2 + 65 - 1 + 10 - 5 + 25, y2 + 5 - 1 - 4 + 1);
	cout << "[ LOAI MAY BAY CHI DUOC NHAP CHU HOAC SO ]";
	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2 + 2, y2 + 5 - 1 + 5 + 1);
	//gotoXY(50, 50);
	connhay_on1();
	do {
		tmp = block_char(41, pointX, pointY1);
	} while (tmp[0] == '\0');
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '.')
		{
			return 0;
		}
		mb.dsmaybay[a]->loaimaybay[i] = tmp[i];
		i++;
		mb.dsmaybay[a]->loaimaybay[i] = '\0';
	}
	gotoXY(x2 + 65 - 1 + 10 - 5 + 25, y2 + 5 - 1 - 4 + 1);
	cout << "                                                ";


	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2 + 2, y2 + 5 - 1 + 5 + 4 + 1);

	do
	{
		i = 0;
		for (int j = 0; j <= 15; j++)
		{
			gotoXY(62 + j, 11); cout << " ";
		}
		do {
			tmp = block_and_char(15, pointX, pointY2);
		} while (tmp[0] == '\0');
		while (tmp[i] != '\0')
		{
			if (tmp[i] == '.')
			{
				return 0;
			}
			mb.dsmaybay[a]->sohieu[i] = tmp[i];
			i++;
			mb.dsmaybay[a]->sohieu[i] = '\0';
		}
		if (same_test(mb, a) == 1)
		{
			//	gotoXY(x2 + 65 - 1 + 10 - 5+25, y2 + 5 - 1 - 4 + 1);
			//	cout << "[ SO HIEU DA CO TRONG DANH SACH]";
			thongBaoString("[ SO HIEU DA CO TRONG DANH SACH]");
			//	gotoXY(x2 + 65 - 1 + 10 - 5 + 25, y2 + 5 - 1 - 4 + 1); cout << "                                      ";
			gotoXY(pointX, pointY2); cout << "                    ";

			//gotoXY(50, 9);cout << "           ";
			//gotoXY(50, 9);
			_getch();
		}
	} while (same_test(mb, a) == 1);
	do
	{

		gotoXY(x2 + 65 - 1 + 10 - 5 + 25, y2 + 5 - 1 - 4 + 1);
		cout << "[ SO CHO >= 20 ]";

		for (int j = 0; j <= 15; j++)
		{
			gotoXY(pointX + j, pointY3); cout << " ";
		}
		connhay_on1();
		i = 0;
		do {
			tmp = block_number(15, pointX, pointY3);
		} while (tmp[0] == '\0');
		while (tmp[i] != '\0')
		{
			if (tmp[i] == '.')
			{
				return 0;
			}
			i++;
		}
		mb.dsmaybay[a]->socho = atoi(tmp);
		if (mb.dsmaybay[a]->socho < 20)
		{
			string socho;
			gotoXY(x2 + 65 - 1 + 10 - 5 + 25, y2 + 5 - 1 - 4 + 1);
			cout << "                                                ";
			socho = to_string(mb.dsmaybay[a]->socho);
			thongBaoString("[ SO CHO " + socho + " < 20 ]");
			gotoXY(pointX, pointY3);

			//_getch();

		}

	} while (mb.dsmaybay[a]->socho < 20);
	connhay_off1();

	gotoXY(x2 + 65 - 1 + 10 - 5 + 25, y2 + 5 - 1 - 4 + 1);
	cout << "[ BAN DA THEM THANH CONG ]";
	Sleep(500);
	gotoXY(x2 + 65 - 1 + 10 - 5 + 25, y2 + 5 - 1 - 4 + 1);
	cout << "                                          ";

	writefile_plane(mb);


	return 0;
}


void connhay_off1()//con nhay bien mat
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cci);
}
void connhay_on1()//con nhay xuat hien
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(hConsole, &cci);
}

void deleteHD1() {
	gotoXY(3, 9); cout << "                                                      ";
	gotoXY(3, 10); cout << "                                                      ";
	gotoXY(3, 11); cout << "                                                      ";
	gotoXY(3, 12); cout << "                                                      ";
	gotoXY(3, 13); cout << "                                                     ";
	gotoXY(3, 14); cout << "                                                     ";
	gotoXY(3, 15); cout << "                                                     ";
	gotoXY(3, 16); cout << "                                                     ";
}
void deleteList1() {
	gotoXY(61, 11); cout << "                                                                                                                  ";
	gotoXY(61, 12); cout << "                                                                                                                  ";
	gotoXY(61, 13); cout << "                                                                                                                  ";
	gotoXY(61, 14); cout << "                                                                                                                  ";
	gotoXY(61, 15); cout << "                                                                                                                  ";
	gotoXY(61, 16); cout << "                                                                                                                  ";
	gotoXY(61, 17); cout << "                                                                                                                  ";
	gotoXY(61, 18); cout << "                                                                                                                  ";
	gotoXY(61, 19); cout << "                                                                                                                  ";
	gotoXY(61, 20); cout << "                                                                                                                  ";
	gotoXY(61, 21); cout << "                                                                                                                  ";
	gotoXY(61, 22); cout << "                                                                                                                  ";
	gotoXY(61, 23); cout << "                                                                                                                  ";
	gotoXY(61, 24); cout << "                                                                                                                  ";
	gotoXY(61, 25); cout << "                                                                                                                  ";
	gotoXY(61, 26); cout << "                                                                                                                  ";
	gotoXY(61, 27); cout << "                                                                                                                  ";
	gotoXY(61, 28); cout << "                                                                                                                  ";
	gotoXY(61, 29); cout << "                                                                                                                  ";
	gotoXY(61, 30); cout << "                                                                                                                  ";
	gotoXY(61, 31); cout << "                                                                                                                  ";
	gotoXY(61, 32); cout << "                                                                                                                  ";
	gotoXY(61, 33); cout << "                                                                                                                  ";
	gotoXY(61, 34); cout << "                                                                                                                  ";
	gotoXY(61, 35); cout << "                                                                                                                  ";
	gotoXY(61, 36); cout << "                                                                                                                   ";
	gotoXY(61, 37); cout << "                                                                                                                   ";
	gotoXY(61, 38); cout << "                                                                                                                   ";
	gotoXY(61, 39); cout << "                                                                                                                   ";

}

void deleteCenter() {
	gotoXY(63, 8); cout << "                                                                                                                                                         ";
	gotoXY(63, 9); cout << "                                                                                                                                                         ";
	gotoXY(63, 10); cout << "                                                                                                                                                        ";
	gotoXY(63, 11); cout << "                                                                                                                                                        ";
	deleteList1();


}


void deleteBoxAdd1() {


	int tmpX = 0 + 65 - 1 + 60 + 30 + 15 + 3;
	int tmpY = 8 + 5 - 1;
	gotoXY(tmpX, 11); cout << "                                       ";
	gotoXY(tmpX, 12); cout << "                                       ";
	gotoXY(tmpX, 13); cout << "                                       ";
	gotoXY(tmpX, 14); cout << "                                       ";
	gotoXY(tmpX, 15); cout << "                                       ";
	gotoXY(tmpX, 16); cout << "                                       ";
	gotoXY(tmpX, 17); cout << "                                       ";
	gotoXY(tmpX, 18); cout << "                                       ";
	gotoXY(tmpX, 19); cout << "                                       ";
	gotoXY(tmpX, 20); cout << "                                       ";
	gotoXY(tmpX, 21); cout << "                                       ";
	gotoXY(tmpX, 22); cout << "                                        ";
	gotoXY(tmpX, 23); cout << "                                       ";
	gotoXY(tmpX, 24); cout << "                                       ";
	gotoXY(tmpX, 25); cout << "                                       ";
	gotoXY(tmpX, 26); cout << "                                             ";
	gotoXY(tmpX, 27); cout << "                                        ";
	gotoXY(tmpX, 28); cout << "                                        ";
	gotoXY(tmpX, 29); cout << "                                        ";
	gotoXY(tmpX, 30); cout << "                                        ";
	gotoXY(tmpX, 31); cout << "                                        ";
	gotoXY(tmpX, 32); cout << "                                        ";
	gotoXY(tmpX, 33); cout << "                                        ";



}

void boxInsertPlane1() {
	int x2 = 0, y2 = 8, w1 = 60;
	box1(x2 + 65 - 1 + w1 + 30 + 15 + 3, y2 + 5 - 1, 40 - 3, 18 + 3, 19);
	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 4 + 10, y2 + 5 - 1 + 1); cout << "[THEM MAY BAY]";
	box1(x2 + 65 - 1 + w1 + 30 + 15 + 3, y2 + 5 - 1, 40 - 3, 2, 19);


	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 - 1); cout << "[Loai May Bay]:";
	box1(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5, 33, 2, 19);
	// gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3+2+2, y2 + 5 - 1+5+1);
	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 - 1 + 4); cout << "[So Hieu May Bay]:";
	box1(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 + 4, 33, 2, 19);
	// gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2+2, y2 + 5 - 1 + 5+4+1);
	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 - 1 + 8); cout << "[So ghe ngoi]:";
	box1(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 + 8, 33, 2, 19);
	// gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2+2, y2 + 5 - 1 + 5+8+1);
}
void boxEditPlane1() {
	int x2 = 0, y2 = 8, w1 = 60;
	box1(x2 + 65 - 1 + w1 + 30 + 15 + 3, y2 + 5 - 1, 40 - 3, 18 + 3, 19);
	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 4 + 10, y2 + 5 - 1 + 1); cout << "[SUA MAY BAY]";
	//box1(x2 + 65 - 1 + w1 + 30 + 15 + 3, y2 + 5 - 1, 40 - 3, 2, 19);


	//gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 - 1); cout << "[Loai May Bay]:";
	//box1(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5, 33, 2, 19);
	// gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3+2+2, y2 + 5 - 1+5+1);
	//gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 - 1 + 4); cout << "[So Hieu May Bay]:";
	//box1(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 + 4, 33, 2, 19);
	// gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2+2, y2 + 5 - 1 + 5+4+1);
	//gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 - 1 + 8); cout << "[So ghe ngoi]:";
	//box1(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 + 8, 33, 2, 19);
	// gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2+2, y2 + 5 - 1 + 5+8+1);
}



void xem_maybay(DS_MAYBAY& mb, DS_CHUYEN_BAY& First)
{
	deleteHD1();

	int movX = 60;
	int movY = 8;
	char c;
back:
	deleteList1();
	TableList1();
	result_plane(mb);
	int trang = 0;
	int tong = 0;
	if (mb.sl - 2 == 17)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (mb.sl - 2) / 18 + 1;
	}
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[300];
	//readfile_cb(First);

	//gotoXY(101, 35); cout << "[Trang]: " << trang + 1 << "/" << tong;

	//connhay_on1();
	do
	{
		ButtonThem1(255);
		ButtonXoa1(255);
		ButtonSua1(255);
		ButtonESC1(255);
		SetbgColor(0);
		c = _getch();
		if (c == 59) {
			ButtonThem1(1);
			SetbgColor(0);
			boxInsertPlane1();
			insert_plane(mb);
			deleteBoxAdd1();
			clearSearch();
			clearThongBao();
		}
		if (c == 83) {
			ButtonXoa1(1);
			SetbgColor(0);
			deleteList1();
			//system("cls");

			delete_plane(mb, First);
			clearSearch();
			clearThongBao();
		}
		if (c == 61) {
			ButtonSua1(1);
			SetbgColor(0);
			deleteList1();
			search_edit(mb, First);
			clearSearch();
			clearThongBao();
		}

		if (i <= 14 && c >= 48 && c <= 122 && c != 59 && c != 83 && c != 61 || c == 32)
		{
			u = 0;
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);
			b[i] = c;
			cout << c;
			i++;
			int k = 0;
			int j = 0;
			connhay_off1();
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(movX + 5 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 50; i++)
				{
					gotoXY(movX + 10 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 39; i++)
				{
					gotoXY(movX + 61 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 10; i++)
				{
					gotoXY(movX + 101 + i, movY + j + 7);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off1();
			int l = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 18)
						{
							break;
						}
						gotoXY(movX + 6, movY + l + 7);
						cout << i;
						gotoXY(movX + 20, movY + l + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoXY(movX + 75, movY + l + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoXY(movX + 103, movY + l + 7);
						cout << mb.dsmaybay[i]->socho;
						l++;
					}
				}
			}
			TableList1();
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);
			connhay_on1();
		}
		if (c == 8 && i > 0)
		{
			u = 0;
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i - 1 + 10, 8 + 5 - 1 - 4 + 1);
			cout << " ";
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i - 1 + 10, 8 + 5 - 1 - 4 + 1);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off1();
			int k = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 18)
						{
							break;
						}
						gotoXY(movX + 6, movY + k + 7);
						cout << i;
						gotoXY(movX + 20, movY + k + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoXY(movX + 75, movY + k + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoXY(movX + 103, movY + k + 7);
						cout << mb.dsmaybay[i]->socho;
						k++;
					}
				}
			}
			if (b[0] == '\0')
			{
				deleteList1();
				result_plane(mb);
				gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);

				goto back;
				connhay_off1();
			}
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);
			TableList1();

			connhay_on1();
		}
		if (c == 27)return;
	} while (c != 27);

	ButtonESC1(1);
	Sleep(500);
	SetbgColor(0);
	deleteList1();

}
void clearSearch() {
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + 10, 8 + 5 - 1 - 4 + 1); cout << "                 ";
}
void clearThongBao() {
	gotoXY(80, 8 + 5 - 1 - 4 + 1); cout << "                                                                                  ";
}
void ButtonThem1(int color)
{
	int x;
	x = 8;
	gotoXY(x, 12); SetbgColor(color); 			    cout << "        ";
	gotoXY(x, 13); SetbgColor(color); SetColor(10); cout << "   F1   ";
	gotoXY(x, 14); SetbgColor(color);	SetColor(0); cout << "  THEM  ";
	gotoXY(x, 15); SetbgColor(color);               cout << "        ";
}
void ButtonXoa1(int color)
{
	int x = 8 + 8 + 8 / 2;
	gotoXY(x, 12); SetbgColor(color); 				cout << "        ";
	gotoXY(x, 13); SetbgColor(color); SetColor(12); cout << " DELETE ";
	gotoXY(x, 14); SetbgColor(color); SetColor(0); cout << "   XOA  ";
	gotoXY(x, 15); SetbgColor(color); 	            cout << "        ";
	SetbgColor(0); SetColor(15);
}
void ButtonCancel1(int color)
{
	int x = 8 + 8 + 8 / 2;
	gotoXY(x, 12); SetbgColor(color); 				cout << "        ";
	gotoXY(x, 13); SetbgColor(color); SetColor(12); cout << " DELETE ";
	gotoXY(x, 14); SetbgColor(color); SetColor(0); cout << " CANCEL ";
	gotoXY(x, 15); SetbgColor(color); 	            cout << "        ";
	SetbgColor(0); SetColor(15);
}
void ButtonSua1(int color)
{
	int x = (8 + 8 + 8 / 2) + 8 + 8 / 2;
	gotoXY(x, 12); SetbgColor(color); 				cout << "        ";
	gotoXY(x, 13); SetbgColor(color); SetColor(9);  cout << "   F3   ";
	gotoXY(x, 14); SetbgColor(color); SetColor(0);	cout << "   SUA  ";
	gotoXY(x, 15); SetbgColor(color); 				cout << "        ";
}
void ButtonESC1(int color)
{
	int x = ((8 + 8 + 8 / 2) + 8 + 8 / 2) + 8 + 8 / 2;
	gotoXY(x, 12); SetbgColor(color); 				cout << "        ";
	gotoXY(x, 13); SetbgColor(color); SetColor(12); cout << "  ESC   ";
	gotoXY(x, 14); SetbgColor(color); SetColor(0); cout << " THOAT  ";
	gotoXY(x, 15); SetbgColor(color); 	            cout << "        ";
	SetbgColor(0); SetColor(15);
}

// XOA MAY BAY
int yes_no(DS_MAYBAY& mb)
{
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, 15); cout << "BAN CO CHAC LA XOA KHONG";
	box1(0 + 65 - 1 + 60 + 30 + 15 + 3, 8 + 5 - 1, 40 - 3, 18 + 3, 19);
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + 5, 18); cout << "YES";
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + 5, 19); cout << "NO";
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, 18); cout << "=>";
	int k = 18;
	char c;
	do
	{
		c = _getch();
		if (c == 72)
		{
			if (k > 18)
			{
				k = k - 1;
			}
		}
		else if (c == 80)
		{
			if (k < 19)
			{
				k += 1;
			}

		}
		if (k > 18)
		{
			gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, k - 1);
			printf("  ");
		}
		if (k < 19)
		{
			gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, k + 1);
			printf("  ");

		}
		cout << "  ";
		gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, k);
		cout << "=>";
		//Sleep(200);
	} while (c != 13);
	switch (k)
	{
	case 18:
		thongBaoString("BAN DA XOA THANH CONG !!!");
		writefile_plane(mb);
		deleteList1();
		return 0;
	case 19:
		deleteBoxAdd1();
		clearSearch();
		return 1;
	}
	//
	return 0;
}
int yes_noSave(DS_MAYBAY& mb)
{
	deleteBoxAdd1();
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, 15); cout << "BAN CO CHAC LA LUU KHONG";
	box1(0 + 65 - 1 + 60 + 30 + 15 + 3, 8 + 5 - 1, 40 - 3, 18 + 3, 19);
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + 5, 18); cout << "YES";
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + 5, 19); cout << "NO";
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, 18); cout << "=>";
	int k = 18;
	char c;
	do
	{
		c = _getch();
		if (c == 72)
		{
			if (k > 18)
			{
				k = k - 1;
			}
		}
		else if (c == 80)
		{
			if (k < 19)
			{
				k += 1;
			}

		}
		if (k > 18)
		{
			gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, k - 1);
			printf("  ");
		}
		if (k < 19)
		{
			gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, k + 1);
			printf("  ");

		}
		cout << "  ";
		gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, k);
		cout << "=>";
		//Sleep(200);
	} while (c != 13);
	switch (k)
	{
	case 18:
		writefile_plane(mb);
		deleteList1();
		deleteBoxAdd1();

		return 0;
	case 19:
		deleteBoxAdd1();
		clearSearch();
		return 1;
	}
	return 0;
}


void delete_plane(DS_MAYBAY& mb, DS_CHUYEN_BAY& First)
{
	clearSearch();
	clearThongBao();
	int movX = 60;
	int movY = 8;
	char c;
back:
	clearSearch();
	clearThongBao();
	deleteList1();
	TableList1();
	result_plane(mb);
	int trang = 0;
	int tong = 0;
	if (mb.sl - 2 == 17)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (mb.sl - 2) / 18 + 1;
	}
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[300];
	readfile_cb(First);

	gotoXY(101, 35); cout << "[Trang]: " << trang + 1 << "/" << tong;

	//connhay_on1();
	do
	{
		bool check = false;
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 122 || c == 32)
		{
			u = 0;
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);
			b[i] = c;
			cout << c;
			i++;
			int k = 0;
			int j = 0;
			connhay_off1();
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(movX + 5 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 50; i++)
				{
					gotoXY(movX + 10 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 39; i++)
				{
					gotoXY(movX + 61 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 10; i++)
				{
					gotoXY(movX + 101 + i, movY + j + 7);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off1();
			int l = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 18)
						{
							break;
						}
						gotoXY(movX + 6, movY + l + 7);
						cout << i;
						gotoXY(movX + 20, movY + l + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoXY(movX + 75, movY + l + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoXY(movX + 103, movY + l + 7);
						cout << mb.dsmaybay[i]->socho;
						l++;
					}
				}
			}
			TableList1();
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);
			connhay_on1();
		}
		if (c == 8 && i > 0)
		{
			u = 0;
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i - 1 + 10, 8 + 5 - 1 - 4 + 1);
			cout << " ";
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i - 1 + 10, 8 + 5 - 1 - 4 + 1);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off1();
			int k = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 18)
						{
							break;
						}
						gotoXY(movX + 6, movY + k + 7);
						cout << i;
						gotoXY(movX + 20, movY + k + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoXY(movX + 75, movY + k + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoXY(movX + 103, movY + k + 7);
						cout << mb.dsmaybay[i]->socho;
						k++;
					}
				}
			}
			if (b[0] == '\0')
			{
				deleteList1();
				result_plane(mb);
				gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);

				goto back;
				connhay_off1();
			}
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);
			TableList1();

			connhay_on1();
		}
		if (c == 27)return;
	} while (c != 13);
	connhay_off1();
	if (u == 0)
	{
		u = mb.sl;
		for (int i = 0; i < u - 1; i++)
		{
			a[i] = i;
		}
		u--;
	}
	int f = 7;
	int p = 0;
	//=================================================================================================================//

kay:
	f = 7;
	gotoXY(movX + 1, movY + 7); cout << ">";
	do
	{
		gotoXY(101, 35); cout << "[Trang]: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f <= 7 && tong > 1 && trang > 0 && c == 72)
		{
			gotoXY(movX + 1, movY + 7);
			cout << "   ";
			f = 25;
			trang--;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(movX + 5 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 50; i++)
				{
					gotoXY(movX + 10 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 39; i++)
				{
					gotoXY(movX + 61 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 10; i++)
				{
					gotoXY(movX + 101 + i, movY + j + 7);
					cout << " ";
				}
				j++;
			}
			TableList1();
			for (int i = 0 + trang * 18; i < mb.sl - 1 && i <= 18 + trang * 18; i++)
			{
				gotoXY(movX + 6, movY + k + 7);
				cout << i;
				gotoXY(movX + 20, movY + k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoXY(movX + 75, movY + k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoXY(movX + 103, movY + k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
		}
		if (c == 72)
		{
			if (f > 7)
			{
				f = f - 1;
				p--;
			}
		}
		else if (c == 80)
		{
			if (f < u + 6 && p <= u - 2)
			{
				f += 1;
				p++;
			}

		}
		if (c == 27)goto back;
		if (f != 7)
		{
			gotoXY(movX + 1, movY + f - 1);
			cout << " ";
		}
		if (f != 7 + u)
		{
			gotoXY(movX + 1, movY + f + 1);
			cout << " ";
		}
		if (f == 25 && tong > 1 && trang + 1 < tong)
		{
			trang++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(movX + 5 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 50; i++)
				{
					gotoXY(movX + 10 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 39; i++)
				{
					gotoXY(movX + 61 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 10; i++)
				{
					gotoXY(movX + 101 + i, movY + j + 7);
					cout << " ";
				}
				j++;
			}
			TableList1();
			for (int i = 0 + trang * 18; i < mb.sl - 1 && i <= 18 + trang * 18; i++)
			{
				gotoXY(movX + 6, movY + k + 7);
				cout << i;
				gotoXY(movX + 20, movY + k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoXY(movX + 75, movY + k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoXY(movX + 103, movY + k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
			goto kay;
		}
		cout << "  ";
		gotoXY(movX + 1, movY + f);
		cout << ">";
	} while (c != 13);
	deleteList1();
	//=============================================================================================================//

	int h = 0;
	char* tmp = new char[16];
	while (mb.dsmaybay[a[p]]->sohieu[h] != '\0')
	{
		tmp[h] = mb.dsmaybay[a[p]]->sohieu[h];
		h++;
		tmp[h] = '\0';
	}
	DS_CHUYEN_BAY v;
	v = First;
	while (v != NULL)
	{

		if (_strcmpi(v->cb.sohieu, tmp) == 0)
		{


			gotoXY(0 + 65 - 1 + 10 - 5 + 20, 8 + 5 - 1 - 4 + 1);  cout << "MAY BAY NAY DA DUOC THANH LAP CHUYEN BAY, NEN BAN KHONG DUOC XOA";
			_getch();
			v->cb.trangthai = 0;
			clearThongBao();
			clearSearch();

			goto back;
			//	gotoXY(50, 13);

				//_getch();
				//system("cls");
				//goto main;
		}
		v = v->next;
	}
	for (int j = a[p]; j < mb.sl - 1; j++)
	{
		strcpy_s(mb.dsmaybay[j]->loaimaybay, mb.dsmaybay[j + 1]->loaimaybay);
		strcpy_s(mb.dsmaybay[j]->sohieu, mb.dsmaybay[j + 1]->sohieu);
		mb.dsmaybay[j]->socho = mb.dsmaybay[j + 1]->socho;
	}
	MAY_BAY* tam = mb.dsmaybay[mb.sl - 1];
	mb.sl = mb.sl - 2;
	deleteList1();


	if (yes_no(mb) == 0)
	{

		gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3, 15);
		cout << "DA XOA XONG";
		writefile_flight(First);
		deleteList1();
		deleteBoxAdd1();
		clearSearch();
		Sleep(500);

	}
	goto back;
	deleteList1();
	deleteBoxAdd1();
	clearSearch();
}


void boxThongBao1() {
	box1(0 + 65 - 1, 8 + 5 - 1 - 4, 60 + 30 + 15, 2, 19);
	gotoXY(0 + 65 - 1 + 10 - 5, 8 + 5 - 1 - 4 + 1); SetColor(29); cout << "[THONG BAO]:";

}
void deleteThongBao1() {
	gotoXY(80, 8 + 5 - 1 - 4 + 1); cout << "                                                        ";
}


void search_edit(DS_MAYBAY& mb, DS_CHUYEN_BAY& First)
{
	clearSearch();
	clearThongBao();
	int  movXX = 180 - 25 - 5 - 2;
	int movXY = 16 - 10;
	int movX = 60;
	int movY = 8;
	char c;
back:
	clearSearch();
	clearThongBao();
	deleteList1();
	TableList1();
	result_plane(mb);
	int trang = 0;
	int tong = 0;
	if (mb.sl - 2 == 17)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (mb.sl - 2) / 18 + 1;
	}
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[300];
	readfile_cb(First);

	gotoXY(101, 35); cout << "[Trang]: " << trang + 1 << "/" << tong;

	//connhay_on1();
	do
	{
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 122 || c == 32)
		{
			u = 0;
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);
			b[i] = c;
			cout << c;
			i++;
			int k = 0;
			int j = 0;
			connhay_off1();
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(movX + 5 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 50; i++)
				{
					gotoXY(movX + 10 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 39; i++)
				{
					gotoXY(movX + 61 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 10; i++)
				{
					gotoXY(movX + 101 + i, movY + j + 7);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off1();
			int l = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 18)
						{
							break;
						}
						gotoXY(movX + 6, movY + l + 7);
						cout << i;
						gotoXY(movX + 20, movY + l + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoXY(movX + 75, movY + l + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoXY(movX + 103, movY + l + 7);
						cout << mb.dsmaybay[i]->socho;
						l++;
					}
				}
			}
			TableList1();
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);
			connhay_on1();
		}
		if (c == 8 && i > 0)
		{
			u = 0;
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i - 1 + 10, 8 + 5 - 1 - 4 + 1);
			cout << " ";
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i - 1 + 10, 8 + 5 - 1 - 4 + 1);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off1();
			int k = 0;
			for (int i = 0; i < mb.sl; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (mb.dsmaybay[i]->sohieu[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 18)
						{
							break;
						}
						gotoXY(movX + 6, movY + k + 7);
						cout << i;
						gotoXY(movX + 20, movY + k + 7);
						cout << mb.dsmaybay[i]->loaimaybay;
						gotoXY(movX + 75, movY + k + 7);
						cout << mb.dsmaybay[i]->sohieu << endl;
						gotoXY(movX + 103, movY + k + 7);
						cout << mb.dsmaybay[i]->socho;
						k++;
					}
				}
			}
			if (b[0] == '\0')
			{
				deleteList1();
				result_plane(mb);
				gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);

				goto back;
				connhay_off1();
			}
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);
			TableList1();

			connhay_on1();
		}
		if (c == 27)return;
	} while (c != 13);
	connhay_off1();
	if (u == 0)
	{
		u = mb.sl;
		for (int i = 0; i < u - 1; i++)
		{
			a[i] = i;
		}
		u--;
	}
	int f = 7;
	int p = 0;
	//=================================================================================================================//

kay:
	f = 7;
	gotoXY(movX + 1, movY + 7); cout << ">";
	do
	{
		gotoXY(101, 35); cout << "[Trang]: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f <= 7 && tong > 1 && trang > 0 && c == 72)
		{
			gotoXY(movX + 1, movY + 7);
			cout << "   ";
			f = 25;
			trang--;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(movX + 5 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 50; i++)
				{
					gotoXY(movX + 10 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 39; i++)
				{
					gotoXY(movX + 61 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 10; i++)
				{
					gotoXY(movX + 101 + i, movY + j + 7);
					cout << " ";
				}
				j++;
			}
			TableList1();
			for (int i = 0 + trang * 18; i < mb.sl - 1 && i <= 18 + trang * 18; i++)
			{
				gotoXY(movX + 6, movY + k + 7);
				cout << i;
				gotoXY(movX + 20, movY + k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoXY(movX + 75, movY + k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoXY(movX + 103, movY + k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
		}
		TableList1();
		if (c == 72)
		{
			if (f > 7)
			{
				f = f - 1;
				p--;
			}
		}
		else if (c == 80)
		{
			if (f < u + 6 && p <= u - 2)
			{
				f += 1;
				p++;
			}

		}
		if (c == 27)goto back;
		if (f != 7)
		{
			gotoXY(movX + 1, movY + f - 1);
			printf(" ");
		}
		if (f != 7 + u)
		{
			gotoXY(movX + 1, movY + f + 1);
			printf(" ");
		}
		if (f == 25 && tong > 1 && trang + 1 < tong)
		{
			trang++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(movX + 5 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 50; i++)
				{
					gotoXY(movX + 10 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 39; i++)
				{
					gotoXY(movX + 61 + i, movY + j + 7);
					cout << " ";
				}
				for (int i = 0; i < 10; i++)
				{
					gotoXY(movX + 101 + i, movY + j + 7);
					cout << " ";
				}
				j++;
			}
			for (int i = 0 + trang * 18; i < mb.sl - 1 && i <= 18 + trang * 18; i++)
			{
				gotoXY(movX + 6, movY + k + 7);
				cout << i;
				gotoXY(movX + 20, movY + k + 7);
				cout << mb.dsmaybay[i]->loaimaybay;
				gotoXY(movX + 75, movY + k + 7);
				cout << mb.dsmaybay[i]->sohieu << endl;
				gotoXY(movX + 103, movY + k + 7);
				cout << mb.dsmaybay[i]->socho;
				k++;
			}
			goto kay;
		}
		TableList1();
		cout << "  ";
		gotoXY(movX + 1, movY + f);
		cout << ">";
	} while (c != 13);
	deleteList1();


	//================================================================================================================//
	int k = 10 + movXY;


	readfile_plane(mb);
main:

	boxEditPlane1();
	// + movXX
	// + movXY



	gotoXY(30 + movXX, 10 + movXY); cout << "LoaiMB: " << mb.dsmaybay[a[p]]->loaimaybay;



	gotoXY(30 + movXX, 11 + movXY); cout << "SoHieuMB: " << mb.dsmaybay[a[p]]->sohieu;

	gotoXY(30 + movXX, 12 + movXY); cout << "So cho: " << mb.dsmaybay[a[p]]->socho;
	gotoXY(30 + movXX, 13 + movXY); cout << "Luu va Thoat";
	gotoXY(25 + movXX, k); cout << "==>";
	do
	{
		c = _getch();
		if (c == 72)
		{
			if (k > 10 + movXY)
			{
				k = k - 1;
			}
		}
		else if (c == 80)
		{
			if (k < 13 + movXY)
			{
				k += 1;
			}

		}
		if (c == 27)
		{

			goto back;
		}
		if (k != 10 + movXY)
		{
			gotoXY(25 + movXX, k - 1);
			printf("   ");
		}
		if (k != 14 + movXY)
		{
			gotoXY(25 + movXX, k + 1);
			printf("  ");
		}
		cout << "  ";
		gotoXY(25 + movXX, k);
		cout << "==>";

		//Sleep(200);
	} while (c != 13);
	fflush(stdin);
	switch (k)
	{
	case 16:
	{

		int i = 0;
		int j = 0;
		char* tmp = new char[100];
		for (int j = 0; j <= 22; j++)
		{
			gotoXY(47 + j + movXX - 8 - 1, 10 + movXY); cout << " ";
		}
		gotoXY(53 + movXY, 8 + movXY);
		do {
			gotoXY(47 + j + movXX - 8 - 1, 10 + movXY); connhay_on1();

			tmp = block_char(41, 47 + j + movXX - 8 - 1, 10 + movXY);
		} while (tmp[0] == '\0');

		if (tmp[0] == '.')
		{
			//system("cls");
			goto main;
		}
		while (tmp[i] != '\0')
		{
			mb.dsmaybay[a[p]]->loaimaybay[i] = tmp[i];
			i++;
			mb.dsmaybay[a[p]]->loaimaybay[i] = '\0';
			connhay_off1();
		}
		break;
	}
	case 17:
	{

		char kmp[16];
		strcpy_s(kmp, mb.dsmaybay[a[p]]->sohieu);
		do
		{
			char* cmp = new char[100];
			int i = 0;
			int j = 0;
			for (int j = 0; j <= 20; j++)
			{
				gotoXY(43 + j + movXX - 4, 11 + movXY); cout << " ";
			}
			gotoXY(53 + movXX, 9 + movXY);
			do {
				gotoXY(43 + j + movXX - 4, 11 + movXY); connhay_on1();
				cmp = block_and_char(14, 43 + j + movXX - 4, 11 + movXY);
			} while (cmp[0] == '\0');
			j = 0;
			if (cmp[0] == '.')
			{

				goto main;
			}
			while (cmp[i] != '\0')
			{
				mb.dsmaybay[a[p]]->sohieu[i] = cmp[i];
				i++;
				mb.dsmaybay[a[p]]->sohieu[i] = '\0';
			}
			if (same_test(mb, a[p]) == 1)
			{


				thongBaoString("SO HIEU MAY BAY DA CO TRONG DANH SACH.");
				connhay_off1();
				//gotoXY(94, 4);
				//cout << "nhap lai!";
				_getch();
				//gotoXY(94, 4); cout << "           ";
			}
		} while (same_test(mb, a[p]) == 1);
		DS_CHUYEN_BAY v;
		v = First;
		while (v != NULL)
		{
			if (_strcmpi(v->cb.sohieu, kmp) == 0)
			{
				//system("cls");
				gotoXY(50 + movXX, 13 + movXY);
				strcpy_s(v->cb.sohieu, mb.dsmaybay[a[p]]->sohieu);
				deleteList1();
			}
			v = v->next;
		}
		connhay_off1();
		deleteList1();
		break;

	}
	case 18:
	{

		int i = 0;
		char* kmp = new char[100];


		do
		{
			for (int j = 0; j <= 10; j++)
			{
				gotoXY(43 + j + movXX - 4 - 1, 11 + movXY + 1); cout << " ";
			}
			gotoXY(53 + movXX, 10 + movXY);
			i = 0;
			do {
				gotoXY(43 + 0 + movXX - 4 - 1, 11 + movXY + 1); cout << "              ";
				gotoXY(43 + 0 + movXX - 4 - 1, 11 + movXY + 1); connhay_on1();
				kmp = block_number(15, 43 + 0 + movXX - 4 - 1, 11 + movXY + 1);
			} while (kmp[0] == '\0');
			int j = 0;
			connhay_off1();
			if (kmp[0] == '.')
			{
				///deleteList1();
				goto main;
			}

			if (atoi(kmp) < 20)
			{
				thongBaoString("SO GHE NGOI PHAI > 20");

				//gotoXY(94, 5);
				//cout << "nhap lai!";
				_getch();
				//gotoXY(94, 5); cout << "           ";
			}
		} while (atoi(kmp) < 20);
		mb.dsmaybay[a[p]]->socho = atoi(kmp);
		DS_CHUYEN_BAY v;
		v = First;
		while (v != NULL)
		{
			if (_strcmpi(v->cb.sohieu, mb.dsmaybay[a[p]]->sohieu) == 0)
			{
				//system("cls");
				gotoXY(50 + movXX, 13 + movXY);
				v->cb.ds_ve.n = mb.dsmaybay[a[p]]->socho;
				//system("cls");
			}
			v = v->next;
		}
		//system("cls");
		break;
	}
	case 19:
		deleteList1();
		mb.sl--;

		if (yes_noSave(mb) == 0)
		{

			writefile_flight(First);
			//can phai thong bao Luu
			thongBaoString("SUA MAY BAY THANH CONG");

			_getch();

			goto back;
		}
		else { goto back; }
	}
	goto main;
}