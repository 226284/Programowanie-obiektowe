#ifdef __GNUG__
# pragma implementation
#endif
#include "ListaBlokow.hh"
#include <iostream>

using namespace std;

/*!
 * Usuwa dynamicznie stworzone elementy listy
 */
ListaBlokow::~ListaBlokow()
{
  for (iterator Iter = begin(); Iter != end(); ++Iter) {
    delete *Iter;
  } 
}

/*!
 *
 */
void ListaBlokow::WyswietlTypBlokowWLiscie() const
{
   for (const_iterator Iter = begin(); Iter != end(); ++Iter) { 
     cout << (*Iter)->NazwaBloku() << endl;
   }
}


/*!
 *
 */
void ListaBlokow::WyswietlOpis() const
{
   for (const_iterator Iter = begin(); Iter != end(); ++Iter) { 
     cout << (*Iter)->OpisBloku() << endl;
   }
}


/*!
 * \retval true - jeśli któryś blok zgłosił chęć zakończenia pracy.
 * \retval false - w przypadku przeciwnym.
 */
vector<Sygnal> ListaBlokow::WyliczSygnal (list<Sygnal>& dane)
{
  Sygnal SygWe, SygWy;
  std::vector<Sygnal> dane_w;
  
  for (iterator Iter = begin(); Iter != end(); ++Iter)
    { 
      if ((*Iter)->CzyZakonczycPrace()) 
	{
	  ZakonczPraceBlokow();
	  return dane_w;
	}
      for (std::list<Sygnal>::iterator it = dane.begin(); it != dane.end(); it++)
	{
	  SygWe = *it;
	  (*Iter)->WyliczSygnalWej(SygWe,SygWy);
	  (*Iter)->WyliczSygnalWyj(*it);
	  SygWe = (*Iter)->WezSygnalWyj(); 

	  *it = SygWe;
	}
    }

  for (std::list<Sygnal>::iterator it = dane.begin(); it != dane.end(); it++)
	{
	  dane_w.push_back(*it);
	}

  return dane_w;
}


/*!
 */
void ListaBlokow::ZakonczPraceBlokow()
{
   for (iterator Iter = begin(); Iter != end(); ++Iter) { 
     (*Iter)->ZakonczPrace();
   }
}
