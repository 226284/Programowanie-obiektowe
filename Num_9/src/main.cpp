#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include "BlokSygnalowy.hh"
#include "BlokPotegujacy.hh"
#include "BlokDyskryminacji.hh"
#include "ListaBlokow.hh"

using namespace std;

int main (int argc, char **argv)
{
  int c;
  ListaBlokow ListaB;
  BlokSygnalowy dane;

  bool checkWyj = false;
  ofstream Wyj;
  string Nazwa;
 
  while ((c = getopt(argc,argv,"o:GD:")) != -1)
    {
      switch (c)
	{

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
	}
    }

  if (checkWyj == true)
    {
      Sygnal tsygnal;
      double czas, sygnal;
      list<Sygnal> dane_l;
      vector<Sygnal> dane_v;
      
      //Generowanie sygnału
      for (int i=0; i<100; ++i)
	{
	  czas = i;
	  tsygnal.ZmienCzas (czas);
	  sygnal = i;
	  tsygnal.ZmienWartoscSyg (sygnal);
	  
	  dane_l.push_back(tsygnal);
	}
      
      dane_v = ListaB.WyliczSygnal (dane_l);
      
      for(unsigned int i = 0; i < dane_v.size(); i++)
	{		
	  Wyj << dane_v[i].WezCzas() << " " << dane_v[i].WezWartoscSyg() << endl;
	}

      Wyj.close();

      cout << "Lista wczytanych bloków:" << endl;
      ListaB.WyswietlTypBlokowWLiscie();
    }

  else return 0;
 
}
