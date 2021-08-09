
#pragma once
#include "KhaiBao.h"
#include "MyLib.h"
#include "DocGhiFile.h"
#include "ChuyenBay.h"
#include "MayBay.h"
#include "HanhKhach.h"
#include "VE.h"
#include "GiaoDien.h"
#include "Box.h"

using namespace std;

void in_ve(DS_CHUYEN_BAY& ds_cb, DS_HANHKHACH& ds_hk, HanhKhach* hk[], DS_MAYBAY& ds_mb, chuyenbay* cb[])
{
	int movX = 60, movY = 8, movSX = 105, movSY = -2;
xuly:
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	deleteNormal();
	TableListCB();
	Time();
	box_nho(15 + movX, 28 + movY, 15, 2);
	gotoXY(16 + movX, 29 + movY); printf("<ESC> QUAY LAI");
	box_nho(32 + movX, 28 + movY, 16, 2);
	gotoXY(33 + movX, 29 + movY); cout << "<ENTER> CHON";
	readfile_cb(ds_cb);
	readfile_plane(ds_mb);
	Print_cb_to_arr(ds_cb, cb);
	result_flight(ds_cb, cb);
	docFileHanhKhach(ds_hk.tree);
	int trang = 0;
	int tong = 0;
	if (dem(ds_cb) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else tong = (dem(ds_cb) / 18) + 1;
	gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
	gotoXY(15 + movX, 3 + movY); cout << "Search theo ma: ";
	connhay_on();
	do
	{

		c = getKey();
		connhay_on();
		if (i <= 14 && c >= 48 && c <= 122 || c == Space)
		{
			u = 0;
			if (c >= 97 && c <= 122)
			{
				gotoXY(35 + i + movX, 4 + movY);
				b[i] = c - 32;
				cout << b[i];
			}
			else
			{
				gotoXY(35 + i + movX, 4 + movY);
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
			connhay_off();
			int l = 7 + movY;
			for (int i = 0; i < dem(ds_cb); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 26) break;
						gotoXY(5 + movX, l);
						cout << i;
						for (int j = 0; j < ds_mb.sl - 1; j++)
						{
							if (_strcmpi(cb[i]->sohieu, ds_mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoXY(10 + movX, l);
								cout << ds_mb.dsmaybay[j]->loaimaybay;
							}
						}
						//cout << mb.dsmaybay[cb[i]->loai]->loaimaybay << endl;
						gotoXY(25 + movX, l);
						cout << cb[i]->machuyenbay;
						gotoXY(40 + movX, l);
						cout << cb[i]->sohieu;
						gotoXY(55 + movX, l);
						cout << cb[i]->sanbay;
						gotoXY(70 + movX, l);
						cout << cb[i]->ngay;
						gotoXY(77 + movX, l);
						cout << cb[i]->thang;
						gotoXY(81 + movX, l);
						cout << cb[i]->nam;
						gotoXY(88 + movX, l);
						cout << cb[i]->gio;
						gotoXY(93 + movX, l);
						cout << cb[i]->phut;
						gotoXY(98 + movX, l);
						cout << cb[i]->ds_ve.n;
						trang_thai(cb[i]->trangthai, 104 + movX, l);
						l++;
					}
				}
			}
		}
		if (c == Backspace && i > 0)
		{
			u = 0;
			gotoXY(27 + i + movX, 3 + movY);
			cout << " ";
			gotoXY(27 + i + movX, 3 + movY);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int k = 7 + movY;
			for (int i = 0; i < dem(ds_cb); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 26 + movY) break;
						gotoXY(5 + movX, k);
						cout << i;
						for (int j = 0; j < ds_mb.sl - 1; j++)
						{
							if (_strcmpi(cb[i]->sohieu, ds_mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoXY(10 + movX, k);
								cout << ds_mb.dsmaybay[j]->loaimaybay;
							}
						}
						gotoXY(25 + movX, k);
						cout << cb[i]->machuyenbay;
						gotoXY(40 + movX, k);
						cout << cb[i]->sohieu;
						gotoXY(55 + movX, k);
						cout << cb[i]->sanbay;
						gotoXY(70 + movX, k);
						cout << cb[i]->ngay;
						gotoXY(77 + movX, k);
						cout << cb[i]->thang;
						gotoXY(81 + movX, k);
						cout << cb[i]->nam;
						gotoXY(88 + movX, k);
						cout << cb[i]->gio;
						gotoXY(93 + movX, k);
						cout << cb[i]->phut;
						gotoXY(98 + movX, k);
						cout << cb[i]->ds_ve.n;
						trang_thai(cb[i]->trangthai, 104 + movX, k);
						k++;
					}
				}
				//gotoXY(27 + i, 3);
				//connhay_on2();
			}
			if (b[0] == '\0')
			{
				result_flight(ds_cb, cb);
				connhay_off();
			}
			gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
		}
		if (c == ESC)return;
	} while (c != Enter);
	connhay_off();
	if (u == 0)
	{
		u = dem(ds_cb);
		for (int i = 0; i < u; i++)
		{
			a[i] = i;
		}
	}
	int f;
	int p = 0;
	//==================================================
data:
	f = 7;
	gotoXY(movX + 1, movY + 7); cout << "=>";
	do
	{
		//box(100 + movX, 27 + movY, 15, 1, White);
		gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
		c = getKey();
		if (f <= 7 && tong > 1 && trang > 0 && c == Up)
		{
			gotoXY(+movX, 7 + movY);
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
			for (int i = trang * 18 + 0; i < dem(ds_cb) && i <= 18 + trang * 18; i++)
			{
				gotoXY(5 + movX, k);
				cout << i;
				for (int j = 0; j < ds_mb.sl - 1; j++)
				{
					if (_strcmpi(cb[i]->sohieu, ds_mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoXY(10 + movX, k);
						cout << ds_mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << ds_mb.dsmaybay[cb[i]->loai]->loaimaybay << endl;
				gotoXY(25 + movX, k);
				cout << cb[i]->machuyenbay;
				gotoXY(40 + movX, k);
				cout << cb[i]->sohieu;
				gotoXY(55 + movX, k);
				cout << cb[i]->sanbay;
				gotoXY(70 + movX, k);
				cout << cb[i]->ngay;
				gotoXY(77 + movX, k);
				cout << cb[i]->thang;
				gotoXY(81 + movX, k);
				cout << cb[i]->nam;
				gotoXY(88 + movX, k);
				cout << cb[i]->gio;
				gotoXY(93 + movX, k);
				cout << cb[i]->phut;
				gotoXY(98 + movX, k);
				cout << cb[i]->ds_ve.n;
				trang_thai(cb[i]->trangthai, 104 + movX, k);
				k++;
			}
		}
		if (c == Up)
		{
			if (f > 7)
			{
				f = f - 1;
				p--;
			}
		}
		else if (c == Down)
		{
			if (f < u + 6 && p <= u - 2)
			{
				f += 1;
				p++;
			}

		}

		if (c == ESC) goto xuly;
		if (f != 7)
		{
			gotoXY(1 + movX, f - 1 + movY);
			printf("   ");
		}
		if (f != 7 + u)
		{
			gotoXY(1 + movX, f + 1 + movY);
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
			for (int i = trang * 18 + 0; i < dem(ds_cb) && i <= 18 + trang * 18; i++)
			{
				gotoXY(5 + movX, k);
				cout << i;
				for (int j = 0; j < ds_mb.sl - 1; j++)
				{
					if (_strcmpi(cb[i]->sohieu, ds_mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoXY(10 + movX, k);
						cout << ds_mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << ds_mb.dsmaybay[cb[i]->loai]->loaimaybay << endl;
				gotoXY(25 + movX, k);
				cout << cb[i]->machuyenbay;
				gotoXY(40 + movX, k);
				cout << cb[i]->sohieu;
				gotoXY(55 + movX, k);
				cout << cb[i]->sanbay;
				gotoXY(70 + movX, k);
				cout << cb[i]->ngay;
				gotoXY(77 + movX, k);
				cout << cb[i]->thang;
				gotoXY(81 + movX, k);
				cout << cb[i]->nam;
				gotoXY(88 + movX, k);
				cout << cb[i]->gio;
				gotoXY(93 + movX, k);
				cout << cb[i]->phut;
				gotoXY(98 + movX, k);
				cout << cb[i]->ds_ve.n;
				trang_thai(cb[i]->trangthai, 104 + movX, k);
				k++;
			}
			goto data;
		}
		cout << "  ";
		gotoXY(1 + movX, f + movY); cout << " =>";
	} while (c != Enter || cb[a[p]]->trangthai == 3 || cb[a[p]]->trangthai == 0);//3: Hoan tat, 0: huy chuyen
	system("cls");
	//deleteNormal();
	int k, x, y;
	k = cb[a[p]]->ds_ve.n;
	int* v = new int[k];
	int o = 1;
	for (int j = 1; j < cb[a[p]]->ds_ve.n + 1; j++)
	{
		if (cb[a[p]]->ds_ve.cmnd[j].length() == 12)
		{
			v[o] = j;
			o++;
		}
	}
	box_nho(5, 32, 15, 2);
	gotoXY(6, 33); printf("<ESC> Quay lai");
	cout << endl;
	box_nho(0, 0, 41, 30);
	box_kexy(0, 3, 41);
	gotoXY(5, 1); cout << "SO VE CON TRONG CUA CHUYEN BAY: " << cb[a[p]]->machuyenbay;
	box_nho(60, 5, 41, 20);
	box_kexy(60, 8, 41);
	gotoXY(75, 7); cout << "GHI CHU";
	gotoXY(65, 10); cout << "VE TO MAU DO LA VE DA BAN";
	gotoXY(65, 12 ); cout << "VE CON TRONG LA: " << cb[a[p]]->ds_ve.sl_con;
	gotoXY(65, 14); cout << "VI TRI VE DA DAT: " << a[p] << "   ";
	inDSVe(k, v);
	while (c != ESC)
	{
		c = _getch();
	}
	system("cls");
	//deleteNormal();
	goto xuly;
}


void xemHanhKhach(DS_CHUYEN_BAY& ds_cb, DS_HANHKHACH& ds_hk, HanhKhach* ds[], DS_MAYBAY& ds_mb, chuyenbay* cb[])
{
	int movX = 60, movY = 8, movSX = 105, movSY = -2;
xuly:
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MAX];
	deleteNormal();
	TableListCB();
	Time();
	box_nho(15 + movX, 28 + movY, 15, 2);
	gotoXY(16 + movX, 29 + movY); printf("<ESC> QUAY LAI");
	box_nho(32 + movX, 28 + movY, 16, 2);
	gotoXY(33 + movX, 29 + movY); cout << "<ENTER> CHON";
	readfile_cb(ds_cb);
	readfile_plane(ds_mb);
	Print_cb_to_arr(ds_cb, cb);
	result_flight(ds_cb, cb);
	docFileHanhKhach(ds_hk.tree);
	int trang = 0;
	int tong = 0;
	if (dem(ds_cb) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else tong = (dem(ds_cb) / 18) + 1;
	gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
	gotoXY(15 + movX, 3 + movY); cout << "Search theo ma: ";
	connhay_on();
	do
	{

		c = getKey();
		connhay_on();
		if (i <= 14 && c >= 48 && c <= 122 || c == Space)
		{
			u = 0;
			if (c >= 97 && c <= 122)
			{
				gotoXY(35 + i + movX, 4 + movY);
				b[i] = c - 32;
				cout << b[i];
			}
			else
			{
				gotoXY(35 + i + movX, 4 + movY);
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
			connhay_off();
			int l = 7 + movY;
			for (int i = 0; i < dem(ds_cb); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (l == 26) break;
						gotoXY(5 + movX, l);
						cout << i;
						for (int j = 0; j < ds_mb.sl - 1; j++)
						{
							if (_strcmpi(cb[i]->sohieu, ds_mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoXY(10 + movX, l);
								cout << ds_mb.dsmaybay[j]->loaimaybay;
							}
						}
						//cout << mb.dsmaybay[cb[i]->loai]->loaimaybay << endl;
						gotoXY(25 + movX, l);
						cout << cb[i]->machuyenbay;
						gotoXY(40 + movX, l);
						cout << cb[i]->sohieu;
						gotoXY(55 + movX, l);
						cout << cb[i]->sanbay;
						gotoXY(70 + movX, l);
						cout << cb[i]->ngay;
						gotoXY(77 + movX, l);
						cout << cb[i]->thang;
						gotoXY(81 + movX, l);
						cout << cb[i]->nam;
						gotoXY(88 + movX, l);
						cout << cb[i]->gio;
						gotoXY(93 + movX, l);
						cout << cb[i]->phut;
						gotoXY(98 + movX, l);
						cout << cb[i]->ds_ve.n;
						trang_thai(cb[i]->trangthai, 104 + movX, l);
						l++;
					}
				}
			}
		}
		if (c == Backspace && i > 0)
		{
			u = 0;
			gotoXY(27 + i + movX, 3 + movY);
			cout << " ";
			gotoXY(27 + i + movX, 3 + movY);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			int k = 7 + movY;
			for (int i = 0; i < dem(ds_cb); i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (cb[i]->machuyenbay[j] != tim_maybay[j])
						break;
					if (j == tim_maybay.length() - 1)
					{
						a[u] = i;
						u++;
						if (k == 26 + movY) break;
						gotoXY(5 + movX, k);
						cout << i;
						for (int j = 0; j < ds_mb.sl - 1; j++)
						{
							if (_strcmpi(cb[i]->sohieu, ds_mb.dsmaybay[j]->sohieu) == 0)
							{
								gotoXY(10 + movX, k);
								cout << ds_mb.dsmaybay[j]->loaimaybay;
							}
						}
						gotoXY(25 + movX, k);
						cout << cb[i]->machuyenbay;
						gotoXY(40 + movX, k);
						cout << cb[i]->sohieu;
						gotoXY(55 + movX, k);
						cout << cb[i]->sanbay;
						gotoXY(70 + movX, k);
						cout << cb[i]->ngay;
						gotoXY(77 + movX, k);
						cout << cb[i]->thang;
						gotoXY(81 + movX, k);
						cout << cb[i]->nam;
						gotoXY(88 + movX, k);
						cout << cb[i]->gio;
						gotoXY(93 + movX, k);
						cout << cb[i]->phut;
						gotoXY(98 + movX, k);
						cout << cb[i]->ds_ve.n;
						trang_thai(cb[i]->trangthai, 104 + movX, k);
						k++;
					}
				}
				//gotoXY(27 + i, 3);
				//connhay_on2();
			}
			if (b[0] == '\0')
			{
				result_flight(ds_cb, cb);
				connhay_off();
			}
			gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
		}
		if (c == ESC)return;
	} while (c != Enter);
	connhay_off();
	if (u == 0)
	{
		u = dem(ds_cb);
		for (int i = 0; i < u; i++)
		{
			a[i] = i;
		}
	}
	int f;
	int p = 0;
	//===================================
data:
	f = 7;
	gotoXY(movX + 1, movY + 7); cout << "=>";
	do
	{
		//box(100 + movX, 27 + movY, 15, 1, White);
		gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
		c = getKey();
		if (f <= 7 && tong > 1 && trang > 0 && c == Up)
		{
			gotoXY(+movX, 7 + movY);
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
			for (int i = trang * 18 + 0; i < dem(ds_cb) && i <= 18 + trang * 18; i++)
			{
				gotoXY(5 + movX, k);
				cout << i;
				for (int j = 0; j < ds_mb.sl - 1; j++)
				{
					if (_strcmpi(cb[i]->sohieu, ds_mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoXY(10 + movX, k);
						cout << ds_mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << ds_mb.dsmaybay[cb[i]->loai]->loaimaybay << endl;
				gotoXY(25 + movX, k);
				cout << cb[i]->machuyenbay;
				gotoXY(40 + movX, k);
				cout << cb[i]->sohieu;
				gotoXY(55 + movX, k);
				cout << cb[i]->sanbay;
				gotoXY(70 + movX, k);
				cout << cb[i]->ngay;
				gotoXY(77 + movX, k);
				cout << cb[i]->thang;
				gotoXY(81 + movX, k);
				cout << cb[i]->nam;
				gotoXY(88 + movX, k);
				cout << cb[i]->gio;
				gotoXY(93 + movX, k);
				cout << cb[i]->phut;
				gotoXY(98 + movX, k);
				cout << cb[i]->ds_ve.n;
				trang_thai(cb[i]->trangthai, 104 + movX, k);
				k++;
			}
		}
		if (c == Up)
		{
			if (f > 7)
			{
				f = f - 1;
				p--;
			}
		}
		else if (c == Down)
		{
			if (f < u + 6 && p <= u - 2)
			{
				f += 1;
				p++;
			}

		}

		if (c == ESC) goto xuly;
		if (f != 7)
		{
			gotoXY(1 + movX, f - 1 + movY);
			printf("   ");
		}
		if (f != 7 + u)
		{
			gotoXY(1 + movX, f + 1 + movY);
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
			for (int i = trang * 18 + 0; i < dem(ds_cb) && i <= 18 + trang * 18; i++)
			{
				gotoXY(5 + movX, k);
				cout << i;
				for (int j = 0; j < ds_mb.sl - 1; j++)
				{
					if (_strcmpi(cb[i]->sohieu, ds_mb.dsmaybay[j]->sohieu) == 0)
					{
						gotoXY(10 + movX, k);
						cout << ds_mb.dsmaybay[j]->loaimaybay;
					}
				}
				//cout << ds_mb.dsmaybay[cb[i]->loai]->loaimaybay << endl;
				gotoXY(25 + movX, k);
				cout << cb[i]->machuyenbay;
				gotoXY(40 + movX, k);
				cout << cb[i]->sohieu;
				gotoXY(55 + movX, k);
				cout << cb[i]->sanbay;
				gotoXY(70 + movX, k);
				cout << cb[i]->ngay;
				gotoXY(77 + movX, k);
				cout << cb[i]->thang;
				gotoXY(81 + movX, k);
				cout << cb[i]->nam;
				gotoXY(88 + movX, k);
				cout << cb[i]->gio;
				gotoXY(93 + movX, k);
				cout << cb[i]->phut;
				gotoXY(98 + movX, k);
				cout << cb[i]->ds_ve.n;
				trang_thai(cb[i]->trangthai, 104 + movX, k);
				k++;
			}
			goto data;
		}
		cout << "  ";
		gotoXY(1 + movX, f + movY); cout << " =>";
	} while (c != Enter || cb[a[p]]->trangthai == 3 || cb[a[p]]->trangthai == 0);
	system("cls");
	doiTREEsangARR(ds_hk.tree, ds, ds_hk.slHK);
	inDSHanhKhach(ds, ds_hk.slHK);
}