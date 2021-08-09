#pragma once
#include "MyLib.h"
#include "Box.h"
#include "KhaiBao.h"
#include "MayBay.h"
#include "ChuyenBay.h"
#include "HanhKhach.h"
#include "VE.h"
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

void connhay_off();
void connhay_on();
void TableListCB();

string menu[n] = { "1. QUAN LY MAY BAY",
				   "2. QUAN LY CHUYEN BAY",
				   "3. DAT VE VA HUY VE",
				   "4. DANH SACH HANH KHACH THUOC 1 CHUYEN BAY",
				   "5. DANH SACH CHUYEN BAY BAY CUNG NGAY VA TOI CUNG DIA DIEM",
				   "6. DANH SACH VE TRONG CUA 1 CHUYEN BAY",
				   "7. THONG KE CHUYEN BAY DA HOAN THANH",
				   "8. THOAT KHOI CHUONG TRINH" };

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





void Console()//khoi tao trang thai ban dau
{
	resizeConsole(1800, 900);//tuong duong khung 210x105
}
void boxThongBao() {
	box(x2 + 65 - 1, y2 + 5 - 1 - 4, w1 + 30 + 15, 1, 19);
	gotoXY(x2 + 65 - 1 + 10 - 5, y2 + 5 - 1 - 4 + 1); SetColor(29); cout << "[THONG BAO]:";

}
void thongBaoString(string input) {
	gotoXY(x2 + 65 - 1 + 10 - 5, y2 + 5 - 1 - 4 + 1); SetColor(29); cout << "[THONG BAO]: " << input; SetColor(7);
	Sleep(900);
	gotoXY(x2 + 65 - 1 + 10 - 5, y2 + 5 - 1 - 4 + 1); cout << "                                                                ";
}
void boxThongBaoCB() {
	box(x2 + 65 - 1, y2 + 5 - 1 - 4, w1 + 30 + 15 + 7, 1, 19);
	gotoXY(x2 + 65 - 1 + 10 - 5, y2 + 5 - 1 - 4 + 1); SetColor(29); cout << "[THONG BAO]:";

}
void deleteThongBao() {
	gotoXY(80, y2 + 5 - 1 - 4 + 1); cout << "                                                                      ";
}
void boxSearch() {
	box(x2 + 65 + w1 + 30 + 15 + 5 - 3, y2 + 5 - 1 - 4, 35 + 2, 1, 19);

	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 5 + 2 - 3, y2 + 5 - 1 - 4 + 1); SetColor(29); cout << "[SEARCH]:";
}
void boxSearchCB() {
	box(x2 + 65 + w1 + 30 + 15 + 5 - 3 + 7, y2 + 5 - 1 - 4, 35 + 2 - 7, 1, 19);

	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 5 + 2 - 3 + 7, y2 + 5 - 1 - 3); SetColor(29); cout << "[SEARCH]:";
}
void deleteBoxSearchCB() {
	gotoXY(x2 + 65 + w1 + 30 + 15 + 5 - 3 + 7, y2 + 5 - 1 - 4); cout << "                                 ";
	gotoXY(x2 + 65 + w1 + 30 + 15 + 5 - 3 + 7, y2 + 5 - 1 - 4 + 1); cout << "                                 ";
	gotoXY(x2 + 65 + w1 + 30 + 15 + 5 - 3 + 7, y2 + 5 - 1 - 4 + 2); cout << "                                 ";
}
void boxAddCB() {
	box(x2 + 65 + w1 + 30 + 15 + 5 - 3 + 7, y2 + 5 - 1 - 1, 35 + 2 - 6, 11, 19);

	//gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 5 + 2 - 3 + 7, y2 + 5 - 1 - 4 + 1); SetColor(29); cout << "[THEM CHUYEN BAY]:";
}


void ButtonDatVe(int color)
{
	gotoXY(x2 + 8, y2 + 4); SetbgColor(color); 			     cout << "        ";
	gotoXY(x2 + 8, y2 + 5); SetbgColor(color); SetColor(10); cout << "   F1   ";
	gotoXY(x2 + 8, y2 + 6); SetbgColor(color);	SetColor(0); cout << " DAT VE ";
	gotoXY(x2 + 8, y2 + 7); SetbgColor(color);               cout << "        ";
}
void ButtonHuyVe(int color)
{
	gotoXY(x2 + 20, y2 + 4); SetbgColor(color); 			 cout << "        ";
	gotoXY(x2 + 20, y2 + 5); SetbgColor(color); SetColor(12); cout << "   F3   ";
	gotoXY(x2 + 20, y2 + 6); SetbgColor(color); SetColor(0); cout << " HUY VE ";
	gotoXY(x2 + 20, y2 + 7); SetbgColor(color); 	         cout << "        ";
	SetbgColor(0); SetColor(15);
}
void ButtonESC(int color)
{
	gotoXY(x2 + 32, y2 + 4); SetbgColor(color); 			    cout << "        ";
	gotoXY(x2 + 32, y2 + 5); SetbgColor(color); SetColor(9); cout << "   ESC  ";
	gotoXY(x2 + 32, y2 + 6); SetbgColor(color); SetColor(0); cout << "  THOAT ";
	gotoXY(x2 + 32, y2 + 7); SetbgColor(color); 	            cout << "        ";
}

void ButtonEnter(int color)
{
	gotoXY(x2 + 44, y2 + 4); SetbgColor(color); 			    cout << "        ";
	gotoXY(x2 + 44, y2 + 5); SetbgColor(color); SetColor(9);    cout << "  ENTER ";
	gotoXY(x2 + 44, y2 + 6); SetbgColor(color); SetColor(0);    cout << "  CHON  ";
	gotoXY(x2 + 44, y2 + 7); SetbgColor(color); 	            cout << "        ";
}

void deleteTrang()
{
	gotoXY(35 + x3, y2 + 27); cout << "                   ";
	gotoXY(35 + x3, y2 + 28); cout << "                   ";
	gotoXY(35 + x3, y2 + 29); cout << "                   ";
}
void TieuDe()
{
	SetColor(19);
	gotoXY(x1, 1); cout << "   ___  _   _  _   _  _   _ __   __   ___ _  _ _   ___   _____ _  _   ___   ___   __  _  _  ___ ___   ___ ___   _  " << "\n";
	gotoXY(x1, 2); cout << "  / _ \\| | | |/_\\ | \\| | | |\\ \\ / /  / __| || | | | \\ \\ / / __| \\| | | _ ) /_\\ \\ / / | \\| |/ _ \\_ _| |   \\_ _| /_\\ " << "\n";
	gotoXY(x1, 3); cout << " | (_) | |_| / _ \\| .` | | |_\\ V /  | (__| __ | |_| |\\ V /| _|| .` | | _ \\/ _ \\ V /  | .` | (_) | |  | |) | | / _ \\" << "\n";
	gotoXY(x1, 4); cout << "  \\__\\_\\\\___/_/ \\_\\_|\\_| |____|_|    \\___|_||_|\\___/  |_| |___|_|\\_| |___/_/ \\_\\_|   |_|\\_|\\___/___| |___/___/_/ \\_\\" << "\n";
	box(178, 3, 30, 2, 11);
	gotoXY(180, 4); cout << "Bui Tan Sang - N18DCCN169";
	gotoXY(180, 5); cout << "Do Thi Tam - N18DCCN178";
	SetColor(11); lineW(x2, y2 - 1, 210);
}
void deleteList() {
	gotoXY(63, 11); cout << "                                                                                                           ";
	gotoXY(63, 12); cout << "                                                                                                           ";
	gotoXY(63, 13); cout << "                                                                                                           ";
	gotoXY(63, 14); cout << "                                                                                                           ";
	gotoXY(63, 15); cout << "                                                                                                           ";
	gotoXY(63, 16); cout << "                                                                                                           ";
	gotoXY(63, 17); cout << "                                                                                                           ";
	gotoXY(63, 18); cout << "                                                                                                           ";
	gotoXY(63, 19); cout << "                                                                                                           ";
	gotoXY(63, 20); cout << "                                                                                                           ";
	gotoXY(63, 21); cout << "                                                                                                           ";
	gotoXY(63, 22); cout << "                                                                                                           ";
	gotoXY(63, 23); cout << "                                                                                                           ";
	gotoXY(63, 24); cout << "                                                                                                           ";
	gotoXY(63, 25); cout << "                                                                                                           ";
	gotoXY(63, 26); cout << "                                                                                                           ";
	gotoXY(63, 27); cout << "                                                                                                           ";
	gotoXY(63, 28); cout << "                                                                                                           ";
	gotoXY(63, 29); cout << "                                                                                                           ";
	gotoXY(63, 30); cout << "                                                                                                           ";
	gotoXY(63, 31); cout << "                                                                                                           ";
	gotoXY(63, 32); cout << "                                                                                                           ";
	gotoXY(63, 33); cout << "                                                                                                           ";
	gotoXY(63, 34); cout << "                                                                                                           ";
	gotoXY(63, 35); cout << "                                                                                                           ";
	gotoXY(63, 36); cout << "                                                                                                           ";
	gotoXY(63, 37); cout << "                                                                                                           ";
	gotoXY(63, 38); cout << "                                                                                                           ";
	gotoXY(63, 39); cout << "                                                                                                           ";
	gotoXY(63, 40); cout << "                                                                                                           ";


}

void deleteListCB() {
	gotoXY(61, 11); cout << "                                                                                                                    ";
	gotoXY(61, 12); cout << "                                                                                                                    ";
	gotoXY(61, 13); cout << "                                                                                                                    ";
	gotoXY(61, 14); cout << "                                                                                                                    ";
	gotoXY(61, 15); cout << "                                                                                                                    ";
	gotoXY(61, 16); cout << "                                                                                                                    ";
	gotoXY(61, 17); cout << "                                                                                                                    ";
	gotoXY(61, 18); cout << "                                                                                                                    ";
	gotoXY(61, 19); cout << "                                                                                                                    ";
	gotoXY(61, 20); cout << "                                                                                                                    ";

	gotoXY(61, 21); cout << "                                                                                                                    ";
	gotoXY(61, 22); cout << "                                                                                                                    ";
	gotoXY(61, 23); cout << "                                                                                                                    ";
	gotoXY(61, 24); cout << "                                                                                                                    ";
	gotoXY(61, 25); cout << "                                                                                                                    ";
	gotoXY(61, 26); cout << "                                                                                                                    ";
	gotoXY(61, 27); cout << "                                                                                                                    ";
	gotoXY(61, 28); cout << "                                                                                                                    ";
	gotoXY(61, 29); cout << "                                                                                                                    ";
	gotoXY(61, 30); cout << "                                                                                                                    ";
	gotoXY(61, 31); cout << "                                                                                                                    ";
	gotoXY(61, 32); cout << "                                                                                                                    ";
	gotoXY(61, 33); cout << "                                                                                                                    ";
	gotoXY(61, 34); cout << "                                                                                                                    ";
	gotoXY(61, 35); cout << "                                                                                                                    ";
	gotoXY(61, 36); cout << "                                                                                                                    ";
	gotoXY(61, 37); cout << "                                                                                                                    ";


}
void TableListCauF()
{
	boxThongBaoCB();

	box(x2 + 65 - 1, y2 + 5 - 1, w1 + 30 + 15 + 7, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 5, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 5 + 15, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 34 + 4, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 34 + 10 + 17 + 3 + 15 + 10, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, w1 + 30 + 15 + 7, 1, 19);
}
void TableListThongKe()
{
	box(x2 + 65 - 1, y2 + 5 - 1, w1 + 30 + 15, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 50, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, w1 + 30 + 15, 2, 19);
}
void deleteBoxAdd() {


	int tmpX = x2 + 65 - 1 + w1 + 30 + 15 + 3;
	int tmpY = y2 + 5 - 1;
	gotoXY(tmpX, 11); cout << "                                              ";
	gotoXY(tmpX, 12); cout << "                                              ";
	gotoXY(tmpX, 13); cout << "                                              ";
	gotoXY(tmpX, 14); cout << "                                              ";
	gotoXY(tmpX, 15); cout << "                                              ";
	gotoXY(tmpX, 16); cout << "                                              ";
	gotoXY(tmpX, 17); cout << "                                              ";
	gotoXY(tmpX, 18); cout << "                                              ";
	gotoXY(tmpX, 19); cout << "                                              ";
	gotoXY(tmpX, 20); cout << "                                              ";
	gotoXY(tmpX, 21); cout << "                                              ";
	gotoXY(tmpX, 22); cout << "                                              ";
	gotoXY(tmpX, 23); cout << "                                              ";
	gotoXY(tmpX, 24); cout << "                                              ";
	gotoXY(tmpX, 25); cout << "                                              ";
	gotoXY(tmpX, 26); cout << "                                              ";
	gotoXY(tmpX, 27); cout << "                                              ";
	gotoXY(tmpX, 28); cout << "                                              ";
	gotoXY(tmpX, 29); cout << "                                              ";
	gotoXY(tmpX, 30); cout << "                                              ";
	gotoXY(tmpX, 31); cout << "                                              ";
	gotoXY(tmpX, 32); cout << "                                              ";
	gotoXY(tmpX, 33); cout << "                                              ";



}
void deleteBoxEDITCB() {


	int tmpX = 177;
	int tmpY = y2 + 5 - 1;
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
void HuongDan()
{
	boxThongBao();
	box(x2, y2, w1, 11, 11);


	gotoXY(x2 + 25, y2 + 1); SetColor(29); cout << "HUONG DAN";
	SetColor(11);
	gotoXY(x2 + 10, y2 + 3); cout << " SU DUNG 4 PHIM MUI TEN DE DI CHUYEN";
	gotoXY(x2 + 10, y2 + 4); cout << "<F1>     THEM";
	gotoXY(x2 + 10, y2 + 5); cout << "<DELETE> XOA";
	gotoXY(x2 + 10, y2 + 6); cout << "<F3>     SUA";

	gotoXY(x2 + 40, y2 + 4);  cout << "<ENTER> CHON";
	gotoXY(x2 + 40, y2 + 5);  cout << "<F2>    LUU";
	gotoXY(x2 + 40, y2 + 6);  cout << "<ESC>   THOAT";
}


void deleteNormal()
{

	system("cls");
	TieuDe();
	HuongDan();
	Time();

}


//void deleteHuongDan()
//{
//	box(x2, y2, w1, 11, 11);
//	int j = 1;
//	for (int i = 0; i < w1; i++)
//	{
//		if (j <= 11)
//		{
//			gotoXY(x2 + i, y2 + j); SetbgColor(Black); cout << " ";
//			j++;
//		}
//	}
//}

void TableList()
{

	boxSearch();
	box(x2 + 65 - 1, y2 + 5 - 1, w1 + 30 + 15, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 5, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 60, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 95, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, w1 + 30 + 15, 2, 19);
}
void TableListCB()
{
	boxThongBaoCB();
	boxSearchCB();
	box(x2 + 65 - 1, y2 + 5 - 1, w1 + 30 + 15 + 7, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 5, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 5 + 15, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 34, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 34 + 10, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 34 + 10 + 17 + 3, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 34 + 10 + 17 + 3 + 18, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 34 + 10 + 17 + 3 + 18 + 5, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 34 + 10 + 17 + 3 + 18 + 5 + 5, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, 34 + 10 + 17 + 3 + 18 + 5 + 5 + 6, 18 + 4, 19);
	//box(x2 + 65 - 1, y2 + 5 - 1, 34 + 10 + 17 + 3 + 18, 18 + 4, 19);
	box(x2 + 65 - 1, y2 + 5 - 1, w1 + 30 + 15 + 7, 1, 19);
}
void boxInsertPlane() {

	box(x2 + 65 - 1 + w1 + 30 + 15 + 3, y2 + 5 - 1, 40 - 3, 18 + 3, 19);
	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 4 + 10, y2 + 5 - 1 + 1); cout << "[THEM MAY BAY]";
	box(x2 + 65 - 1 + w1 + 30 + 15 + 3, y2 + 5 - 1, 40 - 3, 2, 19);


	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 - 1); cout << "[Loai May Bay]:";
	box(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5, 33, 2, 19);
	// gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3+2+2, y2 + 5 - 1+5+1);
	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 - 1 + 4); cout << "[So Hieu May Bay]:";
	box(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 + 4, 33, 2, 19);
	// gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2+2, y2 + 5 - 1 + 5+4+1);
	gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 - 1 + 8); cout << "[So ghe ngoi]:";
	box(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2, y2 + 5 - 1 + 5 + 8, 33, 2, 19);
	// gotoXY(x2 + 65 - 1 + w1 + 30 + 15 + 3 + 2+2, y2 + 5 - 1 + 5+8+1);
}


int Menu()
{

	DS_MAYBAY mb;
	HanhKhach* hk[300];
	DS_HANHKHACH ds_hk;
	DS_CHUYEN_BAY First;
	initialize(First);
	chuyen_bay cb;
	chuyenbay* ds_cb[300];
Menu:
	HuongDan();
	ShowCur(0);
	gotoXY(x2 + 27, y2 + 13); SetColor(29); cout << "MENU";
	box(x2, y2 + 14, w1, 11, 11);
	Begin();
	int i, choose = 0;
	char kytu;
	//char c;

	for (i = 0; i < n; i++)
	{
		gotoXY(x2 + 2, y2 + 16 + i);
		cout << menu[i] << endl;
	}
	gotoXY(x2 + 2, y2 + 16);
	HLtext();
	cout << menu[choose];
	do
	{
		deleteList1();
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
				choose += 7;
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
		case Enter:
		{
			switch (choose)
			{
			case 0:
			{
				DS_CHUYEN_BAY First;
				initialize(First);
				deleteList();
				SetColor(11);
				TableList();
				xem_maybay(mb, First);
				deleteHD1();
				deleteCenter();
				clearSearch();

				clearThongBao();

				goto Menu;
			}
			case 1:
			{

				deleteCenter();
				DS_CHUYEN_BAY First;
				initialize(First);
				deleteList();
				deleteHD1();
				SetColor(11);
				TableListCB();
				xem_cb(First, mb, ds_cb);
				deleteListCB();
				deleteHD1();
				clearSearch();
				deleteBoxSearchCB();

				goto Menu;
			}
			case 2:
			{
				xuly2:
				//system("cls");
				deleteNormal();
				deleteHD1();
				ButtonDatVe(White);
				ButtonHuyVe(White);
				ButtonEnter(White);
				ButtonESC(White);
				SetbgColor(0);
				SetColor(Cyan); gotoXY(x3 + 60, y2 + 10); printf("DAT VE VA HUY VE ");;
				box_nho(50 + x3, 15 + y2, 20, 3); gotoXY(55 + x3, 16 + y2); printf("<F1> DAT VE");
				box_nho(50 + x3, 19 + y2, 20, 3); gotoXY(55 + x3, 20 + y2); printf("<F3> HUY VE");
				box_nho(50 + x3, 23 + y2, 20, 3); gotoXY(55 + x3, 24 + y2); printf("<ESC> THOAT");

				(First, ds_cb);
				result_flight(First, ds_cb);
				do
				{
					kytu = getKey();
					if (kytu == F1)
					{
						deleteNormal();
						datVe(ds_cb, First, ds_hk, mb);
						goto xuly2;
					}
					else if (kytu == F3)
					{
						deleteNormal();
						huyVe(ds_cb, First, hk, ds_hk, mb);
						goto xuly2;
					}
				} while (kytu != ESC);
			}
			case 3:
			{
				
				system("cls");
				connhay_off();
				xemHanhKhach(First, ds_hk, hk, mb, ds_cb);
				deleteNormal();
			}break;

			case 4:
			{

				deleteCenter();
				DS_CHUYEN_BAY First;
				initialize(First);
				in_date(First);
				deleteCenter();
				deleteThongBao1();
				deleteListCB();
				deleteHD1();
				SetColor(11);

				goto Menu;
			}
			case 5:
			{
				system("cls");
				connhay_off();
				in_ve(First, ds_hk, hk, mb, ds_cb);
				deleteNormal();
				break;
			}
			case 6:
			{

				DS_CHUYEN_BAY First;
				initialize(First);
				deleteList();
				SetColor(11);
				TableListThongKe();
				sap_xep(First, mb);
				deleteHD1();
				deleteCenter();
				clearSearch();
				clearThongBao();
				goto Menu;
			}

			case 7: break;

			}
		}
		}
	} while (1);
}


void Khung()
{
	TieuDe();
	HuongDan();
	Time();
	//TableList();
	Menu();

}



