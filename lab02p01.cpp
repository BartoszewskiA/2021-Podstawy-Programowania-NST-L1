#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;
    if ((a+b>c) && (a+c>b) && (b+c>a))
        cout << "Mozna zbudowac trojkat"<<endl;
    else
        cout << "Nie mozna zbudowac trojkata"<<endl;

    if ((a*a+b*b==c*c) || (a*a+c*c==b*b) || (b*b+c*c==a*a))
        cout << "Mozna zbudowac trojkat prostokatny";
    else
        cout << "Nie mozna zbudowac trojkata prostokatnego";

    return 0;
}
