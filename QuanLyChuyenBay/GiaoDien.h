#pragma once
#include "MyLib.h"
using namespace std;
//================================khai bao thao tac phim: F2-save; F4 - edit; Insert - add================================
const int Up = -72, Down = -80, Left = -75, Right = -77, Enter = 13, ESC = 27, Delete = -83, Insert = -82, F2 = -60, F4 = -62, Space = 32, Backspace = 8;
const int x1 = 0, y1 = 4, x2 = 5;

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
	resizeConsole(1600, 800);//tuong duong khung 210x105
}

void lineW(int x, int y, double w)//nhap vao toa do diem dau, dài
{
	if (w <= 1) return;
	for (int ix = x+1; ix < x + w; ix++)
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
void box(int x, int y, int w, int h, int color)
{
	SetColor(color);
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y); cout << char(196);
		gotoXY(ix, y + h); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy); cout << char(179);
		gotoXY(x + w, iy); cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);
	gotoXY(x, y + h); cout << char(192);
}

void menu()
{
	
}
void Khung()
{
	int i;
	box(178, 0, 30, 3,11);
	gotoXY(180, 1); cout << "Bui Tan Sang - N18DCCN169";
	gotoXY(180, 2); cout << "Do Thi Tam - N18DCCN178";
	lineW(x1, y1, 210);
	box(x1, y1, 60, 42, 11);
	

	
}


/*void TieuDe()
{
	SetColor(35);
	gotoXY(x1, 0); cout << "  ___   __ __   ____  ____     _      __ __       __  __ __  __ __  __ __    ___  ____     ____    ____  __ __    ____    ___  ____    ___    ____   ____ " << "\n";
	gotoXY(x1, 1); cout << " /   \\ |  |  | /    ||    \\   | |    |  |  |     /  ]|  |  ||  |  ||  |  |  /  _]|    \\   |    \\  /    ||  |  |  |    \\  /   \\|    |  |   \\  |    | /    |" << "\n";
	gotoXY(x1, 2); cout << "|     ||  |  ||  o  ||  _  |  | |    |  |  |    /  / |  |  ||  |  ||  |  | /  [_ |  _  |  |  o  ||  o  ||  |  |  |  _  ||     ||  |   |    \\  |  | |  o  |" << "\n";
	gotoXY(x1, 3); cout << "|  Q  ||  |  ||     ||  |  |  | |___ |  ~  |   /  /  |  _  ||  |  ||  ~  ||    _]|  |  |  |     ||     ||  ~  |  |  |  ||  O  ||  |   |  D  | |  | |     |" << "\n";
	gotoXY(x1, 4); cout << "|     ||  :  ||  _  ||  |  |  |     ||___, |  /   \\_ |  |  ||  :  ||___, ||   [_ |  |  |  |  O  ||  _  ||___, |  |  |  ||     ||  |   |     | |  | |  _  |" << "\n";
	gotoXY(x1, 5); cout << "|     ||     ||  |  ||  |  |  |     ||     |  \\     ||  |  ||     ||     ||     ||  |  |  |     ||  |  ||     |  |  |  ||     ||  |   |     | |  | |  |  |" << "\n";
	gotoXY(x1, 6); cout << " \\__,_| \\__,_||__|__||__|__|  |_____||____/    \\____||__|__| \\__,_||____/ |_____||__|__|  |_____||__|__||____/   |__|__| \\___/|____|  |_____||____||__|__|" << "\n";
	gotoXY(x1 + 140, 8); cout << "Bui Tan Sang - N18DCCN169";
	gotoXY(x1 + 140, 9); cout << "Do Thi Tam - N18DCCN178";
	Khung();
}*/