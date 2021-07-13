#pragma once
#include "KhaiBao.h"

/*======================= Quan ly hanh khach - Cay nhi phan tim kiem ======================*/
struct HanhKhach {
	char CMND[20]; //check co so 0 o first
	char ho[50];
	char ten[10];
	char phai[4];
};
typedef struct HanhKhach HANHKHACH;

struct node_HanhKhach {
	HANHKHACH info;
	node_HanhKhach* letf = NULL;
	node_HanhKhach* right = NULL;
	int slHK = 0;
};
typedef struct node_HanhKhach *PTR_HANHKHACH;
PTR_HANHKHACH tree = NULL;
void khoitaoTree(PTR_HANHKHACH& root)
{
	root = NULL;
}

void kiemtraCMND(char cmnd[20])
{

}

node_HanhKhach* khoitaoNodeHanhKhach()
{
	node_HanhKhach* p = new node_HanhKhach;
	p->letf = NULL;
	p->right = NULL;
	return p;
}
void nhapHanhKhach(node_HanhKhach ptrHK)
{
	node_HanhKhach* p = khoitaoNodeHanhKhach();
	fflush(stdin);
	gets_s(p->info.CMND);
	gets_s(p->info.ho);
	gets_s(p->info.ten);
	gets_s(p->info.phai);
	
}

node_HanhKhach *taoNodeHanhKhach( HANHKHACH hk)
{
	node_HanhKhach *p = new node_HanhKhach;
	p->info = hk;
	p->letf = NULL;
	p->right = NULL;
	p->slHK = 0;
	return p;
}