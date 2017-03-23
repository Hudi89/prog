#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

enum Exception{
    NPC,
    IS,
    LPN,
    WI
};
const string exceptionNames[] =
    {"NPC","IS","LPN","WI"};

void echoException(Exception e){
    switch(e){
        case NPC: case IS: case LPN:case WI:
            cout << exceptionNames[e] <<endl;
            break;
        default:
            cout << "Unhandled Exception!" << endl;
            break;
    }
}



template<class T>
istream& operator>>(istream& in, vector<T>& v){
    int n;
    in >> n;
    if(in.fail()){throw WI;}
    if(n <= 0){throw NPC;}
    v.resize(n);
    for(int a=0;a<n;a++){
        in >> v[a];
        if(in.fail()){throw WI;}
    }
    return in;
}

istream& operator>>(istream& in, vector<string>& v){
    int n;
    in >> n;
    if(in.fail()){throw WI;}
    if(n <= 0){throw NPC;}

    v.resize(n);
    for(int a=0;a<n;a++){
        in >> v[a];
        if(in.fail()){throw WI;}
        if(!isalpha(v[a][0])){
            throw IS;
        }
        if(v[a].length() > 10){
            throw LPN;
        }
    }
    return in;
}

template<class T>
void writeMatrix(ostream& out, const vector<vector<T> >& m){
    out << m.size() << endl;
    for(int a=0;a<m.size();a++){
        out << m[a].size();
        for(int b=0;b<m[a].size();b++){
            out << " " << m[a][b];
        }
        out << endl;
    }
}

template<class T>
bool linSearchOrderEnd(const vector<T>& v, int& ind){
    bool l=false;
    int i = 0;
    while(!l && i < v.size()){
        l = (v[i] == "orderEnd");
        ind = i;
        i++;
    }
    return l;
}

template<class T>
bool cms(const vector<vector<T> >& m, int& ind){
    bool l = false;
    int actMax;
    for(int a=0;a<m.size();a++){
        int act;
        bool foundOrderEnd = linSearchOrderEnd(m[a],act);
        bool beta = foundOrderEnd &&
                    m[a][0] == "landing";
        if(beta){
            if(!l){
                ind = a;
                l = true;
            }else{
                if(actMax < act){
                    actMax = act;
                    ind = a;
                }
            }
        }
    }
    return l;
}

#include <sstream>

int main()
{
   /* ifstream f("input.txt");
    string str;
    getline(f,str);
    while(!f.fail()){
        stringstream ss;
        ss << str;
        string actWord;
        ss >> actWord;
        while(!ss.fail()){
            cout << actWord << ", ";
            ss >> actWord;
        }
        cout << endl;

        getline(f,str);
    }*/

    
    vector<vector<string> > m;
    try{
        f >> m;
        writeMatrix(cout ,m);
        int ind;
        if(cms(m,ind)){
            cout << "Mevvan:" << (ind + 1) <<endl;
        }else{
            cout<<"NF" <<endl;
        }
    }catch(Exception e){
        echoException(e);
    }
    return 0;
}
