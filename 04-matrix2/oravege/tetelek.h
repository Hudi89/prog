#ifndef TETELEK_H_INCLUDED
#define TETELEK_H_INCLUDED

#include <iostream>
#include <vector>

enum Exceptions {EMPTY_MATRIX,NEGATIVE_COUNT};

std::istream &operator >> (std::istream &in , std::vector<int> &t);
std::istream &operator >> (std::istream &in , std::vector<std::vector<int> > &t);
int sor_osszeg(std::vector< int > &t);
int max_sor (std::vector< std::vector <int> > &t );




#endif // TETELEK_H_INCLUDED
