#ifndef BLOKPOTEGUJACY_HH
#define BLOKPOTEGUJACY_HH
#include <string>
#include "BlokSygnalowy.hh"

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


/*!
 * \brief Modeluje najważniejsze elementy bloku potegowego
 *
 * Klasa modeluje najważniejsze cechy bloku potegowego
 */
class BlokPotegujacy: public BlokSygnalowy {
  
public:
  
  /*!
   * \brief Wylicza wartość sygnału wyjściowego
   *
   *  Wylicza wartość sygnału wyjściowego. Na wejście metody
   *  jest przekazywany wcześniej wyliczony sygnał z wejścia
   *  bloku sygnałowego.
   */

  virtual bool WyliczSygnalWyj(const Sygnal& Syg) 
  {
    _SygnalWyj = Syg;

    _SygnalWyj.ZmienWartoscSyg (Syg.WezWartoscSyg()*Syg.WezWartoscSyg());
    
    return true;
  }
  
   /*!
   * \brief Udostępnia nazwę typu bloku
   *
   *  Udostępnia nazwę typu bloku
   */

  virtual int Identyfikator() const { return 1; }

  /*!
   * \brief Udostępnia nazwę typu bloku
   *
   *  Udostępnia nazwę typu bloku
   */

  virtual const char* NazwaBloku() const { return "Blok potęgujący"; }

  /*!
   * \brief Udostępnia opis bloku
   *
   *  Udostępnia opis, tzn jaki to jest blok, jakie ma parametry itd.
   */

  virtual std::string OpisBloku() const { return "Poteguje wartosc sygnalu"; }

};


#endif
