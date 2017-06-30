#include "Lzespolona.hh"
#include <cmath>
//#include <iomanip>

//using namespace std;

/*
 * W pliku tym nalezy zdefiniowac poszczegolne metody dla klasy LZespolona
 */

LZespolona::LZespolona() 
{
  _re = _im = 0;
}

/*LZespolona::LZespolona (float r, float i) 
  {
  _re = r;
  _im = i;
  }
*/


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
/*
LZespolona LZespolona::sqrt (const LZespolona& Arg) const
{
  float modul;

  modul = sqrt (Arg.Re() + Arg.Im());
  
*/

std::istream&  operator >> ( std::istream&      StrmWe,  
                             LZespolona&  WczytywanaLiczba)
{
  char znak1, znak2;

  StrmWe >> znak1 >> WczytywanaLiczba.Re() >> WczytywanaLiczba.Im() >> znak2;

  if (znak1 != '{' && znak2 != '}')
    {
      std::cerr << "err: Niepoprawna składnia liczby zespolonej" << znak1 << " " << znak2 << std::endl;
      return StrmWe;
    }

  else return StrmWe;
}

std::ostream& operator << (std::ostream& StrmWy,
			   const LZespolona& WyswietlanaLiczba)
{
  StrmWy << "{" << WyswietlanaLiczba.LZespolona::Re() << "+"
	 << WyswietlanaLiczba.LZespolona::Im()<< "i" << "}";

  return StrmWy;
}
