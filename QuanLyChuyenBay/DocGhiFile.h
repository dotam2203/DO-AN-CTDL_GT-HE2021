#pragma once
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include"KhaiBao.h"
#include "HanhKhach.h"
#include "Ve.h"
using namespace std;
//======================Hanh Khach================
HanhKhach* khoiTaoNodeHanhKhach(string CMND);
void themHKvaoTree(TREE& t, HanhKhach* ptrHK);
//void inTTHanhKhach(TREE& t, string CMND, int h);

void docFileHanhKhach(TREE &t)
{
	HanhKhach* hk;
	DS_HANHKHACH ds;
	string CMND;
	ifstream fin;
	fin.open("dsHANHKHACH.txt", ios_base::in);
	/*if (fin.is_open()) cout << "mo file thanh cong!"<<endl;
	else
	{
		cout << "ko mo duoc file!";
		exit(-1);
	}*/
	t = NULL;
	while (!fin.eof())
	{
		hk = khoiTaoNodeHanhKhach(CMND);
		getline(fin, CMND);
		if (CMND == " ") break;
		fin.get(hk->ho,50 );
		fin.get(hk->ten, 10);	
		fin.get(hk->phai, 4);
		themHKvaoTree(t, hk);
		ds.slHK++;
		fin.ignore();
	}
	fin.close();
}

void themHKvaoFile(TREE &t, ofstream &fout)
{
	if (t != NULL)
	{
		fout << t->cmnd <<endl;
		fout << t->ho <<endl;
		fout << t->ten << endl;
		fout << t->phai << endl;
		themHKvaoFile(t->left, fout);
		themHKvaoFile(t->right, fout);
	}
}

void ghiFileHanhKhach(TREE &t)
{
	ofstream fout;
	fout.open("dsHANHKHACH.txt", ios_base::out);
	themHKvaoFile(t, fout);
	fout.close();
}

//======================Danh Sach Ve================

//void docFileVe(DS_VeMB& ds, chuyen_bay cb)
//{
//	ifstream fin;
//	fin.open("dsVE.txt", ios_base::in);
//	while (!fin.eof())
//	{
//		VeMB* ve = new VeMB[cb.];
//		fin >> ds.sttVe->maVe;
//		fflush(stdin);
//		getline(fin, ds.sttVe->cmnd);
//		if (ds.sttVe->cmnd == " ") break;
//		/*cout << ds.sttVe->maVe;
//		cout << ds.sttVe->cmnd;*/
//	}	
//	fin.close();
//}
//
//
//void ghiFileVe(DS_VeMB& ds, MAYBAY mb)
//{
//	FILE* fout;
//	fclose(fout);
//}

