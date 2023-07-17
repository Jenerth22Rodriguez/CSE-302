#include <iostream>
#include "QueType.h"
#include "StackType.h"
using namespace std;

string decode(string exp, string code)
{
    string finalString;
    StackType<char> charStack;
    QueType<char> charQueue;
    for (int i = 0; i < exp.length(); i++)
    {
	
	size_t found=code.find(exp[i]);
	
        if (found !=string::npos)
        {
            charStack.Push(exp[i]);
        }
        else
        {
            charQueue.Enqueue(exp[i]);
        }
    }
    while (!charQueue.IsEmpty())
    {
        char find;
        charQueue.Dequeue(find);
        finalString += find;
    }
    while (!charStack.IsEmpty())
    {
        char find_Stack;
        find_Stack = charStack.Pop();
        finalString += find_Stack;
    }
    return finalString;
}
