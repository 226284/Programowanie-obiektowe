#include <iostream>

using namespace std;

/*
  Definicja typu wyliczeniowego "Symbol" dla symboli  a, b, c, d, e.
*/

/*
  Definicja funkcji: Dodaj, PrzeciwnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel.
*/

/*
  Definicja przeciążeń operatorów
*/

enum Symbol {e,a,b,c,d};

Symbol TabliczkaDzialania[5][5] = { {e,a,b,c,d},
				    {a,d,e,b,c},
				    {b,e,c,d,a},
				    {c,d,b,a,e},
				    {d,c,a,e,b} };

Symbol Dodaj (Symol Arg1, Symbol Arg2)
{
  return TabliczkaDzialania[Arg1][Arg2];
}

Symbol operator + (Symbol Arg1, Symbol Arg2)
{
  return TabliczkaDzialania[Arg1][Arg2];
}

void Porownaj(Symbol wynik_alg, Symbol wynik_ope, Symbol wynik_fun)
{
 cout << ((wynik_alg == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia algebraicznego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_alg) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i algebraicznego." << endl;
}

int main()
{
 Symbol wynik_alg, wynik_ope, wynik_fun;
 
 Symbol wynik;
 wynik = Dodaj(a,b);

/*--------------------
  Po wpisaniu odpowiednich wyrażeń znaki komentujące
  poniższy zestaw instrukcji należy usunąć.

 wynik_alg = WYRAZENIE_ALG_1; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_1; // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = WYRAZENIE_OPE_1; // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = WYRAZENIE_ALG_2; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_2; // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = WYRAZENIE_OPE_2; // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = WYRAZENIE_ALG_3; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_3; // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = WYRAZENIE_OPE_3; // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = WYRAZENIE_ALG_4; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_4; // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = WYRAZENIE_OPE_4; // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);
 */
}
