#include <iostream>
#include <fstream>

using namespace std;

class Minion{
    string name;
    int eyeNumber;
    
    //Number between 0 and 1 
    float annoyFactor;
    bool hasGlass;
public:

    string getName() const{
        return name;
    }
    int getEyeNumber() const{
        return eyeNumber;
    }
    float getAnnoyFactor() const{
        return annoyFactor;
    }
    bool getHasGlass() const{
        return hasGlass;
    }

    friend istream& operator>>(istream& in, Minion& o);
    friend ostream& operator<<(ostream& out, const Minion& o);
};

istream& operator>>(istream& in, Minion& o){
    in >> o.name >> o.eyeNumber >> o.annoyFactor >> o.hasGlass;
    return in;
}

ostream& operator<<(ostream& out, const Minion& o){
    out << o.name << " " << o.eyeNumber << " "  << o.annoyFactor << " " << o.hasGlass;
    return out;
}


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



int main()
{
   
/*    SeqInFile<Minion> in("input.txt");
    bool l = true;
    for(in.init();l && !in.isEnd();in.next()){
        l = in.current().getHasGlass();
    }
    
    cout << (l?"Yes":"no") << endl;
  */  
    
    SeqInFile<Minion> in1("input.txt");
    SeqInFile<Minion> in2("input2.txt");

    SeqOutFileAndConsole<Minion> out("out.txt");
    in1.init();
    in2.init();
    
    
    // Intersect
/*  while(!in1.isEnd() && !in2.isEnd()){
        if(in1.current().getName() < in2.current().getName()){
            in1.next();
        }else if(in2.current().getName() < in1.current().getName()){
            in2.next();
        }else{//in1.current() == in2.current()
            out.write(in1.current());
            in1.next();
            in2.next();
        }
    }*/
    
    // Unio
    
    while(!in1.isEnd() || !in2.isEnd()){
        if( in2.isEnd() ||
               (
               !in1.isEnd() &&
               in1.current().getName() < in2.current().getName()
               )
           ){
            out.write(in1.current());
            in1.next();
        }else if(
                 in1.isEnd() ||
                 (
             !in2.isEnd() &&
            in2.current().getName() < in1.current().getName())

                 ){
            out.write(in2.current());
            in2.next();
        }else{//in1.current().getName() == in2.current().getName()
            out.write(in1.current());
            in1.next();
            in2.next();
        }
    }

    // Substract
    /*
    while(!in1.isEnd()){

        if( in2.isEnd() ||
               (
               !in1.isEnd() &&
               in1.current().getName() < in2.current().getName()
               )
           ){
            out.write(in1.current());
            in1.next();
        }else if(!in2.isEnd() &&
            in2.current().getName() < in1.current().getName()
                 ){
            in2.next();
        }else{//in1.current() == in2.current()
            in1.next();
            in2.next();
        }
    }*/
    // Symmetric difference
    /*
    while(!in1.isEnd() || !in2.isEnd()){
        if( in2.isEnd() ||
               (
               !in1.isEnd() &&
               in1.current().getName() < in2.current().getName()
               )
           ){
            out.write(in1.current());
            in1.next();
        }else if(
                 in1.isEnd() ||
                 (
             !in2.isEnd() &&
            in2.current().getName() < in1.current().getName())

                 ){
            out.write(in2.current());
            in2.next();
        }else{//in1.current() == in2.current()
            in1.next();
            in2.next();
        }
    }
    */

    return 0;
}
