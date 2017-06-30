#include "Lzespolona.hh"
#include <cmath>
#include <iomanip>
#include <iostream>


/*
 * W pliku tym nalezy zdefiniowac poszczegolne metody dla klasy LZespolona
 */

LZespolona::LZespolona() 
{
  _re = _im = 0;
}

LZespolona::LZespolona (double re, double im) 
{
  _re = re;
  _im = im;
}

double LZespolona::Re() const
{
  return _re;
}

double& LZespolona::Re()
{
  return _re;
}

double LZespolona::Im() const
{
  return _im;
}

double& LZespolona::Im()
{
  return _im;
}


LZespolona LZespolona::operator + (const LZespolona& Arg2) const
{
  LZespolona b;
  
  b.Re() = Arg2.Re();
  b.Im() = Arg2.Im();

  b.Re() += _re;
  b.Im() += _im;
  
  return b;
}

LZespolona LZespolona::operator - (const LZespolona& Arg2) const
{
  LZespolona b;
  
  b.Re() = Arg2.Re();
  b.Im() = Arg2.Im();

  b.Re() -= _re;
  b.Im() -= _im;
  
  return b;
}

LZespolona LZespolona::operator * (const LZespolona& Arg2) const
{
  LZespolona b;

  b.Re() = ((_re * Arg2.Re() ) - (_im * Arg2.Im() ));
  b.Im() = ((_re * Arg2.Im() ) + (_im * Arg2.Re() ));

  return b;
}

LZespolona LZespolona::operator / (const LZespolona& Arg2) const
{
  LZespolona b;

  b.Re() = ((_re * Arg2.Re() ) + (_im * Arg2.Im() )) / ((Arg2.Re() * Arg2.Re()) + (Arg2.Im() * Arg2.Im()));
  b.Im() = ((_im * Arg2.Re() ) - (_re * Arg2.Im() )) / ((Arg2.Re() * Arg2.Re()) + (Arg2.Im() * Arg2.Im()));

  return b;
}

LZespolona LZespolona::operator * (const int& Arg2 ) const
{
  LZespolona b;

  b.Re() = (_re * Arg2);
  b.Im() = (_im * Arg2);

  return b;
}

void LZespolona::operator = (const int& Arg2 )
{
  _re = Arg2;
  _im = 0;
}

bool LZespolona::operator == (const LZespolona& Arg2) const
{
  if (_re == Arg2.Re() && _im == Arg2.Im() )
    {	 
      return true;
    }
  else return false;
}

bool LZespolona::operator != (const LZespolona& Arg2) const
{
  if (_re == Arg2.Re() && _im == Arg2.Im() )
    {	 
      return false;
    }
  else return true;
}

bool LZespolona::operator == (const int& Arg2) const
{
  if (_re == Arg2 && _im == Arg2 )
    {	 
      return true;
    }
  else return false;
}

bool LZespolona::operator != (const int& Arg2) const
{
  if (_re == Arg2 && _im == Arg2 )
    {	 
      return false;
    }
  else return true;
}

/*
LZespolona LZespolona::sqrt (const LZespolona& Arg) const
{
  float modul;

  modul = sqrt (Arg.Re() + Arg.Im());
  
*/

std::istream&  operator >> ( std::istream&      StrmWe,  
                             LZespolona&  WczytywanaLiczba)
{
  char znak1, znak2, znak3;

  StrmWe >> znak1 >> WczytywanaLiczba.Re() >> WczytywanaLiczba.Im() >> znak2 >> znak3;

  if (znak1 != '{' && znak2 != 'i' && znak3 != '}')
    {
      std::cerr << "err: Niepoprawna składnia liczby zespolonej" << znak1 << " " << znak2 << std::endl;
      return StrmWe;
    }

  else return StrmWe;
}

std::ostream& operator << (std::ostream& StrmWy,
			   const LZespolona& WyswietlanaLiczba)
{
  StrmWy << "{" << std::noshowpos << WyswietlanaLiczba.LZespolona::Re()
	 << std::showpos << WyswietlanaLiczba.LZespolona::Im() << "i" << "}";

  return StrmWy;
}
