#include <iostream>
#include <vector>

using namespace std;

istream& operator>>(istream& in, vector<vector<int> > &v){
    int n,m;
    in >> n >> m;
    v.resize(n);
    for(int a=0;a<v.size();a++){
        v[a].resize(m);
        for(int b=0;b<v[a].size();b++){
            in >> v[a][b];
        }
    }
    return in;
}
ostream& operator<<(ostream& out, vector<vector<int> > &v){
    out << v.size() << ' ';
    if(v.size()>0){
        out << v[0].size();
    }else{
        out << 0;
    }
    cout << endl;

    for(int a=0;a<v.size();a++){
        for(int b=0;b<v[a].size();b++){
            out << v[a][b];
            if(b < v[a].size()-1){
                out << ' ';
            }
        }
        out << endl;
    }
    return out;
}
int main()
{
    vector<vector<int> > m;
    cin >> m;
    cout << m;
    return 0;
}
