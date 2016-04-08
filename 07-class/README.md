# Komplex számhalmaz

## Struktúra

Ha létre akarunk hozni egy új adattípust, már korábbi tanulmányaink során láthattuk, hogy a
```
[Új típus típusa] [Új típus neve];
```
módon tehetjük meg.
Eddig ismertetett típus típusok:
* enum
* struct

Amikor egy structot létrehozunk több alaptípust akarunk összefogni egy új típusban. Például ha egy koordinátát megvalósítú struktúrát akarunk létrehozni, akkor a következő módon tehetjük:
```
struct Coord{
    int x;
    int y;
};
```
, ahol az ```x``` az egyik tengely, az ```y``` a másik tengely mentén felvett értéket jelöli.
Innentől a két változót egy típusként tudjuk kezelni és ```.``` operátorral tudunk hivatkozni egy-egy részére az adott példánynak.
```
Coord a;
a.x = 12;
a.y = 0;
if(a.x > 0){
   ...
}
```

## Operátor a struktúrához

Jogosan elvárhatjuk egy objektumtól, hogy kiírható legyen:
```
#include <iostream>

using namespace std;

struct Coord{
    int x;
    int y;
};

int main(){
    Coord a,b;
    a.x = 12;
    a.y = 13;
    b.x = 2;
    b.y = 0;
    
    cout << (a+b) << endl;
    return 0;
}
```
Sok nyelvel ellentétben a C++ nyelvi megoldást ad arra, hogy a fenti kód helyes legyen és logikus működést biztosítson, két operátor megírásával.

Először meg kell írnunk a + operátort két koordináta között. Első paraméter a bal operandus (bal kéz - left hand - lh), a második a jobb operandus (jobb kéz - right hand - rh).
```
Coord operator+(const Coord &lh, const Coord &rh){
    Coord ret;
    ret.x = lh.x + rh.x;
    ret.y = lh.y + rh.y;
    return ret;
}
```
Két koordináta összege egyértelműen koordináta lesz, amit úgy kapunk hogy a komponenseket külön-külön összeadjuk.

Ezután megírhatjuk a kiíró operátort, ami egy koordinátát kiír.
```
ostream& operator<<(ostream& out, const Coord &c){
    out << c.re << ' ' << c.im;
    return out;
}
```
Már megszokott módon láthatjuk, hogy olyan operátort kell írnunk, aminek a baloldali paraméter egy kimeneti folyam a jobb oldali meg az a típus amire éppen a kiíró operátort meg szeretnénk írni.

## Tulajdonság számolása egy struktúrának

```
#include <iostream>
#include <cmath>

using namespace std;

struct Coord{
    int x;
    int y;
};

Coord operator+(const Coord &lh, const Coord &rh){
    Coord ret;
    ret.x = lh.x + rh.x;
    ret.y = lh.y + rh.y;
    return ret;
}

ostream& operator<<(ostream& out, const Coord &c){
    out << c.re << ' ' << c.im;
    return out;
}

float length(const Coord &o){
    return sqrt(pow(o.x,2)+pow(o.y,2));
}

int main(){
    Coord a,b;
    a.x = 12;
    a.y = 13;
    b.x = 2;
    b.y = 0;
    
    cout << length(a+b) << endl;
    return 0;
}
```

## Függvény bevitele a struktúrába

Ahogy eddig írtunk függvényeket azt szoktuk úgy hívni, hogy globális térbe írjuk a függvényt, mivel csak úgy magába a fájlba írjuk, viszont a függvényeket be tudjuk rakni a struktúrába is, hogy szorosan hozzákapcsolódjon logikailag. Olyan függvényeket tudunk bevinni az struktúrába aminek az első paramétere maga az osztály és akkor
```length(a)``` helyett ```a.length()``` formában fogjuk hívni a függvényt.


```
#include <iostream>
#include <cmath>

using namespace std;

struct Coord{
  int x;
  int y;
  
 Coord operator+(const Coord &rh){
    Coord ret;
    ret.x = x + rh.x;
    ret.y = y + rh.y;
    return ret;
  }
  
  float length(){
    return sqrt(pow(x,2)+pow(y,2));
  }
};

ostream& operator<<(ostream& out, const Coord &c){
    out << c.x << " " << c.y;
    return out;
}

int main(){
  Coord a,b;
  a.x = 12;
  a.y = 13;
  b.x = 2;
  b.y = 0;
  
  cout << (a+b).length() << endl;
}
```

## Láthatóság

Az új típus amiről ez a lecke szól az az osztály lesz, amit ```class```-al jelölünk c++-ban. Egy class és struct sok dologban nem különbözik, csak az úgynevezett alapértelmezett láthatóságban.
Két típusú láthatóságot fogunk tárgyalni:
```private``` - titkos, azaz kívülről ezek a függvények és változók nem érhetőek el.
```public``` - mindenki által elérhető és módosítható változók és meghívható függvények.

A következő példán keresztül nézük meg, hogy hogy is működik ez a láthatóság.
```
struct Valami{
  int a;
private:
  int b;
  int c;
public: 
  int d;
};

```
Ennek a strutkúrának az ```a``` és ```d``` változóját elérjük, de ```b``` és ```c``` változókat nem, tehát alapvetően egy struktúra publikus, tehát elérhetőek az elemei, de mihelyt egy ```private``` jelzőt rakunk oda a példában látható módon, akkor onnantól privát lesz minden tag, amíg meg nem jelenik egy különböző láthatósági jelző.


## Egy lépés az osztály felé

Az osztály mai fordítóknál lényegében csak egy dologban különbözik, hogy az alapvető láthatóság ```private```, tehát ha a kódunkat így módosítjuk akkor a két kódunk azonos lesz lényegében.
```
class Coord{
public:
  int x;
  int y;
  
  Coord operator+(const Coord &rh){
    Coord ret;
    ret.x = x + rh.x;
    ret.y = y + rh.y;
    return ret;
  }
  
  float length(){
    return sqrt(pow(x,2)+pow(y,2));
  }
};
```

## Adattagokat konvencionálisan priváttá tesszük

```
#include <iostream>
#include <cmath>

using namespace std;

class Coord{
  int x;
  int y;
  
public:
  Coord operator+(const Coord &rh){
    Coord ret;
    ret.x = x + rh.x;
    ret.y = y + rh.y;
    return ret;
  }
  
  float length(){
    return sqrt(pow(x,2)+pow(y,2));
  }
};

ostream& operator<<(ostream& out, const Coord &c){
    out << c.x << " " << c.y;
    return out;
}

int main(){
  Coord a,b;
  a.x = 12;
  a.y = 13;
  b.x = 2;
  b.y = 0;
  
  cout << (a+b).length() << endl;
}
```

Ebben az esetben viszont két probléma is fellép a kódunkban. 
* A kiíró operátorban az x-et és az y-t nem érjük el, mert azok privát adattagok mostantól. Ezt a hibát friend fügvénnyel fogjuk megoldani.
* A main függvényben értékeket adunk egyenesen a változóknak. Ezt a hibát setter-getter-el fogjuk megoldani.

## Friend

Ahogyan van szülő, gyerek, testvér, nagyszülő az osztályoknál úgy vannak haverok is, akikről annyit kell tudni, hogyha bárkit megjelölünk barátnak akkor az minden privát részt is elérhet. 
A kiíró operátor erre egy jó példa mivel az elég erősen az osztályhoz tartozik, csak mivel megszeretnénk őrizni, hogy ```cout << a``` stílusban írhassunk ki, ezért nem tudjuk balra rakni magát az osztályt, így nem tud az operátor bekerülni.

Baráttá tenni egy függvényt annyiból áll, hogy bárhol az osztályban kiírjuk a ```friend``` kulcsszót, majd utána a függvény deklarációját.
Hasonlóan lehet osztályt is baráttá tenni, akkor deklaráció helyett az osztály nevét kell odaírjuk. 

```friend ostream& operator<<(ostream& out, const Coord &c);```

## Getter-Setter

A getter-setter függvények arra valók, hogy ahelyett, hogy egyenesen hozzáférnénk az osztály egyes tagjaihoz ezt egy függvényen keresztül tehessük meg. Tehát privát minden adattag, viszont a legtöbb adattag módosítható egy-egy setterrel. Setterek konvencionális neve set[Változónév upper camel case-el], azaz ```repaRetekMogyoro``` osztálytváltozó setterének a neve ```setRepaRetekMogyoro```.
Hasonlóan getternél: ```getRepaRetekMogyoro```.

A maint nem tesszük baráttá, mivel ő nem tartozik szorosan az osztályunkhoz. 

## Működő kód

```
#include <iostream>
#include <cmath>

using namespace std;

class Coord{
  int x;
  int y;
  
public:
  Coord operator+(const Coord &rh){
    Coord ret;
    ret.x = x + rh.x;
    ret.y = y + rh.y;
    return ret;
  }
  
  float length(){
    return sqrt(pow(x,2)+pow(y,2));
  }

  void setX(int x){
    this->x = x;
  }
  void setY(int y){
    this->y = y;
  }
  
  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
   
  friend ostream& operator<<(ostream& out, const Coord &c);
};

ostream& operator<<(ostream& out, const Coord &c){
    out << c.x << " " << c.y;
    return out;
}

int main(){
  Coord a,b;
  a.setX(12);
  a.setY(13);
  b.setX(2);
  b.setY(0);
  
  cout << (a+b).length() << endl;
}
```

## Miért kell a láthatóság?

A láthatóságra azért van szükségünk, hogy az osztályunknak az állapotterét a megfelelő keretek között tartsuk, hogy végig előfeltételnek megfelelő legyen.
Például, ha kell egy pozitív egész számokat tartalmazó osztály, akkor tudunk olyan settert megadni, ami exception dob, hogyha negatív számot adunk át neki, vagy csak egyszerűen nem hagyja, hogy felülírják.



## Konstruktor

A mainben lévő kódot tehetnénk rövidebbé, mivel láthattuk korábban, hogy már az ifstreamet is lehet paraméterezni már létrehozáskor is és akkor extra fügvényhívás nélkül megtudnánk adni a koordinátánk két komponensét.

Az osztályoknak van egy egyedi függvénye ami az úgynevezett konstruktor. Ez a függvény fele az adott osztály létrehozásáért. Csak úgy tudunk létrehozni egy adott osztályt ha a konstruktor által megkövetelt paramétereket átadjuk létrehozáskor.
Alapesetben minden osztálynak van egy default konstruktora, ezért tudtuk a példában létrehozni a ```Coord``` osztály egy példányát mindenféle paraméter nélkül. De mihelyt írunk egy konstruktort a default konstruktor eltűnik, így ha továbbra is szeretnénk, hogy minden paraméter nélkül létre lehessen hozni az adott osztályt, csinálnunk kell egy üres konstruktort is.
A konstruktor létrehozása ugyanolyan, mint egy függvény létrehozása az osztályban, annyi különbséggel, hogy a visszatérési érték nincs és a függvénynév azonos az osztály nevével. Annyira nincs visszatérési érték, hogy nemcsak hogy void, hanem semmit nem kell odaírni.:)


```c++
#include <iostream>
#include <cmath>

using namespace std;

class Coord{
  int x;
  int y;
public:

  Coord(){}
  Coord(int x, int y){
    this->x = x;
    this->y = y;
  }

  Coord operator+(const Coord &b){
    Coord ret;
    ret.x = x+b.x;
    ret.y = y+b.y;
    return  ret;
  }
  
  float length(){
    return sqrt(pow(x,2)+pow(y,2));
  }

  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  
  void setX(int v){
    x = v;
  }
  void setY(int v){
    y = v;
  }
  
   
  friend ostream& operator<<(ostream& out, const Coord &c);
};

ostream& operator<<(ostream& out, const Coord &c){
    out << c.x << " " << c.y;
    return out;
}


int main(){
  Coord a(1,2);
  Coord b(2,3);
  
  cout << (a+b).length() << endl
}
```


# Osztály a vectorban

Egy osztályt ugyanúgy berakhatunk egy vectorba, ahogy egy sima változót, viszont ha például szeretnénk egy szummát meghívni egy ```vector<Coord>```-ra, akkor két dolgot meg kell írnunk az osztályunkhoz.

```
template<class T>
T sum(const vector<T> &v){
    T s;
    s = 0; //Coord = int nem értelmezhető még
    for(int a=0;a<v.size();a++){
        s += v[a]; // Coord += Coord nem értelmezhető
    }
    return s;
}
```
Először azt kell kitalálnunk, hogy mi a logikus ha egy skalárral akarunk egyenlővé tenni egy koordináttát. Ebben az esetben most azt választjuk, ami nem a legtökéletesebb választás, de megteszi, hogy minden komponense a koordinátának felveszi a skalár értékét.

```
class Coord{
...
  Coord& operator=(float v){
    x = v;
    y = v;
    return *this;
  }

  Coord& operator+=(const Coord &v){
    x += v.x;
    y += v.y;
    return *this;
  }
...
};
```

## A visszatérési érték miért ```Coord&```?

A 
```
int a;
(a=4)=6;
cout << a;
```
példa esetében a kiírt érték 6 lesz, amit viszont csak úgy lehet elérni, hogyha az ```a=4```-es rész magát ```a```-t adja vissza és nem az értékét és mint tudjuk C++-ban, hogyha simán csak visszaadunk valamit akkor az lemásolódik. Annak meg nem is lenne értelme, hogy ```4=6```, ami akkor alakulna ki ha nem referencia szerint adnánk át.
```+=``` operátor esetében ugyanez az érv, mert végülis az egyenlőség operátor megspékelve egy plusszal.




## Kész kód
```
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


class Coord{
  int x;
  int y;
public:

  Coord(){}
  Coord(int x, int y){
    this->x = x;
    this->y = y;
  }

  Coord operator+(const Coord &b){
    Coord ret;
    ret.x = x+b.x;
    ret.y = y+b.y;
    return  ret;
  }
  Coord& operator=(float v){
    x = v;
    y = v;
    return *this;
  }

  Coord& operator+=(const Coord &v){
    x += v.x;
    y += v.y;
    return *this;
  }
  
  float length(){
    return sqrt(pow(x,2)+pow(y,2));
  }

  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  
  void setX(int v){
    x = v;
  }
  void setY(int v){
    y = v;
  }
  
   
  friend ostream& operator<<(ostream& out, const Coord &c);
};

ostream& operator<<(ostream& out, const Coord &c){
    out << c.x << " " << c.y;
    return out;
}

template<class T>
T sum(const vector<T> &v){
    T s;
    s = 0; //Coord = int nem értelmezhető még
    for(int a=0;a<v.size();a++){
        s += v[a]; // Coord += Coord nem értelmezhető
    }
    return s;
}

int main(){
  vector<Coord> v;
  v.push_back(Coord(1,2)); //így is létre tudunk hozni egy Coord értéket amit rögtön át is adunk a vectornak, hogy rakja be
  v.push_back(Coord(1,0));
  v.push_back(Coord(0,3));
  
  cout << sum(v) << endl;
}
```

### De miért van külön sorban az s=0?

Csak a példa kedvéért, ha az lenne ott, hogy ```T s = 0```, akkor abban az esetben az azzal lenne egyenértékű, hogy T s(0), tehát egy egy paraméteres konstruktor hívódna meg. 

## Konstans függvények

Ha a maximális távolságú koordinátát keressük, akkor a következő függvény fog segíteni nekünk.
```
int maxFind(const vector<Coord> &v){
    int ind = 0;
    float max = v[0].length();
    for(int a=0;a<v.size();a++){
        if(max < v[a].length()){
            max = v[a].length();
            ind = a;
        }
    }
    return ind;
}
Erre viszont a fordító panaszkodni fog méghozzá azért, mert a ```v[a]``` az egy ```const Coord```, viszont amikor meghívjuk rá a length függvényt nem garantáljuk, hogy az nem fogja bántani azt amire meghívtuk. Ezt eddig meg tudtuk tenni úgy hogy a paraméter elé írtuk, hogy const, de most hogy tudjuk megtenni, hogy már nincs paraméter?
Egyetlen hely van ahol elfér ez az infó és oda is kell rakni az pedig a függvény után. Ha egy függvény utána odatesszük a ```const``` kulcsszót, akkor onnantól az konstans függvény lesz, ergo nem bánthatja az osztály adatatagjait, csak olvashatja őket.

```class Coord{
  int x;
  int y;
public:

  Coord(){}
  Coord(int x, int y){
    this->x = x;
    this->y = y;
  }

  Coord operator+(const Coord &b) const{
    Coord ret;
    ret.x = x+b.x;
    ret.y = y+b.y;
    return  ret;
  }
  Coord& operator=(float v){
    x = v;
    y = v;
    return *this;
  }

  Coord& operator+=(const Coord &v){
    x += v.x;
    y += v.y;
    return *this;
  }
  
  float length() const{
    return sqrt(pow(x,2)+pow(y,2));
  }

  int getX() const{
    return x;
  }
  int getY() const{
    return y;
  }
  
  void setX(int v){
    x = v;
  }
  void setY(int v){
    y = v;
  }
  
   
  friend ostream& operator<<(ostream& out, const Coord &c);
};
```


## Több fájl

Ahhoz, hogy ez a kód jól nézzen ki több fájlba kell szétszednünk az osztályainkat. A szokás alapján minden osztályhoz tartozik egy h és egy cpp fájl és mind a kettőnek pontosan az a neve mint az osztályénak (kis-nagy betűket beleértve).
Tehát a h fájlban csak a deklarációkat kell tartanunk végsősoron a cpp-ben meg a definíciókat. Az órához tartozó Complex osztályt megvalósításánál láthatjuk pontosan, hogy is.

##Amire figyelni kell

* A fordító a cpp-ket egyenként fordítja le, így ha két cpp-ben includeolunk be azonos h fájl és abban van egy függvénydefiníció akkor a linker azt fogja mondani, hogy kétszer van definiálva, mert mind a két o fájlba belegenerálja a fordító, mivel mind a két cpp-be belekerült az include hatására (Mint korábban mondtam az include kb. copy-paste-nek felel meg)
* Ha const osztályra akarunk meghívni egy függvényt, akkor csak úgy lehetséges, ha az adott függvény konstans, amit úgy érünk el, hogy a függvény deklarációjában a () után írjuk, hogy const:
```int getSomething() const { return something; }```
* ```using namespace std;```-t header file-ban nem használunk (ha más használja a kódunkat akkor rákényszerítenénk vele, hogy azt a namespacet használja amit mi)
* Konstans függvényt lehet csak konstansra hívni.
* Üres konstruktornak léteznie kell ahhoz, hogy egy az adott osztályt tartalmazó vector-t resizeolni lehessen.


## Copykonstruktor, egyenlőségoperátor és destruktor (Extra)

Ha egy kicsit bonyolultabb osztályt akarunk csinálni, amiben például pointerek vannak akkro felmerülhet az a probléma, hogy ha egyenlővé tesszük az egyik osztályt a másikkal vagy vissszaadjuk paraméteren keresztül akkor, hogy másolódik le az adott osztály.
Tehát ha pl. van egy olyan osztályunk ami pointerekkel dolgozik akkor a következő móódon járhatunk el.

**Desktruktor** - Ez a függvény hasonló mint a konstruktor, csak nem lehet paramétere és akkor fut le amikor az adott változó élettartama végetér, ergo a {} blokk végén amiben létre lett hozva.
**Copy Konstruktor ** és **Egyenlőség operátor** - Ezek hívódnak meg amikor másolni akar implicit a fordító egy osztályt, ezért ezeket mindig érdemes megírni az elején. Ha pointerekről vannak az osztályban akkor meg szükséges, mivel rossz eredményre fogunk jutni.
```c++
class String2{
  char* data;
  int length;
   
  String2(){
    data = 0;
    length = 0;
  }
  ~String2(){ 
    if(data != 0){
      delete data;
    }
  }
  String2 operator=(const String2 &other){
    data = new char[other.length];
    length = other.length;
    for(int a=0;a<length;a++){
      data[a] = other.data[a];
    }
    return *this;
  }
  String2(const String2 &other){
    *this = other;
  }
  
}
```
De miért jutunk rossz eredményre ha nem másolódik a pointer rendesen?
Gonoljunk bele, hogy van egy stringünk amit lemásolunk egy másikba majd a másolatot változtatjuk, akkor jobbik esetben az eredeti változó értéke is megváltozik, rosszabbik esetben viszont törlődik a memóriaterület és az első amit lemásoltunk továbbra is oda mutat ahova előtte mind a két változó. Ez pedig rossz hivatkozásra és a program fagyásához vezet.


# Feladatok 

1. Egy üzletlánc folyamatosan elemzi a törzsvásárlóinak vásárlási szokásait. Egy szöveges állományban nyilvántartja, hogy a törzsvásárlók mit vettek az elmúlt időszakban. Az állomány minden sora egy-egy vásárlási tétel adatait tartalmazza: a vásárlás azonosítóját (16 karakter), a törzsvásárló kódját (4 karakter), a vásárolt áru kódját (8 karakter) és egy mennyiséget (valós szám); ezek mind szóközökkel vagy tabulátor jelekkel vannak elválasztva.
..1. Példa egy sorra: 1505181035210101 ve61 árukód21 2.5
..2. Készítsünk a leckében látható módon osztályt egy rekord tárolására, készítsünk hozzá beolvasó, kiíró operátort.
..3. Oldjuk meg a következő feladatokat:
....1. Melyik törzsvásárló vett elősször az "aru11" -ből.
....2. Ha a vevő kódja VIP-el kezdődik, akkor a mennyiségét dupla annyiként számolva összegezzük a teljes mennyiséget.


[2015-05-18 nagy zh - A csoport]
