#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <vector>

enum StudentSpec{
    A_SPEC,
    B_SPEC,
    C_SPEC
};

class Student{
    std::string studentCode;
    int age;
    StudentSpec studentSpec;
    std::vector<bool> attendance;

public:

    enum Exception{
        UNDHANDLED_SPEC,
        UNKNOWN_SPEC,
        WRONG_STUDENT_CODE_LENGTH
    };

    friend std::ostream& operator<<(std::ostream& out, const Student &o);
    friend std::istream& operator>>(std::istream& in, Student &o);
};

std::ostream& operator<<(std::ostream& out, const Student &o);
std::istream& operator>>(std::istream& in, Student &o);

#endif // STUDENT_H_INCLUDED
