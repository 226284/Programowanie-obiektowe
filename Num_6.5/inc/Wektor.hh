#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include "Lzespolona.hh"
#include "Symbol.hh"
#include <iostream>


typedef double element_t;   //deklaracja elementów z których składa się wektor

/*!
 * \brief Klasa Wektor określa wektor którego argumentami są liczby zespolone
 *
 *  Klasa Wektor to tablica jednowymiarowa o odpowiednim rozmiarze, zawierająca argumenty w postaci liczb zespolonych. Wektor wykorzystywany jest w tworzeniu macierzy, wektora wyrazów wolnych, wektora błedu i wektora rozwiązań.
 */

template <typename Typ>
class Wektor
{
  /*!
   * \brief Przechowuje wektor
   *
   * Pole przechowuje wektor, czyli tablicę jednowymiarową odpowiedniego rozmiaru wraz z odpowiednimi argumentami.
   */
  Typ W[ROZMIAR];
  /*!
   * \brief Przechowuje aktualny rozmiar
   *
   * Pole przechowuje aktualny rozmiar, daje możliwość zmiany rozmiaru wektora
   */
  unsigned int Rozmiar;

public:
  /*!
   * \brief Konstruktor wektora
   *
   * Konstruktor pozwala ustawić domyślne parametry wektora
   */
  Wektor () {Rozmiar = ROZMIAR; for(int i=0;i<Rozmiar;++i){W[i]=(Typ)0;}}

   /*!
   * \brief Operator [] pozwala na zmianę elementów wektora
   *
   * Operator [] pozwala zmienić konkretny argument, czyli element wektora.
   */
  const Typ & operator [] (const unsigned int i) const { return W[i]; }
   /*!
   * \brief Operator [] pozwala na pobranie danych z elementów wektora
   *
   * Operator [] pozwala pobrać wartośc konkretnego argumentu, czyli elementu wektora.
   */
  Typ & operator [] (const unsigned int i) { return W[i]; }
   
  /*!
   * \brief Metoda ustawia rozmiar wektora
   *
   * Metoda pozwala zmienić rozmiar wektora, czyli wykorzystywane przez wektor miejsce.
   */
  void set_rozmiar (unsigned int rozm) { Rozmiar = rozm; }
   /*!
   * \brief Metoda pobiera rozmiar wektora
   *
   * Metoda pozwala pobrać wartość ustalonego wcześniej rozmiaru wektora.
   */
  unsigned int const get_rozmiar () const { return Rozmiar; }

};

// Przeciążenie operatora >> dla wczytywania wektora
template <typename Typ>
std::istream & operator >> (std::istream &Strm, Wektor<Typ> &Wek)
{
  unsigned int i;
  for (i=0; i<Wek.get_rozmiar(); i++)
    {
      Strm >> Wek[i];
    }
  return Strm;
}

// Przeciążenie operatora << dla wypisywania wektora
template <typename Typ>
std::ostream & operator << (std::ostream &Strm, const Wektor<Typ> &Wek)
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
template <typename Typ>
Wektor<Typ> operator + (Wektor<Typ> w1, Wektor<Typ> w2)
{

  for (unsigned int i=0; i<w1.get_rozmiar(); i++)
    {
      w1[i] = w1[i] + w2[i];
    }
  
  return w1;
}

// ODEJMOWANIE
template <typename Typ>
Wektor<Typ> operator - (Wektor<Typ> w1, Wektor<Typ> w2)
{
  for (unsigned int i=0; i<w1.get_rozmiar(); i++)
    {
      w1[i] = w1[i] - w2[i];
    }
  
  return w1;
}

// MNOŻENIE WEKTORÓW (ILOCZYN SKALARNY) DLA LICZB ZESPOLONYCH
template <typename Typ>
double operator * (Wektor<Typ> w1, Wektor<LZespolona> w2)
{
  double wynik=0;

  for (unsigned int i=0; i<w1.get_rozmiar(); i++)
  {
    wynik = wynik + (w1[i].Re() * w2[i].Re());
    wynik = wynik + (w1[i].Im() * w2[i].Im());
  }
  return wynik;
}

// MNOŻENIE WEKTORÓW (ILOCZYN SKALARNY) DLA LICZB RZECZYWISTYCH
template <typename Typ>
double operator * (Wektor<Typ> w1, Wektor<double> w2)
{
  double wynik=0;

  for (unsigned int i=0; i<w1.get_rozmiar(); i++)
  {
    wynik += w1[i] * w2[i];
  }
  return wynik;
}

// MNOŻENIE WEKTORÓW (ILOCZYN SKALARNY) DLA SYMBOLI
template <typename Typ>
double operator * (Wektor<Typ> w1, Wektor<Symbol> w2)
{
  double wynik=0;

  for (unsigned int i=0; i<w1.get_rozmiar(); i++)
  {
    wynik = wynik + (w1[i] * w2[i]);
  }
  return wynik;
}

// MNOŻENIE PRZEZ LICZBE
template <typename Typ>
Wektor<Typ> operator * (double Liczba, Wektor<Typ> w)
{
  for (unsigned int i=0; i<w.get_rozmiar(); i++)
    {
      w[i] = Liczba * w[i];
    }
  
  return w;
}

// DZIELENIE PRZEZ LICZBE
template <typename Typ>
Wektor<Typ> operator / (Wektor<Typ> w, double Liczba)
{
  for (unsigned int i=0; i<w.get_rozmiar(); i++)
    {
      w[i] = w[i] / Liczba;
    }
  
  return w;
}


#endif
