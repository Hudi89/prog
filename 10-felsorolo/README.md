#Felsoroló

Ahogy az órák alatt nagyon sokszor az általánosítást vettük fókuszba, most is azt fogjuk. Nézzünk meg egy egyszerű alaptételt:

```c++
int sum(const vector<int> &v){
  int s = 0;
  for(int a=0;a<v.size();a++){
    s += v[a];
  }
  return s;
}
```

Az ```int``` típust template-el könnyedén kitujduk általánosítani, viszont ahhoz hogy igazán általánosak lehessünk, ahhoz azt is kikéne általánosítani, hogy milyen az az input. Most fixen vector lehet csak.
Most, hogy már tudunk osztályt csinálni készíthetünk egyet ami elfedi előlünk és általánosabban fogalmaz.

Egy felsoroló osztályt fogunk csinálni, ami a nevét nem meghazudtolva annyit csinál csak, hogy felsorol elemeket. De milyen elemeket? Ha templatet használunk bármilyet, anélkül egy fixet. 
Miért jó ez? Megtudjuk úgy csinálni a függvényeinket, hogy ne függjenek már szinte semmitől és akkor teljeskörűen feltudjuk őket újra használni.

Mit is várunk el egy ilyen felsoroló osztálytól? Alakítsuk át az összegzés függvényünket úgy, hogy valami felsorolóból jönnek az értékek mágikusan.

```c++
template<typename T>
int sum(Enumerator<T> &e){
  int s = 0;
  for(e.init();!e.isEnd();e.next()){
    s += e.current();
  }
  return s;
}
```

Ez alapján már definiálhatjuk az osztályunkat:
```c++
//Az Enumerator osztály felelős azért, hogy egy elem sorozaton végigiteráljon.
//Egyszerre mindig csak egy elemre mutat ami a tagfüggvényekkel léptethető csak előre.
template<typename T>
class Enumerator{
public:
  //Inicializálja a felsorolót, az elejére áll az inputnak
  virtual void init() = 0;
  //Jelzi, hogy vége-e van-e már az inputnak (Ha igen, akkor a current értéke ismeretlen)
  virtual bool isEnd() const = 0;
  //A következő felsorolandó elemre lép
  virtual void next() = 0;
  
  //Visszaadja, hogy mi az aktuális elem amin a felsoroló áll
  virtual T current() const = 0;
};
```
De mit is jelent ez az ```= 0```? Arra jó, hogy meg tudunk adni függvényeket, amit majd a gyerekekben definiálni kell, így kötelezővé tehetjük, hogyha bárki csinál egy ilyen ```Enumeratort```, akkor a szükséges tagfüggvények létezni fognak. 

Ha szépen akarunk dolgozni akkor ebből az osztályból tudunk származtatni egy osztályt ami megvalósítja az eddigi függvényeket.

```c++
template<typename T>
class VectorEnumerator : public Enumerator<T>{
private:
  vector<T> data;
  int pointer;
public:
  
  VectorEnumerator(const vector<int> &v){
    data.resize(v.size());
    for(int a=0;a<v.size();a++){
      data[a] = v[a];
    }
  }

  void init(){
    pointer = 0;
  }
  bool isEnd() const{
    return pointer >= data.size();
  }
  void next(){
    pointer++;
  }
  T current() const{
    return data[pointer];
  }
};
```

Ha ez az osztályunk kész van akkor máris használhatjuk az új szumma függvényünket sima int vektorra, mivel ez egy ```Enumerator``` úgy mint ahogy a ```ifstream``` is egy ```istream```. 
```c++

int main(){
  vector<int> v;
  cin >> v; //Ez a függvény ismert, már nagyon sokszor megírtuk.:)
  VectorEnumerator<int> ve(v);
  cout << sum(ve);
}

```

De hogy valami értelmét is lássuk az egésznek, definiáljuk a fájl felsorolót, amivel el tudjuk érni azt, hogy nem kell letárolnunk az inputot egy vectorban, hanem egyenesen a fájlból tudunk feldolgozni.

```c++
template<typename T>
class FileEnumerator : public Enumerator<T>{
private:
  T actualData;
public:
  
  FileEnumerator(const string filename){
    f.open(filename.c_str());
  }
  
  ~FileEnumerator(){
    f.close();
  }

  void init(){
    next();
  }
  bool isEnd() const{
    return f.fail(); 
  }
  void next(){
    f >> actualData;
  }
  T current() const{
    return actualData;
  }
};
```

Ekkor a main függvényünk:

```c++
int main(){
  FileEnumerator<int> fe("asd.txt");
  cout << sum(fe);
}
```

Tehát optimálisabbak is lettük és rövidebbek is.:)
Természetesen az egészet tudjuk származtatás nélkül is megoldani, de láthatjuk, hogy sokban nem különbözik a megoldás:

```c++
class IntFileEnumerato{
private:
  int actualData;
public:
  
  IntFileEnumerato(const string filename){
    f.open(filename.c_str());
  }
  ~IntFileEnumerato(){
    f.close();
  }
  
  void init(){
    next();
  }
  bool isEnd() const {
    return f.fail() || f.eof(); 
  }
  void next(){
    f >> actualData;
  }
  int current() const{
    return actualData;
  }
};
int main(){
  IntFileEnumerator fe("asd.txt");
  cout << sum(fe);
}
```
Ezeket a felsorolókat szokás hívni, szekvenciális inputnak is, aminek létezik felsoroló párja is.


##Feladat

Készítsük el azt a programot ami megmondja, hogy a környező bolygók közül melyik a legközelebbi bolygó ahol legalább 10 millió az összlakosság.
Az inputunk olyan formájú, hogy minden sor egy bolygó és először a nevét adjuk meg a bolygónak majd a koordinátáit és végül fixen 4 számot ami megadja, hogy a négy ismert fajból mekkora a népesség az adott bolygón (Millióban megadva).
```
asd 2.3 3.1 0 0 0 0  
bsd 3.1 4.1 1 0 5 2
csd 3.1 4.1 1 4 5 1
```
Itt például csak a```csd``` bolygón elég a lakosság, így az lesz a legközelebbi is.
