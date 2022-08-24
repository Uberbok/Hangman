#include <iostream>
#include "gallows.h"

void setupGallows(char(&arr)[6][9]) {
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 9; ++j)
			arr[i][j] = ' ';
	}

	arr[0][4] = '_';
	arr[0][5] = '_';
	arr[0][6] = '_';
	arr[0][7] = '_';
	arr[0][8] = '_';

	arr[1][4] = ':';
	arr[1][7] = '\\';
	arr[1][8] = '|';
	arr[2][8] = '|';
	arr[3][8] = '|';
	arr[4][8] = '|';
	arr[5][8] = '|';
}

void drawGallows(const char(&arr)[6][9]) {
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 9; ++j) {
			std::cout << arr[i][j];
		}
		std::cout << '\n';
	}
}

void updateGallows(char(&arr)[6][9], const int& tries) {
	switch (tries) {
	case 5:		arr[2][4] = 'O'; break;
	case 4:		arr[3][4] = '|'; break;
	case 3:		arr[3][3] = '/'; break;
	case 2:		arr[3][5] = '\\'; break;
	case 1:		arr[4][3] = '/'; break;
	case 0:		arr[4][5] = '\\'; break;
	}
}

void smiley() {
	std::cout << "\n\n\to -\n" <<
		"\t ^\n" <<
		"\t\\_/\n\n";
}