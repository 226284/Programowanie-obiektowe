#ifndef BLOKPROSTUJACY_HH
#define BLOKPROSTUJACY_HH
#include <string>
#include <cmath>
#include "BlokSygnalowy.hh"

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


/*!
 * \brief Modeluje najważniejsze elementy bloku dyskrymianacji
 *
 * Klasa modeluje najważniejsze cechy bloku dyskryminacji
 */
class BlokProstujacy: public BlokSygnalowy {

  
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
    
    _SygnalWyj.ZmienWartoscSyg(fabs(Syg.WezWartoscSyg()));
    
    return true;
  }
 
   /*!
   * \brief Udostępnia identyfikator bloku
   *
   *  Udostępnia liczbowy identyfikator bloku, który określa jego typ.
   *  Metoda, o ile będzie pomocna (zależy od przyjętej koncepcji),
   *  powinna być redefiniowana w klasie pochodnej.
   */

  virtual int Identyfikator() const { return 3; }

   /*!
   * \brief Udostępnia nazwę typu bloku
   *
   *  Udostępnia nazwę typu bloku
   */

  virtual const char* NazwaBloku() const { return "Blok prostujący"; }

  /*!
   * \brief Udostępnia opis bloku
   *
   *  Udostępnia opis, tzn jaki to jest blok, jakie ma parametry itd.
   */

  virtual std::string OpisBloku() const { return "Zwraca wartość bezwględną sygnału"; }

};


#endif
