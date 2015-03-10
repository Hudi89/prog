# !!!Under Construction!!!

# Exceptionn
Előző órán volt egy olyan problémánk, hogy ha a maxot üres vectorral hívtuk meg akkor kifagyott. A kivételes esetek a nagyobb rendszerekben éles esetben is előfordul, így fura lenne ha nem lenne nyelvi szinten támogatva ezek kezelése.

C-ben ezeket úgy hívják, hogy Exceptionök. A max alaptétel a következő:
```c++
int max(const vector<int> &v){
    int maxInd = 0;
    int max = v[0];
    for(int a=0;a<v.size();a++){
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
Amikor a programunk elindul akkor meghívódik a main függvény, onnan indul a program. Amikor a main meghív egy függvényt, akkor a kód futása a main-ben ott megáll és folytatódik egy függvényben. Ami ha meghív egy függvényt akkor szintén megáll és így tovább. Ezeket a hívásokat lehet úgy elképzelni, hogy egyre mélyebben megy a kódban a futás. Amikor tehát eldobunk egy exceptiont, akkor a hívó fél felé indul el az exception (minden függvény megszakítódik adott pontban). Érdemes debuggerrel megnézni hogy működik.

#### De mi az, hogy elkapni?

Egy speciális blokk amivel jelezzük, hogy az adott fajta hibákat mi lekezeljük az adott ponton.

### Hogy is néz ez ki?

Hiba eldobás (bármilyen típust eldobhatunk valójában, most intet fogunk):
```c++throw 1;``` 
Elfogás:
```c++
try{
   //Ezen belül eldobott hibákat kapja el
}catch(int a){ //az itt megadott típusúakat kapja el
   // Ez fut le ha történt hiba a try blokkban
}
```
De ez így elég csúnyácska, mert ha csak inteket dobálnánk, akkor mindig belefutnánk abba, hogy elkéne kapni és ha nem tudjuk kezelni akkor továbbdobni, hog kezelje le olyan aki ért hozzá:
```c++
try{
   //Ezen belül eldobott hibákat kapja el
}catch(int a){ //az itt megadott típusúakat kapja el
  switch(a){
    case 404: cout << "Nincs oldal!" << endl; break;
    default throw a;
  }
}
```
Ez a továbbdobs annyit tesz, hogy ahogy az exception repül felfelé a hívólistán


# Enum

Új típust létrehozni még nem tanultunk, nem sokkal bonyolultabb. 
```[Létrehozandó típus típusa] [Az új típusunk neve]{[Leírás]};```
A leírás rész különböző típus típusnál változni fog.

Az első amit nézünk az a felsoroló típus, ami arra lesz jó, hogy x darab értéket vehet fel csak, valójában nem sokban különbözik egy ```int```-től, mert az is véges értéket csak vehet fel, csak itt számok helyett magunknak definiált értékek halmazából vehet fel. Ennek a típus típusnak a definíciója annyiból áll, hogy felsoroljuk a ```{}```-k között a lehetséges értékeket és a neve ```enum```.

Tehát egy enum létrehozása:
```c++ enum Rank{OPERATOR,MODERATOR,USER,ADMNIN};```
Ezzel pl. jelezhetjük egy felhasználóról, hogy az milyen ranggal rendelkezik. Ezek az ```enum```-okra használhatjuk az értékeadást és az összehasonlítást. 
Pl.:
```c++

enum Rank{OPERATOR,MODERATOR,USER,ADMNIN};

int main(){
	Rank userRank = OPERATOR;
	
	if(userRank == MODERATOR){
		;
	}else if(userRank != USER){
	
	}
}

```

Note: Ne felejtsük, hogy ezt is csak akkor ismeri meg a fordító, ha feljebb definiáltuk, mint ahol használni szeretnénk.

# Hoz néz ki akkor az új maxunk

```c++
#include <iostream>

using namespace std;

enum Exception {EMPTY_VECTOR, NEGATIVE_COUNT};

int max(const vector<int> &v){
    int maxInd = 0;
    if(v.size()){
    	throw EMPTY_VECTOR;
    }
    int max = v[0];//Ez a sor szál el üres vektornak esetében (üres vektornak nincs 0. sora)
    for(int a=0;a<v.size();a++){
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
	if()
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

A try blokknak van egy olyan tulajdonsága, hogy ahogy a függvények excetion esetén a blokk maga is megszakad. Az előbbbi példában tehát, ha negatív értéket akarunk számossságnak megadni, akkor láthatjuk, hogy el fog dobni egy exceptiont (logikusan negatív méret nem létezik, így ez hiba), viszont ezt a main-ben elkapjuk és az utána lévő maximum keresés már nem fog lefutni (hiba esetén nem is lenne sok értelme, tehát nekünk ez a tulajdonság pont nyerő). Ha két külön try-ba raknánk a beolvasást és a maximum keresést, akkor ha a beolvasásba történne hiba akkor lefutna a max és valószínűleg az is dobna egy hibát, hogy üres a vektor. :)

# Header fájlba szétpakolás

Ahogy az első órán már beszéltünk róla, a header fájlok, amiket pl. használtunk már a kiírás és beolvasás használatához is: ```c++ #inlucde<iostream>```
De most eljött az ideje, hogy saját ilyen fájlokat is létrehozzunk, ami nagyon egyszerű. A menüben a fájl->új->fájl kattintva előjön egy wizard aminek segítségével létrehozhatunk header fájlokat. Ha létrehozunk itt egy fájlt és azt includeoljuk valahol akkor teljesmértékben úgy fog működni mintha copy-paste lenne.

A fejlécfájlokat (.h fájlokat) arra használjuk, hogy deklarációkat, leírásokat (típuslétrehozás pl.) tároljunk benne.
A forrásfájlokat (.cpp fájlokat) viszont arra, hogy konkrét futtatandó programkódokat tároljon, tehát függvénytörzseket.

## Header Guard

Gondoljunk bele, hogy ez van egy header fájlban (asd.h) amit kétszer includeolunk be :
```c++
enum Asd {AAA,BBB};
```
akkor az eredmény a kódunkban:
```c++
#include "asd.h"
#include "asd.h"
```
Ebből lesz:
```c++
enum Asd {AAA,BBB};
enum Asd {AAA,BBB};
```

Itt viszont kétszer van definiálva ugyanarra a névre egy típus, erre a fordító nemet fog modani.:)
Viszont, ha az asd.h tartalmazza a guardot:
```c++
#ifndef ASD_H
#define
enum Asd {AAA,BBB};
#ifndef
```

Ebből lesz:
```c++
#ifndef ASD_H
#define
enum Asd {AAA,BBB};
#ifndef
#ifndef ASD_H
#define
enum Asd {AAA,BBB};
#ifndef
```


## Fordítás

A fordítás során a CPP fájlok mentén fordítunk, tehát azokkal foglalkozik a fordító, a fejlécfájlokat simán include-al bemásoljuk. 
### Preprocess
Első körben a preprocesszor (ez foglalkozik a #-os direktívákkal) dolgozza fel a fájlokat és csinál belőlük .i fájlokat. Ez a formátum még szöveges, de elég olvashatatlan, mivel ez már egy előkészített formátum a konkrét fordításhoz. (Nem könnyű előszedni ezeket a fájlokat, mert ezek mint köztes állapotok léteznek csak)
### Fordítás
Második a körben maga a fordítás, ekkor minden .i fájlból létrejön egy .o fájl (ezeket a .o fájlokat már megtalálhatjuk a CodeBlocks projektek esetében a build mappában). Ebben a fázisban még a fordító nem foglalkozik adott függvények konkrét létezésével, elég ha a deklarációról tud. Például eddig is amíg fordítótodd a mi main.cpp-nk nem panaszkodott a fordító, hogy nem találja a vector definícióját, mert amikor beincludeoltuk a ```<vector>``` -t, akkor abban benne volt, hogy lesz egy ilyesmi. A függvényeit viszont a linker rakja hozzá majd a következő lépésben.

### Linkelés
Ezek után mihelyt minden .o fájl kész van, jön a linker (Nem lineáris keresés, hanem LINK-er) ami a különböző kódszeleteket összekapcsolja, ekkor fogja nézni, hogy létezik-e minden deklarációhoz megfelelő definíció valahol valamelyik cpp-ben. 

A Linkelésnél van egy olyan probléma, hogy 


# Feladat
1. (FTM-cnt(<5)>2,sum) Egy lovaglótusán keressük a nyertest, de a király úgy döntött, hogy mindenkit aki több mint két versenyszámban kevesebb mint 5 pontot ér el azt lefejezteti. (Ne feledjük, hogy mivan ha a király mindenkit lefejeztetett)
