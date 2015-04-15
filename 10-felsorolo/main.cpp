#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template<typename T>
class Enumerator{
public:
    virtual T current() = 0;
    virtual void next() = 0;
    virtual bool isEnd() = 0;
    virtual void init() = 0;
};

template<typename T>
class VectorEnumerator : public Enumerator<T>{
private:
    vector<T> data;
    int p;
public:
    VectorEnumerator(const vector<T> &v){
        data.resize(v.size());
        for(int a=0;a<v.size();a++){
            data[a] = v[a];
        }
    }

    void init(){
        p = 0;
    }
    bool isEnd(){
        return p >= data.size();
    }
    void next(){
        p++;
    }
    T current(){
        return data[p];
    }

};

template<typename T>
class FileEnumerator : public Enumerator<T>{
private:
    ifstream f;

    T actualItem;
public:
    FileEnumerator(string filename){
        f.open(filename.c_str());
    }

    void init(){
        f.seekg(0);
        next();
    }
    bool isEnd(){
        return f.eof();
    }
    void next(){
        f >> actualItem;
    }
    T current(){
        return actualItem;
    }

};

template<typename T>
T sum(Enumerator<T> &en)
{
    T s = 0;
    for(en.init();!en.isEnd();en.next()){
        s += en.current();
    }
    return s;
}

template<typename T>
int cnt(Enumerator<T> &en, bool beta(T))
{
    int c = 0;
    for(en.init();!en.isEnd();en.next()){
        if(beta(en.current())){
            c++;
        }
    }
    return c;
}

template <typename T>
istream& operator>>(istream& in,vector<T> &myvector)
{
    unsigned int lol=0;
    in >> lol;
    myvector.resize(lol);
    T a;
    for(int i=0;i<lol;i++)
    {
        in >> myvector[i];
    }
    return in;
}


bool isNegative(double a){
    return a < 0;
}
int main()
{
    FileEnumerator<double> en("asd.txt");
    cout << cnt(en,isNegative);
    return 0;
}
