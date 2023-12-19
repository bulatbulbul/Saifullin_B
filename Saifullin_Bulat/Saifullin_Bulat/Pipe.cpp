#include "Pipe.h"
#include "header.h"
#include "Graph.h"
using namespace std;
System s;
string status_check(bool x)
{
    if (x == true)
        return ("����� � ������");
    else
        return ("����� � �������");
}
int Pipe::max_id = 0;
istream& operator>> (istream& in, Pipe& p)
{
    cout << "\n ������ �����: " << p.idp;
    cout << "\n������� �������� �����: ";
    INPUT_LINE(cin, p.name);
    cout << "\n������� ����� �����:  ";
    p.length = correctnumber(0.0, DBL_MAX);
    cout << "\n������� ������� �����(500, 700, 1000 ��� 1400): ";
    p.diameter = correctdiametr<int>();
    cout << "\n������� ��������� �����(0 - � �������, 1 - � ������): ";
    p.status = correctnumber(0, 1);
    cout << status_check(p.status) << endl;
    return in;
}
ostream& operator<< (ostream& out, Pipe& p) {
    out << "\n������ �����: " << p.idp << endl;
    out << "�����: " << p.name << endl;
    out << "�����: " << p.length << endl;
    out << "�������: " << p.diameter << endl;
    out << "���������(0 - � �������, 1 - � ������): " << status_check(p.status) << endl;

    return out;
}

double System::getPipeLength(int pipeId) const
{
    auto it = pipe_group.find(pipeId);

    if (it != pipe_group.end())
    {
        return it->second.getPipeLength();
    }
    else
    {
        return 0.0;
    }
}
void Pipe::edit_Pipe() {
    cout << "��������� �����: " << status_check(status) << endl;
    cout << "�������� ��������� ����� (0 - � �������, 1 - � ������)" << endl;
    status = correctnumber(0, 1);
    cout << status_check(status) << endl;;
}
void Pipe::save_pipe(ofstream& file) {
    if (file.is_open()) {
        file << idp << endl;
        file << name << endl;
        file << length << endl;
        file << diameter << endl;
        file << status << endl;

    }
}
void Pipe::load_pipe(ifstream& file) {
    if (file.is_open()) {
        file >> idp;
        getline(file, name);
        getline(file, name);
        file >> length;
        file >> diameter;
        file >> status;
    }
}
bool check_p_name(Pipe& p, string name) {
    return (p.name.find(name) != string::npos);
}
bool check_p_status(Pipe& p, bool status) {
    return (p.status == status);
}