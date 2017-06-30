#ifndef LISTABLOKOW_HH
#define LISTABLOKOW_HH
#ifdef __GNUG__
# pragma interface
#endif
#include <list>
#include <vector>
#include "BlokSygnalowy.hh"

class ListaBlokow: public std::list<BlokSygnalowy*> {

  public:
  /*!
   * \brief Realizuje przeliczenie sygnału dla całej listy bloków
   */
  std::vector<Sygnal> WyliczSygnal(list<Sygnal>& dane);
  /*!
   * \brief Dodaje nowy blok sygnałowy
   *
   * Dodaje nowy blok sygnałowy.
   * \param[in] wBlok - wskaźnik na nowy blok. Musi on być wskazywać
   *                    na obiekt. Nie może to być wskaźnik NULL. 
   */
   void DodajBlokSygnalowy( BlokSygnalowy* wBlok) { push_back(wBlok); }
  /*!
   * \brief Wyświetla typy blokow
   *
   * Wyświetla nazwy typów bloków w liście
   */
   virtual void WyswietlTypBlokowWLiscie() const;

  /*!
   * \brief Wyświetla typy blokow
   *
   * Wyświetla nazwy typów bloków w liście
   */
   virtual void WyswietlOpis() const;

  /*!
   * \brief Usuwa dynamicznie stworzone elementy listy
   */
   virtual ~ListaBlokow();

 private:
  /*!
   * \brief Kończy pracę wszystkich bloków
   */
  void ZakonczPraceBlokow();
};

#endif
