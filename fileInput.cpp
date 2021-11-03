#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "fileInput.h"
#include "linkedList.h"

using namespace std;

void FileInput::fileInput()
{
	ifstream file;
	file.open(filename);

	if (!file.is_open()) // testing whether the file has opened succesfully
	{
		exit(EXIT_FAILURE); // if it hasn't the program exits
	}

	while (!file.eof())
	{
		file.get(ch);

		if (ch == '\0') // shows the file is empty
		{
			countWords = 0; // sets countWords to 0 instead of 1 it was inialised at
		}

		if (ch == '\n') // shows a new line has been entered
		{
			countLines++;
		}
		else if (ch == ' ') // shows a space has been entered, which indicates a word
		{
			countWords++;
			countCharacters++;
		}
		else
		{
			countCharacters++;
		}
	}
};

void FileInput::populateList(WordList wL) // storing each individual word in the word list / linked list
{
	ifstream file;
	file.open(filename);

	wordList = wL;

	if (!file.is_open()) // testing whether the file has opened succesfully
	{
		exit(EXIT_FAILURE); // if it hasn't the program exits
	}

	string word;

	while (file >> word) // a loop which runs through each word in the file and stores it into the string "word"
	{
		wordList.addWordAtEnd(word); // adds the word to the linked list
	}
	
	//wordList.listAllWords();
	wordList.sorting();
	//wordList.listAllWords();
}

void FileInput::menu()
{
	cout << "Input file nane: " << filename << endl;
	cout << "Text loaded..." << endl;
	cout << "Characters: " << countCharacters << endl;
	cout << "Words: " << countWords << endl;
	cout << "For wildcard matching use '*' for char groups." << endl;
	cout << "Enter target search word: ";
	wordList.wordSearch(); // runs the method to search for the word
}