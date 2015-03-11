#include "tetelek.h"

using namespace std;

istream &operator >> (istream &in , vector<int> &t)
{
    int a;
    int n;
    in >> n;
    if (n<0){throw NEGATIV_COUNT;}
    else if (n==0){throw EMPTY_MATRIX;}
    t.resize(n);
    for (int i=0; i<t.size(); ++i)
    {
        in >> a;
        if (a>10){throw TOO_MANY_SCORES;}
        t[i]=a;
    }
    return in;
}

istream &operator >> (istream &in , vector<vector<int> > &t)
{
    vector<int> a;
    int n;
    in >> n;
    if (n<0){throw NEGATIV_TOURNAMENT;}
    else if (n==0){throw NULL_MATCH;}
    t.resize(n);
    for (int i=0; i<t.size(); ++i)
    {
        in >> a;
        t[i]=a;
    }
    return in;
}

int sorOsszeg(vector<int> &v)
{
    int sum=0;
    //null(sum);
    for(int i = 0 ; i < v.size() ; ++i)
    {
        sum = sum + v[i];
    }
    return sum;
}

int sorMennyiseg (vector<int> &v)
{
    int db=0;
    for(int i = 0 ; i < v.size() ; ++i)
    {
        if(v[i]>3){
            db += 1;
        }
    }
    return db;
}

bool feltMaxKer(vector<vector<int> > &v, int& outInd)
{
    int M = 0;
    int ind = 0;
    bool l = false;
    for(int i=0;i<v.size();++i){
        if(sorMennyiseg(v[i])>=1){
                if(l){
                    if(M < (float)sorOsszeg(v[i])/(float)v[i].size()){
                        M = (float)sorOsszeg(v[i])/(float)v[i].size();
                        ind = i;
                    }
                }else{
                    M = (float)sorOsszeg(v[i])/(float)v[i].size();
                    ind = i;
                    l=true;
                }
        }
    }
    if(l){
      outInd = ind
    }
    return l;
}
