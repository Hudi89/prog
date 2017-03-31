#include "myheader.h"

istream& operator>>(istream &in, Complex &c) {
    in >> c.Re;
    in >> c.Im;
    return in;
}

int& osszeg(const vector<int> &v)
{
    int s = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        s = s + v.at(i);
    }
    return s;
}

int& maximumOsszegMatrix(const vector<vector<int> > &a)
{
    if(a.size() == 0)
    {
        throw URES_MATRIX;
    }
    int max_h = osszeg(a[0]);
    for(int i = 1; i < a.size(); ++i)
    {
        int temp = osszeg(a[i]);
        if(max_h < temp)
        {
            max_h = temp;
        }
    }
    return max_h;
}

int& szamol(const vector<int> &v)
{
    int c = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        if(v.at(i)%2 == 0)
        {
            c = c + 1;
        }
    }
    return c;
}

int& maxVector(const vector<int> &a)
{
    int error = -1;
    if(a.size() == 0)
    {
        return error;
    }
    int max_h = a[0];
    for(int i = 1; i < a.size(); ++i)
    {
        int temp = a[i];
        if(max_h < temp)
        {
            max_h = temp;
        }
    }
    return max_h;
}

bool negativE(int a)
{
    return a < 0 ? true : false;
}

bool& keresOptimistaVector(const vector<int> &a)
{
    bool l = true;
    int i = 0;
    while(l && i < a.size())
    {
        l = negativE(a[i]);
        i++;
    }
    return l;
}

bool& keresPesszimistaVector(const vector<int> &a)
{
    bool l = false;
    int i = 0;
    while( !l && i < a.size() )
    {
        l = negativE(a[i]);
        i++;
    }
    return l;
}

int& feltetelesMaximumKeresesVector(const vector<int> &a)
{
    bool l = false;
    int maxh;
    int maxIndex = -1;
    for(int i = 0; i < a.size(); ++i)
    {
        if(l && negativE(a[i]))
        {
            if(maxh < a[i])
            {
                maxIndex = i;
                maxh  = a[i];
            }
        }
        else if(!l && negativE(a[i]))
        {
            maxh = a[i];
            maxIndex = i;
            l = true;
        }
    }
    return maxIndex;
}


int osszegVector(const vector<int> &a) {
    int s = 0;
    for(int i = 0; i < a.size(); ++i) {
        s += a.at(i);
    }
    return s;
}

int feltMaxKerOsszeg(const vector<vector<int> > &a ) {
    bool l = false;
    int maxIndex;
    int maxh;
    for(int i = 0; i < a.size(); ++i) {
        //Feltétel hamis -> nem írunk programba
        int osszeg = osszegVector(a.at(i));
        if(osszeg > 2000 && !l)
        {
            l = true;
            maxh = osszeg;
            maxIndex = i;
        } else if(osszeg > 2000 && l)
        {
            if(maxh < osszeg)
            {
                maxh = osszeg;
                maxIndex = i;
            }
        }
    }
    return maxh;
}

void menu() {
    cout << "MENU" << endl;
    cout << "1 - Beolvasas" << endl;
    cout << "2 - DEBUG" << endl;
    cout << "3 - Feladat" << endl;
    cout << "4 - Kilép" << endl;
}
