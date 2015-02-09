# 1. Gyakorlat - Alapok

A Programozás című tárgy előfeltétele a Programozási alapismeretek című tágy, így annak anyagát ismertnek vesszük és csak egy rövid áttekintés erejéig érintjük a teljesség igénye nélkül.

## Alapok

### A programkód 

```c++
int main(){
  int b=2;
  b++;
  cout << b;
  for(int a=0;a<b;a++){
    cout << "Hello!" <<endl;
  }
  return 0;
}
```
Miket mondhatunk el általánosan egy programkódról!
* Sorról sorra fut (Szigorúan)
* 

### Fordítás (Linux & Konzol esetében)

```bash
g++ main.cpp
```
A programkódunk egyszerűen fordítható a fájl megadásával a g++ parancs után és a.out néven fogja elkészíteni a futtatható állományt (ezt az állományt linux alatt ./a.out parancsal tudjuk futtatni). 
-o kapcsolóval megadhatjuk a kimeneti fájl nevét is, hogy ne a.out néven mentse el.
```bash
g++ main.cpp -o kicsiprogram
```
Ebben az eseteben ./kicsiprogram fogja logikusan elindítani a programunkat (Nem kell kiterjesztés, nem is szokás).

Később több fájlt fordítása esetén alkalmazhatjuk a 
```bash
g++ main.cpp masik.cpp harmadik.cpp -o kicsiprogram
```
vagy 
```bash
g++ *.cpp -o kicsiprogram
```
parancsot.



Részletesen: http://linux.die.net/man/1/g++

### Változók
A változó a program futásához szükséges kellék, ami valamilyen nemű információt tárol. A változót úgy képzelhetjük el, hogy ami
Egy változónak van *élettartama* ameddig az adott változó létezik a memóriánkban.

#### "Manuális futtatás"

| Kódsor | a | b |
| ----- | - | - |
|int b=2;|Ismeretlen|Ismeretlen|


### Kommentelés
