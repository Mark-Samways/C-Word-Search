#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "linkedList.h"

using namespace std;

class FileInput
{
	string filename = "Text.txt";
	int countCharacters = -1; // to not include '\0' as a character
	int countWords = 1; // as words are counted by the number of spaces, countWords 
						// is inialised at 1 as the first word would not be counted otherwise
	int countLines = 0;
	char ch;
	WordList wordList;
public:
	void fileInput();
	void populateList(WordList wL);
	void menu();
};

#endif
