#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Complex
{
    int Re;
    int Im;
};

istream& operator>>(istream &in, Complex &c) {
    in >> c.Re;
    in >> c.Im;
    return in;
}

//Új és ropogós
template<typename T>
istream& operator>>(istream& in, vector<T> &a)
{
    int size;
    in >> size;
    for(int i = 0; i < size; ++i)
    {
        T temp;
        in >> temp;
        a.push_back(temp);
    }
    return in;
}

//Régi beolvasás
/*istream& operator>>(istream& in,vector<int> &a)
{
    int size;
    in >> size;
    int temp;
    for (int i = 0; i < size; ++i) {
        in >> temp;
        a.push_back(temp);
    }
    return in;
}

istream& operator>>(istream& in,vector<vector<int> > &a)
{
    int size;
    in >> size;
    vector<int> temp;
    for(int i = 0; i < size; ++i) {
        temp.clear();
        in >> temp;
        a.push_back(temp);
    }
    return in;
}*/

//Megszámlálás tétel Vectoron
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

//Összegzés tétel Vectoron
int& osszeg(const vector<int> &v)
{
    int s = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        s = s + v.at(i);
    }
    return s;
}

//Maximum keresés tétel Vectoron
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

//Maximumba ágyazott Összegzés Mátrixon
int& maximumOsszegMatrix(const vector<vector<int> > &a)
{
    int error = -1;
    if(a.size() == 0)
    {
        return error;
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

//Feltétel függvény
bool negativE(int a)
{
    return a < 0 ? true : false;
}

//Optimista keresés tétel Vectoron
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

//Pesszimista keresés tétel Vectoron
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

//Feltételes Maximum kiválasztás tétel Vectoron
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


int main()
{
    vector<Complex> c;
    string filename = "asd.txt";
    fstream fin;
    fin.open(filename.c_str());
    fin >> c;
    //==== VECTOR =====
    /*vector<int> v;
    string filename = "asd.txt";
    fstream fin;
    fin.open(filename.c_str());
    if(!fin.is_open())
    {
        cout << "Nem nyert!";
        return -1;
    }
    fin >> v;
    cout << "Minden elem negativ: ";
    int index = feltetelesMaximumKeresesVector(v);
    if(index != -1)
    {
        cout << "Igen " << v[index] << endl;
    }
    else
    {
        cout << "Nem" << endl;
    }

    cout << "DEBUG" << endl;
    for( int i = 0; i < v.size(); ++i )
    {
        cout << v.at(i) << endl;
    }*/
    //=== MÁTRIX ====
    /*vector<vector<int> > matrix;
    cin >> matrix;

    cout << "Maximum: " << maximumOsszegMatrix(matrix) << endl;

    cout << "DEBUG" << endl;
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}
