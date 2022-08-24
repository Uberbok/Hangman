#include <iostream>
#include "word.h"

Word::Word(std::string& w)
	: word{ w }
{
	for (int i = 0; i < w.size(); i++)
	{
		letters.push_back(Letter{ w[i], false });
	}
}

void Word::showWord() {
	std::cout << "   ";
	for (int i = 0; i < letters.size(); i++) {
		if (letters[i].isGuessed) {
			if (i == 0) std::cout << char(letters[i].value - 32);
			else
				std::cout << letters[i].value;
		}
		else
			std::cout << '-';
	}
	std::cout << '\n';
}

void Word::checkGuess(const char g, int& tries) {
	bool missed{ true };

	for (int i = 0; i < letters.size(); ++i) {
		if (letters[i].value == g) {
			letters[i].isGuessed = true;
			++foundLetters;
			missed = false;
		}
	}
	if (missed) tries--;
}

bool Word::gotIt() {
	return (numLetters == foundLetters);
}