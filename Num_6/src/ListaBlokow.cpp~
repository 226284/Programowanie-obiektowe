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
bool ListaBlokow::WyliczSygnal()
{
  Sygnal   SygWe, SygWy;

   for (iterator Iter = begin(); Iter != end(); ++Iter) { 
     if ((*Iter)->CzyZakonczycPrace()) {
       ZakonczPraceBlokow();
       return true;
     }
     (*Iter)->WyliczSygnalWej(SygWe,SygWy);
     (*Iter)->WyliczSygnalWyj(SygWy);
     SygWe = (*Iter)->WezSygnalWyj(); 
   }
   return false;
}


/*!
 */
void ListaBlokow::ZakonczPraceBlokow()
{
   for (iterator Iter = begin(); Iter != end(); ++Iter) { 
     (*Iter)->ZakonczPrace();
   }
}
