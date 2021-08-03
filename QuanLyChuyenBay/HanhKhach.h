#pragma once
#include "KhaiBao.h"
#include "MyLib.h"
#include "DocGhiFile.h"
using namespace std;
///*======================= Quan ly hanh khach - Cay nhi phan tim kiem - BST ======================*/
//struct HanhKhach {
//	string cmnd; //default cmnd = 12
//	char ho[50];
//	char ten[10];
//	char phai[4];
//	HanhKhach* left;
//	HanhKhach* right;
//};
//typedef struct HanhKhach* TREE;
//
//struct node_HanhKhach {
//	TREE tree = NULL;
//	int slHK = 0;
//};
//typedef struct node_HanhKhach DS_HANHKHACH;

/*======================= Quan ly hanh khach - Cay nhi phan tim kiem ======================*/
void docFileHanhKhach(TREE& t);
void ghiFileHanhKhach(TREE& t);
bool ktGioiTinh(char* s);
int ktTrungCMND(TREE t, string CMND);
string themCMND(TREE t);
void nhapTTHK(char* tt);
HanhKhach* khoiTaoNodeHanhKhach(string CMND);
void themHanhKhachMoi(DS_HANHKHACH& ds);
void themHKvaoTree(TREE& t, HanhKhach* ptrHK);
void doiTREEsangARR(TREE t, HanhKhach* hk[], int& ds);
void inTTHanhKhach(TREE& t, string CMND, int h);
void inDSHanhKhach(HanhKhach* hk[], int& ds);
bool timKiemHK(HanhKhach* root, char* CMND);
void giaiPhongHK(TREE& root);
//============================================================================
int ktTrungCMND(TREE t, string CMND)
{
	TREE p = t;
	do
	{
		if (p == NULL)
			return 0;
		else
		{
			if (p->cmnd == CMND)
				return 1;
			else if (p->cmnd < CMND)
				ktTrungCMND(p->right, CMND);
			else
				ktTrungCMND(p->left, CMND);
		}
	} while (1);
}

string themCMND(TREE t)
{
	connhay_off();
	string CMND;
	int n = CMND.length();
	do
	{
		//cmnd = chanSo(Backspace, x1, y2);
		box(x3 + 20, y2 + 12, 20, 1, White);
		gotoXY(x3+22, y2+13); cout << "NHAP SO CAN CUOC CONG DAN: ";
		for (int i = 0; i < 12; i++)
		{
			gotoXY(x3 + 22 +i,y2+14); cout << " ";
		}
		CMND = chanSo(11, x3+22, y2+14);
		if (n != 12)
		{
			BaoLoi("KHONG HOP LE. MOI NHAP LAI!", x2 + 10, y2 + 9);
			_getch();
		}
		for (int i = 0; i < n; i++)
		{
			if (CMND[i] < 48 || CMND[i] > 57) break;
		}
	} while (CMND[0] = '\0' || n != 12 || ktTrungCMND(t, CMND) == 1);
	return CMND;
}
//int nhapSoCMND(char* num, int n) 
//{
//	int i = 0;
//	char  getnum;
//	while (1)
//	{
//		//(getnum=getch())!=13 && getnum!=27
//		getnum = getKey();
//		if (getnum == Space && i > 0) {
//			i--;
//			printf("\b \b");
//		}
//		else if (getnum >= '0' && getnum <= '9' && i < n)
//		{
//			num[i] = getnum;
//			putchar(getnum);
//			i++;
//		}
//		if (getnum == Enter && i == n) break;
//		if (getnum == ESC) return -1;
//	}
//	num[i] = '\0';
//	return 1;
//}

void nhapTTHK(char* tt)
{
	char c;
	int i = 0;
	while (1)
	{
		c = getKey();
		if (c == Backspace && i > 0)
		{
			i--;
			printf("\b \b");
		}
		if (c >= 'A' && c <= 'Z' && i < 14)//i la ma toi da 14 ki tu
		{
			tt[i] = c;
			putchar(c);
			i++;
		}
		else if (c == Enter && i > 0)//chuyen dong
			break;
	}
	tt[i] = 0;

}
//=====================================================
HanhKhach* khoiTaoNodeHanhKhach(string CMND)
{
	HanhKhach* p = new HanhKhach;
	p->cmnd = CMND;
	p->left = NULL;
	p->right = NULL;
	return p;
}
//============= Nhap va tao Node hanh khach moi =============
void themHanhKhachMoi(DS_HANHKHACH &ds)
{
	connhay_off();
	HanhKhach *hk;
	char* tmp;
	int dem = 0;
	string CMND;
	docFileHanhKhach(ds.tree);
	CMND = themCMND(ds.tree);
	for (int i = 0; i < 12; i++)
	{
		if (CMND[i] < '0' || CMND[i] > '9')
			return;
	}
	hk = khoiTaoNodeHanhKhach(CMND);
	box(x3 + 20, y2 + 15, 20, 1, White);
	gotoXY(x3 + 22, y2 + 16); cout << "NHAP HO: ";
	do
	{
		tmp = chanChuoi(50, x3 + 32, y2 + 16);
	} while (tmp[0] = '\0');
	dem = 0;
	while (tmp[dem] != '\0')
	{
		if (tmp[0] < 'A' || tmp[0]>'Z')
			return;
		hk->ho[dem] = tmp[dem];
		dem++;
		hk->ho[dem] = '\0';
	}

	box(x3 + 20, y2 + 17, 20, 1, White);
	gotoXY(x3 + 22, y2 + 18); cout << "NHAP TEN: ";
	do
	{
		tmp = chanChuoi(50, x3 + 32, y2 + 18);
	} while (tmp[0] = '\0');
	dem = 0;
	while (tmp[dem] != '\0')
	{
		if (tmp[0] < 'A' || tmp[0]>'Z')
			return;
		hk->ten[dem] = tmp[dem];
		dem++;
		hk->ten[dem] = '\0';
	}

	box(x3 + 20, y2 + 19, 20, 1, White);
	gotoXY(x3 + 22, y2 + 20); cout << "NHAP PHAI: ";
	if (ktGioiTinh(hk->phai))
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
	gotoXY(x3 + 22, y2 + 35); cout << hk->phai;
	themHKvaoTree(ds.tree, hk);
	ghiFileHanhKhach(ds.tree);
	ds.slHK++;
	system("cls");
}
//void nhapHanhKhach(DS_HANHKHACH list)
//{
//	HanhKhach* p = khoiTaoNodeHanhKhach();
//	fflush(stdin);
//	getline(cin, p->cmnd);
//	gets_s(p->ho);
//	gets_s(p->ten);
//	gets_s(p->phai);
//	list.slHK++;
//}

void themHKvaoTree(TREE& t, HanhKhach* ptrHK)
{
	if (t == NULL)
		t = ptrHK;
	else
	{
		if (t->cmnd > ptrHK->cmnd)
			themHKvaoTree(t->left, ptrHK);
		else if (t->cmnd < ptrHK->cmnd)
			themHKvaoTree(t->right, ptrHK);
		/*else if (t->cmnd == ptrHK->cmnd)
			themHanhKhachMoi(t, ptrHK);*/
	}
}

//============= In danh sach hanh khach =============
//-------------chuyen cay sang mang------------------
/*khoi tao danh sach o ham main
* HanhKhach *ds[100];
* int nds = 0;
*/

void doiTREEsangARR(TREE t, HanhKhach *hk[], int &ds)
{
	if (t != NULL)
	{
		int i = 0;
		hk[ds] = new HanhKhach;
		hk[ds]->cmnd = t->cmnd;
		while (t->ho[i] != '\0')
		{
			hk[ds]->ho[i] = t->ho[i];
			i++;
			hk[ds]->ho[i] = '\0';
		}
		i = 0;
		while (t->ten[i] != '\0')
		{
			hk[ds]->ten[i] = t->ten[i];
			i++;
			hk[ds]->ten[i] = '\0';
		}
		i = 0;
		while (t->phai[i] != '\0')
		{
			hk[ds]->phai[i] = t->phai[i];
			i++;
			hk[ds]->phai[i] = '\0';
		}
		//kiemTraGioiTinh(hk[ds]->phai);
		ds++;
		doiTREEsangARR(t->left, hk, ds);
		doiTREEsangARR(t->right, hk, ds);	
	}
}
// -------------sap xep danh sach hanh khach------------------
//void hoanVi(TREE &a, TREE &b)
//{
//	TREE tam = new HanhKhach;
//	tam->CMND = a->CMND;
//	tam->ho = a->ho;
//	tam->ten - a->ten;
//	tam->phai = a->phai;
//
//	a->CMND = b->CMND;
//	a->ho = b->ho;
//	a->ten - b->ten;
//	a->phai = b->phai;
//
//	b->CMND = tam->CMND;
//	b->ho = tam->ho;
//	b->ten = tam->ten;
//	b->phai = tam->phai;
//
//}
//void tenHanhKhachTanDan(HanhKhach* list[], int nlist)
//{
//	//list = new HanhKhach;
//	char temp[40];
//	for (int i = 0; i < nlist; i++)
//	{
//		for (int j = i + 1; j < nlist; j++)
//		{
//			if (list[i]->ten > list[j]->ten)
//			{
//				hoanVi(list[i], list[j]);
//			}
//			else if (list[i]->ten == list[j]->ten)
//			{
//				if (list[i]->ho > list[j]->ho)
//				{
//					hoanVi(list[i], list[j]);
//				}
//			}
//		}
//	}
//}



//-------------in danh sach hanh khach theo ho - ten------------------
void inTTHanhKhach(TREE& t, string CMND, int h)
{
	TREE p = t;
	do
	{
		if (p == NULL) return;
		else
		{
			if (p->cmnd == CMND)
			{
				gotoXY(x3 + 50, y2 + 7 + n); cout << p->ho << " " << p->ten;
				gotoXY(x3 + 106, y2 + 7 + n); cout << p->phai;
				return;
			}
			else if (p->cmnd > CMND)
				p = p->left;
			else if (p->cmnd < CMND)
				p = p->right;
		}
	} while (1);
}


void inDSHanhKhach(HanhKhach* hk[], int& ds)
{
	int trang = 0;
	int tong = 0;
	for (int i = 0; i < ds; i++)
	{
		cout << hk[i]->cmnd;
		cout << hk[i]->ho;
		cout << hk[i]->ten;
		cout << hk[i]->phai;
	}
}
//------------- Tim kiem hanh khach-------------------
bool timKiemHK(HanhKhach* root, char* CMND)
{
	if (root == NULL) return false;
	if (root->cmnd == CMND)
	{
		cout << root->cmnd;
		cout << root->ho;
		cout << root->ten;
		cout << root->phai;
		return true;
	}
	else if (root->cmnd > CMND) timKiemHK(root->left, CMND);
	else if (root->cmnd < CMND) timKiemHK(root->right, CMND);
}
//------------- giai phong vung nho ------------------
void giaiPhongHK(TREE& root)
{
	if (root == NULL)
		return;
	giaiPhongHK(root->left);
	giaiPhongHK(root->right);
	delete root;
}