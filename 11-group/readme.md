# Középen lista

Eddig csak arra láttunk példát, hogyha egy rekord végén volt n darab érték amiket az osztályban vectorban tároltunk. Azt könnyedén stringstream és getline használatával meg tudtuk oldani (beolvasunk egy sort a getline-al, majd azt átadjuk egy stringstreamnek és abból olvasunk), úgy hogy az első m darab fix adatot beolvastuk a streamről majd addig olvastunk amíg el nem értük a stream végét. 

Legyen most az osztályunk egy fesztivál adatait tartalmazó osztály. Írjuk meg hozzá a gettereket. (vector túl nagy struktúra, hogy csak úgy visszaadjuk, így ahhoz nem írunk gettert.

```
10000 dubstep 1
10000 jazz classic 10
10000 dubstep 5
12000 norw_black_metal 3
12000 rock 2
12000 dubstep 2
13000 folklore house electro 3
13000 house 2
```


```c++
class Festival{
    int price;
    vector<string> genres;
    int length;
public:

    int getPrice() const {
        return price;
    }

    int getLength() const {
        return length;
    }
    
    friend istream& operator>>(istream& in, Festival &o);
    friend ostream& operator<<(ostream& out, const Festival &o);
};

istream& operator>>(istream& in, Festival &o){
    ///????
    return in;
}

ostream& operator<<(ostream& out,
                    const Festival &o){
    out << o.price << " ";
    for(int a=0;a<o.genres.size();a++){
        out << o.genres[a] << " ";
    }
    out << o.length;
    return out;
}
```

A kiíró operátor nem sokkal bonyolultabb, mint eddig, viszont a beolvasónál sokat kell változtatnuk. Hogyan tudjuk megoldani azt, hogy beolvassunk egy olyan adatot aminek a közepén van egy változó hosszúságú adat.

## Feltételig olvasás

Minden újonnan beolvasott értékre mgenézzük, hogy megfelel-e egy adott feltételnek.

Például a fesztiválos példánk esetében megpróbálunk minden értéket átalakítani int-e és amíg nem sikerül addig berakjuk az értéket a vectorba, máskülönben az már a fesztivál hossza.

```c++
    in >> o.price;
    string tempString;
    o.genres.clear();//Ne felejtsük el clearelni előtte a vectort!
    while(in >> tempString){

        stringstream ss(tempString);
        int tempInt;
        ss >> tempInt;
        if(ss.fail()){
            o.genres.push_back(tempString);
        }else{
            o.length = tempInt;
        }
    }
```

Pro: 
* Egyedi feltételeket tudunk megadni (akár regex: http://www.cplusplus.com/reference/regex/)
* Nem kell azt a korlátozást megadnunk, hogy egy sorban legyen egy rekord (példánk ettől függetlenül kéri, de elhagyható a getline-os rész. Abban az esetben ss helyett egynesen in-ről olvasunk)
* Nem használunk getline-t, így szabadabb lehet az input

Contra:
* Nem működik akkor ha csak annyi a feltételünk, hogy sor utolsó eleme már nem az, de előtte minden más.

### Más mezőtípus

Ha például ilyen az inputunk (stílus helyett számadatok vannak a vectorban, ill az utána lévő adat a dátum) és garantáljuk, hogy a vector adatai nem kezdődnek 20-al, akkor is tudjuk alkalmazni ezt a módszert:
```c++
class Festival{
    int price;
    vector<int> numericalData;
    string date;
...
```

```
10000 1 2 3 4 1 2 2014.03.40
```


```c++
    in >> o.price;
    string tempString;
    o.genres.clear();//Ne felejtsük el clearelni előtte a vectort!
    while(in >> tempString){
        if(tempString.substring(0,2) != "20"){
            stringstream ss(tempString);
            int tempInt;
            ss >> tempInt;
            o.numericalData.push_back(tempInt);
        }else{
            o.date = tempString;
        }
    }
```

A ```substring``` kivágja egy string részét. A példánkban a 0. karaktertől 2 karaktert vág ki, azaz az első két karakterét a stringnek.


### Több adat a vector után

Ha mondjuk berakjuk a fesztivál nevét még a sor végére.
```
10000 dubstep 1 DUBBER
```

Egyszerűen a ciklusban lévő else ágban olvasunk be
```c++
    in >> o.price;
    string tempString;
    o.genres.clear();//Ne felejtsük el clearelni előtte a vectort!
    while(in >> tempString){

        stringstream ss(tempString);
        int tempInt;
        ss >> tempInt;
        if(ss.fail()){
            o.genres.push_back(tempString);
        }else{
            o.length = tempInt;
            in >> o.name; // Simán csak beolvasunk egy értéket plusszba
        }
    }
```

## Ablakos olvasás

Minden lépésben két elemet tartunk bent változókban. Ha sikeresen bent van a pufferünkben kettő érték, akkor tudjuk hogy az első változónkban lévő érték

```c++
    string line;
    getline(in,line);
    stringstream ss(line);
    
    ss >> o.price;
    string tempString;
    string tempString2;
    ss >> tempString; //előreolvasunk egy értéket
    o.genres.clear();
    while(ss >> tempString2){
        o.genres.push_back(tempString);
        tempString = tempString2;
    }

    stringstream ss2(tempString);
    ss2 >> o.length;
```

Pro: 
* Egyszerű és rövid

Contra:
* Attól függően mennyi adat van a vektor után, annál mindig egyel több puffer kell ehhez a megoldáshoz.

### Más mezőtípus

```
10000 1 2 3 4 1 2 2014.03.40
```

Semmi ördöngőség nincs benne csak át kell alakítani a megfelelő helyen.

```c++
    string line;
    getline(in,line);
    stringstream ss(line);
    
    ss >> o.price;
    string tempString;
    string tempString2;
    ss >> tempString; //előreolvasunk egy értéket
    o.genres.clear();
    while(ss >> tempString2){
        stringstream ss2(tempString2);
        int tempInt;
        ss2 >> tempInt;
        o.genres.push_back(tempInt);
        tempString = tempString2;
    }
    o.date = tempString;
```

## Visszatörléses olvasás

A következő módszernek az a lényege, hogy egy string tömbbe beolvassuk az összes adatot, majd ```back``` és ```pop_back``` fügvényekkel megszerezzük az utolsó értéket és kivesszük.

```c++
    string line;
    getline(in,line);
    stringstream ss(line);

    ss >> o.price;
    string tempString;
    
    o.genres.clear(); 
    while(ss >> tempString){
        o.genres.push_back(tempString);
    }
    if(!o.genres.empty()){
        stringstream ss2(o.genres.back());
        ss2 >> o.length;
        o.genres.pop_back();
    }
```

Pro: 
* Könnyen bővíthető vector utáni adatokra

Contra:
* Nem szép megoldási módszer, hogy feltöltünk majd visszatörlünk!!


### Több adat a vector után

Nézzük ismét ezt a példát, ahol a név bekerül még a sor végére:

```
10000 dubstep 1 DUBBER
```

```c++
    string line;
    getline(in,line);
    stringstream ss(line);

    ss >> o.price;
    string tempString;
    
    o.genres.clear(); 
    while(ss >> tempString){
        o.genres.push_back(tempString);
    }
    if(!o.genres.empty()){
        o.name = o.genres.back();
        o.genres.pop_back();
    }
    if(!o.genres.empty()){
        stringstream ss2(o.genres.back());
        ss2 >> o.length;
        o.genres.pop_back();
    }
```

Figyeljünk arra, hogy itt a végétől visszafele szedegetjük le az értékeket így először a legutolsó elembe írunk.
Érdemes a hibát jelezni az istreamen ha nem sikerült beolvasni az adatot úgy ahogy szerettük volna.

## Név olvasás 

A név olvasás gyakori eset, ilyenkor a korábbi technikák egyikét alkalmazzuk majd még az operátoron belül összearkjuk őket újra egy stringgé.

Ha például az adatunk emberek adatait tartalmazza (név, kor, magasság):
```
Kovács Lajos 21 180
Molnár Ilona 24 173
Nagy Péter 26 177
```

A következő kóddal megtudjuk oldani a beolvasást:

```c++
istream& operator>>(istream& in, User &o){
    string line;
    getline(in,line);
    stringstream ss(line);
    
    string tempString;
    vector<string> nameTemp;
    while(ss >> tempString){
        stringstream ss2(tempString);
        int tempInt;
        ss2 >> tempInt;
        if(ss2.fail()){
            nameTemp.push_back(tempString);
        }else{
            o.age = tempInt;
            ss >> o.height; 
        }
    }
    o.name = "";
    for(int a=0;a<nameTemp.size();a++){
        //Csak akkor adunk elé szóközt ha már nem az első tag
        o.name += (a>0?" ":"") + nameTemp[a];
        // += operátor a stringekre meg van írva (konkatenálás)
    }
    return in;
}
```

## fail bit közvetítése

Ami általános fontosságú, hogy amikor ```getline```-t használunk, akkor a hibák elrejtődhetnek, mert az ```istream``` nem fail-el el, csak a ```stringstream```. Ez esetben azt tudjuk tenni, hogy beállítjuk manuálisan a failbitet ha belül olvasási hiba történik.

```c++
in.setstate(std::ios::failbit);
```

Pár példa:
```c++
    string line;
    getline(in,line);
    stringstream ss(line);

    ss >> o.price;
    string tempString;
    
    o.genres.clear(); 
    while(ss >> tempString){
        o.genres.push_back(tempString);
    }
    if(!o.genres.empty()){
        o.name = o.genres.back();
        o.genres.pop_back();
    }
    if(!o.genres.empty()){
        stringstream ss2(o.genres.back());
        ss2 >> o.length;
        o.genres.pop_back();
    }else{//Ha nem tudtuk a két adatunkat beszedni akkor failelünk az istream-nél!
        in.setstate(std::ios::failbit);
    }
```


```c++
    string line;
    getline(in,line);
    stringstream ss(line);
    
    ss >> o.price;
    string tempString;
    string tempString2;
    ss >> tempString; //előreolvasunk egy értéket
    if(ss.fail()){//Két adatnak minden sorban lennie kell, így ha itt fail van akkor gond van
        in.setstate(std::ios::failbit);
    }
    o.genres.clear();
    while(ss >> tempString2){
        stringstream ss2(tempString2);
        int tempInt;
        ss2 >> tempInt;
        o.genres.push_back(tempInt);
        tempString = tempString2;
    }
    o.date = tempString;
```

## Összefoglalva

Sok módon csinálhatjuk a beolvasást, mindig a feladat elején kell végiggondolnunk, hogy érdemes megcsinálni a beolvasást. 

# Csoportosítás


Bonyolítsuk még egy kicsit a dolgot. :)

Ha a fesztiválos inputhoz azt a feladatot kapjuk kérdésként, hogy mondjuk meg, hogy melyik árkategóriában melyik a leghosszabb fesztivál, akkor mit tudunk tenni?

```
10000 dubstep 1
10000 jazz classic 10
10000 dubstep 5
12000 norw_black_metal 3
12000 rock 2
12000 dubstep 2
13000 folklore house electro 3
13000 house 2
``` 

Mondhatnánk azt, hogy kipakoljuk vektorba és hasonlítgatunk sokat, de ha sorbarendezett inputunk van akkor meg tudjuk oldani stílusosabban és gyorsabban a problémát. Csoportosítani fogunk.

Az elvárt output:
```
10000 10
12000 3
13000 3
```

A csoportosítás műveletét viszont nem a mainben fogjuk megcsinálni, hanem a felsorolónkat írjuk át egy kicsit, hogy egyedi felsorolót kapjunk a végén.

## Kimeneti osztály

Az egyedi felrosolónak van egy bemeneti típusa, annak az osztályát már megírtuk ```Festival``` néven, viszont kell egy kimeneti is, ami azon mezőket tartalmazza amiket a felsorolóból szeretnénk kiadni.

```c++
class FestivalGroupedByPrice{
    int price;
    int sumLength;
public:
    int getPrice() const {
        return price;
    }

    int getSumLength() const{
        return sumLength;
    }
};
```

## Egyedi felsoroló

Az egyedi felsoroló hasonló lesz egy sima felsorolóhoz csak egy kicsit másképp fogalmazzuk meg.

* Ugyanúgy lesz ```ifstream```-ünk
* Ugyanúgy lesz egy ```actual``` osztályváltozónk ami az aktuális elemet tárolja.
* Hozzákerül viszont két új adattag
** ```actualGroup``` ami tárolni fogja az aktuális csoportot amit összevontunk egy kimeneti értékké
** ```isFinished``` ami azt fogja jelezni, hogy végeztünk-e

A működési elve az új felsorolónknak, hogy az ```init```-ben a legelején beolvassuk az első sort majd rögtön hívunk egy nextet, ami felolvassa az első csoportot.
A csoport felolvasása úgy megy végbe, hogy addig olvasunk újat és újat, amíg a csoportot azonosító változó egyenlő az első elemével. Ezt az értéket a next elején átadjuk az ```actualGroup``` változónak, tehát csak azzal kell hasonlítgatnunk folyton.
Az olvasás végén az ```actual```-bann a következő csoport első eleme marad, ami viszont nekünk jó, mert az ```init```-ben is úgy indítottunk, hogy egy elemet beolvasunk. Így mondhatjuk azt, hogy az ```actual``` mindig a következő csoport első elemét tárolja, az ```actualGroup``` meg az aktuális csoportot. Ezt fogjuk visszaadni a ```current```-ben.

Amit még meg kell érteni, hogy a finished miért kell. 
Ha az ```isEnd```-ben ```f.fail``` lenne, ahogyan a sima felsorolónál is csináltuk, akkor a mostani egyedi felsorolónk sajnos az utolsó sort már nem listázná ki, mivel az ```actual``` mindig a következő csoport első elemén áll, ami az utolsó csoport esetén nem létezik, ergo ha az utolsó csoport beolvasásra került, akkor az ```f```-el ki fogunk futni, azaz be fog állni a fail flag. Ezt elkerülendő berakunk egy csúsztatást az egészbe és egy változóval jelezzük, hogy vége van-e már a felsorolásnak, amit akkor állítunk be, ha ```next```-et hívnak egy elfailelt inputra.

Az egyedi felsoroló osztályunk: 

```c++
class FestivalGroupedByPriceSeqIn{
    ifstream f;
    bool isFinished;

    FestivalGroupedByPrice actualGroup;
    Festival actual;
public:
    FestivalGroupedByPriceSeqIn(string fname){
        f.open(fname.c_str());
    }
    void init(){
        f >> actual;
        isFinished = false;
        next();
    }
    void next(){
        if(f.fail()){
            isFinished = true;
        }else{
            actualGroup.price = actual.getPrice();
            actualGroup.sumLength = 0;
            while(!f.fail() &&
                actual.getPrice() == actualGroup.price){

                actualGroup.sumLength += actual.getLength();
                f >> actual;
            }
        }
    }
    FestivalGroupedByPrice current() const{
        return actualGroup;
    }
    bool isEnd() const{
        return isFinished;
    }
};
```

### A main 

Ilyenkor nagyon egszerűen írhatunk egy kiíró operátort a kimeneti osztályhoz vagy akár manuálisan ki is írhatjuk a szükséges adatokat:

```c++
int main()
{
    FestivalGroupedByPriceSeqIn en("input.txt");
    for(en.init();!en.isEnd();en.next()){
        cout << en.current().getPrice() << " " <<
                en.current().getSumLength() << endl;
    }
    return 0;
}
```


### Egyéb tételek

A nextben lévő while-ban, amivel csoportosítunk ott tudunk mindenféle tételeket beékelni, amik különböző dolgokat kiszámolnak. Legtöbb esetben csak a ```next``` függvényt kell csak módosítanunk, így a továbbiakban csak azt írom le.

Mit kell tennünk ha átlagot kér a feladat?
```
void next(){
    if(f.fail()){
        isFinished = true;
    }else{
        actualGroup.price = actual.getPrice();
        actualGroup.sumLength = 0;
        actualGroup.count = 0;
        while(!f.fail() &&
            actual.getPrice() == actualGroup.price){
            actualGroup.sumLength += actual.getLength();
            actualGroup.count++;
            
            f >> actual;
        }
    }
}
```

A kimeneti osztály:
```c++
class FestivalGroupedByPrice{
    int price;
    int sumLength;
    int count;
public:
    int getPrice() const {
        return price;
    }

    int getSumLength() const{
        return sumLength;
    }
    
    float getAvgLength() const{
        return (float)sumLength / (float)count;
    }
};
```

Hasonlóan tudjuk a többi függvént is ékelni visszavezetve a tételeinkből. Visszavezetés nem annyira triviális, hogyha például egy szummázást akarunk egyszerre végrehajtani egy kereséssel, mivel a keresési tételünk csak addig megy amíg nem talál elemet, esetünkben a szumma miatt végigfutunk úgyis az algoritmuson.

Ha például azt is akarjuk jelezni az outputban, hogy adott fesztiválon van-e jazz, akkor a következő módon tehetjük azt meg:
```
void next(){
    if(f.fail()){
        isFinished = true;
    }else{
        actualGroup.price = actual.getPrice();
        actualGroup.sumLength = 0;
        actualGroup.count = 0;
        actualGroup.hasJazz = false;
        while(!f.fail() &&
            actual.getPrice() == actualGroup.price){
            actualGroup.sumLength += actual.getLength();
            actualGroup.count++;
            
            if(actual.hasJazz()){
                actualGroup.hasJazz = true;
            }
            
            //Vagy vaggyal: actualGroup.hasJazz = actualGroup.hasJazz || actual.hasJazz(); 
            
            f >> actual;
        }
    }
}
```

A kimeneti osztály:
```c++
class FestivalGroupedByPrice{
    int price;
    int sumLength;
    int count;
    bool hasJazz;
public:
    int getPrice() const {
        return price;
    }

    int getSumLength() const{
        return sumLength;
    }
    
    float getAvgLength() const{
        return (float)sumLength / (float)count;
    }
    
    bool getHasJazz() const{
        return hasJazz;
    }
};
```

```c++
class Festival{
    int price;
    vector<string> genres;
    int length;
public:

    int getPrice() const {
        return price;
    }

    int getLength() const {
        return length;
    }
    
    bool hasJazz() const{
        bool l = false;
        int i = 0;
        while(!l && i < genres.size()){
            l = (genres[i] == "jazz");
            i++;
        }
        return l;
    }
    
    friend istream& operator>>(istream& in, Festival &o);
    friend ostream& operator<<(ostream& out, const Festival &o);
};
```


## Egyedi felsoroló eredményein tétel

Ha Az a kérdésünk, hogy mennyi árkategóriában van Jazz-et tartalmazó fesztivál, akkor csak a main-t kell módosítsuk:

```c++
int main()
{
    FestivalGroupedByPriceSeqIn en("input.txt");
    int count = 0;
    for(en.init();!en.isEnd();en.next()){
        if(en.current().getHasJazz()){
            count++;
        }
    }
    
    cout << count << " Jazz-t tartalmazó kategória van!" << endl;
    return 0;
}
```



