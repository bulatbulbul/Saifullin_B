#include "Graph.h"
#include "Pipe.h"
#include "CS.h"
#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//���������, ���������� �� ��� ���������� ����� ��������� ��������� �����.
bool System::check_only(int x, int y) {
    int k = 0;
    for (auto& i : graphs) {
        if ((i.second.id_entrance == x and i.second.id_exit == y) or (i.second.id_entrance == y and i.second.id_exit == x)) {
            k++;
            cout << "��� ���������� ��� ����������" << endl;
        }
    }
    if (k == 0)
        return true;
    else return false;
}

// ���������, ����� �� ������� ������ � ��������� ���������������.
bool System::check_obj(int x) {
    int k = 0;
    for (auto& i : graphs) {
        if (i.second.id_entrance == x or i.second.id_exit == x or i.second.id_pipe == x) {
            k++;
            cout << "�� �� ������ ������� ������ � ���� " << endl;
        }
    }
    if (k == 0) return true;
    else return false;
}

//���������, ���������� �� ����� � ��������� ��������������� � �����.
bool System::checking(int x) {
    int n = 0;
    for (auto& i : graphs)
        if (i.second.id_pipe == x)
            n++;
    if (n == 0)
        return true;
    else return false;
}

//���������, ����� �� �������� ���������� � ��������� ���������������.
int System::check_graph(int x) {
    while (check_pipe(x) >= cs_group[x].getwork()) {
        cout << "������� ����� ���������� ��� ���� ��, �������� ������" << endl;
        x = correctnumber(0, INT_MAX);

    }
    return x;
}

//���������, ���������� �� ������� � ��������� ���������������.
int System::check_existing(int x) {
    while (cs_group.find(x) == cs_group.end()) {
        cout << "��� ����� ��" << endl;
        x = correctnumber(0, INT_MAX);
    }
    return x;
}

bool check_p_name(Pipe p, string name) {
    return (p.name.find(name) != string::npos);
}
bool check_p_status(Pipe p, bool status) {
    return (p.status == status);
}
bool check_cs_name(CS cs, string name) {
    return (cs.name.find(name) != string::npos);
}
bool check_unworking(CS cs, double p) {
    return (cs.get_unused() >= p);
}

// ��������� ����� ������� �� �������� ���������.
vector<int> System::search_cs() {
    int x;
    vector <int> id;
    cout << "������ �� : " <<
        "\n1.�� �����" <<
        "\n2.�� �������� ����������������� �����" << endl;
    x = correctnumber(1, 2);
    if (x == 1) {
        string name;
        cout << "������� �������� ��: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        id = search_cs_by_parametr(cs_group, check_cs_name, name);

    }
    else {
        double k;
        cout << "������� ������� ����������������� �����" << endl;
        k = correctnumber(0, 100);
        id = search_cs_by_parametr(cs_group, check_unworking, k);
    }
    return id;
}
//��������� ����� ���� �� �������� ���������.
vector<int> System::search_p() {
    vector<int> ids;
    int x;
    cout << "������ ����� : " <<
        "\n1.�� �����" <<
        "\n2.�� �������� � �������" << endl;
    x = correctnumber(1, 2);
    if (x == 1) {
        string name;
        cout << "������� �������� �����: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        ids = search_p_by_parametr(pipe_group, check_p_name, name);
    }
    else {
        bool k;
        cout << "������� ������� � �������( 0 - � �������, 1 - � ������): " << endl;
        k = correctnumber(0, 1);
        ids = search_p_by_parametr(pipe_group, check_p_status, k);
    }
    return ids;
}
// ������� ���������� � ������ � ��������.
void System::information() {
    for (auto& pipe : pipe_group) {
        cout << pipe.second << endl;
    }
    for (auto& cs : cs_group) {
        cout << cs.second << endl;
    }
}


void System::Graph::save_edge(ofstream& file) {
    file << id_entrance << endl << id_exit << endl << id_pipe << endl;
}
void System::Graph::load_edge(ifstream& file) {
    file >> id_entrance;
    file >> id_exit;
    file >> id_pipe;
}
//����������
void System::save() {
    string x;
    cout << "������� �������� ����� " << endl;
    cin >> x;
    ofstream file;
    file.open(x + ".txt");
    if (!file)
        cout << "������" << endl;
    else {
        file << pipe_group.size() << " " << cs_group.size() << " " << graphs.size() << endl;
        for (auto pipe : pipe_group) {
            pipe.second.save_pipe(file);
        }
        for (auto cs : cs_group)
            cs.second.save_cs(file);
        for (auto edge : graphs)
            edge.second.save_edge(file);
    }

}
void System::load() {
    string x;
    int len1, len2, len3;
    Pipe newP;
    CS newCS;
    Graph newGr;
    cout << "������� �������� �����  " << endl;
    cin >> x;
    ifstream file;
    file.open(x + ".txt");
    if (!file)
        cout << "��� ����� ������";
    else {
        Pipe::max_id = 0;
        CS::max_idd = 0;
        pipe_group.clear();
        cs_group.clear();
        file >> len1 >> len2 >> len3;
        for (int i = 0; i < len1; i++) {
            newP.load_pipe(file);
            pipe_group.insert({ newP.get_id(),newP });
            if (Pipe::max_id <= newP.get_id())
                Pipe::max_id = newP.get_id() + 1;

        }
        for (int i = 0; i < len2; i++) {
            newCS.load_cs(file);
            cs_group.insert({ newCS.get_id(),newCS });
            if (CS::max_idd <= newCS.get_id())
                CS::max_idd = newCS.get_id() + 1;

        }
        for (int i = 0; i < len3; i++) {
            newGr.load_edge(file);
            graphs.insert({ newGr.id_pipe,newGr });
        }
    }
}

void System::editcs() {
    vector <int> idcs;
    if (cs_group.size() != 0) {
        cout << "1. ������������� ���� �� �� ������\n"
            << "2. ������������� �������\n"
            << "3. ������� �������\n" << endl;
        int edit;
        int x;
        edit = correctnumber(1, 3);
        if (edit == 1) {
            int id;
            cout << cs_group;
            cout << "�������� ������������� ��" << endl;
            id = correctnumber(0, (int)cs_group.size());
            if (cs_group.find(id) != cs_group.end()) {
                cs_group[id].edit_cs();

            }
        }
        if (edit == 2) {
            unordered_set <int> idw;
            cout << "������������� ��: \n"
                << "1. ������� \n"
                << "2. ID \n" << endl;
            int n;
            n = correctnumber(1, 2);
            if (n == 2) {
                cout << cs_group;
                cout << "�������� ����� ������������� ��" << endl;
                int y;
                y = correctnumber(1, (int)cs_group.size());
                cout << "�������� ID �������" << endl;
                for (int i = 0; idw.size() < y; i++) {
                    cin >> x;
                    if (cs_group.find(x) != cs_group.end())
                        idw.insert(x);


                    else {

                        cout << "��� ����� ��" << endl;
                    }
                }
                for (auto& id : idw)

                    cs_group[id].edit_cs();
            }

            else {
                auto idp = search_cs();
                if (idp.size() != 0) {
                    for (auto& i : idp)
                        cs_group[i].edit_cs();
                }

                else {
                    cout << "��� ����� ��";

                }

            }
        }
        if (edit == 3) {
            cout << "1. ID ����� ��, ������� �� ������ �������\n "
                << "2. ������� ��������� ��\n " << endl;
            int d;
            d = correctnumber(1, 2);
            if (d == 1) {
                cout << cs_group;
                cout << "������� ID ��, ������� �� ������ �������" << endl;
                int n;
                n = correctnumber(0, CS::max_idd - 1);
                while (cs_group.find(n) == cs_group.end()) {
                    cout << "��� ����� ��" << endl;
                    n = correctnumber(0, CS::max_idd - 1);
                }
                if (check_obj(n))
                    cs_group.erase(cs_group.find(n));

            }
            else {
                unordered_set <int> idd;
                cout << "1. ������� �� �������\n "
                    << "2. ������� �� ID\n " << endl;
                int n;
                n = correctnumber(1, 2);
                if (n == 2) {
                    cout << cs_group;
                    cout << "������� ����� ��, ������� �� ������ �������" << endl;
                    int y;
                    int x;
                    y = correctnumber(1, (int)cs_group.size());
                    cout << "������� ID �������" << endl;
                    for (int i = 0; idd.size() < y; i++) {
                        x = correctnumber(0, CS::max_idd);
                        if (cs_group.find(x) != cs_group.end())
                            idd.insert(x);
                        else cout << "��� ����� ��";
                    }
                    for (auto& i : idd) {
                        if (check_obj(i))
                            cs_group.erase(cs_group.find(i));
                    }
                }
                else {
                    auto idp = search_cs();
                    if (idp.size() != 0) {
                        for (auto& i : idp) {
                            if (check_obj(i))
                                cs_group.erase(cs_group.find(i));
                        }
                    }
                    else {
                        cout << "��� ����� ��" << endl;


                    }
                }

            }
        }
    }
    else
        cout << "��� �� ��� ��������������" << endl;
}
void System::edit()
{
    if (pipe_group.size() != 0) {
        cout << "1. ������������� ���� ����� �� ������\n"
            << "2. ������������� �����\n"
            << "3. ������� �����\n" << endl;;
        int edit = correctnumber(1, 3);
        if (edit == 1) {
            cout << "�������� ����� ��� ��������������" << endl;
            cout << pipe_group;
            int id = correctnumber(0, (int)pipe_group.size());
            if (pipe_group.find(id) != pipe_group.end()) {
                pipe_group[id].edit_Pipe();

            }
            else
                cout << "��� ����� ����";
        }
        if (edit == 2) {
            cout << "������������� ��: \n"
                << "1. ������� \n"
                << "2. ID \n" << endl;
            int x = correctnumber(1, 2);
            if (x == 1) {
                auto idp = search_p();
                if (idp.size() != 0) {
                    cout << "������� ����� ���������(0 - � �������, 1 - � ������" << endl;
                    bool s;
                    s = correctnumber(0, 1);
                    for (auto& i : idp)
                        pipe_group[i].status = s;
                }

                else {
                    cout << "��� ����� ����";

                }
            }


            if (x == 2) {
                unordered_set <int> ids;
                cout << pipe_group;
                cout << "������� ID ����, ������� �� ������ �������������" << endl;
                int n;
                int id;
                n = correctnumber(1, (int)pipe_group.size());
                cout << "������� ID ���� " << endl;
                for (int i = 0; ids.size() < n; i++) {
                    id = correctnumber(0, Pipe::max_id - 1);
                    if (pipe_group.find(id) != pipe_group.end()) {
                        if (pipe_group.find(id) != pipe_group.end())
                            ids.insert(id);
                    }
                    else
                    {
                        cout << "��� ����� ����" << endl;;
                    }
                }
                cout << "������� ����� ���������(0 - � ��������, 1 - � ������" << endl;
                bool s;
                s = correctnumber(0, 1);
                for (auto& i : ids) {
                    pipe_group[i].status = s;
                }
            }
        }
        if (edit == 3) {
            cout << "1. ID ����� �����, ������� �� ������ ������� \n"
                << "1. ������� ��������� ���� \n" << endl;
            int d;
            d = correctnumber(1, 2);
            if (d == 1) {
                cout << pipe_group;
                cout << "������� ID �����, ������� �� ������ �������������" << endl;
                int n;
                n = correctnumber(0, Pipe::max_id - 1);
                while (pipe_group.find(n) == pipe_group.end()) {
                    cout << "��� ����� ����" << endl;
                    n = correctnumber(0, Pipe::max_id - 1);
                }
                if (check_obj(n))
                    pipe_group.erase(pipe_group.find(n));
            }

            else {
                unordered_set <int> ids;
                cout << "1. ������� �� �������\n "
                    << "2. ������� �� ID\n " << endl;
                int action = correctnumber(1, 2);
                if (action == 2) {
                    cout << pipe_group;
                    cout << "������� �������� �����, ������� �� ������ �������" << endl;;
                    int n = correctnumber(1, (int)pipe_group.size());
                    cout << "������� ID ����" << endl;

                    while (ids.size() < n)
                    {
                        int x = correctnumber(0, Pipe::max_id - 1);
                        if (pipe_group.find(x) != pipe_group.end())
                            ids.insert(x);
                        else
                            cout << "��� ����� ����" << endl;
                    }

                    for (auto& id : ids) {
                        if (check_obj(id))
                            pipe_group.erase(pipe_group.find(id));
                    }

                }

                else {
                    auto idp = search_p();
                    if (idp.size() != 0) {
                        for (auto& i : idp) {
                            if (check_obj(i))
                                pipe_group.erase(pipe_group.find(i));
                        }
                        cout << "����� �������";
                    }
                    else {
                        cout << "��� ����� ����";

                    }

                }
            }

        }
    }



    else
        cout << "��� ���� ��� ��������������" << endl;
}

//��������� ���������� ����������.
int System::check_pipe(int x) {
    int k = 0;
    if (graphs.size() != 0) {
        for (auto& i : graphs) {
            if ((i.second.id_entrance == x) or (i.second.id_exit == x))
                k++;
        }
    }
    return k;
}

//���������� ������������� ����� ��� ���������� ��������.
int System::edge(int x) {
    int k = -1;
    for (auto& i : pipe_group) {
        if (i.second.get_dia() == x) {
            if (checking(i.first)) {
                k = i.first;
                return k;
            }
        }
    }
    return k;
}

// ������� ������� ��������� ��� �����.
void System::adjacencytable(unordered_map<int, System::Graph>& p) {
    table.clear();
    for (auto& i : p)
        table[i.second.id_entrance].push_back(i.second);
}
//��������� �������������� ���������� ��� �����.
void System::topsort(int x, unordered_map<int, int>& visited, vector<int>& vertexes) {
    visited[x] = 1;
    for (auto& i : table[x]) {
        if (visited[i.id_exit] == 0) {
            topsort(i.id_exit, visited, vertexes);
            if (vertexes.empty())
                return;
        }
        else if (visited[i.id_exit] == 1) {
            vertexes.clear();
            return;
        }
    }
    visited[x] = 2;
    vertexes.push_back(x);
}

//������� ��������������� ������� �����
void System::sorted() {
    vector <int> vertexes;
    unordered_map <int, int> visited;
    for (auto& i : table)
        visited.insert({ i.first,0 });
    for (auto& i : table) {
        if (visited[i.first] == 0)
            topsort(i.first, visited, vertexes);

    }
    while (!vertexes.empty()) {
        cout << vertexes.back() << " ";
        vertexes.pop_back();
    }
    cout << endl;
}

//�������� ���������� �����.
void System::sorting() {
    cout << "����������� ����" << endl;
    adjacencytable(graphs);
    sorted();
}

//(��� ������ � �����): ������� ����������������� �������
ostream& operator<<(ostream& out, unordered_set<int> s) {
    cout << "������������������ �������: ";
    for (auto& i : s)
        cout << i << " ";
    cout << endl;
    return out;
}

//(��� ����� �� ������) : ��������� ������� ����� ���������� ����� ���������
istream& operator>> (istream& in, System& s) {
    System::Graph gr;
    cout << s.cs_group;
    cout << "�������� ID �� �����" << endl;
    gr.id_entrance = correctnumber(0, INT_MAX);
    gr.id_entrance = s.check_existing(gr.id_entrance);
    gr.id_entrance = s.check_graph(gr.id_entrance);
    cout << s.cs_group;
    cout << "�������� ID �� ������" << endl;
    gr.id_exit = correctnumber(0, INT_MAX);
    while (gr.id_exit == gr.id_entrance) {
        cout << "�� �� ������ ��������� �� � ������ �����" << endl;
        gr.id_exit = correctnumber(0, INT_MAX);
    }
    gr.id_exit = s.check_existing(gr.id_exit);
    gr.id_exit = s.check_graph(gr.id_exit);
    if (s.check_only(gr.id_entrance, gr.id_exit)) {
        cout << "�������� ������� ����� ��� ����������: 500, 700, 1000 ��� 1400" << endl;
        double dia_pipe = correctdiametr<int>();
        int k = s.edge(dia_pipe);
        while (s.pipe_group.find(k) == s.pipe_group.end()) {
            cout << "��� ����� ����, ������� ������(1) ��� �������� ����� �����(2)" << endl;
            int choise = correctnumber(1, 2);
            if (choise == 2) {
                Pipe p;
                cin >> p;
                s.pipe_group.insert({ p.get_id(), p });
            }
            cout << "�������� ������� ����� ��� ����������: 500, 700, 1000 or 1400" << endl;
            dia_pipe = correctdiametr<int>();
            k = s.edge(dia_pipe);
        }
        gr.id_pipe = k;

        s.graphs.insert({ gr.id_pipe,gr });
    }
    else {
        return in;
    }
    return in;

}