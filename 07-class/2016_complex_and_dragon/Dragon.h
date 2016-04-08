#ifndef DRAGON_H_INCLUDED
#define DRAGON_H_INCLUDED

#include <iostream>

class Dragon{
private:
    int age;
    float tailLength;
    std::string color;

public:
    float getTailLength() const;

    bool operator<(const Dragon &o) const;

    friend std::ostream& operator<<(std::ostream& out, const Dragon &o);
    friend std::istream& operator>>(std::istream& in, Dragon &o);
};

std::ostream& operator<<(std::ostream& out, const Dragon &o);
std::istream& operator>>(std::istream& in, Dragon &o);

#endif // DRAGON_H_INCLUDED
