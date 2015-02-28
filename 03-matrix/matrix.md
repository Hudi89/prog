

# Általánosítunk tovább

Előző óra végén eljutottunk egy olyan beolvasási függvényhez, ami folyam illetve típusfüggetlen és ráadásul >> operátorként használhatjuk.

```c++
template <typename T>
istream& operator>>(istream& in,vector<T> &myvector)
{
    unsigned int n=0;
    in >> n;
    myvector.resize(n);
    for(int i=0;i<n;i++)
    {
        in >> myvector[i];
    }
    return in;
}
```

Ennek a beolvasás függvénynek van egy nagy ereje: alapvetően ez a függvény működik mindenre ami egy vectort akar beolvasni függetlenül attól, hogy mi van benne. A gondolatmenetet követve feltehetünk egy kérdést, hogy: akkor vector is lehet benne? Amire természetesen helyeslő a válasz.

Ha csinálunk egy olyan vectort ami vectorokat tartalmaz, akkor máris eljutottunk egy mátrixhoz. 
```c++
vector< vector<int> > v;
vector< vector<float> > v2;
```
Ez kb. úgy néz ki, hogy van egy vector amiben vannak vectorok és azokban a számok. Így természetesen a sorok szélességei lehetnek különbözőek, de ez minket nem zavar. De akkor nézzük a beolvasó operátorunkat a fejezet elején: Ha egy ilyen vector-vector-int-re (olyan vector, ami olyan vectorokat tartalmaz ami inteket tartalmaz vagy inteket tartalmazó vectorok vectora) ráhívjuk a >> operátorunkat akkor vajon, befogja tudni olvasni?
Előző fejezetben beszéltünk, hogy mindenre jó a beolvasó függvényünk a template miatt azokra amire az istream képes, tehát amiely típusokhoz van >> operátor. Viszont a mátrix beolvasásához szükségünk lenne arra, hogy vectort be tudjunk olvasni, viszont ugyanezt a függvényt már használtuk vector beolvasásához és most ugyanezt akarjuk használni vector-vector-int beolvasására.  Ezt nyugodt szívvel meg is tehetjük, mert ha a kódban írunk egy olyat, hogy:

```c++
vector< vector<int> > v;
cin >> v;
```
Ekkor a ```c++cin >> v```-t a fordító átalakítja ```c++operator>>(cin,v)```-re, ezután megpróbál keresni egy olyan függvényt aminek azonos a szignatúrájá. Az általunk írt ```c++operator>>(istream&,vector<T>)```-t meg is találja úgy, hogy a ```c++T``` típus ```c++vector<int>```. Ebben a függvényben viszont viszont meghívódik egy ```c++T```-re a ```c++operator>>(istream&,vector<int>)```, ebben az esetben meg a template a már eddig látott módon elkészül és az fog lefutni.

## Többszörös visszavezetés 

Azzal, hogy így rekurzíve betudunk olvasni több dimenziós adatot is (az operátorunk logikusan akármennyi egymásba ágyazott vektorra működne.

## Hogy találjunk ki feladatokat

