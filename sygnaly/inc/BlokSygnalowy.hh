#ifndef BLOKSYGNALOWY_HH
#define BLOKSYGNALOWY_HH
#include <string>

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

/*!
 * \brief Zawiera definicję klasy BlokBazowy
 *
 *  Zawiera definicję kalsy BlokBazowy, która jest
 *  klasą bazową dla elementarnych bloków sygnałowych.
 */

/*!
 * \brief Modeluje wartość sygnału w powiązaniu z czasem
 *
 * Klasa modeluje wartość sygnału w danej chwili czasowej.
 */
class Sygnal {
   /*!
    * \brief Przechwouje wartość sygnału
    *
    *  Pole zawiera wartość sygnału.
    */
   double  _WartoscSyg;
  /*!
   * \brief Przechowuje czas skojarzony z wartością sygnału
   *
   *  Pole przechowuje czas skojarzony z wartością sygnału.
   *  O interpretacji jednostki czasu decyduje konwencja
   *  przyjęta w danym programie.
   */
   double _Czas;
  public:
   /*!
    * \brief Inicjalizuje wartościami zerowymi
    *
    *  Inicjalizuje wartościami zerowymi zarówno pole
    *  wartości sygnału, jak też pole czasu. 
    */
   Sygnal(): _WartoscSyg(0), _Czas(0) {}
   /*!
    * \brief Udostępnia czas
    *
    *  Udostępnia czas pamiętany w polu \link Sygnal::_Czas _Czas\endlink.
    */ 
   double WezCzas() const { return _Czas; }
   /*!
    * \brief Udostępnia wartość
    *
    *  Udostępnia czas pamiętany w polu 
    *  \link Sygnal::_WartoscSyg _WartoscSyg\endlink.
    */ 
   double WezWartoscSyg() const { return _WartoscSyg; }
   /*!
    * \brief Zmienia wartość czasu
    *  
    * Zmienia wartość czasu.
    * \warning  Czas powinien być zmieniany TYLKO w bloku
    *           generatora sygnału.
    * \param[in] Czas - nowa wartość czas
    */
   void ZmienCzas(double Czas)  { _Czas = Czas; }
   /*!
    * \brief Zmienia wartość syganłu
    *  
    * Zmienia wartość sygnału.
    * \warning  Czas powinien być zmieniany TYLKO w bloku
    *           generatora sygnału.
    *
    * \param[in] WartoscSyg - nowa wartość sygnału
    */
   void ZmienWartoscSyg(double WartoscSyg) { _WartoscSyg = WartoscSyg; }
};




/*!
 * \brief Modeluje najważniejsze elementy bloku sygnałowego
 *
 * Klasa modeluje najważniejsze cechy bloku sygnałowego.
 */
class BlokSygnalowy {
 public:
  /*!
   * \brief Inicjalizuje wartość sygnału wejściowego
   *
   *   Inicjalizuje wartość sygnału wejściowego wartością 0.
   */
  BlokSygnalowy() {}
  /*!
   * \brief f Inicjalizuje wartość sygnału wejściowego
   *
   * Inicjalizuje wartość sygnału wejściowego wartością 0 oraz etykietę
   * bloku.
   * \param[in] Etykieta - etykieta bloku.
   */
  BlokSygnalowy(const char* Etykieta): _Etykieta(Etykieta) {}
  /*!
   * \brief Zapewnia poprawne wywołanie destruktorów klasy pochodnej
   *
   * Destruktor jest wirtualny dlatego też zapewnia
   * poprawne wywołanie destruktorów klasy pochodnej.
   */
  virtual ~BlokSygnalowy() {}

  /*!
   * \brief Zwraca informację czy należy zakończyć pracę.
   *
   *  Zwraca informację czy należy zakończyć pracę.
   * Metoda jest istotna jedynie dla bloku generatora, który
   * realizuje np. czytanie sygnału z pliku.
   * Zwrócenie wartości true powoduje zakończenie powinno powodować
   * zakończenie pętli wyliczania sygnału.
  */
  virtual bool CzyZakonczycPrace() const { return false; }


  /*!
   * \brief Jest wywoływany, gdy trzeba zakończyć pracę bloku
   *
   * Jest wywoływany, gdy trzeba zakończyć pracę bloku.
   * Metoda jest istotna jedynie dla bloku, który
   * realizuje np. zapisywanie obliczonych wartości dla pliku
   * lub innego typu operacje. Dla zwykłych bloków sygnałowych
   * metodę tę nie trzeba redefiniować. 
   */
  virtual void ZakonczPrace() {}

  /*!
   * \brief Wylicza wartość sygnału wyjściowego
   *
   *  Wylicza wartość sygnału wyjściowego. Na wejście metody
   *  jest przekazywany wcześniej wyliczony sygnał z wejścia
   *  bloku sygnałowego.\n
   *
   *  Metoda ta powinna być redefiniowana w klasie pochodnej.
   *
   *  \param[in] Syg - wartość sygnału, która została
   *             wyliczona przez metodę 
   *      \link BlokSygnalowy::WyliczSygnalWej   WyliczSygnalWej\endlink.
   *  \post Wynik działania zapisywany jest w polu
   *        \link BlokSygnalowy::_SygnalWyj _SygnalWyj\endlink
   */
  virtual bool WyliczSygnalWyj(const Sygnal& Syg) { _SygnalWyj = Syg; return true; }
  /*!
   * \brief Wylicza sygnał wejściowy
   *
   *  Wylicza sygnał wejściowy. Domyślnie jako pierwszy parametr
   *  jest przekazywana wartość sygnało z bloku poprzedniego w liście.
   *  \param[in] SygWe - sygnał wejściowy,
   *  \param[out] SygObliczony - wartość obliczonego sygnału wejściowego.
   */
  virtual bool WyliczSygnalWej(const Sygnal& SygWe, 
                                     Sygnal& SygObliczony
			       ) { SygObliczony = SygWe;  return true; }

  /*!
   * \brief Udostępnia identyfikator bloku
   *
   *  Udostępnia liczbowy identyfikator bloku, który określa jego typ.
   *  Metoda, o ile będzie pomocna (zależy od przyjętej koncepcji),
   *  powinna być redefiniowana w klasie pochodnej.
   */
  virtual int Identyfikator() const { return 0; }

  /*!
   * \brief Udostępnia nazwę typu bloku
   *
   *  Udostępnia nazwę typu bloku, np. może to być "Blok calkujacy".
   *  Metoda ta powinna być redefiniowana w klasie pochodnej.
   */
  virtual const char* NazwaBloku() const { return "Blok bazowy"; }


  /*!
   * \brief Udostępnia opis bloku
   *
   *  Udostępnia opis, tzn jaki to jest blok, jakie ma parametry itd.
   */
  virtual std::string OpisBloku() const { return "Opis pusty"; }
 

  /*!
   * \brief Udostępnia wartość sysgnału wyjściowego
   *
   *  Udostępnia wartość sygnału wyjśiowego.
   */
  const Sygnal &  WezSygnalWyj() const { return _SygnalWyj; }

  /*!
   * \brief Zmienia wartość sygnału, który widoczny jest na wyjściu bloku
   *
   *   Zmienia wartość sygnału, który widoczny jest na wyjściu bloku.
   *   \param[in] Syg - nowa wartość sygnału, która będzie widoczna
   *                    jak wartość sygnału wyjściowego.
   */
  void ZmienSygnalWyj(Sygnal Syg) { _SygnalWyj = Syg; }

  /*!
   * \brief Udostępnia etykietę bloku
   *
   * Udostępnia etykietę bloku jako zwykły napis.
   */
  const std::string &  WezEtykiete() const { return _Etykieta; }


  /*!
   * \brief Zmienia etykietę danego bloku
   *
   * Zmienia etykietę danego bloku.
   * \param[in] Etykieta - nowa etykieta, która zostanie przypisana
   *                       danemu blokowi.
   */
  virtual void ZmienEtykiete(const char* Etykieta) { _Etykieta = Etykieta; }

  /*!
   * \brief Zmienia etykietę danego bloku
   *
   * Zmienia etykietę danego bloku.
   * \param[in] Etykieta - nowa etykieta, która zostanie przypisana
   *                       danemu blokowi.
   */
  virtual void ZmienEtykiete(const std::string& Etykieta) { _Etykieta = Etykieta; }

  /*!
   * Wyświetla wszystkie wejscia i wyjscia danego bloku.
   */
  virtual void WyswietlPolaczenia() const {}

 protected:
  /*!
   * \brief Zawiera wartość sygnału wyjściowego dla danej chwili
   *
   * Zawiera wartość sygnału wyjściowego dla danej chwili.
   * Który wyliczany jest na podstawie wartości sygnałów 
   * na wejściu.
   * 
   */
  Sygnal _SygnalWyj;

 private:
  /*!
   * \brief Etykieta bloku symulacji
   *
   * Pole zawiera etykietę bloku sygnałowego. Może ona
   * zostać użyta jako gdy blok jest przechowywany na liście
   * lub jakiejkolwiek innej kolekcji.
   */
  std::string  _Etykieta;
};


#endif
