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

HANHKHACH themHanhKhach(char *cmnd, char *ho, char *ten, char *phai)
{
	HANHKHACH hk;
	strcpy(hk.CMND,cmnd);
	strcpy(hk.ho, ho);
	strcpy(hk.ten, ten);
	strcpy(hk.phai, phai);

	return hk;
}

struct node_HanhKhach {
	HANHKHACH info;
	struct node_HanhKhach* letf = NULL;
	struct node_HanhKhach* right = NULL;
	int slHK = 0;
};
typedef struct node_HanhKhach *PTR_HANHKHACH;
PTR_HANHKHACH tree = NULL;

void themNodeHanhKhach(PTR_HANHKHACH &ptrHK, HANHKHACH hk)
{
}