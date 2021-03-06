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
  element_t Wyznacznik;
  /*!
   * \brief Przechowuje macierz znaków 
   *
   * Macierz znaków zawiera poszczególne współczynniki, stojące przy zmiennych w kolejnych równaniach układu równań liniowych.
   */
  Macierz m; //macierz znaków
  /*!
   * \brief Przechowuje wektor wyrazów wolnych
   *
   * Wektor wyrazów wolnych zawiera prawe strony równań liniowych układu równań liniowych.
   */
  Wektor w;  //wektor wyrazów wolnych
  /*!
   * \brief Przechowuje wektor rozwiązań
   *
   * Wektor zawiera rozwiązania układu równań liniowych obliczone za pomocą wzorów Cramera.
   */
  Wektor r;  //wektor rozwiązań
  /*!
   * \brief Przechowuje wektor błędu
   *
   * Wektor błedu to obliczona różnica pomiędzy wyliczonymi rozwiązaniami a faktycznymi rozwiązaniami układu. Wynika ona z przechowywania liczb przez komputer.
   */
  Wektor e;  //wektor błędu
  /*!
   * \brief Przechowuje długość wektora błędu
   *
   * Dłuogśc wektora błędu wyliczona jest ze standardowego wzoru na długośc wektora.
   */
  element_t b; //dl wektora błędu
  
public:
  
  /*!
   * \brief Metoda poznwla na zmianę rozmiaru macierzy,wektora oraz układu równań
   *
   *  Metoda ta zmienia ilość wykorzystywanego miejsca w macierzy kwadratowej i wektorze wyrazów wolnych o rozmiarze równym ROZMIAR.
   */
  unsigned int set_rozmiar (unsigned int rozm)
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
  element_t set_wyznacznik (element_t wyzn) {return m.set_wyznacznik(wyzn); }
  /*!
   * \brief Metoda pozwala pobrać wyznacznik z układu równań
   *
   *  Metoda pobiera ustalony wcześniej wyznacznik macierzy.
   */
  element_t get_wyznacznik () { return Wyznacznik; }
  
  /*!
   * \brief Metoda pozwala ustawić wektor rozwiązań
   *
   *  Metoda ustala wektor rozwiązań, zawierający poszczególne rozwiązania dla kolejnych zmiennych.
   */
  void set_rozwiazanie (Wektor rozw) { r = rozw; }
  /*!
   * \brief Metoda pozwala pobrać wektor rozwiązań
   *
   *  Metoda pobiera ustalony wcześniej wektor rozwiązań.
   */
  Wektor get_rozwiazanie () { return r; }

  /*!
   * \brief Metoda pozwala modyfikować macierz znaków
   *
   *  Metoda pozwala ustalić macierz znaków, używaną wobliczaniu wyznacznika macierzy.
   */
  Macierz set_macierz (Macierz mac) { m = mac; return m; }
  /*!
   * \brief Metoda pozwala pobrać macierz znaków
   *
   *  Metoda pozwala pobrać ustaloną wcześniej macierz znaków, używaną do obliczania wyznacznika macierzy.
   */
  Macierz get_macierz () { return m; }

  /*!
   * \brief Metoda pozwala ustawić wektor wyrazów wolnych
   *
   *  Metoda pozwala ustalić wektor wyrazów wolnych, używany w ustalaniu wyznaczników dla poszczególnych zmiennych.
   */
  Wektor set_wyrazy (Wektor wyrazy) { w = wyrazy; return w; }
  /*!
   * \brief Metoda pozwala pobrać wektor wyrazów wolnych
   *
   *  Metoda pozwala pobrać ustalony wcześniej wektor wyrazów wolnych, używany w ustalaniu wyznaczników dla poszczególnych zmiennych.
   */
  Wektor get_wyrazy () { return w; }

  /*!
   * \brief Metoda pozwala ustawić wektor błędu
   *
   *  Metoda pozwala ustalić wektor błędu, zawierający informację o różnicy pomiędzy obliczonymi rozwiązaniami a faktycznymi rozwiązaniami układu równań liniowych.
   */
  Wektor set_wbledu (Wektor wbledu) { e = wbledu; return e; }
  /*!
   * \brief Metoda pozwala pobrać wektor błędu
   *
   *  Metoda pozwala pobrać ustalony wcześniej wektor błędu.
   */
  Wektor get_wbledu () { return e; }
    
  /*!
   * \brief Metoda pozwala ustawić długość wektora błędu
   *
   *  Metoda pozwala ustalić długość obliczonego wektora blędu.
   */
  element_t set_blad (element_t blad) { b = blad; return b; }
  /*!
   * \brief Metoda pozwala pobrać długość błędu
   *
   *  Metoda pozwala pobrać ustaloną wcześniej długość wektora błedu.
   */
  element_t get_blad () { return b; }

};

//Wczytywanie/wypisywanie całego układu równań

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << ( std::ostream                  &Strm, 
                            UkladRownanLiniowych    UklRown);



//Funkcja rozwiąż oblicza rozwiązania wzorami Cramera i wpisuje je do wektora r

Wektor oblicz (UkladRownanLiniowych &u);


//Operator mnożenia macierzy z wektorem

Wektor operator * (Macierz m, Wektor w);


//Funkcja oblicza wektor błędu 

Wektor blad (UkladRownanLiniowych &u);


//Funkcja oblicza długość wektora błędu 

element_t dlugosc_blad (UkladRownanLiniowych &u);


#endif
