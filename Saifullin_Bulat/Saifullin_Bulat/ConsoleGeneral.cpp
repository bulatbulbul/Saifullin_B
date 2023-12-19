#include "CS.h"
#include "Pipe.h"
#include "header.h"
#include "Graph.h"
#include <format>
#include <chrono>
#include <sstream>

using namespace std;
using namespace chrono;
int main()
{
    setlocale(LC_ALL, "ru");



    redirect_output_wrapper cerr_out(cerr);
    string time = format("{:%d_%m_%Y_%H_%M_%OS}", system_clock::now() + hours(3));
    ofstream logfile("Logs/log_" + time + ".txt");
    if (logfile)
        cerr_out.redirect(logfile);

    System network;
    int option = -1;
    while (option) {
        cout << "\n1. Добавить трубу\n" <<
            "2. Добавить КС\n" <<
            "3. Просмотр всех объектов\n" <<
            "4. Редактировать трубу\n" <<
            "5. Редактировать КС\n" <<
            "6. Сохранить\n" <<
            "7. Загрузить\n" <<
            "8. Найти трубу\n" <<
            "9. Найти КС\n" <<
            "10. Создать газотранспортную сеть\n" <<
            "11. Сортировка\n" <<
            "12. Расчет кратчайшего пути между заданными КС\n" <<
            "0. Выход\n" <<
            "Введите ваш выбор: ";

        switch (correctnumber(0, 12)) {
        case 1: {
            Pipe p;
            cin >> p;
            network.pipe_group.insert({ p.get_id(), p });
            break;
        }
        case 2: {
            CS cs;
            cin >> cs;
            network.cs_group.insert({ cs.get_id(), cs });
            break;
        }
        case 3: {
            network.information();
            break;
        }
        case 4: {
            network.edit();
            break;
        }
        case 5: {
            network.editcs();
            break;
        }
        case 6: {
            network.save();
            break;
        }
        case 7: {
            network.load();
            break;
        }
        case 8: {
            if (network.pipe_group.size() != 0) {
                auto x = network.search_p();
                if (x.size() != 0) {
                    for (auto& i : x)
                        cout << network.pipe_group[i] << endl;
                }
                else
                    cout << "Нет такой трубы" << endl;
            }
            else
                cout << "Труба не найдена" << endl;
            break;
        }
        case 9: {
            if (network.cs_group.size() != 0) {
                auto x = network.search_cs();
                if (x.size() != 0) {
                    for (auto& i : x)
                        cout << network.cs_group[i] << endl;
                }
                else
                    cout << "Нет такой КС";
            }
            else
                cout << "КС не найдена" << endl;
            break;
        }
        case 10: {
            cout << "1.Соеднить 2.Разъединить" << endl;
            int choise = correctnumber(1, 2);
            if (choise == 1) {
                if ((network.cs_group.size() < 2) or (network.pipe_group.size() < 1))
                    cout << "Недостаточно объектов, чтобы создать сеть" << endl;
                else
                    cin >> network;
            }
            else {
                if (network.graphs.size() != 0) {
                    cout << "Введите КС входа" << endl;
                    int x = correctnumber(0, INT_MAX);
                    x = network.check_existing(x);
                    cout << "Введите КС выхода" << endl;
                    int y = correctnumber(0, INT_MAX);
                    y = network.check_existing(y);
                    while (x == y) {
                        cout << "Вы не можете разъединить одну и ту же КС" << endl;
                        y = correctnumber(0, INT_MAX);
                        y = network.check_existing(y);
                    }
                    auto i = network.graphs.cbegin();
                    while (i != network.graphs.cend()) {
                        if (((*i).second.id_entrance == x) and ((*i).second.id_exit == y)) {
                            network.graphs.erase(i);
                            break;
                        }
                        i++;
                    }
                }

                else
                    cout << "Нет доступных сетей" << endl;

            }
            for (auto& [i, j] : network.graphs)
                cout << i << ") " << j.id_entrance << " " << j.id_exit << " " << j.id_pipe << endl;
            break;
        }
        case 11: {
            network.sorting();
            break;
        }

        case 12: {
            network.adjacencytable(network.graphs); // Populate the adjacency table
            int start, end;
            cout << "Введите начальную КС: ";
            start = correctnumber(0, INT_MAX);
            cout << "Введите конечную КС: ";
            end = correctnumber(0, INT_MAX);
            network.findShortestPath(start, end);
            break;
        }
        }
    }
}