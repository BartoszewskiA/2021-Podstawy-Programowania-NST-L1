#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool czy_wystepuje_w_linji(string szukana, string linia);

int main()
{
    fstream plik;
    string temp;
    string nazwa_pliku, szukany_tekst;
    cout<<"Jaki plik przesukac: ";
    getline(cin,nazwa_pliku);

    plik.open(nazwa_pliku, ios::in);

    if (!plik.good())
    {
        cout<<"Zla nazwa pliku";
        return 0;
    }

    cout<<"Szukany tekst: ";
    getline(cin,szukany_tekst);
    
    while (!plik.eof())
    {
        getline(plik, temp);
        if (czy_wystepuje_w_linji(szukany_tekst,temp))
            cout << temp << endl;
    }
    return 0;
}

bool czy_wystepuje_w_linji(string szukana, string linia)
{
    int dl = szukana.length();
    int liczba_powt = linia.length() - szukana.length() + 1;
    string s;
    bool odp = false;
    for (int i = 0; i < liczba_powt; i++)
    {
        s = linia.substr(i, dl);
        if (s == szukana)
            odp = true;
    }
    return odp;
}