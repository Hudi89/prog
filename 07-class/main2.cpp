#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>


using namespace std;

enum Exc {
URES_VEKTOR
};

class Bolygo{
    string nev;
    vector<int> faj;
public:

    int nepesseg ()const{
        int nep;
        for( int i = 0 ; i < faj.size() ; ++i){
            nep += faj[i];
        }
        return nep;
    }

    friend istream& operator >> (istream& in , Bolygo & b);
    friend ostream& operator << (ostream& out ,const Bolygo & b);
};

istream& operator >> (istream& in , Bolygo & b){
    string s;
    getline (in , s);
    stringstream ss(s);
    int n;
    ss >> b.nev >> n;

    b.faj.resize(n);

    for(int i = 0 ; i < n ; i++){
        ss >> b.faj[i];
    }

    return in;
}

istream& operator >> (istream& in , vector<Bolygo> &v){
    int n;
    in >> n;
    v.resize(n);
    for(int i = 0 ; i < n ; ++i){
        in >> v[i];
    }
    return in;
}

ostream& operator << (ostream& out ,const Bolygo & b){
    out << b.nev << " " << b.faj.size();
    for (int i = 0 ; i < b.faj.size() ; ++i){
        out << " " <<b.faj[i];
    }
    return out;
}

ostream& operator << (ostream& out , const vector<Bolygo> &v){
    out << v.size();
    for(int i = 0 ; i < v.size() ; ++i){
        out << " " << v[i];
    }
    return out;
}

int maxKer(const vector<Bolygo> &v ){

    if(v.size() < 1){
        throw URES_VEKTOR;
    }

    int ind = 0;
    double maximum = v[0].nepesseg();
    for(int i = 1 ; i < v.size() ; ++i){

        double moszt = v[i].nepesseg();

        if( moszt < maximum ){
            ind = i;
            maximum = moszt;
        }

    }

    return ind;
}

int main()
{
    vector<Bolygo> v;
    cin >> v;

    cout << maxKer(v) + 1 << endl;  //hudinak ennél a pontnál fogyott ki a filce
    return 0;
}
