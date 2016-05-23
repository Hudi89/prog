#include <iostream>
#include <fstream>

using namespace std;

class Raspberry{
    string id;
    float size;
    string color;
    bool isTasty;

public:
    friend istream& operator>>(istream& in, Raspberry &o);
    friend ostream& operator<<(ostream& out, const Raspberry &o);

    string getId() const {
        return id;
    }

    bool operator<(const Raspberry &o) const{
        return id < o.id;
    }
};

istream& operator>>(istream& in, Raspberry &o){
    in >> o.id >> o.size >> o.color >> o.isTasty;
    return in;
}

ostream& operator<<(ostream& out, const Raspberry &o){
    out << o.id << ' '  << o.size << ' ' << o.color << ' ' << o.isTasty;
    return out;
}

template<typename T>
class FileEnumerator{
private:
  ifstream f;
  T actualData;
public:

  FileEnumerator(const string filename){
    f.open(filename.c_str());
  }

  ~FileEnumerator(){
    f.close();
  }

  void init(){
    next();
  }
  bool isEnd() const{
    return f.fail();
  }
  void next(){
    f >> actualData;
  }
  T current() const{
    return actualData;
  }
};

template<class T>
class FileSeqOut{
    ofstream f;
public:
    FileSeqOut(const string fname){
        f.open(fname.c_str());
    }
    void write(const T &v){
        f << v << endl;
    }
};

int main()
{
    FileEnumerator<Raspberry> in1("input.txt");
    FileEnumerator<Raspberry> in2("input2.txt");

    FileSeqOut<Raspberry> out("out.txt");

    in1.init();
    in2.init();
/*
    while(!in1.isEnd() && !in2.isEnd()){
        if(in1.current() < in2.current()){
            in1.next();
        }else if(in2.current() < in1.current()){
            in2.next();
        }else { // in1.current() == in2.current()
            out.write(in1.current());
            in1.next();
            in2.next();
        }
    }*/
    while(!in1.isEnd() || !in2.isEnd()){
        if(in2.isEnd() ||
           (!in1.isEnd() && in1.current() < in2.current())){
            out.write(in1.current());
            in1.next();
        }else if(
                 in1.isEnd() ||
                 (
                 !in2.isEnd() &&
                  in2.current() < in1.current()
                 )){
            out.write(in2.current());
            in2.next();
        }else { // in1.current() == in2.current()
            out.write(in1.current());
            in1.next();
            in2.next();
        }
    }

    return 0;
}
