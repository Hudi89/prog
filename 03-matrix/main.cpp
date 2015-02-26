/**
 * A feladat az volt, hogy határozzuk meg annak a sornak az indexét amelyikben a legnagyobb a sorösszeg.
 *
 * Többszörös tétel visszavezetés: MAX->SUM
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


template<typename T>
istream &operator >> (istream &in , vector<T> &t)
{
    T a;
    int n;

    in >> n;
    t.resize(n);
    for (int i=0; i<t.size(); ++i)
    {
        in >> a;
        t[i]=a;
    }
    return in;
}

int szamlalas(const vector <int> &t)
{
    int darab=0;
    for (unsigned int i=0; i<t.size(); ++i)
    {
        if (t[i] % 2 ==0 )
        {
            darab++;
        }
    }
    return darab;
}

template<typename T>
T sor_osszeg(vector< T > &t)
{
    T sum;
    null(sum);
    for(int i = 0 ; i < t.size() ; ++i)
    {
        sum = sum + t[i];
    }
    return sum;
}

template<typename T>
T max_sor (vector< vector <T> > &t )
{
    int ind = 0;
    T maximum = sor_osszeg(t[0]);
    T most;
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

int main()
{
    vector <vector <int> > t;
    fstream fin("asd.txt");
    fin >> t;

    cout << max_sor ( t ) << endl;

    fin.close();
    return 0;
}
