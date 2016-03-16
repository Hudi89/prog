#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


// Lila sárkányok etetése
// Adatok: napi adott kaja
//CMinF-CNT(==0)!=size(),SUM
//
// 3 4
// 2.4 1.2 1 1
// 0 0 0 0
// 1 1 2 1.2
//
// Melyik lila sárkány kapott a legkevesebb kaját
// azok közül akiket nem éheztetünk (azt éheztetjük
// aki egyik nap sem kapott kaját)?


enum Exception{
    NEGATIVE_COUNT,
    NEGATIVE_VALUE,
    TOO_MUCH_FOOD,
    WRONG_INPUT
};

int count(const vector<double> &v){
    int c = 0;
    for(int i=0;i<v.size();i++){
        if(v[i] == 0){
            c++;
        }
    }
    return c;
}

double sum(const vector<double> &v){
    double s = 0;
    for(int i=0;i<v.size();i++){
        s = s + v[i];
    }
    return s;
}

bool feladat(const vector<vector<double> > &m,
             int &ind){
    bool isFound = false;
    double min;

    for(int i=0;i<m.size();i++){
        if(count(m[i]) != m[i].size()){
            double actVal = sum(m[i]);
            if(!isFound){
                ind = i;
                isFound = true;
                min = actVal;
            }else{
                if(actVal < min){
                    ind = i;
                    min = actVal;
                }
            }
        }
    }
    return isFound;
}


template<class T>
void matrixBeolvas(std::istream &in, std::vector<std::vector<T> > &m ){
    int w,h;
    in >> h>> w;
    if(in.fail()){
        throw WRONG_INPUT;
    }
    if(h == 0 || w == 0){
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
            if(m[a][b] < 0){
                throw NEGATIVE_VALUE;
            }
            if(m[a][b] > 10000){
                throw TOO_MUCH_FOOD;
            }
        }
    }
}

template<class T>
void matrixKiir(std::ostream &out, std::vector<std::vector<T> > &m ){
    out << m.size();

    if(m.size() == 0){
        out << " 0";
    }else{
        out << " " << m[0].size();
    }
    out  << std::endl;

    for(int a =0;a<m.size();a++){
        for(int b = 0;b<m[0].size();b++){
            out << m[a][b] << " ";
        }
        out << std::endl;
    }
}
void menuKiir(){
    cout << "Bela lila sarkanytenyeszto programja!" << endl;
    cout << "--------------" << endl;
    cout << "Valassz!" << endl;
    cout << "1) Beolvas filebol!" << endl;
    cout << "2) Beolvas konzolrol!" << endl;
    cout << "3) Kiir!" << endl;
    cout << "4) Feladat!" << endl;
    cout << "9) Kilep!" << endl;
}

void main2(int cmd, vector<vector<double> > &m){

    switch(cmd){
    case 1:
        {
            string filename;
            cout << "Mondja fajt!" << endl;
            cin >> filename;
            ifstream f(filename.c_str());
            matrixBeolvas(f,m);
        }
        break;
    case 2:
        matrixBeolvas(cin,m);
        break;
    case 3:
        matrixKiir(cout,m);
        break;
    case 4:
        {
            int ind;
            if(feladat(m,ind)){
                cout << "Megvan:" << (ind + 1) << endl;
            }else{
                cout << "A manóba!"<< endl;
            }
        }
        break;
    case 9:break;
    default:
        cout << "Ismeretlen parancs!!!";
        break;
    }
}

int main()
{
    int cmd;
    vector<vector<double> > m;
    do{
        menuKiir();
        cin >> cmd;
        try{
            main2(cmd,m);
        }catch(Exception e){
            switch(e){
                case NEGATIVE_COUNT:
                    cout << "NC" << endl;
                    break;
                case NEGATIVE_VALUE:
                    cout << "NV" << endl;
                    break;
                case TOO_MUCH_FOOD:
                    cout << "TMF" << endl;
                    break;
                case WRONG_INPUT:
                    cout << "WI" << endl;
                    break;
                default:
                    throw e;
            }
        }
    }while(cmd != 9);
    return 0;
}
