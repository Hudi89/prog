# 1. Gyakorlat - Alapok

A Programozás című tárgy előfeltétele a Programozási alapismeretek című tágy, így annak anyagát ismertnek vesszük és csak egy rövid áttekintés erejéig érintjük a teljesség igénye nélkül.

## A programkód 

Ugorjunk rögtön egy mintakód közepébe és próbáljuk meg annak értelmezése mentén felszedni az alapvető információkat.

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

### De miért kell mindenhova ";"?
A c++ nem foglalkozik a sortörésekkel, szóközökkel, tabulátorokkal (úgynevezzet whitespace karakterekkel, szemben a whitespace nevű nyelvvel: http://hu.wikipedia.org/wiki/Whitespace_%28programoz%C3%A1si_nyelv%29), így valahogy el kell választanunk a parancsokat, ebből adódóan az előző programkódot a következő módon is írhattuk volna.

```c++
#include <iostream> 
using namespace std;int main(){int b=2;b++;cout << b;return 0;}
```
A **#include** -os rész sajnos teljesen más világ, így ott az egy sorba behúzást nem tehetjük meg, mivel ezek úgynevezett direktívák.

### Direktíva

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
Egy könnyen érthető magyarázat, hogy programozásban minden feladat megvalósítására nagyon sok verzió készül különböző programozóktól, így viszont elkerülhetetlen, hogy egy nagy projekt esetében ne nevezzenek el a fejlesztők két különböző függvényt azonos névvel, de ha mindkettőt szeretnénk használni akkor mit tudunk tenni? Erre valók a névterek, hogy valamilyen megbeszélt felosztás szerint a függvényeket névcsoportokba soroljuk. Legyen A és B névtér (később erről is részletesebben) mindkettőben létezik a hello függvény, ekkor ```c++ A::hello()``` -val hívhatjuk meg az A verziót ```c++ B::hello()```-val meg a B-set. Ha viszont tudjuk, hogy főként az A függvényeit fogjuk használni, akkor kiírjuk a usingos részt és onnantól ha ```c++ hello()```-t írunk automatikusan az A verziót veszi, de továbbra is elérhető a B verziója ```c++ B::hello()```-t használva. A ```c++::``` operátor más esetekben is használatos lesz majd még. Amit általánosan tudni kell róla az az, hogy ez egy olyan operátor ami egy fogalmi szinten létező dolgon belüli valamit választ ki. A mostani példánkban egy a fogalomban (névtér) lévő másik fogalmat (függvény) érünk elezzel az operátorral (később lesz másra is példa).

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


### De hol is van ez a programkód?

Egyszerű szöveges fájlt hozunk létre és abban mint szöveg, szerkesztéséhez nem szükséges semmi extra eszköz, egy egyszerű notepad-től, komolyabb fejlesztőkörnyezetig minden megtudja nyitni. Problémák a karakterkódolásoknál jelenhetnek meg, de a tárgy folyamán nem használunk ékezetet sehol, így ezzel nem foglalkozunk.
Általában a kiterjesztése a c/c++ programkód fájloknak **cpp**, **cc** vagy simán **c**, mi és a CodeBlocks is a **cpp**-t fogjuk használni.

## Fordítás

Fordításra nagyon sok mód létezik, viszont a tárgy folyamán legfőképp CodeBlocks-ot fogjuk használni.

### Konzolból fordítás (Linux)

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

### Code Blocks
**Code Blocks** is használható a tárgy alatt, új projekt létrehozása illetve fordítása sokkal egyszerűbb: https://www.youtube.com/watch?v=kYA8rK2fy2U

## Kommentelés

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


#  Változók
A változó a program futásához szükséges kellék, ami valamilyen nemű információt tárol. A változót úgy képzelhetjük el, hogy ha azonosulunk a programmal. Képzeljük el, hogy mi vagyunk a buta program aki nem tud olyan komplexen gondolkozni mint egy ember, hanem egyszerre csak egy dologra tud koncentrálni aki ül egy asztalnál. Ha megkérdezed a felhasználót, hogy mondjon egy számot, akkor azt a számot le kell írnod egy lapra és ott hagynod az asztalodon (ami a valóságban a memóriát szimbolizálja), mivel ha nemírod fel elfelejted. 

## Hogy hozzuk létre?

A példánkból már látható vagy sejthető, hogy 
```[Változó típus] [Változó név]```
stílusban hozunk létre változót. A példánkban az int típust használjuk ami az egyszerű egész szám, viszont vigyázzunk vele, mert ezek nem minden egész számot képesek eltárolni, csak adott nagyságút, attól függően hány bit-ről van szó. Ha pl. 32. bites az int (általában ez igaz) akkor 2^32 számot képes kifejezni. (Részletesebben: Numerikus módszerek 1. http://numanal.inf.elte.hu/~hegedus/okt.html)

## Milyen típusok vannak

int - Egész (általában 32 bites 4294967296 értéket vehet fel. fele negatív fele pozitív irányban)
float - Lebegőpontos (általában 32 bites, viszont itt egy érdekesség, hogy vagy nagyon pontos vagy nagyon nagy számokat tud kifejezni)
double - Ugyanaz mint a float csak nagyobb (általában 64 bit)
char - karakter (8 bit - 1 byte - 1 karakter)
bool - logikai változó (1 bit)

A fenti számos típusokból (a bool nem) létrehozhatunk előjel nélkülit is ha a típus elé írjuk, hogy unsigned: ```c++ unsigned int```.

Note: az általában kifejezés annyit tesz, hogy a mi esetünkben az ELTE-n a gépeken így lesz a félév folyamán.

# Függvények

A programozási nyelvek első egyik legfontosabb eleme a függvények, amik segítségével struktúráltabbá tudjuk tenni a programunkat. A függvényt úgy lehet elképzelni, mint egy doboz amiben ül egy manó te odaadod neki a paramétereket ő meg folyamatosan ugyanazt a feladatot hajtja végre és a végén opcionálisan visszaad valami választ és addig mi ott állunk és tartjuk a kezünket. Ilyenkor a szokásos sorról sorra futás hirtelen elugrik arra a kódrészletre ami meg lett hívva. A hívást egyszerűen úgy írjuk, hogy megadjuk a függvénynevét és utána zárójelben a paramétereket.
Egy függvény két részből áll: van deklaráció és definíció része.

## Deklaráció

A deklaráció arra szolgál, hogy jelezzük a fordító számára (ami sorról sorra értelmezi a kódot), hogy lesz egy ilyen nevű és szignatúrájú függvény (Szignatúra később részletesebben). A deklaráció szerkezete a következő:
[Visszatérési érték] [Függvény név]([Paraméterek]);
[Paraméterek] ::= [1. Paraméter típus] [1. Paraméter név], [2. Paraméter típus] [2. Paraméter név] ...

Például:
```c++
int max(int a, int b);
```
A kódban ezalatt a deklaráció alatt már akárhol hívhatjuk a ```c++max``` függvényt függetlenül attól, hogy definiálva lett-e, hogy mit is csinál ez a függvény.

```c++
cout << max(2,3); 
```
Ez természetesen kifogja írni, hogy 3 ha megfelelően definiáljuk később a függvényt. A deklaráció elhagyható és csak a definíció is elég pl. egy egyfájlos program esetében, de később látni fogjuk a hasznát. Ha mégis megakarjuk spórolni a deklaráció leírását, akkor figyeljünk arra, hogy az adott függvény csak onnantól hívható meg ha volt deklarálva vagy definiálva.

## Definíció

A függvény definíciója nem sokban különbözik a deklarációtól, annyi különbséggel, hogy a végén nem ;-el zárjuk le hanem { és } között megírunk egy alprogramot ami végre fog hajtódni a hívás esetén.

```c++
int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}
```

## Szignatúra és overload

Egy függvényt nem csak a neve azonosít hanem az úgynevezett szignatúrája is, ami esetünkben a paraméterek típusa lesz. Az előző példánkban a függvény neve max volt a szignatúrája ```c++int,int``` volt, mivel két paramétert vár és mindkettő int. Ez azért fontos, mert ha ```c++max(2); ``` parancsot adjuk ki a kódunkban, akkor a fordító panaszkodni fog, hogy nem ismeri a függvényt.

Viszont pont ezt kihasználva, hogy a szignatúra is beleszámít egy függvény azonosításába nem csak a név, tudunk úgymond overloadolni, ami annyit tesz, hogy egy névhez több funkciót is megadunk. 

Például:
```c++
int max(int a, int b, int c){
  return max(max(a,b),c);
}
```
Ezzel a kóddal elérjük azt, hogy ha három paraméterrel hívják meg a max függvényünket akkor már az is fog működni. Ez a függvény teljesen egyszerűen, ha nézzük a definíciót meghívja a két paraméteres maxot. 
*Note: Egyelőre nem törekedünk optimális kód írására, a fő szempontunk, hogy gyorsabban és szebb kódot írjunk.*


# Referencia használata
A tárgy óráin általában a http://www.cplusplus.com/ oldalán található leírásokat fogom ajánlani, mivel az oldalon egy függvény használatához általában 


# Tömbök
A programozási alapismeretek órán megismerkedtetek a tömbökkel, amik arra szolgálnak, hogy a fentebb ismertetett típusokból többet tároljunk együtt. Ezt egyszerűen tudjuk megoldani:

```c++
#include <iostream>

using namespace std;

int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}

int max(int a[3]){
  return max(max(a[0],a[1]),a[2]);
}

int main(){
  int T[3];
  T[0] = 1;
  T[1] = 2;
  T[3] = 3;
  cout << max(T);
}
```
Ez a kód szintén ki fogja írni a 3 elem maximumát a korábbiakhoz hasonlóan.
Note: Az, hogy belül hogy nevezzük el a változókat az teljesen független attól, hogy egy függvényen belül hogy hívjuk.
Viszont ezzel a kóddal van egy olyan problémánk, hogy normális esetben egy statikus változó nem lehet dinamikus méretű, ergo ha mondjuk nem tudjuk mennyi bemenő adat lesz, akkor max úgy tudjuk megoldani, hogy létrehozunk egy 1000 nagyságút és imádkozunk, hogy a felhasználó ne akarjon több adatot beadni. Ez egy ideig használható megoldás is lehet, de éles helyzetben egy általánosabb programnál természtesen elfogadhatatlan. 


# Tételek

Ha egy feladatot nagyon sokszor végez el valaki, akkor egy idő után nagyon elkezdi unni. :) Mit tehetünk ilyenkor? Automatizáljuk. A programok pont erre lesznek jók nekünk. Vegyünk például egy egyszerű példát:
Ha egy boltban minden nap meg kell számolnunk az összes bevételt, úgy mint kasszában, ugyanúgy a blokkokon, akkor az egy elég robot munka lehet. Ez az összegzés tétel.

```c++
int s = 0;
for(int i=0;i<billCount;i++){
  s = bills[a];
}
```

Másik példaként vehetjük pl. hogy a legerősebb alkoholt keressük a termékek közül. Ekkor annyit tudunk csinálni ha bemegyünk a boltba, hogy végigmegyünk a soron és nézegetjük, hogy melyik mennyi és mindig megjegyezzük, hogy mi volt eddig a legerősebb alkohol. Amikor a sor végére érünk akkor (ha a memóriánk nem rossz) emlékszünk, hogy melyik volt az, meg is oldottuk a feladatot. Ez a maximum keresés.

```c++
int s = 0;
for(int i=0;i<billCount;i++){
  s = bills[a];
}
```

# Vector 

Ebben az esetben jön segítségünkre a vector, ami egy eddig ismeretlen fogalomtárból származik. Ez egy úgynevezett osztály, amiről most első szinten annyit kell tudnunk, hogy egy olyan dolog aminek parancsokat tudunk kiadni, kérdezni tudunk tőle, de az hogy az adott feladatot hogy oldja meg az minket egyelőre nem érdekel. Ez az osztály segít nekünk dinamikusan kezelni tömböket, nem kell foglalkoznunk memóriafoglalásokkal, méretekkel meg semmivel, csak kiadunk neki egy parancsot, hogy mit csináljon és megoldja nekünk.

Létrehozása egy kicsit érdekes, mert nem simán ahogy gondolnánk, hogy változó típus és név, mert itt van a típusnak egy paramétere is, amivel azt adjuk meg, hogy miket szeretnénk tárolni ebben a vectorban. Ha nem lenne ilyen támogatás a C++-ban akkor létre kéne hozni minden más típusra egy-egy vector osztyált, de mi lenne akkor ha egy saját új típusból szeretnénk vectort csinálni? Hát természetesen nem sikerlüne (egyszerűen legalábbis nem).

Tehát ha mondjuk egy int-ekből álló tömböt akarunk amit v-nek nevezünk, akkor a 
```c++ vector<int> v;```
kód a nekünk való.:)

Ennek az osztálynak úgy tudunk parancsot adni, azaz egy függvényét meghívni, hogy a neve után teszünk egy pontot majd megadjuk a függvény nevét. 

## push_back
Az első és legtriviálisabb függvény az a ```c++ vector::push_back(int)```. A jelölés ne zavarjon meg minket, ez már a korábban emlegetett ```c++::``` operátor ami egy fogalomban egy valamit jelöl. A vector fogalmi szinten létezik amíg nem hozunk létre belőle egyet. Az előző vector létrehozásnál a ```c++v``` a vector osztály egy példánya.
Viszont ha már van példányunk és arra a konkrét vectorra szeretnénk meghívni egy függvényt akkor a ```c++.``` operátor lesz a segítségünkre:
```c++v.push_back(4); ```
Ez a Kód annyit fog tenni, hogy a v vektorba ami kezdetben üres berakja a 4-et.

Note: Természetesen az int helyén *bármi* lehet (A bármire később lesznek korlátaink, de aktuális tudásunk szerint bármi). 

Részletesebben: http://www.cplusplus.com/reference/vector/vector/push_back/

## operator[]

Ha csak berakni tudunk az nem túl izgalmas és mivel a tömböt általánosítottuk elég kínos lenne ha nem tudnánk ugyanúgy hivatkozni az elemeire, mint a tömbnek, így a szokásos írásmóddal tudunk hivatkozni egy tömb elemére:

```c++vector::operator[](unsigned int) ```

```c++v[1] ``` visszaadja az első elemét (tehát a második elemét, mivel 0-tól indexelünk c-ben, ne feledjük)

Részletesebben: http://www.cplusplus.com/reference/vector/vector/operator[]/
 
## size

```c++vector::size() ```
Visszaadja a vektor méretét, hogy mennyi elem van benne. Paramétere természetesen nincs.
```c++v.size()```

http://www.cplusplus.com/reference/vector/vector/size/


```c++
#include <iostream>

using namespace std;

int main(){
  vector<int> v;
  
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  
  for(int a=0;a<v.size())
}
```
Ennek


http://www.cplusplus.com/reference/vector/vector/

#Feladat 

1. Írjunk egy olyan programot ami a vector használatával bekér számokat 0-ig, majd összegüket kiírja. (bontsuk függvényekre: beolvas összegzés)


