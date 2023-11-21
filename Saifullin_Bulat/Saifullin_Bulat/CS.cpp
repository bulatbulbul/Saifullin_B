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
	cout << "Введите название станции: ";
	name = get_str();
	cout << "Введите количество цехов: ";
	num_department = get_correct_value<int>(0, INT_MAX);
	cout << "Введите количество работающих цехов: ";
	work_department = get_correct_value<int>(0, num_department);
	cout << "Введите его эффективность: ";
	efficiency = get_correct_value<double>(0.0, DBL_MAX);
}

void CS::view() {
	if (!name.empty()) {
		cout << "Станция" << '\n';
		cout << getid() << endl;
		cout << "Название станции - " << name << '\n';
		cout << "Количество цехов - " << num_department << '\n';
		cout << "Количество работающих цехов - " << work_department << '\n';
		cout << "Эффективность станции - " << efficiency << '\n';
	}
	else {
		cout << "КС отсутствует\n";
	}
}

void CS::change() {
	cout << "Меняется КС с id " << id << '\n';
	cout << "Сколько цехов задействовано в работе: ";
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
		cout << "Ошибка!";
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
		cout << "Ошибка!";
	}
}
