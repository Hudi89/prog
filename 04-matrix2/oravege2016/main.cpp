#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "common.h"
#include "gt.h"

using namespace std;


int main()
{
    vector<vector<string> > m;
    ifstream f("input2.txt");
    //matrixBeolvas(f,m);
    f >> m;
    //matrixKiir(cout,m);
    cout << m;
    int ind;
    try {
        if(ls(m,ind)){
            cout << "Talalt:" << (ind+1) << endl;
        }else{
            cout << "Hulyevagy!" << endl;
        }
    }catch(Exception e){
        switch(e){
        case VECTOR_IS_EMPTY:
            cout << "Vector empty!" << endl;
            break;
        default:
            throw e;
        }
    }
    return 0;
}
