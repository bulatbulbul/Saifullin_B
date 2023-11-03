#include "CS.h"
#include <fstream>
#include <iostream>
#include <Header.h>

using namespace std;

void Add_cs(CS& c)
{
	cout << "���������� ��" << endl;
	cout << "������� ��������: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, c.name);
	cout << "������� ���������� �����: ";
	c.number_workshop = GetCorrectNumber(0, INT_MAX);
	cout << "������� ���������� ����� � ������: ";
	c.in_work = GetCorrectNumber(0, c.number_workshop);
	cout << "������� ������������� (�� 0 �� 1): ";
	c.effectiveness = GetCorrectNumber(0.0, 1.0);
	cout << "\n";
}

void View_cs(CS& c)
{
	cout << "�������� ��" << endl;
	cout << "��" << endl;
	cout << "��������: " << c.name << endl;
	cout << "���������� �����: " << c.number_workshop << endl;
	cout << "���������� ����� � ������: " << c.in_work << endl;
	cout << "������������� (�� 0 �� 1): " << c.effectiveness << endl;
	cout << "\n";
}

void Edit_cs(CS& c)
{
	if (c.name.size() != 0)
	{
		cout << "�������������� ��" << endl;
		cout << "������� ���������� ����� � ������: " << endl;
		c.in_work = GetCorrectNumber(0, c.number_workshop);
		cout << "������� ������������� (�� 0 �� 1): " << endl;
		c.effectiveness = GetCorrectNumber(0, 1);
		cout << "\n";
	}
	else
	{
		cout << "�������� ��" << endl;
		cout << "\n";
	}
}

