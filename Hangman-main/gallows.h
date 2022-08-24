#ifndef GALLOWS_H
#define GALLOWS_H

void setupGallows(char(&arr)[6][9]);
void drawGallows(const char(&arr)[6][9]);
void updateGallows(char(&arr)[6][9], const int& tries);
void smiley();

#endif // !GALLOWS_H
