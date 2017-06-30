#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "Lzespolona.hh"
#include "Symbol.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

//W funkcji main znajdują się tylko podstawowe operacje

int main(int argc, char** argv)
{
  int c = 0, size = 0;
  bool zesp = false, rzecz = false, symb = false, blad1 = false; //przekaźniki

  // Sprawdzenie parametrów wywołania programu
  while ((c = getopt (argc, argv, "t:n:e")) != -1)
    {
      
      switch (c)
	{
	  
	case 't': //warunek typu układu równań
	  
	  if (*optarg == 'r')
	    {
	      rzecz = true;
	    }

	  else if (*optarg == 'z')
	    {
	      zesp = true;
	    }
	  
	  else if (*optarg == 's')
	    {
	      symb = true;
	    }
	  
	  else
	    {
	      cerr << "-t: Niepoprawny parametr" << endl;
	      return 0;
	    }

	  break;

	case 'n': //warunek rozmiaru układu równań
	  
	  size = atoi(optarg);
	  break;

	case 'e': // warunek obliczania wektora błędu

	  blad1 = true;
	  break;

	default: // jeśli nie podano żadnego parametru
	  
	  cerr << "err: Niepoprawny parametr" << endl;
	  return 0;
	}	  
    }

  //warunek sprawdzający czy poprawnie podano wszystkie opcje
  if (size == 0 || (zesp==false && rzecz==false && symb == false))
    {
      cerr << "Niepoprawne parametry" << endl;
      return 0;
    }
  //wyświetlenie nazwy programu
  cout << "Nazwa: " << argv[0] << endl;
  
  if (rzecz == true) // Typ: Liczby rzeczywiste 
    {
      cout << "Liczby rzeczywiste" << endl;
      UkladRownanLiniowych<double> u;

      if (size == 3 || size == 4)
	{
	  cout << "Liczba równań: " << size << endl;
	  u.set_rozmiar (size);
	}
      else 
	{
	  cerr << "Niepoprawny parametr" << endl; 
	  return 0;
	}
      
      cout << endl << " Start programu " << endl << endl;
      
      cout << "Wprowadz macierz i wektor wyrazów wolnych:" << endl;
      cin >> u;
      
      u.oblicz ();
      
      if (blad1 == true)
	{
	  u.set_czy_blad (true);
	  u.blad ();
	  u.dlugosc_blad();
	}
      
      cout << u << endl;
    }
  
  else if (zesp == true) // Typ: Liczby zespolone
    {
      cout << "Liczby zespolone" << endl;
      UkladRownanLiniowych<LZespolona> u;

      if (size == 3 || size == 4)
	{
	  cout << "Liczba równań: " << size << endl;
	  u.set_rozmiar (size);
	}
      else 
	{
	  cerr << "Niepoprawny parametr" << endl; 
	  return 0;
	}
  
      cout << endl << " Start programu " << endl << endl;

      cout << "Wprowadz macierz i wektor wyrazów wolnych:" << endl;
      cin >> u;

      u.oblicz ();

      if (blad1 == true)
	{
	  u.set_czy_blad (true);
	  u.blad ();
	  u.dlugosc_blad();
	}

      cout << u << endl;
    }
  
    else if (symb == true) // Typ: Symbole
    {
      cout << "Symbole" << endl;
      UkladRownanLiniowych<Symbol> u;

      if (size == 3 || size == 4)
	{
	  cout << "Liczba równań: " << size << endl;
	  u.set_rozmiar (size);
	}
      else 
	{
	  cerr << "Niepoprawny parametr" << endl; 
	  return 0;
	}
  
      cout << endl << " Start programu " << endl << endl;

      cout << "Wprowadz macierz i wektor wyrazów wolnych:" << endl;
      cin >> u;

      u.oblicz ();
      
      if (blad1 == true)
	{
	  u.set_czy_blad (true);
	  u.blad ();
	  u.dlugosc_blad();
	}
      
      cout << u << endl;
    }
    
}
