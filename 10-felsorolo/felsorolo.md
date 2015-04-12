#Felsoroló

Ahogy az órák alatt nagyon sokszor az általánosítást vettük fókuszba, most is azt fogjuk. 

```c++
int sum(const vector<int> &v){
  int s = 0;
  for(int a=0;a<v.size();a++){
    s += v[a];
  }
  return s;
}
```
