#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum Exception{
    NEGATIVE_COUNT,
    HIGH_VALUE,
    ZERO_VALUE,
    WRONG_INPUT
};

float sum(const vector<int> &v){
    float s = 0;
    for(int i = 0; i <v.size();i++){
        s = max(s + v[i] - 2.5,0.0);
    }
    return s;
}

bool linearSearch(const vector<int> &v){
    bool l = true;
    int i = 0;
    while(l && i < v.size()){
        l = v[i] >= 0;
        i = i + 1;
    }
    return l;
}

bool feladat(const vector<vector<int> > &m,
             int &ind){
    bool l = false;
    float max;
    for(int i=0;i<m.size();i++){
        if(linearSearch(m[i])){
         float actLife = sum(m[i]);
      //  cout << actLife << endl;
           if(!l){
              ind = i;
              l = true;
              max = actLife;
           }else{
              if(actLife > max){
                ind = i;
                max = actLife;
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
istream &operator >> (istream &in , vector<int> &t)
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
		if(t[i] > 100 || t[i] < -100){
			throw HIGH_VALUE;
		}
		if(t[i] == 0){
			throw ZERO_VALUE;
		}
    }
    return in;
}



template<class T>
void matrixBeolvas(std::istream &in, std::vector<std::vector<T> > &m ){
    int w,h;
    in >> w>> h;
    if(in.fail()){
        throw WRONG_INPUT;
    }
    if(w < 0 || h <0){
        throw NEGATIVE_COUNT;
    }
    m.resize(h);
    for(int a =0;a<h;a++){
        m[a].resize(w);
        for(int b = 0;b<w;b++){
            in >> m[a][b];
            if(in.fail()){
                throw WRONG_INPUT;
            }
        }
    }
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
		vector<vector<int> > m;
		ifstream f("input.txt");
		f >> m;
//		matrixKiir(cout,m);
		int ind;
		if(feladat(m,ind)){
			cout << (ind + 1) <<endl;
		}else{
			cout << "NM" <<endl;
		}
	}catch(Exception e){
		switch(e){
			case NEGATIVE_COUNT:cout << "NC" << endl; break;
			case HIGH_VALUE:cout << "HV" << endl; break;
			case ZERO_VALUE:cout << "ZV" << endl; break;
			case WRONG_INPUT:cout << "WI" << endl; break;
		}
	}
}

