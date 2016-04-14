#include "FamilyGuyCharacters.h"


bool FamilyGuyCharacters::getGender() const{
    return gender;
}
int FamilyGuyCharacters::getShowTime() const{
    return showTime;
}
bool FamilyGuyCharacters::operator>(const FamilyGuyCharacters &o) const{
    return showTime < o.showTime;
}

std::ostream& operator<<(std::ostream& out,
                        const FamilyGuyCharacters &rh){
    out << rh.name << " " << rh.iq << " " <<
            rh.showTime << " " << rh.gender;
    return out;
}
std::istream& operator>>(std::istream& in,
                          FamilyGuyCharacters &rh){
    in >> rh.name >> rh.iq >>
            rh.showTime >> rh.gender;
    return in;
}
