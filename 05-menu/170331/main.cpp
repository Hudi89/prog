#include "myheader.h"

using namespace std;

int main()
{
    int cmd;
    vector<vector<int> > matrix;
    string filename;
    fstream fin;
    do {
        menu();
        cout << "Kerem a parancs számát: ";
        cin >> cmd;
        switch(cmd) {
        case 1:
            try {
                cout << "Kerem a file nevet: ";
                cin >> filename;
                fin.open(filename.c_str());
                if(!fin.is_open()) {
                    throw FILE_NOT_EXIST;
                }
                matrix.clear();
                cout << matrix.size() << endl;
                fin >> matrix;
                fin.close();
            } catch(Exception exc) {
                switch(exc) {
                case NEGATIVE_SIZE:
                    cout << "Beolvasasnal negativ szamot adtal meg" << endl;
                    break;
                case FILE_NOT_EXIST:
                    cout << "Nem letezik a file!" << endl;
                    break;
                default:
                    cout << "sorry nem ismerem a hibat" << endl;
                    break;
                }
            }
            break;
        case 2:
            cout << "DEBUG" << endl;
            for(int i = 0; i < matrix.size(); ++i) {
                for(int j = 0; j < matrix[i].size(); ++j) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 3:
            try {
                cout << "FMK: " << feltMaxKerOsszeg(matrix) << endl;
            } catch(Exception exc) {
                switch(exc) {
                case URES_MATRIX:
                    cout << "Ures volt a matrix!" << endl;
                    break;
                default:
                    cout << "Kerlek keresd a helpdesk-et!" << endl;
                    break;
                }
            }
        }
        //=======COMPLEX========
        /*
        vector<Complex> c;
        string filename = "asd.txt";
        fstream fin;
        fin.open(filename.c_str());
        fin >> c;
        */
        //==== VECTOR =====
        /*vector<int> v;
        string filename = "asd.txt";
        fstream fin;
        fin.open(filename.c_str());
        if(!fin.is_open())
        {
            cout << "Nem nyert!";
            return -1;
        }
        fin >> v;
        cout << "Minden elem negativ: ";
        int index = feltetelesMaximumKeresesVector(v);
        if(index != -1)
        {
            cout << "Igen " << v[index] << endl;
        }
        else
        {
            cout << "Nem" << endl;
        }

        cout << "DEBUG" << endl;
        for( int i = 0; i < v.size(); ++i )
        {
            cout << v.at(i) << endl;
        }*/

    }while(cmd != 4);
    return 0;
}
