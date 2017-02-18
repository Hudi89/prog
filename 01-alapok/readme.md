# 1. Gyakorlat - Alapok

A Programozás című tárgy előfeltétele a Programozási alapismeretek című tágy, így annak anyagát ismertnek vesszük és csak egy rövid áttekintés erejéig érintjük a teljesség igénye nélkül.

## A programkód 

Ugorjunk rögtön egy mintakód közepébe és próbáljuk meg annak értelmezése mentén elkezdeni az egészet.

```c++
#include <iostream>

using namespace std;

int main(){
  int b=2;
  b++;
  cout << b << endl;
  return 0;
}
```
Egy programkód futtatás nélküli elemzéséhez az első dolog amit szem előtt kell tartani, hogy a programunk mindig **sorról sorra fut**, ergo a gép nem fogja mágikus módon kitalálni, hogy mit akarunk, hanem sorról sorra fogja azokat végrehajtani, mint egy gép:). 
Először figyeljük meg azt, hogy hol jelenik meg a programunkban az **int main()** nevű függvény, mivel innen fog indulni a futásunk. Ami a ```main``` után van a **{ és }** között, az a rész lesz a főprogramunk. 
Szóval ez a programkód pl. annyit csinál, hogy létrehoz egy egészeket tároló változót b névvel, majd annak értékéül adja, hogy kettő.
```int b=2;```. következő sorban a b változót növeljük egyel ```b++;```.  Ekkor a b-nk 3 lesz, mivel eddig 2 volt. Kiírjuk a b-t, ergo a képernyőre kikerül, hogy 3 majd utána egy sortörés (sortörést jelölése: endl).
```return 0;``` minden main végén kötelező, ezzel jelezzük a programot indítónak, hogy a program lefutása sikeres volt (ha nem 0-t írunk a return után, akkor azzal hibát jelzünk a programunkat futtató felé). 

### De miért kell mindenhova ";"?
A c++ nem foglalkozik a sortörésekkel, szóközökkel, tabulátorokkal (whitespace karakterekkel, szemben a whitespace nevű nyelvvel: http://hu.wikipedia.org/wiki/Whitespace_%28programoz%C3%A1si_nyelv%29), így valahogy el kell választanunk a parancsokat, ebből adódóan az előző programkódot a következő módon is írhattuk volna.

```c++
#include <iostream> 
using namespace std;int main(){int b=2;b++;cout << b;return 0;}
```
A **#include** -os rész sajnos teljesen más világ, így ott az egy sorba behúzást nem tehetjük meg, mivel ezek úgynevezett direktívák.

### Változók és Aritmerika
Minden névnek és kifejezésnek típusa van, amely meghatározza a végrehajtható műveleteket:
```c++
int inch;
```
A fenti deklaráció például azt adja meg, hogy inch típusa int (vagyis inch egy egész típusú változó). 

A deklaráció olyan utasítás, mely a programba egy nevet vezet be. Ehhez a névhez egy típust rendel. A típus egy név vagy kifejezés megfelelő használatát határozza meg. 

A c++ több alaptípussal rendelkezik. Például:
```c++
bool	//logikai típus, lehetséges értékei: true(igaz) vagy false(hamis)
char	//karakter, például: 'a', 'z' vagy '9'
int		//egész érték, például: 1, 42, vagy 1216
double	//kétszeres pontosságú lebegőpontos szám
```

Az aritmetikai műveletek e típusok bármilyen párosítására használhatók:
```c++
+	//összeadás vagy előjel, egy- és kétoperandusú is lehet
-	//kivonás vagy előjel, egy- és kétoperandusú is lehet
*	//szorzás
/	//osztás
%	//maradékképzés
```

Ugyanígy az összehasonlító műveletek is:
```c++
==	//egyenlő
!=	//nem egyenlő
<	//kisebb
>	//nagyobb
<=	//kisebb vagy egyenlő
>=	//nagyobb vagy egyenlő
```

### Direktíva

 #-el kezdődő részeket a programban direktívának hívjuk, ami nem konkrét programkód, hanem csak egy előfeldolgozó folyamat.
Első direktíva amiről beszélünk a legalapvetőbb #include, ami annyit tesz, hogy másolás beillesztés, ekkor egy úgynevezett fejlécfájlt másol be a mi kódunkba, hogy a fordító tudja, hogy miket használhatunk a programunkban. De erről részletesebben későbbi fejezetekben lesz, egyelőre maradjunk annyiban, hogy ha valamilyen funkcióra szükségünk van, akkor ilyen #include sorokat kell majd hozzáadnunk és akkor azokat is megtudjuk majd hívni.

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
Egy könnyen érthető magyarázat, hogy programozásban minden feladat megvalósítására nagyon sok verzió készül különböző programozóktól, így viszont elkerülhetetlen, hogy egy nagy projekt esetében ne nevezzenek el a fejlesztők két különböző függvényt azonos névvel, de ha mindkettőt szeretnénk használni akkor mit tudunk tenni? Erre valók a névterek, hogy valamilyen megbeszélt felosztás szerint a függvényeket névcsoportokba soroljuk. Legyen A és B névtér (később erről is részletesebben) mindkettőben létezik a hello függvény, ekkor ```A::hello()``` -val hívhatjuk meg az A verziót ```B::hello()```-val meg a B-set. Ha viszont tudjuk, hogy főként az A függvényeit fogjuk használni, akkor kiírjuk a usingos részt és onnantól ha ```hello()```-t írunk automatikusan az A verziót veszi, de továbbra is elérhető a B verziója ```B::hello()```-t használva. A ```::``` operátor más esetekben is használatos lesz majd még. Amit általánosan tudni kell róla az az, hogy ez egy olyan operátor ami egy fogalmi szinten létező dolgon belüli valamit választ ki. A mostani példánkban egy a fogalomban (névtér) lévő másik fogalmat (függvény) érünk elezzel az operátorral (később lesz másra is példa).

Tehát ha eltávolítjuk a usingos rézt, akkor az iostream-ből ismert dolgok elé kikell rakni az ```std::```-t
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

Egyszerű szöveges fájlt hozunk létre és abban mint szöveg, szerkesztéséhez nem szükséges semmi extra eszköz, egy egyszerű notepad-től, komolyabb fejlesztőkörnyezetig mindennel szerkeszthetjük. Problémák a karakterkódolásoknál jelenhetnek meg, de a tárgy folyamán nem használunk speciális karaktereket, így ezzel nem foglalkozunk.
Általában a kiterjesztése a c/c++ programkód fájloknak **cpp**, **cc** vagy simán **c**, mi és a CodeBlocks is a **cpp**-t fogjuk használni.

## Fordítás

Fordításra nagyon sok mód létezik, viszont a tárgy folyamán legfőképp CodeBlocks-ot fogjuk használni.

### Code Blocks
**Code Blocks** is használható a tárgy alatt, új projekt létrehozása illetve fordítása sokkal egyszerűbb: https://www.youtube.com/watch?v=kYA8rK2fy2U

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
A programozási világban a több soros megjegyzés használata esetén óvatosságra intenek, mert ha pl. van egy 1000 soros kódod és kiakarsz kommentelni 200 sort belőle, de valahol van benne egy 10 soros rész aminél már használtad a több soros megjegyzés, akkor a több soros megjegyzés az 200 soros komment nyitójától fog tartani a 10 soros zárójáig, tehát a 10 soros */-jétől nem lesz kikommentelve a kód. Ahhoz, hogy egy soros kommentelést alkalmazzunk több soron, a legtöbb fejlesztő környezet kínál egy billentyűkombinációt, aminek a segítségével a kijelölt sorok mindegyikét egysoros kommentbe teszi. (Ideiglenes kód eltávolítás miatt pl.)


#  Változók
Nemes egyszerűséggel egy változó az ami valamilyen nemű információt tárol. A változót úgy képzelhetjük el, hogy ha azonosulunk a programmal, hogy mi vagyunk a buta program aki nem tud olyan komplexen gondolkozni, hanem egyszerre csak egy dologra tud koncentrálni. Ha megkérdezed a felhasználót, hogy mondjon egy számot, akkor azt a számot le kell írnod egy lapra és ott hagynod az asztalodon (ami a valóságban a memóriát szimbolizálja), mivel ha nemírod fel elfelejted. 

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

A fenti számos típusokból (a bool nem) létrehozhatunk előjel nélkülit is ha a típus elé írjuk, hogy unsigned: ```unsigned int```.

Note: az általában kifejezés annyit tesz, hogy a mi esetünkben az ELTE-n a gépeken így lesz a félév folyamán.

# Függvények

A programozási nyelvek első egyik legfontosabb eleme a függvények, amik segítségével struktúráltabbá tudjuk tenni a programunkat. A függvényt úgy lehet elképzelni, mint egy doboz amiben ül egy manó te odaadod neki a paramétereket ő meg folyamatosan ugyanazt a feladatot hajtja végre és ha a függvény olyan, hogy visszaad valami választ akkor addig mi ott állunk és tartjuk a kezünket, ha nem akkor is megvárjuk míg végez (kivéve párhuzamos programozás, ami arról szól, hogy nem feltétlenül várjuk meg a függvényt míg végez). Ilyenkor a sorról sorra futásból hirtelen átugrik arra a kódrészletre ami meg lett hívva. A hívást egyszerűen úgy írjuk, hogy megadjuk a függvénynevét és utána zárójelben a paramétereket.
Egy függvény két részből áll: van deklaráció és definíció része.

## Deklaráció

A deklaráció arra szolgál, hogy jelezzük a fordító számára (ami sorról sorra értelmezi a kódot, hasonlóan ahogyan futtatja is), hogy lesz egy ilyen nevű és szignatúrájú függvény (Szignatúra később részletesebben). A deklaráció szerkezete a következő:
```
[Visszatérési érték] [Függvény név]([Paraméterek]);
[Paraméterek] ::= [1. Paraméter típus] [1. Paraméter név], [2. Paraméter típus] [2. Paraméter név] ...
```
Például:
```c++
int max(int a, int b);
```
A kódban ezalatt a deklaráció alatt már akárhol hívhatjuk a ```max``` függvényt függetlenül attól, hogy definiálva lett-e, hogy mit is csinál ez a függvény.

```c++
cout << max(2,3); 
```
Ez természetesen kifogja írni, hogy 3 ha megfelelően definiáljuk később a függvényt. A deklaráció elhagyható és csak a definíció is elég, de később látni fogjuk a hasznát. Ha mégis megakarjuk spórolni a deklaráció leírását, akkor figyeljünk arra, hogy az adott függvény csak onnantól hívható meg a programkódban ha volt deklarálva vagy definiálva.

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

## Összegezve
```c++
#include <iostream>
using namespace std;


int max(int a, int b)

int main(){
  cout << max(2,3);
  return 0;
}

int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}
```
Helyes.

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

int main(){
  cout << max(2,3);
  return 0;
}

```
Helyes.
```c++
#include <iostream>
using namespace std;

int main(){
  cout << max(2,3);
  return 0;
}

int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}

```
Nem helyes, mivel az első hívásnál még a fordító nem tud a max függvényről.
```c++
#include <iostream>
using namespace std;


int max(int a, int b)

int main(){
  cout << max(2,3);
  return 0;
}
```
Nem helyes, mert az értelmezés során a max függvény nem lesz ismertlen számára, de a végén amikor össze akarja rakni a végleges programot a fordító panaszkodni fog, hogy azt állítottad a program elején, hogy lesz max függvény, de végül nem definiáltad, így nem tudja összerakni a programot.

## Szignatúra és overload

Egy függvényt nem csak a neve azonosít hanem az úgynevezett szignatúrája is, ami esetünkben a paraméterek típusa lesz. Az előző példánkban a függvény neve ```max``` volt, a szignatúrája pedig ```int,int```, mivel két paramétert vár és mindkettő int. Ez azért fontos, mert ha ```max(2); ``` parancsot adjuk ki a kódunkban, akkor a fordító panaszkodni fog, hogy nem ismeri a függvényt.

Viszont pont ezt kihasználva, hogy a szignatúra is beleszámít egy függvény azonosításába nem csak a név, tudunk úgymond overloadolni, ami annyit tesz, hogy egy névhez több funkciót is megadunk. 

Például:
```c++
int max(int a, int b, int c){
  return max(max(a,b),c);
}
```
Ezzel a kóddal elérjük azt, hogy ha három paraméterrel hívják meg a max függvényünket akkor már az is fog működni. Ez a függvény teljesen egyszerűen, ha nézzük a definíciót meghívja a két paraméteres maxot. 
*Note: Egyelőre nem törekedünk optimális kód írására, a fő szempontunk, hogy gyorsabban és szebb kódot írjunk.*


##Név változtatás
Az, hogy a hívó függvényben hogy nevezzük el a változókat az teljesen független attól, hogy egy függvényen belül hogy hívjuk.
```c++
#include <iostream>
using namespace std;

int max(int a, int b)

int main(){
  int bela=2;
  int feri=3;
  cout << max(bela,feri);
  return 0;
}

int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}
```
Helyes. A ```max``` függvényen belül az átadott értékek nevei ```a``` és ```b``` lesz a többitől függetlenül.

# Referencia használata
A tárgy óráin általában a http://www.cplusplus.com/ oldalán található leírásokat fogom ajánlani, mivel az oldalon egy függvény használatához általában vannak példák, amik sokat segíthetnek a megértésben.


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

## 0-tól indexelünk

A c++-ban 0-tól indexelünk, tehát ha egy tömb első elemét akarjuk elérni, akkor 0. elemet kérünk le, ha 2.at, akkor 1.t és így tovább. Ennek több oka is van, egyet közülük röviden megemlítek. Ha a memóriában lefoglalunk egy 4 elemű tömböt akkor az úgy történik, hogy a 4 elemű tömb első elemének a helyét jegyezzük csak meg, amit nevezzünk címnek.
Ha az első elemet akarjuk, akkor Cím+0 lesz az 1. elem címe, Cím+1 lesz a 2. elemé és így tovább. C++ tárgy részletesebben kitér erre a gondolatmenetre.

## Dinamizmus problémája

Ezzel a kóddal van egy olyan problémánk, hogy normális esetben egy statikus változó nem lehet dinamikus méretű, ergo ha mondjuk nem tudjuk mennyi bemenő adat lesz, akkor max úgy tudjuk megoldani, hogy létrehozunk egy 1000 nagyságút és imádkozunk, hogy a felhasználó ne akarjon több adatot beadni. Ez egy ideig használható megoldás is lehet, de éles helyzetben egy általánosabb programnál természtesen elfogadhatatlan. 

# Vector 

Ebben az esetben jön segítségünkre a vector, ami eddig progalaphoz képest új. Ez egy úgynevezett osztály, amiről most első szinten annyit kell tudnunk, hogy egy olyan dolog aminek parancsokat tudunk kiadni, kérdezni tudunk tőle, de az hogy az adott feladatot hogy oldja meg az minket egyelőre nem érdekel, de az esetek nagy részében nem is fog. Ez az osztály segít nekünk dinamikusan kezelni tömböket, nem kell foglalkoznunk memóriafoglalásokkal, méretekkel meg semmivel, csak kiadunk neki egy parancsot, hogy mit csináljon és megoldja nekünk.

Ahhoz, hogy használhassunk egy új fejlécfájlt kell includeolnunk, ami meglepő módon a vector lesz. Tehát ahhoz, hogy használni tudjuk a következő sort kell hozzáadni az eddigi kódunkhoz.
```c++
#include <vector>
```

Létrehozása egy kicsit érdekes, mert nem simán ahogy gondolnánk, hogy változó típus és név, mert itt van a típusnak egy paramétere is, amivel azt adjuk meg, hogy miket szeretnénk tárolni ebben a vectorban. Ha nem lenne ilyen támogatás a C++-ban akkor létre kéne hozni minden típusra egy-egy vector osztyált, de mi lenne akkor ha egy saját új típusból szeretnénk vectort csinálni? Hát természetesen nem sikerlüne (egyszerűen legalábbis nem), tehát template paramétert adunk meg a változó létrehozásakor.

Tehát ha mondjuk egy int-ekből álló tömböt akarunk amit v-nek nevezünk, akkor a 
```c++
vector<int> v;
```
kód a nekünk való.:)

Ennek az osztálynak úgy tudunk parancsot adni, azaz egy függvényét meghívni, hogy a neve után teszünk egy pontot majd megadjuk a függvény nevét. A pont operátor lesz a ```::``` operátor párja, mivel a ```.```egy létező dolog részét célozza meg, amíg a ```::``` egy fogalmi dolog részét.

## push_back
Az első és legtriviálisabb függvény az a
```c++
vector::push_back(int)
```
A jelölés ne zavarjon meg minket, a ```vector``` egy fogalom, maga a ```vector``` nem tárol semmit, csak ha létrehozunk egy ilyen változót akkor az fog tudni tárolni elemeket, tehát az lesz egy létező valami. 
A
```c++
vector<int> v;
```
kód esetén a ```v``` a vector osztály egy példánya, ami már egy létező elem, erre már meghívhatjuk a függvényeket.
```c++
v.push_back(4);
```
Ez a Kód annyit fog tenni, hogy a v vektorba ami kezdetben üres berakja a 4-et.

Összerakva:
```c++
#include <iostream>
#include <vector>

int main(){
  std::vector<int> v;
  v.push_back(12);
  return 0;
}
```
vagy 
```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> v;
  v.push_back(12);
  return 0;
}
```

Note: Természetesen az int helyén bármi lehet (A bármire később lesznek korlátaink, de az alapvető típusokra jó lesz). 

Részletesebben: http://www.cplusplus.com/reference/vector/vector/push_back/

## operator[]

Ha csak berakni tudunk az nem túl izgalmas és mivel a tömböt általánosítottuk elég kínos lenne ha nem tudnánk ugyanúgy hivatkozni az elemeire, mint a tömbnek, így a szokásos írásmóddal tudunk hivatkozni egy tömb elemére:

```c++
vector::operator[](unsigned int)
```

```a[1] ``` és ```a.operator[](1) ``` teljesen ekvivalens, később láthatjuk, hogy a többi jelnél is hasonlóan működik.

Tehát  ```v[1] ``` visszaadja a ```v``` vector első elemét (tehát a második elemét, mivel 0-tól indexelünk c-ben, ne feledjük)

Részletesebben: http://www.cplusplus.com/reference/vector/vector/operator[]/
 
## size

```c++
vector::size()
```
Visszaadja a vektor méretét, hogy mennyi elem van benne. Paramétere természetesen nincs.
```c++
v.size()
```

http://www.cplusplus.com/reference/vector/vector/size/


```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> v;
  
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  
  cout << v.size() << endl; //3-at fog kiírni és egy sortörést
  
  for(int a=0;a<v.size()){
    cout << v[a] << endl;  //kiír egy elemet egy cikluslépésben
  }
}
```
Végereményben ki fogja írni a program, hogy 
```
3
3
2
1
```

http://www.cplusplus.com/reference/vector/vector/

## Vector átadása

Egy dologra kell még figyelni nagyon a vector használatánál, az az átadás. A vector mint már említettem egy úgy nevezett osztály, ami egy nagyobb valami, mint például egy int vagy bármi, így a másolása nem feltétlenül szerencsés. Képzeljünk el egy 10 millió elemet tartalmazó vectort és hogy azt ha lemásoljuk, akkor ~40 megát kell másolnunk a memóriában, amit szerencsés elkerülni ha nem feltétlen szükséges.

A c++-ban minden alapesetben másolódik (egy vectornál ez problémát jelenthet, de alap típusoknál nem), tehát ha van a main-ben egy változód amit átadsz és egy függvényben módosítod az értéket az kívülre nem hat.
```c++
#include <iostream>

int test(int a){
  a = 31;
}

int main(){
  int asd = 12;
  test(asd);
  std::cout << asd;
}
```
Ez a program 12-t fog kiírni. 
Van viszont egy kis jelünk amivel megtudjuk mondani a fordítónak, hogy ne másolja le az adott értéket, hanem a függvény belül azzal a változóval dolgozzon amit átadtak neki.
```c++
#include <iostream>

int test(int& a){
  a = 31;
}

int main(){
  int asd = 12;
  test(asd);
  std::cout << asd;
}
```
Ez a program 31-t fog eredményül kiírni, mivel a függvénynek megmondtuk, hogy ne a másolattal dolgozzon.

Figyelni kell arra, hogy ha referencia szerinti paramétert várunk akkor konstans nem lehet, tehát a 
```c++
#include <iostream>

int test(int& a){
  std::cout << a;
}

int main(){
  test(32);
}
```
program fordítási hibát fog eredményezni, mivel egy konstanst nem tud referencia szerint átadni.

Vector esetében a következő a megoldás tehát:
```c++
#include <iostream>
#include <vector>

using namespace std;

void writeVector(const vector<int>& v){
  cout << v.size() << endl; //3-at fog kiírni és egy sortörést
  for(int a=0;a<v.size()){
    cout << v[a] << endl;  //kiír egy elemet egy cikluslépésben
  }
}

int main(){
  vector<int> v;
  
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  
  writeVector(v);
}
```
Itt tartalmaz még egy plusz kulcsszót a program, ami a ```const```. Ez annyit tesz, hogy a hívó félnek garantáljuk, hogy a függvényen belül annak ellenére, hogy referencia szerint adta át nem fogjuk változtatni a vectorját. Ezzel a megoldással elértük azt, hogy ne másolódjon feleslegesen rengeteg adat, viszont a vector védelme megmaradjon (tehát egy függvény suttyomba ne tudja változtatni).

Összefoglalva: 
* Alap típust általában érték szerint adunk át (referencia jel nélkül), kivéve ha kimenetként szeretnénk az adott paramétert használni és direkt abba akarjuk, hogy írjon a függvény.
* Osztályokat, tehát a vector típust lehetőleg mindig referenciaszerint adjunk át (& jellel).

# Tételek 

Ha egy feladatot nagyon sokszor végez el valaki, akkor egy idő után nagyon elkezdi unni. :) Mit tehetünk ilyenkor? Automatizáljuk. A programok pont erre lesznek jók nekünk. Vegyünk például egy egyszerű példát:
Ha egy boltban minden nap meg kell számolnunk az összes bevételt, úgy mint kasszában, ugyanúgy a blokkokon, akkor sokadik nap végére már eléggé unni fogjuk a feladatot. Ezt a programozásban hívjuk összegzési tételnek.

```c++
int s = 0;
for(int i=0;i<billCount;i++){
  s += bills[a]; //s = s + bills[a];
}
```

Másik példaként vehetjük pl. hogy a legerősebb alkoholt keressük a termékek közül. Ekkor annyit tudunk csinálni ha bemegyünk a boltba, hogy megnézzük az első üvegen, hogy hány fokos és ahogy végigmegyünk a soron nézzük folyamatosan, hogy melyik mennyi és mindig megjegyezzük, hogy mi volt eddig a legerősebb alkohol. Ha az ami előtt állunk erősebb mint az eddigi legerősebb, akkor nekem már ezt kell megjegyeznem. Amikor a sor végére érünk akkor (ha a memóriánk nem rossz) emlékszünk, hogy melyik volt az, meg is oldottuk a feladatot. Ez a maximum keresés.

```c++
int m = alc[0]; //megjegyezzük az első fokot
int ind = 0; //megjegyezzük, hogy az első üveg volt eddig a legerősebb (másikat még nem néztünk)
for(int i=0;i<billCount;i++){
   if(alc[a] > m){ //Ha az amit most látunk erősebb akkor megjegyezzük
    m = alc[a];
    ind = a; //hanyadik üveg volt
   }
}
```

# Beolvasás

A beolvasás a kiíráshoz hasonlóan működik ```>>``` jellel, csak a fordítva ```<<```. A jel arra mutat amerre az információ halad.

A példa beolvas egy számot majd kijrja annak kétszeresét:
```c++
#include <iostream>

int main(){
  int a;
  cout << "Adj meg egy számot! ";
  cin >> a;
  
  cout << "A megadott szám kétszerese: " << (a*2) << endl;
  return 0;
}
```

#Feladat 

1. Írjunk egy olyan programot ami a vector használatával bekér számokat 0-ig, majd összegüket kiírja. (bontsuk függvényekre: beolvas összegzés)
2. Írjunk egy olyan programot ami a vector használatával bekéri egy vector méretét (n>=0), majd sorban annyi számot, majd kiírja a beaddot számok maximumát. (bontsuk függvényekre: beolvas összegzés)


