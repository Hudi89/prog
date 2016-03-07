#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

enum Exceptions{
    NEGATIV_LABSZAM,
    NEGATIV_SZAMOSSAG,
    FILE_NOT_FOUND
};

//CMF
//  -CNT(<10)==0
//  -LS(%17==0)
// Note: int

int countLesserThan10(const vector<int> &v){
    int c=0;
    for(int a=0;a<v.size();a++){
        if(v[a] < 10){
            c++;
        }
    }
    return c;
}

bool ls(const vector<int> &v, int &ind){
    bool l = false;
    int i = 0;
    while(!l && i < v.size()){
        l = ((v[i] % 17) == 0);
        ind = i;
        i++;
    }
    return l;
}

int sum(const vector<int> &v){
    int s=0;
    for(int a=0;a<v.size();a++){
        s += v[a];
    }
    return s;
}

bool cmf(const vector<vector<int> > &m,
            int &ind){
    float min;
    bool voltEMar = false;
    for(int a=0;a<m.size();a++){
        int temp;
        bool tempLsResL = ls(m[a],temp);

        //Ha pl. atlag lenne
        //float temp = ((float)sum(m[a])) / m[a].size();
        if(countLesserThan10(m[a]) == 0
           && tempLsResL
           ) {
            if(!voltEMar){
                ind = a;
                min = temp ;
                voltEMar = true;
            }else{
                if(temp  < min){
                    ind = a;
                    min = temp ;
                }
            }
        }
    }
    return voltEMar;
}




void beolvas(istream& in, vector<vector<int> > &v){
    int dc;
    in >> dc;
    if(dc < 0){
        throw NEGATIV_SZAMOSSAG;
    }
    v.resize(dc);
    for(int a=0;a<dc;a++){
        int n;
        in >> n;
        v[a].resize(n);
        for(int b=0;b<n;b++){
            in >> v[a][b];
            if(v[a][b] < 0){
                throw NEGATIV_LABSZAM;
            }
        }
    }
}

template<class T>
ostream& operator<<(ostream& out, const vector<T> &v2){
    out << v2.size() << endl;
    for(int a=0;a<v2.size();a++){
        out << v2[a] << endl;
    }
    return out;
}

void menuKiir(){
    cout << "Hello bela vagyok!" <<endl;
    cout << "-------------" <<endl;
    cout << "Mutans kacsa nyilvantartas" <<endl;
    cout << "-------------" <<endl;
    cout << "Valassz egy labat" <<endl;
    cout << "1. beolvas fajl" <<endl;
    cout << "2. beolvas konzolrol" <<endl;
    cout << "3. kiir" <<endl;
    cout << "4. feladat" <<endl;
    cout << "9. kilep" <<endl;
}

void runMindegy(int cmd, vector<vector<int> > &m){

    switch(cmd){
    case 1:
        {
            ifstream f("input.txt");
            if(!f.is_open())
            {
                throw FILE_NOT_FOUND;
            }
            beolvas(f,m);
            cout << "Sikeres beolvasas!" << endl;
        }
        break;
    case 2:
        beolvas(cin,m);
        break;
    case 3:
        cout <<m;
        break;
    case 4:
        {
            int ind;
            if(cmf(m,ind)){
                cout << "Megvan:" << (ind+1) << endl;
            }else{
                cout << "Nincs meg!" <<endl;
            }
        }
        break;
    default:
        cout << "Csip csip!" << endl;
    }

}

int main()
{
    int cmd;
    vector<vector<int> > m;
    do {
        menuKiir();
        cin >> cmd;

        try{
            runMindegy(cmd,m);
        }catch(Exceptions e){
            switch(e){
            case NEGATIV_LABSZAM:
                cout << "csip csip" << endl;
                break;
            case NEGATIV_SZAMOSSAG:
                cout << "csup csup" << endl;
                break;
            }
        }
    }while(cmd != 9);
    return 0;
}
/*
3
5 13 10 17 12 12
5 21 34 9 10 32
5 12 43 12 1 0

----
Csip-csip

Teszt eset 2.
3
5 13 10 17 12 12
5 21 34 9 10 32
5 12 43 12 1 0
---
csup csup

...
.
.
.
.
.
*/
