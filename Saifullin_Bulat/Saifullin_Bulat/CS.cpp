#include <iostream>
#include <fstream>

#include "CS.h"
#include "Functions.h"

using namespace std;

int CS::Nextid = 1;

CS::CS()
{
	this->id = Nextid;
	Nextid += 1;
}

void CS::add() {
	cout << "������� �������� �������: ";
	name = get_str();
	cout << "������� ���������� �����: ";
	num_department = get_correct_value<int>(0, INT_MAX);
	cout << "������� ���������� ���������� �����: ";
	work_department = get_correct_value<int>(0, num_department);
	cout << "������� ��� �������������: ";
	efficiency = get_correct_value<double>(0.0, DBL_MAX);
}

void CS::view() {
	if (!name.empty()) {
		cout << "�������" << '\n';
		cout << getid() << endl;
		cout << "�������� ������� - " << name << '\n';
		cout << "���������� ����� - " << num_department << '\n';
		cout << "���������� ���������� ����� - " << work_department << '\n';
		cout << "������������� ������� - " << efficiency << '\n';
	}
	else {
		cout << "�� �����������\n";
	}
}

void CS::change() {
	cout << "�������� �� � id " << id << '\n';
	cout << "������� ����� ������������� � ������: ";
	work_department = get_correct_value(0, num_department);
}

void CS::save(ofstream& out) {
	if (out.is_open()) {
		out << "comp" << '\n';
		out << id << '\n';
		out << name << '\n';
		out << num_department << '\n';
	}
	else {
		cout << "������!";
	}
}

void CS::download(ifstream& read) {
	if (read.is_open()) {
		read >> id;
		read >> name;
		read >> num_department;
		read >> work_department;
		read >> efficiency;
	}
	else {
		cout << "������!";
	}
}
