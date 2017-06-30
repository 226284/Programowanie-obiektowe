#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;


enum Symbol {e,a,b,c,d,f};

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

istream& operator >> (istream &wejscie, Symbol &Wczyt)
{
  Symbol Tab[] = {a,b,c,d,e};
  char ZnakSym;
  
  wejscie >> ZnakSym;
 
  if(ZnakSym>='a' && ZnakSym<='e')
    {
      Wczyt = Tab[ZnakSym - 'a'];
    }
  
  else Wczyt = f;

  return wejscie;
}

//WYŚWIETLANIE
  
char WyswSym(Symbol wysw)
{
  const char *Nazwa = "eabcdf";
  return Nazwa[wysw];
}

//Przeciążenie operatora wyjscia "<<"
ostream& operator << (ostream &wyjscie, Symbol Arg)
{
  wyjscie << WyswSym(Arg);
  return wyjscie;
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

  cerr << "NIE ZNALEZIONO ODWROTNEGO ELEMENTU!" << endl;
  assert(0);
  return f;
}

Symbol Dziel (Symbol Arg1, Symbol Arg2)
{
  return Arg1 * ~Arg2;
}    

Symbol operator / (Symbol Arg1, Symbol Arg2)
{
  return Arg1 * ~Arg2;
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
 // Symbol wynik_alg, wynik_ope, wynik_fun;
 

 //Testowanie
 Symbol znak;

 cin >> znak;          //przeciązenie operatora >>
 cout << znak << endl; //przeciazenie operatora <<

 /* Przykładowe wywołania */
 /*
 wynik_alg = a + b; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = Dodaj (a,b); // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = operator + (a,b); // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = c + -a; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = Dodaj (c,PrzeciwnyDodawania(a)); // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = operator - (c,a); // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = e * b; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = Mnoz (e,b); // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = operator * (e,b); // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);
 
 wynik_alg = c / a; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = Dziel (c,a); // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = operator / (c,a); // <- Wyrażenie z jawnym wywołaniem operatorów 
 
 Porownaj(wynik_alg,wynik_ope,wynik_fun);
 */
}
