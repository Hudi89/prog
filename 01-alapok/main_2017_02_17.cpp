#include <iostream>
#include <vector>

using namespace std;

void beolvas(vector<int> &v, int size_v) {
	int temp;
	for(int i = 0; i < size_v; ++i) {
		cin >> temp;
		v.push_back(temp);
	}
}

int osszeg(const vector<int> &v) {
	int s = 0;
	for(int i = 0; i < v.size(); ++i) {
		s = s + v.at(i);
	}
	return s;
}

int szamlal(const vector<int> &v) {
	int c = 0;
	for(int i = 0; i < v.size(); ++i) {
		if(v.at(i)%2 == 0) {
			c = c + 1;
		}
	}
	return c;
}

int main()
{
	vector<int> v;
	int size_v;
	cout << "Kerem a vector meretet: ";
	cin >> size_v;
	beolvas(v,size_v);
	cout << "A szamok osszege a vectorban: " << osszeg(v) << endl;
	cout << "A paros szamok szama a vectorban: " << szamlal(v) << endl;
	
	cout << "DEBUG" << endl;
	for(int i = 0; i < size_v; ++i) {
		cout << v.at(i) << " ";
	}
	return 0;
}
