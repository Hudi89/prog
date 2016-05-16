#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Pancake{
    float radius;
    vector<string> filling;
    float tastyFactor;
public:

    float getRadius() const { return radius; }
    float getTastyFactor() const { return tastyFactor; }

    bool isHaveTuros() const{
        bool l = false;
        int i = 0;
        while(!l && i < filling.size()){
            l = (filling[i] == "turo");
            i++;
        }
        return l;
    }

    friend istream& operator>>(istream& in, Pancake &o);
    friend ostream& operator<<(ostream& out,
                     const Pancake &o);
};
//kolbasz erosPista vanilia 1
istream& operator>>(istream& in, Pancake &o){
    string temp;
    getline(in,temp);
    stringstream ss(temp);
    //ss << temp;

    ss >> o.radius;


   /*  o.filling.clear();
    string tempString;
    while(ss >> tempString){
        stringstream ss2(tempString);
        ss2 >> o.tastyFactor;
        if(ss2.fail()){
           o.filling.push_back(tempString);
        }
    }*/
/*
    o.filling.clear();
    string tempString;
    string tempString2;
    ss >> tempString;
    while(ss >> tempString2){
        o.filling.push_back(tempString);
        tempString = tempString2;
    }
    stringstream ss2(tempString);
    ss2 >> o.tastyFactor;*/

    o.filling.clear();
    string tempString;
    while(ss >> tempString){
        o.filling.push_back(tempString);
    }

    if(!o.filling.empty()){
        stringstream ss2(o.filling.back());
        ss2 >> o.tastyFactor;

        o.filling.pop_back();
    }
    return in;
}
ostream& operator<<(ostream& out,
                     const Pancake &o){
    out << o.radius << " ";
    for(int a=0;a<o.filling.size(); a++){
        out << o.filling[a] << " ";
    }
    out << o.tastyFactor;
    return out;
}




class PancakeGroupedBySize{
    float radius;
    float sumTastyFactor;
    int count;
    bool haveTuros;
public:

    float getRadius() const{
        return radius;
    }
    float getAvgTastyFactor() const{
        return sumTastyFactor /(float) count;
    }

    bool isHaveTuros() const{
        return haveTuros;
    }

    friend class PancakeGroupedBySizeSeqIn;
    friend ostream& operator <<(ostream& tokmindegy,
        const PancakeGroupedBySize& dzs);
};

ostream& operator <<(ostream& tokmindegy,
        const PancakeGroupedBySize& dzs){
    tokmindegy << dzs.radius << " " << dzs.sumTastyFactor/(float)dzs.count;
    return tokmindegy;
}

class PancakeGroupedBySizeSeqIn{
    ifstream f;
    Pancake actual;
    PancakeGroupedBySize actualGroup;
    bool isFinished;
public:
    PancakeGroupedBySizeSeqIn(string fname){
        f.open(fname.c_str());
    }
    void init(){
        f >> actual;
        next();
        isFinished = false;
    }
    void next(){
        if(f.fail()){
            isFinished = true;
        }else{
            actualGroup.radius = actual.getRadius();
            actualGroup.sumTastyFactor = 0;
            actualGroup.count = 0;
            actualGroup.haveTuros = false;

            while(!f.fail() &&
                actual.getRadius() == actualGroup.radius){
                actualGroup.sumTastyFactor +=
                    actual.getTastyFactor();
                actualGroup.count++;
                if(actual.isHaveTuros()){
                    actualGroup.haveTuros = true;
                }
                f >> actual;
            }
        }
    }
    bool isEnd() const{
        return isFinished;
    }
    PancakeGroupedBySize current() const{
        return actualGroup;
    }
};



int main()
{
    PancakeGroupedBySizeSeqIn en("input.txt");
    for(en.init();!en.isEnd();en.next()){
            cout << en.current().getRadius() << " " <<
                en.current().getAvgTastyFactor()<<" " <<
                (en.current().isHaveTuros()?"TUROS":"NEM TUROS") << endl;
      //  cout << en.current() << endl;
    }
    return 0;
}
