#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "Podaj zdanie: ";
    getline(cin, s);
    // for (int i=0; i<s.length(); i++)
    //     if (s[i] == ' ')
    //         cout<<"_";
    //     else
    //         cout<<s[i];
    for (int i=0; i<s.length(); i++)
        if (s[i] == ' ') s[i]='_';
    cout<<"wynik: "<<s;
    return 0;
}