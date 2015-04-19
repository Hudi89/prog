#Feladatok

A féléves pontokat egy-egy feladattal lehet feljebb tornászni, ha esetleg a szükséges menyniség nem sikeres. Az elérhető pontszám a feladat mellett zárójelben található.

### Adatbázis (8)

Írjunk egy mini adatbáziskezelő programot. 
Az adatbázisunk egy txt fájl lesz. Az aktuális esetben az adatbázisunk bolygókat fognak tárolni a következő információkkal:

* Név
* 3d Koordináta (3 lebegőpontos szám)
* föld hasonlósági faktor (lebegőpontos szám 0-1 között)

```
Earth 0 0 0 1 
Theia 0 12 0 0.03 
Mars 0 12 0 0.03
````

A program képes kell legyen lefuttatni tranzakciókat. Egy tranzakció egy fájlban tárolódik és a következő parancsokat tudja:

* INSERT [Hozzáadandó bolygó adatai]
* DELETE [Bolygó neve]
* UPDATE [Bolygó neve] [Új adatok]


### Osztálykirándulás

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

