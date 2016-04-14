#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum Exception{
    NEGATIVE_COUNT,
    WRONG_LENGTH,
    NOT_BINARY,
    WRONG_INPUT
};

int count(const vector<string> &v){
    int c = 0;
    for(int i = 0; i <v.size();i++){
        if(v[i][0] == '1' && (v[i][1] != '0' || v[i][2] != '0' || v[i][3] != '0')){ 
        	c++;
        }
    }
    return c;
}

bool linearSearch(const vector<string> &v){
    bool l = false;
    int i = 0;
    while(!l && i < v.size()){
        l = v[i][3] == '1';
        i = i + 1;
    }
    return l;
}

bool feladat(const vector<vector<string> > &m,
             int &ind){
    bool l = false;
    int max;
    for(int i=0;i<m.size();i++){
        if(linearSearch(m[i])){
         float act = count(m[i]);
     //   cout << act << endl;
           if(!l){
              ind = i;
              l = true;
              max = act;
           }else{
              if(act > max){
                ind = i;
                max = act;
              }
           }
        }
    }
    return l;
}

template<class T>
istream &operator >> (istream &in , vector<T> &t)
{
    int a;
    int n;

    in >> n;
    if(in.fail()){
        throw WRONG_INPUT;
    }

    if(n < 0){
        throw NEGATIVE_COUNT;
    }
    t.resize(n);
    for (int i=0; i<t.size(); ++i){
        in >> t[i];
    	if(in.fail()){
		    throw WRONG_INPUT;
		}
    }
    return in;
}
istream &operator >> (istream &in , vector<string> &t)
{
    int a;
    int n;

    in >> n;
    if(in.fail()){
        throw WRONG_INPUT;
    }

    if(n < 0){
        throw NEGATIVE_COUNT;
    }
    t.resize(n);
    for (int i=0; i<t.size(); ++i){
        in >> t[i];
    	if(in.fail()){
		    throw WRONG_INPUT;
		}
		if(t[i].length() != 4){
			throw WRONG_LENGTH;
		}
		
		for(int a=0;a<4;a++){
			if(t[i][a] != '0' && t[i][a] != '1'){
				throw NOT_BINARY;
			}
		}
    }
    return in;
}

template<class T>
void matrixKiir(std::ostream &out, std::vector<std::vector<T> > &m ){
    if(m.size() == 0){
        out << "0 ";
    }else{
        out << m[0].size() << " ";
    }

    out << m.size() << std::endl;
    for(int a =0;a<m.size();a++){
        for(int b = 0;b<m[0].size();b++){
            out << m[a][b] << " ";
        }
        out << std::endl;
    }
}

int main(){
	try{
		vector<vector<string> > m;
		ifstream f("input.txt");
		f >> m;
		//matrixKiir(cout,m);
		int ind;
		if(feladat(m,ind)){
			cout << (ind + 1) <<endl;
		}else{
			cout << "NM" <<endl;
		}
	}catch(Exception e){
		switch(e){
			case NEGATIVE_COUNT:cout << "NC" << endl; break;
			case WRONG_LENGTH:cout << "WL" << endl; break;
			case NOT_BINARY:cout << "NB" << endl; break;
			case WRONG_INPUT:cout << "WI" << endl; break;
		}
	}
}

