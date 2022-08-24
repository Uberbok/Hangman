#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>

struct Letter {
	char value{};
	bool isGuessed{ false };
};

class Word {
	std::string word;
	std::vector<Letter> letters{};
	int numLetters{ static_cast<int>(word.length()) };
	int foundLetters{ 0 };
public:
	Word(std::string& w);
	void showWord();
	void checkGuess(const char g, int& tries);
	bool gotIt();
};

#endif // !WORD_H

