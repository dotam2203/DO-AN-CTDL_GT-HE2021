#pragma once
#include <ctime>
#include "KhaiBao.h"

int yearDay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
 
// kiểm tra xem ngày tháng năm có đúng, năm nhuận 
bool Check_Valid_Date(int dd, int mm, int yy) {
	
	int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((yy % 4 == 00 && yy % 100 != 0) || (yy % 400 == 0)) {
		months[1] = 29;
	}
	if (mm >= 1 && mm <= 12) {
		if (dd >= 1 && dd <= months[mm - 1]) return true;
	}
	return false;
}

bool Check_Valid_Time(int hour, int min) {
	if (hour >= 24) {
		return false;
	}
	if (min >= 60) {
		return false;
	}
	return true;
}

ThoiGianKH CreateADateSet(int day, int month, int year, int hour, int min) {

	ThoiGianKH tmp;
	tmp.ngay = day;
	tmp.thang = month;
	tmp.nam = year;
	tmp.gio = hour;
	tmp.phut = min

	return tmp;
}
