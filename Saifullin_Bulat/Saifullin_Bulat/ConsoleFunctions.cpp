#include <fstream>
#include <iostream>
#include <string>
#include <Pipe.h>
#include <CS.h>
#include <Header.h>
#include <ConsoleFunctions>

using namespace std;

int menu()
{
	int number;
	while (true)
	{
		cout << "�������� ����� �� ����" << endl;
		cout << "����:" << endl;
		cout << "1. �������� �����" << endl;
		cout << "2. �������� ��" << endl;
		cout << "3. �������� ���� ��������" << endl;
		cout << "4. ������������� �����" << endl;
		cout << "5. ������������� ��" << endl;
		cout << "6. ���������" << endl;
		cout << "7. ���������" << endl;
		cout << "0. �����" << endl;
		number = GetCorrectNumber(0, 7);
		cout << "\n";
		break;
	}
	return number;
}

void View(Pipe& p, CS& c)
{
	if ((p.name.size() != 0) || (c.name.size() != 0))
	{
		int number;
		while (true)
		{
			cout << "��������:" << endl;
			cout << "1. �������� �����" << endl;
			cout << "2. �������� ��" << endl;
			cout << "0. �����" << endl;
			number = GetCorrectNumber(0, 2);
			cout << "\n";
			switch (number)
			{
			case 1:
				if (p.name.size() != 0)
				{
					View_pipe(p);
				}
				else
				{
					cout << "�������� �����" << endl;
					cout << "\n";

				}
				break;
			case 2:
				if (c.name.size() != 0)
				{
					View_cs(c);
				}
				else
				{
					cout << "�������� ��" << endl;
					cout << "\n";
				}
				break;
			case 0:
				return;
			default:
				cout << "������ ������." << endl;
			}
		}
	}
	else
	{
		cout << "��� ����� � ��" << endl;
		cout << "\n";
	}
}

void Save(const Pipe& p, const CS& c)
{
	if ((p.name.size() != 0) || (c.name.size() != 0))
	{
		ofstream file("data.txt");
		if (p.name.size() != 0) {
			if (file.is_open()) {
				file << "Pipe" << endl;
				file << p.name << endl;
				file << p.length << endl;
				file << p.diameter << endl;
				file << p.sign << endl;

			}
			else {
				cout << "�� ������� ������� ����" << endl;
			}
		}
		if (c.name.size() != 0) {
			if (file.is_open()) {
				file << "CS" << endl;
				file << c.name << endl;
				file << c.number_workshop << endl;
				file << c.in_work << endl;
				file << c.effectiveness << endl;

			}
			else {
				cout << "�� ������� ������� ����" << endl;
			}
		}
		if ((p.name.size() == 0) && (c.name.size() == 0)) {
			cout << "�������� ����� ��� ��" << endl;
		}
		else {
			if ((p.name.size() != 0) && (c.name.size() != 0))
			{
				cout << "������ ����� � �� ���������" << endl;
			}
			else if (p.name.size() != 0)
			{
				cout << "������ ����� ���������" << endl;
			}
			else
			{
				cout << "������ �� ���������" << endl;
			}
		}
		file.close();
	}
	else
	{
		cout << "�������� ����� ��� ��" << endl;
		cout << "\n";
	}
}


void Load(Pipe& p, CS& c)
{
	string line;
	ifstream file("data.txt");
	if (file.is_open()) {
		getline(file, line);
		if (line == "Pipe") {
			getline(file, p.name);
			getline(file, line);
			p.length = stod(line);
			getline(file, line);
			p.diameter = stod(line);
			getline(file, line);
			p.sign = stoi(line);
			getline(file, line);
			cout << "������ ����� �����������" << endl;
			if (line == "CS") {
				getline(file, c.name);
				getline(file, line);
				c.number_workshop = stoi(line);
				getline(file, line);
				c.in_work = stoi(line);
				getline(file, line);
				c.effectiveness = stoi(line);
				cout << "������ �� �����������" << endl;
			}
		}
		else if (line == "CS") {
			getline(file, c.name);
			getline(file, line);
			c.number_workshop = stoi(line);
			getline(file, line);
			c.in_work = stoi(line);
			getline(file, line);
			c.effectiveness = stod(line);
			cout << "������ �� �����������" << endl;
		}
		else {
			cout << "���� ����" << endl;
		}
	}
	else {
		cout << "�� ������� ������� ����" << endl;
	}
	file.close();

}

int main()
{
	setlocale(LC_ALL, "RUS");
	Pipe pipe;
	CS cs;
	while (true)
	{
		int number = menu();
		switch (number)
		{
		case 1:
			Add_pipe(pipe);
			break;
		case 2:
			Add_cs(cs);
			break;
		case 3:
			View(pipe, cs);
			break;
		case 4:
			Edit_pipe(pipe);
			break;
		case 5:
			Edit_cs(cs);
			break;
		case 6:
			Save(pipe, cs);
			break;
		case 7:
			Load(pipe, cs);
			break;
		case 0:
			cout << "����!";
			cout << "\n";
			return 0;
		default:
			cout << "�������� ����";
			cout << "\n";
			break;
		}
	}
}
