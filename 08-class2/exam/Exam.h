#ifndef EXAM_H_INCLUDED
#define EXAM_H_INCLUDED

#include <iostream>
#include <vector>

class Exam{
public:
    enum Type{
        ORAL,
        WRITE
    };

    enum Exception{
        UNDHANDLED_TYPE_TO_OUTPUT,
        UNKNOWN_TYPE_TO_READ
    };
private:
    std::string courseName;
    int credit;
    std::string dateTime;
    Type type;

    std::vector<int> grades;
public:
    friend std::ostream& operator<<(std::ostream& out, const Exam &o);
    friend std::istream& operator>>(std::istream& in, Exam &o);
};

std::ostream& operator<<(std::ostream& out, const Exam &o);
std::istream& operator>>(std::istream& in, Exam &o);
#endif // EXAM_H_INCLUDED
