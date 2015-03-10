# !!!Under Construction!!!
# Menü írás

írjunk egy menüt amin ki lehet választani, hogy konzol vagy fájl illetve újrafuttatás

```c++
void menukiir();

int main()
{
    int parancs;
    vector<int> asd;
    cin >> asd;

    menukiir();
    bool futE=true;
    
    while (futE)
    {
    	cin >> parancs;
        switch (parancs)
        {
            case 0: asd.clear(); cin >> asd; break;
            case 1:cout << maxker(asd);break;
            case 2:cout << szum(asd);break;
            case 3:futE=false;break;
        }
	    menukiir();	
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
