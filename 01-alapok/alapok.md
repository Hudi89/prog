# 1. Gyakorlat - Alapok

A Programozás című tárgy előfeltétele a Programozási alapismeretek című tágy, így annak anyagát ismertnek vesszük és csak egy rövid áttekintés erejéig érintjük a teljesség igénye nélkül.

## Alapok

Egy programot úgy foghatunk fel mint egy ember által sokszor elvégzett feladat formalizálását. Például ha azt a feladatot kapod a boltban, hogy nézd át minden nap zárás után, hogy van-e esetleg lejárt termék. Ebben az esetben buta verzióban annyit fogunk tenni, hogy minden nap végignézzük az összes terméket, hogy mikor jár le és ha az adott dátum kisebb mint a mai akkor kidobjuk. Ez esetünkben lehet egy többszörös **keresés**, igen keresési tétel, ergo kiválogatás, mert ha ismerjük az 5 alap tételt, akkor egyelőre még csak keresést tudjuk használni, de azzal is megtudjuk oldani, mert ha kikeresünk egy olyat ami lejárt kivesszük és addig futtatjuk amíg van benne lejárt elem.

Másik példaként vehetjük pl. hogy a legerősebb alkoholt keressük (szintén a boltban...nem ott írom ezt...komolyan) a termékek közül. Ekkor annyit tudunk csinálni ha bemegyünk a boltba, hogy végigmegyünk a soron és nézegetjük, hogy melyik mennyi és mindig megjegyezzük, hogy mi volt eddig a legerősebb alkohol. Amikor a sor végére érünk akkor (ha a memóriánk nem rossz) emlékszünk, hogy melyik volt az, meg is oldottuk a feladatot.

### A programkód 

```c++
#include <iostream>

using namespace std;

int main(){
  int b=2;
  b++;
  cout << b;
  return 0;
}
```
Egy programkód értelmezése futtatás nélkül első dolog amit szem előtt kell tartani, hogy a programunk mindig **sorról sorra fut**, ergo nem kell rögtön megérteni az egészet, hanem a fejünkben szépen végiglépkedni a programunk futását. Első szinten azt figyeljük mindig, hogy hol jelenik meg a programunkban az **int main()** nevű függvény, mivel innen fog indulni a futásunk, ami ezután le van írva a **{ és }** között, az a rész lesz a főprogramunk amit elemezni fogunk lépésről lépésre. 
Szóval ez a programkód pl. annyit csinál, hogy létrehoz egy változót b névvel, majd annak értékéül adja, hogy kettő.
```c++ int b=2;```. Ezzel végeztünk is. A következő sorban a b változót növeljük egyel ```c++ b++;```.  Ekkor a b-nk 3 lesz, mivel eddig 2 volt. Kiírjuk a b-t, ergo a képernyőre kikerül, hogy 3.```c++ return 0;``` minden main végén kötelező, ezzel jelezzük a programot indítónak, hogy a program lefutása helyes volt. 

#### De miért kell mindenhova ";"?
A c++ nem foglalkozik a sortörésekkel, szóközökkel, tabulátorokkal (úgynevezzet whitespace karakterekkel, szemben a whitespace nevű nyelvvel: http://hu.wikipedia.org/wiki/Whitespace_%28programoz%C3%A1si_nyelv%29), így valahogy el kell választanunk a parancsokat, ebből adódóan az előző programkódot a következő módon is írhattuk volna.

```c++
#include <iostream> 
using namespace std;int main(){int b=2;b++;cout << b;return 0;}
```
A **#include** -os rész sajnos teljesen más világ, így ott az egy sorba behúzást nem tehetjük meg, mivel ezek úgynevezett direktívák.

#### Direktíva

 #-el kezdődő részeket a programban direktívának hívjuk, ami nem konkrét programkód, hanem csak egy elősegítő folyamat.
Első direktíva az #include, ami annyit tesz, hogy másolás beillesztés, ekkor egy úgynevezett fejlécfájlt másol be a mi kódunkba, hogy a fordító tudja, hogy miket használhatunk a programunkban. De erről részletesebben későbbi fejezetekben lesz, egyelőre maradjunk annyiban, hogy ha valamilyen funkcióra szükségünk van, akkor ilyen #include sorokat kell majd hozzáadnunk és akkor azokat is megtudjuk majd hívni.

A tárgyon belül az úgynevezett STL-t (Standard Template Library) fogjuk használni csak, ennek része az iostream is, de ha pl. matematikai függvényeket akarunk használni, akkor
```c++
#include <cmath> 
```
sor hozzáadásával elérhetővé tesszük a abs() függvényt is ami a paraméterül adott szám abszolútértékét adja vissza. 
Részletesen: http://www.cplusplus.com/reference/ (ezekből csak párat fogunk érinteni a tárgy alatt.

### És mit jelent az az utolsó még nem magyarázott sor?
```c++
using namespace std;
```

Ez egy egyszerű rövidítés, mivel ha ez nincs kiírva, akkor minden cout elé oda kell írni, hogy std::cout (később lesz szó részletesebben a :: operátorról). De mire is jó?
Egy könnyen érthető magyarázat, hogy programozásban minden feladat megvalósítására nagyon sok verzió készül különböző programozóktól, így viszont elkerülhetetlen, hogy egy nagy projekt esetében ne nevezzenek el a fejlesztők két különböző függvényt azonos névvel, de ha mindkettőt szeretnénk használni akkor mit tudunk tenni? Erre valók a névterek, hogy valamilyen megbeszélt felosztás szerint a függvényeket névcsoportokba soroljuk. Legyen A és B névtér (később erről is részletesebben) mindkettőben létezik a hello függvény, ekkor ```c++ A::hello()``` -val hívhatjuk meg az A verziót ```c++ B::hello()```-val meg a B-set. Ha viszont tudjuk, hogy főként az A függvényeit fogjuk használni, akkor kiírjuk a usingos részt és onnantól ha ```c++ hello()```-t írunk automatikusan az A verziót veszi, de továbbra is elérhető a B verziója ```c++ B::hello()```-t használva.

Tehát ha eltávolítjuk a usingos rézt, akkor az iostream-ből ismert dolgok elé kikell rakni az ```c++ std::```-t
```c++
#include <iostream>

int main(){
  int b=2;
  b++;
  std::cout << b;
  return 0;
}
```


#### De hol is van ez a programkód?

Egyszerű szöveges fájlt hozunk létre és abban mint szöveg, szerkesztéséhez nem szükséges semmi extra eszköz, egy egyszerű notepad-től, komolyabb fejlesztőkörnyezetig minden megtudja nyitni. Problémák a karakterkódolásoknál jelenhetnek meg, de a tárgy folyamán nem használunk ékezetet sehol, így ezzel nem foglalkozunk.
Általában a kiterjesztése a c/c++ programkód fájloknak **cpp**, **cc** vagy simán **c**, mi és a CodeBlocks is a **cpp**-t fogjuk használni.

### Fordítás

Fordításra nagyon sok mód létezik, viszont a tárgy folyamán legfőképp CodeBlocks-ot fogjuk használni.

#### Konzolból fordítás (Linux)

```bash
g++ main.cpp
```
A programkódunk egyszerűen fordítható a fájl megadásával a g++ parancs után és a.out néven fogja elkészíteni a futtatható állományt (ezt az állományt linux alatt ./a.out parancsal tudjuk futtatni). 
-o kapcsolóval megadhatjuk a kimeneti fájl nevét is, hogy ne a.out néven mentse el.
```bash
g++ main.cpp -o kicsiprogram
```
Ebben az eseteben ./kicsiprogram fogja logikusan elindítani a programunkat (Nem kell kiterjesztés, nem is szokás).

Később több fájlt fordítása esetén alkalmazhatjuk a 
```bash
g++ main.cpp masik.cpp harmadik.cpp -o kicsiprogram
```
vagy 
```bash
g++ *.cpp -o kicsiprogram
```
parancsot.

Részletesen: http://linux.die.net/man/1/g++

#### Code Blocks
**Code Blocks** is használható a tárgy alatt, új projekt létrehozása illetve fordítása sokkal egyszerűbb: https://www.youtube.com/watch?v=kYA8rK2fy2U

### Kommentelés

A kódban megjelenhetnek olyan információk is amik nem feltétlenül tartoznak a kódhoz hanem csak a kód megértését könnyítik, TODO (olyan amit még meg kell csinálni), dokumentáció, vagy bármi egyéb megjegyzés.
C++-ban két alapvető lehetésünk van kommentelésre: 
* // jelek után írt szövegrészeket a program figyelmen kívül hagyja (egy soros megjegyzés)
* /* és */ közé írt szöveget szintén (több soros megjegyzés)

```c++
#include <iostream>

using namespace std;

int main(){
  int b=2; //Szeretem a mákosgubát
  b++;
  cout << b;
  /*
  Egyszer volt hol nem volt volt egyszer egy... róka... vége.
  */
  
  return 0;
}
```
A modern programozási világban a több soros megjegyzés használata esetén óvatosságra intenek, mert ha pl. van egy 1000 soros kódod és kiakarsz kommentelni 200 sort belőle, de valahol van benne egy 10 soros rész aminél már használtad a több soros megjegyzés, akkor a több soros megjegyzés az 200 soros komment nyitójától fog tartani a 10 soros zárójáig, tehát a 10 soros */-jétől nem lesz kikommentelve a kód. Ahhoz, hogy egy soros kommentelést alkalmazzunk több soron, a legtöbb fejlesztő környezet kínál egy billentyűkombinációt, aminek a segítségével a kijelölt sorok mindegyikét egysoros kommentbe teszi. (Ideiglenes kód eltávolítás miatt pl.)


##  Változók
A változó a program futásához szükséges kellék, ami valamilyen nemű információt tárol. A változót úgy képzelhetjük el, hogy ha azonosulunk a programmal. Képzeljük el, hogy mi vagyunk a buta program aki nem tud olyan komplexen gondolkozni mint egy ember, hanem egyszerre csak egy dologra tud koncentrálni aki ül egy asztalnál. Ha megkérdezed a felhasználót, hogy mondjon egy számot, akkor azt a számot le kell írnod egy lapra és ott hagynod az asztalodon (ami a valóságban a memóriát szimbolizálja), mivel ha nemírod fel elfelejted. 

### Hogy hozzuk létre?

A példánkból már látható vagy sejthető, hogy 
```[Változó típus] [Változó név]```
stílusban hozunk létre változót. A példánkban az int típust használjuk ami az egyszerű egész szám, viszont vigyázzunk vele, mert ezek nem minden egész számot képesek eltárolni, csak adott nagyságút, attól függően hány bit-ről van szó. Ha pl. 32. bites az int (általában ez igaz) akkor 2^32 számot képes kifejezni. (Részletesebben: Numerikus módszerek 1. http://numanal.inf.elte.hu/~hegedus/okt.html)

#### Milyen típusok vannak

int - Egész (általában 32 bites 0..4294967296)
float - Lebegőpontos (általában 32 bites, viszont itt egy érdekesség, hogy vagy nagyon pontos vagy nagyon nagy számokat tud kifejezni)
double - Ugyanaz mint a float csak nagyobb (általában 64 bit)
char - karakter (8 bit - 1 byte - 1 karakter)
bool - logikai változó (1 bit)

Note: az általában kifejezés annyit tesz, hogy a mi esetünkben az ELTE-n a gépeken így lesz a félév folyamán.

#### Milyen módosítók vannak

## Függvények

A programozási nyelvek első egyik legfontosabb eleme a függvények, amik segítségével struktúráltabbá tudjuk tenni a programunkat


## Referencia használata
A tárgy óráin általában a http://www.cplusplus.com/ oldalán található leírásokat fogom ajánlani, mivel az oldalon egy függvény használatához általában 
