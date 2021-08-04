#pragma once
#include"MyLib.h"
#include"XuLyChuoi.h"
#include "GiaoDien.h"




char* block_char(int a, int x, int y)
{
	//Time();
	char* b;
	b = new char[a];
	b[0] = '\0';
	int i = 0;
	char c;
	gotoXY(x, y);
	//connhay_on();
	while (1)
	{
		c = _getch();

		if (i <= a && ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) || c == 32)
		{
			gotoXY(x + i, y);
			b[i] = c;
			cout << c;
			i++;
		}
		if (c == 8 && i > 0)
		{
			gotoXY(x + i - 1, y);
			cout << " ";
			gotoXY(x + i - 1, y);
			i--;
		}
		if (c == 27)
		{
			//connhay_off();
			b[0] = '.';
			b[1] = '\0';
			return b;
		}
		if (c == 13)
		{
			//connhay_off();
			b[i] = '\0';
			return b;
		}
	}
}
char* block_number(int a, int x, int y)
{
	//Time();
	char* b;
	b = new char[a];
	b[0] = '\0';
	int i = 0;
	char c;
	gotoXY(x, y);
	//connhay_on();
	while (1)
	{
		c = _getch();
		if (i <= a && c >= 48 && c <= 57)
		{
			gotoXY(x + i, y);
			b[i] = c;
			cout << c;
			i++;
		}
		if (c == 8 && i > 0)
		{
			gotoXY(x + i - 1, y);
			cout << " ";
			gotoXY(x + i - 1, y);
			i--;
		}
		if (c == 27)
		{
			//connhay_off();
			b[0] = '.';
			b[1] = '\0';
			return b;
		}
		if (c == 13)
		{
			//connhay_off();
			b[i] = '\0';
			return b;
		}
	}
}
char* block_and_char(int a, int x, int y)
{
	//Time();
	char* b;
	b = new char[a];
	b[0] = '\0';
	int i = 0;
	char c;
	gotoXY(x, y);
	//connhay_on();
	while (1)
	{
		c = _getch();
		if (i <= a && i <= a && c != 75 && c != 77 && c != -32 && c != 72 && c != 80 && ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) || c == 32 || c == 32)
		{
			if (c >= 97 && c <= 122)
			{
				gotoXY(x + i, y);
				b[i] = c - 32;
				cout << b[i];
			}
			else
			{
				gotoXY(x + i, y);
				b[i] = c;
				cout << c;
			}
			i++;
		}
		if (c == 27)
		{
			//connhay_off();
			b[0] = '.';
			b[1] = '\0';
			return b;
		}
		if (c == 8 && i > 0)
		{
			gotoXY(x + i - 1, y);
			cout << " ";
			gotoXY(x + i - 1, y);
			i--;
		}
		if (c == 13)
		{
			//connhay_off();
			b[i] = '\0';
			return b;
		}
	}
}