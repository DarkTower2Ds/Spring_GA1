#pragma once
#include <iostream>
using namespace std;

class Personnel
{
protected:
	int SSN, YOB, nameLen, cityLen;
	long salary;
	char * name;
	char * city;
	friend fstream& operator <<(fstream&, const Personnel&);
	friend fstream& operator >>(fstream&, Personnel&);

public:
	Personnel();
	Personnel(int);
	Personnel(int, int, char *, char *, long);
	int getSSN();
	void writeToFile(fstream&);
	void readFromFile(fstream&);
	friend bool operator ==(int, const Personnel&);
	ostream& writeToConsole(ostream& outputStream);
	istream& readFromConsole(istream& inputStream);
};

