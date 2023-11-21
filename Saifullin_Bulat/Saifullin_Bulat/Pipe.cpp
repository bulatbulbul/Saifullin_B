#include <iostream>
#include <fstream>

#include "Pipe.h"
#include "Functions.h"

using namespace std;

int Pipe::Nextid = 1;

Pipe::Pipe()
{
	this->id = Nextid;
	Nextid += 1;
}

void Pipe::add() {
	cout << "������� �������� �����: ";
	name = get_str();
	cout << "������� ����� �����: ";
	length = get_correct_value<int>(1, INT_MAX);
	cout << "������� ������� �����: ";
	diameter = get_correct_value<int>(1, INT_MAX);
	cout << "�������� �� ��� �������?: ";
	maintenance = get_correct_value<bool>(0, 1);
}

void Pipe::view() {
	if (!name.empty()) {
		cout << "�����" << '\n';
		cout << id << endl;
		cout << "�������� ����� - " << name << '\n';
		cout << "����� ����� - " << length << '\n';
		cout << "������� ����� - " << diameter << '\n';
		if (maintenance == 1) {
			cout << "������?: Yes\n";
		}
		else {
			cout << "������?: No\n";
		}
	}
	else {
		cout << "����� �����������\n";
	}
}

void Pipe::change() {
	cout << "�������� ����� � id " << id << '\n';
	cout << "�������� ����� ��� ���(0 - ��������, 1 - �� ��������): ";
	maintenance = get_correct_value(0, 1);
}

void Pipe::save(ofstream& out) {
	if (out.is_open()) {
		out << "pipe" << '\n';
		out << id << '\n';
		out << name << '\n';
		out << length << '\n';
		out << diameter << '\n';
		out << maintenance << '\n';
		cout << "������ ����� " << id << " ��������� � ����." << '\n';
	}
	else {
		cout << "������!";
	}
}

void Pipe::download(ifstream& read) {
	if (read.is_open()) {
		read >> id;
		read >> name;
		read >> length;
		read >> diameter;
		read >> maintenance;

	}
	else {
		cout << "������!";
	}
}