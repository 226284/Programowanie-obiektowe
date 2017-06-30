#include "Macierz.hh"


std::istream & operator >> (std::istream &Strm, Macierz &Mac)
{
  unsigned int i,j;
  for (i=0; i<Mac.get_rozmiar(); i++)
    for(j=0; j<Mac.get_rozmiar(); j++)
      {
	{
	  Strm >> Mac(i,j);
	}
      }
  return Strm;
}

std::ostream & operator << (std::ostream &Strm, const Macierz &Mac)
{
  unsigned int i,j;


  for (i=0; i<Mac.get_rozmiar(); i++)
    {
      Strm << "|";
      for(j=0; j<Mac.get_rozmiar(); j++)
	{
	  Strm << Mac(i,j) << " ";
	}
      Strm << "|" << std::endl;
    }
  return Strm;
}

element_t sprawdz_wyzn (element_t wyzn)
{
  if (wyzn < 0.001 && wyzn > -0.001)
    {
      return 0;
    }

  else
    {
      return wyzn;
    }
}

element_t wyznacznik (Macierz m)
{
  unsigned int i,j,k,l;
  unsigned int rozmiar = m.get_rozmiar();
  element_t wynik;
  Wektor kolumny[ROZMIAR];

  for(i = 0; i < rozmiar; ++i) kolumny[i] = m[i];

  for(i = 0; i < rozmiar-1; ++i){
    for(j = i+1; j< rozmiar; ++j){
      for(k = i+1; k< rozmiar; ++k){
	if(kolumny[i][i] == 0){
	  bool find = false;
	  for(l = i; l< rozmiar; ++l){
	    if(kolumny[l][l] != 0){
	      Wektor bufor;
	      bufor = kolumny[i];
	      kolumny[i] = kolumny[l];
	      kolumny[l] = bufor;
	      find = true;
	    }
	  }
	  if(!find) return 0;
	}
	kolumny[j][k]  -= (kolumny[j][i]/kolumny[i][i]*kolumny[i][k]);
      }
    }
  }
  wynik = 1;
  for(i = 0; i<rozmiar; ++i) wynik *= kolumny[i][i];
  
  return wynik;
}

