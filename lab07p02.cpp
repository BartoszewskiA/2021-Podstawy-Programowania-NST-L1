#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string modyfikuj_nazwe(string nazwa);
string usun_spacje(string s);

int main()
{
    fstream plik, plik_w;
    string temp;
    string nazwa_pliku, nazwa_pliku_w;
    cout << "Jaki plik przekonwertowac: ";
    getline(cin, nazwa_pliku);

    plik.open(nazwa_pliku, ios::in);

    if (!plik.good())
    {
        cout << "Zla nazwa pliku";
        return 0;
    }
    nazwa_pliku_w = modyfikuj_nazwe(nazwa_pliku);

    plik_w.open(nazwa_pliku_w, ios::out);

    while (!plik.eof())
    {
        getline(plik, temp);
        if ((int) temp.find("#include")<0) //nie wystapilo
             plik_w << usun_spacje(temp);
        else
            plik_w<<temp<<endl;
    }

    plik.close();
    plik_w.close();
    return 0;
}

string modyfikuj_nazwe(string nazwa)
{
    int poz = nazwa.find('.');
    string nowa_nazwa = nazwa.substr(0, poz);
    nowa_nazwa += "_komp";
    nowa_nazwa += nazwa.substr(poz, nazwa.length() - poz);
    return nowa_nazwa;
}

string usun_spacje(string s)
{
    string wynik = "";
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            wynik += s[i];
    return wynik;
}
