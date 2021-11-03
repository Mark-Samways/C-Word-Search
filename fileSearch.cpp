#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <regex>
#include "fileSearch.h"
#include "linkedList.h"

using namespace std;

void FileSearch::wildcardSearch(string target)
{
	string tempStr;
	string addWildcard = "[^ ]?";
	
	for (int i = 0; i < target.size(); i++) // for loop which cycles through each character of the input word
	{
		if (target.substr(i, 1) == "*")
		{
			if (i == target.length() - 1)
			{
				for (int i = 0; i < 29; i++) // for loop to add wildcard 29 times, so longest word in English could still be found
				tempStr += addWildcard; // when the end character is a '*' adds the wildcard 29 times to the tempStr
			}
			else
			{
				tempStr += addWildcard; // when the character is a '*' adds the wildcard to the tempStr
			}
		}
		else
		{
			tempStr += target.substr(i,1); // when the character isn't '*' adds the character to the tempStr
		}
	}
	reg = tempStr; // stores the tempStr in reg
}

void FileSearch::setStr(string word)
{
	str = word;
}

void FileSearch::regexMatch()
{
	int previousCount;
	previousCount = matchCount;
	regex_match(str, match, reg);
	matchCount += match.size();
	if (previousCount != matchCount) // if the matchCount has increased, the word is added to a temporary wordlist
	{
		tempWordList.addWordAtEnd(str);
	}
}

int FileSearch::getMatchCount()
{
	return matchCount;
}

void FileSearch::getTempWordList() // lists all words stored in the temporary wordlist
{
	tempWordList.listAllWords();
}
