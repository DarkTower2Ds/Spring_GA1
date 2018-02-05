#include <iostream>
#include<fstream>
#include<string>
#include"Student.h"
using namespace std;

Student::Student()
{
	string major;
}

void Student::readWriteFile(ofstream &ofs, ifstream &ifs, string word[])
{
	int counter = 0;
	ofs.open("output.txt", ios::app);
	while (ifs.good())
	{
		ifs >> word[counter];
		counter++;
	}
	ifs.close();

	for (int i = 0; i < counter; i++)
	{
		ofs << "Student's Major: " << word[i] << endl;
	}

	ofs.close();
}

int main()
{
	const int maxSize = 10;
	ifstream input;
	ofstream output;
	input.open("Info.txt");
	string data[maxSize];

	Student student1;
	student1.readWriteFile(output, input, data);

	return 0;
}