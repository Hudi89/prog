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
    in >> o.name >> o.date >> o.amount;
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
    
    friend class DepositGroupedByPriceSeqIn;
};

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
 
int main()
{
    DepositGroupedByPriceSeqIn en("input.txt");
    string differFlat;
    bool foundDifferFlat = false;
    for(en.init();!en.isEnd();en.next()){
        cout << en.current().getName() << " " << en.current().getSumAmount() << endl;
        if(!foundDifferFlat && en.current().isPayedAlwaysDifferent()){
            differFlat = en.current().getName();
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
