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

istream& operator>>(istream& in,vector<vector<int> > &a) {
    int size;
    in >> size;
    vector<int> temp;
    for(int i = 0; i < size; ++i) {
        temp.clear();
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

int& max_vector(const vector<int> &a) {
    int error = -1;
    if(a.size() == 0) {
        return error;
    }
    int max_h = a[0];
    for(int i = 1; i < a.size(); ++i) {
        int temp = a[i];
        if(max_h < temp) {
            max_h = temp;
        }
    }
    return max_h;
}


int& max_osszeg_matrix(const vector<vector<int> > &a) {
    int error = -1;
    if(a.size() == 0) {
        return error;
    }
    int max_h = osszeg(a[0]);
    for(int i = 1; i < a.size(); ++i) {
        int temp = osszeg(a[i]);
        if(max_h < temp) {
            max_h = temp;
        }
    }
    return max_h;
}

int main()
{
    //==== VECTOR =====
    /*vector<int> v;
    cin >> v;
    cout << "Összeg: " << osszeg(v) << endl;

    cout << "DEBUG" << endl;
    for( int i = 0; i < v.size(); ++i ) {
        cout << v.at(i) << endl;
    }*/
    //=== MÁTRIX ====
    vector<vector<int> > matrix;
    cin >> matrix;

    cout << "Maximum: " << max_Osszeg_matrix(matrix) << endl;

    cout << "DEBUG" << endl;
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
