#include<iostream>

using namespace std;

int main()
{
    int n;
    double y, suma = 0;
    cout<<"n=";
    cin>>n;
    for(int x = 2 ; x<=n ; x++)
    {
        //y = (x*x)/(x-1.0);
        y = (double)(x*x)/(x-1);
         suma = suma + y;
    }
    cout<<"Suma = "<<suma;
    return 0;
}
