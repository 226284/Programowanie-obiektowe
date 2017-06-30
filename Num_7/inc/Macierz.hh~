#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/*!
 * \brief Klasa Macierz określa macierz znaków składającą się z Wektorów
 *
 * W klasie macierz znajdują się takie atrybuty jak: Rozmiar - odpowiada za 
 przechowywanie aktualnego rozmiaru macierzy oraz K[ROZMIAR] - odpowiada za 
 przechowywanie danych w macierzy
 */
template <typename Typ>
class Macierz
{
  /*!
   * \brief Przechowuje Rozmiar macierzy
   *
   * Przechowuje rozmiar macierzy, z którego można skorzystać w każdym momencie
   */
  unsigned int Rozmiar;
  /*!
   * \brief Tworzy kolumny oparte na Wektorach
   *
   * Pole jest odpowiedzialne za przechowywanie danych w macierzy, która składa
   się z wektorów
   */
  Wektor<Typ> K[ROZMIAR];
   /*!
   * \brief Przechowuje informacje o wyznaczniku macierzy
   *
   * Pole przechowuje informacje na temat obliczonego wyznacznika macierzy
   */
  Typ Wyznacznik;

public:

  //Konstruktor nadający podstawowe parametry
  /*!
   * \brief Konstruktor zeruje wyznacznik i przypisuje domyślny rozmiar macierzy
   *
   *  Konstruktor zeruje wyznacznik i przypisuje domyślny rozmiar macierzy

   */
  Macierz<Typ> () { Rozmiar = ROZMIAR; Wyznacznik = (Typ)0;}
  
  //Operator () pozwala na swobodne poruszanie się po elementach macierzy
  /*!
   * \brief Przeciążenie pozwala na zmianę danych każdego pola macierzy
   *
   *  Przeciążenie pozwala na zmianę danych każdego pola macierzy
   */
  const Typ & operator () (const unsigned int r, const unsigned int c) const { return K[c][r]; }
  /*!
   * \brief Przeciążenie pozwala na odczyt danych każdego pola macierzy
   *
   *  Przeciążenie pozwala na odczyt danych każdego pola macierzy
   */
  Typ & operator () (const unsigned int r, const unsigned int c) { return K[c][r]; }
  
  //Operator [] pozwala na swobodne poruszanie się po kolumnach macierzy
  /*!
   * \brief Przeciążenie pozwala na zmianę danych kolumny macierzy
   *
   *  Przeciążenie pozwala na zmianę danych kolumny macierzy
   */
  const Wektor<Typ> & operator [] (unsigned int Kol) const { return K[Kol]; }
  /*!
   * \brief Przeciążenie pozwala na odczyt danych z kolumny macierzy
   *
   *  Przeciążenie pozwala na odczyt danych z kolumny macierzy
   */
  Wektor<Typ> & operator [] (unsigned int Kol) { return K[Kol]; }
  
  //Ustawianie rozmiaru
  /*!
   * \brief Metoda ustawia rozmiar macierzy
   *
   *  Metoda ustawia rozmiar macierzy
   */
  void set_rozmiar (unsigned int rozm) { Rozmiar = rozm; }
  /*!
   * \brief Metoda pobiera rozmiar macierzy
   *
   *  Metoda pobiera rozmiar macierzy
   */
  unsigned int const get_rozmiar () const { return Rozmiar; }

  //Ustawianie wyznacznika
  /*!
   * \brief Metoda ustawia wyznacznik macierzy
   *
   *  Metoda ustawia wyznacznik macierzy
   */
  Typ set_wyznacznik (Typ wyzn) { Wyznacznik = wyzn; return Wyznacznik;}
  /*!
   * \brief Metoda pobiera wyznacznik macierzy
   *
   *  Metoda pobiera wyznacznik macierzy
   */
  Typ get_wyznacznik () { return Wyznacznik; }
  /*!
   * \brief Obliczenie wyznacznika macierzy 
   *
   * Metoda liczy wyznacznik dowolnej macierzy metodą Gaussa
   */
  Typ wyznacznik ();
  
};

//Definicja metody liczenia wyznacznika
template <typename Typ>
Typ Macierz<Typ>::wyznacznik ()
  {
    unsigned int i,j,k,l;
    unsigned int rozmiar = get_rozmiar();
    Typ wynik;
    Wektor<Typ> kolumny[ROZMIAR];

    wynik = (Typ)0;

    for (i=0; i<rozmiar; ++i) 
      {
	kolumny[i] = K[i];
      }
    
    for (i=0; i<rozmiar-1; ++i){
      
      for (j=i+1; j<rozmiar; ++j){
	
	for (k=i+1; k<rozmiar; ++k){
	  
	  if (kolumny[i][i] == (Typ)0)
	    {
	      bool find = false;
	      for(l = i; l< rozmiar; ++l){
		
		if(kolumny[l][l] != (Typ)0)
		  {
		    Wektor<Typ> bufor;
		    bufor = kolumny[i];
		    kolumny[i] = kolumny[l];
		    kolumny[l] = bufor;
		    find = true;
		  }
	      }
	      
	      if(!find) return wynik*(Typ)0;
	    }
	  
	kolumny[j][k] = kolumny[j][k] - (kolumny[j][i] / kolumny[i][i] * kolumny[i][k]);
	}
      }
    }
    wynik = (Typ)1;
    for(i = 0; i<rozmiar; ++i)
      {
	wynik = wynik * kolumny[i][i];
      }
    
    return wynik * (Typ)(1);
  }

//Przeciążenie operatora >> dla wczytywania macierzy
template <typename Typ>
std::istream & operator >> (std::istream &Strm, Macierz<Typ> &Mac)
{
  unsigned int i,j;
  for (i=0; i<Mac.get_rozmiar(); i++)
    for(j=0; j<Mac.get_rozmiar(); j++)
      {
	{
	  Strm >> Mac(j,i);
	}
      }
  return Strm;
}

//Przeciążenie operatora << dla wypisywania miacierzy
template <typename Typ>
std::ostream & operator << (std::ostream &Strm, const Macierz<Typ> &Mac)
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


#endif
