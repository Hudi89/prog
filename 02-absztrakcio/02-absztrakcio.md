## Absztraktáljunk

A beolvas függvényünket absztraktáljuk

### Template

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
#### .txt.txt hiba!
