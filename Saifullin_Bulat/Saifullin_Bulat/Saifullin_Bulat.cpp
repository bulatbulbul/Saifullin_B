#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

struct Pipe 
{
	//Свойства трубы
	string name;//километровая отметка (название)
	double length;//длина
	double diameter;//диаметр
	bool sign;//признак "в ремонте"
};

struct CS
{
	//Свойства КС
	string name; //название
	int number_workshop;//количество цехов
	int in_work;//количество цехов в работе
	double effectiveness;//эффективность (некий показатель, обобщающий различные специфические характеристики) от 0 до 1
};

bool isDouble(const string& input) {
	istringstream iss(input);
	double test_variable;
	iss >> noskipws >> test_variable;
	return iss.eof() && !iss.fail() && test_variable > 0;
}

bool isInteger(const string& input) {
	istringstream iss(input);
	int test_variable;
	iss >> test_variable;
	return iss.eof() && !iss.fail() && test_variable > 0;
}

bool isBool(const string& input) {
	istringstream iss(input);
	bool test_variable;
	iss >> test_variable;
	return iss.eof() && !iss.fail();
}
int menu()
{
	int number;
	cout << "Выберите пункт из меню" << endl;
	cout << "Меню: 1. Добавить трубу 2. Добавить КС 3. Просмотр всех объектов 4. Редактировать трубу 5. Редактировать КС 6. Сохранить 7. Загрузить 0. Выход" << endl;
	cin >> number;
	return number;
}

void fun_1(Pipe& p)
{

	cout << "Добавление трубы" << endl;
	cout << "Введите название: ";
	cin.ignore(1000, '\n');
	getline(cin, p.name);

	while (true) {
		string input;
		cout << "\nВведите длину: ";
		getline(cin, input);
		if (isDouble(input)) {
			istringstream iss(input);
			iss >> noskipws >> p.length;
			break;
		}
		else {
			cout << "Неверный ввод\n";
			continue;
		}
	}
	
	while (true) {
		string input;
		cout << "\nВведите диаметр: ";
		getline(cin, input);
		if (isDouble(input)) {
			istringstream iss(input);
			iss >> noskipws >> p.diameter;
			break;
		}
		else {
			cout << "Неверный ввод\n";
			continue;
		}
	}
	while (true) {
		string input;
		cout << "\nВведите признак((0 - в ремонте, 1 - не в ремонте)) : ";
		getline(cin, input);
		if (isBool(input)) {
			istringstream iss(input);
			iss >> noskipws >> p.sign;
			break;
		}
		else {
			cout << "Неверный ввод\n";
			continue;
		}
	}
	cout << "\n";
}
void fun_2(CS& c)
{
	cout << "Добавление КС" << endl;
	cout << "Введите название: ";
	cin >> c.name;
	cout << "\nВведите количество цехов: ";
	cin >> c.number_workshop;
	cout << "\nВведите количество цехов в работе: ";
	cin >> c.in_work;
	cout << "\nВведите эффективность (от 0 до 1): ";
	cin >> c.effectiveness;
	cout << "\n";
}

void fun_3(Pipe& p, CS& c)
{
	cout << "Просмотр всех объектов" << endl;
	cout << "Труба"<< endl;
	cout << "Название: "<< p.name << endl;
	cout << "Длина: " << p.length << endl;
	cout << "Диаметр: " << p.diameter << endl;
	cout << "Признак ((0 - в ремонте, 1 - не в ремонте)): " << p.sign << endl;

	cout << "КС" << endl;
	cout << "Название: " << c.name << endl;
	cout << "Количество цехов: " << c.number_workshop << endl;
	cout << "Количество цехов в работе: " << c.in_work << endl;
	cout << "Эффективность (от 0 до 1): " << c.effectiveness << endl;
}
void fun_4(Pipe& p)
{
	cout << "Редактирование трубы" << endl;
	cout << "Введите название: ";
	cin >> p.name;
	cout << "\nВведите длину: ";
	cin >> p.length;
	cout << "\nВведите диаметр: ";
	cin >> p.diameter;
	cout << "\nВведите признак (0 - в ремонте, 1 - не в ремонте): ";
	cin >> p.sign;
	cout << "\n";

}
void fun_5(CS& c)
{
	cout << "Редактирование КС" << endl;
	cout << "Введите название: ";
	cin >> c.name;
	cout << "\nВведите количество цехов: ";
	cin >> c.number_workshop;
	cout << "\nВведите количество цехов в работе: ";
	cin >> c.in_work;
	cout << "\nВведите эффективность: ";
	cin >> c.effectiveness;
	cout << "\n";
}

void fun_6(Pipe& p, CS& c)
{
	ofstream out;// поток для записи
	out.open("data_1.txt");  // открываем файл для записи
	if (out.is_open()) {
		out << "Труба";
		out << "\nНазвание: " << p.name;
		out << "\nДлина: " << p.length;
		out << "\nДиаметр: " << p.diameter;
		out << "\nДлина: " << p.sign;
		out << "\nКС";
		out << "\nНазвание: " << c.name;
		out << "\nКоличество цехов: " << c.number_workshop;
		out << "\nКоличество цехов в работе: " << c.in_work;
		out << "\nЭффективность: " << c.effectiveness;
		out.close();
		cout << "Сохранилось" << endl;
	}
}
void fun_7(Pipe& p,CS& c)
{
		ifstream file("data_2.txt");
		if (file.is_open()) {
			file >> p.name;
			file >> p.length;
			file >> p.diameter;
			file >> p.sign;
			file >> c.name;
			file >> c.number_workshop;
			file >> c.in_work;
			file >> c.effectiveness;
			cout << "Данные загрузились из файла." << endl;
			file.close();
		}
}
void fun_default()
{
	cout << "Неверно выбрали пункт из меню, попробуйте еще раз." << endl;
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
			fun_1(pipe);
			break;
		case 2:
			fun_2(cs);
			break;
		case 3:
			fun_3(pipe,cs);
			break;
		case 4:
			fun_4(pipe);
			break;
		case 5:
			fun_5(cs);
			break;
		case 6:
			fun_6(pipe,cs);
			break;
		case 7:
			fun_7(pipe,cs);
			break;
		case 0:
			return 0;
		default:
			fun_default();
			break;
		}
	}
	
}
