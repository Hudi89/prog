#include <iostream>
#include <fstream>
#include <vector>

#include "Ogre.h"

using namespace std;


template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &v2){
    T temp;
    while(in >> temp){
        v2.push_back(temp);
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
        vector<Ogre> v;
        f >> v;
        cout << v;
    }catch(Ogre::Exception e){
        cout << "Megdoglott az Ogre!" << endl;
    }
    return 0;
}
