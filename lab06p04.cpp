#include <iostream>
#include <string>

using namespace std;

int wczytaj(string t[]);
void wypisz(string t[], int ile);
void analiza(string t[], int ile);
int main()
{
    string tab[100];
    int n = 0;
    n = wczytaj(tab);
    wypisz(tab, n);
    analiza(tab,n);
    return 0;
}

int wczytaj(string t[])
{
    string s;
    int i = 0;
    do
    {
        cout << ":";
        getline(cin, s);
        if (s.length() > 0)
        {
            t[i] = s;
            i++;
        }
    } while (s.length() > 0);
    return i;
}

void wypisz(string t[], int ile)
{
    for (int i = 0; i < ile; i++)
        cout << t[i] << " : ";
}

void analiza(string t[], int ile)
{
    int ile_liter = 0, ile_szukanych_liter=0;
    for (int i = 0; i < ile; i++)
    {
        ile_liter += t[i].length();
        for (int j = 0; j < t[i].length(); j++)
            if (t[i][j] == 'a') ile_szukanych_liter++;
        cout<<endl<<"Liter: "<<ile_liter
            <<endl<<"liter a:"<<ile_szukanych_liter;
    }
}