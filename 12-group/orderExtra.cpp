#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


/*
Ugyanaz mint az order.cpp csak operátorokkal és rövidítésekkel.
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


	bool operator==(Order &o2){
		return date == o2.date;
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
			while(f >> temp && temp == firstRow){
				if(temp.isAlcoholicOrder()){
					l = true;
				}
			}
		
			dx.date = firstRow.getDate();
			dx.l = l;
		
			firstRow = temp;
		}
	}
	
	operator bool() const{
		return !isEnd();
	}

	void operator++(){
		next();
	}
	
	void operator +=(int a){
		for(int b=0;b<a;b++){
			next();
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

bool operator<(const Day& d1, const Day& d2){
	return d1.date < d2.date;
}
bool operator>(const Day& d1, const Day& d2){
	return d1.date > d2.date;
}


bool operator<(const DayFileSeqIn& s1, const DayFileSeqIn& s2){
	return s1.current() < s2.current();
}
bool operator>(const DayFileSeqIn& s1, const DayFileSeqIn& s2){
	return s1.current() > s2.current();
}

int main(){	
	DayFileSeqIn is1("bsd.txt");
	DayFileSeqIn is2("bsd2.txt");
	FileSeqOut os("csd.txt");

	is1.init();
	is2.init();
	while(is1 && is2){
		if(is1 < is2){
			++is1;
		}else if(is1 > is2){
			++is2;
		}else{ // == 
			if(is1.current().l && is2.current().l){
				os.write(is1.current().date);
			}
			++is1;
			++is2;
		}
	}
	
	return 0;
}
