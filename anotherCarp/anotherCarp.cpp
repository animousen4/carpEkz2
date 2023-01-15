// anotherCarp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <strHelp.h>
#include "TPrizes.h"
using namespace std;
int main()
{   

    setlocale(LC_ALL, "rus");
    TPrizes tp;
    
    ifstream namePrizesFile("NamePrizes.txt");

    namePrizesFile >> tp;

    namePrizesFile.close();

    tp.ReadFirm();

    tp.fillPrizesInfo();

    tp.sortPrizesInfo();

    ofstream sortPrizesFile("SortPrizes.txt");

    sortPrizesFile << tp;

    sortPrizesFile.close();


    //cout << tp.firms[1].firmRaschet;

    
}
