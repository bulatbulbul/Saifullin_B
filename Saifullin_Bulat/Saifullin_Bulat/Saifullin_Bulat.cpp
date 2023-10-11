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

void Save(Pipe& p, CS& c)
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
			cout << "Не удалось открыть файл" << endl;
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
			cout << "Не удалось открыть файл" << endl;
		}
	}
	if ((p.name.size() == 0) && (c.name.size() == 0)) {
		cout << "Добавьте трубу или КС" << endl;
	}
	else {
		if ((p.name.size() != 0) && (c.name.size() != 0))
		{
			cout << "Данные трубы и КС сохранены" << endl;
		}
		else if (p.name.size() != 0)
		{
			cout << "Данные трубы сохранены" << endl;
		}
		else
		{
			cout << "Данные КС сохранены" << endl;
		}
	}
	file.close();
}

void Load(Pipe& p,CS& c)
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
			cout << "Данные трубы загрузились" << endl;
			if (line == "CS") {
				getline(file, c.name);
				getline(file, line);
				c.number_workshop = stoi(line);
				getline(file, line);
				c.in_work = stoi(line);
				getline(file, line);
				c.effectiveness = stoi(line);
				cout << "Данные КС загрузились" << endl;
			}
		}
		else if (line == "CS") {
			getline(file, c.name);
			getline(file, line);
			c.number_workshop = stoi(line);
			getline(file, line);
			c.in_work = stoi(line);
			getline(file, line);
			c.effectiveness = stoi(line);
			cout << "Данные КС загрузились" << endl;
		}
		else {
			cout << "Файл пуст" << endl;
		}
	}
	else {
		cout << "Не удалось открыть файл" << endl;
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
				Save(pipe, cs);
			}
			else
			{
				cout << "Добавьте трубу или КС" << endl;
				cout << "\n";
			}
			break;
		case 7:
			Load(pipe,cs);
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
