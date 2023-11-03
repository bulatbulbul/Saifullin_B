#pragma once
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

template <typename T>
T GetCorrectNumber(T min, T max) {
	int x;
	while ((cin >> x).fail() || cin.peek() != '\n' || x < min || x > max) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nДанные введены неверно" << endl;
	}
	return x;
}