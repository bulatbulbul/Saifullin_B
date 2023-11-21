// Защита от многократного включения заголовочного файла
#pragma once

#include <iostream>

using namespace std;

// Класс, обертывающий вывод для перенаправления вывода в другой поток
class redirect_output_wrapper
{
	ostream& stream;         // Ссылка на поток, который нужно перенаправить
	streambuf* const old_buf; // Указатель на оригинальный буфер потока (для восстановления)

public:
	// Конструктор класса, сохраняющий оригинальный буфер потока
	redirect_output_wrapper(ostream& src)
		: old_buf(src.rdbuf()), stream(src)
	{
	}

	// Деструктор класса, восстанавливающий оригинальный буфер потока
	~redirect_output_wrapper() {
		stream.rdbuf(old_buf);
	}

	// Метод для перенаправления вывода в другой поток
	void redirect(ostream& dest)
	{
		stream.rdbuf(dest.rdbuf());
	}
};