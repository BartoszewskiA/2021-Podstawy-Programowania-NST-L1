#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    fstream plik;
    plik.open("out.txt",ios::out);
    if (!plik.good())
    {
        cout<<"blad pliku";
        return 0;
    }
    string tab[100];
    int n = 0;
    string s;
    while (1)
    {
        cout<<"Podaj zdanie: ";
        getline(cin,s);
        if (s.length()==0)  //s==""
            break;
        tab[n]=s;
        n++;
    }

    for (int i=n-1; i>=0; i--)
    {
        cout<<tab[i]<<endl;
        plik<<tab[i]<<endl;
    }
    plik.close();
    return 0;
}