#include <iostream>
using namespace std;

const int MAX_SIZE = 800;

struct Covid_cases
{
    string date;
    int afg;
    int alb;
    int alg;
    int ando;
    int ang;
};

class StackArray
{
private:
    Covid_cases arr[MAX_SIZE];
    int top;

public:
    StackArray()
    {
        top = -1;
    }

    void push(Covid_cases val)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        arr[++top] = val;
    }

    Covid_cases pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }

        return arr[top--];
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};