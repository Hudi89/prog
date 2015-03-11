#ifndef TETELEK_H_INCLUDED
#define TETELEK_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>

enum Exceptions {
    EMPTY_MATRIX, 
    NEGATIV_COUNT,
    NEGATIV_TOURNAMENT,
    NULL_MATCH,
    TOO_MANY_SCORES //Scores <= 10
};

std::istream &operator >> (std::istream &in , std::vector<int> &t);
std::istream &operator >> (std::istream &in , std::vector<std::vector<int> > &t);
int sorOsszeg(std::vector<int> &v);
int sorMennyiseg (std::vector<int> &v);
bool feltMaxKer(std::vector<std::vector<int> > &v, int& outInd);

#endif // TETELEK_H_INCLUDED
