#include "ASListR.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

ASListR csvtoASListR(string csvfile) { //convert a csv file to a list structure
    ASListR retCCList(205); //Make sure the array has sufficient size for our data
	ifstream ReadFile(csvfile); //open the csv file for reading
    string line, curvalue;
	getline(ReadFile, line); //throw away the first line (column names)
    while (getline(ReadFile,line)) {        
        stringstream ss(line); //turn the line into a string-stream
        int fielditer=0;
        Covid_cases newrec;
		while(getline(ss, curvalue, ',')){ //Separate each variable per sample from the comma separator
            switch (fielditer) { //We need to explicitly convert values to the appropriate type (stoi=integer, stod=double)
            	case 0: newrec.date=curvalue; break;
            	case 1: newrec.afg=stoi(curvalue); break;
            	case 2: newrec.alb=stoi(curvalue); break;
                case 3: newrec.alg = stoi(curvalue); break;
                case 4: newrec.ando = stoi(curvalue); break;
                case 5: newrec.ang = stoi(curvalue); break;
            }
            fielditer++;
        }
        retCCList.PutItem(newrec);
    }
    return retCCList;
}

int main(int argc, char** argv) {
	ASListR CCFraudData=csvtoASListR("Covid_cases.csv");
	CCFraudData.PrintList(); //Print the data to make sure they are correct order (in this case, in decreasing order by cost)
}
    
