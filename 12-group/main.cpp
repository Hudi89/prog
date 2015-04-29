#include <iostream>
#include <fstream>
using namespace std;

class Flat{
    int dis;
    double area;
    int price;
public:

    int getDis(){
        return dis;
    }

    double getPriceDArea(){
        return price / area;
    }

    friend istream& operator>> (istream& in, Flat& dx);
    friend ostream& operator<< (ostream& out,const Flat& dx);
};

struct District{
    int dis;
    double avg;
};

istream& operator>> (istream& in, Flat& dx)
{
    in >> dx.dis >> dx.price >> dx.area;
    return in;
};
ostream& operator<< (ostream& out,const Flat& dx)
{
    out << dx.dis << " " << dx.price<< " " << dx.area;
    return out;
};

ostream& operator<< (ostream& out,const District& dx)
{
    out << dx.dis << " " << dx.avg;
    return out;
};

class SeqIn{
private:
    ifstream f;
    Flat dx;
    District dxOut;
    bool fuckYourself;
public:
    SeqIn(string filename){
        fuckYourself = false;
        f.open(filename.c_str());

        if(f.fail()){
            throw "NOT_EXISTS";
        }
    }
    void init(){
        f >> dx;
        next();
    }
    void next(){

        if(f.fail()){
            fuckYourself = true;
        }else{
            Flat temp;
            int c =1;
            double s = dx.getPriceDArea();
            while(f >> temp && temp.getDis()==dx.getDis())
            {
                s+=temp.getPriceDArea();
                c++;
            }

            dxOut.avg = s / c;
            dxOut.dis = dx.getDis();
            dx = temp;
        }

    }
    bool isEnd(){
        return fuckYourself;
    }
    District current(){
        return dxOut;
    }
};
int main()
{
    SeqIn si("input.txt");

    int M = 0;

    for(si.init();!si.isEnd();si.next()){
        cout << si.current() << endl;
        if(M < si.current().avg){
            M = si.current().avg;
        }
    }

    while(s1.isEnd() &&s2.isEnd()){
        if(==){
            out << max(M1,M2)
        }
        else if (<){
            Max
            out << Max
        }
        >
    }

    cout << "\tMax:" << M <<endl;
    return 0;
}
