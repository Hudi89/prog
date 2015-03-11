#include <iostream>
#include <vector>
#include <fstream>
#include "tetelek.h"

using namespace std;

int main()
{
    vector <vector <int> > t;

    fstream be("asd.txt");
    try{
        int ind;
        be >> t;
        if(feltMaxKer (t, ind)){
            cout << "The " << (ind + 1) << ". knight won The Tournament." << endl;
        }else{
            cout << "Kill them all!" << endl;
        }
    }catch(Exceptions e){
        switch (e){
            case EMPTY_MATRIX: 
                cout << "The vector size is null!" <<endl;
                break;
            case NEGATIV_COUNT: 
                cout << "The size of the vector cant be negative!" <<endl;
                break;
            case NEGATIV_TOURNAMENT: 
                cout << "The number of tournament cant be negative!" <<endl;
                break;
            case NULL_MATCH: 
                cout << "At least 1 match needed!" <<endl;
                break;
            case TOO_MANY_SCORES: 
                cout << "The max score is 10!" <<endl;
                break;
            default: 
                cout << "Unknown problem!" <<endl;
                break;
        }
    }
    be.close();
    return 0;
}
