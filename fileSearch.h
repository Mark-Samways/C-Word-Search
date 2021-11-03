#ifndef FILESEARCH_H
#define FILESEARCH_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <regex>
#include "linkedList.h"

using namespace std;

class FileSearch
{
	regex reg;
	string str;
	smatch match;
	WordList tempWordList;
	int matchCount;
public:
	void wildcardSearch(string target);
	void setStr(string word);
	void regexMatch();
	int getMatchCount();
	void getTempWordList();
};

#endif
