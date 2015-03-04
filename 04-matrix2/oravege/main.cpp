#include <fstream>
#include <iostream>
#include <vector>

#include "tetelek.h"

using namespace std;

int main()
{
   /* Dolgozo d = FERI;
    if(d == FERI){


    }*/

    vector <vector <int> > t;
    fstream fin("asd.txt");

    try{
        fin >> t;
        int s = max_sor ( t );
        cout << s << endl;
    }catch(Exceptions e){
        switch(e){
            case EMPTY_MATRIX:
                cout << "Ures a matrix" << endl;
                break;
            case NEGATIVE_COUNT:
                cout << "Negativ........." << endl;
                break;
            default:
                throw e;
        }
    }

    fin.close();
    return 0;
}
