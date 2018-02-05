#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <iostream>
using namespace std;

class Personnel
{
protected:
	int SSN, YOB, nameLen, cityLen;
	long salary;
	char * name;
	char * city;
public:
	Personnel();
	Personnel(int);
	Personnel(int, int, char *, char *, long);

	int getSSN();
	static int size();

	void writeToFile(fstream&);
	void readFromFile(fstream&);
	ostream& writeToConsole(ostream& outputStream);
	istream& readFromConsole(istream& inputStream);

	friend bool operator ==(int, const Personnel&);
	friend fstream& operator <<(fstream&, const Personnel&);
	friend fstream& operator >>(fstream&, Personnel&);
};
#endif