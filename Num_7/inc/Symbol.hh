#ifndef SYMBOL_HH
#define SYMBOL_HH

#include <iostream>
#include <iomanip>
#include <cassert>


enum Symbol {e,a,b,c,d,f,gumis};

/*************************************************************************************/
// WCZYTYWANIE
Symbol WczytSym(char wczyt);

//Przeciążanie operatora wejścia dla pojedynczego symbolu
std::istream& operator >> (std::istream &wejscie, Symbol &Wczyt);

/**************************************************************************************/
//WYŚWIETLANIE
  
char WyswSym(Symbol wysw);

//Przeciążenie operatora wyjscia "<<"
std::ostream& operator << (std::ostream &wyjscie, const Symbol Arg);

/**************************************************************************************/
/* DODAWANIE */

Symbol operator + (Symbol Arg1, Symbol Arg2);

Symbol operator + (Symbol Arg);

/**************************************************************************************/
/* ODEJMOWANIE */
 
Symbol operator - (Symbol Arg);

  Symbol operator - (Symbol Arg1, Symbol Arg2);

/**************************************************************************************/
/* MNOŻENIE */

Symbol operator * (Symbol Arg1, Symbol Arg2);

/**************************************************************************************/
/* DZIELENIE */

Symbol operator ~ (Symbol Arg);

Symbol operator / (Symbol Arg1, Symbol Arg2);


Symbol operator * (Symbol Arg1, int Arg2);


#endif
