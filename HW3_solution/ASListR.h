#include <string>
#include <iostream>

using namespace std;

struct Covid_cases
{
  string date;
  int afg;
  int alb;
  int alg;
  int ando;
  int ang;
};

class ASListR // Most of these declarations will match those of AUList or LLUList, as the general interface and functionality has not changed.
{
public:
  ASListR(int); // Constructor with parameter for max array size

  ~ASListR(); // Destructor

  void PutItem(Covid_cases); // Adds the item to the list.

  void PrintList(); // Print all elements of the list in a readable format.

private:
  int length;
  Covid_cases*ListItems;
  int MAXSIZE;
  int currentPos;
};
