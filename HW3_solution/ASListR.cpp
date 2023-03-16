// Implementation file for AUList
#include <iostream>
#include "ASListR.h"

ASListR::ASListR(int arraysize) {
  length = 0; //a newly constructed list has 0 elements; we don't care about the contents of the array.
  MAXSIZE = arraysize; //default array size
  ListItems=new Covid_cases[MAXSIZE];
}

ASListR::~ASListR() {
  delete(ListItems);
}

void ASListR::PutItem(Covid_cases pitem) {
    int aloc=0;
    bool moreToSearch = aloc < length;
    while (moreToSearch) {
        if (pitem.date>ListItems[aloc].date)
            moreToSearch = false;
        else {		
            aloc++;
            moreToSearch = aloc < length;
        }
    }
    for (int i = length; i > aloc; i--)
        ListItems[i] = ListItems[i-1];
    ListItems[aloc] = pitem;
    length++;
}

void ASListR::PrintList() {
  std::cout<<"Country//Region, Afghanistan, Albania, Algeria, Andorra, Angola"<<std::endl;
  for (int loc=0; loc<length; loc++) {
  	Covid_cases curitem=ListItems[loc];
	std::cout<<curitem.date<<", "<<curitem.afg<<", "<<curitem.alb<<", "<<curitem.alg<<", "<<curitem.ando<<", "<<curitem.ang<<std::endl;
  }
}

