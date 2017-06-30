#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "Lzespolona.hh"


using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

//W funkcji main znajdują się tylko podstawowe operacje

int main()
{
  UkladRownanLiniowych   u;   

  cout << endl << " Start programu " << endl << endl;

  cout << "Wprowadz rozmiar, a następnie macierz i wektor:" << endl;
  cin >> u;

  oblicz (u);
  blad (u);

  cout << u << endl;
    
}
