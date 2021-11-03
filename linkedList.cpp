#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "linkedList.h"
#include "fileSearch.h"

using namespace std;

WordNode::WordNode()
{
	word = NULL;
	next = NULL;
}

WordNode::WordNode(string inputWord)
{
	word = new string(inputWord);
	next = NULL;
}

void WordNode::setNewWord(string* newWord)
{
	word = newWord;
}

void WordNode::setNext(WordNode* nextNode)
{
	next = nextNode;
}

WordNode* WordNode::getNext()
{
	return next;
}

string* WordNode::getWord()
{
	return word;
}


WordList::WordList()
{
	start = NULL;
	end = NULL;
}

bool WordList::isEmpty()
{
	return start == NULL;
}

void WordList::addFirstWord(string inputWord)
{
	//cout << "Adding word " << inputWord << " at start" << endl << endl;
	WordNode* current;
	current = new WordNode(inputWord);
	start = current;
	end = current;
}

void WordList::addWordAtEnd(string inputWord)
{
	//cout << "Adding word " << inputWord << " at end" << endl << endl;
	WordNode* current;

	if (end == NULL)
	{
		addFirstWord(inputWord);
	}
	else
	{
		current = new WordNode(inputWord);
		end->setNext(current);
		end = current;
	}
}

void WordList::listAllWords()
{
	WordNode* current;

	if (!isEmpty())
	{
		//cout << "Start of list" << endl;
		current = start;
		while (current != NULL)
		{
			cout << *(current->getWord()) << endl;
			current = current->getNext();
		}
		//cout << "End of list" << endl << endl;
	}
	else
	{
		//cout << "List empty" << endl << endl;
	}
}

void WordList::wordSearch()
{
	WordNode* current;
	string str;
	FileSearch f;

	string input;

	cin >> input;
	f.wildcardSearch(input);

	if (!isEmpty())
	{
		current = start;
		while (current != NULL) // cycles through each word in the linked list whilst running them against the input word
		{
			str = *(current->getWord());
			f.setStr(str);
			f.regexMatch();
			current = current->getNext();
		}
	}
	cout << "-----------------------------" << endl;
	cout << "Results" << endl;
	cout << "Number of matches found : " << f.getMatchCount() << endl;
	cout << "Words which were found: " << endl;
	f.getTempWordList(); // displays the words which were matched
}

void WordList::sorting()
{
	WordNode *current, *next;
	string* temp;
	string word, word1;

	if (!isEmpty())
	{
		current = start;
		while (current != NULL) // cycles through each word in the linked list whilst running them against the input word
		{
			next = current->getNext();
			while (next != NULL)
			{
				word = *(current->getWord());
				word1 = *(next->getWord());
				if (word.compare(word1) > 0) // if returns postive, swaps the words around
				{									
					temp = current->getWord();
					current->setNewWord(next->getWord());
					next->setNewWord(temp);
				}
				next = next->getNext();
			}
			current = current->getNext();
		}
	}


}
