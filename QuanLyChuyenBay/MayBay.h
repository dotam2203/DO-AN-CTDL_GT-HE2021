#pragma once
#include"KhaiBao.h"

/*======================= Quan ly may bay - Mang con tro ======================*/


DS_MAYBAY planeAddArray;

// Tao may bay moi
MAYBAY PlaneCreate(char* id, char* kind, int seat) {
	MAYBAY tmp;
	strcpy(tmp.soHieuMB, id);
	strcpy(tmp.loaiMB, kind);
	tmp.seat = seat;
	return tmp;
}
// Them may bay vao  danh sach may bay
void PlaneAdd(MAYBAY plane) {
	planeAddArray.dsMB[planeAddArray.slMB] = new MAYBAY;
	*planeAddArray.dsMB[planeAddArray.slMB] = plane;
	planeAddArray.slMB++;
}
// Xoa may bay tai vi tri trong ds may bay
void PlaneRemoveByIndex(int index) {
	delete planeAddArray.dsMB[index];
	for (int i = index; i < planeAddArray.slMB - 1; i++) {
		planeAddArray.dsMB[i] = planeAddArray.dsMB[i + 1];
	}
	planeAddArray.slMB--;
}
// Sua may bay tai vi tri trong ds may bay
void PlaneEditByIndex(int index, char* kind) {
	strcpy(planeAddArray.dsMB[index]->loaiMB, kind);
}
// Xoa danh sach may bay
void ClearAllPlaneList() {
	for (int i = 0; i < planeAddArray.slMB; i++) {
		delete planeAddArray.list[i];
		planeAddArray.slMB--;
	}
}
// tim may bay theo ID 
Planes* FindPlaneByID(char* id) {
	for (int i = 0; i < planeAddArray.slMB; i++) {
		if (strcmp(planeAddArray.dsMB[i]->planeID, id) == 0) {
			return planeAddArray.dsMB[i];
		}
	}
	return NULL;
}