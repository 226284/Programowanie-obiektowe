#ifndef BLOKDYSKRYMINACJI_HH
#define BLOKDYSKRYMINACJI_HH
#include <string>
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
class BlokDyskryminacji: public BlokSygnalowy {
  
   /*!
    * \brief Przechwouje wartość progu dyskryminacji
    *
    *  Pole zawiera wartość progu dyskrymiancji
    */

  double prog_dyskryminacji;
  
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
    if (Syg.WezWartoscSyg() > get_prog())
      {
	_SygnalWyj.ZmienWartoscSyg (1);
      }
    else {_SygnalWyj.ZmienWartoscSyg (0);}
    
    return true;
  }
 
   /*!
   * \brief Udostępnia identyfikator bloku
   *
   *  Udostępnia liczbowy identyfikator bloku, który określa jego typ.
   *  Metoda, o ile będzie pomocna (zależy od przyjętej koncepcji),
   *  powinna być redefiniowana w klasie pochodnej.
   */

  virtual int Identyfikator() const { return 2; }

   /*!
   * \brief Udostępnia nazwę typu bloku
   *
   *  Udostępnia nazwę typu bloku
   */

  virtual const char* NazwaBloku() const { return "Blok dyskryminacji"; }

  /*!
   * \brief Udostępnia opis bloku
   *
   *  Udostępnia opis, tzn jaki to jest blok, jakie ma parametry itd.
   */

  virtual std::string OpisBloku() const { return "Zwraca 1 gdy S(t)>sd i 0 w przeciwnym wypadku"; }
  
  /*!
   * \brief Ustawia wartość progu
   *
   *  Ustawia pole które przechowuję aktualny próg dyskryminacji bloku
   */

  void set_prog (double prog) {prog_dyskryminacji = prog;}

  /*!
   * \brief Pobiera wartość progu
   *
   *  Pobiera pole które przechowuje aktualny próg dyskryminacji bloku
   */

  double get_prog () {return prog_dyskryminacji;}

};


#endif
