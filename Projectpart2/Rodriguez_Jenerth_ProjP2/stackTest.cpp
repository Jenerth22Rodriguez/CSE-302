#include "Stack.h"
#include <fstream>
#include <string>

int main()
{
    StackArray stack;

    ifstream infile("Covid_cases.csv");
    if (!infile.is_open())
    {
        cout << "Failed to open file" << endl;
        return 1;
    }
    string line;
    getline(infile, line);
    while (getline(infile, line))
    {
        Covid_cases case_data;
        int pos = line.find(",");
        case_data.date = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(",");
        case_data.afg = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        pos = line.find(",");
        case_data.alb = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        pos = line.find(",");
        case_data.alg = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        pos = line.find(",");
        case_data.ando = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        case_data.ang = stoi(line);
        stack.push(case_data);
    }

    Covid_cases top;
    
    cout << "Country//Region, Afghanistan, Albania, Algeria, Andorra, Angola" << endl;

    while (!stack.isEmpty())
    {
        top = stack.pop();
        
        if (top.date != "")
        {
            cout << top.date << " " << top.afg << " " << top.alb << " " << top.alg << " " << top.ando << " " << top.ang << endl;
        }
    }

    return 0;
}