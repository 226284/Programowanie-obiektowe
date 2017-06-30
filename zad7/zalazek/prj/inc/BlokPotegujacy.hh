#ifndef BLOKPOTEGUJACY_HH
#define BLOKPOTEGUJACY_HH
#include <string>
#include "BlokSygnalowy.hh"

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


/*!
 * \brief Modeluje najważniejsze elementy bloku sygnałowego
 *
 * Klasa modeluje najważniejsze cechy bloku sygnałowego.
 */
class BlokPotegujacy: public BlokSygnalowy {
  
public:
  
  virtual bool WyliczSygnalWyj(const Sygnal& Syg) 
  {
    _SygnalWyj = Syg;

    _SygnalWyj.ZmienWartoscSyg (Syg.WezWartoscSyg()*Syg.WezWartoscSyg());
    
    return true;
  }
 
  virtual int Identyfikator() const { return 0; }

  virtual const char* NazwaBloku() const { return "Blok potęgujący"; }

  virtual std::string OpisBloku() const { return "Poteguje wartosc sygnalu"; }

};


#endif
