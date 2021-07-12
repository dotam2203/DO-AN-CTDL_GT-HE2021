#pragma once
#include "MyLib.h"
#define MBMAX 300 //so luong may bay toi da
//using namespace std;

 /*======================= Quan ly may bay - Mang con tro ======================*/
struct MayBay {
	char soHieuMB[16];//ten viet tat loai may bay+stt (001 -> 300)
	char loaiMB[41];
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


/*======================= Quan ly ve may bay - Danh sach tuyen tinh cap phat dong ======================*/
struct Ve {
	int maVe; //tang dan theo so cho cua may bay
	char CMND[20];//CMND:10 so - CCCD:12 so
};
typedef struct Ve VeMB;

enum TrangThaiVe
{
	daDat,
	daHuy
};
struct ds_Ve {
	VeMB* vitriNgoi; //so luong ve phu thuoc so luong cho cua may bay, 1 mang dong co con tro chua thong tin ve
	//int dat; //so cho da dat -dua vao mang

	TrangThaiVe trangThaiVe;//dat ve - huy ve
	bool huyVe = true;//cho phep hanh khach huy ve
	int veMax; //gioi han ve ma 1 nguoi duoc dat
};
typedef struct ds_Ve DS_VeMB;


/*======================= Quan ly hanh khach - Cay nhi phan tim kiem ======================*/
struct HanhKhach {
	char CMND[20]; //check co so 0 ơ first
	char ho[50];
	char ten[10];
	char phai[4];
};
typedef struct HanhKhach HANHKHACH;

struct node_HanhKhach {
	HANHKHACH dsKH;
	node_HanhKhach* letf = NULL;
	node_HanhKhach* right = NULL;
	int slHK = 0;
};
typedef struct node_HanhKhach* PTR_HANHKHACH;


/*======================= Quan ly chuyen bay - Danh sach lien ket don ======================*/
struct ThoiGianKH {
	int gio; // 09:00 20/07/2021
	int phut;
	int ngay;
	int thang;
	int nam;
};
typedef struct ThoiGianKH THOIGIAN_KH;

enum TrangThaiCB
{
	huyChuyen,
	conVe,
	hetVe,
	hoanTat
};
struct ChuyenBay {
	char maCB[16]; //CB+NGAY+THANG (khoi hanh)
	THOIGIAN_KH khoiHanh;
	char sanBayDen[15];
	TrangThaiCB trangThai;
	char soHieuMB[16];
	string* danhSachVe;//khoi tao mang dong chua Ve, khi can biet ve da mua hay chua thi nhay coc toi - tiet kiem bo nho
	int slVe; //SoLuongVe = SoCho
};
typedef struct ChuyenBay CHUYENBAY;

struct node_ChuyenBay {
	CHUYENBAY info;
	node_ChuyenBay* next;
	int slCB = 0;
};
typedef struct node_ChuyenBay* PTR_CHUYENBAY;