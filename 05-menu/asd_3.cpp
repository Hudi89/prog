#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// CMF-LS(>3),SUM/size()
// Foci
//
// n db focista
// m meccsen lőtt gól
//
// 3 3
// 1 3 4
// 1 2 2
// 2 3 2
//
// Melyik focista lőtt a legtöbb gólt átlagban,
// azok közül akik legalább egyszer lőttek több
// mint 3 gólt egy meccsen.
//

enum Exception{
    NEGATIVE_COUNT,
    NULL_COUNT,
    WRONG_INPUT
};

int sum(const vector<vector<int> > &m, int col){
    int s = 0;
    for(int i = 0; i <m.size();i++){
        s = s + m[i][col];
    }
    return s;
}

bool linearSearchGreaterThanThree(const vector<vector<int> > &m, int col){
    bool l = false;
    int i = 0;
    while(!l && i < m.size()){
        l = m[i][col] > 3;
        i = i + 1;
    }
    return l;
}

bool feladat(const vector<vector<int> > &m,
             int &ind){
    bool l = false;
    float max;
    for(int i=0;i<m[0].size();i++){
        if(linearSearchGreaterThanThree(m,i)){
         float actAvg = (float)sum(m,i)/(float)m.size();
           if(!l){
              ind = i;
              l = true;
              max = actAvg;
           }else{
              if(actAvg > max){
                ind = i;
                max = actAvg;
              }
           }
        }
    }
    return l;
}


template<class T>
void matrixBeolvas(std::istream &in, std::vector<std::vector<T> > &m ){
    int w,h;
    in >> w>> h;
    if(in.fail()){
        throw WRONG_INPUT;
    }
    if(w < 0 || h <0){
        throw NEGATIVE_COUNT;
    }
    m.resize(h);
    for(int a =0;a<h;a++){
        m[a].resize(w);
        for(int b = 0;b<w;b++){
            in >> m[a][b];
            if(in.fail()){
                throw WRONG_INPUT;
            }
        }
    }
}
/*
Beolvasás transzponálással:

template<class T>
void matrixBeolvas(std::istream &in, std::vector<std::vector<T> > &m ){
    int w,h;
    in >> w>> h;
    if(in.fail()){
        throw WRONG_INPUT;
    }
    if(w < 0 || h <0){
        throw NEGATIVE_COUNT;
    }
    m.resize(w);
    for(int a =0;a<w;a++){
        m[a].resize(h);
    }
    for(int a =0;a<h;a++){
        for(int b = 0;b<w;b++){
            in >> m[b][a];
            if(in.fail()){
                throw WRONG_INPUT;
            }
        }
    }
}
*/

template<class T>
void matrixKiir(std::ostream &out, std::vector<std::vector<T> > &m ){
    if(m.size() == 0){
        out << "0 ";
    }else{
        out << m[0].size() << " ";
    }

    out << m.size() << std::endl;
    for(int a =0;a<m.size();a++){
        for(int b = 0;b<m[0].size();b++){
            out << m[a][b] << " ";
        }
        out << std::endl;
    }
}

void menuKiir(){
    cout << "Focista eredmeny elemzo programocska!" <<endl;
    cout << "Ribert Goza - ABCDEF" <<endl;
    cout << "--------------------" <<endl;
    cout << "1) Beolvas fajlbol!" <<endl;
    cout << "2) Beolvas konzolrol!" <<endl;
    cout << "3) Kiir!" <<endl;
    cout << "4) Meglepi!" <<endl;
    cout << "9) Kilepes!" <<endl;
}

void main2(int cmd, vector<vector<int> > &m){
    switch(cmd){
    case 1:
        {
            ifstream f("input.txt");
            matrixBeolvas(f,m);
            if(m.size() == 0 || m[0].size() == 0){
                throw NULL_COUNT;
            }
        }
        break;
    case 2:
        matrixBeolvas(cin,m);
        if(m.size() == 0 || m[0].size() == 0){
            throw NULL_COUNT;
        }
        break;
    case 3:
        matrixKiir(cout,m);
        break;
    case 4:
        {
            int ind;
            if(feladat(m,ind)){
                cout << (ind + 1) <<endl;
            }else{
                cout << "Hulye vagy!" <<endl;
            }
        }
    }
}

int main()
{
    int cmd;
    vector<vector<int> > m;
    do{
        menuKiir();
        cin >> cmd;

        try{
            main2(cmd,m);
        }catch(Exception e){
            switch(e){
            case NEGATIVE_COUNT:
                cout << "NC" <<endl;
                break;
            case NULL_COUNT:
                cout << "NullC" <<endl;
                break;
            case WRONG_INPUT:
                cout << "WI" <<endl;
                break;
            default:
                cout << "Megnagyobb hulye vagy!" << endl;
            }
        }
    }while(cmd != 9);
    return 0;
}
