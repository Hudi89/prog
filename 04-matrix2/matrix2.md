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

Az első amit nézünk az a felsoroló típus:

# Menü írás

írjunk egy menüt amin ki lehet választani, hogy konzol vagy fájl illetve újrafuttatás

```c++
void menukiir();

int main()
{
    int parancs;
    vector<int> asd;
    cin >> asd;

    menukiir();
    bool futE=true;
    
    while (futE)
    {
    	cin >> parancs;
        switch (parancs)
        {
            case 0: asd.clear(); cin >> asd; break;
            case 1:cout << maxker(asd);break;
            case 2:cout << szum(asd);break;
            case 3:futE=false;break;
        }
	    menukiir();	
    }
    return 0;
}

void menukiir()
{
    cout << "0. Beirni az adatokat" << endl;
    cout << "1. Maxker" << endl;
    cout << "2. Feltmaxker" << endl;
    cuot << "3. Kilepes" << endl;
}

```

# Header fájlba szétpakolás


# Feladat
1. 
