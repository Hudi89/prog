#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Goat{
    string color;
    vector<float> milkHistory;
    float weight;
public:
    friend istream& operator>>(istream& in, Goat &g);
    friend ostream& operator<<(ostream& out, const Goat &g);

    string getColor() const { return color; }
    float getWeight() const { return weight; }
    bool isMilkKing() const{
        bool l = true;
        int i = 0;
        while(l && i < milkHistory.size()){
            l = (milkHistory[i] > 0);
            i++;
        }
        return l;
    }
};

istream& operator>>(istream& in, Goat &g){
    string temp;
    getline(in,temp);

    stringstream ss(temp);
    // ss<<temp;

    ss >> g.color;
    float tempFloat;
    float tempFloat2;

    g.milkHistory.clear();
    ss>>tempFloat;
    while(ss >> tempFloat2){
        g.milkHistory.push_back(tempFloat);
        tempFloat = tempFloat2;
    }
    g.weight = tempFloat;
    return in;
}
ostream& operator<<(ostream& out, const Goat &g){
    out << g.color << " ";
    for(int a=0;a<g.milkHistory.size();a++){
        out << g.milkHistory[a] << " ";
    }
    out << g.weight;
    return out;
}

class GoatGroupedByColorEnumerator;

class GoatGroupedByColor{
    string color;
    float sumWeight;

    int weightNumber;
    bool allMilkKing ;
public:
    string getColor() const { return color; }
    float getSumWeight() const { return sumWeight; }
    float getAvgWeight() const {
        return sumWeight / (float)weightNumber;
    }
    bool isAllMilkKing() const{
        return allMilkKing;
    }

    friend class GoatGroupedByColorEnumerator;
};

class GoatGroupedByColorEnumerator{
    ifstream f;
    Goat actual;
    GoatGroupedByColor actualGrouped;

    bool isFinished;
public:
    GoatGroupedByColorEnumerator(string fname){
        f.open(fname.c_str());
        isFinished = false;
    }
    void init(){
        f >> actual;
        next();
    }
    void next(){
        if(f.fail()){
           isFinished = true;
        }else{
            actualGrouped.color = actual.getColor();
            actualGrouped.sumWeight = 0;
            actualGrouped.weightNumber = 0;
            actualGrouped.allMilkKing = true;
            while(actualGrouped.color == actual.getColor()
                  &&
                  !f.fail()){
                actualGrouped.sumWeight += actual.getWeight();
                actualGrouped.weightNumber++;
                if(!actual.isMilkKing()){
                    actualGrouped.allMilkKing = false;
                }
                f >> actual;
            }
        }
    }
    GoatGroupedByColor current() const{
        return actualGrouped;
    }
    bool isEnd() const{
       return isFinished;
    }
};

int main()
{
    GoatGroupedByColorEnumerator en("input.txt");
    string maxColor;
    float sumWeight ;

    bool l=false;
    for(en.init();!en.isEnd();en.next()){
        if(en.current().isAllMilkKing()){
            if(!l){
                maxColor = en.current().getColor();
                sumWeight = en.current().getSumWeight();
                l = true;
            }else{
                if(en.current().getSumWeight() > sumWeight){
                    maxColor = en.current().getColor();
                    sumWeight = en.current().getSumWeight();
                }
            }
        }
    }
    cout << maxColor << endl;
    return 0;
}
