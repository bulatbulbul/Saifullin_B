#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

#include "CS.h"
#include "Pipe.h"
#include "logging.h"

using namespace std;
extern unordered_map<int, Pipe> data_P;
extern unordered_map<int, CS> data_KS;



inline void menu() {
    cout << "1. Добавить трубу" << '\n';
    cout << "2. Добавить КС" << '\n';
    cout << "3. Просмотр объектов" << '\n';
    cout << "4. Редактировать трубу" << '\n';
    cout << "5. Редактировать КС" << '\n';
    cout << "6. Сохранить" << '\n';
    cout << "7. Загрузить" << '\n';
    cout << "0. Выход" << '\n' << '\n';
}



template <typename T>
T get_correct_value(T min, T max) {
    T value;
    cin >> value;
    cerr << value << '\n';
    while (cin.fail() || cin.peek() != '\n' || value < min || value > max) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Данные введены неверно, попробуйте ещё раз: ";
        cin >> value;
        cerr << value << '\n';
    }
    return value;
}

// Шаблонная функция для получения списка идентификаторов из словаря
template <typename T>
vector<int> get_ids(const unordered_map<int, T>& dict)
{
    unordered_set<int> ids;
    cout << "Введите id; если закончили, то -1" << '\n';
    while (1) {
        int id = get_correct_value(-1, INT_MAX);
        if (id == -1) {
            break;
        }
        else if (dict.contains(id)) {
            ids.insert(id);
        }
        else {
            cout << "Нет объекта с этим id" << '\n';;
        }
        if (ids.size() == dict.size()) {
            break;
        }
    }
    return vector<int>(ids.begin(), ids.end());
}


template<typename T1, typename T2>
using filter = bool(*)(const T1& dict, T2 param);

// Функция-фильтр для сравнения по имени
template<typename T>
bool filter_by_name(const T& dict, string name) {
    return dict.name.find(name) != string::npos;
}

// Шаблонная функция для поиска элементов по заданному фильтру
template <typename T1, typename T2>
unordered_set<int> find_by_filter(const unordered_map<int, T1>& dict, filter<T1, T2> f, T2 par) {
    unordered_set<int> ids;
    for (auto& pair : dict) {
        if (f(pair.second, par)) {
            ids.insert(pair.first);
        }
    }
    return ids;
}

// Шаблонная функция для просмотра данных в словаре
template <typename M>
void view_data(unordered_map<int, M>& dict) {
    for (auto const& pair : dict) {
        M value = pair.second;
        value.view();
    }
}

// Шаблонная функция для просмотра данных по конкретному идентификатору
template <typename F>
void view_id(unordered_map<int, F>& dict, int id) {
    for (auto const& pair : dict) {
        if (id == pair.first) {
            F value = pair.second;
            value.view();
        }
    }
}

// Шаблонная функция для добавления объекта в словарь
template <typename T>
void add_to_dict(unordered_map<int, T>& dict) {
    T obj;
    obj.add();
    dict.insert({ obj.getid(), obj });
}

inline string get_str() {
    string str;
    cin >> ws;
    getline(std::cin, str);
    cerr << str << '\n';
    return str;
}

// Функция-фильтр для сравнения по статусу обслуживания трубы
inline bool filter_by_status(const Pipe& dict, bool status) {
    return dict.maintenance == status;
}

// Функция-фильтр для сравнения по проценту незадействованных цехов КС
inline bool filter_by_non_working(const CS& dict, int non_working) {
    return dict.num_department - dict.work_department == dict.num_department * non_working / 100;
}

inline void thirth() {
    cout << "1 - посмотреть все объекты, 0 - отфильтровать информацию: ";
    if (bool choice1 = get_correct_value(0, 1)) {
        view_data(data_P);
        view_data(data_KS);
    }
    else {
        cout << "1 - Трубу, 0 - КС: ";
        if (bool choice2 = get_correct_value(0, 1)) {
            cout << "1 - по названию, 0 - по ремонту: ";
            if (bool choice3 = get_correct_value(0, 1)) {
                cout << "Введите название: ";
                // Ввод названия для фильтрации
                string name = get_str();
                // Поиск и просмотр данных труб по фильтру по названию
                for (int i : find_by_filter(data_P, filter_by_name, name)) {
                    view_id(data_P, i);
                }
            }
            else {
                cout << "Введите статус: ";
                // Ввод статуса для фильтрации
                bool maintenance = get_correct_value(0, 1);
                // Поиск и просмотр данных труб по фильтру по статусу обслуживания
                for (int i : find_by_filter(data_P, filter_by_status, maintenance)) {
                    view_id(data_P, i);
                }
            }
        }
        else {
            cout << "1 - по названию, 0 - по проценту незадействованных цехов: ";
            if (bool choice4 = get_correct_value(0, 1)) {
                cout << "Введите название: ";
                // Ввод названия для фильтрации
                string name = get_str();
                // Поиск и просмотр данных КС по фильтру по названию
                for (int i : find_by_filter(data_KS, filter_by_name, name)) {
                    view_id(data_KS, i);
                }
            }
            else {
                cout << "Введите процент: ";
                // Ввод процента для фильтрации
                int non_working = get_correct_value(0, 100);
                // Поиск и просмотр данных КС по фильтру по проценту незадействованных цехов
                for (int i : find_by_filter(data_KS, filter_by_non_working, non_working)) {
                    view_id(data_KS, i);
                }
            }
        }
    }
}

inline void fourth() {
    if (!data_P.empty()) {
        cout << "1 - удаление, 0 - изменение труб: ";
        bool choice1 = get_correct_value(0, 1);
        vector<int> ids;
        cout << "Введите название трубы: ";
        // Ввод названия трубы для фильтрации
        string name = get_str();
        unordered_set<int> set = find_by_filter(data_P, filter_by_name, name);
        if (set.size() == 0) {
            cout << "Такого имени нет";
        }
        else {
            if (choice1) {
                cout << "1 - удалить все трубы, 0 - на ваш выбор: ";
                bool choice2 = get_correct_value(0, 1);
                if (!choice2) {
                    cout << "Можете выбирать из данного набора id" << '\n';
                    for (const auto& id : set) {
                        cout << id << '\n';
                    }
                    // Получение выбранных id для удаления
                    ids = get_ids(data_P);
                    for (int id : ids) {
                        data_P.erase(id);
                    }
                }
                else {
                    // Удаление всех труб с данным названием
                    for (int id : set) {
                        data_P.erase(id);
                    }
                }
            }
            else {
                cout << "1 - поменять все трубы, 0 - на ваш выбор: ";
                bool choice3 = get_correct_value(0, 1);
                if (!choice3) {
                    cout << "Можете выбирать из данного набора id" << '\n';
                    for (const auto& id : set) {
                        cout << id << '\n';
                    }
                    // Получение выбранных id для изменения
                    ids = get_ids(data_P);
                    for (int id : ids) {
                        data_P[id].change();
                    }
                }
                else {
                    cout << "В ремонте?(0 - нет , 1 - да): ";
                    // Изменение статуса ремонта для выбранных труб
                    for (int id : set) {
                        data_P[id].change();
                    }
                }
            }
        }
    }
    else {
        cout << "Нет труб для изменений" << '\n';
    }
}


inline void fif() {
    if (!data_KS.empty()) {
        cout << "1 - удаление, 0 - изменение КС: ";
        bool choice = get_correct_value(0, 1);
        cout << "Введите название КС: ";
        // Ввод названия КС для фильтрации
        string name = get_str();
        unordered_set<int> set = find_by_filter(data_KS, filter_by_name, name);
        if (set.size() == 0) {
            cout << "Такого имени нет" << "\n";
        }
        else {
            for (int id : set) {
                if (choice) {
                    // Удаление выбранных КС
                    data_KS.erase(id);
                }
                else {
                    // Изменение выбранных КС
                    data_KS[id].change();
                }
            }
        }
    }
    else {
        cout << "Нет КС для изменений" << '\n';
    }
}

inline void six() {
    cout << "Введите название файла для записи: ";
    // Ввод названия файла для записи
    string in_file = get_str();
    ofstream out(in_file);
    if (data_P.empty()) {
        cout << "Нет труб" << '\n';
    }
    if (data_KS.empty()) {
        cout << "Нет КС" << '\n';
    }
    // Сохранение данных в файл
    for (auto const& p : data_P) {
        if (!p.second.name.empty()) {
            data_P[p.first].save(out);
        }
    }
    for (auto const& k : data_KS) {
        if (!k.second.name.empty()) {
            data_KS[k.first].save(out);
        }
    }
}

inline void seven() {
    cout << "Введите название файла для загрузки: ";
    string read_file = get_str();
    ifstream read(read_file);
    // условие пустоты файла
    if (read.peek() == std::ifstream::traits_type::eof()) {  
        cout << "Файла не существует!\n";
    }
    else {
        string Name;
        while (getline(read, Name)) {
            if (Name == "pipe") {
                Pipe read_pipe;
                read_pipe.download(read);
                data_P.insert({ read_pipe.getid(), read_pipe });
                cout << "Данные трубы " << read_pipe.getid() << " выгружены из файла." << '\n';
            }
            if (Name == "comp") {
                CS read_ks;
                read_ks.download(read);
                data_KS.insert({ read_ks.getid(), read_ks });
                cout << "Данные КС " << read_ks.getid() << " выгружены из файла." << '\n';
            }
        }
    }
}