#ifndef STUDENT_H
#define SUTDENT_H
#include<string>
#include<iostream>
using namespace std;

class Student {
private:
	string major;
public:
	Student();
	void readWriteFile(ofstream &of, ifstream &ifs, string word[]);
};
#endif