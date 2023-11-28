#include "CS.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "header.h"
#include "Graph.h"
using namespace std;
System t;
int CS::max_idd = 0;
istream& operator>> (istream& in, CS& cs)
{
    cout << "\n������ ��: " << cs.idcs;
    cout << "\n������� �������� �� ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, cs.name);
    cout << "\n������� ���������� ����� �� ";
    cs.workshop = correctnumber(0, INT_MAX);
    cout << "\n������� ���������� ����� � ������ ";
    cs.working_workshop = correctnumber(0, cs.workshop);
    cout << "\n������� �������������(0 - 100) ";
    cs.effectiveness = correctnumber(0, 100);
    return in;
}
ostream& operator<< (ostream& out, CS& cs) {
    out << "������ ��: " << cs.idcs << endl;
    out << "��: " << cs.name << endl;
    out << "���������� �����: " << cs.workshop << endl;
    out << "���������� ����� � ������: " << cs.working_workshop << endl;
    out << "�������������: " << cs.effectiveness << endl;
    return out;
}
void CS::edit_cs() {
    cout << "����: " << workshop << endl;
    cout << "���������� ����: " << working_workshop << endl;
    cout << "������� ����� ���������� ���������� �����" << endl;
    working_workshop = correctnumber(0, workshop);
}
void CS::save_cs(ofstream& file) {
    if (file.is_open()) {
        file << idcs << endl << name << endl
            << workshop << endl << working_workshop << endl << effectiveness << endl;
    }
}
void CS::load_cs(ifstream& file) {
    if (file.is_open()) {
        file >> idcs;
        getline(file, name);
        getline(file, name);
        file >> workshop;
        file >> working_workshop;
        file >> effectiveness;
    }
}