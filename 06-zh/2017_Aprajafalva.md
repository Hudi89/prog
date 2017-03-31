# ZH Feladat
Aprajafalván Captain Törp felkért minket, hogy segítsünk kitalálni neki, hogy melyik napon lenne érdemes több gyömbér szörpöt készíteni. Ennek eldöntéséhez feljegyezte, hogy hány szörpöt kellett készítenie az elmúlt napok folyamán.
Úgy gondolja, ha megmondjuk, hogy melyik nap az, amin átlagosan a legtöbb szörpöt kell készítenie és aznap minden elkészített adag legalább 5 darabból kell hogy álljon, az neki most megfelelő lesz. 

## Bemenet
Bemenő adatként Captain Törp egy nagy fájlt fog nekünk adni, az elmúlt x napban eladott gyömbér szörpről, úgy, hogy az első rekord hétfői (majd kedd,szerda,... és vasárnap után ismét hétfő). A fájl a feljegyzett napok számával kezdődik, majd sorban 1-1 nap feljegyzései követik, úgy hogy először megadjuk hogy az adott napon mennyiszer kellett új adagot készítenie, majd a készített szörpök számai sorban.
```
10
3 5 10 20
2 10 12
3 12 10 5
1 5
1 2
0
1 2
3 50 50 100
2 5 10
1 5
```

## Output
Pontos dátumra nem vagyunk kíváncsiak, a program csak a következő értékek közül az egyiket adja vissza (ha nincs előfeltételsértés): H,K,SZ,CS,P,SZo,V (ami logikusan a hét napjait jelöli)

A fenti minta bemenetre az eredmény:
```
H
```

Abban az esetben ha nincs feltételnek megfelelő nap akkor ```NM``` legyen a kimenet.

**Fontos:** A kimenet pontosan ez legyen, se több se kevesebb. :)

Note: Az átlagolásnak soronként kell megtörténnie, csak a program eredménye a hét napjai legyen.

## Előfeltételek
Az előfeltételek esetében a zárójelben megadottakat írja ki a program!

* Számosság nem lehet negatív (NC)
* Egy darabszám érték sem lehet kisebb mint 1 (LV)
* Egy darabszám értéke sem lehet nagyobb mint 1000 (HV)
* Megfelelő kell legyen az input, nem tartalmazhat szöveget például (WI)

## Tundivalók
https://github.com/Hudi89/prog/blob/master/06-zh/readme.md
