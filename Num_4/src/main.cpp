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
  UkladRownanLiniowych<double> u;
  int c = 0, size = 0;
  bool zesp = false, rzecz = false, blad1 = false;   

  while ((c = getopt (argc, argv, "t:n:e")) != -1)
    {
      
      switch (c)
	{
	  
	case 't':
	  
	  if (*optarg == 'r')
	    {
	      rzecz = true;
	    }

	  else if (*optarg == 'z')
	    {
	      zesp = true;
	    }

	  else
	    {
	      cerr << "-t: Niepoprawny parametr" << endl;
	      return 0;
	    }

	  break;

	case 'n':
	  
	  size = atoi(optarg);
	  break;

	case 'e':

	  blad1 = true;
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

  cout << "Nazwa: " << argv[0] << endl;
  if (rzecz == true) 
    {
      cout << "Liczby rzeczywiste" << endl;
      //      UkladRownanLiniowych<double> u;
    }
  else if (zesp == true) 
    {
      cout << "Liczby zespolone" << endl;
      //      UkladRownanLiniowych<LZespolona> u;
    }



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
      u.blad ();
      u.dlugosc_blad();
    }

  cout << u << endl;
    
}
