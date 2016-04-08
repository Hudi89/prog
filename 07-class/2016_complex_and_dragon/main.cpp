#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

#include "Complex.h"
#include "Dragon.h"

using namespace std;

template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &v){
    int n;
    in >> n;
    v.resize(n);
    for(int a=0;a<n;a++){
        in >> v[a];
    }
    return in;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &v2){
    out <<v2.size() << std::endl;
    for(int a=0;a<v2.size();a++){
        out << v2[a] << std::endl;
    }
    return out;
}


template<class T>
T sum(const vector<T> &v){
    T s = 0;
    for(int a=0;a<v.size();a++){
        s += v[a];
    }
    return s;
}

template<class T>
int maxFind(const vector<T> &v){
    int ind = 0;
    T max = v[0];
    for(int a=1;a<v.size();a++){
        if(max < v[a]){
            max = v[a];
            ind = a;
        }
    }
    return ind;
}

int main()
{
    ifstream f("input.txt");
    vector<Dragon> v;
    f >> v;
    cout << maxFind(v) + 1 << endl;

    return 0;
}
