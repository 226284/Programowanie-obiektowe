#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include "BlokSygnalowy.hh"
#include "BlokPotegujacy.hh"
#include "BlokDyskryminacji.hh"
#include "BlokProstujacy.hh"
#include "ListaBlokow.hh"


using namespace std;

int main (int argc, char **argv)
{
  int c;
  ListaBlokow ListaB;
  BlokSygnalowy dane;

  bool checkWyj = false, checkWej = false;
  ifstream Wej;
  ofstream Wyj;
  string Nazwa;
 
  while ((c = getopt(argc,argv,"i:o:GD:S")) != -1)
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
	    else cout << ">>Sprawdz czy podano prawidłowy plik!" << endl;

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

	case 'D':
	  {
	    BlokDyskryminacji *tmp = new BlokDyskryminacji();
	    tmp->set_prog(atof(optarg));
	    ListaB.DodajBlokSygnalowy (tmp);

	    break;	
	  }

	case 'S':
	  {
	    ListaB.DodajBlokSygnalowy (new BlokProstujacy());
	    
	    break;	
	  }

	}
    }

  if (checkWej == true && checkWyj == true)
    {
      Sygnal tsygnal;
      double czas, sygnal;
      list<Sygnal> dane_l;
      vector<Sygnal> dane_v;
      
      //Wczytywanie pliku wejściowego
      while (!Wej.eof())
	{
	  Wej >> czas;
	  tsygnal.ZmienCzas (czas);
	  Wej >> sygnal;
	  tsygnal.ZmienWartoscSyg (sygnal);
	  
	  dane_l.push_back (tsygnal);
	}
      
      Wej.close();
      
      //Wyświetlanie listy wczytanych bloków
      cout << "Lista wczytanych bloków:" << endl;
      ListaB.WyswietlTypBlokowWLiscie();

      //Obliczanie sygnału
      dane_v = ListaB.WyliczSygnal (dane_l);
      
      //Wypisywanie wektora sygnałów do pliku
      for(unsigned int i = 0; i < dane_v.size()-1; i++)
	{		
	  Wyj << dane_v[i].WezCzas() << " " << dane_v[i].WezWartoscSyg() << endl;
	}

      Wyj.close();

      cout << ">>Dane zostały przetworzone" << endl;

    }

  else cerr << "err: Nie podano pliku wejściowego/wyjściowego!" << endl;
 
}
