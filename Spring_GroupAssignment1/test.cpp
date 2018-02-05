#include <iostream>
#include <fstream>

using namespace std;

void writeARecord(string);

int main()
{

	try
	{
		fstream inFile;
		inFile.open("test.txt", ios::in | ios::out);

		char* myString = new char[10];
		inFile.seekg(1);

		cout << "Here's a thing??\t" << inFile.tellg() << endl;

		inFile.get(myString, 10, '\n');

		cout << myString << endl;

		char* stringToAdd = new char[8];
		for (int i = 0; i < 8; i++)
		{
			stringToAdd[i] = '&';
		}

		cout << "Adding: " << stringToAdd << " to the file..." << endl;

		inFile.seekp(42);

		cout << "Place reached..." << endl;

		inFile.write(stringToAdd, 8);

		cout << "All done!" << endl;

		inFile.close();

		cout << "BEGINNING SECOND ROUND OF TESTING!" << endl;

		fstream countingSheep;
		countingSheep.open("test2.txt", ios::in | ios::out);

		int size = 0;
		countingSheep.seekg(ios::end);
		size = countingSheep.tellg();

		cout << "There are " << size << " characters in this file!" << endl;

		cout << "A character has " << sizeof(char) << " bytes" << endl;
		countingSheep.close();

		fstream formatTest;
		formatTest.open("byteTest.txt", ios::in | ios::out);

		cout << "\n\n====Byte Test Stuff====" << endl;
		cout << "get pointer is at " << formatTest.tellg() << endl;

		formatTest.seekg(0, ios::end);

		int gPos = formatTest.tellg();

		cout << "get pointer is now at " << gPos << endl;

		cout << "There are " << ((gPos - 1) / 37) << " records in the file" << endl;

		formatTest.seekg(0, ios::beg);
		char* record1 = new char[37];
		char* record2 = new char[37];
		formatTest.get(record1, 38);
		formatTest.seekg(37);
		formatTest.get(record2, 38);

		cout << "First record retrieved: " << record1 << endl;
		cout << "Second record retrieved: " << record2 << endl;

		formatTest.close();
		
		cout << "Attempting to write a new record..." << endl;
		
		writeARecord("byteTest.txt");
	}
	catch (exception e)
	{
		cerr << "Error opening or reading file..." << endl;
		e.what();

		exit(1);
	}
	return 0;
}

void writeARecord(string path)
{
	fstream myStream;
	myStream.open(path, ios::in | ios::out);


	char* record1 = new char[37];
	char* record2 = new char[37];
	myStream.get(record1, 38);
	myStream.seekg(37);
	myStream.get(record2, 38);

	cout << "First record retrieved: " << record1 << endl;
	cout << "Second record retrieved: " << record2 << endl;

	
	myStream.seekp(37);
	myStream.write("5432167891776  99Houston***Cane******", 37);
	myStream.seekp(75);
	myStream.write(record2, 37);
	
	char* record3 = new char[37];
	myStream.seekg(37);
	myStream.get(record3, 38);
	cout << "Record added: " << record3 << endl;

	myStream.close();
}