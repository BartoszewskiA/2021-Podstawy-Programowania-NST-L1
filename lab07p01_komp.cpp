#include <iostream>
#include <fstream>
#include <string>
usingnamespacestd;boolczy_wystepuje_w_linji(stringszukana,stringlinia);intmain(){fstreamplik;stringtemp;stringnazwa_pliku,szukany_tekst;cout<<"Jakiplikprzesukac:";getline(cin,nazwa_pliku);plik.open(nazwa_pliku,ios::in);if(!plik.good()){cout<<"Zlanazwapliku";return0;}cout<<"Szukanytekst:";getline(cin,szukany_tekst);while(!plik.eof()){getline(plik,temp);if(czy_wystepuje_w_linji(szukany_tekst,temp))cout<<temp<<endl;}return0;}boolczy_wystepuje_w_linji(stringszukana,stringlinia){intdl=szukana.length();intliczba_powt=linia.length()-szukana.length()+1;strings;boolodp=false;for(inti=0;i<liczba_powt;i++){s=linia.substr(i,dl);if(s==szukana)odp=true;}returnodp;}