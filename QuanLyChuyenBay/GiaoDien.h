#pragma once
#include "MyLib.h"
using namespace std;
//================================khai bao thao tac phim: F2-save; F4 - edit; Insert - add================================
const int Up = -72, Down = -80, Left = -75, Right = -77, Enter = 13, ESC = 27, Delete = -83, Insert = -82, F2 = -60, F4 = -62, Space = 32, Backspace = 8;
const int x1 = 0, y2 = 7 , x2 = 5;

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
	
}
void Khung()
{
	TieuDe();
	VeHCN(178, 3, 30, 3,11);
	gotoXY(180, 4); cout << "Bui Tan Sang - N18DCCN169";
	gotoXY(180, 5); cout << "Do Thi Tam - N18DCCN178";
	SetColor(11); lineW(x1, y2, 210);
	VeHCN(x1,y2,60,42,11);
	

	
}


