#include <iostream>
#include <cassert>
#include <iomanip> //dla funkcji setprecision()

using namespace std;


enum Symbol {e,a,b,c,d,f,gumis};

/**************************************************************************************/
//STATYSTYKA
struct Statystyka
{
  int Calkowita_liczba=0;
  int Poprawne_wyniki=0;
  int Bledna_skladnia=0;
  int Niepoprawny_wynik=0;
  int Dodawanie_odejmowanie=0;
  int Mnozenie_dzielenie=0;
};

/*************************************************************************************/
//WYRAŻENIE ALGEBRAICZNE
struct WyrazenieAlg
{
  Symbol Arg1, Arg2, Wynik;
  char Operator, Operator2;
};

/*************************************************************************************/
// WCZYTYWANIE
Symbol WczytSym(char wczyt)
{
  Symbol Tab[]={a,b,c,d,e};
  
  if(wczyt>='a' && wczyt<='e')
    {
      return Tab[wczyt - 'a'];
    }
  
  else return f;
}
//Przeciążanie operatora wejścia dla pojedynczego symbolu
istream& operator >> (istream &wejscie, Symbol &Wczyt)
{
  char ZnakSym;
  
  wejscie >> ZnakSym;

  Wczyt = WczytSym(ZnakSym);
  return wejscie;
}

//Przeciążanie operatora >> dla całego wyrażenia
istream& operator >> (istream &wejscie, WyrazenieAlg &we)
{
  wejscie >> we.Arg1 >> we.Operator >> we.Arg2 >> we.Operator2 >> we.Wynik;
  return wejscie;
}

/**************************************************************************************/
//WYŚWIETLANIE
  
char WyswSym(Symbol wysw)
{
  const char *Nazwa = "eabcdf";
  return Nazwa[wysw];
}

//Przeciążenie operatora wyjscia "<<"
ostream& operator << (ostream &wyjscie, const Symbol Arg)
{
  wyjscie << WyswSym(Arg);
  return wyjscie;
}

//Wyświetlanie Całego wyrażenia
ostream& operator << (ostream &wyjscie, const WyrazenieAlg &wy)
{
  wyjscie << wy.Arg1 << " " << wy.Operator << " " << wy.Arg2 << " = " << wy.Wynik;
  return wyjscie;
}

/**************************************************************************************/
//WYPISYWANIE STRUKTURY
void Wypisz_stat(Statystyka &stat)
{
  cout << endl << " STATYSTYKA:"<< endl;
  cout << "                        Całkowita liczba wyrażeń: "<< stat.Calkowita_liczba << endl;
  cout << "                 Ilość wyrażeń z błędną składnią: "<< stat.Bledna_skladnia << endl;
  cout << "             Ilość wyrażeń z prawidłową składnią: "<< stat.Calkowita_liczba - stat.Bledna_skladnia << endl;
  cout << "              Ilość wyrażeń z poprawnym wynikiem: "<< stat.Poprawne_wyniki << endl;
  cout << " Ilość wyrażeń z poprawnym wynikiem (procentowo): "<< setprecision(2+2)<<((float)stat.Poprawne_wyniki/(stat.Calkowita_liczba - stat.Bledna_skladnia))*100.0 <<"%"<<endl;
  cout << "           Ilość wyrażeń z niepoprawnym wynikiem: "<< stat.Niepoprawny_wynik << endl;
  cout << "          Ilość operacji dodawania i odejmowania: "<< stat.Dodawanie_odejmowanie<<endl;
  cout << "             Ilość operacji mnozenia i dzielenia: "<< stat.Mnozenie_dzielenie << endl;
}

/**************************************************************************************/
/* TABLICZKA DODAWANIA I ODEJMOWANIA */

Symbol TabliczkaDzialania[5][5] = { {e,a,b,c,d},
				    {a,d,e,b,c},
				    {b,e,c,d,a},
				    {c,d,b,a,e},
				    {d,c,a,e,b} };

/**************************************************************************************/
/* TABLICZKA MNOŻENIA I DZIELENIA */

Symbol TabliczkaMnozenia[5][5] = { {e,e,e,e,e},
				   {e,a,b,c,d},
				   {e,b,a,d,c},
				   {e,c,d,b,a},
				   {e,d,c,a,b} };

/**************************************************************************************/
/* DODAWANIE */

Symbol Dodaj (Symbol Arg1, Symbol Arg2)
{
  return TabliczkaDzialania[Arg1][Arg2];
}

Symbol operator + (Symbol Arg1, Symbol Arg2)
{
  return TabliczkaDzialania[Arg1][Arg2];
}

Symbol operator + (Symbol Arg)
{
  return Arg;
}

/**************************************************************************************/
/* ODEJMOWANIE */

Symbol Przeciwny;
 
Symbol operator - (Symbol Arg)
{
   //Znajdowanie elementu przeciwnego:
  int i;

  for(i=0; i<=4; i++)
    {
      Przeciwny = TabliczkaDzialania[e][i];
      
      if(Przeciwny + Arg == e)
	{
	  return Przeciwny;
	}
    }
  
  cerr << "ZMIANA ZNAKU NA - : NIE ZNALEZIONO PRZECIWNEGO ELEMENTU!" << endl;
  assert(0);
  return f;
}

Symbol Odejmij (Symbol Arg1, Symbol Arg2)
{
  return Arg1 + -Arg2;
}

Symbol operator - (Symbol Arg1, Symbol Arg2)
{
  return Arg1 + -Arg2;
}

Symbol PrzeciwnyDodawania (Symbol Arg)
{
  return -Arg;
}

/**************************************************************************************/
/* MNOŻENIE */

Symbol Mnoz (Symbol Arg1, Symbol Arg2)
{
  return TabliczkaMnozenia[Arg1][Arg2];
}

Symbol operator * (Symbol Arg1, Symbol Arg2)
{
  return TabliczkaMnozenia[Arg1][Arg2];
}

/**************************************************************************************/
/* DZIELENIE */

Symbol Odwrotny;

Symbol operator ~ (Symbol Arg)
{
  int i;

  for(i=0; i<=4; i++)
    {
      Odwrotny = TabliczkaMnozenia[a][i];

      if(Odwrotny * Arg == a)
        {
          return Odwrotny;
        }
    }

  //cerr << "  BŁĄD: NIE ZNALEZIONO ODWROTNEGO ELEMENTU!" << endl;
  //assert(0);
  return gumis;
}

Symbol Dziel (Symbol Arg1, Symbol Arg2)
{
  return Arg1 * ~Arg2;
}    

Symbol operator / (Symbol Arg1, Symbol Arg2)
{
  if (~Arg2 == gumis)
    {
      //cout << "Nie można podzielić przez e" << endl;
      return gumis;
    }
  else
    {
      return Arg1 * ~Arg2;
    }
}

Symbol OdwrotnyMnozenia (Symbol Arg)
{
  return ~Arg;
}

/**************************************************************************************/
/* POTEGOWANIE */

Symbol ElemPotega[] = {e,b,c,d,e};

Symbol Potega (Symbol Arg)
{
  return ElemPotega[Arg];
}
/*
Symbol operator ~ (Symbol Arg)
{
  return ElemPotega[Arg];
}
*/
/**************************************************************************************/
// SPRWADZENIE CZY WSZYSTKIE OPERACJE DAJĄ TEN SAM WYNIK 

void Porownaj(Symbol wynik_alg, Symbol wynik_ope, Symbol wynik_fun)
{
 cout << ((wynik_alg == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia algebraicznego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_alg) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i algebraicznego." << endl << endl;
}

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

int main()
{
  Statystyka stat;
  WyrazenieAlg alg;
  
  cout << "Start sprawdzianu z arytmetyki symboli " << endl << endl;
  
    while(cin >> alg) //wprowadzanie danych zakończy się po wciśniećiu CTRL+D
    {

  //Sprawdzenie czy ogólna składnia wyrażenia jest prawidłowa
    if ((alg.Operator=='+' || alg.Operator=='-' || alg.Operator=='*' || alg.Operator=='/') && (alg.Arg1!=f && alg.Arg2!=f) && (alg.Operator2=='=') && (alg.Wynik!=f))
    { 
      cout << "Odczytano wyrażenie: ";
      cout << alg << endl; //jeżeli wyrażenie jest poprawne to wypisujemy je
      
      if (alg.Operator=='+') //sprawdzenie znaku pierwszego operatora
	{
	  ++stat.Dodawanie_odejmowanie;
	  if((alg.Arg1 + alg.Arg2) != alg.Wynik) //sprawdzenie wyniku dodawania
	    {
	      cout << "  Wynik niepoprawny. Właściwy wynik to: ";
	      cout << (alg.Arg1 + alg.Arg2) << endl; //jeżeli niepoprawyny wynik to 
	      ++stat.Niepoprawny_wynik;              //wypisujemy poprawny
	    }
	  else
	    {
	      ++stat.Poprawne_wyniki;
	      cout << "  Wynik poprawny." << endl; //jeżeli poprawny to tylko komunikat
	    }	
	}
      else if (alg.Operator=='-') // to samo tyczy się pozostałych operatorów
	{
	  ++stat.Dodawanie_odejmowanie;
	  if((alg.Arg1 - alg.Arg2) != alg.Wynik)
	    {
	      cout << "  Wynik niepoprawny. Właściwy wynik to: ";
	      cout << alg.Arg1 - alg.Arg2 << endl;
	      ++stat.Niepoprawny_wynik;
	    }
	  else
	    {
	      ++stat.Poprawne_wyniki;
	      cout << "  Wynik poprawny." << endl;
	    }
	}
      else if (alg.Operator=='*')
	{
	  ++stat.Mnozenie_dzielenie;
	  if((alg.Arg1 * alg.Arg2) != alg.Wynik)
	    {
	      cout << "  Wynik niepoprawny. Właściwy wynik to: ";
	      cout << (alg.Arg1 * alg.Arg2) << endl;
	      ++stat.Niepoprawny_wynik;
	    }
	  else
	    {
	      ++stat.Poprawne_wyniki;
	      cout << "  Wynik poprawny." << endl;
	    }	
	}
      else if (alg.Operator=='/')
	{
	  ++stat.Mnozenie_dzielenie;
	  if((alg.Arg1 / alg.Arg2) != alg.Wynik && (alg.Arg1 / alg.Arg2) != gumis) // gumis wypada kiedy dzielimy przez e
	    {
	      cout << "  Wynik niepoprawny. Właściwy wynik to: ";
	      cout << alg.Arg1 / alg.Arg2 << endl;
	      ++stat.Niepoprawny_wynik;
	    }
	  else if ((alg.Arg1 / alg.Arg2) == gumis) // w przypadku zwrócenia gumisia wesłany będzie konunikat o błędzie
	    {
	      cerr<< "  Nie można podzielić przez e" <<endl;
	    }
	  else
	    {
	      ++stat.Poprawne_wyniki;
	      cout << "  Wynik poprawny." << endl;
	    }
	}
      else cerr << " To nie powinno się wyświetlić :P " << endl;
      
      ++stat.Calkowita_liczba; // dla statystyki
    }

  else //czyli gdy wyrażenie jest niepoprawnie zbudowane
    {
      cout << "Błąd składni wyrażenia!" << endl;
      ++stat.Bledna_skladnia;   //statystyka
      ++stat.Calkowita_liczba;

      if (alg.Arg1==f) //jeżeli Arg1 źle wprowadzony 
	{
	  cout << "  Niepoprawny znak pierwszego elementu." << endl;
	}
               // jeżeli operator źle wprowadzony
      else if (alg.Operator!='+' && alg.Operator!='-' && alg.Operator!='*' && alg.Operator!='/')
	{
	  cout << "  Niedozwolony znak operatora." << endl;
	}

      else if (alg.Arg2==f) //drugi Arg źle prowadzony
	{
	  cout << "  Niepoprawny znak drugiego elementu." << endl;
	}
      else if (alg.Operator2!='=') //nie podano znaku = lub podano inny
	{
	  cout << "  Brak znaku '='." << endl;
	}
      else if (alg.Wynik==f)
	{
	  cout << "  Niepoprawny znak wyniku.";
	}
      else cerr << "  To nie powinno się pojawić :(" <<endl;
    }
    }
  //wypisanie statystyki
  Wypisz_stat(stat);
}
