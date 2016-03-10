#include <iostream>
#include <vector>
#include <fstream>

#include "asd4_1.h"

using namespace std;


//Sárkányok
// n db. sárkány
// m db. lovag
// adat: hány pecig bírja lovag (float)
//
//SUM/size()-MAX
//
// Átlagosan egy lovag maximálisan
// meddig bírja a sárkányok ellen?

int main()
{
    ifstream f("input.txt");
    vector<vector<float> > m;
    try{
        f >> m;
        cout << m;
        cout << feladat(m) << endl;
    }catch(Exception e){
        switch(e){
        case EMPTY_VECTOR:
            cout << "Ures a vektor!" << endl;
            break;
        case WRONG_INPUT_FORMAT:
            cout << "Rossz input!" << endl;
            break;
        case NEGATIVE_COUNT:
            cout << "Negativ szamossag!" <<endl;
            break;
        default:
        //    cout << "Unknown Error!" << endl;
            throw e;
        }
    }

    return 0;
}
