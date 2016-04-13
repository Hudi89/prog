#include <iostream>
#include <vector>
#include <fstream>

#include "Exam.h"

using namespace std;

template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &v){
    T temp;
    in >> temp;
    while(!in.fail()){
        v.push_back(temp);
        in >> temp;
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

int main()
{
    try{
        ifstream f("input.txt");
        vector<Exam> v;
        f >> v;
        cout << v;
    }catch(Exam::Exception e){
        switch(e){
        case Exam::UNDHANDLED_TYPE_TO_OUTPUT:
            cout << "UNHANDLED_TYPE_TO_OUTPUT";
            break;
        case Exam::UNKNOWN_TYPE_TO_READ:
            cout << "UNKNOWN_TYPE_TO_READ";
            break;
        default:
            throw e;
        }
    }
   // cout << "Hello world!" << endl;
    return 0;
}
