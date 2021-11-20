#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL)); // 1 x na program
    int n, a, b;
    cout << "ile liczb: ";
    cin >> n;
    cout << "Poczatek zakresu: ";
    cin >> a;
    cout << "koniec zakresu: ";
    cin >> b;

    for (int i = 0; i < n; i++)
    {
        cout << rand()%((b - a)+1) - a << " ";
    }
    return 0;
}