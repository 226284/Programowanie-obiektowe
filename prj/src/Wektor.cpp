#include "Wektor.hh"


std::istream & operator >> (std::istream &Strm, Wektor &Wek)
{
  unsigned int i;
  for (i=0; i<Wek.get_rozmiar(); i++)
    {
      Strm >> Wek[i];
    }
  return Strm;
}

std::ostream & operator << (std::ostream &Strm, const Wektor &Wek)
{
  unsigned int i;
  
  Strm << "[";
  for(i=0; i<Wek.get_rozmiar(); i++) 
    {
      Strm << Wek[i] << " ";
    }
  Strm << "]" << std::endl;
  return Strm; 
}

// DODAWANIE WEKTORÓW

Wektor operator + (Wektor w1, Wektor w2)
{

  for (unsigned int i=0; i<w1.get_rozmiar(); i++)
    {
      w1[i] = w1[i] + w2[i];
    }
  
  return w1;
}

// ODEJMOWANIE

Wektor operator - (Wektor w1, Wektor w2)
{
  for (unsigned int i=0; i<w1.get_rozmiar(); i++)
    {
      w1[i] = w1[i] - w2[i];
    }
  
  return w1;
}

// MNOŻENIE WEKTORÓW (ILOCZYN SKALARNY)

element_t operator * (Wektor w1, Wektor w2)
{
  element_t wynik;

  for (unsigned int i=0; i<w1.get_rozmiar(); i++)
  {
    wynik += (w1[i] * w2[i]);
  }
  
  return wynik;
}

// MNOŻENIE PRZEZ LICZBE

Wektor operator * (float Liczba, Wektor w)
{
  for (unsigned int i=0; i<w.get_rozmiar(); i++)
    {
      w[i] = Liczba * w[i];
    }
  
  return w;
}

// DZIELENIE PRZEZ LICZBE

Wektor operator / (Wektor w, int Liczba)
{
  for (unsigned int i=0; i<w.get_rozmiar(); i++)
    {
      w[i] = w[i] / Liczba;
    }
  
  return w;
}
