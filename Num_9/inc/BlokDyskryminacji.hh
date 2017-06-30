#ifndef BLOKDYSKRYMINACJI_HH
#define BLOKDYSKRYMINACJI_HH
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
class BlokDyskryminacji: public BlokSygnalowy {
  
  double prog_dyskryminacji;
  
public:
  
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
 
  virtual int Identyfikator() const { return 1; }

  virtual const char* NazwaBloku() const { return "Blok dyskryminacji"; }

  virtual std::string OpisBloku() const { return "Zwraca 1 gdy S(t)>sd i 0 w przeciwnym wypadku"; }
  
  void set_prog (double prog) {prog_dyskryminacji = prog;}

  double get_prog () {return prog_dyskryminacji;}

};


#endif
