#include <iostream>

using namespace std;

int main()
{
    int x;
    int tab[100];
    int n = 0;
    do
    {
        cout << "x=";
        cin >> x;
        if (x >= 0)
        {
            tab[n] = x;
            n++;
        }
    } while (x >= 0);

    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    // wyliczenie sredniej
    int suma = 0;
    for (int i = 0; i < n; i++)
        suma += tab[i];
    double srednia = (double)suma / n;
    cout << "srednia = " << srednia;
    //wieksze od sredniej
    cout<<endl<<"wieksze od sredniej: ";
    for (int i = 0; i < n; i++)
        if (tab[i] > srednia)
            cout << tab[i] << " ";
    //mniejsze od sredniej
    cout<<endl<<"mniejsze od sredniej: ";
    for (int i = 0; i < n; i++)
        if (tab[i] < srednia)
            cout << tab[i] << " ";
    return 0;
}