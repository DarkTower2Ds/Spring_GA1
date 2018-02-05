#include <iostream>
#include <fstream>
#include <cstring>
#include "Database.h"
#include "Personnel.h"
using namespace std;

template<class T>
Database<T>::Database()
{

}

template<class T>
Database<T>::Database(char* path)
{
	filepath = path;
	cout << "The path is " << filepath << endl;

	try
	{
		stream.open(path, ios::in | ios::out);

		T temp;
		stream.seekp(0, ios::end);
		size =  stream.tellp() /  temp.size();
		cout << "A size is " << size << endl;
	}
	catch (exception e)
	{
		cerr << "There was an error opening the file..." << endl;
		e.what();
	}
}

template<class T>
fstream& Database<T>::getStream()
{
	return stream;
}

template<class T>
int Database<T>::find(char ssn[9])
{
	cout << "SSN Entered is " << ssn << endl;
	cout << "Size is " << Personnel::size() << endl;
	char* temp = new char[9];
	for (int i = 0; i < size; i++)
	{
		stream.seekg((i * Personnel::size()));

		cout << "tellg =\t" << stream.tellg() << endl;
		stream.get(temp, 10);

		cout << "i =\t" << i << endl;
		cout << "i*s =\t" << i * Personnel::size() << endl;
		cout << "tellg =\t" << stream.tellg() << endl;
		cout << "temp =\t" << temp << endl;

		cout << temp << " ?= " << ssn << " = " << strcmp(temp, ssn) << endl;
		if (strcmp(temp, ssn) == 0)
		{
			cout << "I is returning " << i << endl;
			return i;
		}
	}

	delete temp;

	return -1;
}

template<class T>
void Database<T>::add()
{
	cout << "Enter the 9-digit SSN without any \"-\" characters: ";
	int ssn;
	cin >> ssn;

	cout << "\nEnter the 4-digit year of birth: ";
	int yob;
	cin >> yob;

	cout << "\nEnter the salary: ";
	long salary;
	cin >> salary;

	cout << "\nEnter the name: ";
	char* name;
	cin >> name;

	cout << "\nEnter the city-name: ";
	char* cityName;
	cin >> cityName;

	T temp(ssn, yob, name, cityName, salary);
	stream.seekp(ios::end);
	temp.writeToFile(stream);
}

template<class T>
void Database<T>::modify()
{
	char ssn[9];
	cout << "Enter the 9-digit SSN of the entry you would like to modify without any \"-\" characters: ";
	cin >> ssn;

	int index = find(ssn);
	if (index < 0)
	{
		cout << "The entry with the SSN \"" << ssn << "\" was not found" << endl;
	}
	else
	{
		stream.seekg(index * Personnel::size());
		T temp;
		temp.readFromFile(stream);
		/*int tssn, tyob;
		long tsalary;
		char tname[10], tcity[10], ctssn[9], ctyob[4], ctsal[4];

		stream.get(ctssn, 10);
		tssn = std::stoi(ctssn);
		stream.get(ctyob, 5);
		tyob = std::stoi(ctyob);

		stream.get(ctsal, 5);
		tsalary = std::atol(ctsal);

		stream.get(tname, 11);
		stream.get(tcity, 11);

		T temp(tssn, tyob, tname, tcity, tsalary);*/
		cout << "This is the entry you have selected to edit:" << endl;

		temp.writeToConsole(cout);
	}
}

template class Database<Personnel>;