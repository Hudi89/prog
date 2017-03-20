A felsorolt feladatok közül a ZH-ban egy várható, tehát mondjuk például a "hogy" után csak az egyes feladat lesz ott ZH-ban és az a feladat.

# Mintafeladat
Rádióban dolgozunk és a főnök kitalálta, hogy csinál egy válogatásversenyt, amire rengeteg jelentkezés érkezett, így megszívtuk, tehát megkért minket, hogy írjunk egy programot ami megmondja nekünk, hogy...

**Feladat minták:**

1. melyik válogatás a leghosszabb ami még a műsoridőbe belefér (10 perces műsoridő).
2. melyik a leghosszabb válogatás azok közül amikben nincs 5 percnél hosszabb szám.
3. mennyi a számok átlagos hossza a pályázók számainál.

Erre kéne írnunk egy programot.

## Bemenet

Az input tartalmazza a pályázatokat, ahol minden egyes sor 1-1 pályázatnak felel meg.
Az input ezen rekordok számával kezdődik, majd minden sor megadja, hogy mennyi számból áll a válogatás amit a pályázó beküldött, majd sorba egymás után a számok hosszait másodpercben megadva.
```
3 
3 90 180 184
4 90 170 150 130
2 200 200

```
## Output:

1. [index]|1
2. [Index]|Nincs
3. [Átlag érték]

## Előfeltételek

* Számosság nem lehet negatív
* Egy zeneszám hossza pozitív kell legyen
* Egy zeneszám hossza kevesebb mindig mint 10 óra :)
