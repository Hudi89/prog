#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include "Complex.h"
#include "FamilyGuyCharacters.h"

using namespace std;

template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &v2){
    int n;
    in >> n;
    v2.resize(n);
    for(int a=0;a<n;a++){
        in >> v2[a];
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
bool cmf(const vector<T> &v, int &ind, bool beta(T)){
    bool l=false;
    T max;
    for(int a=0;a<v.size();a++){
        if(beta(v[a])){
            if(l){
                if(v[a] > max){
                    max = v[a];
                    ind = a;
                }
            }else{
                max = v[a];
                l = true;
                ind = a;
            }
        }
    }
    return l;
}

bool isMale(FamilyGuyCharacters i){
    return i.getGender();
}

int main()
{
    ifstream f("input.txt");
    vector<FamilyGuyCharacters> v;
    f >> v;
    cout << v;
    int ind;
    if(cmf(v,ind,isMale)){
        cout << ind + 1 << endl;
    }else{
        cout << "nemjo" << endl;
    }

    return 0;
}
