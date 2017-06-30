#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


typedef float element_t;   //deklaracja elementów z których składa się wektor

/*!
 * \brief Klasa Wektor określa wektor którego argumentami są liczby zespolone
 *
 *  Klasa Wektor to tablica jednowymiarowa o odpowiednim rozmiarze, zawierająca argumenty w postaci liczb zespolonych. Wektor wykorzystywany jest w tworzeniu macierzy, wektora wyrazów wolnych, wektora błedu i wektora rozwiązań.
 */

class Wektor
{
  /*!
   * \brief Przechowuje rozmiar Wektora
   *
   * Pole zawiera aktualny rozmiar wektora, zgodny z rozmiarem macierzy kwadratowej.
   */
  unsigned int Rozmiar;
  /*!
   * \brief Przechowuje wektor
   *
   * Pole przechowuje wektor, czyli tablicę jednowymiarową odpowiedniego rozmiaru wraz z odpowiednimi argumentami.
   */
  element_t W[ROZMIAR];

public:
  
  Wektor () {Rozmiar = ROZMIAR;}
  
  //Operator [] pozwala na odwoływanie się do poszczególnych elementów wektora
   /*!
   * \brief Konstruktor pozwala na zmianę elementów wektora
   *
   * Konstruktor pozwala zmienić konkretny argument, czyli element wektora.
   */
  const element_t & operator [] (const unsigned int i) const { return W[i]; }
   /*!
   * \brief Konstruktor pozwala na pobranie danych z elementów wektora
   *
   * Konstruktor pozwala pobrać wartośc konkretnego argumentu, czyli elementu wektora.
   */
  element_t & operator [] (const unsigned int i) { return W[i]; }
   
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

//Przeciążenia wczytujące wektor i wypisujące go

std::istream & operator >> (std::istream &Strm, Wektor &Wek);

std::ostream & operator << (std::ostream &Strm, const Wektor &Wek);


// DODAWANIE WEKTORÓW

Wektor operator + (Wektor w1, Wektor w2);


// ODEJMOWANIE

Wektor  operator - (Wektor w1, Wektor w2);


// MNOŻENIE WEKTORÓW (ILOCZYN SKALARNY)

element_t operator * (Wektor w1, Wektor w2);


// MNOŻENIE PRZEZ LICZBE

Wektor operator * (float Liczba, Wektor w);


// DZIELENIE PRZEZ LICZBE

Wektor operator / (Wektor w, int Liczba);



#endif
