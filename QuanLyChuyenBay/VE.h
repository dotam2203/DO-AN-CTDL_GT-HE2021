#pragma once
#include "KhaiBao.h"
#include "MyLib.h"
#include "DocGhiFile.h"
#include "ChuyenBay.h"
#include "MayBay.h"

using namespace std;
///*======================= Quan ly ve may bay - Danh sach tuyen tinh cap phat dong ======================*/
int boxGioiTinh();
int boxYNVe();
string CMNDrong(TREE root, string s);
void docFileHanhKhach(TREE& t);
void ghiFileHanhKhach(TREE& t);

void inDSVe(int a, int* b)
{
	int j = 1, k = 6;
	int* n = new int[a];
	gotoXY(x3, y2 + 5);
	for (int i = 1; i <= a; i++)
	{
		if (b[j] == i)
		{
			SetbgColor(Yellow);
			cout << setw(4) << i;
		}
		else
		{
			SetbgColor(White);
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
			gotoXY(x3 + 20, y2 + 12);
			cout << "CHUNG MINH NHAN DAN: " << t->cmnd;
			gotoXY(x3 + 20, y2 + 14);
			cout << "HO: " << t->ho;
			gotoXY(x3 + 20, y2 + 16);
			cout << "TEN: " << t->ten;
			gotoXY(x3 + 20, y2 + 18);
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
			gotoXY(x3 + 20, y2 + 12);
			cout << "CHUNG MINH NHAN DAN: " << t->cmnd;
			gotoXY(x3 + 20, y2 + 14);
			cout << "HO: " << t->ho;
			gotoXY(x3 + 20, y2 + 16);
			cout << "TEN: " << t->ten;
			gotoXY(x3 + 20, y2 + 18);
			cout << "GIOI TINH: " << t->phai;
		}
		layTTVe(CMND, t->left);
		layTTVe(CMND, t->right);
	}
}

void ttVe(chuyenbay ds[], TREE t, int x, int y)
{
	Time();
	int i = 0, j = 0;
	while (i < 12)
	{
		gotoXY(x1 + j, y2 + i); cout << " ";
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
		gotoXY(x3 + j, y2 + i); cout << " ";
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
int XuLy(chuyenbay cb[], DS_HANHKHACH& ds_hk, DS_CHUYEN_BAY& ds_cb, int a, int* b, int X, int Y)
{
main:
	X = whereX();
	Y = whereY();
	int x = x3 + 1, y = y2 + 1, i = 1;
	char c = getKey();
	string CMND;
	do
	{
		if (c == Up && Y > 5)
		{
			if (b[i] == x + 10 * (y - 1))
			{
				i -= 10;
				gotoXY(X - 4, Y);
				SetbgColor(Yellow);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX() - 4;
				Y = whereY() - 1;
				y--;
				gotoXY(X, Y);
				SetbgColor(Cyan);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX();
				Y = whereY();
				SetbgColor(Grey);
				ttVe(cb, ds_hk.tree, x, y);
				gotoXY(x, y);
			}
			else
			{
				i -= 10;
				gotoXY(X - 4, Y);
				SetbgColor(Grey);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX() - 4;
				Y = whereY() - 1;
				y--;
				gotoXY(X, Y);
				SetbgColor(Yellow);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX();
				Y = whereY();
				SetbgColor(Grey);
				ttVe(cb, ds_hk.tree, x, y);
				gotoXY(x, y);
			}
		}
		if (c == Down && Y < a / 10 + 5 && x + 9 + (y - 1) < a)
		{
			if (b[i] == x + 10 * (y - 1))
			{
				i += 10;
				gotoXY(X - 4, Y);
				SetbgColor(Yellow);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX() - 4;
				Y = whereY() - 1;
				y++;
				gotoXY(X, Y);
				SetbgColor(Cyan);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX();
				Y = whereY();
				SetbgColor(Grey);
				ttVe(cb, ds_hk.tree, x, y);
				gotoXY(x, y);
			}
			else
			{
				i += 10;
				gotoXY(X - 4, Y);
				SetbgColor(Grey);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX() - 4;
				Y = whereY() - 1;
				y++;
				gotoXY(X, Y);
				SetbgColor(Yellow);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX();
				Y = whereY();
				SetbgColor(Grey);
				ttVe(cb, ds_hk.tree, x, y);
				gotoXY(x, y);
			}
		}
		if (c == Left && X > 5)
		{
			if (b[i] == x + 10 * (y - 1))
			{
				i--;
				gotoXY(X - 4, Y);
				SetbgColor(Yellow);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX() - 4 - 4;
				Y = whereY();
				x--;
				gotoXY(X, Y);
				SetbgColor(Cyan);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX();
				Y = whereY();
				SetbgColor(Grey);
				ttVe(cb, ds_hk.tree, x, y);
				gotoXY(x, y);
			}
			else
			{
				i--;
				gotoXY(X - 4, Y);
				SetbgColor(Grey);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX() - 4 - 4;
				Y = whereY();
				x--;
				gotoXY(X, Y);
				SetbgColor(Yellow);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX();
				Y = whereY();
				SetbgColor(Grey);
				ttVe(cb, ds_hk.tree, x, y);
				gotoXY(x, y);
			}
		}
		if (c == Right && X < 4 * 10 && x + 10 * (y - 1) < a)
		{
			if (b[i] == x + 10 * (y - 1))
			{
				i++;
				gotoXY(X - 4, Y);
				SetbgColor(Yellow);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX() - 4 - 4;
				Y = whereY();
				x++;
				gotoXY(X, Y);
				SetbgColor(Cyan);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX();
				Y = whereY();
				SetbgColor(Grey);
				ttVe(cb, ds_hk.tree, x, y);
				gotoXY(x, y);
			}
			else
			{
				i++;
				gotoXY(X - 4, Y);
				SetbgColor(Grey);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX() - 4 - 4;
				Y = whereY();
				x++;
				gotoXY(X, Y);
				SetbgColor(Yellow);
				cout << setw(4) << x + 10 * (y - 1);
				X = whereX();
				Y = whereY();
				SetbgColor(Grey);
				ttVe(cb, ds_hk.tree, x, y);
				gotoXY(x, y);
			}
		}
		if (c == ESC)
		{
			system("cls");
			return 1;
		}

	} while (c != Enter || b[i] == x + 10 * (y - 1));

	int j = x + 10 * (y - 1);
	gotoXY(x3 + 25, y2 + 12); cout << "BAN CO CMND KHONG?";
	if (boxYNVe() == 0)
	{
		delttVe();
		string CMND;
		CMND = CMNDrong(ds_hk.tree, "000000000000");

	}
}
int boxYNVe()
{
	box(x3 + 30, y2 + 16, 20, 2, White);
	gotoXY(x3 + 35, y2 + 17); cout << "YES";
	gotoXY(x3 + 35, y2 + 18); cout << "NO";
	gotoXY(x3 + 30, y2 + 18); cout << "=>";
	int k = y2 + 17;
	char c;
	do
	{
		c = getKey();
		if (c == Up)
		{
			if (k > y2 + 17)
				k -= 1;
		}
		else if (c == Down)
		{
			if (k < y2 + 18)
				k += 1;
		}
		if (k > y2 + 17)
		{
			gotoXY(x3 + 30, k - 1);
			cout << " ";
		}
		if (k < y2 + 18)
		{
			gotoXY(x3 + 30, k + 1);
			cout << " ";
		}
		cout << " ";
		gotoXY(x3 + 30, k); cout << "=>";
	} while (c != ESC);
	switch (k)
	{
	case (y2 + 17): return 1;
	case (y2 + 18):return 0;
	}
}
int boxGioiTinh()
{
	box(x3 + 15, y2 + 18, 10, 2, White);
	gotoXY(x3 + 20, y2 + 19); cout << "NAM";
	gotoXY(x3 + 20, y2 + 20); cout << "NU";
	gotoXY(x3 + 16, y2 + 19); cout << "=>";
	int k = y2 + 19;
	char c;
	do
	{
		c = getKey();
		if (c == Up)
		{
			if (k > 19)
				k -= 1;
		}
		else if (c == Down)
		{
			if (k < 20)
				k += 1;
		}
		if (k != 19)
		{
			gotoXY(x3 + 16, k - 1);
			cout << " ";
		}
		if (k != 21)
		{
			gotoXY(x3 + 16, k + 1);
			cout << " ";
		}
		cout << " ";
		gotoXY(x3 + 16, k);
	} while (c != ESC);
	switch (k)
	{
		case (y2 + 19):
		{
			int i = 0, j = 0;
			while (i <= 2)
			{
				gotoXY(x3 + 15 + j, y2 + 18 + i);
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
		case (y2 + 20):
		{
			int i = 0, j = 0;
			while (i <= 2)
			{
				gotoXY(x3 + 15 + j, y2 + 18 + i);
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
	//string t;
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
int themHKdatVe(DS_HANHKHACH& ds, string CMND)
{
	HanhKhach* hk;
	hk = khoiTaoNodeHanhKhach(CMND);
	char* tmp;
	int i = 0;
	/*gotoXY(x3 + 20, y2 + 12);
	cout << "CHUNG MINH NHAN DAN: " << t->cmnd;*/
	gotoXY(x3 + 20, y2 + 14);
	cout << "NHAP HO: ";
	do
	{
		tmp = chanChuoi(50, x3 + 30, y2 + 14);
		if (tmp[0] == '.') return 0;
	} while (tmp[0] == '\0');
	i = 0;
	while (tmp[i] != '\0')
	{
		hk->ho[i] = tmp[i];
		i++;
		hk->ho[i] = '\0';
	}

	gotoXY(x3 + 20, y2 + 16);
	cout << "NHAP TEN: ";
	do
	{
		tmp = chanChuoi(10, x3 + 30, y2 + 16);
		if (tmp[0] == '.') return 0;
	} while (tmp[0] == '\0');
	i = 0;
	while (tmp[i] != '\0')
	{
		hk->ten[i] = tmp[i];
		i++;
		hk->ten[i] = '\0';
	}

	gotoXY(x3 + 20, y2 + 18);
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
	gotoXY(x3 + 30, y2 + 18); cout << hk->phai;
	gotoXY(x3 + 50, y2 + 27); cout << "<ENTER> DE TIEP TUC!";
	_getch();
	themHKvaoTree(ds.tree, hk);
	ds.slHK++;
	system("cls");
	return 1;
}
void datVe(chuyenbay* cb[], DS_CHUYEN_BAY& ds_cb, DS_HANHKHACH& ds_hk, DS_MAYBAY& ds_mb)
{
	int movX = 60, movY = 8, movSX = 105, movSY = -2;
xuly:
	system("cls");
	char c;
	char* b = new char[14];
	int i = 0, u = 0, a[MBMAX];
	Time();
	readfile_cb(ds_cb);
	readfile_plane(ds_mb);
	docFileHanhKhach(ds_hk.tree);
	Print_cb_to_arr(ds_cb,cb);
	result_flight(ds_cb, cb);
	gotoXY(x3 + 30, y2); cout << "DAT VE MAY BAY";
	connhay_on();
	int trang = 0, tong = 0;
	if (dem(ds_cb) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else tong = (dem(ds_cb) / 18) + 1;
	//gotoXY(x3 + 60, y2 + 26);
	box(x3, y2+1, 100, 26, White);
	gotoXY(x3 + 80, y2 + 27);
	cout << "Trang: " << trang + 1 << "/" << tong;
	gotoXY(x4 + 5, y2); cout << "Search CB: ";
	connhay_on();
	do
	{
		c = getKey();
		connhay_on();
		if (c == Space || c >= 48 && c <= 122 && i <= 14)
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
						//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
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
			gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
			cout << " ";
			gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
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
						if (k == 26 + movY)break;
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
			}
			if (b[0] == '\0')
			{
				result_flight(ds_cb, cb);
				connhay_off();
			}
			gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
		}
		if (c == ESC) return;
	} while (c!=Enter);
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
data:
	f = 7;

	gotoXY(0 + movX, 7 + movY); cout << "==>";
	do
	{
		gotoXY(101 + movX, 28); cout << "Trang: " << trang + 1 << "/" << tong;
		c = getKey();
		if (f <= 7 && tong > 1 && trang > 0 && c == Up)
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
		gotoXY(0 + movX, f + movY);
		cout << "==>";
	} while (c != Enter || cb[a[p]]->trangthai == 3 || cb[a[p]]->trangthai == 0);
	system("cls");
	chuyenbay cb1;
	int slve, vitri = 1;
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
	gotoXY(x3 + 30, y2+4); cout << "DAT VE CUA CHUYEN BAY: "<<cb[a[p]]->machuyenbay;
	gotoXY(x3 + 30, y2 + 9);
	int X = whereX();
	int Y = whereY();
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
	ttVe(cb[a[p]], ds_hk.tree, X, Y);
	gotoXY(X, Y);
	int xl = XuLy(cb[a[p]], ds_hk, ds_cb, slve, ve, X, Y);
	if (xl == 0)
	{
		system("cls");
		goto xuly1;
	}
	else
	{
		gotoXY(x3, y2 + 16);
		int slcb = dem(ds_cb);
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
		gotoXY(x2 + 25, y2 + 9); SetColor(Red); cout << "DAT VE THANH CONG!";
		writefile_flight(ds_cb);
		ghiFileHanhKhach(ds_hk.tree);
		system("cls");
		goto xuly;
	}

}
void huyVe(chuyenbay* cb[], DS_CHUYEN_BAY& ds_cb, HanhKhach* hk[], DS_HANHKHACH& ds_hk, DS_MAYBAY& ds_mb)
{
	int movX = 60, movY = 8, movSX = 105, movSY = -2;
xuly:
	system("cls");
	char c;
	char* b = new char[14];
	int i = 0, u = 0, a[MBMAX];
	Time();
	readfile_cb(ds_cb);
	readfile_plane(ds_mb);
	docFileHanhKhach(ds_hk.tree);
	Print_cb_to_arr(ds_cb, cb);
	result_flight(ds_cb, cb);
	gotoXY(x3 + 30, y2); cout << "HUY VE MAY BAY";
	connhay_on();
	int trang = 0, tong = 0;
	if (dem(ds_cb) == 18)
	{
		trang = 0;
		tong = 1;
	}
	else tong = (dem(ds_cb) / 18) + 1;
	//gotoXY(x3 + 60, y2 + 26);
	box(x3, y2 + 1, 100, 26, White);
	gotoXY(x3 + 80, y2 + 27);
	cout << "Trang: " << trang + 1 << "/" << tong;
	gotoXY(x4 + 5, y2); cout << "Search CB: ";
	connhay_on();
	do
	{
		c = getKey();
		connhay_on();
		if (c == Space || c >= 48 && c <= 122 && i <= 14)
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
						//cout << mb.dsmaybay[ds_cb[i]->loai]->loaimaybay << endl;
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
			gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
			cout << " ";
			gotoXY(27 + i - 1 + movX + movSX, 3 + movY + movSY);
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
						if (k == 26 + movY)break;
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
			}
			if (b[0] == '\0')
			{
				result_flight(ds_cb, cb);
				connhay_off();
			}
			gotoXY(27 + i + movX + movSX, 3 + movY + movSY);
		}
		if (c == ESC) return;
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
data:
	f = 7;

	gotoXY(0 + movX, 7 + movY); cout << "==>";
	do
	{
		gotoXY(101 + movX, 28); cout << "Trang: " << trang + 1 << "/" << tong;
		c = getKey();
		if (f <= 7 && tong > 1 && trang > 0 && c == Up)
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
		gotoXY(0 + movX, f + movY);
		cout << "==>";
	} while (c != Enter || cb[a[p]]->trangthai == 3 || cb[a[p]]->trangthai == 0);
	system("cls");

main:
	system("cls");
	Time();
	gotoXY(15 + movX, 3 + movY); cout << "SEARCH CMND: ";
	gotoXY(5 + movX, 5 + movY);
	cout << "STT";
	gotoXY(10 + movX, 5 + movY);
	cout << "SO THU TU VE";
	gotoXY(18 + movX, 5 + movY);
	cout << "CHUNG MINH NHAN DAN";
	gotoXY(60 + movX, 5 + movY);
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
	gotoXY(101 + movX, 28); cout << "Trang: " << trang1 + 1 << "/" << tong1;
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
		c = getKey();
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
			gotoXY(27 + (i - 1) + movX, 3 + movY);
			cout << " ";
			gotoXY(27 + (i - 1) + movX, 3 + movY);
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
		connhay_on();
	} while (1);
	connhay_off();
	int x = 0, y = 0;
xuly1:
	f = 7;

	gotoXY(0 + movX, 7 + movY); cout << "==>";
	do
	{
		gotoXY(101 + movX, 28); cout << "Trang: " << trang1 + 1 << "/" << tong1;
		c = getKey();
		if (f <= 7 && tong1 > 1 && trang1 > 0 && c == Up)
		{
			gotoXY(0 + movX, 7 + movY);
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
			for (int i = trang1*18+0; i <= cb[a[p]]->ds_ve.sl_da_ban - 1 && i<=18+trang1*18; i++)
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
		if (c == Up)
		{
			if (f > 7)
			{
				f-=1;
				x--;

			}
		}
		else if (c == Down)
		{
			if (f < dem + 6 && x <= dem - 2)
			{
				f += 1;
				x++;
			}
		}
		if (c == ESC) goto xuly;
		if (f != 7)
		{
			gotoXY(movX, f - 1 + movY);
			cout << "  ";
		}
		if (f == 25 && tong1 > 1 && trang1 + 1 < tong1)
		{
			trang1++;
			int k = 0, j=0;
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
		gotoXY(movX, f + movY);
		cout << "=>";
	}while (c != Enter);

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
				ds_cb1->cb.ds_ve.sl_con += 1;
				ds_cb1->cb.ds_ve.sl_da_ban -= 1;
			}
		}
		ds_cb1 = ds_cb1->next;
	}
	system("cls");
	Time();
	gotoXY(49+movX, 11+movY); cout << "BAN CHAC CHAN HUY VE?";
	yes_no_fl(ds_cb);
	goto xuly;
}

