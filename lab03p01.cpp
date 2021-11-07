#include <iostream>

using namespace std;

int main()
{
    int s = 0, ile = 0, x;
    do
    {
        cout << "x=";
        cin >> x;
        ile++;
        s +=x; //s=s+x;
    } while (s <= 100);

    cout<<"w setce zmiescilo sie "<<ile - 1<<" liczb";

    return 0;
}