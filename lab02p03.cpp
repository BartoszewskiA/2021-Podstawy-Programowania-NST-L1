#include<iostream>

using namespace std;

int main()
{
    int n, x , s = 0;
    cout <<"ile liczb wczytac: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout << "x[" << i+1 << "]=";
        cin >> x;
        s= s + x;
    }
    cout<<"suma="<<s<<endl;
    if (n>0)
        cout<<"srednia="<< (double)s/n;
    else
        cout <<"srednia=0";
    return 0;
}
