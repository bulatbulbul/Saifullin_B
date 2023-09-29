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
		cout << "8. Выход" << endl;
		cin >> number;
		cout << "\n";
		//Проверка ввода в меню сделать
		break;
	}
	return number;
}

void Add_pipe(Pipe& p)
{
	cout << "Добавление трубы" << endl;
	cout << "Введите название: ";
	cin >> p.name;
	cout << "Введите длину: " << endl;
	cin >> p.length;
	cout << "Введите диаметр: " << endl;
	cin >> p.diameter;
	cout << "Введите признак 'в ремонте'  (0 - в ремонте, 1 - не в ремонте): " << endl;;
	cin >> p.sign;
	cout << "\n";
}
void Add_cs(CS& c)
{
	cout << "Добавление КС" << endl;
	cout << "Введите название: " << endl;
	cin >> c.name;
	cout << "Введите количество цехов: " << endl;
	cin >> c.number_workshop;
	cout << "Введите количество цехов в работе: "<< endl;
	cin >> c.in_work;
	cout << "Введите эффективность (от 0 до 1): " << endl;
	cin >> c.effectiveness;
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
void View(Pipe& p, CS& c, int score_pipe, int score_cs)
{
	int number;
	while (true)
	{
		cout << "Выберите:" << endl;
		cout << "1. Просмотр трубы" << endl;
		cout << "2. Просмотр КС" << endl;
		cout << "3. Назад" << endl;
		cin >> number;
		cout << "\n";
		switch (number)
		{
		case 1:
			if (score_pipe != 0)
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
			if (score_cs != 0)
			{
				View_cs(c);
			}
			else
			{
				cout << "Добавьте КС" << endl;
				cout << "\n";
			}
			break;
		case 3:
			menu();
			break;
			// проверку на ошибки
		}
		break;
	}
}

void Edit_pipe(Pipe& p)
{
	cout << "Редактирование трубы" << endl;
	cout << "Введите признак 'в ремонте'  (0 - в ремонте, 1 - не в ремонте): " << endl;
	cin >> p.sign;
	cout << "\n";
}

void Edit_cs(CS& c)
{
	cout << "Редактирование КС" << endl;
	cout << "Введите количество цехов в работе: " << endl;
	cin >> c.in_work;
	cout << "Введите эффективность (от 0 до 1): " << endl;
	cin >> c.effectiveness;
	cout << "\n";
}
void Save_pipe(Pipe& p)
{
	cout << "Труба сохранилась" << endl;
	cout << "\n";
	/*
	ofstream out;// поток для записи
	out.open("data.txt");  // открываем файл для записи
	if (out.is_open()) {
		out << p.name;
		out << "\n" << p.length;
		out << "\n" << p.diameter;
		out << "\n" << p.sign;
		out << "\n";
		out.close();
		cout << "Сохранилось" << endl;
	}
	else
	{
		cout << "Ошибка" << endl;
	}
	*/
}
void Save_cs(CS& c)
{
	cout << "КС сохранилась" << endl;
	cout << "\n";
	/*
	ofstream out;// поток для записи
	out.open("data.txt");  // открываем файл для записи
	if (out.is_open()) {
		out << c.name;
		out << "\n" << c.number_workshop;
		out << "\n" << c.in_work;
		out << "\n" << c.effectiveness;
		out << "\n";
		out.close();
		cout << "Сохранилось" << endl;
	}
	else
	{
		cout << "Ошибка" << endl;
	}
	*/
}


void Save(Pipe& p, CS& c, int score_pipe, int score_cs)
{
	int number;
	while (true)
	{
		cout << "Выберите:" << endl;
		cout << "1. Сохранить трубу" << endl;
		cout << "2. Сохранить КС" << endl;
		cout << "3. Назад" << endl;
		cin >> number;
		cout << "\n";
		switch (number)
		{
		case 1:
			if (score_pipe != 0)
			{
				Save_pipe(p);
			}
			else
			{
				cout << "Добавьте трубу" << endl;
				cout << "\n";
			}
			break;
		case 2:
			if (score_cs != 0)
			{
				Save_cs(c);
			}
			else
			{
				cout << "Добавьте КС" << endl;
				cout << "\n";
			}
			break;
		case 3:
			menu();
			break;
		// Ошибки 
		}
		break;
	}
}
void Load_pipe(Pipe& p)
{
		ifstream file("data.txt");
		if (file.is_open()) {
			file >> p.name;
			file >> p.length;
			file >> p.diameter;
			file >> p.sign;
			cout << "Данные загрузились из файла." << endl;
			cout << "\n";
			file.close();
		}
		else
		{
			cout << "Ошибка" << endl;
			cout << "\n";
		}
}
void Load_cs(CS& c)
{
	ifstream file("data.txt");
	if (file.is_open()) {
		file >> c.name;
		file >> c.number_workshop;
		file >> c.in_work;
		file >> c.effectiveness;
		cout << "Данные загрузились из файла." << endl;
		cout << "\n";
		file.close();
	}
	else
	{
		cout << "Ошибка" << endl;
		cout << "\n";
	}
}
void Load(Pipe& p,CS& c, int& score_pipe, int& score_cs)
{
	int number;
	while (true)
	{
		cout << "Выберите:" << endl;
		cout << "1. Загрузить трубу" << endl;
		cout << "2. Загрузить КС" << endl;
		cout << "3. Назад" << endl;
		cin >> number;
		cout << "\n";
			switch (number)
			{
			case 1:
				Load_pipe(p);
				score_pipe += 1;
				break;
			case 2:
				Load_cs(c);
				score_cs += 1;
				break;
			case 3:
				menu();
				break;
			// ошибки
			}
			break;
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
			if (score_pipe != 0 || score_cs != 0)
			{
				View(pipe, cs, score_pipe,score_cs);
			}
			else 
			{
				cout << "Нет трубы или КС" << endl;
				cout << "\n";
			}
			break;
		case 4:
			if (score_pipe != 0)
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
			if (score_cs != 0)
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
			if (score_pipe > 0 || score_cs > 0)
			{
				Save(pipe, cs,score_pipe, score_cs);
			}
			else
			{
				cout << "Добавьте трубу или КС" << endl;
				cout << "\n";
			}
			break;
		case 7:
			//если файл не пуст
			Load(pipe,cs,score_pipe,score_cs);
			break;
		case 8:
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
