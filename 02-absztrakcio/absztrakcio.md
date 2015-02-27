# Általánosítsunk

Előző óra végén eljutottunk egy egyszerű beolvasáshoz, amit most megpróbálunk általánosítani, ami a következő:

```c++
void beolvas(vector<int> &v){
  int a;
  cin >> a;
  
  while(a != 0){
    v.push_back(a);
    cin >> a;
  }
}
```

Alapvetően ha mondatként akarjuk ennek a függvénynek a funkcióját kimondani, akkor egy kis célzott gondolkodás után:) eljuthatunk addig az előző példában látható függvényünknél, hogy: Egész számokat a konzolról beolvas vektorba.
Ezt a mondatot megpróbáljuk általánosítani, amivel végsősoron a függvény funkcióját fogjuk absztraktabbá tenni.

Valamilyen típusú számokat olvasunk be egy valamilyen folyamról vektorba.
A vektor szót azért általánosításával nem foglalkozunk, mert az egyelőre túl bonyolult lenne, de más nyelvekben nagyon szépen általánosítható ez a része is.

## Template

Az első lépés amit általánosítunk, az az, hogy ne csak egész számokat tudjon beolvasni a függvényünk. Ebben segítségünkre lesz a c nyelv egy hasznos része, az úgynevezett template, amit pár egyszerű módosítással megtehetünk. A lényeg, hogy az a célunk, hogy megadható legyen, hogy az adott függvény milyen típussal működjön.
Ha a beolvasást akarjuk általánosítani, akkor egy függő paraméter kell, ami az lesz, hogy milyen típusokat olvassunk be a konzolról.  Ebben az esetben annyi dolgunk van, hogy a függvény neve elég odaírjuk, hogy ```c++template<class T> ``` (általában az előtte lévő sorba szoktuk írni, hogy jobban átlátható legyen). Ha ezt a sort hozzáadtuk akkor mindenhol a függvényben az adott típust amit általánosítani akarunk ki kell cserélnünk ```c++T```-re. (Logikusan ha ```c++template<class Valami> ``` a template paraméter akkor a ```c++Valami```-t kell mindenhova írni.

```c++
template<class T>
void beolvas(vector<T> &v){
  T a;
  cin >> a;
  
  while(a != 0){
    v.push_back(a);
    cin >> a;
  }
}
```
Ez a kód működni fog vector<int> vector<float> típusokra, mert ekkor végigfogja nézni az adott nevű függvényeket és próbál megfelelő szignatúrájút találni. Ha vector<int>-el akarjuk meghívni akkor látja, hogy van olyan hogy vector<T> paraméterű. Ekkor úgy fogja megcsinálni a függvényt, hogy a templateből csinál egy másolatot úgy, hogy minden T helyére berakja a megfelelő típust.

```c++
vector<int> v;
beolvas(v);
```

A függvénytörzsben látható egy cin >> a; itt esetünkben számít, hogy milyen típusú a T, mivel nem mindegy, hogy intet, floatot vagy pl. stringet akarunk beolvasni. De szerencsénkre ezek mind megvannak írva, ez alapján mondhatjuk azt, hogy minden olyan vectorra működni fog ez a függvény ami olyan elemeket tartalmaz amire az STL-ben van >> operátor. (Tehát pl. amit be tudunk olvasni konzolról)

Note: Több template paraméter is használható: ```c++template<class T,class T2> ``` hasonlóan mint a paraméterek.
Note: Programozási nyelvek c++ tárgyon lesz részletesebben a template használata.

### istream

A függvényünk funkciójának a mondatát általánosítva tovább megyünk arra, hogy ne csak konzolról lehessen beolvasni, hanem valamilyen folyamról. Progalapon megismerkedtetek a fájlbeolvasással és a konzolról való beolvasással.

#### Fájlbeolvasás 
Fájlbeolvasáshoz két dologra van szükségünk: 
* includeolni az fstreamet
* létrehozni egy ifstreamet ami majd kezeli a fájlt aminek az úgynevezett konstruktorában megadjuk a fájl nevét

Ezután már ugyanúgy mint a cin-el tudunk dolgozni.
```c+
#include <fstream>

int main(){
  ifstream f("asd.txt");
}
```

Figyeljünk arra mindenképp, hogy ha a sulis gépeken hozunk létre egy fájlt és beírjuk, hogy .txt a végére akkor a létrejött fájl neve valami.txt.txt lesz, mivel a windows elrejti a kiterjesztéseket.

#### Honnan fogja olvasni a fájlt?
Alapvetően a válasz egyszerű, ahol fut a programunk, viszont ha CodeBlocks-ban futtatjuk a programot akkor az úgynevezett munkakönyvtár, ahol futni fog a program az a projektfájl mappája, így ha valami inputot be akarunk olvasni relatív útvonallal (pl.: "valami.txt") akkor azt oda tegyük.

#### istream

Rögtön láthatjuk is az utat az általánosítás felé, mivel a cin meg az ifstream nagyon hasonlóan működik és mivel az STL-t nem csak úgy összedobták valószínűleg megfelelően van megcsinálva hozzá, hogy tudjunk általánosítani.
Keressünk is rá, hogy mi is az a cin:
Ha googlebe beírjuk, hogy "cin c++" akkor első találatként eljuthatunk a http://www.cplusplus.com/reference/iostream/cin/ oldalra, viszont itt nem látunk olyat, hogy >> operátor. Ha elkezdjük olvasni a szöveget, akkor rátalálhatunk a válaszra: "Object of class istream", tehát ez egy objektuma az istream osztálynak, azaz egy példánya. Tehát akkor valójában azt kell néznünk nem az istream-et, mert a cin amikor pl. a v vektorunknak a funkcióit akarjuk megnézni akkor sem arra keresünk rá hogy "v c++" :P . Így végsősoron eljutnk a http://www.cplusplus.com/reference/istream/istream/ linkhez.
Itt már láthatjuk az operator>>-at, viszont ha az oldal tetejét nézzük akkor láthatunk egy ábrát, ahol mindenféle nyilak vannak, ez az úgynevezett osztályhierarchiát hivatott megadni. A lényeg annyi, hogy amiből mutat a nyíl az rendelkezik minden tulajdonsággal (esetünkben minden függvénnyel) amivel az rendelkezik amibe mutat a nyíl. Innen láthatjuk, hogy az **ifstream egy speciális istream**. 
Tehát a cin egy példánya az istream-nek, az ifstream meg egy speciális istream, tehát mindkettő istream! 

#### De mi az a származás?

Gondoljunk bele: amikor csinálunk egy valamilyen funkciót ellátó osztályt (később majd fogunk csinálni), aztán szeretnénk csinálni egy nagyon hasonlót, de kicsit másra jót, akkor ebben az esetben minden függvényt lekéne másolni és így egy csomó dolog többször szerepelne a kódunkban, ennek fő hátrányai, hogy ha át kell írni (mert pl. hibát találtunk benne) akkor több helyen kell majd átírni, átláthatatlanabb lesz a kód, illetve több sor mindig veszélyesebb.
Erre jött létre az úgynevezett származtatás, amikor pl. van egy olyan osztályunk mint a vector aminek van operator[]-je, ekkor ha kiakarjuk bővíteni egy függvénnyel akkor fogjuk és származtatjuk és csak azt az egy függvényt írjuk meg.
Amiből származtatunk azt nevezzük **ős**-nek.
Ami származik egy adott osztályból azt hívjuk **gyerek**-nek

Részletesebben: OAF

#### A végeredmény

De hogy is tudjuk akkor ezt csinálni? Van egy fájl olvasónk ami egy ifstream példánya, ami viszont az istream-ből származik és van egy cin-ünk ami egy istream példány.
Egyértelmű: Felveszünk még egy paramétert a függvényünkbe amin keresztül majd átadjuk, hogy mely folyamról olvassa be azt a vektort és ahol eddig a cin-t használtuk a függvényünkben ott most már ezt az istream-et fogjuk használni.

```c++
template<class T> 
void beolvas(istream &in, vector<T> &v){
  T a;
  in >> a;
  
  while(a != 0){
    v.push_back(a);
    in >> a;
  }
}
```

Ezt a függvényt már kényelmesen tudjuk a main-ből hívni akár cin-el akár egy ifstream példánnyal. pl.:
```c++
int main(){
  vector<int> v;
  vector<float> v2;
  
  beolvas(cin,v);
  
  ifstream f("asd.txt"); //Megnyitok egy asd.txt nevű fájlt
  
  beolvas(f,v); // átadom a beolvasnak, hogy a fájlból olvasson be
  
  return 0;
}
```

## Csináljuk szépen

Ha mindenfelé nézünk olyanokat láthatunk, hogy ```c++cin>> a``` ami szép és jó és érdemes lenne ezt a stílust át venni. De hogy tudjuk ezt megtenni? Nagyon egyszerűen, mivel a C++-ban egyszerű függvényekként defininálhatóak operátorok. Annyi a dolgunk, hogy létrehozunk egy olyan függvényt, aminek az a neve, hogy ```c++operator>>(istream&,vector<T>&)```, tehát kb. csak át kell neveznünk a beolvas függvényünket egy különbséggel. Itt most nekünk kelleni fog visszatérési érték.


Note: Ha bal és jobb oldalt is egy alap típus(pl. int) áll, akkor azt nem fogja engedni a fordító.

Csinájuk meg mi is a sajt operátorunkat.
Láncolás szabálya. cin >> a >> b;


```c++
template<class T> 
istream& operator>>(istream &in, vector<T> &v){
  T a;
  in >> a;
  
  while(a != 0){
    v.push_back(a);
    in >> a;
  }
  return in;
}
```

# Feladat
1. Alakítsuk úgy a beolvasó operátorunkat, hogy ne 0-ig olvassa ezt a T típust, hanem int-ek esetében annyi legyen, hogy először beolvassa hány elem lesz a vektorban, majd sorban az elemek. pl.: 3 1 2 1 vagy 4 1 1 1 2. Végül számolja meg, hogy a beolvasott vektor elemei között mennyi páros van. 
