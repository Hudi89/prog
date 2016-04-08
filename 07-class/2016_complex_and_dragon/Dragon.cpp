#include "Dragon.h"

float Dragon::getTailLength() const{
    return tailLength;
}
bool Dragon::operator<(const Dragon &o) const{
    return tailLength < o.tailLength;
}

std::ostream& operator<<(std::ostream& out, const Dragon &o){
    out << o.age << ' ' << o.tailLength << ' ' << o.color;
    return out;
}

std::istream& operator>>(std::istream& in, Dragon &o){
    in >> o.age >> o.tailLength >> o.color;
    return in;
}
