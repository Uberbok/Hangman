#include <iostream>
#include <string>
#include <vector>
#include "word.h"
#include "gallows.h"
#include "input.h"

int main()
{		
	bool keepPlaying{ true };
	
	while (keepPlaying) {

		char gallows[6][9];	
		setupGallows(gallows);
		int tries{ 6 };
		char guess{};
		bool hanged{ false };
		std::string word{};
		bool firstGuess{ true };

		std::cout << "User 1, please enter a word: ";
		do {
			std::cin >> word;
		} while (checkInput(word));

		Word secret{ word };
		std::vector<char> prevGuesses{};

		while (!hanged && !secret.gotIt()) {
			system("cls");

			updateGallows(gallows, tries);
			drawGallows(gallows);
			std::cout << "\n\n";
			secret.showWord();
			std::cout << '\n';

			if (firstGuess) {
				std::cout << "Guess a letter: ";
				do {
					std::cin >> guess;
				} while (checkInput(guess));

				prevGuesses.push_back(guess);
				firstGuess = false;
			}
			else
			{
				std::cout << "Previous guesses: ";
				for (int i = 0; i < prevGuesses.size(); i++)
					std::cout << prevGuesses[i] << ", ";
				std::cout << "guess another letter: ";
				do {
					std::cin >> guess;
				} while (checkInput(guess));

				while (alreadyGuessed(prevGuesses, guess)) {
					std::cout << "You already tried that! Try another: ";
					do {
						std::cin >> guess;
					} while (checkInput(guess));
				}
				prevGuesses.push_back(guess);
			}

			secret.checkGuess(guess, tries);
			if (tries <= 0) {
				system("cls");
				updateGallows(gallows, tries);
				drawGallows(gallows);
				hanged = true;
			}
		}

		if (hanged)
			std::cout << "\nOh no! You have been hanged!!!\n";
		else
		{
			system("cls");
			smiley();
			secret.showWord();
			std::cout << '\n';
			std::cout << "Congratulations! Lucky escape...\n";
		}
		keepPlaying = playAgain();
	}
	return 0;
}


