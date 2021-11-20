#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int los, x, ile = 0;
    los = rand() % 100 + 1;
    cout << los <<endl;
    do
    {
        cout << "x=";
        cin >> x;
        ile++;
        if (los < x)
            cout<<"za duzo"<<endl;
        else if (los > x)
            cout<<"za malo"<<endl;
    } while (x != los);
    cout<<"zgadles po "<<ile<<" probach";


    return 0;
}