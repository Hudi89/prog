#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;



enum Exceptions {
	NPC,IS,LPN,WI
};

istream& operator>>(istream& in, vector<vector<string> > &v){
	int n,m;
	in >> n;
	if(in.fail()){
		throw WI;
	}
	if(n <= 0){
		throw NPC;
	}
	v.resize(n);
	for(int a=0;a<n;a++){
		in >> m;
		if(in.fail()){
			throw WI;
		}
		if(m <= 0){
			throw NPC;
		}
		v[a].resize(m);
		for(int b=0;b<m;b++){
			in >> v[a][b];
			if(!isalpha(v[a][b][0])){
				throw IS;
			}
			if(v[a][b].size() > 10){
				throw LPN;
			}

		}
	}
	return in;
}

ostream& operator<<(ostream& out, const vector<vector<string> > &v){
	
	out << v.size() << endl;
	for(int a=0;a<v.size();a++){
		out << v[a].size() << " ";
		for(int b=0;b<v[a].size();b++){
			out << " " << v[a][b];
		}
		out << endl;
	}

	return out;
}

bool keres(const vector<string> &v, int &ind){
	bool l = 0;
	for(int a=0;a<v.size()&&!l;a++){
		if(v[a] == "orderEnd"){
			ind = a; //Csak akkor állítjuk át a kapott változót, ha találtunk is valamit
			l = true;
		}else if(v[a] == "orderEndQ"){
			ind = a - 2;
			l = true;
		}
	}
	return l;
}

bool feltMax(const vector<vector<string > >&v,int &ind){
	bool l;
	float M;
	for(int a=0;a<v.size();a++){
		int temp;
		bool ok = keres(v[a],temp);
		if(!ok || v[a][0] != "landing"){}
		else{
		//	cout << a << ". megfelel: " << temp << endl;
			if(!l){
				l = true;
				ind = a;
				M = temp;
			}else{
				if(temp < M){
					M = temp;
					ind = a;
				}
			}
		}
	}	
	return l;
}



int main(){
	ifstream f("input.txt");
	vector<vector<string> > v;
	try{
		int ind;
		f >> v;
//		cout  << v;
		if(feltMax(v,ind)){
			cout << ind + 1 << endl;
		}else{
			cout << "NM" << endl;
		}
	}catch(Exceptions e){
		switch(e){
			case NPC:cout << "NPC" << endl;break;
			case IS:cout << "IS" << endl;break;
			case LPN:cout << "LPN" << endl;break;
			case WI:cout << "WI" << endl;break;
			default:
				throw e;
				break;
		}
	}
	
	
}
