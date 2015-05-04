#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


/*
Feladat: Melyik nap nem fogyott alkohol 

apróbetűs rész: Illetve nem került be a jegyzőkönyvbe.
*/

struct OrderItem{
	string name;
	int price;
};

istream& operator>>(istream &in, OrderItem &o){
	in >> o.name >> o.price;
	return in;
}
ostream& operator<<(ostream &out, const OrderItem &o){
	out << o.name << " " << o.price;
	return out;
}

class Order{
private:
	string date;
	vector<OrderItem> orders;
	
public:
	bool isAlcoholicOrder(){
		bool l = false;
		for(int a=0;a<orders.size();a++){
			
			if(orders[a].name == "Beer" ||
				orders[a].name == "Whisky"){
				l = true;
			}
		}
		return l;
	}
	
	string getDate(){
		return date;
	}	

	friend istream& operator>>(istream &in, Order &o);
	friend ostream& operator<<(ostream &out, const Order &o);
};

istream& operator>>(istream &in, Order &o){
	string temp;
	getline(in,temp);
	
	stringstream ss(temp);
	
	ss >> o.date;
	OrderItem orderItemTemp;
	o.orders.clear();
	while(ss >> orderItemTemp){
		o.orders.push_back(orderItemTemp);
	}
	
	return in;
}
ostream& operator<<(ostream &out, const Order &o){
	out << o.date;
	for(int a=0;a<o.orders.size();a++){
		out << " " << o.orders[a];
	}
	return out;
}


struct Day{
	string date;
	bool l;
};



class DayFileSeqIn{
private:
	ifstream f;
	Day dx;
	Order firstRow;
	
	bool vege;
public:
	DayFileSeqIn(string filename){
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
			Order temp;
			
			bool l = firstRow.isAlcoholicOrder();
			while(f >> temp && temp.getDate() == firstRow.getDate()){
				if(temp.isAlcoholicOrder()){
					l = true;
				}
			}
		
			dx.date = firstRow.getDate();
			dx.l = l;
		
			firstRow = temp;
		}
	}
	
	bool isEnd() const{
		return vege;
	}
	Day current() const{
		return dx;
	}
};

class FileSeqOut {
private:
	ofstream f;
public:

	FileSeqOut(string filename){
		f.open(filename.c_str());
	}
	void write(string d){
		f << d << endl;
	}
};

int main(){	
	DayFileSeqIn is1("bsd.txt");
	DayFileSeqIn is2("bsd2.txt");
	FileSeqOut os("csd.txt");

	is1.init();
	is2.init();
	while(!is1.isEnd()  && !is2.isEnd()){
		if(is1.current().date < is2.current().date){
			is1.next();
		}else if(is1.current().date > is2.current().date){
			is2.next();
		}else{ // == 
			if(is1.current().l && is2.current().l){
				os.write(is1.current().date);
			}
			is1.next();
			is2.next();
		}
	}
	
	return 0;
}
