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
    cout << "1. �������� �����" << '\n';
    cout << "2. �������� ��" << '\n';
    cout << "3. �������� ��������" << '\n';
    cout << "4. ������������� �����" << '\n';
    cout << "5. ������������� ��" << '\n';
    cout << "6. ���������" << '\n';
    cout << "7. ���������" << '\n';
    cout << "0. �����" << '\n' << '\n';
}



template <typename T>
T get_correct_value(T min, T max) {
    T value;
    cin >> value;
    cerr << value << '\n';
    while (cin.fail() || cin.peek() != '\n' || value < min || value > max) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "������ ������� �������, ���������� ��� ���: ";
        cin >> value;
        cerr << value << '\n';
    }
    return value;
}

// ��������� ������� ��� ��������� ������ ��������������� �� �������
template <typename T>
vector<int> get_ids(const unordered_map<int, T>& dict)
{
    unordered_set<int> ids;
    cout << "������� id; ���� ���������, �� -1" << '\n';
    while (1) {
        int id = get_correct_value(-1, INT_MAX);
        if (id == -1) {
            break;
        }
        else if (dict.contains(id)) {
            ids.insert(id);
        }
        else {
            cout << "��� ������� � ���� id" << '\n';;
        }
        if (ids.size() == dict.size()) {
            break;
        }
    }
    return vector<int>(ids.begin(), ids.end());
}


template<typename T1, typename T2>
using filter = bool(*)(const T1& dict, T2 param);

// �������-������ ��� ��������� �� �����
template<typename T>
bool filter_by_name(const T& dict, string name) {
    return dict.name.find(name) != string::npos;
}

// ��������� ������� ��� ������ ��������� �� ��������� �������
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

// ��������� ������� ��� ��������� ������ � �������
template <typename M>
void view_data(unordered_map<int, M>& dict) {
    for (auto const& pair : dict) {
        M value = pair.second;
        value.view();
    }
}

// ��������� ������� ��� ��������� ������ �� ����������� ��������������
template <typename F>
void view_id(unordered_map<int, F>& dict, int id) {
    for (auto const& pair : dict) {
        if (id == pair.first) {
            F value = pair.second;
            value.view();
        }
    }
}

// ��������� ������� ��� ���������� ������� � �������
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

// �������-������ ��� ��������� �� ������� ������������ �����
inline bool filter_by_status(const Pipe& dict, bool status) {
    return dict.maintenance == status;
}

// �������-������ ��� ��������� �� �������� ����������������� ����� ��
inline bool filter_by_non_working(const CS& dict, int non_working) {
    return dict.num_department - dict.work_department == dict.num_department * non_working / 100;
}

inline void thirth() {
    cout << "1 - ���������� ��� �������, 0 - ������������� ����������: ";
    if (bool choice1 = get_correct_value(0, 1)) {
        view_data(data_P);
        view_data(data_KS);
    }
    else {
        cout << "1 - �����, 0 - ��: ";
        if (bool choice2 = get_correct_value(0, 1)) {
            cout << "1 - �� ��������, 0 - �� �������: ";
            if (bool choice3 = get_correct_value(0, 1)) {
                cout << "������� ��������: ";
                // ���� �������� ��� ����������
                string name = get_str();
                // ����� � �������� ������ ���� �� ������� �� ��������
                for (int i : find_by_filter(data_P, filter_by_name, name)) {
                    view_id(data_P, i);
                }
            }
            else {
                cout << "������� ������: ";
                // ���� ������� ��� ����������
                bool maintenance = get_correct_value(0, 1);
                // ����� � �������� ������ ���� �� ������� �� ������� ������������
                for (int i : find_by_filter(data_P, filter_by_status, maintenance)) {
                    view_id(data_P, i);
                }
            }
        }
        else {
            cout << "1 - �� ��������, 0 - �� �������� ����������������� �����: ";
            if (bool choice4 = get_correct_value(0, 1)) {
                cout << "������� ��������: ";
                // ���� �������� ��� ����������
                string name = get_str();
                // ����� � �������� ������ �� �� ������� �� ��������
                for (int i : find_by_filter(data_KS, filter_by_name, name)) {
                    view_id(data_KS, i);
                }
            }
            else {
                cout << "������� �������: ";
                // ���� �������� ��� ����������
                int non_working = get_correct_value(0, 100);
                // ����� � �������� ������ �� �� ������� �� �������� ����������������� �����
                for (int i : find_by_filter(data_KS, filter_by_non_working, non_working)) {
                    view_id(data_KS, i);
                }
            }
        }
    }
}

inline void fourth() {
    if (!data_P.empty()) {
        cout << "1 - ��������, 0 - ��������� ����: ";
        bool choice1 = get_correct_value(0, 1);
        vector<int> ids;
        cout << "������� �������� �����: ";
        // ���� �������� ����� ��� ����������
        string name = get_str();
        unordered_set<int> set = find_by_filter(data_P, filter_by_name, name);
        if (set.size() == 0) {
            cout << "������ ����� ���";
        }
        else {
            if (choice1) {
                cout << "1 - ������� ��� �����, 0 - �� ��� �����: ";
                bool choice2 = get_correct_value(0, 1);
                if (!choice2) {
                    cout << "������ �������� �� ������� ������ id" << '\n';
                    for (const auto& id : set) {
                        cout << id << '\n';
                    }
                    // ��������� ��������� id ��� ��������
                    ids = get_ids(data_P);
                    for (int id : ids) {
                        data_P.erase(id);
                    }
                }
                else {
                    // �������� ���� ���� � ������ ���������
                    for (int id : set) {
                        data_P.erase(id);
                    }
                }
            }
            else {
                cout << "1 - �������� ��� �����, 0 - �� ��� �����: ";
                bool choice3 = get_correct_value(0, 1);
                if (!choice3) {
                    cout << "������ �������� �� ������� ������ id" << '\n';
                    for (const auto& id : set) {
                        cout << id << '\n';
                    }
                    // ��������� ��������� id ��� ���������
                    ids = get_ids(data_P);
                    for (int id : ids) {
                        data_P[id].change();
                    }
                }
                else {
                    cout << "� �������?(0 - ��� , 1 - ��): ";
                    // ��������� ������� ������� ��� ��������� ����
                    for (int id : set) {
                        data_P[id].change();
                    }
                }
            }
        }
    }
    else {
        cout << "��� ���� ��� ���������" << '\n';
    }
}


inline void fif() {
    if (!data_KS.empty()) {
        cout << "1 - ��������, 0 - ��������� ��: ";
        bool choice = get_correct_value(0, 1);
        cout << "������� �������� ��: ";
        // ���� �������� �� ��� ����������
        string name = get_str();
        unordered_set<int> set = find_by_filter(data_KS, filter_by_name, name);
        if (set.size() == 0) {
            cout << "������ ����� ���" << "\n";
        }
        else {
            for (int id : set) {
                if (choice) {
                    // �������� ��������� ��
                    data_KS.erase(id);
                }
                else {
                    // ��������� ��������� ��
                    data_KS[id].change();
                }
            }
        }
    }
    else {
        cout << "��� �� ��� ���������" << '\n';
    }
}

inline void six() {
    cout << "������� �������� ����� ��� ������: ";
    // ���� �������� ����� ��� ������
    string in_file = get_str();
    ofstream out(in_file);
    if (data_P.empty()) {
        cout << "��� ����" << '\n';
    }
    if (data_KS.empty()) {
        cout << "��� ��" << '\n';
    }
    // ���������� ������ � ����
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
    cout << "������� �������� ����� ��� ��������: ";
    string read_file = get_str();
    ifstream read(read_file);
    // ������� ������� �����
    if (read.peek() == std::ifstream::traits_type::eof()) {  
        cout << "����� �� ����������!\n";
    }
    else {
        string Name;
        while (getline(read, Name)) {
            if (Name == "pipe") {
                Pipe read_pipe;
                read_pipe.download(read);
                data_P.insert({ read_pipe.getid(), read_pipe });
                cout << "������ ����� " << read_pipe.getid() << " ��������� �� �����." << '\n';
            }
            if (Name == "comp") {
                CS read_ks;
                read_ks.download(read);
                data_KS.insert({ read_ks.getid(), read_ks });
                cout << "������ �� " << read_ks.getid() << " ��������� �� �����." << '\n';
            }
        }
    }
}