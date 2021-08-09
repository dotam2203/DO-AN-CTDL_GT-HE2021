#pragma once
#include "KhaiBao.h"
#include "MyLib.h"
#include "DocGhiFile.h"
#include "ChuyenBay.h"
#include "MayBay.h"
#include "HanhKhach.h"
#include "GiaoDien.h"
#include "Box.h"
using namespace std;
///*======================= Quan ly ve may bay - Danh sach tuyen tinh cap phat dong ======================*/
void boxSearchCB();
void ButtonDatVe(int color);
void ButtonHuyVe(int color);
void ButtonEnter(int color);
void ButtonESC(int color);
void boxThongBao();
void deleteHD1();
void deleteNormal();
void deleteTrang();
int boxGioiTinh();
int boxYNVe();
string CMNDrong(TREE root, string s);
void docFileHanhKhach(TREE& t);
void ghiFileHanhKhach(TREE& t);
int ktTrungCMND(TREE t, string CMND);
HanhKhach* khoiTaoNodeHanhKhach(string CMND);
void themHKvaoTree(TREE& t, HanhKhach* ptrHK);
int themHKdatVe(DS_HANHKHACH& ds, string CMND);
void inTTHanhKhach(TREE& t, string CMND, int h);
void xem_cb(DS_CHUYEN_BAY& First, DS_MAYBAY& mb, chuyen_bay* ds_cb[]);
void inDSVe(int a, int* b)
{
	int j = 1;
	int k = 6;
	int* f = new int[a];
	gotoXY(1, 5);
	for (int i = 1; i <= a; i++)
	{
		if (b[j] == i)
		{
			SetbgColor(12);
			cout << setw(4) << i;
			//b[i] = b[j];
			//f[j] = b[j];
			j++;
		}
		else
		{
			SetbgColor(0);
			cout << setw(4) << i;
		}
		if (i % 10 == 0)
		{
			gotoXY(1, k);
			k++;
		}
	}
}

void ktTrungCMNDdatve(chuyenbay ds[], TREE t, int x, int y)
{
	int i = x + 10 * (y - 1);
	if (t != NULL)
	{
		if (ds->ds_ve.cmnd[i] == t->cmnd)
		{
			gotoXY(70, 12);
			cout << "CHUNG MINH NHAN DAN: " << t->cmnd;
			gotoXY(70, 13);
			cout << "HO: " << t->ho;
			gotoXY(70, 14);
			cout << "TEN: " << t->ten;
			gotoXY(70, 15);
			cout << "GIOI TINH: " << t->phai;
		}
		ktTrungCMNDdatve(ds, t->left, x, y);
		ktTrungCMNDdatve(ds, t->right, x, y);
	}

}

void layTTVe(string CMND, TREE t)
{
	if (t != NULL)
	{
		if (CMND == t->cmnd)
		{
			gotoXY(70, 12);
			cout << "CHUNG MINH NHAN DAN: " << t->cmnd;
			gotoXY(70, 13);
			cout << "HO: " << t->ho;
			gotoXY(70, 14);
			cout << "TEN: " << t->ten;
			gotoXY(70, 15);
			cout << "GIOI TINH: " << t->phai;
		}
		layTTVe(CMND, t->left);
		layTTVe(CMND, t->right);
	}
}

void ttVe(chuyenbay ds[], TREE t, int x, int y)
{
	Time();
	int i = 0;
	int j = 0;
	while (i < 12)
	{
		gotoXY(61 + j, 9 + i);
		cout << " ";
		j++;
		if (j == 40)
		{
			i++;
			j = 0;
		}
	}
	ktTrungCMNDdatve(ds, t, x, y);
}

void delttVe()
{
	int i = 0, j = 0;
	while (i < 12)
	{
		gotoXY(61 + j, 9 + i); cout << " ";
		j++;
		if (j == 40)
		{
			i++;
			j = 0;
		}
	}
}

//void sapxeptheoSttVe(VE& list, MAY_BAY mb)
//{
//	int i, j;
//	for (i = 0; i < mb.socho - 1; i++)
//	{
//		for (j = mb.socho - 1; j > i; j--)
//		{
//			if (list.n[j].maVe > list.n[j - 1].maVe)
//			{
//				ve temp = list.n[j];
//				list.n[j] = list.n[j - 1];
//				list.n[j - 1] = temp;
//			}
//		}
//	}
//}

//void sapxeptheoCMND(VE& list, MAY_BAY mb)
//{
//	int i, j;
//	for (i = 0; i < mb.socho - 1; i++)
//	{
//		for (j = mb.socho - 1; j > i; j--)
//		{
//			if (list.cmnd[j - 1].length() > list.cmnd[j].length())
//			{
//				ve temp = list.cmnd[j];
//				list.cmnd[j] = list.cmnd[j - 1];
//				list.cmnd[j - 1] = temp;
//			}
//		}
//	}
//}

//=======================Xu ly chuc nang==================
int XuLy(chuyenbay cb[], DS_HANHKHACH& ds_hk, DS_CHUYEN_BAY& ds_cb, int a, int* b, int x, int y)
{
main:
	x = whereX();
	y = whereY();
	int x1 = 1, y1 = 1, j = 1;
	int key;
	string CMND;
	do
	{
		key = _getch();
		if ((int)key == 72 && y > 5)
		{
			if (b[j] == 10 * (y1 - 1) + x1)
			{
				j = j - 10;
				gotoXY(x - 4, y);
				SetbgColor(12);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = whereX() - 4;
				y = whereY() - 1;
				y1--;
				gotoXY(x, y);
				SetbgColor(Grey);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = whereY();//Y
				x = whereX();//X
				SetbgColor(0);
				ttVe(cb, ds_hk.tree, x1, y1);
				gotoXY(x, y);
			}
			else
			{
				j = j - 10;
				gotoXY(x - 4, y);
				SetbgColor(0);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = whereX() - 4;
				y = whereY() - 1;
				y1--;
				gotoXY(x, y);
				SetbgColor(Grey);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = whereY();
				x = whereX();
				SetbgColor(0);
				ttVe(cb, ds_hk.tree, x1, y1);
				gotoXY(x, y);
			}
		}
		if ((int)key == 80 && y < a / 10 + 5 && 10 * (y1 - 1) + x1 + 9 < a)
		{
			if (b[j] == 10 * (y1 - 1) + x1)
			{
				j = j + 10;
				gotoXY(x - 4, y);
				SetbgColor(12);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = whereX() - 4;
				y = whereY() + 1;
				y1++;
				gotoXY(x, y);
				SetbgColor(Grey);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = whereY();
				x = whereX();
				SetbgColor(0);
				ttVe(cb, ds_hk.tree, x1, y1);
				gotoXY(x, y);
			}
			else
			{
				j = j + 10;
				gotoXY(x - 4, y);
				SetbgColor(0);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = whereX() - 4;
				y = whereY() + 1;
				y1++;
				gotoXY(x, y);
				SetbgColor(Grey);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = whereY();
				x = whereX();
				SetbgColor(0);
				ttVe(cb, ds_hk.tree, x1, y1);
				gotoXY(x, y);
			}
		}
		if ((int)key == 75 && x > 5)
		{
			if (b[j] == 10 * (y1 - 1) + x1)
			{
				j--;
				gotoXY(x - 4, y);
				SetbgColor(12);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = whereX() - 4 - 4;
				y = whereY();
				x1--;
				gotoXY(x, y);
				SetbgColor(Grey);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = whereY();
				x = whereX();
				SetbgColor(0);
				ttVe(cb, ds_hk.tree, x1, y1);
				gotoXY(x, y);
			}
			else
			{
				j--;
				gotoXY(x - 4, y);
				SetbgColor(0);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = whereX() - 4 - 4;
				y = whereY();
				x1--;
				gotoXY(x, y);
				SetbgColor(Grey);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = whereY();
				x = whereX();
				SetbgColor(0);
				ttVe(cb, ds_hk.tree, x1, y1);
				gotoXY(x, y);
			}
		}
		if ((int)key == 77 && x < (4 * 10) && 10 * (y1 - 1) + x1 < a)
		{
			if (b[j] == 10 * (y1 - 1) + x1)
			{
				j++;
				gotoXY(x - 4, y);
				SetbgColor(12);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = whereX();
				y = whereY();
				x1++;
				gotoXY(x, y);
				SetbgColor(Grey);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = whereY();
				x = whereX();
				SetbgColor(0);
				ttVe(cb, ds_hk.tree, x1, y1);
				gotoXY(x, y);
			}
			else
			{
				j++;
				gotoXY(x - 4, y);
				SetbgColor(0);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				x = whereX();
				y = whereY();
				x1++;
				gotoXY(x, y);
				SetbgColor(Grey);
				cout << setw(4) << 10 * (y1 - 1) + x1;
				y = whereY();
				x = whereX();
				SetbgColor(0);
				ttVe(cb, ds_hk.tree, x1, y1);
				gotoXY(x, y);
			}
		}
		if (key == 27)
		{
			system("cls");
			return 1;
		}
	} while (key != 13 || b[j] == 10 * (y1 - 1) + x1);
	int i = 10 * (y1 - 1) + x1;
	gotoXY(66, 11); cout << "BAN CO CMND KHONG?";
	if (boxYNVe() == 0)
	{
		int t = 0;
		delttVe();
		string CMND;
		CMND = CMNDrong(ds_hk.tree, "000000000000");
		if (themHKdatVe(ds_hk, CMND) == 0) return 0;
		cb->ds_ve.cmnd[i] = CMND;
		cb->ds_ve.sl_da_ban = cb->ds_ve.sl_da_ban + 1;
		cb->ds_ve.sl_con = cb->ds_ve.sl_con - 1;
		if (cb->ds_ve.sl_con != 0)//chinh trang thai
		{
			cb->trangthai = 1;
		}
		else if (cb->ds_ve.sl_con == 0)
		{
			cb->trangthai = 2;
		}
	}
	else
	{
		int u = 0;
		delttVe();
		gotoXY(62, 12);
		cout << "CHUNG MINH NHAN DAN: ";
		do
		{
			for (int i = 1; i <= 12; i++)
			{
				gotoXY(82 + i, 12);
				cout << " ";
			}
			CMND = chanSo(11, 83, 12);
			if (CMND[u] == '.')
			{
				system("cls");
				return 0;
			}
			if (CMND.length() != 12)
			{
				gotoXY(83, 12);
				cout << "KHONG HOP LE!";
				//Sleep(2000);
				_getch();
			}
			u++;
		} while (CMND[0] == '\0' || CMND.length() != 12);
		for (int k = 0; k < cb->ds_ve.n + 1; k++)//kiem tra xem co cmnd nay tren chuyen bay chua
		{
			if (cb->ds_ve.cmnd[k] == CMND)
			{
				system("cls");
				box_nho(10, 13, 100, 3);
				gotoXY(30, 14); cout << "HANH KHACH DA DAT TREN CHUYEN BAY NAY ROI!";
				_getch();
				system("cls");
				return 1;
			}
		}
		DS_CHUYEN_BAY ds_cb1 = ds_cb;
		while (ds_cb1 != NULL)
		{
			if (ds_cb1->cb.trangthai != 3 || ds_cb1->cb.trangthai != 0)
			{
				for (int i = 0; i <= ds_cb1->cb.ds_ve.n; i++)
				{
					if (CMND == ds_cb1->cb.ds_ve.cmnd[i])
					{
						if (ds_cb1->cb.ngay == cb->ngay && abs(ds_cb1->cb.gio - cb->gio < 10))
						{
							system("cls");
							box_nho(10, 13, 100, 3);
							gotoXY(15, 14);
							cout << "HANH KHACH DA DAT VE 10 GIO TRUOC. VUI LONG HUY VE VA DAT LAI!";
							//Sleep(2000);
							_getch();
							return 1;
						}
					}
				}
			}
			ds_cb1 = ds_cb1->next;
		}
		if (ktTrungCMND(ds_hk.tree, CMND) == 1)//kiem tra ton tai cmnd chua
		{
			delttVe();
			layTTVe(CMND, ds_hk.tree);
			_getch();
			system("cls");
			cb->ds_ve.cmnd[i] = CMND;
			cb->ds_ve.sl_da_ban = cb->ds_ve.sl_da_ban + 1;
			cb->ds_ve.sl_con = cb->ds_ve.sl_con - 1;
			if (cb->ds_ve.sl_con != 0)
			{
				cb->trangthai = 1;
			}
			else if (cb->ds_ve.sl_con == 0)
			{
				cb->trangthai = 2;
			}
		}
		else
		{
			if (themHKdatVe(ds_hk, CMND) == 0) return 0;
			cb->ds_ve.cmnd[i] = CMND;
			cb->ds_ve.sl_da_ban = cb->ds_ve.sl_da_ban + 1;
			cb->ds_ve.sl_con = cb->ds_ve.sl_con - 1;
			if (cb->ds_ve.sl_con != 0)
			{
				cb->trangthai = 1;
			}
			else if (cb->ds_ve.sl_con == 0)
			{
				cb->trangthai = 2;
			}
		}
	}
	system("cls");
	return 1;
}
int boxYNVe()
{
	box_nho(64, 10, 34, 5);
	gotoXY(78, 12); cout << "YES";
	gotoXY(78, 13); cout << "NO";
	gotoXY(74, 12); cout << "=>";
	int k = 12;
	char c;
	do
	{
		c = _getch();
		if (c == 72)
		{
			if (k > 12)
			{
				k = k - 1;
			}
		}
		else if (c == 80)
		{
			if (k < 13)
			{
				k += 1;
			}

		}
		if (k > 12)
		{
			gotoXY(74, k - 1);
			printf("  ");
		}
		if (k < 13)
		{
			gotoXY(74, k + 1);
			printf("  ");

		}
		cout << "  ";
		gotoXY(74, k);
		cout << "=>";
	} while (c != 13);
	switch (k)
	switch (k)
	{
	case 12:
	{
		return 1;
	}
	case 13:
	{
		return 0;
	}
	}
}
int boxGioiTinh()
{
	
	box_nho(64, 19, 10, 5);
	gotoXY(66, 20); cout << "GIOI TINH";
	gotoXY(68, 21); cout << "NAM";
	gotoXY(68, 22); cout << "NU";
	gotoXY(65, 21); cout << "=>";
	int k = 21;
	char c;
	do
	{
		c = getKey();
		if (c == Up)
		{
			if (k > 21)
			{
				k = k - 1;
			}
		}
		else if (c == Down)
		{
			if (k < 22)
			{
				k += 1;
			}

		}
		if (k != 21)
		{
			gotoXY(65, k - 1);
			printf("  ");
		}
		if (k != 23)
		{
			gotoXY(65, k + 1);
			printf(" ");

		}
		cout << "  ";
		gotoXY(65, k);
		cout << "=>";
	} while (c != Enter);
	switch (k)
	{
	case 21:
	{
		int i = 0;
		int j = 0;
		while (i <= 5)
		{
			gotoXY(63 + j, 19 + i);
			cout << " ";
			if (j == 12)
			{
				i++;
				j = 0;
			}
			j++;
		}
		return 1;
	}
	case 22:
	{
		int i = 0;
		int j = 0;
		while (i <= 5)
		{
			gotoXY(63 + j, 19 + i);
			cout << " ";
			if (j == 12)
			{
				i++;
				j = 0;
			}
			j++;
		}
		return 0;
	}
	}
}

string CMNDrong(TREE root, string s)
{
	string result;
	int n, i = 0;
	char* tmp = new char[12];
	while (s[i] != '\0')
	{
		tmp[i] = s[i];
		i++;
		tmp[i] = '\0';
	}
	n = atoi(tmp);
	do
	{
		ostringstream convert;
		n++;
		if (n < 10)
		{
			convert << n;
			result = "00000000000" + convert.str();
		}
		else if (n >= 10)
		{
			convert << n;
			result = "0000000000" + convert.str();
		}
		else if (n >= 100)
		{
			convert << n;
			result = "000000000" + convert.str();
		}

	} while (ktTrungCMND(root, result) == 1);
	return result;
}
int themHKdatVe(DS_HANHKHACH& ds_hk, string CMND)
{
	HanhKhach* hk;
	char* tmp;
	int i = 0;
	hk = khoiTaoNodeHanhKhach(CMND);
	gotoXY(70, 13);
	cout << "NHAP HO: ";
	do
	{
		tmp = chanChuoi(50, 80, 13);
		if (tmp[0] == '.') return 0;
	} while (tmp[0] == '\0');
	while (tmp[i] != '\0')
	{
		hk->ho[i] = tmp[i];
		i++;
		hk->ho[i] = '\0';
	}
	gotoXY(70, 14);
	cout << "NHAP TEN: ";
	do
	{
		tmp = chanChuoi(10, 80, 14);
		if (tmp[0] == '.') return 0;
	} while (tmp[0] == '\0');
	i = 0;
	while (tmp[i] != '\0')
	{
		hk->ten[i] = tmp[i];
		i++;
		hk->ten[i] = '\0';
	}
	gotoXY(70, 15);
	cout << "NHAP GIOI TINH: ";
	if (boxGioiTinh() == 1)
	{
		hk->phai[0] = 'N';
		hk->phai[1] = 'A';
		hk->phai[2] = 'M';
		hk->phai[3] = '\0';
	}
	else
	{
		hk->phai[0] = 'N';
		hk->phai[1] = 'U';
		hk->phai[2] = '\0';
	}
	gotoXY(86, 15); cout << hk->phai;
	gotoXY(70, 16); cout << "<ENTER> DE TIEP TUC!";
	_getch();
	themHKvaoTree(ds_hk.tree, hk);
	ds_hk.slHK++;
	system("cls");
	return 1;
}
void datVe(chuyenbay* cb[], DS_CHUYEN_BAY& ds_cb, DS_HANHKHACH& ds_hk, DS_MAYBAY& ds_mb)
{
	int movX = 60, movY = 8, movSX = 105, movSY = -2;
xuly:
	deleteNormal();
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MBMAX];
	deleteHD1();
	ButtonDatVe(255);
	ButtonHuyVe(255);
	ButtonEnter(255);
	ButtonESC(255);
	SetbgColor(0);

	TableListCB();
	Time();
	box_nho(15 + movX, 28 + movY, 15, 2);
	gotoXY(16 + movX, 29 + movY); printf("<ESC> QUAY LAI");
	box_nho(32 + movX, 28 + movY, 16, 2);
	gotoXY(33 + movX, 29 + movY); cout << "<ENTER> CHON";
	readfile_cb(ds_cb);
	readfile_plane(ds_mb);
	docFileHanhKhach(ds_hk.tree);
	Print_cb_to_arr(ds_cb, cb);
	result_flight(ds_cb, cb);
	gotoXY(x3 + 50, y3); cout << "DAT VE MAY BAY";
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
	} while (c != Enter || cb[a[p]]->trangthai == 3 || cb[a[p]]->trangthai == 0);
	system("cls");
	//deleteNormal();
	deleteNormal();
	chuyenbay cb1;
	int slve, X, Y, vitri = 1;
	slve = cb[a[p]]->ds_ve.n;
	int* sttve = new int[slve];
	int* ve = new int[slve];
	for (int i = 1; i < cb[a[p]]->ds_ve.n + 1; i++)
	{
		if (cb[a[p]]->ds_ve.cmnd[i].length() == 12)
		{
			ve[vitri] = i;
			vitri++;
		}
	}
xuly1:
	system("cls");
	box_nho(5, 32, 15, 2);
	gotoXY(6, 33); printf("<ESC> Quay lai");
	box_nho(22, 32, 16, 2);
	gotoXY(24, 33); cout << "<ENTER> de chon";
	cout << endl;
	box_nho(0, 0, 41, 30);
	box_kexy(0, 3, 41);
	box_nho(60, 5, 41, 20);
	box_kexy(60, 8, 41);
	gotoXY(75, 7); cout << "THONG TIN";
	gotoXY(5, 1); cout << "DAT VE CUA CHUYEN BAY: " << cb[a[p]]->machuyenbay;
	gotoXY(1, 5);
	X = whereX();
	Y = whereY();
	inDSVe(slve, ve);
	int j = 1;
	for (int i = 1; i <= slve; i++)
	{
		if (ve[j] == i)
		{
			sttve[i] = ve[j];
			j++;
		}
	}
	gotoXY(X, Y);
	SetbgColor(Grey);
	cout << setw(4) << X + 10 * (Y - 5);
	SetbgColor(Black);
	ttVe(cb[a[p]], ds_hk.tree, X, Y - 4);
	gotoXY(X, Y);
	int xl = XuLy(cb[a[p]], ds_hk, ds_cb, slve, sttve, X, Y);
	if (xl == 0)
	{
		//deleteNormal();
		system("cls");
		goto xuly1;
	}
	else
	{
		gotoXY(5 + movX, movY + 25);
		int slcb = dem(ds_cb);
		clearlist(ds_cb);
		for (int i = 0; i < slcb; i++)
		{
			cb1.ds_ve.cmnd = new string[cb[i]->ds_ve.n + 1];
			strcpy_s(cb1.machuyenbay, cb[i]->machuyenbay);
			strcpy_s(cb1.sohieu, cb[i]->sohieu);
			strcpy_s(cb1.sanbay, cb[i]->sanbay);
			cb1.ngay = cb[i]->ngay;
			cb1.thang = cb[i]->thang;
			cb1.nam = cb[i]->nam;
			cb1.gio = cb[i]->gio;
			cb1.phut = cb[i]->phut;
			cb1.ds_ve.n = cb[i]->ds_ve.n;
			cb1.trangthai = cb[i]->trangthai;
			cb1.ds_ve.sl_con = cb[i]->ds_ve.sl_con;
			cb1.ds_ve.sl_da_ban = cb[i]->ds_ve.sl_da_ban;
			for (int slve = 1; slve < cb[i]->ds_ve.n + 1; slve++)
				cb1.ds_ve.cmnd[slve] = cb[i]->ds_ve.cmnd[slve];
			insert_last(ds_cb, cb1);
		}
		system("cls");
		boxThongBao();
		gotoXY(x3 + 18, y2 + 1); SetColor(Blue); cout << "DAT VE THANH CONG!";
		Sleep(1000);
		/*writefile_flight(ds_cb);
		ghiFileHanhKhach(ds_hk.tree);*/
		system("cls");
		goto xuly;
	}

}
void huyVe(chuyenbay* cb[], DS_CHUYEN_BAY& ds_cb, HanhKhach* hk[], DS_HANHKHACH& ds_hk, DS_MAYBAY& ds_mb)
{
	int movX = 60, movY = 8, movSX = 105, movSY = -2;
xuly:
	char c;
	char* b = new char[14];
	int i = 0;
	int u = 0;
	int a[MBMAX];
	deleteNormal();
	deleteHD1();
	ButtonDatVe(255);
	ButtonHuyVe(255);
	ButtonEnter(255);
	ButtonESC(255);
	SetbgColor(0);

	TableListCB();
	Time();
	box_nho(15 + movX, 28 + movY, 15, 2);
	gotoXY(16 + movX, 29 + movY); printf("<ESC> QUAY LAI");
	box_nho(32 + movX, 28 + movY, 16, 2);
	gotoXY(33 + movX, 29 + movY); cout << "<ENTER> CHON";
	readfile_cb(ds_cb);
	readfile_plane(ds_mb);
	docFileHanhKhach(ds_hk.tree);
	Print_cb_to_arr(ds_cb, cb);
	result_flight(ds_cb, cb);
	gotoXY(x3 + 50, y3); cout << "HUY VE MAY BAY";
	connhay_on();
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
	} while (c != Enter || cb[a[p]]->trangthai == 3 || cb[a[p]]->trangthai == 0);
	system("cls");
	//==============================
main:
	//system("cls");
	deleteNormal();
	Time();

	box_nho(15 + movX, 27 + movY, 15, 2);
	gotoXY(16 + movX, 28 + movY); printf("<ESC> QUAY LAI");
	box_nho(32 + movX, 27 + movY, 16, 2);
	gotoXY(33 + movX, 28 + movY); cout << "<ENTER> CHON";
	gotoXY(15 + movX, 3 + movY); cout << "SEARCH CMND: ";
	gotoXY(5 + movX, 5 + movY);
	cout << "STT";
	gotoXY(20 + movX, 5 + movY);
	cout << "SO THU TU VE";
	gotoXY(45 + movX, 5 + movY);
	cout << "CHUNG MINH NHAN DAN";
	gotoXY(80 + movX, 5 + movY);
	cout << "HO VA TEN";
	gotoXY(106 + movX, 5 + movY);
	cout << "PHAI";
	int dem = 0, trang1 = 0, tong1 = 0;
	if (cb[a[p]]->ds_ve.sl_da_ban == 18)
	{
		tong1 = 1;
		trang1 = 0;
	}
	else
	{
		tong1 = (cb[a[p]]->ds_ve.sl_da_ban) / 18 + 1;
	}
	box(100 + movX, 27 + movY, 15, 1, White);
	gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
	int* slban = new int[cb[a[p]]->ds_ve.sl_da_ban];
	for (int i = 1; i <= cb[a[p]]->ds_ve.n; i++)
	{
		if (cb[a[p]]->ds_ve.cmnd[i].length() == 12)
		{
			slban[dem] = i;
			dem++;
		}
	}
	int k = 0, m = 0;
	int* slban1 = new int[cb[a[p]]->ds_ve.n + 1];
	for (int i = 0; i <= cb[a[p]]->ds_ve.sl_da_ban - 1; i++)
	{
		if (ktTrungCMND(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]]) == 12)
		{
			if (k == 18) break;
			gotoXY(5 + movX, 7 + k + movY); cout << k;
			gotoXY(19 + movX, 7 + k + movY); cout << cb[a[p]]->ds_ve.cmnd[slban[i]];
			inTTHanhKhach(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]], k);
			gotoXY(11 + movX, 7 + k + movY); cout << slban[i];
			connhay_off();
			k++;
		}
	}
	do
	{
		c = _getch();
		if (i <= 14 && c >= 48 && c <= 57)
		{
			u = 0;
			if (c >= 97 && c <= 122)
			{
				gotoXY(27 + i + movX, 3 + movY);
				b[i] = c - 32;
				cout << b[i];
			}
			else
			{
				gotoXY(27 + i + movX, 3 + movY);
				b[i] = c;
				cout << c;
			}
			i++;
			k = 0;
			int j = 0;
			connhay_off();
			while (j <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 6; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 21; i++)
				{
					gotoXY(17 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 61; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 9; i++)
				{
					gotoXY(101 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			b[i] = '\0';
			string tim_maybay = b;
			connhay_off();
			k = 0;
			string temp;
			for (int i = 0; i <= cb[a[p]]->ds_ve.sl_da_ban - 1; i++)
			{
				temp = cb[a[p]]->ds_ve.cmnd[slban[i]];
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					if (temp[j] != tim_maybay[j]) break;
					if (ktTrungCMND(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]]) == 1)
					{
						if (j == tim_maybay.length() - 1)
						{
							if (k == 18) break;
							gotoXY(5 + movX, 7 + k + movY); cout << k;
							gotoXY(19 + movX, 7 + k + movY); cout << cb[a[p]]->ds_ve.cmnd[slban[i]];
							inTTHanhKhach(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]], k);
							gotoXY(11 + movX, 7 + k + movY); cout << slban[i];
							connhay_off();
							k++;
						}
					}
				}
			}
			gotoXY(27 + i + movX, 3 + movY);
			connhay_on();
		}
		if (c == Backspace && i > 0)
		{
			gotoXY(27 + i + movX, 3 + movY);
			cout << " ";
			gotoXY(27 + i + movX, 3 + movY);
			i--;
			b[i] = '\0';
			string tim_maybay;
			tim_maybay = b;
			connhay_off();
			k = 0;
			string temp;
			for (int i = 0; i <= cb[a[p]]->ds_ve.sl_da_ban - 1; i++)
			{
				for (int j = 0; j < tim_maybay.length(); j++)
				{
					temp = cb[a[p]]->ds_ve.cmnd[slban[i]];
					if (temp[j] != tim_maybay[j]) break;
					if (ktTrungCMND(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]]) == 1)
					{
						if (j == tim_maybay.length() - 1)
						{
							if (k == 18) break;
							gotoXY(5 + movX, 7 + k + movY); cout << k;
							gotoXY(19 + movX, 7 + k + movY); cout << cb[a[p]]->ds_ve.cmnd[slban[i]];
							inTTHanhKhach(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]], k);
							gotoXY(11 + movX, 7 + k + movY); cout << slban[i];
							connhay_off();
							k++;
						}
					}
				}
			}
		}
		gotoXY(27 + i + movX, 3 + movY);
		connhay_on();
		if (b[0] == '\0')
		{
			k = 0;
			for (int i = 0; i <= cb[a[p]]->ds_ve.sl_da_ban - 1; i++)
			{
				if (ktTrungCMND(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]]) == 1)
				{
					if (k == 18) break;
					gotoXY(5 + movX, 7 + k + movY); cout << k;
					gotoXY(19 + movX, 7 + k + movY); cout << cb[a[p]]->ds_ve.cmnd[slban[i]];
					inTTHanhKhach(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]], k);
					gotoXY(11 + movX, 7 + k + movY); cout << slban[i];
					connhay_off();
					k++;
				}
			}
		}
		gotoXY(27 + i + movX, 3 + movY);
		if (c == ESC) goto xuly;
		//connhay_on();
	} while (c != Enter);
	connhay_off();
	int x = 0, y = 0;
xuly1:
	f = 7;

	gotoXY(1 + movX, 7 + movY);  cout << "=>";
	do
	{
		gotoXY(101 + movX, 28 + movY); cout << "Trang: " << trang + 1 << "/" << tong;
		c = _getch();
		if (f <= 7 && tong1 > 1 && trang1 > 0 && c == 72)
		{
			gotoXY(2 + movX, 7 + movY);
			cout << "   ";
			f = 25;
			trang1--;
			int k = 0, j = 0;
			while (m <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 6; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 21; i++)
				{
					gotoXY(17 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 61; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 9; i++)
				{
					gotoXY(101 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			for (int i = trang1 * 18 + 0; i <= cb[a[p]]->ds_ve.sl_da_ban - 1 && i <= 18 + trang1 * 18; i++)
			{
				if (ktTrungCMND(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]]) == 1)
				{
					if (n == 18) break;
					gotoXY(5 + movX, 7 + k + movY); cout << k;
					gotoXY(19 + movX, 7 + k + movY); cout << cb[a[p]]->ds_ve.cmnd[slban[i]];
					inTTHanhKhach(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]], k);
					gotoXY(11 + movX, 7 + k + movY); cout << slban[i];
					connhay_off();
					k++;
				}
			}
		}
		if (c == 72)
		{
			if (f > 7)
			{
				f -= 1;
				x--;

			}
		}
		else if (c == 80)
		{
			if (f < dem + 6 && x <= dem - 2)
			{
				f += 1;
				x++;
			}
		}
		if (c == 27) goto xuly;
		if (f != 7)
		{
			gotoXY(movX, f - 1 + movY);
			printf("  ");
		}
		if (f != 7 + dem)
		{
			gotoXY(movX, f + 1 + movY);
			printf("  ");
		}
		if (f == 25 && tong1 > 1 && trang1 + 1 < tong1)
		{
			trang1++;
			int k = 0, j = 0;
			while (m <= 18)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoXY(5 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 6; i++)
				{
					gotoXY(10 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 21; i++)
				{
					gotoXY(17 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 61; i++)
				{
					gotoXY(39 + i + movX, j + 7 + movY);
					cout << " ";
				}
				for (int i = 0; i < 9; i++)
				{
					gotoXY(101 + i + movX, j + 7 + movY);
					cout << " ";
				}
				j++;
			}
			for (int i = trang1 * 18 + 0; i <= cb[a[p]]->ds_ve.sl_da_ban - 1 && i <= 18 + trang1 * 18; i++)
			{
				if (ktTrungCMND(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]]) == 1)
				{
					if (n == 18) break;
					gotoXY(5 + movX, 7 + k + movY); cout << k;
					gotoXY(19 + movX, 7 + k + movY); cout << cb[a[p]]->ds_ve.cmnd[slban[i]];
					inTTHanhKhach(ds_hk.tree, cb[a[p]]->ds_ve.cmnd[slban[i]], k);
					gotoXY(11 + movX, 7 + k + movY); cout << slban[i];
					connhay_off();
					k++;
				}
			}
			goto xuly1;
		}
		cout << " ";
		gotoXY(1 + movX, f + movY);
		cout << "=>";
	} while (c != 13);

	//==========================
	DS_CHUYEN_BAY ds_cb1;
	ds_cb1 = ds_cb;
	while (ds_cb1 != NULL)
	{
		for (int i = 0; i < ds_cb1->cb.ds_ve.n; i++)
		{
			if (ds_cb1->cb.ds_ve.cmnd[i] == cb[a[p]]->ds_ve.cmnd[slban[x]])
			{
				ds_cb1->cb.ds_ve.cmnd[i] == "";
				ds_cb1->cb.ds_ve.sl_con = ds_cb1->cb.ds_ve.sl_con + 1;
				ds_cb1->cb.ds_ve.sl_da_ban = ds_cb1->cb.ds_ve.sl_da_ban - 1;
			}
		}
		ds_cb1 = ds_cb1->next;
	}
	//system("cls");
	deleteNormal();
	Time();
	gotoXY(175 + movX , 14 ); cout << "BAN CHAC CHAN HUY VE?";
	yes_no_fl(ds_cb);
	goto xuly;
}

