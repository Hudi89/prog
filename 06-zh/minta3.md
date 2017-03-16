A felsorolt feladatok közül a ZH-ban egy várható, tehát mondjuk például a "hogy" után csak az egyes feladat lesz ott ZH-ban és az a feladat.

# Mintafeladat
Matematikus kollégánk megkért, hogy segítsünk neki egy két dolog kiszámolásában. Nem részletezte az indokokat csak megkért minket, hogy írjunk egy olyan programot ami megmondja egy mátrix alapján, hogy

**Feladat minták:**

1. igaz-e rá, hogy 
  1. egységmátrix.
  2. permutáló mátrix.
  3. diagonális mátrix.
  4. háromszög mátrix.
2. mennyi a mátrix
  1. Egyes normája.
  2. Végtelen normája.
3. minden sora/oszlopa számtani/mértani sor-e.
4. mennyi sorára igaz, hogy a legkisebb nemnegatív szám kisebb mint a szélessége a mátrixnak.


Erre kéne írnunk egy programot.

## Bemenet

Az inputunk egy mátrix: az input első két értéke megadja a mátrix magasságát és szélességét, majd a mátrix elemei következnek sorfojtonosan.
```
3 3
1 1 1 
2 1 4 
3 4 1 
```
## Output:

1. Igen|Nem
2. [Számérték]
3. Igen|Nem
4. [Számosság]

## Előfeltételek

* Számosság nem lehet negatív
* A mátrix legalább 3*3-as kell legyen
