#pragma once
#include "KhaiBao.h"

/*======================= Quan ly hanh khach - Cay nhi phan tim kiem ======================*/
struct HanhKhach {
	char CMND[13] = ""; //check co so 0 o first
	char ho[50] = "";
	char ten[10] = "";
	char phai[4] = "";
};
typedef struct HanhKhach HANHKHACH;

struct node_HanhKhach {
	HANHKHACH info;
	node_HanhKhach* letf = NULL;
	node_HanhKhach* right = NULL;
	int slHK = 0;
};
typedef struct node_HanhKhach *PTR_HANHKHACH;
//PTR_HANHKHACH tree = NULL;

void khoitaoTree(PTR_HANHKHACH& root)
{
	root = NULL;
}

node_HanhKhach* khoitaoNodeHanhKhach()
{
	node_HanhKhach* p = new node_HanhKhach;//cap phat vung nho cho 1 hanh khach
	p->letf = NULL;
	p->right = NULL;
	return p;
}

void taoHanhKhachMoi(PTR_HANHKHACH &list) 
{
	node_HanhKhach *ptr = khoitaoNodeHanhKhach();//con tro lay thong tin hanh khach tro toi vung nho da cap phat;
	fflush(stdin);
	gets_s(ptr->info.CMND);
	gets_s(ptr->info.ho);
	gets_s(ptr->info.ten);
	gets_s(ptr->info.phai);
	/*xoaKhoangTrang(p->info.CMND);
	xoaKhoangTrangDu(p->info.ho);
	xoaKhoangTrang(p->info.ten);
	xoaKhoangTrang(p->info.phai);*/
	themHanhKhachMoi(list, ptr);
	list->slHK++;
}

void themHanhKhachMoi(PTR_HANHKHACH &list, node_HanhKhach *ptr)//moi lan them 1 hanh khach vao tree thi bo nho da tu dong cap phat (taoHanhKhachMoi)
{
	if (list == NULL)
		list = ptr;
	else
	{
		if (strcmp(list->info.CMND, ptr->info.CMND) > 0)//strmp(c1,c2): ham so sanh chuoi 1 vs 2
			themHanhKhachMoi(list->letf, ptr);
		else if (strcmp(list->info.CMND, ptr->info.CMND) < 0)
			themHanhKhachMoi(list->right, ptr);
		else if (strcmp(list->info.CMND, ptr->info.CMND) == 0)
			themHanhKhachMoi(list, ptr);
	}
}



