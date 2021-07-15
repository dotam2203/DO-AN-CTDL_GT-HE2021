#pragma once

void NumToCharArr(char* s, int num) {
	if (num == 0) {
		s[0] = '0';
		s[1] = 0;
		return;
	}
	char tmp[50] = "";
	while (num > 0) {
		int tmpN = num % 10;
		char tmpC = (char)(tmpN + 48);
		char tmpS[5];
		tmpS[0] = tmpC;
		tmpS[1] = 0;
		strcat(tmp, tmpS);
		num /= 10;
	}
	//	std::cout << "tmp: "<<tmp;
	for (int i = strlen(tmp) - 1; i >= 0; i--) {
		char tmpS[5];
		tmpS[0] = tmp[i];
		tmpS[1] = 0;
		//		std::cout << "i: "<<i;
		//		system("pause");
		strcat(s, tmpS);
	}
	//	system("pause");
}