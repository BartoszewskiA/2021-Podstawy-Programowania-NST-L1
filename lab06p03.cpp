#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "Podaj zdanie: ";
    getline(cin, s);
    for (int i=0; i<s.length(); i++)
        if(s[i]>='a' && s[i]<='z')
            s[i]='#';
    cout<<s;
    return 0;
}