#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Megfogalmazunk egy absztrakt osztályt, hogy milyen függvényeket várunk el egy felsoroló osztálytól
template<typename T>
class Enumerator{
public:
    //Visszaadja azt az elemet amin állunk
    virtual T current() = 0;
    
    //Következő elemre lép a szekvencia
    virtual void next() = 0;
    
    //Visszadja, hogy vége van-e az szekvenciának
    virtual bool isEnd() = 0;
    
    //A felsorolót inicializálja (Valójában elhagyható lenne)
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


//Egy olyan osztály ami a konstruktorában egy fájl nevet vár majd a >> operátorral felsorolja a T típusú elemeket
template<typename T>
class FileEnumerator : public Enumerator<T>{
private:
    ifstream f;
    //Ebben tároljuk mindig az aktuális elemet, amin áll a felsorolónk
    T actualItem;
public:
    FileEnumerator(string filename){
        f.open(filename.c_str());
    }

    void init(){       
        //Beolvassuk az első elemet
        next();
    }
    bool isEnd(){
        //Akkor állunk le, ha az olvasás sikertelen volt
        return f.fail();
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
