#include "CS.h"
#include <fstream>
#include <iostream>
#include <Header.h>

using namespace std;

void Add_cs(CS& c)
{
	cout << "Добавление КС" << endl;
	cout << "Введите название: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, c.name);
	cout << "Введите количество цехов: ";
	c.number_workshop = GetCorrectNumber(0, INT_MAX);
	cout << "Введите количество цехов в работе: ";
	c.in_work = GetCorrectNumber(0, c.number_workshop);
	cout << "Введите эффективность (от 0 до 1): ";
	c.effectiveness = GetCorrectNumber(0.0, 1.0);
	cout << "\n";
}

void View_cs(CS& c)
{
	cout << "Просмотр КС" << endl;
	cout << "КС" << endl;
	cout << "Название: " << c.name << endl;
	cout << "Количество цехов: " << c.number_workshop << endl;
	cout << "Количество цехов в работе: " << c.in_work << endl;
	cout << "Эффективность (от 0 до 1): " << c.effectiveness << endl;
	cout << "\n";
}

void Edit_cs(CS& c)
{
	if (c.name.size() != 0)
	{
		cout << "Редактирование КС" << endl;
		cout << "Введите количество цехов в работе: " << endl;
		c.in_work = GetCorrectNumber(0, c.number_workshop);
		cout << "Введите эффективность (от 0 до 1): " << endl;
		c.effectiveness = GetCorrectNumber(0, 1);
		cout << "\n";
	}
	else
	{
		cout << "Добавьте КС" << endl;
		cout << "\n";
	}
}

