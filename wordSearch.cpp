#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "fileInput.h"
#include "linkedList.h"

using namespace std;

int main(void)
{
	FileInput file = FileInput();
	WordList w;

	file.fileInput();
	file.populateList(w);

	file.menu();

	system("pause");
	return 0;
}