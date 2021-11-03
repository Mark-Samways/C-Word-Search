#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

class WordNode
{
	string* word;
	WordNode* next;
public:
	WordNode();
	WordNode(string inputWord);
	void setNewWord(string* newWord);
	void setNext(WordNode* nextNode);
	WordNode* getNext();
	string* getWord();
};

class WordList
{
	WordNode *start, *end;
public:
	WordList();
	bool isEmpty();
	void addFirstWord(string inputWord);
	void addWordAtEnd(string inputWord);
	//void listAllWords();
	void sorting();
	void listAllWords();
	void wordSearch();
	
};

#endif
