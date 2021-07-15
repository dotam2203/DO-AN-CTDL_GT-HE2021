#pragma once
#include"KhaiBao.h"

/*======================= Quan ly may bay - Mang con tro ======================*/
struct MayBay {
	char soHieuMB[16] = "";//ten viet tat loai may bay+stt (001 -> 300)
	char loaiMB[41] = "";
	int soCho;

	//them chi so
	int soLuotBay = 0; //dem so luot da thuc hien chuyen bay cua may bay
	bool active = true; //cho phep mo chuyen bay
};
typedef struct MayBay MAYBAY;

struct ds_Maybay {
	MAYBAY* dsMB[MBMAX];
	int slMB = 0; //dem so luong may bay
};
typedef struct ds_Maybay DS_MAYBAY;

