#include <iostream>
#include <vector>
#include <fstream>
#include "Complex.h"

using namespace std;

Complex sum(vector<Complex> &v){
    Complex s;
    s = 0;
    for(int a=0;a<v.size();a++){
        s += v[a];
    }
    return s;
}

int main()
{
    int n;
    ifstream f("asd.txt");
    f >> n;
    vector<Complex> v;
    v.resize(n);
    for(int a=0;a<v.size();a++){
        f >> v[a];
    }
    cout << sum(v);
    return 0;
}
