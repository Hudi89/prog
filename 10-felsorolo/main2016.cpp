#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template<class T>
class Enumerator{
public:
    virtual T current() const = 0;
    virtual void next() = 0;
    virtual bool isEnd() const = 0;
    virtual void init() = 0;
};

template<class T>
class VectorEnumerator : public Enumerator<T>{
    vector<T>* data;
    int a;
public:
    VectorEnumerator(vector<T> &v){
        data = &v;
        init();
    }

    T current() const{
        return (*data)[a];
    }
    void next(){
        a++;
    }
    bool isEnd() const{
        return a >= data->size();
        //return !(a < v.size());
    }
    void init(){
        a = 0;
    }
};

template<class T>
class FileEnumerator : public Enumerator<T>{
    ifstream f;
    T temp;
public:
    FileEnumerator(string str){
        f.open(str.c_str());
    }

    T current() const{
        return temp;
    }
    void next(){
        f >> temp;
    }
    bool isEnd() const{
        return f.fail();
    }
    void init(){
        next();
    }
};

template<class T>
std::ostream& operator<<(std::ostream& out, Enumerator<T> &en){
    for(en.init();!en.isEnd();en.next()){
        out << en.current() << " ";
    }
    return out;
}


template<class T>
T sum(Enumerator<T> &en){
    T s = 0;
    for(en.init();!en.isEnd();en.next()){
        s += en.current();
    }
    return s;
}

int main()
{
    FileEnumerator<int> en("input.txt");
   // cout << en << endl;
    cout << sum(en);

    return 0;
}
