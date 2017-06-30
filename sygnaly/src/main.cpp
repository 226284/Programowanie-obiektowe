#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include "BlokSygnalowy.hh"
#include "BlokPotegujacy.hh"
#include "ListaBlokow.hh"

using namespace std;

int main (int argc, char **argv)
{
  int c;
  ListaBlokow ListaB;
  BlokSygnalowy dane;

  ifstream Wej;
  ofstream Wyj;
  bool checkWej = false, checkWyj = false;
  string Nazwa;

  while ((c = getopt(argc,argv,"i:o:G")) != -1)
    {
      switch (c)
	{
	
	case 'i':
	  {
	    Wej.open (optarg, ios::in);

	    if (Wej.good())
	      {
		cout << ">>Pobrano plik wejściowy" << endl << endl;
		checkWej = true;
	      }	

	    break;
	  }

	case 'o':
	  {
	    Wyj.open (optarg, ios::out);

	    Nazwa = string(optarg);
	    checkWyj = true;
	
	    break;
	  }
	
	case 'G':
	  {
	    ListaB.DodajBlokSygnalowy (new BlokPotegujacy());
	    
	    break;	
	  }
	}
    }

  if (checkWej == true && checkWyj == true)
    { 
      //Wczytywanie pliku wejściowego
      Sygnal tsygnal;
      double czas, sygnal;
      
      while (!Wej.eof())
	{
	  Wej>>czas;
	  tsygnal.ZmienCzas(czas);
	  Wej>>sygnal;
	  tsygnal.ZmienWartoscSyg (sygnal);
	}
      
      

      cout << "Lista wczytanych bloków:" << endl;
      ListaB.WyswietlTypBlokowWLiscie();
    }

  else cerr << "err: Nie podano pliku wejściowego/wyjściowego!" << endl;
}
