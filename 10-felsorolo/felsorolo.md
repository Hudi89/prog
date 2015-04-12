#Felsoroló

Ahogy az órák alatt nagyon sokszor az általánosítást vettük fókuszba, most is azt fogjuk. Nézzünk meg egy egyszerű alaptételt:

```c++
int sum(const vector<int> &v){
  int s = 0;
  for(int a=0;a<v.size();a++){
    s += v[a];
  }
  return s;
}
```

Az ```int``` típust template-el könnyedén kitujduk általánosítani, viszont ahhoz hogy igazán általánosak lehessünk, ahhoz azt is kikéne általánosítani, hogy milyen az az input. Most fixen vector lehet csak.
Most, hogy már tudunk osztályt csinálni készíthetünk egyet.

Egy felsoroló osztályt fogunk csinálni, ami a nevét nem meghazudtolva annyit csinál csak, hogy felsorol elemeket. De milyen elemeket? Ha templatet használunk bármilyet, anélkül egy fixet. 
Miért jó ez? Megtudjuk úgy csinálni a függvényeinket, hogy ne függjenek már szinte semmitől és akkor teljeskörűen feltudjuk őket újra használni.

Mit is várunk el egy ilyen felsoroló osztálytól? Alakítsuk át az összegzés függvényünket úgy, hogy valami felsorolóból jönnek az értékek mágikusan.

```c++
int sum(Enumerator &e){
  int s = 0;
  for(e.init();e.isEnd();e.next()){
    s += e.current();
  }
  return s;
}
```


```c++
class Enumerator
```
