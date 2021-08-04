#pragma once
#include"KhaiBao.h"
#include"MayBay.h"
#include"mylib.h"
#include<cstring>
#include<ctime>
#include<time.h>
#include "Box.h"
#include"DocGhiFileSang.h"
#include"MayBay.h"
#include"GiaoDien.h"
#define MAX 100
void connhay_on();
void deleteBoxEDITCB();
void clearPoint();
void thongBaoString(string input);
void connhay_on1();
void ButtonCancel1(int color);
void deleteBoxAdd();
void cancel_flight(DS_CHUYEN_BAY& First, DS_MAYBAY& mb, chuyenbay* ds_cb[]);
void deleteCenter();
void TableListCB();
void boxAddCB();
void edit_fl(DS_CHUYEN_BAY& First, DS_MAYBAY& mb, chuyenbay* ds_cb[]);
void insert_last(DS_CHUYEN_BAY& first, chuyenbay x);
void TableList1();
char* block_number(int a, int x, int y);
char* block_char(int a, int x, int y);
char* block_and_char(int a, int x, int y);
void insert_cb(DS_CHUYEN_BAY& First, chuyen_bay& x);
void readfile_plane(DS_MAYBAY& mb);
void deleteBoxAdd1();
void clearSearch();
void result_plane(DS_MAYBAY& mb);
void ButtonThem1(int color);
void ButtonXoa1(int color);
void ButtonSua1(int color);
void ButtonESC1(int color);
void  box1(int x, int y, int w, int h, int mauNen);
void deleteListCB();
void clearThongBao();
void readfile_cb(DS_CHUYEN_BAY& First);
void writefile_flight(DS_CHUYEN_BAY& first);
int huy_chuyen(DS_CHUYEN_BAY& First, char* k, char* sh, chuyenbay* ds_cb[]);
int yes_no_fl(DS_CHUYEN_BAY& First);

void connhay_off2()//con nhay bien mat
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cci);
}
void connhay_on2()//con nhay xuat hien
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(hConsole, &cci);
}
DS_CHUYEN_BAY new_nodecb(void)
{
	DS_CHUYEN_BAY p = new ds_chuyen_bay;
	return p;
}
void initialize(DS_CHUYEN_BAY& First)
{
	First = NULL;
}
void clearlist(DS_CHUYEN_BAY& First)
{
	DS_CHUYEN_BAY p, q;
	p = First;
	while (First != NULL)
	{
		p = First;
		First = First->next;
		free(p);
	}
}
void Print_cb_to_arr(DS_CHUYEN_BAY& First, chuyenbay* ds_cb[])
{
	DS_MAYBAY mb;
	readfile_cb(First);
	DS_CHUYEN_BAY p;
	p = First;
	int i = 0;
	int stt = 0;
	if (p == NULL)return;
	while (p != NULL)
	{
		ds_cb[stt] = new chuyenbay;
		ds_cb[stt]->ds_ve.cmnd = new string[p->cb.ds_ve.n + 1];
		i = 0;
		while (p->cb.machuyenbay[i] != '\0')
		{
			ds_cb[stt]->machuyenbay[i] = p->cb.machuyenbay[i];
			i++;
			ds_cb[stt]->machuyenbay[i] = '\0';
		}
		p->cb.machuyenbay;
		i = 0;
		while (p->cb.sohieu[i] != '\0')
		{
			ds_cb[stt]->sohieu[i] = p->cb.sohieu[i];
			i++;
			ds_cb[stt]->sohieu[i] = '\0';
		}
		p->cb.sohieu;
		i = 0;
		while (p->cb.sanbay[i] != '\0')
		{
			ds_cb[stt]->sanbay[i] = p->cb.sanbay[i];
			i++;
			ds_cb[stt]->sanbay[i] = '\0';
		}
		p->cb.sanbay;
		ds_cb[stt]->ngay = p->cb.ngay;
		ds_cb[stt]->thang = p->cb.thang;
		ds_cb[stt]->nam = p->cb.nam;
		ds_cb[stt]->gio = p->cb.gio;
		ds_cb[stt]->phut = p->cb.phut;
		ds_cb[stt]->ds_ve.n = p->cb.ds_ve.n;
		ds_cb[stt]->trangthai = p->cb.trangthai;
		ds_cb[stt]->ds_ve.sl_con = p->cb.ds_ve.sl_con;
		ds_cb[stt]->ds_ve.sl_da_ban = p->cb.ds_ve.sl_da_ban;
		for (int k = 1; k < ds_cb[stt]->ds_ve.n + 1; k++)
		{
			ds_cb[stt]->ds_ve.cmnd[k] = p->cb.ds_ve.cmnd[k];
		}
		stt++;
		p = p->next;
	}
}
int dem(DS_CHUYEN_BAY& First)
{
	DS_CHUYEN_BAY p;
	int i = 0;
	p = First;
	if (p == NULL)return -1;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
void trang_thai(int t, int x, int y)
{
	if (t == 0)
	{
		gotoXY(x, y); cout << "0.Huy chuyen";
	}
	else if (t == 1)
	{
		gotoXY(x, y); cout << "1.Con ve";
	}
	else if (t == 2)
	{
		gotoXY(x, y); cout << "0.Het ve";
	}
	else if (t == 3)
	{
		gotoXY(x, y); cout << "3.Hoan tat";
	}
}
int result_flight(DS_CHUYEN_BAY& First, chuyenbay* ds_cb[])
{
	int movX = 60, movY = 8;
	DS_MAYBAY mb;
	int trang = 0;
	int tong = 0;
	if (dem(First) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (dem(First)) / 18 + 1;
	}

	readfile_plane(mb);
	if (First == NULL)
	{
		cout << "chua co chuyen bay nao";
		return 0;
	}
	gotoXY(5 + movX, 5 + movY);
	cout << "STT";
	gotoXY(10 + movX, 5 + movY);
	cout << "loai may bay";
	gotoXY(25 + movX, 5 + movY);
	cout << "Ma chuyen bay";
	gotoXY(40 + movX, 5 + movY);
	cout << "so hieu";
	gotoXY(55 + movX, 5 + movY);
	cout << "San bay den";
	gotoXY(70 + movX, 5 + movY);
	cout << "Ngay";
	gotoXY(75 + movX, 5 + movY);
	cout << "Thang";
	gotoXY(81 + movX, 5 + movY);
	cout << "Nam";
	gotoXY(88 + movX, 5 + movY);
	cout << "Gio";
	gotoXY(92 + movX, 5 + movY);
	cout << "Phut";
	gotoXY(97 + movX, 5 + movY);
	cout << "So ve";
	gotoXY(104 + movX, 5 + movY);
	cout << "Trang thai";
	int k = 7 + movY;
	for (int i = trang * 18 + 0; i < dem(First) && i <= 18 + trang * 18; i++)
	{
		gotoXY(5 + movX, k);
		cout << i;
		for (int j = 0; j < mb.sl - 1; j++)
		{
			if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
			{
				gotoXY(10 + movX, k);
				cout << mb.dsmaybay[j]->loaimaybay;
			}
		}
		//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
		gotoXY(25 + movX, k);
		cout << ds_cb[i]->machuyenbay;
		gotoXY(40 + movX, k);
		cout << ds_cb[i]->sohieu;
		gotoXY(55 + movX, k);
		cout << ds_cb[i]->sanbay;
		gotoXY(70 + movX, k);
		cout << ds_cb[i]->ngay;
		gotoXY(77 + movX, k);
		cout << ds_cb[i]->thang;
		gotoXY(81 + movX, k);
		cout << ds_cb[i]->nam;
		gotoXY(88 + movX, k);
		cout << ds_cb[i]->gio;
		gotoXY(93 + movX, k);
		cout << ds_cb[i]->phut;
		gotoXY(98 + movX, k);
		cout << ds_cb[i]->ds_ve.n;
		gotoXY(108 + movX, k); trang_thai(ds_cb[i]->trangthai, 104 + movX, k);
		//cout << ds_cb[i]->trangthai;
		k++;
	}
	return 0;
}
void xem_cb(DS_CHUYEN_BAY& First, DS_MAYBAY& mb, chuyen_bay* ds_cb[])
{
	int movX = 60, movY = 8, movSX = 105, movSY = -2;
back:
	clearPoint();
	TableListCB();
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;

	int a[MAX];


	readfile_cb(First);
	readfile_plane(mb);
	Print_cb_to_arr(First, ds_cb);
	result_flight(First, ds_cb);

	int trang = 0;
	int tong = 0;
	if (dem(First) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (dem(First)) / 18 + 1;
	}

	//gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
	//gotoXY(15 + movX, 3 + movY); cout << "Search_CB:";
	connhay_on2();
	do
	{
		ButtonThem1(255);
		ButtonCancel1(255);

		ButtonSua1(255);
		ButtonESC1(255);
		SetbgColor(0);
		c = _getch();
		connhay_on2();
		if (c == 59) {
			chuyen_bay cb;
			ButtonThem1(1);
			SetbgColor(0);
			deleteListCB();
			insert_cb(First, cb);
			deleteBoxAdd1();
			clearSearch();
			clearThongBao();

			goto back;
		}
		if (c == 83) {
			ButtonCancel1(1);
			SetbgColor(0);
			deleteListCB();
			//system("cls");
			cancel_flight(First, mb, ds_cb);
			//delete_plane(mb, First);
			deleteBoxAdd1();
			clearSearch();
			clearThongBao();
			goto back;
		}
		if (c == 61) {
			ButtonSua1(1);
			SetbgColor(0);
			deleteListCB();
			edit_fl(First, mb, ds_cb);
			//search_edit(mb, First);
			deleteBoxAdd1();
			clearSearch();
			clearThongBao();
			goto back;
		}




		if (i <= 14 && c >= 48 && c <= 122 && c != 59 && c != 83 && c != 61 || c == 32)
		{
			u = 0;
			if (c >= 97 && c <= 122)
			{
				gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
				b[i] = c - 32;
				cout << b[i];
			}
			else
			{
				gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
				b[i] = c;
				cout << c;
			}
			i++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 14; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 13; i++)
				{
					gotoXY(25 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 8; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 20; i++)
				{
					gotoXY(48 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(69 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(75 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(81 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(87 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(92 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(97 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(103 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 12; i++)
				{
					gotoXY(104 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off2();
			int l = 7 + movY;
			for (int i = 0; i < dem(First); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (ds_cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 26)break;
						gotoXY(5 + movX, l);
						cout << i;
						for (int j = 0; j < mb.sl - 1; j++)
						{
							if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoXY(10 + movX, l);
								cout << mb.dsmaybay[j]->loaimaybay;
							}
						}
						//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
						gotoXY(25 + movX, l);
						cout << ds_cb[i]->machuyenbay;
						gotoXY(40 + movX, l);
						cout << ds_cb[i]->sohieu;
						gotoXY(55 + movX, l);
						cout << ds_cb[i]->sanbay;
						gotoXY(70 + movX, l);
						cout << ds_cb[i]->ngay;
						gotoXY(77 + movX, l);
						cout << ds_cb[i]->thang;
						gotoXY(81 + movX, l);
						cout << ds_cb[i]->nam;
						gotoXY(88 + movX, l);
						cout << ds_cb[i]->gio;
						gotoXY(93 + movX, l);
						cout << ds_cb[i]->phut;
						gotoXY(98 + movX, l);
						cout << ds_cb[i]->ds_ve.n;
						trang_thai(ds_cb[i]->trangthai, 104 + movX, l);
						l++;
					}
				}
			}
		}
		if (c == 8 && i > 0)
		{
			u = 0;
			gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
			cout << " ";
			gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off2();
			int k = 7 + movY;
			for (int i = 0; i < dem(First); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (ds_cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 26 + movY)break;
						gotoXY(5 + movX, k);
						cout << i;
						for (int j = 0; j < mb.sl - 1; j++)
						{
							if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoXY(10 + movX, k);
								cout << mb.dsmaybay[j]->loaimaybay;
							}
						}
						gotoXY(25 + movX, k);
						cout << ds_cb[i]->machuyenbay;
						gotoXY(40 + movX, k);
						cout << ds_cb[i]->sohieu;
						gotoXY(55 + movX, k);
						cout << ds_cb[i]->sanbay;
						gotoXY(70 + movX, k);
						cout << ds_cb[i]->ngay;
						gotoXY(77 + movX, k);
						cout << ds_cb[i]->thang;
						gotoXY(81 + movX, k);
						cout << ds_cb[i]->nam;
						gotoXY(88 + movX, k);
						cout << ds_cb[i]->gio;
						gotoXY(93 + movX, k);
						cout << ds_cb[i]->phut;
						gotoXY(98 + movX, k);
						cout << ds_cb[i]->ds_ve.n;
						trang_thai(ds_cb[i]->trangthai, 104 + movX, k);
						k++;
					}
				}
				//gotoXY(27 + i, 3);
				//connhay_on2();
			}
			if (b[0] == '\0')
			{
				result_flight(First, ds_cb);
				connhay_off2();
			}
			gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
		}
		if (c == 27)return;
	} while (c != 13);
	connhay_off2();
	if (u == 0)
	{
		u = dem(First);
		for (int i = 0; i < u; i++)
		{
			a[i] = i;
		}
	}
	int f;
	int p = 0;

key://============================================================================================================//

	//system("cls");
	deleteCenter();
}
void edit_fl(DS_CHUYEN_BAY& First, DS_MAYBAY& mb, chuyen_bay* ds_cb[])
{

	int movX = 60, movY = 8, movSX = 105, movSY = -2;
back:
	deleteBoxEDITCB();
	clearPoint();
	boxAddCB();
	TableListCB();
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	DS_CHUYEN_BAY v;
	int a[MAX];
	int years;
	int days;
	int months;
	int hours;
	int mins;
	time_t baygio = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &baygio);
	years = 1900 + ltm->tm_year;
	months = 1 + ltm->tm_mon;
	days = ltm->tm_mday;
	hours = ltm->tm_hour;
	mins = 1 + ltm->tm_min;

	readfile_cb(First);
	readfile_plane(mb);
	Print_cb_to_arr(First, ds_cb);
	result_flight(First, ds_cb);

	int trang = 0;
	int tong = 0;
	if (dem(First) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (dem(First)) / 18 + 1;
	}

	gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
	//gotoXY(15 + movX, 3 + movY); cout << "Search_CB:";
	connhay_on2();
	do
	{

		c = _getch();
		connhay_on2();
		if (i <= 14 && c >= 48 && c <= 122 && c != 59 && c != 83 && c != 61 || c == 32)
		{
			u = 0;
			if (c >= 97 && c <= 122)
			{
				gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
				b[i] = c - 32;
				cout << b[i];
			}
			else
			{
				gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
				b[i] = c;
				cout << c;
			}
			i++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 14; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 13; i++)
				{
					gotoXY(25 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 8; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 20; i++)
				{
					gotoXY(48 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(69 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(75 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(81 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(87 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(92 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(97 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(103 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 12; i++)
				{
					gotoXY(104 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off2();
			int l = 7 + movY;
			for (int i = 0; i < dem(First); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (ds_cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 26)break;
						gotoXY(5 + movX, l);
						cout << i;
						for (int j = 0; j < mb.sl - 1; j++)
						{
							if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoXY(10 + movX, l);
								cout << mb.dsmaybay[j]->loaimaybay;
							}
						}
						//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
						gotoXY(25 + movX, l);
						cout << ds_cb[i]->machuyenbay;
						gotoXY(40 + movX, l);
						cout << ds_cb[i]->sohieu;
						gotoXY(55 + movX, l);
						cout << ds_cb[i]->sanbay;
						gotoXY(70 + movX, l);
						cout << ds_cb[i]->ngay;
						gotoXY(77 + movX, l);
						cout << ds_cb[i]->thang;
						gotoXY(81 + movX, l);
						cout << ds_cb[i]->nam;
						gotoXY(88 + movX, l);
						cout << ds_cb[i]->gio;
						gotoXY(93 + movX, l);
						cout << ds_cb[i]->phut;
						gotoXY(98 + movX, l);
						cout << ds_cb[i]->ds_ve.n;
						trang_thai(ds_cb[i]->trangthai, 104 + movX, l);
						l++;
					}
				}
			}
		}
		if (c == 8 && i > 0)
		{
			u = 0;
			gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
			cout << " ";
			gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off2();
			int k = 7 + movY;
			for (int i = 0; i < dem(First); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (ds_cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 26 + movY)break;
						gotoXY(5 + movX, k);
						cout << i;
						for (int j = 0; j < mb.sl - 1; j++)
						{
							if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoXY(10 + movX, k);
								cout << mb.dsmaybay[j]->loaimaybay;
							}
						}
						gotoXY(25 + movX, k);
						cout << ds_cb[i]->machuyenbay;
						gotoXY(40 + movX, k);
						cout << ds_cb[i]->sohieu;
						gotoXY(55 + movX, k);
						cout << ds_cb[i]->sanbay;
						gotoXY(70 + movX, k);
						cout << ds_cb[i]->ngay;
						gotoXY(77 + movX, k);
						cout << ds_cb[i]->thang;
						gotoXY(81 + movX, k);
						cout << ds_cb[i]->nam;
						gotoXY(88 + movX, k);
						cout << ds_cb[i]->gio;
						gotoXY(93 + movX, k);
						cout << ds_cb[i]->phut;
						gotoXY(98 + movX, k);
						cout << ds_cb[i]->ds_ve.n;
						trang_thai(ds_cb[i]->trangthai, 104 + movX, k);
						k++;
					}
				}
				//gotoXY(27 + i, 3);
				//connhay_on2();
			}
			if (b[0] == '\0')
			{
				result_flight(First, ds_cb);
				connhay_off2();
			}
			gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
		}
		if (c == 27)return;
	} while (c != 13);

	connhay_off2();
	if (u == 0)
	{
		u = dem(First);
		for (int i = 0; i < u; i++)
		{
			a[i] = i;
		}
	}
	int f;
	int p = 0;

key://============================================================================================================//
	f = 7;

	gotoXY(0 + movX + 1, 7 + movY); cout << ">";
	do
	{
		gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f <= 7 && tong > 1 && trang > 0 && c == 72)
		{
			gotoXY(0 + movX, 7 + movY);
			cout << "   ";
			f = 25;
			trang--;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 14; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 13; i++)
				{
					gotoXY(25 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 8; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 20; i++)
				{
					gotoXY(48 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(69 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(75 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(81 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(87 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(92 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(97 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(103 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 12; i++)
				{
					gotoXY(104 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			k = 7 + movY;
			for (int i = trang * 18 + 0; i < dem(First) && i <= 18 + trang * 18; i++)
			{
				gotoXY(5 + movX, k);
				cout << i;
				for (int j = 0; j < mb.sl - 1; j++)
				{
					if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoXY(10 + movX, k);
						cout << mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
				gotoXY(25 + movX, k);
				cout << ds_cb[i]->machuyenbay;
				gotoXY(40 + movX, k);
				cout << ds_cb[i]->sohieu;
				gotoXY(55 + movX, k);
				cout << ds_cb[i]->sanbay;
				gotoXY(70 + movX, k);
				cout << ds_cb[i]->ngay;
				gotoXY(77 + movX, k);
				cout << ds_cb[i]->thang;
				gotoXY(81 + movX, k);
				cout << ds_cb[i]->nam;
				gotoXY(88 + movX, k);
				cout << ds_cb[i]->gio;
				gotoXY(93 + movX, k);
				cout << ds_cb[i]->phut;
				gotoXY(98 + movX, k);
				cout << ds_cb[i]->ds_ve.n;
				trang_thai(ds_cb[i]->trangthai, 104 + movX, k);
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
		if (f != 7)
		{
			gotoXY(0 + movX + 1, f - 1 + movY);
			printf(" ");
		}
		if (f != 7 + u)
		{
			gotoXY(0 + movX + 1, f + 1 + movY);
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
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 14; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 13; i++)
				{
					gotoXY(25 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 8; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 20; i++)
				{
					gotoXY(48 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(69 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(75 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(81 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(87 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(92 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(97 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(103 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 12; i++)
				{
					gotoXY(104 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			k = 7 + movY;
			for (int i = trang * 18 + 0; i < dem(First) && i <= 18 + trang * 18; i++)
			{
				gotoXY(5 + movX, k);
				cout << i;
				for (int j = 0; j < mb.sl - 1; j++)
				{
					if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoXY(10 + movX, k);
						cout << mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
				gotoXY(25 + movX, k);
				cout << ds_cb[i]->machuyenbay;
				gotoXY(40 + movX, k);
				cout << ds_cb[i]->sohieu;
				gotoXY(55 + movX, k);
				cout << ds_cb[i]->sanbay;
				gotoXY(70 + movX, k);
				cout << ds_cb[i]->ngay;
				gotoXY(77 + movX, k);
				cout << ds_cb[i]->thang;
				gotoXY(81 + movX, k);
				cout << ds_cb[i]->nam;
				gotoXY(88 + movX, k);
				cout << ds_cb[i]->gio;
				gotoXY(93 + movX, k);
				cout << ds_cb[i]->phut;
				gotoXY(98 + movX, k);
				cout << ds_cb[i]->ds_ve.n;
				trang_thai(ds_cb[i]->trangthai, 104 + movX, k);
				k++;
			}
			goto key;
		}
		cout << "  ";
		gotoXY(0 + movX + 1, f + movY);
		cout << ">";
	} while (c != 13);
	if (ds_cb[a[p]]->trangthai == 3) {
		thongBaoString("CHUYEN BAY DA HOAN TAT, KHONG THE SUA CHUYEN");
		//khongHuy = true;
		goto back;
	}
	else if (ds_cb[a[p]]->trangthai == 0) {
		thongBaoString("CHUYEN BAY DA HUY !!!, KHONG THE SUA");
		//khongHuy = true;
		goto back;
	}
	//system("cls");
	//deleteCenter();

	deleteBoxEDITCB();
	int moX = 145;

	f = 13;
main:

	boxAddCB();


	gotoXY(35 + moX, 13); cout << "Ma chuyen bay: " << ds_cb[a[p]]->machuyenbay;
	gotoXY(35 + moX, 14); cout << "San bay den: " << ds_cb[a[p]]->sanbay;

	gotoXY(35 + moX, 15); cout << "Ngay: " << ds_cb[a[p]]->ngay;

	gotoXY(35 + moX, 16); cout << "Thang: " << ds_cb[a[p]]->thang;

	gotoXY(35 + moX, 17); cout << "Nam: " << ds_cb[a[p]]->nam;

	gotoXY(35 + moX, 18); cout << "Gio: " << ds_cb[a[p]]->gio;

	gotoXY(35 + moX, 19); cout << "Phut: " << ds_cb[a[p]]->phut;
	gotoXY(35 + moX, 20); cout << "Luu va Thoat";
	int setX = -38;
	gotoXY(70 + moX + setX, f); cout << "=>";
	do
	{
		c = _getch();
		if (c == 72)
		{
			if (f > 13)
			{
				f = f - 1;
			}
		}
		else if (c == 80)
		{
			if (f < 20)
			{
				f += 1;
			}

		}
		if (c == 27)
		{
			//system("cls");
			goto back;
		}
		if (f != 13)
		{
			gotoXY(70 + moX + setX, f - 1);
			cout << "  ";
		}
		if (f != 20)
		{
			gotoXY(70 + moX + setX, f + 1);
			cout << "  ";
		}
		//cout << "  ";
		gotoXY(70 + moX + setX, f);
		cout << "=>";
	} while (c != 13);
	switch (f)
	{
	case 13:
	{
	xuat:

		int j = 0;
		char* tmp = new char[100];
		for (int j = 0; j <= 20; j++)
		{
			gotoXY(49 + j + moX, 13); cout << " ";
		}
		boxAddCB();
		//gotoXY(53, 8);
		int n = 0;
		do {
			gotoXY(50 + moX, 13); connhay_on();
			tmp = block_and_char(15, 50 + moX, 13);
		} while (tmp[0] == '\0');
		if (tmp[0] == '.')
		{
			goto main;
		}
		while (tmp[n] != '\0')
		{
			ds_cb[a[p]]->machuyenbay[n] = tmp[n];
			n++;
			ds_cb[a[p]]->machuyenbay[n] = '\0';
		}
		v = First;
		while (v != NULL)
		{
			if (_strcmpi(v->cb.machuyenbay, ds_cb[a[p]]->machuyenbay) == 0 && _strcmpi(v->cb.sohieu, ds_cb[a[p]]->sohieu) == 0)
			{
				thongBaoString("MA CHUYEN BAY DA CO TRONG DANH SACH!!!");
				goto xuat;
			}
			v = v->next;
		}
		break;
	}
	case 14:
	{

		int n = 0;
		int j = 0;
		char* tmp = new char[100];
		for (int j = 0; j <= 20; j++)
		{
			gotoXY(47 + j + moX, 14); cout << " ";
		}
		boxAddCB();
		do {
			gotoXY(48 + moX, 14); connhay_on();
			tmp = block_char(100, 48 + moX, 14);
		} while (tmp[0] == '\0');
		if (tmp[0] == '.')
		{
			goto main;
		}
		while (tmp[n] != '\0')
		{
			ds_cb[a[p]]->sanbay[n] = tmp[n];
			n++;
			ds_cb[a[p]]->sanbay[n] = '\0';
		}
	}
	break;
	case 15:
	{

		char* tmp = new char[100];
		do
		{
			for (int j = 0; j <= 20; j++)
			{
				gotoXY(40 + j + moX, 15); cout << " ";
			}
			boxAddCB();
			gotoXY(40 + moX, 15); connhay_on();
			tmp = block_number(1, 40 + moX, 15);
			if (ds_cb[a[p]]->thang == months && ds_cb[a[p]]->nam == years && atoi(tmp) < days || atoi(tmp) > 31)
			{
				//gotoXY(94 + moX, 4); cout << "khong hop le";
				thongBaoString("THOI GIAN KHONG HOP LE !!!");
				//gotoXY(94 + moX, 5); cout << "nhap lai";

			}
		} while (tmp[0] == '\0' || ds_cb[a[p]]->thang == months && ds_cb[a[p]]->nam == years && atoi(tmp) < days || atoi(tmp) > 31);
		if (tmp[0] == '.')
		{
			goto main;
		}
		ds_cb[a[p]]->ngay = atoi(tmp);
		break;
	}
	case 16:
	{

		char* tmp = new char[100];
		do {
			for (int j = 0; j <= 20; j++)
			{
				gotoXY(41 + j + moX, 16); cout << " ";
			}
			boxAddCB();
			gotoXY(41 + moX, 16); connhay_on();
			tmp = block_number(1, 41 + moX, 16);
			if (atoi(tmp) < months && ds_cb[a[p]]->nam == years || atoi(tmp) > 12)
			{
				thongBaoString("THOI GIAN KHONG HOP LE");

			}
		} while (tmp[0] == '\0' || atoi(tmp) < months && ds_cb[a[p]]->nam == years || atoi(tmp) > 12);
		if (tmp[0] == '.')
		{
			goto main;
		}
		ds_cb[a[p]]->thang = atoi(tmp);
		break;
	}
	case 17:
	{

		char* tmp = new char[100];
		do {

			for (int j = 0; j <= 20; j++)
			{
				gotoXY(40 + j + moX, 17); cout << " ";
			}
			boxAddCB();
			gotoXY(40 + moX, 17); connhay_on();
			tmp = block_number(3, 40 + moX, 17);
			if (tmp[0] == '.')goto main;
			if (atoi(tmp) < years && tmp[0] != '\0')
			{
				thongBaoString("THOI GIAN KHONG HOP LE");
			}
		} while (tmp[0] == '\0' || atoi(tmp) < years || atoi(tmp) < 1000);
		ds_cb[a[p]]->nam = atoi(tmp);
		break;
	}
	case 18:
	{
	back1:
		v = First;

		char* tmp = new char[100];
		do
		{
			for (int j = 0; j <= 20; j++)
			{
				gotoXY(40 + j + moX, 18); cout << " ";
			}
			boxAddCB();
			gotoXY(40 + moX, 18); connhay_on();
			tmp = block_number(1, 40 + moX, 18);
			if (days == ds_cb[a[p]]->ngay && months == ds_cb[a[p]]->thang && years == ds_cb[a[p]]->nam && atoi(tmp) - hours < 0 || atoi(tmp)>24)
			{
				thongBaoString("THOI GIAN KHONG HOP LE");
				for (int i = 0; i <= 15; i++)
				{
					gotoXY(94 + i + moX, 4); cout << " ";
					gotoXY(94 + i + moX, 5); cout << " ";
				}
			}
		} while (tmp[0] == '\0' || days == ds_cb[a[p]]->ngay && months == ds_cb[a[p]]->thang && years == ds_cb[a[p]]->nam && atoi(tmp) - hours < 0 || atoi(tmp)>24);
		if (tmp[0] == '.')
		{
			goto main;
		}
		while (v != NULL)
		{
			if (_strcmpi(v->cb.sohieu, ds_cb[a[p]]->sohieu) == 0 && _strcmpi(v->cb.machuyenbay, ds_cb[a[p]]->machuyenbay) != 0 /*|| _strcmpi(v->cb.machuyenbay, ds_cb[a[p]]->machuyenbay) == -1*/)
			{
				if (v->cb.ngay == ds_cb[a[p]]->ngay && v->cb.thang == ds_cb[a[p]]->thang && v->cb.nam == ds_cb[a[p]]->nam && abs(atoi(tmp) - v->cb.gio) < 4)
				{
					thongBaoString("DA CO CHUYEN BAY CACH DAY 4 GIO");
					goto back1;
				}
			}
			v = v->next;
		}
		ds_cb[a[p]]->gio = atoi(tmp);
		break;
	}
	case 19:
	{

		char* tmp = new char[100];
		do {
			for (int j = 0; j <= 20; j++)
			{
				gotoXY(40 + j + moX, 19); cout << " ";
			}
			boxAddCB();
			gotoXY(40 + moX, 19); connhay_on();
			tmp = block_number(1, 40 + moX, 19);
			if (atoi(tmp) > 60)
			{
				thongBaoString("KHONG HOP LE");
			}
		} while (tmp[0] == '\0' || atoi(tmp) > 60);
		if (tmp[0] == '.')
		{
			goto main;
		}
		ds_cb[a[p]]->phut = atoi(tmp);
		break;
	}
	case 20:
		//system("cls");
		int k;
		chuyenbay x;
		k = dem(First);
		clearlist(First);
		for (int i = 0; i < k; i++)
		{
			strcpy_s(x.machuyenbay, ds_cb[i]->machuyenbay);
			strcpy_s(x.sohieu, ds_cb[i]->sohieu);
			strcpy_s(x.sanbay, ds_cb[i]->sanbay);
			x.ngay = ds_cb[i]->ngay;
			x.thang = ds_cb[i]->thang;
			x.nam = ds_cb[i]->nam;
			x.gio = ds_cb[i]->gio;
			x.phut = ds_cb[i]->phut;
			x.trangthai = ds_cb[i]->trangthai;
			x.ds_ve.n = ds_cb[i]->ds_ve.n;
			x.ds_ve.sl_con = ds_cb[i]->ds_ve.sl_con;
			x.ds_ve.sl_da_ban = ds_cb[i]->ds_ve.sl_da_ban;
			x.ds_ve.cmnd = ds_cb[i]->ds_ve.cmnd;
			insert_last(First, x);
		}
		deleteBoxAdd();
		yes_no_fl(First);
		goto back;
	}
	goto main;

}
void clearPoint() {
	for (int i = 15; i <= 25; i++) {
		gotoXY(61, i); cout << " ";
	}

}
void cancel_flight(DS_CHUYEN_BAY& First, DS_MAYBAY& mb, chuyen_bay* ds_cb[])
{

	int movX = 60, movY = 8, movSX = 105, movSY = -2;
back:
	clearPoint();
	TableListCB();
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;

	int a[MAX];
	int years;
	int days;
	int months;
	int hours;
	int mins;
	time_t baygio = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &baygio);
	years = 1900 + ltm->tm_year;
	months = 1 + ltm->tm_mon;
	days = ltm->tm_mday;
	hours = ltm->tm_hour;
	mins = 1 + ltm->tm_min;
	//deleteListCB();

	DS_CHUYEN_BAY v;


	readfile_cb(First);
	readfile_plane(mb);
	Print_cb_to_arr(First, ds_cb);
	result_flight(First, ds_cb);

	int trang = 0;
	int tong = 0;
	if (dem(First) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else
	{
		tong = (dem(First)) / 18 + 1;
	}

	gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
	//gotoXY(15 + movX, 3 + movY); cout << "Search_CB:";
	connhay_on2();
	do
	{


		c = _getch();
		connhay_on2();
		if (i <= 14 && c >= 48 && c <= 122 && c != 59 && c != 83 && c != 61 || c == 32)
		{
			u = 0;
			if (c >= 97 && c <= 122)
			{
				gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
				b[i] = c - 32;
				cout << b[i];
			}
			else
			{
				gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
				b[i] = c;
				cout << c;
			}
			i++;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 14; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 13; i++)
				{
					gotoXY(25 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 8; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 20; i++)
				{
					gotoXY(48 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(69 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(75 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(81 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(87 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(92 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(97 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(103 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 12; i++)
				{
					gotoXY(104 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off2();
			int l = 7 + movY;
			for (int i = 0; i < dem(First); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (ds_cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 26)break;
						gotoXY(5 + movX, l);
						cout << i;
						for (int j = 0; j < mb.sl - 1; j++)
						{
							if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoXY(10 + movX, l);
								cout << mb.dsmaybay[j]->loaimaybay;
							}
						}
						//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
						gotoXY(25 + movX, l);
						cout << ds_cb[i]->machuyenbay;
						gotoXY(40 + movX, l);
						cout << ds_cb[i]->sohieu;
						gotoXY(55 + movX, l);
						cout << ds_cb[i]->sanbay;
						gotoXY(70 + movX, l);
						cout << ds_cb[i]->ngay;
						gotoXY(77 + movX, l);
						cout << ds_cb[i]->thang;
						gotoXY(81 + movX, l);
						cout << ds_cb[i]->nam;
						gotoXY(88 + movX, l);
						cout << ds_cb[i]->gio;
						gotoXY(93 + movX, l);
						cout << ds_cb[i]->phut;
						gotoXY(98 + movX, l);
						cout << ds_cb[i]->ds_ve.n;
						trang_thai(ds_cb[i]->trangthai, 104 + movX, l);
						l++;
					}
				}
			}
		}
		if (c == 8 && i > 0)
		{
			u = 0;
			gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
			cout << " ";
			gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off2();
			int k = 7 + movY;
			for (int i = 0; i < dem(First); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (ds_cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 26 + movY)break;
						gotoXY(5 + movX, k);
						cout << i;
						for (int j = 0; j < mb.sl - 1; j++)
						{
							if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoXY(10 + movX, k);
								cout << mb.dsmaybay[j]->loaimaybay;
							}
						}
						gotoXY(25 + movX, k);
						cout << ds_cb[i]->machuyenbay;
						gotoXY(40 + movX, k);
						cout << ds_cb[i]->sohieu;
						gotoXY(55 + movX, k);
						cout << ds_cb[i]->sanbay;
						gotoXY(70 + movX, k);
						cout << ds_cb[i]->ngay;
						gotoXY(77 + movX, k);
						cout << ds_cb[i]->thang;
						gotoXY(81 + movX, k);
						cout << ds_cb[i]->nam;
						gotoXY(88 + movX, k);
						cout << ds_cb[i]->gio;
						gotoXY(93 + movX, k);
						cout << ds_cb[i]->phut;
						gotoXY(98 + movX, k);
						cout << ds_cb[i]->ds_ve.n;
						trang_thai(ds_cb[i]->trangthai, 104 + movX, k);
						k++;
					}
				}
				//gotoXY(27 + i, 3);
				//connhay_on2();
			}
			if (b[0] == '\0')
			{
				result_flight(First, ds_cb);
				connhay_off2();
			}
			gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
		}
		if (c == 27)return;
		
	} while (c != 13);
	connhay_off2();
	if (u == 0)
	{
		u = dem(First);
		for (int i = 0; i < u; i++)
		{
			a[i] = i;
		}
	}
	int f;
	int p = 0;

key://============================================================================================================//
	f = 7;

	gotoXY(0 + movX + 1, 7 + movY); cout << ">";
	do
	{
		gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f <= 7 && tong > 1 && trang > 0 && c == 72)
		{
			gotoXY(0 + movX, 7 + movY);
			cout << "   ";
			f = 25;
			trang--;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 14; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 13; i++)
				{
					gotoXY(25 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 8; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 20; i++)
				{
					gotoXY(48 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(69 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(75 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(81 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(87 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(92 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(97 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(103 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 12; i++)
				{
					gotoXY(104 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			k = 7 + movY;
			for (int i = trang * 18 + 0; i < dem(First) && i <= 18 + trang * 18; i++)
			{
				gotoXY(5 + movX, k);
				cout << i;
				for (int j = 0; j < mb.sl - 1; j++)
				{
					if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoXY(10 + movX, k);
						cout << mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
				gotoXY(25 + movX, k);
				cout << ds_cb[i]->machuyenbay;
				gotoXY(40 + movX, k);
				cout << ds_cb[i]->sohieu;
				gotoXY(55 + movX, k);
				cout << ds_cb[i]->sanbay;
				gotoXY(70 + movX, k);
				cout << ds_cb[i]->ngay;
				gotoXY(77 + movX, k);
				cout << ds_cb[i]->thang;
				gotoXY(81 + movX, k);
				cout << ds_cb[i]->nam;
				gotoXY(88 + movX, k);
				cout << ds_cb[i]->gio;
				gotoXY(93 + movX, k);
				cout << ds_cb[i]->phut;
				gotoXY(98 + movX, k);
				cout << ds_cb[i]->ds_ve.n;
				trang_thai(ds_cb[i]->trangthai, 104 + movX, k);
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
		if (f != 7)
		{
			gotoXY(0 + movX + 1, f - 1 + movY);
			printf(" ");
		}
		if (f != 7 + u)
		{
			gotoXY(0 + movX + 1, f + 1 + movY);
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
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 14; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 13; i++)
				{
					gotoXY(25 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 8; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 20; i++)
				{
					gotoXY(48 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(69 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(75 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(81 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(87 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(92 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(97 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(103 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 12; i++)
				{
					gotoXY(104 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			k = 7 + movY;
			for (int i = trang * 18 + 0; i < dem(First) && i <= 18 + trang * 18; i++)
			{
				gotoXY(5 + movX, k);
				cout << i;
				for (int j = 0; j < mb.sl - 1; j++)
				{
					if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoXY(10 + movX, k);
						cout << mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
				gotoXY(25 + movX, k);
				cout << ds_cb[i]->machuyenbay;
				gotoXY(40 + movX, k);
				cout << ds_cb[i]->sohieu;
				gotoXY(55 + movX, k);
				cout << ds_cb[i]->sanbay;
				gotoXY(70 + movX, k);
				cout << ds_cb[i]->ngay;
				gotoXY(77 + movX, k);
				cout << ds_cb[i]->thang;
				gotoXY(81 + movX, k);
				cout << ds_cb[i]->nam;
				gotoXY(88 + movX, k);
				cout << ds_cb[i]->gio;
				gotoXY(93 + movX, k);
				cout << ds_cb[i]->phut;
				gotoXY(98 + movX, k);
				cout << ds_cb[i]->ds_ve.n;
				trang_thai(ds_cb[i]->trangthai, 104 + movX, k);
				k++;
			}
			goto key;
		}
		cout << "  ";
		gotoXY(0 + movX + 1, f + movY);
		cout << ">";

		if (c == 27)return;
	} while (c != 13);
	//bool khongHuy = false;
	if (ds_cb[a[p]]->trangthai == 3) {
		thongBaoString("CHUYEN BAY DA HOAN TAT, KHONG THE HUY CHUYEN");
		//khongHuy = true;
		goto back;
	}
	else if (ds_cb[a[p]]->trangthai == 0) {
		thongBaoString("CHUYEN BAY DA HUY !!!");
		//khongHuy = true;
		goto back;
	}


	//system("cls");
	//deleteCenter();
	f = 7;
	char* tmp = new char[15];
	int j = 0;
	while (ds_cb[a[p]]->machuyenbay[j] != '\0')
	{
		tmp[j] = ds_cb[a[p]]->machuyenbay[j];
		j++;
		tmp[j] = '\0';
	}
	char* cmp = new char[15];
	j = 0;
	while (ds_cb[a[p]]->sohieu[j] != '\0')
	{
		cmp[j] = ds_cb[a[p]]->sohieu[j];
		j++;
		cmp[j] = '\0';
	}
	huy_chuyen(First, tmp, cmp, ds_cb);
	//gotoXY(50, 11); cout << "Ban co chac la huy chuyen!";
	if (yes_no_fl(First) == 0)
	{
		//box_nho(10, 13, 100, 3);
		thongBaoString("DA HUY CHUYEN !!!!");
		goto back;
	}
	else { goto back; }
}

int yes_no_fl(DS_CHUYEN_BAY& First)
{
	TableListCB();
	int movX = 7;
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + movX, 15); cout << "BAN CO CHAC CHAN KHONG ?";
	box1(0 + 65 - 1 + 60 + 30 + 15 + 3 + movX, 8 + 5 - 1, 35, 15, 19);
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + 5 + movX, 18); cout << "YES";
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + 5 + movX, 19); cout << "NO";
	gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + movX, 18); cout << "=>";
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
			gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + movX, k - 1);
			printf("  ");
		}
		if (k < 19)
		{
			gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + movX, k + 1);
			printf("  ");

		}
		cout << "  ";
		gotoXY(0 + 65 - 1 + 60 + 30 + 15 + 3 + 3 + movX, k);
		cout << "=>";
		//Sleep(200);
	} while (c != 13);
	switch (k)
	{
	case 18:
		writefile_flight(First);
		deleteBoxAdd();
		deleteListCB();
		return 0;
	case 19:
		deleteBoxAdd();
		clearSearch();
		return 1;
	}
	//
	return 0;
}

int huy_chuyen(DS_CHUYEN_BAY& First, char* k, char* sh, chuyenbay* ds_cb[])
{

	readfile_cb(First);
	DS_CHUYEN_BAY p, q;
	p = First;
	int n;
	chuyenbay x;
	n = dem(First);
	clearlist(First);
	for (int i = 0; i < n; i++)
	{
		if (_strcmpi(k, ds_cb[i]->machuyenbay) == 0 && _strcmpi(sh, ds_cb[i]->sohieu) == 0)
		{
			strcpy_s(x.machuyenbay, ds_cb[i]->machuyenbay);
			strcpy_s(x.sohieu, ds_cb[i]->sohieu);
			strcpy_s(x.sanbay, ds_cb[i]->sanbay);
			ds_cb[i]->trangthai = 0;
			x.trangthai = ds_cb[i]->trangthai;
			x.ngay = ds_cb[i]->ngay;
			x.thang = ds_cb[i]->thang;
			x.nam = ds_cb[i]->nam;
			x.gio = ds_cb[i]->gio;
			x.phut = ds_cb[i]->phut;
			x.ds_ve.n = ds_cb[i]->ds_ve.n;
			x.ds_ve.sl_con = ds_cb[i]->ds_ve.sl_con;
			x.ds_ve.sl_da_ban = ds_cb[i]->ds_ve.sl_da_ban;
			x.ds_ve.cmnd = ds_cb[i]->ds_ve.cmnd;
			insert_last(First, x);
		}
		else
		{
			strcpy_s(x.machuyenbay, ds_cb[i]->machuyenbay);
			strcpy_s(x.sohieu, ds_cb[i]->sohieu);
			strcpy_s(x.sanbay, ds_cb[i]->sanbay);
			x.trangthai = ds_cb[i]->trangthai;
			x.ngay = ds_cb[i]->ngay;
			x.thang = ds_cb[i]->thang;
			x.nam = ds_cb[i]->nam;
			x.gio = ds_cb[i]->gio;
			x.phut = ds_cb[i]->phut;
			x.ds_ve.n = ds_cb[i]->ds_ve.n;
			x.ds_ve.sl_con = ds_cb[i]->ds_ve.sl_con;
			x.ds_ve.sl_da_ban = ds_cb[i]->ds_ve.sl_da_ban;
			x.ds_ve.cmnd = ds_cb[i]->ds_ve.cmnd;
			insert_last(First, x);
		}
	}
	//writefile_flight(First);
	return 0;
}
int search_choi(DS_MAYBAY& mb)
{
	int movX = 60;
	int movY = 8;
	char c;
back:
	deleteListCB();
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


	gotoXY(101, 35); cout << "[Trang]: " << trang + 1 << "/" << tong;

	//connhay_on2();
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
			connhay_off2();
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
			connhay_off2();
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
			connhay_on2();
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
			connhay_off2();
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
				deleteListCB();
				result_plane(mb);
				gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);

				goto back;
				connhay_off2();
			}
			gotoXY(65 - 1 + 60 + 30 + 15 + 5 + 2 - 3 + i + 10, 8 + 5 - 1 - 4 + 1);
			TableList1();

			connhay_on2();
		}
		if (c == 27)return 0;
	} while (c != 13);
	connhay_off2();
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
	deleteListCB();
	return a[p];

}
void insert_cb(DS_CHUYEN_BAY& First, chuyen_bay& x)
{
	boxAddCB();
	int movX = 140;
	int years;
	int days;
	int months;
	int hours;
	int mins;
	time_t baygio = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &baygio);
	years = 1900 + ltm->tm_year;
	months = 1 + ltm->tm_mon;
	days = ltm->tm_mday;
	hours = ltm->tm_hour;
	mins = 1 + ltm->tm_min;
	readfile_cb(First);
	DS_MAYBAY mb;
	int k = 7;
	char c;
	int i = 0;
	char* tmp;
	int n = 0;
	DS_CHUYEN_BAY p;
	tmp = new char[200];
	connhay_off2();
	//system("cls");
	deleteListCB();

	gotoXY(65 + 60 + 30 + 15 + 5 - 3 + +7 + 1, 8 + 5 + 1);
	cout << "CHON SO HIEU";
	int j = 0;
	i = search_choi(mb);
	while (mb.dsmaybay[i]->sohieu[j] != '\0')
	{
		x.sohieu[j] = mb.dsmaybay[i]->sohieu[j];
		j++;
		x.sohieu[j] = '\0';
	}
	deleteListCB();

xuat:
	gotoXY(65 + 60 + 30 + 15 + 5 - 3 + +7 + 1, 8 + 5 + 1);
	cout << "              ";
	x.ds_ve.n = mb.dsmaybay[i]->socho;
	gotoXY(45 + movX, 12);
	cout << "So hieu: ";
	gotoXY(60 + movX, 12); cout << x.sohieu;
	gotoXY(45 + movX, 13);
	cout << "Ma chuyen bay: ";
	gotoXY(45 + movX, 14);
	cout << "Nhap san bay: ";
	gotoXY(45 + movX, 15);
	cout << "Nhap ngay: ";
	gotoXY(45 + movX, 16);
	cout << "Nhap thang: ";
	gotoXY(45 + movX, 17);
	cout << "Nhap nam: ";
	gotoXY(45 + movX, 18);
	cout << "Nhap gio: ";
	gotoXY(45 + movX, 19);
	cout << "Nhap phut: ";
	gotoXY(45 + movX, 20);
	cout << "so luong ve: "; gotoXY(60 + movX, 20); cout << x.ds_ve.n;
	do {
		gotoXY(60 + movX, 13); connhay_on2();
		tmp = block_and_char(15, 60 + movX, 13);
	} while (tmp[0] == '\0');
	if (tmp[0] == '.')
	{
		return;
	}
	n = 0;
	while (tmp[n] != '\0')
	{
		x.machuyenbay[n] = tmp[n];
		n++;
		x.machuyenbay[n] = '\0';
	}
	p = First;
	while (p != NULL)
	{
		if (_strcmpi(p->cb.machuyenbay, x.machuyenbay) == 0 && _strcmpi(p->cb.sohieu, x.sohieu) == 0)
		{
			//gotoXY(94 + movX, 4);
		//	cout << "Nhap trung";
			thongBaoString("MA CHUYEN BAY DA CO TRONG DANH SACH, NHAP LAI !!!");
			//gotoXY(94 + movX, 5); cout << "Nhap lai";
			_getch();
			for (int i = 0; i <= 10; i++)
			{
				gotoXY(94 + i + movX, 4); cout << " ";
				gotoXY(94 + i + movX, 5); cout << " ";
				gotoXY(60 + i + movX, 13); cout << " ";
			}
			boxAddCB();
			gotoXY(45 + movX, 12);
			cout << "So hieu: ";
			gotoXY(60 + movX, 12); cout << x.sohieu;
			goto xuat;
		}
		p = p->next;
	}
	connhay_off2();
	do {

		gotoXY(60 + movX, 14); connhay_on2();
		tmp = block_char(100, 60 + movX, 14);
	} while (tmp[0] == '\0');
	if (tmp[0] == '.')
	{
		return;
	}
	n = 0;
	while (tmp[n] != '\0')
	{
		x.sanbay[n] = tmp[n];
		n++;
		x.sanbay[n] = '\0';
	}
	connhay_off2();
	//gotoXY(45, 11);
	//cout << "Nhap ngay: ";
	do {
		for (int i = 0; i < 10; i++)
		{
			gotoXY(60 + i + movX, 15); cout << " ";
		}
		boxAddCB();
		gotoXY(45 + movX, 12);
		cout << "So hieu: ";
		gotoXY(60 + movX, 12); cout << x.sohieu;
		//gotoXY(15, 3);
		gotoXY(60 + movX, 15); connhay_on2();
		tmp = block_number(1, 60 + movX, 15);
	} while (tmp[0] == '\0' || atoi(tmp) > 31);
	if (tmp[0] == '.')
	{
		return;
	}
	x.ngay = atoi(tmp);
	connhay_off2();
	//gotoXY(45, 12);
	//cout << "Nhap thang: ";
	do {
		for (int i = 0; i < 10; i++)
		{
			gotoXY(60 + i + movX, 16); cout << " ";
		}
		boxAddCB();
		gotoXY(45 + movX, 12);
		cout << "So hieu: ";
		gotoXY(60 + movX, 12); cout << x.sohieu;
		//gotoXY(15, 4);
		gotoXY(60 + movX, 16); connhay_on2();
		tmp = block_number(1, 60 + movX, 16);
	} while (tmp[0] == '\0' || atoi(tmp) > 12);
	if (tmp[0] == '.')
	{
		n++;
		return;
	}
	x.thang = atoi(tmp);
	connhay_off2();
	//gotoXY(45, 13);
	//cout << "Nhap nam: ";
	do {
		for (int i = 0; i < 10; i++)
		{
			gotoXY(60 + i + movX, 17); cout << " ";
		}
		boxAddCB();
		gotoXY(45 + movX, 12);
		cout << "So hieu: ";
		gotoXY(60 + movX, 12); cout << x.sohieu;
		//gotoXY(15, 5);
		gotoXY(60 + movX, 17); connhay_on2();
		tmp = block_number(3, 60 + movX, 17);
	} while (tmp[0] == '\0' || x.thang < months && atoi(tmp) == years || atoi(tmp) < years);
	if (tmp[0] == '.')
	{
		return;
	}
	x.nam = atoi(tmp);
	connhay_off2();
back1:
	//gotoXY(45, 14);
	//cout << "Nhap gio: ";
	do {
		for (int i = 0; i < 10; i++)
		{
			gotoXY(60 + i + movX, 18); cout << " ";
		}
		boxAddCB();
		gotoXY(45 + movX, 12);
		cout << "So hieu: ";
		gotoXY(60 + movX, 12); cout << x.sohieu;
		gotoXY(60 + movX, 18); connhay_on2();
		tmp = block_number(1, 60 + movX, 18);
	} while (tmp[0] == '\0' || days == x.ngay && months == x.thang && years == x.nam && atoi(tmp) - hours < 0 || atoi(tmp)>24);
	n = 0;
	if (tmp[0] == '.')
	{
		return;
	}
	while (p != NULL)
	{
		if (_strcmpi(p->cb.sohieu, x.sohieu) == 0 && _strcmpi(p->cb.machuyenbay, x.machuyenbay) != 0)
		{
			if (p->cb.ngay == x.ngay && p->cb.thang == x.thang && p->cb.nam == x.nam && abs(atoi(tmp) - p->cb.gio) < 4)
			{
				//gotoXY(60, 18);
				thongBaoString("DA CO CHUYEN BAY CACH DAY 4 GIO !!!");

				_getch();
				for (int i = 0; i <= 10; i++)
				{
					gotoXY(94 + i + movX, 4); cout << " ";
					gotoXY(94 + i + movX, 5); cout << " ";
					gotoXY(60 + i + movX, 5); cout << " ";
				}
				goto back1;
			}
		}
		p = p->next;
	}
	connhay_off2();
	x.gio = atoi(tmp);
	//gotoXY(45, 15);
	//cout << "Nhap phut: ";
	do {
		gotoXY(60 + movX, 19); connhay_on2();
		tmp = block_number(1, 60 + movX, 19);
	} while (tmp[0] == '\0' || atoi(tmp) > 60);
	if (tmp[0] == '.')return;
	x.phut = atoi(tmp);
	x.ds_ve.cmnd = new string[x.ds_ve.n + 1];
	for (int i = 1; i < x.ds_ve.n + 1; i++)
	{
		x.ds_ve.cmnd[i] = "";
	}
	connhay_off2();
	x.trangthai = 1;
	x.ds_ve.sl_con = x.ds_ve.n;
	x.ds_ve.sl_da_ban = 0;
	//insert_oder(First, x);
	insert_last(First, x);
	writefile_flight(First);
}

/*
	f = 7;

	gotoXY(0 + movX, 7 + movY); cout << "==>";
	do
	{
		gotoXY(101 + movX, 28); cout << "Trang: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f <= 7 && tong > 1 && trang > 0 && c == 72)
		{
			gotoXY(0 + movX, 7 + movY);
			cout << "   ";
			f = 25 ;
			trang--;
			int k = 0;
			int j = 0;
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 14; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 13; i++)
				{
					gotoXY(25 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 8; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 20; i++)
				{
					gotoXY(48 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(69 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(75 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(81 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(87 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(92 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(97 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(103 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 12; i++)
				{
					gotoXY(104 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			k = 7 + movY;
			for (int i = trang * 18 + 0; i < dem(First) && i <= 18 + trang * 18; i++)
			{
				gotoXY(5 + movX, k);
				cout << i;
				for (int j = 0; j < mb.sl - 1; j++)
				{
					if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoXY(10 + movX, k);
						cout << mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
				gotoXY(25 + movX, k);
				cout << ds_cb[i]->machuyenbay;
				gotoXY(40 + movX, k);
				cout << ds_cb[i]->sohieu;
				gotoXY(55 + movX, k);
				cout << ds_cb[i]->sanbay;
				gotoXY(70 + movX, k);
				cout << ds_cb[i]->ngay;
				gotoXY(77 + movX, k);
				cout << ds_cb[i]->thang;
				gotoXY(81 + movX, k);
				cout << ds_cb[i]->nam;
				gotoXY(88 + movX, k);
				cout << ds_cb[i]->gio;
				gotoXY(93 + movX, k);
				cout << ds_cb[i]->phut;
				gotoXY(98 + movX, k);
				cout << ds_cb[i]->ds_ve.n;
				trang_thai(ds_cb[i]->trangthai, 104 + movX, k);
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
		if (f != 7)
		{
			gotoXY(0 + movX, f - 1 + movY);
			printf("   ");
		}
		if (f != 7 + u)
		{
			gotoXY(0 + movX, f + 1 + movY);
			printf("  ");
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
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 14; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 13; i++)
				{
					gotoXY(25 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 8; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 20; i++)
				{
					gotoXY(48 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(69 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(75 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(81 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(87 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(92 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 4; i++)
				{
					gotoXY(97 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 5; i++)
				{
					gotoXY(103 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 12; i++)
				{
					gotoXY(104 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			k = 7 + movY;
			for (int i = trang * 18 + 0; i < dem(First) && i <= 18 + trang * 18; i++)
			{
				gotoXY(5 + movX, k);
				cout << i;
				for (int j = 0; j < mb.sl - 1; j++)
				{
					if (_strcmpi(ds_cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoXY(10 + movX, k);
						cout << mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
				gotoXY(25 + movX, k);
				cout << ds_cb[i]->machuyenbay;
				gotoXY(40 + movX, k);
				cout << ds_cb[i]->sohieu;
				gotoXY(55 + movX, k);
				cout << ds_cb[i]->sanbay;
				gotoXY(70 + movX, k);
				cout << ds_cb[i]->ngay;
				gotoXY(77 + movX, k);
				cout << ds_cb[i]->thang;
				gotoXY(81 + movX, k);
				cout << ds_cb[i]->nam;
				gotoXY(88 + movX, k);
				cout << ds_cb[i]->gio;
				gotoXY(93 + movX, k);
				cout << ds_cb[i]->phut;
				gotoXY(98 + movX, k);
				cout << ds_cb[i]->ds_ve.n;
				trang_thai(ds_cb[i]->trangthai, 104 + movX, k);
				k++;
			}
			goto key;
		}
		cout << "  ";
		gotoXY(0 + movX, f + movY);
		cout << "==>";
	} while (c != 27);

*/