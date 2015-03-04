#include "tetelek.h"

using namespace std;

int sor_osszeg(vector< int > &t)
{
    int sum = 0;
    for(int i = 0 ; i < t.size() ; ++i)
    {
        sum = sum + t[i];
    }
    return sum;
}


int max_sor (vector< vector <int> > &t )
{
    int ind = 0;

    if(t.size()==0){
        throw EMPTY_MATRIX;
    }

    int maximum = sor_osszeg(t[0]);
    int most;
    for(int i = 0 ; i< t.size() ; ++i)
    {
        most = sor_osszeg(t[i]);
        if(maximum < most)
        {
            maximum = most;
            ind = i;
        }
    }
    return maximum;
}


istream &operator >> (istream &in , vector<int> &t)
{
    int a;
    int n;

    in >> n;
    if(n < 0){
        throw NEGATIVE_COUNT;
    }
    t.resize(n);
    for (int i=0; i<t.size(); ++i)
    {
        in >> t[i];
    }
    return in;
}

istream &operator >> (istream &in , vector<vector<int> > &t)
{
    int a;
    int n;

    in >> n;
    if(n < 0){
        throw NEGATIVE_COUNT;
    }
    t.resize(n);
    for (int i=0; i<t.size(); ++i)
    {
        in >> t[i];
    }
    return in;
}
