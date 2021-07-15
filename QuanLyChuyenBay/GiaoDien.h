#pragma once
#include "MyLib.h"
using namespace std;
//================================khai bao thao tac phim: F2-save; F4 - edit; Insert - add================================
const int Up = -72, Down = -80, Left = -75, Right = -77, Enter = 13, ESC = 27, Delete = -83, Insert = -82, F2 = -60, F4 = -62, Space = 32, Backspace = 8;
const int x1 = 0, y2 = 8 , w1 = 60;

//================================Cau truc man hinh Console================================
void Background()//nen:den, chu:trang =>den - trang
{
	SetColor(15);
	SetbgColor(0);
}

void HighLight()//chu trang, nhay hong
{
	SetColor(15);
	SetbgColor(12);
}

void Console()//khoi tao trang thai ban dau
{
	resizeConsole(1800, 900);//tuong duong khung 210x105
}

void TieuDe()
{
	SetColor(19);
	gotoXY(x1 + 50, 1); cout << "   ___  _   _  _   _  _   _ __   __   ___ _  _ _   ___   _____ _  _   ___   ___   __  _  _  ___ ___   ___ ___   _  " << "\n";
	gotoXY(x1 + 50, 2); cout << "  / _ \\| | | |/_\\ | \\| | | |\\ \\ / /  / __| || | | | \\ \\ / / __| \\| | | _ ) /_\\ \\ / / | \\| |/ _ \\_ _| |   \\_ _| /_\\ " << "\n";
	gotoXY(x1 + 50, 3); cout << " | (_) | |_| / _ \\| .` | | |_\\ V /  | (__| __ | |_| |\\ V /| _|| .` | | _ \\/ _ \\ V /  | .` | (_) | |  | |) | | / _ \\" << "\n";
	gotoXY(x1 + 50, 4); cout << "  \\__\\_\\\\___/_/ \\_\\_|\\_| |____|_|    \\___|_||_|\\___/  |_| |___|_|\\_| |___/_/ \\_\\_|   |_|\\_|\\___/___| |___/___/_/ \\_\\" << "\n";
}
void menu()
{
	VeHCN(x1, y2, w1, 11, 11);
	gotoXY(x1 + 25, y2 + 1); SetColor(29); cout << "HUONG DAN";
	SetColor(11);
	gotoXY(x1 + 10, y2 + 3); cout << " SU DUNG 4 PHIM MUI TEN DE DI CHUYEN";
	gotoXY(x1 + 10, y2 + 4); cout << "INSERT: THEM"; 
	gotoXY(x1 + 10, y2 + 5); cout << "DELETE: XOA";
	gotoXY(x1 + 10, y2 + 6); cout << "F4    : SUA";
	
	gotoXY(x1 + 40, y2 + 4);  cout << "F2 : LUU";
	gotoXY(x1 + 40, y2 + 5);  cout << "F4 : SUA";
	gotoXY(x1 + 40, y2 + 6);  cout << "ESC: THOAT";

	gotoXY(x1 + 25, y2 + 8); SetColor(29); cout << "THONG BAO";

	VeHCN(x1, y2+12, w1, 20, 11);
	gotoXY(x1 + 28, y2 + 14); SetColor(29); cout << "MENU";
	SetColor(11);
	lineW(x1, y2 + 16, w1); gotoXY(x1 + 3, y2 + 17); cout << "                  QUAN LY MAY BAY";
	lineW(x1, y2 + 18, w1); gotoXY(x1 + 3, y2 + 19); cout << "                 QUAN LY CHUYEN BAY";
	lineW(x1, y2 + 20, w1); gotoXY(x1 + 3, y2 + 21); cout << "                   DAT VE MAY BAY";
	lineW(x1, y2 + 22, w1); gotoXY(x1 + 3, y2 + 23); cout << "                   HUY VE MAY BAY";
	lineW(x1, y2 + 24, w1); gotoXY(x1 + 3, y2 + 25); cout << "       DANH SACH HANH KHACH THUOC 1 CHUYEN BAY";
	lineW(x1, y2 + 26, w1); gotoXY(x1 + 3, y2 + 27); cout << "DANH SACH CHUYEN BAY BAY CUNG NGAY VA TOI CUNG DIA DIEM";
	lineW(x1, y2 + 28, w1); gotoXY(x1 + 3, y2 + 29); cout << "         DANH SACH VE TRONG CUA 1 CHUYEN BAY";
	lineW(x1, y2 + 30, w1); gotoXY(x1 + 3, y2 + 31); cout << "          THONG KE CHUYEN BAY DA HOAN THANH";
}
void Khung()
{
	TieuDe();
	VeHCN(178, 3, 30, 3,11);
	gotoXY(180, 4); cout << "Bui Tan Sang - N18DCCN169";
	gotoXY(180, 5); cout << "Do Thi Tam - N18DCCN178";
	SetColor(11); lineW(x1, y2-1, 210);
	menu();
}


