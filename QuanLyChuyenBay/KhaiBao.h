#pragma once
#include "MyLib.h"
#define MBMAX 300 //so luong may bay toi da
//using namespace std;

 /*======================= Quan ly may bay - Mang con tro ======================*/
struct may_bay
{
	char sohieu[16];
	char loaimaybay[41];
	int socho;
};
typedef struct may_bay MAY_BAY;
struct ds_maybay
{
	MAY_BAY* dsmaybay[MBMAX];
	int sl = 0;
};
typedef struct ds_maybay DS_MAYBAY;

/*======================= Quan ly ve may bay - Danh sach tuyen tinh cap phat dong ======================*/
struct ve
{
	int n;//so luong ve =  so cho
	string* cmnd;
	int sl_con = 0;
	int sl_da_ban = 0;
};
typedef struct ve VE;

/*======================= Quan ly hanh khach - Cay nhi phan tim kiem ======================*/
struct HanhKhach {
	string cmnd; //default cmnd = 12
	char ho[50];
	char ten[10];
	char phai[4];
	HanhKhach* left;
	HanhKhach* right;
};
typedef struct HanhKhach* TREE;

struct node_HanhKhach {
	TREE tree = NULL;
	int slHK = 0;
};
typedef struct node_HanhKhach DS_HANHKHACH;


/*======================= Quan ly chuyen bay - Danh sach lien ket don ======================*/
struct chuyenbay
{
	char sohieu[16];
	char sanbay[100];
	int cb;
	char machuyenbay[15];
	int ngay;
	int gio;
	int phut;
	int thang;
	int nam;
	int trangthai;
	VE ds_ve;
};

typedef struct chuyenbay chuyen_bay;
struct ds_chuyen_bay
{
	chuyen_bay cb;
	struct ds_chuyen_bay* next;
	int sl = 0;
};
typedef struct ds_chuyen_bay* DS_CHUYEN_BAY;

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
	char maCB[16] = ""; //CB+NGAY+THANG (khoi hanh)
	THOIGIAN_KH khoiHanh;
	char sanBayDen[15] = "";
	TrangThaiCB trangThai;
	char soHieuMB[16] = "";
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