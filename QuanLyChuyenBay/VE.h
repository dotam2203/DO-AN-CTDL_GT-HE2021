#pragma once
#include "KhaiBao.h"

/*======================= Quan ly ve may bay - Danh sach tuyen tinh cap phat dong ======================*/
struct Ve {
	int maVe; //tang dan theo so cho cua may bay
	char CMND[13] ="";//CMND:10 so - CCCD:12 so
};
typedef struct Ve VeMB;

enum TrangThaiVe
{
	daDat,
	daHuy
};
struct ds_Ve {
	VeMB* sttVe; //so luong ve phu thuoc so luong cho cua may bay, 1 mang dong co con tro chua thong tin ve
	int soVeDaBan = 0; //so cho da dat -dua vao mang
	TrangThaiVe trangThaiVe;//dat ve - huy ve
	bool huyVe = true;//cho phep hanh khach huy ve
	int veMax; //gioi han ve ma 1 nguoi duoc dat
};
typedef struct ds_Ve DS_VeMB;

void slVeDaBan(DS_VeMB& list)
{
	
}

void datVe(DS_VeMB &list, MAYBAY mb)
{
	list.sttVe = new VeMB[mb.soCho];
	for (int i = 1; i <= mb.soCho; i++)
	{
		cin >> list.sttVe[i].maVe;
		fflush(stdin);
		gets_s(list.sttVe[i].CMND);
	}
	slVeDaBan(list);
}

void slVeDaBan()
{

}
void dsVeDaBan()
{

}