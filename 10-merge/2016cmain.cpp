#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class SeqInFile{
private:
    ifstream f;
    T actual;
public:
    SeqInFile(string fname){
        f.open(fname.c_str());
    }

    void init(){
        f >> actual;
    }
    void next(){
        f >> actual;
    }
    T current() const{
        return actual;
    }

    bool isEnd() const{
        return f.fail();
    }
};

template<class T>
class SeqOut{
public:
    virtual void write(const T &v) = 0;
};

template<class T>
class SeqOutConsole : public SeqOut<T>{
public:
    void write(const T &v){
        cout << v << endl;
    }
};

template<class T>
class SeqOutFile : public SeqOut<T>{
    ofstream f;
public:
    SeqOutFile(string fname){
        f.open(fname.c_str());
    }
    void write(const T &v){
        f << v << endl;
    }
};



class Minion{
    string name;
    int eyeNumber;
    float annoyFactor;
    bool hasGlass;
public:

    bool operator<(const Minion &o){
        return name < o.name;
    }

    string getName(){
        return name;
    }

    friend istream& operator>>(istream& in, Minion& o);
    friend ostream& operator<<(ostream& out, const Minion& o);
};

istream& operator>>(istream& in, Minion& o){
    in >> o.name >> o.eyeNumber
     >> o.annoyFactor >> o.hasGlass;
    return in;
}

ostream& operator<<(ostream& out, const Minion& o){
    out << o.name << " " << o.eyeNumber << " "
        << o.annoyFactor << " " << o.hasGlass;
    return out;
}

template<class T>
class SeqOutFileAndConsole : public SeqOut<T>{
    ofstream f;
public:
    SeqOutFileAndConsole(string fname){
        f.open(fname.c_str());
    }
    void write(const T &v){
        f << v << endl;
        cout << v << endl;
    }
};

void intersect(SeqInFile<Minion> &in1, SeqInFile<Minion> &in2,
               SeqOut<Minion> &out){
    in1.init();
    in2.init();

    while(!in1.isEnd() && !in2.isEnd()){
        if(in1.current().getName() < in2.current().getName()){
            in1.next();
        }else if(in2.current().getName() < in1.current().getName()){
            in2.next();
        }else{//in1.current() == in2.current()
            out.write(in1.current());
            in1.next();
            in2.next();
        }
    }
}

void unio(SeqInFile<Minion> &in1, SeqInFile<Minion> &in2,
               SeqOut<Minion> &out){
    in1.init();
    in2.init();

    while(!in1.isEnd() || !in2.isEnd()){

        if( in2.isEnd() ||
               (
               !in1.isEnd() &&
               in1.current() < in2.current()
               )
           ){
            out.write(in1.current());
            in1.next();
        }else if(
                 in1.isEnd() ||
                 (
             !in2.isEnd() &&
            in2.current() < in1.current())

                 ){
            out.write(in2.current());
            in2.next();
        }else{//in1.current() == in2.current()
            out.write(in1.current());
            in1.next();
            in2.next();
        }
    }
}

template<class T>
void write(SeqInFile<T> &in){
    for(in.init();!in.isEnd();in.next()){
        cout << in.current() << endl;
    }
}


int main()
{
    SeqInFile<Minion> in1("input.txt");
    SeqInFile<Minion> in2("input2.txt");

    SeqOutConsole<Minion> out;
    SeqOutFileAndConsole<Minion> out2("out.txt");

    unio(in1,in2,out);

    return 0;
}
