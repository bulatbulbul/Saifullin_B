#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Pipe
{
	//Свойства трубы
	string name;//километровая отметка (название)
	double length;//длина
	double diameter;//диаметр
	bool sign;//признак "в ремонте"
};
