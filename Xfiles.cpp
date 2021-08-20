#include "Xfiles.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Xfiles::loadPages()
{
	Pages.push_back("xfiles//xfile_1.txt");
	Pages.push_back("xfiles//xfile_2.txt");
	Pages.push_back("xfiles//xfile_3.txt");
	Pages.push_back("xfiles//xfile_4.txt");
	Pages.push_back("xfiles//xfile_5.txt");
}

// function to load files based on user input
void Xfiles::loadFile(string page)
{
	string line;	// declaring a variable
	// ifstream infile("xfiles//xfile_1.txt", ios::in);	// creating/opening an input filestream
	ifstream infile(page, ios::in);	// creating/opening an input filestream

	if (infile.is_open()) // make sure input filestream is open
	{
		while (getline(infile, line))  // while the open file has content, get it...
		{
			cout << line << "\n";				// parse it
		}
		infile.close();		// close input filestream
			// outfile.close();	// close output filestream
	}
	else
	{
		cout << "Unable to open file or file is corrupt.\n\n";  // msg if outfile cannot be opened

	}	// end of infile if statement

	system("pause>nul|set/p=  CONTINUE...");					// WinOS specific command to pause for	 user input
	system("CLS");	
}




