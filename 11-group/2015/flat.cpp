#include <iostream>
#include <fstream>

using namespace std;


/*
Kerület Ár AlapTerület
1 1 1
1 1 1 
1 2 3 
2 4 1 
2 2 1 
2 4 1 
3 1 1 
5 2 1 

Feladat: Határozzuk meg, hogy melyik kerületben a legalacsonyabb a nm/Ft!

*/

class Flat{
private:
	int dist;
	int price;
	double area;
	
public:
	
	double getPriceDArea() const{
		return price / area;
	}
	
	int getDist() const{
		return dist;
	}

	friend istream& operator>>(istream &in, Flat &o);
	friend ostream& operator<<(ostream &out, const Flat &o);
};

istream& operator>>(istream &in, Flat &o){
	in >> o.dist >> o.price >> o.area;
	return in;
}
ostream& operator<<(ostream &out, const Flat &o){
	out << o.dist << " " << o.price << " "  << o.area;
	return out;
}


struct District{
	int dist;
	double avg;
};



class DistrictFileSeqIn{
private:
	ifstream f;
	District dx;
	Flat firstRow;
	
	bool vege;
public:
	DistrictFileSeqIn(string filename){
		f.open(filename.c_str());
	}
	
	void init(){
		f >> firstRow;
		next();
	}
	void next(){
		if(f.fail()){
			vege = true;
		}else{
			Flat temp;
			int c = 1; 
			double s = firstRow.getPriceDArea();
		
			while(f >> temp && temp.getDist() == firstRow.getDist()){
				s += temp.getPriceDArea();
				c++;
			}
		
			dx.dist = firstRow.getDist();
			dx.avg = s / c;
		
			firstRow = temp;
		}
	}
	
	bool isEnd() const{
		return vege;
	}
	District current() const{
		return dx;
	}
};

int main(){
	DistrictFileSeqIn is("asd.txt");
	
	is.init();
	int ind = is.current().dist;
	double m = is.current().avg;
	for(;!is.isEnd();is.next()){
		if(m > is.current().avg){
			m = is.current().avg;
			ind = is.current().dist;
		}
		cout << is.current().dist << " " << is.current().avg << endl;
	}
	cout << endl << ind << ":" << m << endl;

	return 0;
}
