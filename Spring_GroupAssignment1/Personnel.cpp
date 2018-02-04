#include <iostream>
#include <cstdlib>
#include "Personnel.h"
#include <bitset>
#include <string>
#include <fstream>
using namespace std;


Personnel::Personnel() : nameLen(10), cityLen(10)
{
	SSN = 123456789;
	YOB = 0000;
	salary = 100000;
	name = new char[nameLen + 1];
	city = new char[cityLen + 1];
}
Personnel::Personnel(int SSNin)
{
	int SSN = SSNin;
}
Personnel::Personnel(int ssn, int yob, char *n, char *c, long s) : nameLen(10), cityLen(10)
{
	name = new char[nameLen + 1];
	city = new char[cityLen + 1];
	SSN = ssn;
	YOB = yob;
	strcpy(name, n);
	strcpy(city, c);
	salary = s;
}
int Personnel::getSSN()
{
	return SSN;
}

bool operator ==(int x, const Personnel& y)
{
	return (x == y.SSN);
}

void Personnel::writeToFile(fstream& outputStream)
{
	outputStream << SSN;
	outputStream << YOB;
	outputStream.write(name, nameLen);
	outputStream.write(city, cityLen);
	outputStream.write(reinterpret_cast<const char*>(&salary), sizeof(long));
}
void Personnel::readFromFile(fstream& inputStream)
{
	char * temp = new char[nameLen + cityLen];
	inputStream.get(temp, 9);
	SSN = std::stoi(temp);
	inputStream.get(temp, 4);
	YOB = std::stoi(temp);
	inputStream.read(name, nameLen);
	inputStream.read(city, cityLen);
	inputStream.read(reinterpret_cast<char*>(&salary), sizeof(salary));
}
ostream& Personnel::writeToConsole(ostream& outputStream)
{
	outputStream << "SSN:" << SSN << endl;
	outputStream << "Year of Birth:" << YOB << endl;
	outputStream << "Name:" << name << endl;
	outputStream << "City:" << city << endl;
	outputStream << "Salary:" << salary << endl;
	return outputStream;
}
istream& Personnel::readFromConsole(istream& inputStream)
{
	char temp[50];
	cout << "SSN: ";
	inputStream.getline(temp, 9);
	SSN = std::stoi(temp);

	cout << "Year of Birth: ";
	inputStream.getline(temp, 4);
	YOB = std::stoi(temp);

	cout << "Name: ";
	inputStream.getline(temp, 50);
	strncpy(name, temp, nameLen);

	cout << "City:";
	inputStream.getline(temp, 50);
	strncpy(city, temp, cityLen);

	cout << "Salary: ";
	inputStream >> salary;

	inputStream.getline(temp, 50); //might be needed if the files are stored 1 per line
	return inputStream;
}

