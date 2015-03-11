#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct FTMMegoldas{
    int ind;
    int maximum;
    bool l;
};

FTMMegoldas FTM(const vector<int> &v, bool beta(int)){
    bool volt = false;
    int indMax;
    int m;
    for(int a=0;a<v.size();a++){
        if(!beta(v[a])){
        }else{
            if(!volt){
                indMax = a;
                m = v[a];
                volt = true;
            }
            else{
                if(m < v[a]){
                    m = v[a];
                    indMax = a;
                }
            }
        }
    }
    FTMMegoldas ret;
    ret.l = volt;
    if(volt){
        ret.ind = indMax;
        ret.maximum = m;
    }
    return ret;
}

istream& operator>>(istream& in, vector<int> &v){
    int n;
    in >> n;
    v.resize(n);
    for(int a=0;a<n;a++){
        in >> v[a];
    }
    return in;
}

ostream& operator<<(ostream& out, vector<int> &v){
    out << v.size();
    for(int a=0;a<v.size();a++){
        out <<  ' ' << v[a];
    }
    return out;
}

bool parosE(int a){
    return (a % 2) == 0;
}

void menuKiir(){
    cout << "AFEAG23 - 1. feladat" << endl;
    cout << "=================" << endl;
    cout << "1. kiir" << endl;
    cout << "2. újra beolvas" << endl;
    cout << "3. FTM- parose" << endl;
    cout << "4. fájlból" << endl;
    cout << "5. fájlba" << endl;
    cout << "10. kilépés" << endl << endl;
}

int main()
{
    vector<int> v;

    int cmd;
    cout << "Add meg ...!";
    cin >> v;

    do{
        menuKiir();
        cin >> cmd;
        switch(cmd){
            case 1: cout << v << endl; break;
            case 2: cin >> v; break;
            case 3:
            {
                FTMMegoldas mo = FTM(v,parosE);
                if(mo.l){
                    cout <<"MO:" << mo.ind + 1 <<endl;
                }else{
                    cout <<"Mindenki meghalt!" << endl;
                }
            }
            break;
            case 4:
            {
                string str;
                cout << "Add meg a fájl nevét!" << endl;
                cin >> str;
                ifstream f(str.c_str());
                f >> v;
            }
                break;
            case 5:
            {
                string str;
                cout << "Add meg a fájl nevét!" << endl;
                cin >> str;
                ofstream f(str.c_str());
                f << v;
            }
                break;
            case 10: break;
            default:
                cout << "ROSSZ PARANCS WAZZE!" <<endl;
                break;
        }
    }while(cmd != 10);

    cout << "Ciao a program voltam!" <<endl;

    return 0;
}
