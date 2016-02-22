# !!!Under Construction!!!

# Struct 

Emlékezünk típust úgy hozunk létre, hogy:
```
[Típus típus] [típus név] {[típus típustól függő definíció]};
```

```c++
struct FTM {
	bool l;
	int ind;
	int max; 
}
```
# Menü írás

írjunk egy menüt amin ki lehet választani, hogy konzol vagy fájl illetve újrafuttatás

```c++
void menukiir();

int main()
{
    int parancs;
    vector<int> asd;
    cin >> asd;

    bool futE=true;
    
    while (futE)
    {
    	menukiir();
    	cin >> parancs;
        switch (parancs)
        {
            case 0: 
            	asd.clear(); 
            	cin >> asd; 
            	break;
            case 1: 
            	cout << maxker(asd);
            	break;
            case 2: 
            	cout << szum(asd);
            	break;
            case 3: 
            	futE=false;
            	break;
        }
        cout << "Üss le egy billentyűzetet!";
	getch();
	system("cls");
    }
    return 0;
}

void menukiir()
{
    cout << "0. Beirni az adatokat" << endl;
    cout << "1. Maxker" << endl;
    cout << "2. Feltmaxker" << endl;
    cuot << "3. Kilepes" << endl;
}
```

# Mi is az a getch() és a system("cls")

Igazából egyik sem egy nagy trükk. A getch() mint a függvény neve is mondja vár egy karakter leütést. (get - char). A system("cls") pedig letisztítja nekünk a képernyőt, az átláthatóság érdekében.
