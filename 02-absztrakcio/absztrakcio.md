# Általánosítsunk

Előző óra végén eljutottunk egy egyszerű beolvasáshoz, amit most megpróbálunk általánosítani, ami a következő:

```c++
void beolvas(vector<int> &v){
  int a;
  cin >> a;
  
  while(a != 0){
    v.push_back(a);
    cin >> a;
  }
}
```

Alapvetően ha mondatként akarjuk ennek a függvénynek a funkcióját kimondani, akkor egy kis célzott gondolkodás után:) eljuthatunk addig az előző példában látható függvényünknél, hogy: Egész számokat a konzolról beolvas vektorba.
Ezt a mondatot megpróbáljuk általánosítani, amivel végsősoron a függvény funkcióját fogjuk absztraktabbá tenni.

Valamilyen típusú számokat olvasunk be egy valamilyen folyamról vektorba.
A vektor szót azért általánosításával nem foglalkozunk, mert az egyelőre túl bonyolult lenne, de más nyelvekben nagyon szépen általánosítható ez a része is.

## Template

Az első lépés amit általánosítunk, az az, hogy ne csak egész számokat tudjon beolvasni a függvényünk. Ebben segítségünkre lesz a c nyelv egy hasznos része, az úgynevezett template, amit pár egyszerű módosítással megtehetünk. A lényeg, hogy az a célunk, hogy megadható legyen, hogy az adott függvény milyen típussal működjön.
Ha a beolvasást akarjuk általánosítani, akkor egy függő paraméter kell, ami az lesz, hogy milyen típusokat olvassunk be a konzolról.  Ebben az esetben annyi dolgunk van, hogy a függvény neve elég odaírjuk, hogy ```c++template<class T> ``` (általában az előtte lévő sorba szoktuk írni, hogy jobban átlátható legyen). Ha ezt a sort hozzáadtuk akkor mindenhol a függvényben az adott típust amit általánosítani akarunk ki kell cserélnünk ```c++T```-re. (Logikusan ha ```c++template<class Valami> ``` a template paraméter akkor a ```c++Valami```-t kell mindenhova írni.

```c++
template<class T>
void beolvas(vector<T> &v){
  T a;
  cin >> a;
  
  while(a != 0){
    v.push_back(a);
    cin >> a;
  }
}
```
Ez a kód működni fog vector<int> vector<float> típusokra, mert ekkor végigfogja nézni az adott nevű függvényeket és próbál megfelelő szignatúrájút találni. Ha vector<int>-el akarjuk meghívni akkor látja, hogy van olyan hogy vector<T> paraméterű. Ekkor úgy fogja megcsinálni a függvényt, hogy a templateből csinál egy másolatot úgy, hogy minden T helyére berakja a megfelelő típust.

```c++
vector<int> v;
beolvas(v);
```

A függvénytörzsben látható egy cin >> a; itt esetünkben számít, hogy milyen típusú a T, mivel nem mindegy, hogy intet, floatot vagy pl. stringet akarunk beolvasni. De szerencsénkre ezek mind megvannak írva, ez alapján mondhatjuk azt, hogy minden olyan vectorra működni fog ez a függvény ami olyan elemeket tartalmaz amire az STL-ben van >> operátor. (Tehát pl. amit be tudunk olvasni konzolról)

Note: Több template paraméter is használható: ```c++template<class T,class T2> ``` hasonlóan mint a paraméterek.
Note: Programozási nyelvek c++ tárgyon lesz részletesebben a template használata.

### istream

A függvényünk funkciójnak a mondatát általánosítva tovább megyünk arra, hogy ne csak konzolról lehessen beolvasni, hanem valamilyen folyamról.

```c++

template<class T> 
void beolvas(istream &in, vector<T> &v){
...
}

```

```c++
template<class T>
void beolvas(vector<T> &v){
  T a;
  cin >> a;
  
  while(a != 0){
    v.push_back(a);
    cin >> a;
  }
}
```



###
```c++

#include <fstream>


int main(){
  ifstream f("asd.txt");
}
```

#### Honnan fogja olvasni a fájlt 
Alapvetően a válasz egyszerű, ahol fut a programunk, viszont ha CodeBlocks-ban futtatjuk a programot akkor az úgynevezett munkakönyvtár, ahol futni fog a program az a projektfájl mappája, így ha valami inputot be akarunk olvasni relatív útvonallal (pl.: "valami.txt") akkor azt oda tegyük.

#### .txt.txt hiba!

```c++
template<class T> 
void beolvas(vector<T> &v){
  int n; //Érdemes n-et írni, mert azt szokja meg az ember, hogy m és n a számosság
  v.resize(n);
  for(int a=0;a<v.size();a++){
    cin >> v[a];
  }
}
```
