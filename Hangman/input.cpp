#include "input.h"
#include <iostream>
#include <algorithm>

bool playAgain() {
	std::cout << "\nWould you like to play again(y/n)?\n";
	char ch{ 'a' };
	while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') {
		std::cin >> ch;
		cleanCin();
		if (ch == 'y' || ch == 'Y') {
			system("cls");
			return true;
		}
		else if (ch == 'n' || ch == 'N') return false;
		else std::cout << "Y or N...\n";
	}
}
bool alreadyGuessed(const std::vector<char>& arr, const char c) {
	for (int i = 0; i < arr.size(); i++) {
		if (c == arr[i]) {
			return true;
		}
	}
	return false;
}

void cleanCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool checkInput(char& c) {
	if ((c < 65 || c > 122) || (c < 97 && c > 90)) {
		cleanCin();
		std::cout << "Invalid input! Please re-enter: ";
		return true;
	}
	if (c >= 65 && c <= 90) {
		c += 32;
	}
	cleanCin();
	return false;
}

bool checkInput(std::string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (!std::isalpha(str[i])) {
			std::cout << "Invalid input! Please re-enter: ";
			return true;
		}
		else {
			std::for_each(str.begin(), str.end(), [](char& c) { c = static_cast<char>(::tolower(c)); });
		}
	}
	return false;
}
