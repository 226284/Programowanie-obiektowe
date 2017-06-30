#include "UkladRownanLiniowych.hh"


//PPRZECIĄŻENIE WCZYTYWANIA UKŁADU RÓWNAŃ

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
  unsigned int roz;
  Macierz mac;
  Wektor wek;

  Strm >> roz;

  UklRown.set_rozmiar(roz);
  mac.set_rozmiar(roz);
  wek.set_rozmiar(roz);
  
  Strm >> mac >> wek;
  UklRown.set_macierz (mac);
  UklRown.set_wyrazy (wek);
  
  return Strm;
}

//PRZECIĄŻENIE ZAPISU UKŁADU RÓWNAŃ

std::ostream& operator << (std::ostream &Strm, 
			   UkladRownanLiniowych UklRown)
{ 
  Strm << std::endl << "Macierz A:" << std::endl << UklRown.get_macierz() << std::endl;

  Strm << std::endl << "Wektor wyrazów wolnych:" << std::endl << UklRown.get_wyrazy() 
       << std::endl;

  if(wyznacznik (UklRown.get_macierz())==0)
    {
      Strm << "Nie można obliczyć rozwiązań: W=0" << std::endl;      
    }
  else
    {
      Strm << std::endl << "Wektor rozwiązań:" << std::endl << UklRown.get_rozwiazanie()
	   << std::endl;
      
      Strm << std::endl << "Wektor błędu:" << std::endl << UklRown.get_wbledu()
	   << std::endl;  
  
      Strm << std::endl << "Długość wektora błędu:" << std::endl 
	   << UklRown.get_blad() << std::endl;
    }
  
  return Strm;
}

//MNOŻENIE MACIERZY PRZEZ WEKTOR

Wektor operator * (Macierz m, Wektor w)
{
  unsigned int i,j;
  Wektor bufor;
  
  for(i=0; i<m.get_rozmiar(); i++)
    {
      bufor[i]=0;
      
      for(j=0; j<m.get_rozmiar(); j++)
	{
	  bufor[i] += m(i,j) * w[j];
	}
    }

  return bufor;
}



//OBLICZANIE WEKTORA ROZWIĄZAŃ
Wektor oblicz (UkladRownanLiniowych &u)
{ 
  Macierz _mac = u.get_macierz();
  Wektor _wyrazy = u.get_wyrazy();
  Wektor _rozw;
  element_t _wyzn = u.set_wyznacznik(wyznacznik (_mac));
  Wektor bufor;
  
  if (_wyzn!=0)
    {
      for (unsigned  int i=0; i<u.get_rozmiar(); ++i)
	{
	  bufor = _mac[i];
	  _mac[i] = _wyrazy;
	  _wyrazy = bufor;

	  _rozw[i] = (wyznacznik (_mac) / _wyzn);
	  
	  _mac = u.get_macierz();
	  _wyrazy = u.get_wyrazy();
	}
	  
    }
      u.set_rozwiazanie(_rozw); 
      return _rozw;
}


//OBLICZANIE WEKTORA BŁĘDU
Wektor blad (UkladRownanLiniowych &u)
{
  if (u.get_macierz().get_wyznacznik() != 0)
    {
      u.set_wbledu( (u.get_macierz() * u.get_rozwiazanie()) - u.get_wyrazy() );
    }

  return u.get_wbledu();
}
  
//OBLICZANIE DŁUGOŚCI WEKTORA BŁĘDU
element_t dlugosc_blad (UkladRownanLiniowych &u)
{
  u.set_blad (sqrt (u.get_wbledu() * u.get_wbledu()));
  
  return u.get_blad();
}
