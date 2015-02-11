# 1. Gyakorlat - Alapok

A Programozás című tárgy előfeltétele a Programozási alapismeretek című tágy, így annak anyagát ismertnek vesszük és csak egy rövid áttekintés erejéig érintjük a teljesség igénye nélkül.

## Alapok

Egy programot úgy foghatunk fel mint egy ember által sokszor elvégzett feladat formalizálását. Például ha azt a feladatot kapod a boltban, hogy nézd át minden nap zárás után, hogy van-e esetleg lejárt termék. Ebben az esetben buta verzióban annyit fogunk tenni, hogy minden nap végignézzük az összes terméket, hogy mikor jár le és ha az adott dátum kisebb mint a mai akkor kidobjuk. Ez esetünkben lehet egy többszörös *keresés*, igen keresési tétel, ergo kiválogatás, mert ha ismerjük az 5 alap tételt, akkor egyelőre még csak keresést tudjuk használni, de azzal is megtudjuk oldani, mert ha kikeresünk egy olyat ami lejárt kivesszük és addig futtatjuk amíg van benne lejárt elem.

Másik példaként vehetjük pl. hogy a legerősebb alkoholt keressük (szintén a boltban...nem ott írom ezt...komolyan) a termékek közül. Ekkor annyit tudunk csinálni ha bemegyünk a boltba, hogy végigmegyünk a soron és nézegetjük, hogy melyik mennyi és mindig megjegyezzük, hogy mi volt eddig a legerősebb alkohol. Amikor a sor végére érünk akkor (ha a memóriánk nem rossz) emlékszünk, hogy melyik volt az, meg is oldottuk a feladatot.

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

*Code Blocks* is használható a tárgy alatt, új projekt létrehozása illetve fordítása sokkal egyszerűbb: https://www.youtube.com/watch?v=kYA8rK2fy2U

### Változók
A változó a program futásához szükséges kellék, ami valamilyen nemű információt tárol. A változót úgy képzelhetjük el, hogy ami
Egy változónak van *élettartama* ameddig az adott változó létezik a memóriánkban.

#### "Manuális futtatás"

| Kódsor | a | b |
| ----- | - | - |
|int b=2;|Ismeretlen|Ismeretlen|


### Kommentelés

A kódban megjelenhetnek olyan információk is amik nem feltétlenül tartoznak a kódhoz hanem csak a kód megértését könnyítik, TODO (olyan amit még meg kell csinálni), dokumentáció, vagy bármi egyéb megjegyzés.
C++-ban két alapvető lehetésünk van kommentelésre: 
* // jelek után írt szövegrészeket a program figyelmen kívül hagyja (egy soros megjegyzés)
* /* és */ közé írt szöveget szintén (több soros megjegyzés)

```c++
int main(){
  int b=2; //Szeretem a mákosgubát
  b++;
  cout << b;
  for(int a=0;a<b;a++){
    cout << "Hello!" <<endl;
  }
  /*
  Egyszer volt hol nem volt volt egyszer egy... róka... vége.
  */
  
  return 0;
}
```
A modern programozási világban a /*-os megjegyzés használata mellett óvatosságra intenek, mert ha pl. van egy 1000 soros kódod és kiakarsz kommentelni 200 sort belőle, de valahol van benne egy 10 soros rész aminél már használtad a több soros megjegyzés.
