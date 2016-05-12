#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Festival{
    int price;
    vector<string> genres;
    int length;
public:

    int getPrice() const {
        return price;
    }

    int getLength() const {
        return length;
    }
    bool isHaveJazz() const{
        bool l = false;
        int i = 0;
        while(!l && i < genres.size()){
            l = (genres[i] == "jazz");
            i++;
        }
        return l;
    }

    friend istream& operator>>(istream& in, Festival &o);
    friend ostream& operator<<(ostream& out,
                    const Festival &o);
};

istream& operator>>(istream& in, Festival &o){
    /*string line;
    getline(in,line);
    stringstream ss(line);
    ss >> o.price;
    string tempString;
    o.genres.clear();
    while(ss >> tempString){

        stringstream ss2(tempString);
        int tempInt;
        ss2 >> tempInt;
        if(ss2.fail()){
            o.genres.push_back(tempString);
        }else{
            o.length = tempInt;
        }
    }*/

    /*string line;
    getline(in,line);
    stringstream ss(line);
    //jazz dubstep 2
    ss >> o.price;
    string tempString;
    string tempString2;
    ss >> tempString;
    o.genres.clear();
    while(ss >> tempString2){
        o.genres.push_back(tempString);
        tempString = tempString2;
    }

    stringstream ss2(tempString);
    ss2 >> o.length;*/

    string line;
    getline(in,line);
    stringstream ss(line);

    ss >> o.price;
    string tempString;
    o.genres.clear();
    while(ss >> tempString){
        o.genres.push_back(tempString);
    }
    if(!o.genres.empty()){
        stringstream ss2(o.genres.back());
        ss2 >> o.length;
        o.genres.pop_back();
    }

    return in;
}

ostream& operator<<(ostream& out,
                    const Festival &o){
    out << o.price << " ";
    for(int a=0;a<o.genres.size();a++){
        out << o.genres[a] << " ";
    }
    out << o.length;
    return out;
}

class FestivalGroupedByPrice{
    int price;
    int sumLength;
    int count;
    int maxLength;
    bool isHaveJazz;
public:
    int getPrice() const {
        return price;
    }

    int getSumLength() const{
        return sumLength;
    }

    int getMaxLength() const{
        return maxLength;
    }

    bool getIsHaveJazz() const{
        return isHaveJazz;
    }

    float getAvgLength() const{
        return (float)sumLength / (float)count;
    }

    friend class FestivalGroupedByPriceSeqIn;
};

class FestivalGroupedByPriceSeqIn{
    ifstream f;
    bool isFinished;

    FestivalGroupedByPrice actualGroup;
    Festival actual;
public:
    FestivalGroupedByPriceSeqIn(string fname){
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
            actualGroup.price = actual.getPrice();
            actualGroup.sumLength = 0;
            actualGroup.count = 0;
            actualGroup.maxLength = actual.getLength();
            actualGroup.isHaveJazz = false;
            while(!f.fail() &&
                actual.getPrice() == actualGroup.price){

                actualGroup.sumLength += actual.getLength();
                actualGroup.count++;
                if(actual.getLength() > actualGroup.maxLength){
                    actualGroup.maxLength = actual.getLength();
                }
                if(actual.isHaveJazz()){
                    actualGroup.isHaveJazz = true;
                }
                f >> actual;
            }
        }
    }
    FestivalGroupedByPrice current() const{
        return actualGroup;
    }
    bool isEnd() const{
        return isFinished;
    }
};

int main()
{
    FestivalGroupedByPriceSeqIn en("input.txt");
    for(en.init();!en.isEnd();en.next()){
        cout << en.current().getPrice() << " " <<
                en.current().getIsHaveJazz() << endl;
    }
    return 0;
}
