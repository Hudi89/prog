/*
Feladat:
Olvassunk be számokat a konzolról amíg 0-t nem ír be a felhasználó, majd ezeket adjuk össze és írjuk ki a számok összegét.
*/

#include <iostream>
#include <vector>

using namespace std;

// függvények deklarációja, itt adjuk meg a fordítónak előre, hogy milyen függvények lesznek majd később definiálva
///////////////////////////////////

//beolvas számokat egy vektorba amíg 0-t nem ír be a felhasználó
void beolvas(vector<int> &myvector);
//összegzi egy vektor minden elemét és visszatér az összegével
//const kulcs szót kirakjuk, hogy garantljuk a hívónak, hogy nem fogjuk módosítani
//& jelet is berakjuk, hogy ne másoljon feleslegesen minden adatot 
int osszeg(const vector<int> &myvector);

int main ()
{
    vector< int > myvector;
    cout << "Kérlek add meg a bemenő számokat (0-t írva befejezheted a bevitelt):\n";
    beolvas(myvector);

    cout << "Az összeg " << osszeg(myvector) << "." <<endl;

    return 0;
}

void beolvas(vector<int> &v)
{
    int a;
	cin >> a;
    while(a != 0)
    {
    	v.push_back(a);
    	cin >> myint;
    }
}

int osszeg(const vector<int> &v)
{
    int s = 0;
    for (int a=0; a<v.size(); ++a)
    {
       s += v[a];
    }
    return s;
}
