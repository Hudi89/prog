#include <iostream>
#include <vector>

using namespace std;

istream& operator>>(istream& in,vector<int> &a) {
    int size;
    in >> size;
    int temp;
    for (int i = 0; i < size; ++i) {
        in >> temp;
        a.push_back(temp);
    }
    return in;
}

int& szamol(const vector<int> &v) {
    int c = 0;
    for(int i = 0; i < v.size(); ++i) {
        if(v.at(i)%2 == 0) {
            c = c + 1;
        }
    }
    return c;
}

int& osszeg(const vector<int> &v)
{
    int s = 0;
    for(int i = 0; i < v.size(); ++i) {
        s = s + v.at(i);
    }
    return s;
}

int main()
{
    vector<int> v;
    cin >> v;
    cout << "Összeg: " << osszeg(v) << endl;

    cout << "DEBUG" << endl;
    for( int i = 0; i < v.size(); ++i ) {
        cout << v.at(i) << endl;
    }
    return 0;
}
