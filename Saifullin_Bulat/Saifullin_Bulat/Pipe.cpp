#include "Pipe.h"
#include <fstream>
#include <iostream>
#include <Header.h>

using namespace std;

void Add_pipe(Pipe& p)
{
	cout << "Добавление трубы" << endl;
	cout << "Введите название: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, p.name);
	cout << "Введите длину: ";
	p.length = GetCorrectNumber(0.0, DBL_MAX);
	cout << "Введите диаметр: ";
	p.diameter = GetCorrectNumber(0.0, DBL_MAX);
	p.sign = true;
	cout << "\n";
}

void View_pipe(Pipe& p)
{
	cout << "Просмотр трубы" << endl;
	cout << "Труба" << endl;
	cout << "Название: " << p.name << endl;
	cout << "Длина: " << p.length << endl;
	cout << "Диаметр: " << p.diameter << endl;
	cout << "Признак 'в ремонте' (0 - в ремонте, 1 - не в ремонте): " << p.sign << endl;
	cout << "\n";
}

void Edit_pipe(Pipe& p)
{
	if (p.name.size() != 0)
	{
		cout << "Редактирование трубы" << endl;
		cout << "Введите признак 'в ремонте'  (0 - в ремонте, 1 - не в ремонте): " << endl;
		p.sign = GetCorrectNumber(0, 1);
		cout << "\n";
	}
	else
	{
		cout << "Добавьте трубy" << endl;
		cout << "\n";
	}
}



