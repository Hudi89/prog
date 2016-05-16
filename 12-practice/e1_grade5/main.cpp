#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Deposit{
    string name;
    string date;
    int amount;
public:

    string getName() const {
        return name;
    }

    string getDate() const {
        return date;
    }
    
    int getAmount() const{
        return amount;
    }

    friend istream& operator>>(istream& in, Deposit &o);
    friend ostream& operator<<(ostream& out,
                    const Deposit &o);
};

istream& operator>>(istream& in, Deposit &o){   
    string line;
    getline(in,line);
    stringstream ss(line);

    string tempString;
    
    vector<string> nameTemp; 
   
    while(ss >> tempString){
        nameTemp.push_back(tempString);
    }
    if(!nameTemp.empty()){
        stringstream ss2(nameTemp.back());
        ss2 >> o.amount;
        nameTemp.pop_back();
    }
    
    if(!nameTemp.empty()){
        o.date = nameTemp.back();
        nameTemp.pop_back();
    }else{//Ha nem tudtuk a két adatunkat beszedni akkor failelünk az istream-nél!
        in.setstate(std::ios::failbit);
    }
    
    o.name = "";
    for(int a=0;a<nameTemp.size();a++){
        o.name += (a>0?" ":"") + nameTemp[a];
    }
    return in;
}

ostream& operator<<(ostream& out,const Deposit &o){
    out << o.name << " " << o.date << " " << o.amount;
    return out;
}

class DepositGroupedByPrice{
    string name;
    int sumAmount;
    bool payedDifferent;
public:
    string getName() const {
        return name;
    }

    int getSumAmount() const{
        return sumAmount;
    }

    bool isPayedAlwaysDifferent() const{
        return payedDifferent;
    }
    
    DepositGroupedByPrice operator +(const DepositGroupedByPrice& other) const{
        //Lehet hibát kezelni, de végülis nem követelmény
//        if(name != other.name){
//            throw INVALID...
//        }
        DepositGroupedByPrice ret;
        ret.name = name;
        ret.sumAmount = sumAmount + other.sumAmount;
        
        //Akkor fizetett mindig mást, ha mindkét fájlban mindig mást fizetett egymás után
        ret.payedDifferent = payedDifferent && other.payedDifferent;
        
        return ret;
    }
    
    
    friend class DepositGroupedByPriceSeqIn;
    friend ostream& operator<<(ostream& out, const DepositGroupedByPrice &o);
};

 
ostream& operator<<(ostream& out, const DepositGroupedByPrice &o){
    out << o.name << " " << o.sumAmount;
}


class DepositGroupedByPriceSeqIn{
    ifstream f;
    bool isFinished;

    DepositGroupedByPrice actualGroup;
    Deposit actual;
public:
    DepositGroupedByPriceSeqIn(string fname){
        f.open(fname.c_str());
    }
    void init(){
        f >> actual;
        isFinished = false;
        next();
    }
    void next(){
        if(f.fail()){
            isFinished = true;
        }else{
            int lastAmount;
            bool isFirst = true;
        
            actualGroup.name = actual.getName();
            actualGroup.sumAmount = 0;
            actualGroup.payedDifferent = true;
            
            while(!f.fail() && actual.getName() == actualGroup.name){

                actualGroup.sumAmount += actual.getAmount();
                
                //Ha nem első sor, tehát van mivel összehasonlítani
                if(!isFirst && actual.getAmount() == lastAmount){
                    actualGroup.payedDifferent = false;
                }
                
                lastAmount = actual.getAmount();

                isFirst = false;
                f >> actual;
            }
        }
    }
    DepositGroupedByPrice current() const{
        return actualGroup;
    }
    bool isEnd() const{
        return isFinished;
    }
    
};
 
 
template<class T>
class SeqOutFileAndConsole{
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
    DepositGroupedByPriceSeqIn in1("input1.txt");
    DepositGroupedByPriceSeqIn in2("input2.txt");
    
    SeqOutFileAndConsole<DepositGroupedByPrice> out("out.txt");
    in1.init();
    in2.init();
    
    string differFlat;
    bool foundDifferFlat = false;
    
    while(!in1.isEnd() || !in2.isEnd()){
        DepositGroupedByPrice act;
        
        if( in2.isEnd() ||
               (
               !in1.isEnd() && in1.current().getName() < in2.current().getName()
               )
           ){
            act = in1.current();
            in1.next();
        }else if(in1.isEnd() ||
                 (
             !in2.isEnd() && in2.current().getName() < in1.current().getName())
                 ){
                 
            act = in2.current();
            in2.next();
        }else{//in1.current().getName() == in2.current().getName()
            act = in1.current() + in2.current();
            in1.next();
            in2.next();
        }
        out.write(act);
        if(!foundDifferFlat && act.isPayedAlwaysDifferent()){
            differFlat = act.getName();
            foundDifferFlat = true;
        }
    }
        
    
    if(foundDifferFlat){
        cout << "Sosem fizetett be ugyanannyit: " << differFlat << endl;
    }else{
        cout << "Mindenki volt hogy ugyanannyit fizetett be. " << endl;
    }
    
    return 0;
}
