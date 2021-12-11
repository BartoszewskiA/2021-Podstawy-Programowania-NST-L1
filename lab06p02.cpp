#include <iostream>
#include <string>

using namespace std;

string normalizuj(string napis);

int main()
{
    string s;
    cout << "Podaj imie i nazwisko: ";
    getline(cin, s);
    int poz = s.find(' ');
    string imie = s.substr(0, poz);
    string nazwisko = s.substr(poz+1,s.length()-poz -1);
    imie = normalizuj(imie);
    nazwisko = normalizuj(nazwisko);
    cout<<"Imie:"<<imie<<endl;
    cout<<"nazwisko:"<<nazwisko<<endl;
    return 0;
}

string normalizuj(string napis)
{
    for (int i = 0; i < napis.length(); i++)
        napis[i] = tolower(napis[i]);
    napis[0] = toupper(napis[0]);
    return napis;
}