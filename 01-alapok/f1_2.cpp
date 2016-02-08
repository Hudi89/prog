#include <iostream>
#include <vector>

using namespace std;

// függvények deklarációja, itt adjuk meg a fordítónak előre, hogy milyen függvények lesznek majd később definiálva
///////////////////////////////////

//beolvas számokat egy vektorba amíg 0-t nem ír be a felhasználó
void beolvas(vector<int> &myvector);
//összegzi egy vektor minden elemét és visszatér az összegével
int osszeg(const vector<int> &myvector);

int main ()
{
    //létrehozunk egy olyan vektort ami olyan vektorokat tartalmaz ami inteket tartalmaz :)
    vector< vector<int> > myvector;
    //ebbe összegezzük majd az eredményt
    int ossz;

    cout<<"szam"<<endl;

    // beolvassuk az [a] változóba, hogy 
    int a;
    cin>>a;

    // a nagy vektort megfelelő méretre állítjuk, ezzel létrehozva sok vector<int> típusú objektumot
    myvector.resize(a);

    //ciklusosan beolvasunk a vektorokba
    for(int i=0;i<a;++i)
    {
        beolvas(myvector[i]);
    }


    ossz=0;
    // összegzés tétele, úgy, hogy nem T[i]-t adjuk össze, hanem egy másik összegzési tétel eredményét 
    for (int i=0; i<myvector.size(); ++i)
    {
       ossz=ossz+osszeg(myvector[i]);
    }

    cout << ossz<<endl;

    return 0;
}

void beolvas(vector<int> &myvector)
{
    //kitöröljük a vektort, hogy tuti csak azok legyenek benne amiket a user beírt
    myvector.clear();
    cout << "Please enter some integers (enter 0 to end):\n";

    int myint;
    do
    {
       cin >> myint;

       if(myint!=0)//csak akkor adjuk hozzá a vektorhoz, ha nem 0-t írt be
       {
	    myvector.push_back (myint);
       }
    }
    while (myint);
}


int osszeg(const vector<int> &myvector)
{

    int ossz;
    ossz=0;

    for (int i=0; i<myvector.size(); ++i)
    {
       ossz=ossz+myvector[i];
    }

    return ossz;
}
