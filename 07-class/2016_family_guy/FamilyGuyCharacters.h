#ifndef FAMILYGUYCHARACTERS_H_INCLUDED
#define FAMILYGUYCHARACTERS_H_INCLUDED

#include <iostream>

class FamilyGuyCharacters{
    std::string name;
    int iq;
    int showTime;
    bool gender;
public:

    bool getGender() const;
    int getShowTime() const;

    bool operator>(const FamilyGuyCharacters &o) const;

    friend std::ostream& operator<<(std::ostream& out, const FamilyGuyCharacters &rh);
    friend std::istream& operator>>(std::istream& in, FamilyGuyCharacters &rh);

};

std::ostream& operator<<(std::ostream& out, const FamilyGuyCharacters &rh);
std::istream& operator>>(std::istream& in, FamilyGuyCharacters &rh);

#endif // FAMILYGUYCHARACTERS_H_INCLUDED
