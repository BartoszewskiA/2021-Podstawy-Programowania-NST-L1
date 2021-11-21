#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    const int n = 1000;
    int x, ile = 0;
    srand(time(NULL));
    int tab[n];
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 201 - 100;
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl
         << "x=";
    cin>>x;
    for (int i = 0; i < n; i++)
        if (tab[i]==x)
            ile++;
    cout<<"liczba "<<x<<" wystapila "<<ile<<" razy";
        return 0;
}