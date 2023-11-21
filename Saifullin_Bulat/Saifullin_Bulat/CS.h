#pragma once
#include <fstream>

using namespace std;

class CS
{
	int id;
	static int Nextid;
public:
	inline int getid() const { return id; };
	string name;
	int num_department;
	int work_department;
	double efficiency;
	CS();
	void add();
	void view();
	void change();
	void download(ifstream& read);
	void save(ofstream& out);
};