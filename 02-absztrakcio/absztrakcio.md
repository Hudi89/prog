## Általánosítsunk

Előző óra végén eljutottunk egy egyszerű beolvasáshoz, amit most megpróbálunk általánosítani.
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


A beolvas függvényünket absztraktáljuk

### Template

A


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


### istream

```c++

template<class T> 
void beolvas(istream &in, vector<T> &v){
...
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
