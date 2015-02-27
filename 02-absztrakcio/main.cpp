/**
 * Beolvasunk számokat az inputról (file és konzol közös istreammel) addig amíg 0-t nem kapunk, majd megadjuk a páros számok számát.
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
istream& operator>>(istream& in,vector<T> &myvector)
{
    unsigned int lol=0;
    in >> lol;
    myvector.resize(lol);
    T a;
    for(int i=0;i<lol;i++)
    {
        in >> myvector[i];
    }
    return in;
}

template <typename T>
T eredmeny(const vector<T> &myvector)
{
    T osszeg=myvector[0];
    for(int i = 1; i < myvector.size(); i++ )
    {
        osszeg = osszeg + myvector[i];
    }
    return osszeg;

}


bool feltetel(const int& kapott)
{
    return (kapott%2)==0;
}


unsigned int szamolj(const vector<int> &myvector)
{
    unsigned int C=0;
    for(int i = 0; i < myvector.size(); i++ )
    {
        if(feltetel(myvector[i]))
        {
            C++;
        }
    }
    return C;

}

int main()
{
    vector<int> myvector;
    fstream fin("asd.txt");

    cin >> myvector;
  //Az általánosítás miatt fstreamet és a cin-t is átadhatjuk, hogy onnan olvasson be a program
  //fin >> myvector;
    cout << szamolj(myvector);
    fin.close();
    return 0;
}
