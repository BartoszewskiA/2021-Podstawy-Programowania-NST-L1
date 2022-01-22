#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct pytanie
{
    string pyt;
    string odp_1;
    string odp_2;
    string odp_3;
    int prawidlowa;
};

pytanie tab[20];
int liczba_pytan = 0;

int odczyt_z_pliku();
bool zadaj_pytanie(int nr);

int main()
{
    srand(time(NULL));
    int wynik=0;
    liczba_pytan = odczyt_z_pliku();
    for (int i=0; i<liczba_pytan; i++)
    if (zadaj_pytanie(i))
        wynik++;

    // if (zadaj_pytanie(rand()%3))
    //     cout<<"OK";
    // else
    //     cout<<"Buuu";
    cout<<"Uzyskales wynik "<< wynik<<" punkty";
    return 0;
}

int odczyt_z_pliku()
{
    fstream plik;
    string s;
    int ile=0;
    plik.open("ptania.txt", ios::in);
    while (!plik.eof())
    {
        getline(plik, s);
        if (s.length()==0) break;
        tab[ile].pyt = s;
        getline(plik, s);
        tab[ile].odp_1 = s;
        getline(plik, s);
        tab[ile].odp_2 = s;
        getline(plik, s);
        tab[ile].odp_3 = s;
        getline(plik, s);
        tab[ile].prawidlowa = atoi(s.c_str());
        ile++;
    }
    plik.close();
    return ile;
}

bool zadaj_pytanie(int nr)
{
    string temp;
    cout << endl
         << "------------------------------------" << endl;
    cout << tab[nr].pyt << endl;
    cout << "1) " << tab[nr].odp_1 << endl;
    cout << "2) " << tab[nr].odp_2 << endl;
    cout << "3) " << tab[nr].odp_3 << endl;
    cout<<"Podaj odpowiedz: (1/2/3) ";
    getline(cin,temp);
    int odp = atoi(temp.c_str());
    if (odp == tab[nr].prawidlowa)
        return true;
    else
        return false;
}