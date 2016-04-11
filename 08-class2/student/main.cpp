#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


#include "Student.h"

using namespace std;

template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &v){
    T temp;
    in >> temp;
    while(in.good()){
        v.push_back(temp);
        in >> temp;
    }
    return in;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &v2){
    for(int a=0;a<v2.size();a++){
        out << v2[a] << std::endl;
    }
    return out;
}


int main()
{
    vector<Student> v;
    ifstream f("input.txt");
    try{
        f >> v;
        cout << v;
    }
    catch(Student::Exception e){
        cout << "Hiba:" << e;
    }

    return 0;
}
