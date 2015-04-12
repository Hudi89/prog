# Komplex számhalmaz

## Osztály 
Egy osztály nagyon hasonló mint egy struct annyi különbséggel, hogy minden változója és függvénye titkos alapesetben.

```private``` - titkos, azaz kívülről ezek a függvények és változók nem érhetőek el
```public``` - mindenki által elérhető és módosítható változók és meghívható függvények

```c++
class Coord{
  int x;
  int y;
public:
  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  
  void setX(int v){
    x = v;
  }
  void setY(int v){
    y = v;
  }
}

Coord operator+(const Coord a, const Coord b){
  Coord ret;
  ret.setX(a.getX()+b.getX());
  ret.setY(a.getY()+b.getY());
  return  ret;
}

double norma2(Coord a){
  return a.getX()*a.getX() + a.getY()*a.getY();
}

ostream& operator<<(ostream& out, const Coord &c){
    out << c.getX() << " " << c.getY();
    return out;
}

int main(){
  Coord a;
  Coord b;
  
  cout << a + b;
}
```
A példában az x és 

## Függvény bevitele az osztályba

Ahogy eddig írtunk függvényeket azt szoktuk úgy hívni, hogy globális térbe írjuk a függvényt, mivel csak úgy magába a fájlba írjuk, viszont most hogy vannak osztályaink, így a függvényeket tudjuk ragasztani az osztályhoz is. Olyan függvényeket tudunk bevinni az osztályba aminek az első paramétere maga az osztály és akkor
```norma(a)``` helyett ```a.norma()``` formában fogjuk hívni a függvényt.

```c++
class Coord{
  int x;
  int y;
public:
  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  
  void setX(int v){
    x = v;
  }
  void setY(int v){
    y = v;
  }
  
  Coord operator+(const Coord b){
    Coord ret;
    ret.setX(getX()+b.getX());
    ret.setY(getY()+b.getY());
    return  ret;
  }
  
  double norma2(){
    return getX()*getX() + getY()*getY();
  }
}

ostream& operator<<(ostream& out, const Coord &c){
    out << c.getX() << " " << c.getY();
    return out;
}

int main(){
  Coord a;
  Coord b;
  
  cout << a + b;
}
```
De mivel az osztályban vagyunk már benn, így már a privát zónában lévő dolgok elérhetőek lesznek, így a getter setter helyett hivatkozhatunk egyenesen a változókra is. De ezt megtehetjük az operátorral is, ha jelezzük az osztályban, hogy az adott függvény a haverunk. Ezt úgy tehetjük meg, hogy a függvény deklarációját bemásoljuk az osztályba és elé írjuk a ```friend``` operátort.
```c++
class Coord{
  int x;
  int y;
public:
  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  
  void setX(int v){
    x = v;
  }
  void setY(int v){
    y = v;
  }
  
  Coord operator+(const Coord b){
    Coord ret;
    ret.x = x+b.x;
    ret.y = y+b.y;
    return  ret;
  }
  
  double norma2(){
    return x*x+y*y;
  }
  
  friend ostream& operator<<(ostream& out, const Coord &c);
}

ostream& operator<<(ostream& out, const Coord &c){
    out << c.x << " " << c.y;
    return out;
}

int main(){
  Coord a;
  Coord b;
  
  cout << a + b;
}
```


Amire figyelni kell: 
* A fordító a cpp-ket egyenként fordítja le, így ha két cpp-ben includeolunk be azonos h fájl és abban van egy függvénydefiníció akkor a linker azt fogja mondani, hogy kétszer van definiálva, mert mind a két o fájlba belegenerálja a fordító, mivel mind a két cpp-be belekerült az include hatására (Mint korábban mondtam az include kb. copy-paste-nek felel meg)
* Ha const osztályra akarunk meghívni egy függvényt, akkor csak úgy lehetséges, ha az adott függvény konstans, amit úgy érünk el, hogy a függvény deklarációjában a () után írjuk, hogy const:
```c++ int getSomething() const { return something; }```
* ```using namespace std;```-t header file-ban nem használunk (ha más használja a kódunkat akkor rákényszerítenénk vele, hogy azt a namespacet használja amit mi)
* Érdemes
