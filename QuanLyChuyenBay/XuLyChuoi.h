
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
	Time();
	box_nho(15 + movX, 27 + movY, 15, 2);
	gotoXY(16 + movX, 28 + movY); printf("<ESC> QUAY LAI");
	box_nho(32 + movX, 27 + movY, 16, 2);
	gotoXY(33 + movX, 28 + movY); cout << "<ENTER> CHON";
	readfile_cb(ds_cb);
	readfile_plane(ds_mb);
	docFileHanhKhach(ds_hk.tree);
	Print_cb_to_arr(ds_cb, cb);
	result_flight(ds_cb, cb);
	int trang = 0;
	int tong = 0;
	if (dem(ds_cb) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else tong = (dem(ds_cb) / 18) + 1;
	//box(100 + movX, 27 + movY, 15, 1,Blue);
	gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
	gotoXY(15 + movX, 4 + movY); cout << "Search theo Ma CB:";
	//boxSearchCB();
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
						if (l == 26)break;
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
			//gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
			gotoXY(27 + i - 1 + movX, 3 + movY);
			cout << " ";
			//gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
			gotoXY(27 + i - 1 + movX, 3 + movY);
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
data://============================================================================================================//
	f = 7;
	//box_nho(100, 27, 15, 2);
	gotoXY(movX, 7 + movY); cout << " =>";
	SetbgColor(0);
	do
	{
		//box(100 + movX, 27 + movY, 15, 1, White);
		gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
		c = getKey();
		if (f <= 7 && tong > 1 && trang > 0 && c == Up)
		{
			gotoXY( 5 + movX, 7 + movY);
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
			gotoXY(2 + movX, f - 1 + movY);
			printf("   ");
		}
		if (f != 7 + u)
		{
			gotoXY(2 + movX, f + 1 + movY);
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
		gotoXY(movX, f + movY); cout << " =>";
		SetbgColor(0);
	} while (c != Enter || cb[a[p]]->trangthai == 3 || cb[a[p]]->trangthai == 0);
	//system("cls");
	deleteNormal();
	int k, x, y;
	k = cb[a[p]]->ds_ve.n;
	int* v = new int[k];
	int o = 1;
	for (int j = 1; j < cb[a[p]]->ds_ve.n + 1; j++)
	{
		if (cb[a[p]]->ds_ve.cmnd[j].length() == 9)
		{
			v[o] = j;
			o++;
		}
	}
	deleteTrang();
	deleteNormal();
	box_nho(10 + movX, 3 + movY, 45, 23);
	box_kexy(10 + movX, 5 + movY, 45);
	box_nho(80 + movX, 8 + movY, 45, 18);
	box_kexy(80 + movX, 10 + movY, 45);
	box_nho(20 + movX, 27 + movY, 15, 2);
	gotoXY(25 + movX, 28 + movY); printf("<ESC> THOAT");
	gotoXY(95 + movX, 9 + movY); cout << "GHI CHU";
	gotoXY(90 + movX, 11 + movY); cout << "VE TO MAU DO LA VE DA BAN";
	gotoXY(15 + movX, 4 + movY); cout << "SO VE CON TRONG CUA CHUYEN BAY: " << cb[a[p]]->machuyenbay;
	gotoXY(90 + movX, 12 + movY); cout << "VE CON TRONG LA: " << cb[a[p]]->ds_ve.sl_con;
	inDSVe(k, v);
	while (c != ESC)
	{
		c = _getch();
	}
	//system("cls");
	deleteNormal();
	goto xuly;
}

//void inVe(DS_CHUYEN_BAY& ds_cb, DS_HANHKHACH& ds_hk, HanhKhach* ds[], DS_MAYBAY& mb, chuyenbay* cb[])
//{
//xuly:
//	char c;
//	char* b = new char[14];
//	int i = 0;
//	int u = 0;
//	int a[MAX];
//	Time();
//	box_nho(5, 27, 11, 2);
//	gotoXY(6, 28); printf("<ESC> thoat");
//	readfile_cb(ds_cb);
//	readfile_plane(mb);
//	docFileHanhKhach(ds_hk.tree);
//	Print_cb_to_arr(ds_cb, cb);
//	result_flight(ds_cb, cb);
//	int trang = 0;
//	int tong = 0;
//	if (dem(ds_cb) == 18)
//	{
//		trang = 0;
//		tong = 1;
//	}
//	else
//	{
//		tong = (dem(ds_cb)) / 18 + 1;
//	}
//	box_nho(100, 27, 15, 2); gotoXY(101, 28); cout << "Trang: " << trang + 1 << "/" << tong;
//	gotoXY(15, 3); cout << "Search_CB:";
//	connhay_on();
//	do
//	{
//		c = _getch();
//		connhay_on();
//		if (i <= 14 && c >= 48 && c <= 122 || c == 32)
//		{
//			u = 0;
//			if (c >= 97 && c <= 122)
//			{
//				gotoXY(27 + i, 3);
//				b[i] = c - 32;
//				cout << b[i];
//			}
//			else
//			{
//				gotoXY(27 + i, 3);
//				b[i] = c;
//				cout << c;
//			}
//			i++;
//			int k = 0;
//			int j = 0;
//			while (j <= 18)
//			{
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(5 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 14; i++)
//				{
//					gotoXY(10 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 13; i++)
//				{
//					gotoXY(25 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 8; i++)
//				{
//					gotoXY(39 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 20; i++)
//				{
//					gotoXY(48 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(69 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(75 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(81 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(87 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(92 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(97 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(103 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 12; i++)
//				{
//					gotoXY(104 + i, j + 7);
//					cout << " ";
//				}
//				j++;
//			}
//			b[i] = '\0';
//			string tim_maybay;
//			tim_maybay = b;
//			connhay_off();
//			int l = 7;
//			for (int i = 0; i < dem(ds_cb); i++)
//			{
//				for (int j = 0; j < tim_maybay.length(); j++)
//				{
//					if (cb[i]->machuyenbay[j] != tim_maybay[j])
//						break;
//					if (j == tim_maybay.length() - 1)
//					{
//						a[u] = i;
//						u++;
//						if (l == 26)break;
//						gotoXY(5, l);
//						cout << i;
//						for (int j = 0; j < mb.sl - 1; j++)
//						{
//							if (_strcmpi(cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
//							{
//								gotoXY(10, l);
//								cout << mb.dsmaybay[j]->loaimaybay;
//							}
//						}
//						//cout << mb.dsmaybay[cb[i]->loai]->loaimaybay << endl;
//						gotoXY(25, l);
//						cout << cb[i]->machuyenbay;
//						gotoXY(40, l);
//						cout << cb[i]->sohieu;
//						gotoXY(55, l);
//						cout << cb[i]->sanbay;
//						gotoXY(70, l);
//						cout << cb[i]->ngay;
//						gotoXY(77, l);
//						cout << cb[i]->thang;
//						gotoXY(81, l);
//						cout << cb[i]->nam;
//						gotoXY(88, l);
//						cout << cb[i]->gio;
//						gotoXY(93, l);
//						cout << cb[i]->phut;
//						gotoXY(98, l);
//						cout << cb[i]->ds_ve.n;
//						trang_thai(cb[i]->trangthai, 104, l);
//						l++;
//					}
//				}
//			}
//		}
//		if (c == 8 && i > 0)
//		{
//			u = 0;
//			gotoXY(27 + i - 1, 3);
//			cout << " ";
//			gotoXY(27 + i - 1, 3);
//			i--;
//			b[i] = '\0';
//			string tim_maybay;
//			tim_maybay = b;
//			connhay_off();
//			int k = 7;
//			for (int i = 0; i < dem(ds_cb); i++)
//			{
//				for (int j = 0; j < tim_maybay.length(); j++)
//				{
//					if (cb[i]->machuyenbay[j] != tim_maybay[j])
//						break;
//					if (j == tim_maybay.length() - 1)
//					{
//						a[u] = i;
//						u++;
//						if (k == 26)break;
//						gotoXY(5, k);
//						cout << i;
//						for (int j = 0; j < mb.sl - 1; j++)
//						{
//							if (_strcmpi(cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
//							{
//								gotoXY(10, k);
//								cout << mb.dsmaybay[j]->loaimaybay;
//							}
//						}
//						gotoXY(25, k);
//						cout << cb[i]->machuyenbay;
//						gotoXY(40, k);
//						cout << cb[i]->sohieu;
//						gotoXY(55, k);
//						cout << cb[i]->sanbay;
//						gotoXY(70, k);
//						cout << cb[i]->ngay;
//						gotoXY(77, k);
//						cout << cb[i]->thang;
//						gotoXY(81, k);
//						cout << cb[i]->nam;
//						gotoXY(88, k);
//						cout << cb[i]->gio;
//						gotoXY(93, k);
//						cout << cb[i]->phut;
//						gotoXY(98, k);
//						cout << cb[i]->ds_ve.n;
//						trang_thai(cb[i]->trangthai, 104, k);
//						k++;
//					}
//				}
//				//gotoXY(27 + i, 3);
//				//connhay_on();
//			}
//			if (b[0] == '\0')
//			{
//				result_flight(ds_cb, cb);
//				connhay_off();
//			}
//			gotoXY(27 + i, 3);
//		}
//		if (c == 27)return;
//	} while (c != 13);
//	connhay_off();
//	if (u == 0)
//	{
//		u = dem(ds_cb);
//		for (int i = 0; i < u; i++)
//		{
//			a[i] = i;
//		}
//	}
//	int f;
//	int p = 0;
//	//int tr = 0;
//data://============================================================================================================//
//	f = 7;
//	box_nho(100, 27, 15, 2);
//	gotoXY(0, 7); cout << "==>";
//	do
//	{
//		gotoXY(101, 28); cout << "Trang: " << trang + 1 << "/" << tong;
//		c = _getch();
//		if (f == 7 && tong > 1 && trang > 0 && c == 72)
//		{
//			gotoXY(0, 7);
//			cout << "   ";
//			f = 25;
//			trang--;
//			//tr--;
//			//gotoXY(108, 28);cout << tr;
//			int k = 0;
//			int j = 0;
//			while (j <= 18)
//			{
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(5 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 14; i++)
//				{
//					gotoXY(10 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 13; i++)
//				{
//					gotoXY(25 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 8; i++)
//				{
//					gotoXY(39 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 20; i++)
//				{
//					gotoXY(48 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(69 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(75 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(81 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(87 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(92 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(97 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(103 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 12; i++)
//				{
//					gotoXY(104 + i, j + 7);
//					cout << " ";
//				}
//				j++;
//			}
//			k = 7;
//			for (int i = trang * 18 + 0; i < dem(ds_cb) && i <= 18 + trang * 18; i++)
//			{
//				gotoXY(5, k);
//				cout << i;
//				for (int j = 0; j < mb.sl - 1; j++)
//				{
//					if (_strcmpi(cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
//					{
//						gotoXY(10, k);
//						cout << mb.dsmaybay[j]->loaimaybay;
//					}
//				}
//				//cout << mb.dsmaybay[cb[i]->loai]->loaimaybay << endl;
//				gotoXY(25, k);
//				cout << cb[i]->machuyenbay;
//				gotoXY(40, k);
//				cout << cb[i]->sohieu;
//				gotoXY(55, k);
//				cout << cb[i]->sanbay;
//				gotoXY(70, k);
//				cout << cb[i]->ngay;
//				gotoXY(77, k);
//				cout << cb[i]->thang;
//				gotoXY(81, k);
//				cout << cb[i]->nam;
//				gotoXY(88, k);
//				cout << cb[i]->gio;
//				gotoXY(93, k);
//				cout << cb[i]->phut;
//				gotoXY(98, k);
//				cout << cb[i]->ds_ve.n;
//				trang_thai(cb[i]->trangthai, 104, k);
//				k++;
//			}
//		}
//		if (c == 72)
//		{
//			if (f > 7)
//			{
//				f = f - 1;
//				p--;
//			}
//		}
//		else if (c == 80)
//		{
//			if (f < u + 6 && p <= u - 2)
//			{
//				f += 1;
//				p++;
//			}
//
//		}
//		if (c == 27)goto xuly;
//		if (f != 7)
//		{
//			gotoXY(0, f - 1);
//			printf("   ");
//		}
//		if (f != 7 + u)
//		{
//			gotoXY(0, f + 1);
//			printf("  ");
//		}
//		if (f == 25 && tong > 1 && trang + 1 < tong && c == 80)
//		{
//			trang++;
//			int k = 0;
//			int j = 0;
//			while (j <= 18)
//			{
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(5 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 14; i++)
//				{
//					gotoXY(10 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 13; i++)
//				{
//					gotoXY(25 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 8; i++)
//				{
//					gotoXY(39 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 20; i++)
//				{
//					gotoXY(48 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(69 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(75 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(81 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(87 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(92 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 4; i++)
//				{
//					gotoXY(97 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 5; i++)
//				{
//					gotoXY(103 + i, j + 7);
//					cout << " ";
//				}
//				for (int i = 0; i < 12; i++)
//				{
//					gotoXY(104 + i, j + 7);
//					cout << " ";
//				}
//				j++;
//			}
//			k = 7;
//			for (int i = trang * 18 + 0; i < dem(ds_cb) && i <= 18 + trang * 18; i++)
//			{
//				gotoXY(5, k);
//				cout << i;
//				for (int j = 0; j < mb.sl - 1; j++)
//				{
//					if (_strcmpi(cb[i]->sohieu, mb.dsmaybay[j]->sohieu) == 0)
//					{
//						gotoXY(10, k);
//						cout << mb.dsmaybay[j]->loaimaybay;
//					}
//				}
//				//cout << mb.dsmaybay[cb[i]->loai]->loaimaybay << endl;
//				gotoXY(25, k);
//				cout << cb[i]->machuyenbay;
//				gotoXY(40, k);
//				cout << cb[i]->sohieu;
//				gotoXY(55, k);
//				cout << cb[i]->sanbay;
//				gotoXY(70, k);
//				cout << cb[i]->ngay;
//				gotoXY(77, k);
//				cout << cb[i]->thang;
//				gotoXY(81, k);
//				cout << cb[i]->nam;
//				gotoXY(88, k);
//				cout << cb[i]->gio;
//				gotoXY(93, k);
//				cout << cb[i]->phut;
//				gotoXY(98, k);
//				cout << cb[i]->ds_ve.n;
//				trang_thai(cb[i]->trangthai, 104, k);
//				k++;
//			}
//			//f = 7;
//			goto data;
//		}
//		cout << "  ";
//		gotoXY(0, f);
//		cout << "==>";
//	} while (c != 13 || cb[a[p]]->trangthai == 3 || cb[a[p]]->trangthai == 0);
//	system("cls");
//	int k, x, y;
//	k = cb[a[p]]->ds_ve.n;
//	int* v = new int[k];
//	int o = 1;
//	for (int j = 1; j < cb[a[p]]->ds_ve.n + 1; j++)
//	{
//		if (cb[a[p]]->ds_ve.cmnd[j].length() == 9)
//		{
//			v[o] = j;
//			o++;
//		}
//	}
//	box_nho(0, 0, 41, 25);
//	box_kexy(0, 3, 41);
//	box_nho(60, 5, 41, 20);
//	box_kexy(60, 8, 41);
//	box_nho(5, 27, 11, 2);
//	gotoXY(6, 28); printf("<ESC> thoat");
//	gotoXY(75, 7); cout << "CHU THICH";
//	gotoXY(67, 10); cout << "VE TO MAU DO LA VE DA BAN";
//	gotoXY(1, 1); cout << "SO VE CON TRONG CUA CHUYEN BAY: " << cb[a[p]]->machuyenbay;
//	gotoXY(14, 2); cout << "VE CON TRONG LA: " << cb[a[p]]->ds_ve.sl_con;
//	inDSVe(k, v);
//	while (c != 27)
//	{
//		c = _getch();
//	}
//	system("cls");
//	goto xuly;
//}