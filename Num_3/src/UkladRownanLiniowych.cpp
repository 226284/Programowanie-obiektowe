#include "UkladRownanLiniowych.hh"



//METODA USTALAJĄCA ROZMIAR DLA WSZYSTKICH ATRYBUTÓW KLASY UKŁ RÓWN
unsigned int & UkladRownanLiniowych::set_rozmiar (unsigned int rozm)
{
  m.set_rozmiar (rozm);
  w.set_rozmiar (rozm);
  r.set_rozmiar (rozm);
  e.set_rozmiar (rozm);

  Rozmiar = rozm;
  return Rozmiar;
}

//OBLICZANIE WEKTORA ROZWIĄZAŃ
Wektor UkladRownanLiniowych::oblicz ()
{ 
  Macierz _mac = get_macierz();
  Wektor _wyrazy = get_wyrazy();
  Wektor _rozw;
  element_t _wyzn = _mac.wyznacznik();
  _rozw.set_rozmiar (get_rozmiar());
  set_wyznacznik(_wyzn);

  Wektor bufor;
  
  if (_wyzn!=0)
    {
      for (unsigned  int i=0; i<get_rozmiar(); ++i)
	{
	  bufor = _mac[i];
	  _mac[i] = _wyrazy;
	  _wyrazy = bufor;

	  _rozw[i] = (_mac.wyznacznik () / _wyzn);

	  _mac = get_macierz();
	  _wyrazy = get_wyrazy();
	}
	  
    }
      set_rozwiazanie(_rozw); 
      return get_rozwiazanie();
}

//OBLICZANIE WEKTORA BŁĘDU
Wektor UkladRownanLiniowych::blad ()
{
  Wektor wektor_bledu;
  
  if (get_wyznacznik() != 0)
    {
      wektor_bledu = (get_macierz() * get_rozwiazanie()) - get_wyrazy();
    }

  wektor_bledu.set_rozmiar (get_rozmiar());
  
  set_wbledu (wektor_bledu);
  return get_wbledu();
}

//OBLICZANIE DŁUGOŚCI WEKTORA BŁĘDU
double UkladRownanLiniowych::dlugosc_blad ()
{
  set_blad (sqrt (get_wbledu() * get_wbledu()));
  
  return get_blad();
}


//PRZECIĄŻENIE WCZYTYWANIA UKŁADU RÓWNAŃ

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
  Macierz mac;
  Wektor wek;

  mac.set_rozmiar(UklRown.get_rozmiar());
  wek.set_rozmiar(UklRown.get_rozmiar());
  
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

  if (UklRown.get_wyznacznik() == 0)
    {
      Strm << "Nie można obliczyć rozwiązań: W=0" << std::endl;      
    }
  else
    {
      Strm << std::endl << "Wektor rozwiązań:" << std::endl << UklRown.get_rozwiazanie()
	   << std::endl;

      if (UklRown.get_czy_blad() == true)
	{
	  Strm << std::endl << "Wektor błędu:" << std::endl << UklRown.get_wbledu()
	       << std::endl;  
	  
	  Strm << std::endl << "Długość wektora błędu:" << std::endl 
	       << std::noshowpos << UklRown.get_blad() << std::endl;
	}
    }
  
  return Strm;
}

//MNOŻENIE MACIERZY PRZEZ WEKTOR

Wektor operator * (Macierz m, Wektor w)
{
  unsigned int i,j;
  Wektor bufor;
  LZespolona zero;
  
  for(i=0; i<m.get_rozmiar(); i++)
    {
      bufor[i]=zero;
      
      for(j=0; j<m.get_rozmiar(); j++)
	{
	  bufor[i] = bufor[i] + (m(i,j) * w[j]);
	}
    }

  return bufor;
}

