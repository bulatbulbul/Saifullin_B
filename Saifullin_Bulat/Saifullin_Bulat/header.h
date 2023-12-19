#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Pipe.h"
#include "CS.h"
#include "Graph.h"
#include <format>
#include <chrono>
#include <sstream>
#include <queue>
#include <limits>

using namespace std;

#define INPUT_LINE(in, str) getline(in>>ws, str); \
						cerr << str << endl

class redirect_output_wrapper
{
    std::ostream& stream;
    std::streambuf* const old_buf;
public:
    redirect_output_wrapper(std::ostream& src)
        :old_buf(src.rdbuf()), stream(src)
    {
    }

    ~redirect_output_wrapper() {
        stream.rdbuf(old_buf);
    }
    void redirect(std::ostream& dest)
    {
        stream.rdbuf(dest.rdbuf());
    }
};


template <typename T>
T correctnumber(T min, T max) {
    T x;
    while (((cin >> x).fail()) || (cin.peek() != '\n') || (x < min) || (x > max)) {
        cout << "\nНеверный ввод данных!" << endl;
        cout << "Введите число от " << min << " до " << max << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    cerr << x << endl;
    return x;
}

template <typename T>
T correctdiametr() {
    T x;
    while (((cin >> x).fail()) || (cin.peek() != '\n') || ((x != 500) && (x != 700) && (x != 1000) && (x != 1400))) {
        cout << "\nНеверный ввод данных!" << endl;
        cout << "Введите число из списка: (500, 700, 1000, 1400) " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return x;
}


template <typename T>
ostream& operator<< (ostream& out, unordered_map <int, T>& p) {
    out << "ID: ";
    for (auto& [i, obj] : p) {
        out << i << " ";
    }
    out << endl;
    return out;
}
template <typename T>
using filter_p = bool (*) (Pipe p, T par);
template <typename T>
using filter_cs = bool(*) (CS cs, T par);
template <typename T>
vector <int> search_p_by_parametr(unordered_map <int, Pipe>& pipe_group, filter_p<T> f, T par) {
    vector <int> id;
    for (auto& pipe : pipe_group) {
        if (f(pipe.second, par))
            id.push_back(pipe.second.get_id());
    }
    return id;
}
template <typename T>
vector <int> search_cs_by_parametr(unordered_map <int, CS>& cs_group, filter_cs<T> f, T par) {
    vector <int> id;
    for (auto& cs : cs_group) {
        if (f(cs.second, par))
            id.push_back(cs.second.get_id());
    }
    return id;
}

;
