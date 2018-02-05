#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Database
{
private:
	char* filepath;
	int size;

	fstream stream;
public:
	Database();
	Database(char* path);

	int find(char [9]);
	void add();
	void modify();

	fstream& getStream();
	char* getPath();
	void setPath(char* path);

	void print(fstream&);
};
#endif