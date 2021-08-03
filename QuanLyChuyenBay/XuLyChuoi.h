//#pragma once
//#include"MyLib.h"
//
////=======  Xoa khoang trang ======= 
//void Xoa(char* s, int vt)
//{
//	int n = strlen(s);
//	for (int i = vt + 1; i < n; i++)
//		s[i - 1] = s[i];
//	s[n - 1] = '\0';
//
//}
//
//void xoaKhoangTrang(char* s)
//{
//	for (int i = 0; i < strlen(s); i++)
//	{
//		if (s[i] == ' ')
//		{
//			Xoa(s, i);
//			i--;
//		}
//	}
//	for (int i = 0; s[i] != '\0'; i++)
//		if (s[i] >= 'a' && s[i] <= 'z')
//			s[i] = s[i] - 32;
//}
//void xoaKhoangTrangDu(char* s)
//{
//	for (int i = 0; i < strlen(s); i++)
//		if (s[i] == ' ' && s[i + 1] == ' ')
//		{
//			Xoa(s, i);
//			i--;
//		}
//	if (s[0] == ' ')
//		Xoa(s, 0);
//	if (s[strlen(s) - 1] == ' ')
//		Xoa(s, strlen(s) - 1);
//	for (int i = 0; s[i] != '\0'; i++)
//		if (s[i] >= 'a' && s[i] <= 'z')
//			s[i] = s[i] - 32;
//}
////=======  chuyen thanh chua in=======
//void chuInHoa(char* s)
//{
//	for (int i = 0; s[i] != '\0'; i++)
//		if (s[i] >= 'a' && s[i] <= 'z')
//			s[i] = s[i] - 32;
//}
