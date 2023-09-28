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
	while (true) {
		string input;
		cout << "Выберите пункт из меню" << endl;
		cout << "Меню:" << endl;
		cout << "1. Добавить трубу" << endl;
		cout << "2. Добавить КС" << endl;
		cout << "3. Просмотр всех объектов" << endl;
		cout << "4. Редактировать трубу" << endl;
		cout << "5. Редактировать КС" << endl;
		cout << "6. Сохранить" << endl;
		cout << "7. Загрузить" << endl;
		cout << "8. Выход" << endl;
		getline(cin, input);
		if (isInteger(input)) {
			istringstream iss(input);
			iss >> noskipws >> number;
			break;
		}
		else {
			cout << "Неверный ввод\n";
			continue;
		}
	}
	return number;
}

int countLines(string filename) {
	ifstream file(filename);
	string line;
	int count = 0;

	while (getline(file, line)) {
		count++;
	}
	file.close();
	return count;
}
void Add_pipe(Pipe& p)
{

	cout << "Добавление трубы" << endl;
	cout << "Введите название: ";

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
void Add_cs(CS& c)
{
	cout << "Добавление КС" << endl;
	cout << "Введите название: ";
	getline(cin, c.name);
	while (true) {
		string input;
		cout << "\nВведите количество цехов: ";
		getline(cin, input);
		if (isInteger(input)) {
			istringstream iss(input);
			iss >> noskipws >> c.number_workshop;
			break;
		}
		else {
			cout << "Неверный ввод\n";
			continue;
		}
	}

	while (true) {
		string input;
		cout << "\nВведите количество цехов в работе: ";
		getline(cin, input);
		if (isInteger(input)) {
			istringstream iss(input);
			iss >> noskipws >> c.in_work;
			break;
		}
		else {
			cout << "Неверный ввод\n";
			continue;
		}
	}
	while (true) {
		string input;
		cout << "\nВведите эффективность (от 0 до 1): ";
		getline(cin, input);
		if (isBool(input)) {
			istringstream iss(input);
			iss >> noskipws >> c.effectiveness;
			break;
		}
		else {
			cout << "Неверный ввод\n";
			continue;
		}
	}
	cout << "\n";
}

void View(Pipe& p, CS& c)
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
void Edit_pipe(Pipe& p)
{
	cout << "Редактирование трубы" << endl;
	cout << "Введите название: ";
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
void Edit_cs(CS& c)
{
	cout << "Редактирование КС" << endl;
	cout << "Введите название: ";
	getline(cin, c.name);
	while (true) {
		string input;
		cout << "\nВведите количество цехов: ";
		getline(cin, input);
		if (isInteger(input)) {
			istringstream iss(input);
			iss >> noskipws >> c.number_workshop;
			break;
		}
		else {
			cout << "Неверный ввод\n";
			continue;
		}
	}

	while (true) {
		string input;
		cout << "\nВведите количество цехов в работе: ";
		getline(cin, input);
		if (isInteger(input)) {
			istringstream iss(input);
			iss >> noskipws >> c.in_work;
			break;
		}
		else {
			cout << "Неверный ввод\n";
			continue;
		}
	}
	while (true) {
		string input;
		cout << "\nВведите эффективность (от 0 до 1): ";
		getline(cin, input);
		if (isBool(input)) {
			istringstream iss(input);
			iss >> noskipws >> c.effectiveness;
			break;
		}
		else {
			cout << "Неверный ввод\n";
			continue;
		}
	}
	cout << "\n";
}


void Write(Pipe& p, CS& c)
{
		ofstream out;// поток для записи
		out.open("data.txt");  // открываем файл для записи
		if (out.is_open()) {
			out << p.name;
			out << "\n" << p.length;
			out << "\n" << p.diameter;
			out << "\n" << p.sign;
			out << "\n" << c.name;
			out << "\n" << c.number_workshop;
			out << "\n" << c.in_work;
			out << "\n" << c.effectiveness;
			out.close();
			cout << "Сохранилось" << endl;
		}
		else
		{
			cout << "Ошибка" << endl;
		}
	}
	
void Save(Pipe& p,CS& c)
{
		ifstream file("data.txt");
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
		else
		{
			cout << "Ошибка" << endl;
		}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	Pipe pipe;
	CS cs;
	int score_pipe = 0;
	int score_cs = 0;
	while (true) 
	{
		int number = menu();
		switch (number)
		{
		case 1:
			Add_pipe(pipe);
			score_pipe += 1;
			break;
		case 2:
			Add_cs(cs);
			score_cs += 1;
			break;
		case 3:
			if (score_pipe > 0 && score_cs > 0)
			{
				View(pipe, cs);
			}
			else 
			{
				cout << "Нет трубы или КС" << endl;
			}
			break;
		case 4:
			if (score_pipe > 0)
			{
				Edit_pipe(pipe);
			}
			else
			{
				cout << "Нет трубы" << endl;
			}
			break;
		case 5:
			if (score_cs > 0)
			{
				Edit_cs(cs);
			}
			else
			{
				cout << "Нет КС" << endl;
			}
			break;
		case 6:
			if (score_pipe > 0 && score_cs > 0)
			{
				Save(pipe, cs);
			}
			else
			{
				cout << "Нет трубы или КС" << endl;
			}
			break;
		case 7:
			if (countLines("data.txt") == 8)
			{
				Write(pipe,cs);
				score_cs += 1;
				score_pipe += 1;
			}
			else
			{
				cout << "Не удалось загрузить" << endl;
			}
			break;
		case 8:
			cout << "Пока!";
			return 0;
		default:
			cout << "Неверный ввод\n";
			break;
		}
	}
}
