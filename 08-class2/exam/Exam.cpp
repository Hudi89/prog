#include "Exam.h"

#include <sstream>


using namespace std;

std::ostream& operator<<(std::ostream& out, const Exam &o){
    out << o.courseName << " " << o.credit << " " << o.dateTime << " ";

    switch(o.type){
        case Exam::ORAL: out << "ORAL"; break;
        case Exam::WRITE: out << "WRITE"; break;
        default:
            throw Exam::UNDHANDLED_TYPE_TO_OUTPUT;
    }

    for(int a=0;a<o.grades.size();a++){
        out << " " << o.grades[a];
    }
    return out;
}

std::istream& operator>>(std::istream& in, Exam &o){
    string temp;
    getline(in,temp);

    stringstream ss;
    ss << temp;
    ss >> o.courseName;
    ss >> o.credit >> o.dateTime;

    string typeString;
    ss >> typeString;

    if(typeString == "ORAL"){
        o.type = Exam::ORAL;
    }else if(typeString == "WRITE"){
        o.type = Exam::WRITE;
    }else if(in.good()){
        throw Exam::UNKNOWN_TYPE_TO_READ;
    }

    o.grades.clear();
    int tempGrade;
    while(ss >> tempGrade){
        o.grades.push_back(tempGrade);
    }

    return in;
}
