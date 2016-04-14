#include "Ogre.h"

#include <sstream>

using namespace std;

std::ostream& operator<<(std::ostream& out,
                         const Ogre& rh){
    out << rh.weight << " " << rh.smellyFactor << " ";

    switch(rh.cl){
        case Ogre::WARRIOR: out << "WARRIOR"; break;
        case Ogre::ALPHA: out << "ALPHA"; break;
        case Ogre::BETA: out << "BETA"; break;
        default:
            throw Ogre::UNHANDLED_CLASS_TYPE_TO_OUTPUT;
    }

    for(int a=0;a<rh.skinThickness.size();a++){
        out << " " << rh.skinThickness[a];
    }
    return out;
}
std::istream& operator>>(std::istream& in,
                         Ogre& rh){
    stringstream ss;
    string temp;
    getline(in,temp);

    ss << temp;
    //150.1 1.1 1.2 1.4 0.1

    ss >> rh.weight >> rh.smellyFactor;

    string classStr;
    ss >> classStr;
    if(classStr == "WARRIOR"){
        rh.cl = Ogre::WARRIOR;
    }else if(classStr == "ALPHA"){
        rh.cl = Ogre::ALPHA;
    }else if(classStr == "BETA"){
        rh.cl = Ogre::BETA;
    }else if(!in.fail()){
        throw Ogre::UNKNOWN_CLASS_TYPE_TO_READ;
    }

    //1.2 1.4 0.1
    rh.skinThickness.clear();
    float tempThickness;
    while(ss >> tempThickness){
        rh.skinThickness.push_back(tempThickness);
    }

    return in;
}
