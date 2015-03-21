A felsorolt feladatok közül a ZH-ban egy várható, tehát mondjuk például a "hogy" után csak az egyes feladat lesz ott ZH-ban és az a feladat.

#Mintafeladat
Bulit szerveztünk a hétvégén a haverokkal, de kicsit túl nagyra sikeredett a buli, így a költségvetés kiszámolása elég nehézkes. Azt látjuk, hogy mennyi pénzünk maradt a végére, de megbeszéltük, hogy írunk egy programot ami kiszámolja nekünk, hogy...

**Feladat minták:**

1. melyik vásárlás volt a legkisebb, mire költöttünk a legkevesebbet. 
2. volt-e olyan amikor nem mindenki fizetett be a közösbe.
3. mennyit költöttünk összesen.

Erre kéne írnunk egy programot.

##Bemenet

Az input tartalmazza a vásárlásokat és a közös kasszába való befizetéseket is vegyesen. 
Az input ezen rekordok számával kezdődik, majd minden sor megadja egy vásárlás 1-1 tételét, vagy ha közösbe fizetésről volt szó, akkor 1-1 ember által beadott pénzösszeget.  
```
5 
5 -3000 -3000 -3000 -3000 -3000
4 1000 2000 3500 4000
5 -500 -500 -500 -500 -500
2 1000 2500
3 500 1000 1500
```
Output:

A fent megadott feladatok minta outputjai a következők, zárójelben a lehetsgées outputokat adom meg.

1. 2    ([index]|Nincs)
2. Nincs (Nincs|Van)
3. 16000 ([Érték])
