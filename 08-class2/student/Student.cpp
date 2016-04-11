#include "Student.h"

#include <sstream>

using namespace std;

std::ostream& operator<<(std::ostream& out, const Student &o){
    out << o.studentCode << " "<< o.age << " ";
    switch(o.studentSpec){
        case A_SPEC: out << "A";break;
        case B_SPEC: out << "B";break;
        case C_SPEC: out << "C";break;
        default:
            throw Student::UNDHANDLED_SPEC;
    }
    for(int a=0;a<o.attendance.size();a++){
        out << " " << o.attendance[a];
    }
    return out;
}

std::istream& operator>>(std::istream& in, Student &o){
    string temp;
    getline(in,temp);

    stringstream ss;
    ss <<temp;

    ss >> o.studentCode >> o.age;
    if(ss && o.studentCode.length() != 6){
        throw Student::WRONG_STUDENT_CODE_LENGTH;
    }
    string specStr;
    ss >>specStr;
    if(specStr == "A"){
        o.studentSpec = A_SPEC;
    }else if(specStr == "B"){
        o.studentSpec = B_SPEC;
    }else if(specStr == "C"){
        o.studentSpec = C_SPEC;
    }else if(ss){
        throw Student::UNKNOWN_SPEC;
    }

    bool tempBool;

    o.attendance.clear();
//  o.attendance.resize(0);
    while(ss >> tempBool){
        o.attendance.push_back(tempBool);
    };

    return in;
}
