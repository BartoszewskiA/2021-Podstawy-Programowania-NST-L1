#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    fstream plik;
    plik.open("pytania.txt",ios::app);
    string s;
    while(1)
    {
        cout<<"dodac pytanie (t/n) ";
        getline(cin,s);
        if (s!="t") 
            break;
        cout<<"Podaj pytanie: ";
        getline(cin,s);
        plik<<s<<endl;
        cout << "Podaj odpowiedz 1: ";
        getline(cin, s);
        plik << s << endl;
        cout << "Podaj odpowiedz 2: ";
        getline(cin, s);
        plik << s << endl;
        cout << "Podaj odpowiedz 3: ";
        getline(cin, s);
        plik << s << endl;
        cout << "Podaj nuemer prawidlowej odpowiedzi: ";
        getline(cin, s);
        plik << s<<endl; //uwaga na pusta linie na koncu pliku
    }

    plik.close();
    
    return 0;
}