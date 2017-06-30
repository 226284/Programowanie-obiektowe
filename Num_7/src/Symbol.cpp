#include "Symbol.hh"


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
std::istream& operator >> (std::istream &wejscie, Symbol &Wczyt)
{
  char ZnakSym;
  
  wejscie >> ZnakSym;

  Wczyt = WczytSym(ZnakSym);
  return wejscie;
}


char WyswSym(Symbol wysw)
{
  const char *Nazwa = "eabcdf";
  return Nazwa[wysw];
}

//Przeciążenie operatora wyjscia "<<"
std::ostream& operator << (std::ostream &wyjscie, const Symbol Arg)
{
  wyjscie << WyswSym(Arg);
  return wyjscie;
}


Symbol operator + (Symbol Arg1, Symbol Arg2)
{
  return TabliczkaDzialania[Arg1][Arg2];
}

Symbol operator + (Symbol Arg)
{
  return Arg;
}


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
  
  std::cerr << "ZMIANA ZNAKU NA - : NIE ZNALEZIONO PRZECIWNEGO ELEMENTU!" << std::endl;
  assert(0);
  return f;
}

Symbol operator - (Symbol Arg1, Symbol Arg2)
{
  return Arg1 + -Arg2;
}


Symbol operator * (Symbol Arg1, Symbol Arg2)
{
  return TabliczkaMnozenia[Arg1][Arg2];
}


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

Symbol operator * (Symbol Arg1, int Arg2)
{
  Symbol tmp = Arg1;

  if (Arg2 == -1) {tmp = -tmp; return tmp; }

  else if (Arg2 == 0) { return e; }

  else if (Arg2 == 1) { return tmp;}

  else return f; //error
}
