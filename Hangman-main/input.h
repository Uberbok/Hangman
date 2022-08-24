#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

bool alreadyGuessed(const std::vector<char>& arr, const char c);
void cleanCin();
bool checkInput(char& c);
bool checkInput(std::string& str);
bool playAgain();
#endif // !INPUT_H
