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

enum Exception {URES_VEKTOR};

int max(const vector<int> &v){
    int maxInd = 0;
    if(v.size()){
    	throw ;
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
			case URES_VEKTOR: 
				cout << "Üres vektor!" << endl;
				break;
				
			default:
				throw e;
		}
	}
	return 0;
}
```

A try blokknak van egy olyan tulajdonsága, hogy ahogy a függvények excetion esetén 



# Header fájlba szétpakolás

Ahogy az első órán már beszéltünk róla, a header fájlok, amiket pl. használtunk már a kiírás és beolvasás használatához is: ```c++ #inlucde<iostream>```
De most eljött az ideje, hogy saját ilyen fájlokat is létrehozzunk, ami nagyon egyszerű. A menüben a fájl->új->fájl kattintva előjön egy wizard aminek segítségével létrehozhatunk header fájlokat. Ha létrehozunk itt egy fájlt és azt includeoljuk valahol akkor teljesmértékben úgy fog működni mintha copy-paste lenne.


# Feladat
1. (FTM-cnt(>=3)>=1,sum)
