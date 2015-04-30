#include <iostream>
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


template<class T>
class SeqOut{
public:
    virtual void write(const T& data) = 0;
};

template<class T>
class ConsoleSeqOut : public SeqOut<T>{
public:
    void write(const T& data){
        cout << data << " ";
    }
};

class Adatok{
    string name;
    int kereset;
public:
    string getName() {
        return name;
    }

    int getKereset() {
        return kereset;
    }
    friend istream& operator>>(istream& in, Adatok &adatok);
    friend ostream& operator<<(ostream& out,const Adatok &adatok);
};

istream& operator>>(istream& in, Adatok &adatok) {
    in >> adatok.name >> adatok.kereset;
    return in;
}

ostream& operator<<(ostream& out,const Adatok &adatok) {
    out << adatok.name <<" "<< adatok.kereset<<endl;
    return out;
}

int main()
{
    FileEnumerator<ppl> si1("in1.txt");
    FileEnumerator<ppl> si2("in2.txt");
    ConsoleSeqOut<ppl> so;
    si1.init();
    si2.init();

    while (!(si1.isEnd() || si2.isEnd())) {
        if (si1.current().getName() == si2.current().getName()) {
            so.write(si1.current());
            si1.next();
            si2.next();
        } else {
            if (si1.current().getName() < si2.current().getName()) {
                si1.next();
            }
            else {
                si2.next();
            }
        }
    }
    return 0;
}
