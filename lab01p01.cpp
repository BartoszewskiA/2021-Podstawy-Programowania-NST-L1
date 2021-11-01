#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;
    cout << "x=";
    cin >> x;
    cout << "y=";
    cin >> y;
    if (y != 0)
    {
        double wynik = (double)x / y;
        cout << "wynik = " << wynik <<endl;
    } 
    else
    {
        cout <<"nie dziel przez zero\n";
    }
    cout << "\nkoniec programu";
    return 0;
}