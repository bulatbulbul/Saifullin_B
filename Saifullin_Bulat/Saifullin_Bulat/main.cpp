#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <format>
#include <chrono> 
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#include "Functions.h"
#include "Pipe.h"
#include "CS.h"
#include "logging.h"


using namespace std;
using namespace chrono;


unordered_map<int, Pipe> data_P;
unordered_map<int, CS> data_KS;

int main()
{

    redirect_output_wrapper cerr_out(cerr);

    string time = format("{:%d-%m-%Y %H_%M_%OS}", system_clock::now());

    ofstream logfile("log" + time + ".txt");
    if (logfile) {
        cerr_out.redirect(logfile);
    }

    while (true) {
        setlocale(LC_ALL, "Rus");
        menu(); 
        cout << "¬ведите ваш выбор: ";
        cin.clear();
        int choice = get_correct_value(0, 7);
        switch (choice) {
        case 1:
        {
            add_to_dict(data_P);
            break;
        }
        case 2:
        {
            add_to_dict(data_KS);
            break;
        }
        case 3:
        {
            thirth();
            break;
        }
        case 4:
        {
            fourth();
            break;
        }
        case 5:
        {
            fif();
            break;
        }
        case 6:
        {
            six();
            break;
        }
        case 7:
        {
            seven();
            break;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            cout << "¬ведите числа от 0 до 7\n";
            break;
        }

        }
    }
    return 0;
}