#Feladatok

A féléves pontokat egy-egy feladattal lehet feljebb tornászni, ha esetleg a szükséges mennyiség nem sikeres. Az elérhető pontszám a feladat mellett zárójelben található.
A feladatok megoldásához a dokumentáció és a részletes kommentezés nem szükséges, viszont erős követelmény, hogy a kód gyorsan/könnyen átlátható legyen, így valamennyi kommentet igényelnek a programok, természetesen megvalósítás minőségétől függően. 
Az inputoknak sincs konkrét szigorú formája, ha a feladat nem ad meg semmit, ezek is rátok vannak bízva, de törekedjetek a leghatékonyabb megoldásra, mert szép megoldás esetében tovább pontok szerezhetőek.

Több feladat is igényel olyan tudást amit nem tanultunk konkrétan, de egy programozónak tudnia kell új tudást felvennie.:)

### (i-j) mátrix (3)

Készítsünk egy programot, ami megmondja egy bináris mátrixról i-j mátrix-e, azaz igaz-e a mátrixra, hogy minden sora pontosan ```i```  és minden oszlopa pontosan ```j``` egyest tartalmaz, minden más egyes. Input formája szabadon választható.


### Adatbázis (8)

Írjunk egy mini adatbáziskezelő programot. 
Az adatbázisunk egy txt fájl lesz. Az aktuális esetben az adatbázisunk bolygókat fognak tárolni a következő információkkal:

* Név
* 3d Koordináta (3 lebegőpontos szám)
* föld hasonlósági faktor (lebegőpontos szám 0-1 között)

```
Earth 0 0 0 1 
Mars 0 12 0 0.03
Theia 0 12 0 0.03 
````
A program képes kell legyen lefuttatni tranzakciókat. Egy tranzakció egy fájlban tárolódik és a következő parancsokat tudja:

* INSERT [Hozzáadandó bolygó adatai]
* DELETE [Bolygó neve]
* UPDATE [Bolygó neve] [Új adatok]

Note: **A fő kulcs a neve a bolygónak, így eszerint van rendezve az input fájl és a tranzakció lista is**
Note: A megoldáshoz szekvenciális osztályokkal oldjátok meg.

### Osztálykirándulás (6)

Egy iskolai osztálykirándulás árát (13000) a tanulók részletekben fizetik be. Minden tanuló minden befizetése egy szöveges állomány egy-egy sorában található, amelyik tartalmazza a  tanuló nevét (sztring), a befizetés dátumát (EEEE.HH.NN formájú sztring) és összegét(természetes szám). Egy soron belül az adatokat elválasztójelek (szóközök, tabulátor jelek) határolják egymástól. A sorok a tanulók nevei szerint, azon belül a befizetési dátumok időrendje szerint rendezettek. Feltehetjük, hogy az állomány nem üres, sorai a megadott formájúak.

Példa néhány egymást követő sorra:
```
Feri   2013.11.13   2500   
Feri   2014.01.23   3000   
Feri   2014.03.11   1500
Juli    2013.11.21   4000
Juli    2014.02.15   1500
```
1. megszámolja, hogy eddig összesen mennyit fizettek be a tanulók,
2. megadja egy olyan tanulónak a nevét, aki a legkevesebb részletben fizetette be a teljes összeget. 
3. a befizetések két, a fent megadott formájú szöveges állományban helyezkednek el,
4. egy tanuló neve tetszőleges számú tagból, szóközökkel és/vagy tabulátor jelekkel elválasztott részekből állhat.

Ezeken kívül a programja kielégíti az alábbi követelményeket:

* nemcsak az érvényes tesztesetekre működik helyesen a programja (itt felteheti, hogy a tanuló neve egyetlen, elválasztójeleket nem tartalmazó sztring, és az állomány minden sora a megadott módon van kitöltve), hanem a nem létező fájl esetét is lekezeli.
* a program ciklusai tanult programozási tételekből származnak;
* egy osztályt készít a szöveges állomány olvasásához;
* a szöveges állományt csak egyszer nyitja meg olvasásra és nem használ a szöveges állomány sorainak számától függő méretű változót.

### Reguláris cserélő (5)

**Ez a feladat olyan tudást is igényel ami a tanév alatt nem került leadásra**

Készítsünk egy programot ami reguláris kifejezéseket tud lefuttatni. A program négy parancssori paramétert várjon, ha nem kap elegendőt egy helpet adjon a program, hogy hogy kell paraméterezni. A három paraméter legyen:

* A forrásfájl neve
* A célfájl neve
* Mit cseréljen (reguláris kifejezés)
* Mire cseréljen (captureöket lehessen megadni)

+3 - Működjön teljeskörűen, mint egy normális linuxos bash program minden szempontból, lehessen pl. pipeolni.

### tikzpicture (4)

**Ez a feladat olyan tudást is igényel ami a tanév alatt nem került leadásra**

Készítsünk egy programot ami Latex-tikzpicture formátumú megjelenítést készít egy paraméterül átadott mátrixra, ami egy irányítatlan egyszerű gráf szomszédossági mátrixát adja meg. A kiement magasságát és szélességét is meg lehessen adni paraméterként a generáláshoz.

+1 - irányított gráf 
+2 - nem egyszerű gráfra is működik


### GMP (4-8)

**Ez a feladat olyan tudást is igényel ami a tanév alatt nem került leadásra**

Gmp libary (https://gmplib.org/) használatával készítsünk minél gyorsabb algoritmust ami megadja a paraméterül adott két szám prímfelbontását (Tudjuk, hogy az átadott szám két prímszám szorzata).
