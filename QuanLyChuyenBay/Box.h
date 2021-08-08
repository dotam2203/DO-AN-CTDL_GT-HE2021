#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "MyLib.h"
using namespace std;
#define boxx 4 //Vi tri x bat dau cua box
#define moveX  61;
#define boxy 1 //Vi tri y bat dau cua box
#define moveY  14;
#define boxs 111 //Box size

void Box_tong()
{
	SetColor(15);
	gotoXY(boxx, boxy); cout << char(218);
	for (int i = 1; i < boxs + 1; i++) cout << char(196);
	cout << char(191);
	int i = 1; int j = 1;
	for (int i = 1; i < 25; i++)
	{
		gotoXY(boxx, boxy + i);             cout << char(179);
		gotoXY(boxx + boxs + 1, boxy + i);  cout << char(179);
	}
	gotoXY(boxx, boxy + 25);               cout << char(192);
	for (int i = 1; i < boxs + 1; i++)    cout << char(196);
	cout << char(217);
}
void box_kex(int x, int y)
{
	int i = y;
	gotoXY(x, boxy + y); cout << char(194);
	while (i <= 25)
	{
		gotoXY(x, boxy + i);             cout << char(179);
		i++;
	}
	gotoXY(x, boxy + 25);
	cout << char(193);
}
void box_key(int y)
{
	gotoXY(boxx, y);
	for (int i = 1; i <= boxs + 1; i++)    cout << char(196);
	cout << char(180);
	gotoXY(boxx, y); cout << char(195);
}
void box_kexy(int x, int y, int s)
{
	gotoXY(x, y);
	for (int i = 1; i <= s + 1; i++) cout << char(196);
	cout << char(180);
	gotoXY(x, y); cout << char(195);
}
void box_noio(int x, int y)
{
	gotoXY(x, y); cout << char(197);
}
void box_noih(int x, int y)
{
	gotoXY(x, y); cout << char(194);
}
void box_nho(int x, int y, int s, int h)
{
	gotoXY(x, y); cout << char(218);
	for (int i = 1; i < s + 1; i++)
	{
		gotoXY(x + i, y);
		cout << char(196);
	}
	cout << char(191);
	for (int i = 1; i < h; i++)
	{
		gotoXY(x, y + i);             cout << char(179);
		gotoXY(x + s + 1, y + i);  cout << char(179);
	}
	for (int i = 1; i < s + 1; i++)
	{
		gotoXY(x + i, h + y);
		cout << char(196);
	}
	cout << char(217);
	gotoXY(x, y + h); cout << char(192);
}