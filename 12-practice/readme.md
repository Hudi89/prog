Egy társasház közös költségének egy adott évben történt befizetéseit egy szöveges állományban tároljuk. Minden lakás minden befizetése egy-egy sor az állományban, amelyik tartalmazza a lakás azonosítóját (sztring), a befizetés dátumát (EEEE.HH.NN formájú sztring) és összegét (természetes szám). Egy soron belül az adatokat elválasztójelek (szóközök, tabulátor jelek) határolják egymástól. A sorok a lakásazonosítók szerint, azon belül a befizetési dátumok időrendje szerint rendezettek.

Példa néhány egymást követő sorra:
```
IV.ép.I.lh.8.em.12. 2014.01.05 23000
IV.ép.I.lh.8.em.12. 2014.02.06 24500
IV.ép.I.lh.9.em.1. 2014.02.06 27500
```

Megfelelt szintű (közepes) a munkája akkor, ha

1. kilistázza a képernyőre, hogy az egyes lakások mennyit fizettek be eddig,
2. keres olyan lakást, amelyik sosem fizetett egymást követően ugyanakkora összeget.

Ezeken kívül a programja kielégíti az alábbi követelményeket:

- nemcsak az érvényes tesztesetekre működik helyesen a programja (itt felteheti, hogy a lakás azonosítója egyetlen, elválasztójeleket nem tartalmazó sztring, és az állomány minden sora a megadott módon van kitöltve), hanem a nem létező fájl esetét is lekezeli.

- a program ciklusai tanult programozási tételekből származnak;
- egy osztályt készít a szöveges állomány olvasásához;
- a szöveges állományt csak egyszer nyitja meg olvasásra és nem használ a szöveges állomány sorainak számától függő méretű változót.

Kiválóan megfelelt szintű a munkája akkor, ha a megfelelt szinten túl

1. a befizetések két, a fent megadott formájú szöveges állományban helyezkednek el,
2. egy tanuló neve tetszőleges számú tagból, szóközökkel és/vagy tabulátor jelekkel elválasztott részekből állhat.

---

Egy iskolai osztálykirándulás árát (13000) a tanulók részletekben fizetik be. Minden tanuló minden befizetése egy szöveges állomány egy-egy sorában található, amelyik tartalmazza a tanuló nevét (sztring), a befizetés dátumát (EEEE.HH.NN formájú sztring) és összegét (természetes szám). Egy soron belül az adatokat elválasztójelek (szóközök, tabulátor jelek) határolják egymástól. A sorok a tanulók nevei szerint, azon belül a befizetési dátumok időrendje szerint rendezettek. Feltehetjük, hogy az állomány nem üres, sorai a megadott formájúak.

Példa néhány egymást követő sorra:

```
Feri 2013.11.13 2500
Feri 2014.01.23 3000
Feri 2014.03.11 1500
Juli 2013.11.21 4000
Juli 2014.02.15 1500
```

*Megfelelt szintű* (közepes) a munkája akkor, ha
1. megszámolja, hogy eddig összesen mennyit fizettek be a tanulók,
2. megadja egy olyan tanulónak a nevét, aki a legkevesebb részletben fizetette be a teljes összeget.

Ezeken kívül a programja kielégíti az alábbi követelményeket:
* nemcsak az érvényes tesztesetekre működik helyesen a programja (itt felteheti, hogy a tanuló neve egyetlen, elválasztójeleket nem tartalmazó sztring, és az állomány minden sora

a megadott módon van kitöltve), hanem a nem létező fájl esetét is lekezeli.
* a program ciklusai tanult programozási tételekből származnak;
* egy osztályt készít a szöveges állomány olvasásához;
* a szöveges állományt csak egyszer nyitja meg olvasásra és nem használ a szöveges állomány sorainak számától függő méretű változót.

Kiválóan megfelelt szintű a munkája akkor, ha a megfelelt szintet úgy teljesíti, hogy
1. a befizetések két, a fent megadott formájú szöveges állományban helyezkednek el,
2. egy tanuló neve tetszőleges számú tagból, szóközökkel és/vagy tabulátor jelekkel elválasztott részekből állhat.
