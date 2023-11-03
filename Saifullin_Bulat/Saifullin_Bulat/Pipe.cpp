#include "Pipe.h"
#include <fstream>
#include <iostream>
#include <Header.h>

using namespace std;

void Add_pipe(Pipe& p)
{
	cout << "���������� �����" << endl;
	cout << "������� ��������: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, p.name);
	cout << "������� �����: ";
	p.length = GetCorrectNumber(0.0, DBL_MAX);
	cout << "������� �������: ";
	p.diameter = GetCorrectNumber(0.0, DBL_MAX);
	p.sign = true;
	cout << "\n";
}

void View_pipe(Pipe& p)
{
	cout << "�������� �����" << endl;
	cout << "�����" << endl;
	cout << "��������: " << p.name << endl;
	cout << "�����: " << p.length << endl;
	cout << "�������: " << p.diameter << endl;
	cout << "������� '� �������' (0 - � �������, 1 - �� � �������): " << p.sign << endl;
	cout << "\n";
}

void Edit_pipe(Pipe& p)
{
	if (p.name.size() != 0)
	{
		cout << "�������������� �����" << endl;
		cout << "������� ������� '� �������'  (0 - � �������, 1 - �� � �������): " << endl;
		p.sign = GetCorrectNumber(0, 1);
		cout << "\n";
	}
	else
	{
		cout << "�������� ����y" << endl;
		cout << "\n";
	}
}



