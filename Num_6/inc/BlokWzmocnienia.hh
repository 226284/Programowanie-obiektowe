#ifndef BLOKWZMOCNIENIA_HH
#define BLOKWZMOCNIENIA_HH
#include <string>
#include "BlokSygnalowy.hh"

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


/*!
 * \brief Modeluje najważniejsze elementy bloku wzmocnienia
 *
 * Klasa modeluje najważniejsze cechy bloku wzmocnienia
 */
class BlokWzmocnienia: public BlokSygnalowy {

   /*!
    * \brief Przechwouje wartość progu wzmocnienia
    *
    *  Pole zawiera wartość progu wzmocnienia
    */

  double prog_wzmocnienia;

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

    _SygnalWyj.ZmienWartoscSyg(prog_wzmocnienia*Syg.WezWartoscSyg());

    return true;
  }

   /*!
   * \brief Udostępnia identyfikator bloku
   *
   *  Udostępnia liczbowy identyfikator bloku, który określa jego typ.
   *  Metoda, o ile będzie pomocna (zależy od przyjętej koncepcji),
   *  powinna być redefiniowana w klasie pochodnej.
   */

  virtual int Identyfikator() const { return 5; }

   /*!
   * \brief Udostępnia nazwę typu bloku
   *
   *  Udostępnia nazwę typu bloku
   */

  virtual const char* NazwaBloku() const { return "Blok wzmocnienia"; }

  /*!
   * \brief Udostępnia opis bloku
   *
   *  Udostępnia opis, tzn jaki to jest blok, jakie ma parametry itd.
   */

  virtual std::string OpisBloku() const { return "Blok wzmacnia sygnał o podawaną przez użytkownika stałą "; }



  void set_wzmocnienie (double prog) {prog_wzmocnienia = prog;}

  /*!
   * \brief Pobiera wartość progu
   *
   *  Pobiera pole które przechowuje aktualny próg wzmocnienia bloku
   */

  double get_wzmocnienie () {return prog_wzmocnienia;}

};


#endif
