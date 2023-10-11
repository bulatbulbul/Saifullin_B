#include <iostream>
#include <fstream>
#include <string>

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

int isInteger(int min, int max) {
	int x;
	while ((cin >> x).fail() || cin.peek() != '\n' || x < min || x > max) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nДанные введены неверно" << endl;
	}
	return x;
}

double isDouble(double min, double max) {
	double x;
	while ((cin >> x).fail() || cin.peek() != '\n' || x < min || x > max) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nДанные введены неверно" << endl;
	}
	return x;
}
int menu()
{
	int number;
	while (true)
	{
		cout << "Выберите пункт из меню" << endl;
		cout << "Меню:" << endl;
		cout << "1. Добавить трубу" << endl;
		cout << "2. Добавить КС" << endl;
		cout << "3. Просмотр всех объектов" << endl;
		cout << "4. Редактировать трубу" << endl;
		cout << "5. Редактировать КС" << endl;
		cout << "6. Сохранить" << endl;
		cout << "7. Загрузить" << endl;
		cout << "0. Выход" << endl;
		number = isInteger(0, 7);
		cout << "\n";
		break;
	}
	return number;
}

void Add_pipe(Pipe& p)
{
	cout << "Добавление трубы" << endl;
	cout << "Введите название: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, p.name);
	cout << "Введите длину: ";
	p.length = isDouble(0.0, DBL_MAX);
	cout << "Введите диаметр: ";
	p.diameter = isDouble(0.0, DBL_MAX);
	p.sign = true;
	cout << "\n";
}

void Add_cs(CS& c)
{
	cout << "Добавление КС" << endl;
	cout << "Введите название: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, c.name);
	cout << "Введите количество цехов: ";
	c.number_workshop = isInteger(0, INT_MAX);
	cout << "Введите количество цехов в работе: ";
	c.in_work = isInteger(0, c.number_workshop);
	cout << "Введите эффективность (от 0 до 1): ";
	c.effectiveness = isDouble(0.0, 1.0);
	cout << "\n";
}

void View_pipe(Pipe& p)
{
	cout << "Просмотр трубы" << endl;
	cout << "Труба"<< endl;
	cout << "Название: "<< p.name << endl;
	cout << "Длина: " << p.length << endl;
	cout << "Диаметр: " << p.diameter << endl;
	cout << "Признак 'в ремонте' (0 - в ремонте, 1 - не в ремонте): " << p.sign << endl;
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
void View(Pipe& p, CS& c)
{
	int number;
	while (true)
	{
		cout << "Выберите:" << endl;
		cout << "1. Просмотр трубы" << endl;
		cout << "2. Просмотр КС" << endl;
		cout << "0. Назад" << endl;
		number = isInteger(0, 2);
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
				cout << "Добавьте трубу" << endl;
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
				cout << "Добавьте КС" << endl;
				cout << "\n";
			}
			break;
		case 0:
			return ;
		default:
			cout << "Ошибка выбора." << endl;
		}
	}
}

void Edit_pipe(Pipe& p)
{
	cout << "Редактирование трубы" << endl;
	cout << "Введите признак 'в ремонте'  (0 - в ремонте, 1 - не в ремонте): " << endl;
	p.sign = isInteger(0,1);
	cout << "\n";
}

void Edit_cs(CS& c)
{
	cout << "Редактирование КС" << endl;
	cout << "Введите количество цехов в работе: " << endl;
	c.in_work = isInteger(0, c.number_workshop);
	cout << "Введите эффективность (от 0 до 1): " << endl;
	c.effectiveness = isDouble(0, 1);
	cout << "\n";
}

void Save_pipe(Pipe& p, ofstream& out) {
	if (out.is_open()) {
		out << p.name << endl;
		out << p.length << endl;
		out << p.diameter << endl;
		out << p.sign << endl;
		cout << "Данные трубы сохранены" << endl;
	}
	else {
		cout << "Ошибка!";
	}
}

void Save_cs(CS& c, ofstream& out) {
	if (out.is_open()) {
		out << c.name << endl;
		out << c.number_workshop << endl;
		out << c.in_work << endl;
		out << c.effectiveness << endl;
		cout << "Данные КС сохранены" << endl;
	}
	else {
		cout << "Ошибка!";
	}
}


void Load_pipe(Pipe & p, ifstream& read) {
	if (read.is_open()) {
		read >> p.name;
		read >> p.length;
		read >> p.diameter;
		read >> p.sign;
		cout << "Данные трубы загрузились" << endl;

	}
	else {
		cout << "Ошибка!";
	}
}

void Load_cs(CS& c, ifstream& read) {
	if (read.is_open()) {
		read >> c.name;
		read >> c.number_workshop;
		read >> c.in_work;
		read >> c.effectiveness;
		cout << "Данные КС загрузились" << endl;

	}
	else {
		cout << "Ошибка!";
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	Pipe pipe;
	CS cs;
	ifstream read;
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
			if ((pipe.name.size() != 0) || (cs.name.size() != 0))
			{
				View(pipe, cs);
			}
			else 
			{
				cout << "Нет трубы и КС" << endl;
				cout << "\n";
			}
			break;
		case 4:
			if (pipe.name.size() != 0)
			{
				Edit_pipe(pipe);
			}
			else
			{
				cout << "Добавьте трубy" << endl;
				cout << "\n";
			}
			break;
		case 5:
			if (cs.name.size() != 0)
			{
				Edit_cs(cs);
			}
			else
			{
				cout << "Добавьте КС" << endl;
				cout << "\n";
			}
			break;
		case 6:
			if ((pipe.name.size() != 0) || (cs.name.size() != 0))
			{
				ofstream out;
				out.open("data.txt");
				if (pipe.name.size() != 0) {
					out << "Pipe\n";
					Save_pipe(pipe, out);
				}
				if (cs.name.size() != 0) {
					out << "CS\n";
					Save_cs(cs, out);
				}
				break;
			}
			else
			{
				cout << "Добавьте трубу или КС" << endl;
				cout << "\n";
			}
			break;
		case 7:
			read.open("data.txt");
			if (read.peek() == std::ifstream::traits_type::eof()) {  // условие пустоты файла
				cout << "Файл пуст!\n";
			}
			else {
				string line;
				while (getline(read, line)) {
					if (line.find("Pipe") != string::npos) {
						Load_pipe(pipe, read);
					}
					if (line.find("CS") != string::npos) {
						Load_cs(cs, read);
					}
				}
			}
			break;
		case 0:
			cout << "Пока!";
			cout << "\n";
			return 0;
		default:
			cout << "Неверный ввод";
			cout << "\n";
			break;
		}
	}
}
