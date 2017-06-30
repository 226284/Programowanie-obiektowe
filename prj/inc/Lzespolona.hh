#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>

/*
 * Opisy przedstawione w tym pliku nalezy odpowiednio zmienic.
 */

/*!
 * \brief Klasa LZespolona określa liczbę zespoloną
 *
 *  Klasa zawiera argumenty układu równań liniowych w postaci liczb ze zbioru liczb zespolonych.
 */
class LZespolona {
  /*!
   * \brief Przechowuje część rzeczywistą liczby zespolonej
   *
   * Pole przechowuje część rzeczywistą liczby zespolonej.
   */
   double  _re;
  /*!
   * \brief Przechowuje część urojoną liczby zespolonej
   *
   * Pole przechowuje część urojoną liczby zespolonej.
   */
   double  _im;

 public:
  /*!
   * \brief Konstruktor zeruje zmienne re i im
   *
   * Konstruktor powoduje przypisanie części rzeczywistej i części urojonej wartości 0.
   */
   LZespolona();

  /*!
   * \brief Możemy pobrać dane o części rzeczywistej
   *
   *  Metoda pozwala pobrać wartość części rzeczywistej liczby zespolonej.
   */
   double  Re() const;
  /*!
   * \brief Możemy ustawić dane części zespolonej
   *
   *  Metoda pozwala ustalić wartość części rzeczywistej liczby zespolonej.
   */
   double& Re();
  /*!
   * \brief Możemy pobrać dane z części urojonej
   *
   *  Metoda pozwala pobrać wartość części urojonej liczby zespolonej.
   */
   double  Im() const;
  /*!
   * \brief Możemy zapisać dane do części urojonej
   *
   *  Metoda pozwala ustalić wartość części urojonej liczby zespolonej.
   */
   double& Im();

  /*!
   * \brief Przeciążenie daje możliwość dodawania liczb zespolonych
   *
   *  Przeciążenie operatora pozwala dodać do siebie dwie liczby zespolone poprzez dodanie ich części rzeczywistych i części urojonych.
   */
   LZespolona  operator + (const LZespolona&  Arg2) const;
  /*!
   * \brief Przeciążenie daje możliwość odejmowania liczb zespolonych
   *
   *  Przeciążenie operatora pozwala odjąć od siebie dwie liczby zespolone poprzez odjęcie ich części rzeczywistych i części urojonych.
   */
   LZespolona  operator - (const LZespolona&  Arg2) const;
  /*!
   * \brief Przeciążenie daje możliwość mnożenia liczb zespolonych
   *
   *  Przeciążenie operatora pozwala pomnożyć przez siebie dwie liczby zespolone.
   */
  LZespolona  operator * (const LZespolona&  Arg2) const;
  /*!
   * \brief Przeciążenie daje możliwość dzielenia liczb zespolonych
   *
   *  Przeciążenie operatora pozwala podzielić przez siebie dwie liczby zespolone.
   */
  LZespolona  operator / (const LZespolona&  Arg2) const;
};

/*!
 * \brief Przeciążenie wczytyje LZespoloną na standardowe wejście
 *
 *  Przeciążenie pozwala wpisać liczbę zespoloną na standardowe wejście.
 */
std::istream&  operator >> ( std::istream&      StrmWe,  
                             LZespolona&  WyswietlanaLiczba
			   ); 
/*!
 * \brief Przeciążenie wypisuje LZespoloną na standardowe wyjście
 *
 *  Przeciążenie pozwala wypisać liczbę zespoloną na standardowe wyjście.
 */
std::ostream&  operator << ( std::ostream&      StrmWy,  
                             const LZespolona&  WyswietlanaLiczba
			   ); 

#endif
