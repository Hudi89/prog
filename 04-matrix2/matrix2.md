# Exception
Előző órán volt egy olyan problémánk, hogy ha a maxot üres vectorral hívtuk meg akkor kifagyott. A kivételes esetek a nagyobb rendszerekben éles esetben is előfordulnak, így fura lenne ha nem lenne nyelvi szinten támogatva ezek kezelése.

C-ben ezeket úgy hívják, hogy Exceptionök. A max alaptétel a következő:
```c++
int max(const vector<int> &v){
    int maxInd = 0;
    int max = v[0];
    for(int a=1;a<v.size();a++){
        if (max < v[a]){
            max = v[a];
            maxInd = a;
        }
    }
    return maxInd;
}
```
Ez a függvény rögtön a 2. sorában kifagy ha üres vektorral akarjuk futtatni, mivel nincs a paraméterül adott vektornak 0. eleme (mivel üres:) ). Még azelőtt a sor előtt meg kell nézni, hogy üres-e a vektor és ha igen akkor valamit csinálni.
De mit is csinálhatunk? Eldobunk egy hibát, ami addig megy felfele a hívó függvényeken amíg el nem kapja valaki vagy a mainből is ki nem repül!

#### Mi az, hogy felfele a hívó függvényeken?
Amikor a programunk elindul akkor meghívódik a main függvény, onnan indul a program. Amikor a main meghív egy függvényt, akkor a kód futása a main-ben ott megáll és folytatódik egy függvényben. Ami ha meghív egy függvényt, akkor szintén megáll és így tovább. Ezeket a hívásokat lehet úgy elképzelni, hogy egyre mélyebben megy a kódban a futás. Amikor tehát eldobunk egy exceptiont, akkor a hívó fél felé indul el az exception (minden függvény megszakítódik adott pontban). Érdemes debuggerrel megnézni hogy működik.

#### De mi az, hogy elkapni?

Egy speciális blokk amivel jelezzük, hogy az adott fajta hibákat mi lekezeljük az adott ponton.

### Hogy is néz ez ki?

Hiba eldobás (bármilyen típust eldobhatunk valójában, most intet fogunk):
```throw 1;``` 
Elfogás:
```c++
try{
   //Ezen belül eldobott hibákat kapja el
}catch(int a){ //az itt megadott típusúakat kapja el
   // Ez fut le ha történt hiba a try blokkban
}
```
De ez így elég csúnyácska, mert ha csak inteket dobálnánk, akkor mindig belefutnánk abba, hogy elkéne kapni és ha nem tudjuk kezelni akkor továbbdobni, hogy kezelje le olyan aki ért hozzá:
```c++
try{
   //Ezen belül eldobott hibákat kapja el
}catch(int a){ //az itt megadott típusúakat kapja el
  switch(a){
    case 404: cout << "Nincs oldal!" << endl; break;
    default: throw a;
  }
}
```
Ez a továbbdobás annyit tesz, hogy a kivételt tovább dobjuk felfelé a hívólistán.

Note: Itt a ```default: throw a;``` annyit tesz, hogy amennyiben a ```switch(){case...}```-ben nem volt rá vonatkozó esetkezelés, dobjon egy kivételt tovább...


# Enum

Új típust létrehozni még nem tanultunk, nem sokkal bonyolultabb. 
```[Létrehozandó típus típusa] [Az új típusunk neve]{[Leírás]};```
A leírás rész különböző típus típusnál változni fog.

Az első amit nézünk az a felsoroló típus, ami arra lesz jó, hogy x darab értéket vehet fel csak, valójában nem sokban különbözik egy ```int```-től, mert az is véges értéket csak vehet fel, csak itt számok helyett magunknak definiált értékek halmazából vehet fel. Ennek a típus típusnak a definíciója annyiból áll, hogy felsoroljuk a ```{}```-k között a lehetséges értékeket és a neve ```enum```.

Tehát egy enum létrehozása:
```enum Rank{OPERATOR,MODERATOR,USER,ADMNIN};```
Ezzel pl. jelezhetjük egy felhasználóról, hogy az milyen ranggal rendelkezik. Ezekre az ```enum```-okra használhatjuk az értékeadást és az összehasonlítást. 
Pl.:
```c++

enum Rank{OPERATOR,MODERATOR,USER,ADMNIN};

int main(){
	Rank userRank = OPERATOR;
	
	if(userRank == MODERATOR){
		
	}else if(userRank != USER){
	
	}
}

```

Note: Ne felejtsük, hogy ezt is csak akkor ismeri fel a fordító, ha feljebb definiáltuk, mint ahol használni szeretnénk.

# Hogy is néz ki akkor az új maxunk?

```c++
#include <iostream>
#include <vector>

using namespace std;

enum Exception {EMPTY_VECTOR, NEGATIVE_COUNT};

int max(const vector<int> &v){
    int maxInd = 0;
    if(v.size() == 0){
    	throw EMPTY_VECTOR;
    }
    int max = v[0];//Ez a sor szál el üres vektor esetén (üres vektornak nincs 0. eleme)
    for(int a=1;a<v.size();a++){
        if (max < v[a]){
            max = v[a];
            maxInd = a;
        }
    }
    return maxInd;
}

istream& operator>>(istream &in, vector<int> &v){
	int n;
	in >> n;
	if(n<0) throw NEGATIVE_COUNT;
	v.resize(n);
	for(int a=0;a<v.size();a++){
		in >> v[a];
	}
	return in;
}

int main(){
	vector<int> v;
	//Teszt adatokkal feltöltjük
	try {
		cin >> v;
		cout << max(v);
	}catch(Exception e){
		switch(e){
			case EMPTY_VECTOR: 
				cout << "Üres vektor!" << endl;
				break;
			case NEGATIVE_COUNT:
				cout << "Bemeneten negatív méretet kaptunk a vektorra!" << endl;
				break;
			default:
				throw e;
		}
	}
	return 0;
}
```

A try blokknak van egy olyan tulajdonsága, hogy amint benne egy exception dobódik, onnantól kilép a try blokkból. Az előbbi példában tehát, ha negatív értéket akarunk számosságnak megadni, akkor láthatjuk, hogy ez fog dobni egy exceptiont (logikusan negatív méret nem létezik, így ez hiba), viszont ezt a main-ben elkapjuk és az utána lévő maximum keresés már nem fog lefutni (hiba esetén nem is lenne sok értelme, tehát nekünk ez a tulajdonság pont nyerő). Ha két külön try-ba raknánk a beolvasást és a maximum keresést, akkor ha a beolvasásba hiba történne akkor utána még megpróbálna lefutni a max függvény is és valószínűleg az is dobna egy hibát, hogy üres a vektor. :)

# Header fájlba szétpakolás

Ahogy az első órán már beszéltünk róla, a header fájlok (fejlécfájlok), amiket pl. használtunk már a ```cin``` és ```cout``` használatához is: ```#inlucde<iostream>```
De most eljött az ideje, hogy saját header fájlokat is létrehozzunk, ami nagyon egyszerű. A menüben a fájl->új->fájl kattintva előjön egy wizard aminek segítségével létrehozhatjuk ezeket. Ha létrehozunk itt egy fájlt és azt includeoljuk valahol akkor teljesmértékben úgy fog működni mintha copy-paste lenne.

A fejlécfájlokat (.h fájlokat) arra használjuk, hogy deklarációkat, leírásokat (típuslétrehozás pl.) tároljunk benne.
A forrásfájlokat (.cpp fájlokat) viszont arra, hogy konkrét futtatandó programkódokat tároljon, tehát függvénytörzseket.

## Header Guard

Képzeljük el azt a szituációt, hogy van egy valaki által írt fejlécfájl, ami beincludeolja a vectort, viszont mi is megtesszük ezt. Ebben az esetben minden kétszer lenne deklarálva ami a fordítónak nem fog tetszeni, mert neki nem tisztje eldönteni, hogy ha kétszer ugyanúgy akarunk megadni egy típust pl. akkor melyik legyen a kettő teljesen egyforma közül. :) (Igen...:D)

Ennek a komoly problémának a megoldására jött létre az úgynevezett header guard, amit nekünk a Code::Blocks automatikusan hozzá fog rakni a headerfájljainkhoz, de azért ismerkedjünk meg vele. A direktíváknál is vannak elágazások, viszont itt a feltételek csak kapcsolók lehetnek, hogy adott érték már be van-e állítva/igaz-e/definiálva volt-e már. Egy ilyen kapcsolót úgy tudunk bekapcsolt állapotra állítani, hogy azt írjuk a kódba, hogy 
```#define ASD```
Ebben az esetben az adott sor kódtól nekünk ez definiálva lesz, tehát ha azt írjuk, hogy
```c++
#ifdef ASD
//A kódrészlet
#else
//B kódrészlet
#endif
```
Akkor ebben az esetben ha a ```define``` fölött történik ez, akkor a ```B``` kódrészlet lesz itt a előfeldogozás után, ha viszont alatta, tehát a kapcsoló már be van állítva mire az ```if```-hez érünk, így az ```if``` igaz lesz, akkor az ```A``` kódrészlet marad. A Header Guardokhoz a tagadó if-et használják:
```#ifndef ASD```
ami annyit tesz, hogy ahelyett hogy azt kérdezénk, hogy ```ASD``` be van-e állítva azt kérdezzük, hogy ```ASD``` nincs beállítva?

Gondoljunk bele, hogy ez van egy header fájlban (asd.h) amit kétszer includeolunk be :
```c++
enum Asd {AAA,BBB};
```
akkor az eredmény a kódunkban:
```c++
#include "asd.h"
#include "asd.h"
```
amiből az lesz, hogy:
```c++
enum Asd {AAA,BBB};
enum Asd {AAA,BBB};
```

Itt viszont kétszer van definiálva ugyanarra a névre egy típus, erre a fordító ki fog akadni.:)
Viszont, ha az asd.h tartalmazza a guardot:
```c++
#ifndef ASD_H
#define ASD_H
enum Asd {AAA,BBB};
#endif
```

Ebből lesz:
```c++
#ifndef ASD_H
#define ASD_H
enum Asd {AAA,BBB};
#endif
#ifndef ASD_H
#define ASD_H
enum Asd {AAA,BBB};
#endif
```
Ekkor az első esetben nincs még definiálva az **ASD_H**. Így az ottani rész az azt követő ```#endif```-ig érvényes lesz, tehát az ott lévő ```#define ASD_H``` direktíva is.
A második ```#ifndef```-nél viszont már definiálva van az **ASD_H**, így az abban az elágazásban lévő kódrészlet kivágásra kerül. Tehát az eredmény:
```c++
enum Asd {AAA,BBB};
```
:)

Az ilyen direktívás ifeket szokták (régebben legalábbis, már manapság nem túl elterjedtek) arra is használni, hogy debug szinteket definiáljanak:
```c++
int max(const vector<int> &v){
    int maxInd = 0;
    if(v.size() == 0){
	    #ifdef DEGUB_MAX
	    	cout << "Empty vector passed to max: throwing exception!" << endl;
	    #endif
    	throw EMPTY_VECTOR;
    }
    int max = v[0];//Ez a sor szál el üres vektornak esetében (üres vektornak nincs 0. sora)
    #ifdef DEGUB_MAX
    	cout << "First element is " << v[0] << ", so this is the max now" << endl;
    #endif
    for(int a=1;a<v.size();a++){
	    #ifdef DEGUB_MAX
	    	cout << "Next element is " << v[a] << ", comparing to " << max << endl;
	    #endif
        if (max < v[a]){
            max = v[a];
            maxInd = a;
		    #ifdef DEGUB_MAX
		    	cout << "Find a new max " << max << " in the " << maxInd << " position." << endl;
		    #endif
        }
    }
    return maxInd;
}
```
Ebben az esetben, ha a függvény előtt definiáljuk a **DEBUG_MAX** kapcsolót, akkor ki fog írni mindent a **max** futása közben a programunk, viszont ha nem definiáljuk, akkor nem ír ki semmit. 
Miért jobb ez mint egy kódbeli változótól függő if? Mert ez a kész termékbe nem fordul bele, mivel még fordítás előtt kidobódnak az adott kiírós részek ha a kapcsoló nincs definiálva. Ennek köszönhetően nem fogja feleslegesen lassítani a sok-sok felesleges if mindenhol a végső kódot, illetve kisebb is lesz.

## Fordítás

A fordítás során a CPP fájlok mentén fordítunk, tehát azokkal foglalkozik a fordító, a fejlécfájlokat simán include-al bemásoljuk. 
### Preprocessor
Első körben a preprocesszor (ez foglalkozik a #-os direktívákkal) dolgozza fel a fájlokat és csinál belőlük .i fájlokat. Ez a formátum még szöveges, de elég olvashatatlan, mivel ez már egy előkészített formátum a konkrét fordításhoz. (Nem könnyű előszedni ezeket a fájlokat, mert ezek csak ideiglenesen jönnek létre)
### Fordítás
Második körben jön maga a fordítás. Ekkor minden .i fájlból létrejön egy .o fájl (ezeket a .o fájlokat már megtalálhatjuk a Code::Blocks projektek esetében a build mappában). Ebben a fázisban a fordító még nem foglalkozik adott függvények konkrét kifejtésével, elég ha a deklarációikról tud. Például eddig is amíg fordítódott a mi main.cpp-énk nem panaszkodott a fordító, hogy nem találja a vector definícióját, mert amikor beincludeoltuk a ```<vector>``` -t, akkor abban benne volt, hogy lesz egy ilyesmi. A függvényeit viszont a **linker** rakja hozzá majd a következő lépésben.

### Linkelés
Ezek után mihelyt minden .o fájl kész van, jön a linker (Nem lineáris keresés, hanem LINK-er), ami a különböző kódszeleteket összekapcsolja. Ekkor fogja megnézni, hogy létezik-e minden deklarációhoz megfelelő definíció valamelyik cpp-ben. 

A Linkelésnél van egy olyan probléma, hogy ha a definíciókat is a fejlécfájlokba tartanánk, akkor az két .o fájlba fordulna bele és akkor a linker nem tudná eldönteni, hogy melyik legyen a mérvadó (Igen, megint két ugyan olyan definició között nem tud különbséget tenni, de megvan ennek is az oka), tehát ezért kell a CPP-ékbe rakni a definíciókat és csak a deklarációkat a headerfájlokba.

Viszont van egy kivétel, ami a template. Mivel ott előjön a probléma, hogy ha a cppbe rakjuk a templatet:
- Fordul a main.cpp (ebben használjuk a templatünket), a deklarációját látjuk a h fájlban a template-nek, így megnyugszunk, hogy majd linkelés közben lesz hozzá definíció
- Fordul a seged.cpp (ebben van a templateünk amire a main-ben hivatkozunk): itt nézi a függvényeket, de a templatekből nem csinál egy rendes függvényt sem, mivel nincs rá hivatkozás (beszéltük, hogy a template C-ben sajnos olyan buta, hogy szinte copy-paste módon csinál másolatot azokból a függvényekből adott típusra amire használják őket)
- A linkerhez viszont eljutva szembesülünk azzal, hogy nincs adott típusra létrehozott függvénydefiníció

Ezt úgy tudjuk megoldani, hogy a seged.cpp-ben megadjuk, hogy milyen altípusokra használhatják a templatünket (nem túl biztonságos, mivel a header fájlban nincs megszabva, így fordítási időben nem tűnik fel, csak linkeléskor ha olyan típussal akarjuk használni ami nincs), illetve nem működik a x dimenziós beolvasás sem.
```c++

template<typename T>
int max(const vector<T> &v){
    int maxInd = 0;
    T max = v[0];
    for(int a=1;a<v.size();a++){
        if (max < v[a]){
            max = v[a];
            maxInd = a;
        }
    }
    return maxInd;
}
template void max<int>(const vector<int> &v); 
template void max<float>(const vector<float> &v); 
```
De láthatjuk, hogy ez nem a legjobb megoldás, tehát maradjunk annál, hogy a templatek esetében a fejlécfájlban tartjuk a definíciókat is.

# Feladat
1. (FTM-cnt(<5)>2,sum) Egy lovaglótusán keressük a nyertest, de a király úgy döntött, hogy mindenkit aki több mint két versenyszámban kevesebb mint 5 pontot ér el azt lefejezteti. (Ne feledjük, hogy mivan ha a király mindenkit lefejeztetett)
