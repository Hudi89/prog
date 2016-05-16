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
    string line;
    getline(in,line);
    stringstream ss(line);
    
    ss >> o.price;
    string tempString;
    o.genres.clear();//Ne felejtsük el clearelni előtte a vectort!
    while(ss >> tempString){

        stringstream ss2(tempString);
        int tempInt;
        ss2 >> tempInt;
        if(ss2.fail()){
            o.genres.push_back(tempString);
        }else{
            o.length = tempInt;
        }
    }
```

Pro: 
* Egyedi feltételeket tudunk megadni (akár regex: http://www.cplusplus.com/reference/regex/)
* Nem kell azt a korlátozást megadnunk, hogy egy sorban legyen egy rekord (példánk ettől függetlenül kéri, de elhagyható a getline-os rész. Abban az esetben ss helyett egynesen in-ről olvasunk)

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
    string line;
    getline(in,line);
    stringstream ss(line);
    
    ss >> o.price;
    string tempString;
    o.genres.clear();//Ne felejtsük el clearelni előtte a vectort!
    while(ss >> tempString){
        if(tempString.substring(0,2) != "20"){
            stringstream ss2(tempString);
            int tempInt;
            ss2 >> tempInt;
            o.numericalData.push_back(tempInt);
        }else{
            o.date = tempInt;
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
    string line;
    getline(in,line);
    stringstream ss(line);
    
    ss >> o.price;
    string tempString;
    o.genres.clear();//Ne felejtsük el clearelni előtte a vectort!
    while(ss >> tempString){

        stringstream ss2(tempString);
        int tempInt;
        ss2 >> tempInt;
        if(ss2.fail()){
            o.genres.push_back(tempString);
        }else{
            o.length = tempInt;
            ss >> o.name; // Simán csak beolvasunk egy értéket plusszba
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
        stringstream ss2(o.genres.back());
        ss2 >> o.length;
        o.genres.pop_back();
    }
    if(!o.genres.empty()){
        o.name = o.genres.back();
        o.genres.pop_back();
    }
```


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



# Csoportosítás




