#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <conio.h>

using namespace std;

enum Exception{
    WRONG_INPUT,
    EMPTY_VECTOR_FOR_AVG,
    NEGATIVE_COUNT,
    LOW_VALUE,
    HIGH_VALUE
};

template<class T>
istream& operator>>(istream& in, vector<T> &v){
    int n;
    in >> n;
    if(in.fail()){
        throw WRONG_INPUT;
    }
    if(n < 0){
        throw NEGATIVE_COUNT;
    }

    v.resize(n);
    for(int a=0;a<n;a++){
        in >> v[a];
        if(in.fail()){
            throw WRONG_INPUT;
        }
    }
    return in;
}

istream& operator>>(istream& in, vector<int> &v){
    int n;
    in >> n;
    if(in.fail()){
        throw WRONG_INPUT;
    }
    if(n < 0){
        throw NEGATIVE_COUNT;
    }

    v.resize(n);
    for(int a=0;a<n;a++){
        in >> v[a];
        if(in.fail()){
            throw WRONG_INPUT;
        }
        if(v[a] < 50){
            throw LOW_VALUE;
        }
        if(v[a] > 100000){
            throw HIGH_VALUE;
        }
    }
    return in;
}

template<class T>
ostream& operator<<(ostream& out, const vector<T> &v){
    out << v.size();
    for(int a=0;a<v.size();a++){
        out << " " << v[a];
    }
    return out;
}

template<class T>
void echoMatrix(ostream& out,const vector<vector<T> > &m){
    out << m.size() << endl;
    for(int a=0;a<m.size();a++){
        out << m[a].size();
        for(int b=0;b<m[a].size();b++){
            out << " "<< m[a][b];
        }
        out << endl;
    }
}

float average(const vector<int>& v){
    int s=0;
    if(v.size() == 0){
        throw EMPTY_VECTOR_FOR_AVG;
    }
    for(int a=0;a<v.size();a++){
        s += v[a];
    }
    return (float)s/v.size();
}

bool cms(const vector<vector<int> >& alma, int &ind){
    bool l = false;
    float actMax;
    for(int a=0;a<alma.size();a++){
        bool beta = (alma[a].size() >= 3) && (a%7 < 5);
        if(beta){
            float avg = average(alma[a]);
            //cout << "Sor " << a + 1 << " AVG: " << avg << endl;
            if(!l){
                ind = a;
                actMax = avg;
                l = true;
            }else{
                if(actMax < avg){
                    ind = a;
                    actMax = avg;
                }
            }

        }
    }
    return l;
}

string days[] = {"H","K","SZ","CS","P","SZo","V"};

void echoMenu(ostream& out){
    system("cls");
    out << "Hello     Bloeee" <<endl
        << "---------------" <<endl
        << "quit" <<endl
        << "execute" <<endl
        << "read" <<endl
        << "-------" << endl
        << "Choose:";
}

int main()
{
    vector<vector<int> > m;
    string cmd;

    do{
        try{
            echoMenu(cout);
            cin >> cmd;
            if(cmd == "execute"){
                int ind;
                if(cms(m,ind)){
                    cout << "Megvan " << days[ind % 7] <<endl;
                }else{
                    cout << "NM" << endl;
                }
            }else if(cmd == "read"){
                string fname;
                cout << "Filename? " << endl;
                cin >> fname;
                ifstream f(fname.c_str());
                f >> m;
                cout <<"Read ok!" <<endl;
            }else if(cmd == "readConsole"){
                cout << "Hogy kell beadni az adatokat..." <<endl;
                cin >> m;
            }else if(cmd == "write"){
                echoMatrix(cout,m);
            }
        }catch(Exception e){
            switch(e){
            case WRONG_INPUT:
                cout << "WI" << endl;
                break;
            case EMPTY_VECTOR_FOR_AVG:
                cout << "Empty vector for average!" <<endl;
                break;
            case NEGATIVE_COUNT:
                cout << "NC" << endl;
                break;
            case LOW_VALUE:
                cout << "LV" << endl;
                break;
            case HIGH_VALUE:
                cout << "HV" << endl;
                break;
            default:
                cout << "Unhandled Exception!" << endl;
                break;
            }
        }
        if(cmd != "quit"){
            cout << "Press any key!" << endl;
            getch();
        }
    }while(cmd != "quit");
    return 0;
}
