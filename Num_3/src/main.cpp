#include <iostream>
#include <unistd.h>
#include <cstdlib>
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

int main(int argc, char** argv)
{
  int c = 0, size = 0;
  bool zesp = false, rzecz = false;
  UkladRownanLiniowych u;   

  while ((c = getopt (argc, argv, "n:t:e")) != -1)
    {
      
      switch (c)
	{
	  
	case 'n':

	  cout << "Nazwa: " << argv[0] << endl;
	  
	  size = atoi(optarg);
	  
	  if (size == 3 || size == 4)
	    {
	      cout << "Liczba równań: " << size << endl;
	      u.set_rozmiar (size);
	      break;
	    }
	  else 
	    {
	      cerr << "Niepoprawny parametr" << endl; 
	      return 0;
	    }
	
	case 't':
	  
	  if (*optarg == 'r')
	    {
	      cout << "Liczby rzeczywiste" << endl;
	      rzecz = true;
	    }

	  else if (*optarg == 'z')
	    {
	      cout << "Liczby urojone" << endl;
	      zesp = true;
	    }

	  else
	    {
	      cerr << "-t: Niepoprawny parametr" << endl;
	      return 0;
	    }

	  break;

	case 'e':

	  u.set_czy_blad (true);
	  break;

	default:
	  
	  cerr << "err: Niepoprawny parametr" << endl;
	  return 0;
	}	  
    }
  
  if (size == 0 || (zesp==false && rzecz==false) || (zesp==true && rzecz==true))
    {
      cerr << "Niepoprawne parametry" << endl;
      return 0;
    }

  cout << endl << " Start programu " << endl << endl;

  cout << "Wprowadz macierz i wektor wyrazów wolnych:" << endl;
  cin >> u;

  u.oblicz ();

  if (u.get_czy_blad() == true)
    {
      u.blad ();
      u.dlugosc_blad();
    }

  cout << u << endl;
    
}
