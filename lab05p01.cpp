#include <iostream>
#include <time.h>

using namespace std;

void wypisz(int t[], int ile);
void losuj_tbalice(int t[], int ile, int min, int max);
int losuj_tbalice_v2(int t[], int ile, int min, int max);
void zeruj_ujenme(int t[], int ile);
void sortuj_tablice(int t[], int ile);

int main()
{
    int tab[100], tab_2[100];
    int dlugosc = 0, dlugosc_2 = 0;

    srand(time(NULL));
    //losuj_tbalice(tab, 30, -10, 30);
    //dlugosc = 30;
    dlugosc = losuj_tbalice_v2(tab, 44, -20, 40);
    dlugosc_2 = losuj_tbalice_v2(tab_2,20,-1000,1000);
    wypisz(tab, dlugosc);
    wypisz(tab_2,dlugosc_2);
    //zeruj_ujenme(tab,dlugosc);
    sortuj_tablice(tab, dlugosc);
    sortuj_tablice(tab_2,dlugosc_2);
    wypisz(tab, dlugosc);
    wypisz(tab_2, dlugosc_2);
    return 0;
}

void zeruj_ujenme(int t[], int ile)
{
    for (int i = 0; i < ile; i++)
    {
        if (t[i] < 0)
            t[i] = 0;
    }
}

void losuj_tbalice(int t[], int ile, int min, int max)
{
    for (int i = 0; i < ile; i++)
    {
        t[i] = rand() % (max - min + 1) + min;
    }
}

int losuj_tbalice_v2(int t[], int ile, int min, int max)
{
    for (int i = 0; i < ile; i++)
    {
        t[i] = rand() % (max - min + 1) + min;
    }
    return ile;
}

void wypisz(int t[], int ile)
{
    cout << endl
         << "---------------------------------------------------------------------------"
         << endl;
    for (int i = 0; i < ile; i++)
    {
        if (i % 10 == 0 && i != 0)
            cout << endl;
        cout << t[i] << "\t";
    }
    cout << endl
         << "---------------------------------------------------------------------------"
         << endl;
}

void sortuj_tablice(int t[], int ile)
{
    int temp;
    for (int j = 0; j < ile; j++)
        for (int i = 0; i < ile - j - 1; i++)
            if (t[i] > t[i + 1])
            {
                temp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = temp;
            }
}