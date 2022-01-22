#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    fstream plik;
    plik.open("in.txt",ios::in);
    if (!plik.good())
    {
        cout<<"Blad pliku";
        return 0;
    }
    string s;
    //cout << "Podaj tekst: ";
    //getline(cin, s);
    getline(plik,s);
    if (s.length()==0)
        {
            cout<< "plik był pusty";
            return 0;
        }
    string s_w = "", s_m = "";
    for (int i = 0; i < s.length(); i++)
        if ((int)s[i] >= (int)'A' && (int)s[i] <= (int)'Z')
            s_w += s[i];
        else if ((int)s[i] >= (int)'a' && (int)s[i] <= (int)'z')
            s_m += s[i];
    cout << "Duze litery: " << s_w << endl
         << "Male litery: " << s_m;
         plik.close();
    return 0;
}