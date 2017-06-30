#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <math.h> //została dodana z uwagi na użycie pierwiastka dla dł wektora
#include "Macierz.hh"
#include "rozmiar.h"
#include "Wektor.hh"
#include "Lzespolona.hh"


/*!
 * \brief Klasa UkladRownanLiniowych łączy w sobie klasy: LZespolona, Wektor, Macierz
 *
 *  Klasa UkladRownanLiniowych zawiera macierz współczynników, wektor wyrazów wolnych i typ zmiennych (liczba zespolona).
 */
template <typename Typ>
class UkladRownanLiniowych{
  
  /*!
   * \brief Przechowuje rozmiar macierzy i wektora
   *
   * Tu przechowywana jest informacja o rozmiarze wektora wyrazów wolnych i macierzy kwadratowej, przechowującej współczynniki.
   */
  unsigned int Rozmiar;
  /*!
   * \brief Przechowuje wyznacznik macierzy
   *
   * Pole zawiera wyznacznik macierzy obliczony za pomocą eliminacji Gaussa.
   */
  Typ Wyznacznik;
  /*!
   * \brief Przechowuje macierz znaków 
   *
   * Macierz znaków zawiera poszczególne współczynniki, stojące przy zmiennych w kolejnych równaniach układu równań liniowych.
   */
  Macierz<Typ> m; //macierz znaków
  /*!
   * \brief Przechowuje wektor wyrazów wolnych
   *
   * Wektor wyrazów wolnych zawiera prawe strony równań liniowych układu równań liniowych.
   */
  Wektor<Typ> w;  //wektor wyrazów wolnych
  /*!
   * \brief Przechowuje wektor rozwiązań
   *
   * Wektor zawiera rozwiązania układu równań liniowych obliczone za pomocą wzorów Cramera.
   */
  Wektor<Typ> r;  //wektor rozwiązań
  /*!
   * \brief Przechowuje wektor błędu
   *
   * Wektor błedu to obliczona różnica pomiędzy wyliczonymi rozwiązaniami a faktycznymi rozwiązaniami układu. Wynika ona z przechowywania liczb przez komputer.
   */
  Wektor<Typ> e;  //wektor błędu
  /*!
   * \brief Przechowuje długość wektora błędu
   *
   * Dłuogśc wektora błędu wyliczona jest ze standardowego wzoru na długośc wektora.
   */
  double b; //dl wektora błędu
  /*!
   * \brief Przechowuje informację czy ma być liczony bład
   *
   * Przechowuje informację czy ma być liczony wektor błędu i długość wektora błędu, decyduje również czy błąd będzie wyświetlany
   */
  bool czy_blad;
  
public:
  /*!
   * \brief Konstruktor ustala podstawowe parametry Układu Rownan liniowych
   *
   *  Konstruktor ustala podstawowe parametry Układu Rownan liniowych (jak na razie ustala tylko czy_blad)
   */
  UkladRownanLiniowych<Typ> () { czy_blad = false; }
  /*!
   * \brief Metoda pozwala na zmianę rozmiaru macierzy,wektora oraz układu równań
   *
   *  Metoda ta zmienia ilość wykorzystywanego miejsca w macierzy kwadratowej i wektorze wyrazów wolnych o rozmiarze równym ROZMIAR.
   */
  unsigned int & set_rozmiar (unsigned int rozm)
  {
    m.set_rozmiar (rozm);
    w.set_rozmiar (rozm);
    r.set_rozmiar (rozm);
    e.set_rozmiar (rozm);
    
    Rozmiar = rozm;
    return Rozmiar;
  }
  /*!
   * \brief Metoda pobiera rozmiar układu równań
   *
   *  Metoda pozwala pobrać aktualnie wykorzystywany rozmiar układu równań, a zatem także rozmiar macierzy i wektora wyrazów wolnych.
   */
  unsigned int const get_rozmiar () const { return Rozmiar; }

  //Ustawianie wyznacznika
  /*!
   * \brief Metoda pozwala ustawić wyznacznik układu równań oraz macierzy
   *
   *  Metoda ustala wyznacznik macierzy, używany poźniej we wzorach Cramera.
   */
  void set_wyznacznik (Typ wyzn) {Wyznacznik = wyzn; m.set_wyznacznik(wyzn); }
  /*!
   * \brief Metoda pozwala pobrać wyznacznik z układu równań
   *
   *  Metoda pobiera ustalony wcześniej wyznacznik macierzy.
   */
  const Typ get_wyznacznik () const { return Wyznacznik; }
  
  /*!
   * \brief Metoda pozwala ustawić wektor rozwiązań
   *
   *  Metoda ustala wektor rozwiązań, zawierający poszczególne rozwiązania dla kolejnych zmiennych.
   */
  void set_rozwiazanie (Wektor<Typ> rozw) { r = rozw; }
  /*
   * \brief Metoda pozwala pobrać wektor rozwiązań
   *
   *  Metoda pobiera ustalony wcześniej wektor rozwiązań.
   */
  Wektor<Typ> & get_rozwiazanie () { return r; }

  /*!
   * \brief Metoda pozwala modyfikować macierz znaków
   *
   *  Metoda pozwala ustalić macierz znaków, używaną wobliczaniu wyznacznika macierzy.
   */
  Macierz<Typ> set_macierz (Macierz<Typ> mac) { m = mac; return m; }
  /*!
   * \brief Metoda pozwala pobrać macierz znaków
   *
   *  Metoda pozwala pobrać ustaloną wcześniej macierz znaków, używaną do obliczania wyznacznika macierzy.
   */
  Macierz<Typ> get_macierz () { return m; }

  /*!
   * \brief Metoda pozwala ustawić wektor wyrazów wolnych
   *
   *  Metoda pozwala ustalić wektor wyrazów wolnych, używany w ustalaniu wyznaczników dla poszczególnych zmiennych.
   */
  Wektor<Typ> set_wyrazy (Wektor<Typ> wyrazy) { w = wyrazy; return w; }
  /*!
   * \brief Metoda pozwala pobrać wektor wyrazów wolnych
   *
   *  Metoda pozwala pobrać ustalony wcześniej wektor wyrazów wolnych, używany w ustalaniu wyznaczników dla poszczególnych zmiennych.
   */
  Wektor<Typ> get_wyrazy () { return w; }

  /*!
   * \brief Metoda pozwala ustawić wektor błędu
   *
   *  Metoda pozwala ustalić wektor błędu, zawierający informację o różnicy pomiędzy obliczonymi rozwiązaniami a faktycznymi rozwiązaniami układu równań liniowych.
   */
  Wektor<Typ> set_wbledu (Wektor<Typ> wbledu) { e = wbledu; return e; }
  /*!
   * \brief Metoda pozwala pobrać wektor błędu
   *
   *  Metoda pozwala pobrać ustalony wcześniej wektor błędu.
   */
  Wektor<Typ> get_wbledu () { return e; }
    
  /*!
   * \brief Metoda pozwala ustawić długość wektora błędu
   *
   *  Metoda pozwala ustalić długość obliczonego wektora blędu.
   */
  double set_blad (double blad) { b = blad; return b; }
  /*!
   * \brief Metoda pozwala pobrać długość błędu
   *
   *  Metoda pozwala pobrać ustaloną wcześniej długość wektora błedu.
   */
  double get_blad () { return b; }

  /*!
   * \brief Obliczanie rozwiązań
   *
   *  Metoda pozwala obliczyć rozwiązania układu równań
   */
  Wektor<Typ> oblicz ();

  /*!
   * \brief Obliczanie wektora błędu
   *
   *  Metoda pozwala obliczyć wektor błedu
   */
  Wektor<Typ> blad ();

  /*!
   * \brief Obliczanie długości wektora błędu
   *
   *  Metoda pozwala obliczyć długość wektora błędu
   */
  double dlugosc_blad ();

  /*!
   * \brief Ustalanie parametru czy_blad
   *
   *  Metoda pozwala ustawić parametr czy_blad
   */
  void set_czy_blad (bool blad) {czy_blad = blad; }
  /*!
   * \brief Pobieranie parametru czy_blad
   *
   *  Metoda pozwala pobrać parametr czy_blad
   */
  bool get_czy_blad () { return czy_blad; }

};

//definicja metody która pozwala obliczyć wektor rozwiązań
template <typename Typ>
Wektor<Typ> UkladRownanLiniowych<Typ>::oblicz ()
  { 
  Macierz<Typ> _mac = get_macierz();
  Wektor<Typ> _wyrazy = get_wyrazy();
  Wektor<Typ> _rozw;
  Typ _wyzn = _mac.wyznacznik();
  _rozw.set_rozmiar (get_rozmiar());
  set_wyznacznik(_wyzn);
  
  std::cout << std::endl << "Wyznacznik:    " << get_wyznacznik() << std::endl;
  Wektor<Typ> bufor;
  
  if (_wyzn!=0)
    {
      for (unsigned  int i=0; i<get_rozmiar(); ++i)
	{
	  bufor = _mac[i];
	  _mac[i] = _wyrazy;
	  _wyrazy = bufor;

	  _rozw[i] = (_mac.wyznacznik () / _wyzn);
	  
	  std::cout << "Wyznacznik["<< i+1 << "]: " << _mac.wyznacznik() << std::endl;
	  
	  _mac = get_macierz();
	  _wyrazy = get_wyrazy();
	}
	  
    }
      set_rozwiazanie(_rozw); 
      return get_rozwiazanie();
}

//definicja metody która pozwala obliczyć wektor błędu
template <typename Typ>
Wektor<Typ> UkladRownanLiniowych<Typ>::blad ()
{
  Wektor<Typ> wektor_bledu;
  
  if (get_wyznacznik() != 0)
    {
      wektor_bledu = (get_macierz() * get_rozwiazanie()) - get_wyrazy();
    }

  wektor_bledu.set_rozmiar (get_rozmiar());
  
  set_wbledu (wektor_bledu);
  return get_wbledu();
}

//definicja betody oblicza długość wektora błędu
template <typename Typ>
double UkladRownanLiniowych<Typ>::dlugosc_blad ()
{
  set_blad (sqrt (get_wbledu() * get_wbledu()));
  
  return get_blad();
}

//Wczytywanie/wypisywanie całego układu równań

template <typename Typ>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<Typ> &UklRown)
{
  Macierz<Typ> mac;
  Wektor <Typ> wek;

  mac.set_rozmiar(UklRown.get_rozmiar());
  wek.set_rozmiar(UklRown.get_rozmiar());
  
  Strm >> mac >> wek;
  UklRown.set_macierz (mac);
  UklRown.set_wyrazy (wek);
  
  return Strm;
}

template <typename Typ>
std::ostream& operator << ( std::ostream                  &Strm, 
                            UkladRownanLiniowych<Typ>    UklRown)
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

//Operator mnożenia macierzy z wektorem
template <typename Typ>
Wektor<Typ> operator * (Macierz<Typ> m, Wektor<Typ> w)
{
  unsigned int i,j;
  Wektor<Typ> bufor;
  
  for(i=0; i<m.get_rozmiar(); i++)
    {
      bufor[i]=(Typ)0;
      
      for(j=0; j<m.get_rozmiar(); j++)
	{
	  bufor[i] = bufor[i] + (m(i,j) * w[j]);
	}
    }

  return bufor;
}


#endif
