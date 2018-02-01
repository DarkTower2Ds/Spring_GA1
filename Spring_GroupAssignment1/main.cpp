#include <string>
#include <fstream>
#include <iostream>
//#include "Personnel.h"
using namespace std;

void setup();
void userInterface();
int main()
{
	//setup(); //opens the file they specify and creates one if it doesnt exist
	//userInterface(); //main user interface
	return 0;
}

void setup()
{
	string fileName;
	ifstream inStream;
	ofstream outStream;
	cout << "Enter the name of the file desired to be opened:" << endl;
	cin >> fileName;
	inStream.open(fileName);
	if (inStream.is_open())
	{
		cout << "File opened successfully!" << endl;
	}
	else
	{
		cout << "Failed to open " << fileName << endl << "Creating file named " << fileName << endl;
		outStream.open(fileName);
	}
	inStream.close();
	outStream.close();
}
void userInterface()
{
	int userInput;
	bool finished = false;
	while (finished != true)
	{
		cout << "1. Insert a new record into the file" << endl;
		cout << "2. Find a record" << endl;
		cout << "3. Modify an existing record" << endl;
		cout << "4. Exit" << endl;
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			// use Database::add(); 
			break;
		case 2:
			// use find(); 
			break;
		case 3:
			// use modify();
			break;
		case 4:
			cout << "Good Bye" << endl;
			finished = true;
			break;
		default:
			cout << "Bad Input " << endl;
		}
	}
}
