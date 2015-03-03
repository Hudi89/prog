#include <iostream>
#include <vector>
#include <fstream>
// fstream kell nekünk, hogy fájlt tudjunk kezelni

using namespace std;


// továbbfejlesztettük a beolvasás műveletet, hogy ne csak sima cin-ről olvasson be hanem bármilyen ios beviteli cuccról
void beolvas(vector<int> &myvector, istream &_stream);

// az összegzés helyett produktum
int szorzat(const vector<int> &myvector);

// Ezt a függvényt adjuk majd át a kereséseknek felételként
// eldöntjük, hogy a szám páros-e és logikai értékkel térünk vissza (bool)
bool parose(int a);

//kiválasztás tétele, vektoron végigmegyünk és kiválasztjuk az első béta feltételnek megfelelő paramétert
int kivalaszt(const vector<int> &_vektor, bool beta (int));

// keresés - az átadott vektoron végigmegyünk és visszatérünk vele, hogy találtunk-e béta feltételnek megfelelő értéket, ha igen akkor index változóba írjuk a választ
// index változót tudjuk módosítani, mivel & jel előtte van
bool kereses(const vector<int> &_vektor, bool beta (int), int &index);



int main ()
{
    //létrehozzuk a fájl beolvasására szolgáló változót
    fstream filestream;
    filestream.open ("test.txt");// megnyitjuk a fájlt

    vector<int> myvector;
    int index;

    //int myint;

    beolvas(myvector,filestream); // a módosított beolvas függvénnyel beolvastatjuk a file-ból az adatokat

    //mivel a keresésnek visszatérési értéke logikai, hogy találtunk-e feltételnek megfelelőt, ezért egy if-be nyugodtan berakhatjuk, mivel az if logikai eredményt vár
    //a fetltétel függvényt csak egyszerűen átadjuk (zárójel nélkül, mert ha zárójelet írunk akkor az a függvény meghívását jelentené)
    if ( kereses(myvector,parose,index) )
    {
	//hozzáadunk az index-hez egyet, mert a felhasználó számára nem a 0-tól indexelés a logikus
        cout << "elemszam: " << (index+1) << endl;
    }
    else
    {
        cout << "nincs talalat" << endl;
    }
    cout  << "sorzat: " << szorzat(myvector) << endl;

    return 0;

}



void beolvas(vector<int> &myvector, istream &_stream)
{
    myvector.clear();//kiürítjük a vektort
    
    int myint;
    do
    {
       _stream >> myint;// az input stream-ről (fstream vagy cin) beolvasunk egy int-et
       
       if(myint!=0)//csak akkor adjuk hozzá a vektorhoz, ha nem 0-t írt be
       {
	    myvector.push_back (myint);
       }
    }
    while (myint != 0);
}


int szorzat(const vector<int> &myvector)
{
    int ossz;
    ossz=1;//összegzés műveletéhez képest itt 1 az alap érték, mivel 0*a = 0 és 1*a=a minden a-ra
    for (int i=0; i<myvector.size(); ++i)
    {
       ossz=ossz*myvector[i];
    }
    return ossz;
}



bool parose(int a)
{
    // % a maradékos osztás, és ha elosztunk egy a számot b-vel és a maradék 0 akkor b osztója a-nak
    return (a%2 == 0);
    /*
    if (a%2 == 0) return true;
    else return false;

    */
}

int kivalaszt(const vector<int> &_vektor, bool beta (int))
{
    int i = 0;
    // egy ciklust csinálunk, ami addig megy amíg a feltételnek meg nem felel az aktuális elem
    while (!beta(_vektor[i]))
    {
	// a magban csak léptetünk semmi más dolgunk nincs
        i++; //i=i+1;
    }
    return i;
}


bool kereses(const vector<int> &_vektor, bool beta (int), int &index)
{
    int i = 0;
    // szintén ciklussal addig megyünk amíg a feltételnek meg nem felel az aktuális elem
    // csak hozzátesszük, hogy ha a ciklus végére ér akkor álljon le
    while (!beta(_vektor[i]) && i<_vektor.size())
    {
        i++;
    }


    if (i >= _vektor.size())// ha a ciklus azért állt le, mert a végére értünk akkor nem találtunk feltételnek megfelelő elemet
    {
        return false;//tehát hasissal térünk vissza és index-et nem módisítjuk
    }
    else // ha viszont megtaláltuk akkor
    {
        index = i; // index-ben eltároljuk hogy hol találtuk
        return true;// igazzal térünk vissza
    }
}
	
