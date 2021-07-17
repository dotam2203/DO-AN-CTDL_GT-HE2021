#pragma once
#include"KhaiBao.h"

//======================Hanh Khach================
void docHanhKhachTuFile()
{

}

void ghiHanhKhachVaoFile()
{

}
//======================Danh Sach Ve================
void docVeTuFile(DS_VeMB &list, MAYBAY mb)
{
	fstream veIn;
	veIn.open("dsv.txt", ios_base::in);
	while (veIn.eof() != true)//doc den cuoi file 
	{
		list.sttVe = new VeMB[mb.soCho];
		getline(veIn,list.sttVe->CMND,',');
		veIn >> list.sttVe->maVe;
	}

}