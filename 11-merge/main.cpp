#include <iostream>
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
        //A fájl elejére ugrunk. Ezzel a funkciót is megvalósítjuk, hogy újra 
        //inicializálás esetében a szekvencia előről kezdődik (Ezt nem várjuk el amúgy)
        f.seekg(0);
        
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
    FileEnumerator<Adatok> si1("in1.txt");
    FileEnumerator<Adatok> si2("in2.txt");
    ConsoleSeqOut<Adatok> so;
    si1.init();
    si2.init();

    //Metszet
    while (!(si1.isEnd() || si2.isEnd())) {
        if (si1.current().getName() == si2.current().getName()) {
            so.write(si1.current());
            si1.next();
            si2.next();
        } else if (si1.current().getName() < si2.current().getName()) {
            si1.next();
        }
        else {
            si2.next();
        }

    }
    return 0;
}
