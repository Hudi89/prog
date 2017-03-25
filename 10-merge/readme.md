# Alap tételek felsorolóval

Valósítsunk meg először egy valamilyen rekord osztályt, majd annak kiíró és beolvasó operátorát. Írjunk minden adattaghoz egy gettert, mivel egyik sem érzékeny adat, így kívülről olvashatóvá tehetjük őket nyugodtan.
```c++
class Minion{
    string name;
    int eyeNumber;
    
    //Number between 0 and 1 
    float annoyFactor;
    bool hasGlass;
public:

    string getName() const{
        return name;
    }
    int getEyeNumber() const{
        return eyeNumber;
    }
    float getAnnoyFactor() const{
        return annoyFactor;
    }
    bool getHasGlass() const{
        return hasGlass;
    }

    friend istream& operator>>(istream& in, Minion& o);
    friend ostream& operator<<(ostream& out, const Minion& o);
};

istream& operator>>(istream& in, Minion& o){
    in >> o.name >> o.eyeNumber >> o.annoyFactor >> o.hasGlass;
    return in;
}

ostream& operator<<(ostream& out, const Minion& o){
    out << o.name << " " << o.eyeNumber << " "  << o.annoyFactor << " " << o.hasGlass;
    return out;
}
```


Majd vegyük elő az előző órán felépített szekvenciális felsoroló osztályt, most származtatás nélkül.

```c++
template<class T>
class SeqInFile{
private:
    ifstream f;
    T actual;
public:
    SeqInFile(string fname){
        f.open(fname.c_str());
    }

    void init(){
        f >> actual;
    }
    void next(){
        f >> actual;
    }
    T current() const{
        return actual;
    }

    bool isEnd() const{
        return f.fail();
    }
};
```

Ehhez az eddigiekben egy egy dimenziós tételt csináltunk meg, úgy mint pl.:

Átlagoljuk az inputban szereplő minyonok szemszámát.
```c++
int main(){
    SeqInFile<Minion> in("input.txt");
    int s = 0;
    int count = 0;
    for(in.init();!in.isEnd();in.next()){
        s += in.current().getEyeNumber();
        count++;
    }
    
    cout << (float)s/(float)count << endl;
}
```
Számoljuk meg mennyi szemüveges van a csapatban.
```c++
int main(){
    SeqInFile<Minion> in("input.txt");
    int count = 0;
    for(in.init();!in.isEnd();in.next()){
        if(in.current().getHasGlass()){
            count++;
        }
    }
    
    cout << count << endl;
}
```

Ki a legidegesítőbb?
```c++
int main(){
    SeqInFile<Minion> in("input.txt");
    int count = 0;
    
    in.init();
    if(!in.isEnd()){
        float maxVal = in.current().getAnnoyFactor();
        string maxKey = in.current().getName();        
        for(in.next();!in.isEnd();in.next()){
            if(in.current().getHasGlass()){
                float actVal = in.current().getAnnoyFactor();
                if(actVal > maxVal){
                    maxVal = actVal;
                    maxKey = in.current().getName();
                }
            }
        }
        cout << maxVal << endl;
    }else{
        cout << "The sequence is empty!" << endl;
    }
}
```

Mindenki szemüveges?
```c++
int main(){
    SeqInFile<Minion> in("input.txt");
    bool l = true;
    for(in.init();l && !in.isEnd();in.next()){
        l = in.current().getHasGlass();
    }
    
    cout << (l?"Yes":"no") << endl;
}
```

# Kiválogatás és szekvenciális output

## Kiválogatás

Ha egy adott feltétel szerint kell nekünk elemeket visszadni, például, hogy adjuk meg a szemüveges minyonokat, akkor egy egyszerű if-el megtudjuk tenni.


```c++
int main(){
    SeqInFile<Minion> in("input.txt");
    
    for(in.init();l && !in.isEnd();in.next()){
        if(in.current().getHasGlass()){
            cout << in.current().getName() << endl;
        }
    }
}
```

Viszont ha van szekvenciális felsorolónk, akkor szekvenciális kimenetünk is lehetne általánosítás képpen, mert most így beégettük, hogy csak a cout-ra ír ki és nem tudjuk egyszerűen cserélni.

## Szekvenciális output

Hasonlóan a szekvenciális inputhoz, definiálhatunk szekvenciális outputot, viszont ez nagyságrendileg egyszerűbb osztály lesz, mivel egy függvény is elegendő hozzá. Ez a függvény lesz amin keresztül egy értéket átadhatunk a szekvenciális outputnak.

```c++
template<class T>
class SeqOut{
public:
    virtual void write(const T &v) = 0;
};
```

Definiálhatjuk több módon a szekvenciális outputot:

Az egyik ha simán konzolos kimenetként definiáljuk.
```c++
template<class T>
class SeqOutConsole : public SeqOut<T>{
public:
    void write(const T &v){
        cout << v << endl;
    }
};
```

Ekkor a mainünk általánosabb lesz egy picit:
```c++
int main(){
    SeqInFile<Minion> in("input.txt");
    SeqOutConsole<Minion> out("out.txt");
    
    for(in.init();l && !in.isEnd();in.next()){
        if(in.current().getHasGlass()){
            out.write(in.current());
        }
    }
}
```

De definiálhatunk fájlba kimenetet is.

```c++
template<class T>
class SeqOutFile : public SeqOut<T>{
    ofstream f;
public:
    SeqOutFile(string fname){
        f.open(fname.c_str());
    }
    void write(const T &v){
        f << v << endl;
    }
};
```

```c++
int main(){
    SeqInFile<Minion> in("input.txt");
    SeqOutFile<Minion> out("out.txt");
    
    for(in.init();l && !in.isEnd();in.next()){
        if(in.current().getHasGlass()){
            out.write(in.current());
        }
    }
}
```

Vagy akár olyat ami egyszerre a kettőre kiír:

```c++
template<class T>
class SeqOutFileAndConsole : public SeqOut<T>{
    ofstream f;
public:
    SeqOutFileAndConsole(string fname){
        f.open(fname.c_str());
    }
    void write(const T &v){
        f << v << endl;
        cout << v << endl;
    }
};
```
```c++
int main(){
    SeqInFile<Minion> in("input.txt");
    SeqOutFileAndConsole<Minion> out("out.txt");
    
    for(in.init();l && !in.isEnd();in.next()){
        if(in.current().getHasGlass()){
            out.write(in.current());
        }
    }
}
```

Láthatjuk, hogy maga a függvényünk nem kell hogy változzon semmit, csak az output típusát változtatjuk meg és kész. Ezt hasonlóan függvénybe is kiemelhetjük és ha ott a paraméter típusának ```SeqOut```-ot adunk meg, akkor bármilyen osztály ami gyereke a ```SeqOut```-nak és megvalósítja a write függvényt, használható kimenetként. Például a fenti 3 mód, de akár küldhetjük rögtön egy szervernek is vagy bármi.


# Csoportosítás

Mi történik viszont ha több fájlban van egyszerre az inputunk? Hogy tudjuk ezeket összerakni? Mi van ha például Fred mindkét fájlban benne van. Mi van ha az a feladatunk, hogy két fájlban vannak jelenlétek az adott eseményen és azt kell meghatároznunk, hogy ki volt mindkettőn, vagy hasonlók.

Első ötletként az jön, hogy beolvasunk minden elemet és minden elemet egyesével a másik input minden elemével összehasonlítunk és ha találunk olyat aki mindkét inputban benne van akkor ott volt mindkét eseményen.

Ez a megoldás sajnos nagyon sok műveletet igényel, mert mindkét inputon nekünk n-szer kell végigmenni. 

Hogy tudnánk ezt megoldani gyorsan?

Ha teszünk egy olyan plusz feltételt, hogy az *inputjaink sorbarendezettek*, akkor tudunk olyan algoritmust adni ami mindkettő inputunkon csak egyszer megy végig.

Az algoritmusnak a lényegi eleme, hogy két szekvenciális inputot hozunk létre amelyeket párhuzamosan vagy a kettő közül a megfelelőt léptetjük. 
A metszet keresés esetében amikor az egyik input le van maradva, azaz az az érték ami szerint az az input rendezve van hátrébb van, akkor csak azt léptetjük. Minden azt léptetjük ami le van maradva. Így el fogunk jutni olyan állapotokra, hogy a két inputunk azonos azonosítóval rendelkező rekordokra lép. Ha azonost találunk akkor meg simán kiírjuk az outputra. 

## Metszet

Tegyük fel tehát, hogy az inputjaink sorbarendezettek név szerint például és a feladatunk az, hogy megadjuk, hogy kik voltak mindkét ülésen ott például.

```c++
int main(){
    SeqInFile<Minion> in1("input.txt");
    SeqInFile<Minion> in2("input2.txt");

    SeqOutFileAndConsole<Minion> out("out.txt");
    in1.init();
    in2.init();
    
    while(!in1.isEnd() && !in2.isEnd()){ // addig megyünk amíg mindkét inputban még van valami, ha egyik elfogyott akkor már több metsző elemet nem találunk
        if(in1.current().getName() < in2.current().getName()){ 
            in1.next();
        }else if(in2.current().getName() < in1.current().getName()){
            in2.next();
        }else{//in1.current() == in2.current()
            out.write(in1.current());
            in1.next();
            in2.next();
        }
    }
}
```

Az új tételeink közül a metszet a legkönnyebb, most nézük a legnehezebbet.

## Unió

Mi a teendő akkor ha az a feladatunk, hogy mondjuk meg, hogy ki az aki legalább az egyik ülésen volt. Ekkor szintén össze kell fésülnünk, viszont minden ágnál ki kell írnunk. De ez sajnos önmagában nem elegendő.
Amit változtatnunk kell a metszethez képest:
* Mindhárom ágban kiiratunk.
* A cilkus addig megy amíg legalább az egyik input még nem ért véget
* Ha az első input véget ért akkor mindig a 2. ágnak kell lefutnia 
* Ha a 2. input ért véget akkor mindig az 1. ágnak kell lefutnia

```c++
int main(){
    SeqInFile<Minion> in1("input.txt");
    SeqInFile<Minion> in2("input2.txt");

    SeqOutFileAndConsole<Minion> out("out.txt");
    in1.init();
    in2.init();
    
    while(!in1.isEnd() || !in2.isEnd()){
        if( in2.isEnd() ||
               (
               !in1.isEnd() &&
               in1.current().getName() < in2.current().getName()
               )
           ){
            out.write(in1.current());
            in1.next();
        }else if(
                 in1.isEnd() ||
                 (
             !in2.isEnd() &&
            in2.current().getName() < in1.current().getName())

                 ){
            out.write(in2.current());
            in2.next();
        }else{//in1.current().getName() == in2.current().getName()
            out.write(in1.current());
            in1.next();
            in2.next();
        }
    }
}
```
Az 1. és 2. ifben figyeljük meg, hogy valójában ugyanaz mint ha azt írtuk volna, hogy:
```c++
 if( in2.isEnd() ||
               (
               !in1.isEnd() && !in2.isEnd()
               in1.current() < in2.current()
               )
           ){           
```
Ha a 2. inputnak vége van VAGY egyiknek sincs vége és az elsőben kisebb az érték. De mivel a C++-ban lusta kiértékelés van így ha az egy vagy operátor bal oldalán igaz van akkor a jobb oldali résszel már nem is foglalkozik hanem belép a feltételmagba, akkor ebből tudhatjuk, hogy az if jobb oldala csak akkor fut le, ha a bal oldalon nem volt igaz.

Az eddigiek alaján a szimmetrikus differencia és a különbség már nagyon egyszerű. Az únióból könnyedén vissza tudjuk építeni őket.

## Kivonás

```c++
while(!in1.isEnd()){
    if( in2.isEnd() ||
           (
           !in1.isEnd() &&
           in1.current().getName() < in2.current().getName()
           )
       ){
        out.write(in1.current());
        in1.next();
    }else if(!in2.isEnd() &&
        in2.current().getName() < in1.current().getName()
             ){
        in2.next();
    }else{//in1.current() == in2.current()
        in1.next();
        in2.next();
    }
}
```

## Szimmetrikus differencia

```c++
while(!in1.isEnd() || !in2.isEnd()){
    if( in2.isEnd() ||
           (
           !in1.isEnd() &&
           in1.current().getName() < in2.current().getName()
           )
       ){
        out.write(in1.current());
        in1.next();
    }else if(
             in1.isEnd() ||
             (
         !in2.isEnd() &&
        in2.current().getName() < in1.current().getName())

             ){
        out.write(in2.current());
        in2.next();
    }else{//in1.current() == in2.current()
        in1.next();
        in2.next();
    }
}

```


# Feladatok

## Bevásárlólista
Két bevásárló lista egyesítése úgy, hogy az output listán a darabszám és az összeg összeadódjon.
```
AUTO 1 EGYSEG 3000000
CSOKI 5 TABLA 1500
TEJ 1 LITER 200
```

## Boltocska

Különbség

1. input Terméknyilvántartás 
2. input Ami fogyott ma

Határozzuk meg a másnapi nyilvántartást. Az inputok terméknév szerint sorbarendezettek.
Bemenet 1.:
```
Kenyer 20 kg
Majom 3 doboz
Padlizsan 4 csokor
TEJ 50 L
```

Bemenet 2.:
```
Kenyer 2 kg
Padlizsan 4 csokor
TEJ 10 L
```

Kimenet:
```
Kenyer 18 kg
Majom 3 doboz
TEJ 40 L
```
