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
	HanhKhach* p;
	DS_HANHKHACH hk;
	ifstream fin;
	char a[11];
	fin.open("ds_hanhkhach.txt");
	string cmnd;
	//Free(t);
	t = NULL;
	while (fin.eof() != true)
	{
		getline(fin, cmnd);
		if (cmnd == "")break;
		p = khoiTaoNodeHanhKhach(cmnd);
		fin.getline(p->ho, 50);
		fin.getline(p->ten, 10);
		fin >> p->phai;
		themHKvaoTree(t, p);
		hk.slHK++;
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


