
# Vector az osztályban

Könnyen előfodrulhat, hogy az osztályunk nem csak egyszerű adattagokból áll össze, hanem bonyolutabb más osztályokat is tartalmaz. Nézzük meg, hogy hogy változik egy kódunk ha egy egyszerű vizsgát meghatározó osztályba berakunk egy vectort is ami példánkban azt jelzi, hogy milyen érdemjegyek születtek a vizsgán.
 
A kezdő osztályunk váza.
```
class Exam{
private:
    std::string courseName;
    int credit;
    std::string dateTime;
public:
    friend std::ostream& operator<<(std::ostream& out, const Exam &o);
    friend std::istream& operator>>(std::istream& in, Exam &o);
};
std::ostream& operator<<(std::ostream& out, const Exam &o){
    out << o.courseName << " " << o.credit << " " << o.dateTime;
    return out;
}
std::istream& operator>>(std::istream& in, Exam &o){
    in >> o.courseName >> o.credit >> o.dateTime;
    return in;
}
```
Ennek a beolvasása a szokásos vectorokat beolvasó fügvényeinkel mennek, mivel megírtuk hozzá az operátorokat amik egy ```Exam``` beolvasásáért felelősek, azokat meg úgy írtuk meg, hogy bármely típusra működik amire megvannak írva ezek az operátorok.

Ha bővítjük az osztály tagjait egy vectorral, akkor valójában azt kell végiggondolnunk, hogy hogyan változik meg a beolvasás és kiírás.
Legyen példánkban egy vizsgának a formátuma a következő:
```Prog 7 2016-04-14 5 4 4 4 5 1```
Ahol az első három adat értelemszerűen az eddig is jelen lévő három adattagnak felel meg, utána felsorolásszerűen az érdemjegyek a sor végéig.

Előszöris vegyünk fel egy új mezőt az osztályunkba:
```vector<int> grades;```

## Hogyan lehetne egyszerűbben?

Ha ugyanúgy ahogy eddig csináltuk megjelöljük a számosságot egy vector elején majd felsoroljuk az elemeket, akkor valójában semmi extrát nem kell csinálunk ahhoz képest amit eddig csináltunk.

```Prog 7 2016-04-14 6 5 4 4 4 5 1```
Ebben az esetben a beolvasónk úgy nézne ki, hogy:
```
std::istream& operator>>(std::istream& in, Exam &o){
    in >> o.courseName >> o.credit >> o.dateTime;
    int n;//Beolvassuk, hogy hány jegy született adott vizsgán
    in >> n;
    o.grades.resize(n);//Méretezzük a vektort
    for(int a=0;a<n;a++){
        in >> o.grades[a];//Egyenként a létező helyerke beolvasuk a jegyeket
    }
    return in;
}
```

## Új módszer

Ha meg akarjuk tartani az első felvetett formátumot akkor egy sort ki kell emelnünk mindig és abból beolvasni a különböző adattagokat. Ennek megoldására létezik egy függvény ami egy adott istream-ről beolvas egy sort. Ez a függvény a ```std::getline```
```
std::istream& operator>>(std::istream& in, Exam &o){
    string temp;
    std::getline(in,temp);
    return in;
}
```

###De hogy lesz ebből float int satöbbi?

A másik dolog amit használunk az új módszerhez az a ```std::stringstream```. Ez az osztály leegyszerűsítve annyit csinál, hogy stringre építve olyan viselkedést nyújt, mint amit már a ```cout``` és ```cin``` párostól megszokhattunk anélkül, hogy bármilyen fájlt vagy streamet használna. Itt a stream központja egy ```string```, ami csak az adott ```stringstream```-ben létezik.
Ehhez viszont includeolnunk kell a ```sstream``` fejlécfájlt.

```
#include <sstream>
```
és 
```
std::istream& operator>>(std::istream& in, Exam &o){
    string temp;
    std::getline(in,temp);
    std::stringstream ss;
    ss << temp; //beleküldjük a stringet a streamünkbe
    ss >> o.courseName >> o.credit >> o.dateTime; //kiolvassuk az adatokat
    
    //A megmaradt rész a 5 4 4 4 5 1, amik az érdemjegyek
    return in;
}
```

### Hogyan tudunk olvasni egy stream végéig?

Ahogyan ```cin```-nél és minden ```istream```-nél, a ```stringstream```-nek is van egy olyan függvénye, hogy ```fail()```. Ez a függvény azt adja vissza, hogy történt-e valami hiba a beolvasás közben. Hibák közé sorolható az a hiba, hogy rossz formátumó volt az input, de az is, hogy egy adott stream végére értünk és már nem sikerült a beolvasás (fájl esetében fájl végéig).
Ami fontos, hogy a ```fail``` akkor fog igazat visszaadni csak ha már volt egy hibás beolvasás, tehát nem jó az a megoldás, hogy
```
std::istream& operator>>(std::istream& in, Exam &o){
    string temp;
    std::getline(in,temp);
    std::stringstream ss;
    ss << temp; //beleküldjük a stringet a streamünkbe
    ss >> o.courseName >> o.credit >> o.dateTime; //kiolvassuk az adatokat
    
    while(ss){
        int tempGrade;
        ss >> tempGrade;
        o.grades.push_back(tempGrade);
    }
    return in;
}
```
mivel ekkor lesz egy plusz hozzáadás. A beolvasás hibás, de utána van egy berakás, tehát a hibásan beolvasott érték bekerül a vektorba.

A megoldás az előreolvasás:
```
std::istream& operator>>(std::istream& in, Exam &o){
    string temp;
    std::getline(in,temp);
    std::stringstream ss;
    ss << temp; //beleküldjük a stringet a streamünkbe
    ss >> o.courseName >> o.credit >> o.dateTime; //kiolvassuk az adatokat
    
    int tempGrade;
    ss >> tempGrade; //beolvasunk egyet előre
    while(!ss.fail()){//ha jó volt a beolvasás
        o.grades.push_back(tempGrade); //hozzáadjul
        ss >> tempGrade; //és beolvasunk egy újat
    }
    return in;
}
```

### Hogy csinálhatjuk mégrövidebben?

Ha egy istream-et berakunk egy if-be, tehát azt akarjuk, hogy logikai értékként értékelődjön ki, ekkor az istreamek úgy viselkednek, hogy csak akkor lesz igaz, ha minden rendben van, ellenkező esetben hamisat. Ezt kihasználva tudjuk rövidíteni a kódot a következőre:
```
std::istream& operator>>(std::istream& in, Exam &o){
    string temp;
    std::getline(in,temp);
    std::stringstream ss;
    ss << temp; //beleküldjük a stringet a streamünkbe
    ss >> o.courseName >> o.credit >> o.dateTime; //kiolvassuk az adatokat
    
    int tempGrade;
    while(ss >> tempGrade){//Beolvasunk egyet, ami ha sikeres volt
        o.grades.push_back(tempGrade); //akkor hozzáadjuk
    }
    return in;
}
```

### A szokásos vector beolvasásunkkal nem jó.

Ha ezt a függvényt a szokásos beolvasásunkkal együtt használjuk, akkor gondba leszünk, mivel be fog olvasni egy üres sort. Az indok egyszerű.

Az input fájlunk:
```
3
Prog 7 2016-04-14 5 4 4 4 5 1
Anal 2 2016-04-15 2 2 1 3 2 5 1 2
Dimat 2 2016-06-12 3 3 4 2 1 1 2 3 2 1
```

A beolvasó függvényünk:
```
template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &v2){
    int n;
    in >> n;
    v2.resize(n);
    for(int a=0;a<n;a++){
        in >> v2[a];
    }
    return in;
}
```

Ha jól megfigyeljük a beolvasó függvény beolvas egy darab számot majd beolvassa a T típusú elemeket. Ha a T típusú elemnek a beolvasó operátora úgy van megírva, hogy egy sort kér be, akkor viszont problémánk lesz.
Az első int beolvasása után a fájlban közvetlenül a hármas szám után fogunk tartani. Ekkor jön az első elem olvasása, ami getline-al kezdődik, így be fogja olvasni azt a 0 karaktert ami a hármas szám és a sortörés között van.:)

#### Gyors megoldás 1. 

```
3 Prog 7 2016-04-14 5 4 4 4 5 1
Anal 2 2016-04-15 2 2 1 3 2 5 1 2
Dimat 2 2016-06-12 3 3 4 2 1 1 2 3 2 1
```

Ebben az esetben a probléma nem fog felmerülni természetesen, mivel itt már nincs sortörés a számosság és az első sor között.

#### Gyors megoldás 2.

```
template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &v2){
    int n;
    in >> n;
    v2.resize(n);
    string temp;
    getline(in,temp);
    for(int a=0;a<n;a++){
        in >> v2[a];
    }
    return in;
}
```

Ez működik a fent megadott inputunkra, de elég erőltetett.

#### Szép megoldás

Egyszerűen dobjuk ki az inputunkból a számosságot. Legyen tehát az inputunk:
```
Prog 7 2016-04-14 5 4 4 4 5 1
Anal 2 2016-04-15 2 2 1 3 2 5 1 2
Dimat 2 2016-06-12 3 3 4 2 1 1 2 3 2 1
```

Ahogyan tudtunk egy stringstream végéig olvasni, úgy tudunk olvasni egy fájl végéig hasonló módon. Tehát a következő kóddal jól fog működni a beolvasásunk:

```
template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &v){
    T temp;
    in >> temp;//előreolvasunk egyet
    while(!in.fail()){ //ha nincs hiba (ergo nincs fájl vége pl.) akkor
        v.push_back(temp); //berakjuk
        in >> temp; //és beolvasunk egy újat
    }
    return in;
}
```

Note: Ha bármi miatt sikertelen a beolvasás, akkor ugyanúgy le fog állni a ciklusunk. Van erre is függvény ```istream::eof```. Ha ezt használjuk a hibákra figyeljünk oda, hogy kezelve legyenek.


### Probléma merül fel

Ekkor ha lefuttatjuk ap programunkat, láthatjuk, hogy valamiért a vectorok halmozódva olvasódnak be, ez meg pontosan amiatt van, mert az ```operator>>(std::istream& in, std::vector<T> &v)```-ban a cikluson kívül van defininálva egy ```T``` típusú elemünk amiben van egy vector, tehát amikor a következő beolvasásához érünk, bár az értékek simán felülíródnak, a vector nem mivel ott ```push_back```-et használtunk. Be kell raknunk az osztályt beolvasó függvénybe egy olyat, hogy töröljük a vectort a beolvasás elején. Erre a vector osztálynak van egy külön parancsa, ami a ```clear()```

Tehát:

```
std::istream& operator>>(std::istream& in, Exam &o){
    string temp;
    std::getline(in,temp);
    std::stringstream ss;
    ss << temp; //beleküldjük a stringet a streamünkbe
    ss >> o.courseName >> o.credit >> o.dateTime; //kiolvassuk az adatokat
    
    o.grades.clear();
    int tempGrade;
    while(ss >> tempGrade){//Beolvasunk egyet, ami ha sikeres volt
        o.grades.push_back(tempGrade); //akkor hozzáadjuk
    }
    return in;
}
```

# Enum az osztályban

Adjunk hozzá egy olyan tulajdonságot az osztályunkhoz, hogy szóbeli vagy írásbeli az adott vizsga.

```
class Exam{
public:
    //Szóbeli vagy írásbeli
    enum Type{
        ORAL,
        WRITTEN
    };

    //Kivételek kezeléséhez egy enum
    enum Exception{
        UNDHANDLED_TYPE_TO_OUTPUT,
        UNKNOWN_TYPE_TO_READ
    };
private:
    std::string courseName;
    int credit;
    std::string dateTime;
    Type type; //Hozzáadjuk a változót

    std::vector<int> grades;
public:
    friend std::ostream& operator<<(std::ostream& out, const Exam &o);
    friend std::istream& operator>>(std::istream& in, Exam &o);
};
```
Az új típusokat az osztályon belülre raktuk, mert valójában erős részei az osztálynak. Ekkor az osztály úgy viselkedik, mint egy névtér, tehát a ```Exam::Type``` módon tudunk rá a main-ből is hivatkozni például.

Enumnál nem akarjuk kihasználni, hogy valójában számok, hanem lehetőleg írjuk ki szövegesen az inputba is ezeket az értékeket, mivel:
* Ha például bekerül egy plusz enum érték az elejére, akkor elcsúszik minden érték és az rossz.:) 
* Amikor adatbázisban olvasunk, akkor nem kell mindig kikeresni, hogy adott szám minek felel meg, hanem rögtön látjuk.
* Egy pár karakteres tömör string sem sokkal több terület, mint egy szám.


```
std::ostream& operator<<(std::ostream& out, const Exam &o){
    out << o.courseName << " " << o.credit << " " << o.dateTime << " ";

    switch(o.type){
        case Exam::ORAL: out << "ORAL"; break;
        case Exam::WRITTEN: out << "WRITTEN"; break;
        default:
            throw Exam::UNDHANDLED_TYPE_TO_OUTPUT;
    }

    for(int a=0;a<o.grades.size();a++){
        out << " " << o.grades[a];
    }
    return out;
}

std::istream& operator>>(std::istream& in, Exam &o){
    string temp;
    getline(in,temp);

    stringstream ss;
    ss << temp;
    ss >> o.courseName;
    ss >> o.credit >> o.dateTime;

    string typeString;
    ss >> typeString;

    if(typeString == "ORAL"){
        o.type = Exam::ORAL;
    }else if(typeString == "WRITTEN"){
        o.type = Exam::WRITTEN;
    }else if(in.good()){ //good függvény az a fail ellentéte
        throw Exam::UNKNOWN_TYPE_TO_READ;
    }

    o.grades.clear();
    int tempGrade;
    while(ss >> tempGrade){
        o.grades.push_back(tempGrade);
    }

    return in;
}
```

Ha olyan esetre futnánk amit nem tudunk kezelni akkor dobunk hibát, hogyha esetleg valaki később berak egy új elemet az enumba akkor ne maradjon visszajelzés nélkül, hogy valami probélma van. Debug időt spórolunk ezzel.

Az ```UNKNOWN_TYPE_TO_READ``` hibát csak akkor dobjuk el, hogyha még a streamünk aktuális, mert a külső függvényünk úgy működik, hogy addig olvas amíg egy beolvasás nem lesz hibás, tehát történik egy hibás beolvasás is. Ha a beolvasásunk hibás, akkor az már a kifutó menet, tehát akkor nem akarunk hibát dobni.


# Feladat

## Cica

Állapítsuk meg az átlagos tejindexet a cicák között.
Egy cica tejindexe úgy számolandó, hogy összeadjuk a fogyasztott tejmennyiségeket, majd leosztjuk a súlyával.

Név Súly [vector: fogyasztott tejmennyiségek]
```
Cirmos 80 1 2.3 4 5.1 7 58
Cian 3 0.1 0.3 21 
Tigris 4 1.1 3 4 5
Alfred 4 6 3 1 
Cauchy 30 10 10 10
```

## Sleep

Állapítsuk meg, hogy a vizsgára készülés alatt ki tudott a legtöbb alvási ciklust abszolválni.

Egy alvási ciklus csak ha teljes akkor érvényes.

```
Bela 18 1.2 1.2 0.2 3.2 10 12 0.1
Feri 19 1.0 1.0 0.1 0.1 0.1 0
Gizi 21 2.0 6.0 2.0 3.0 1.0
```
Név Kor AlvásiCiklus idő [Vector: Alvási idők]
