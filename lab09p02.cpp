#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int tab[1000];
    int n;
    cout << "n=";
    cin >> n;
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 2001 - 1000;
    int suma_d = 0, l_d = 0, suma_u = 0, l_u = 0;
    for (int i = 0; i < n; i++)
        if (tab[i] >= 0)
        {
            suma_d += tab[i];
            l_d++;
        }
        else
        {
            suma_u += tab[i];
            l_u++;
        }
    if (l_d >= 0)
        cout << "Srednia liczb dodatnich =" << (double)suma_d / l_d << endl;
    if (l_u >= 0)
        cout << "Srednia liczb ujemnych =" << (double)suma_u / l_u;
    return 0;
}