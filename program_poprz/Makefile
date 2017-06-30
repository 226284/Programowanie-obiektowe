__start__: obj przetwarzanie_sygnalu
	./przetwarzanie_sygnalu

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall



obj:
	mkdir obj

przetwarzanie_sygnalu: obj/main.o obj/BlokSygnalowy.o obj/ListaBlokow.o obj/BlokDyskryminacji.o\
                          obj/BlokPotegujacy.o obj/BlokProstujacy.o
	g++ ${LDFLAGS} -o przetwarzanie_sygnalu obj/main.o obj/BlokSygnalowy.o\
                          obj/ListaBlokow.o obj/BlokDyskryminacji.o obj/BlokPotegujacy.o\
                          obj/BlokProstujacy.o


obj/main.o: src/main.cpp inc/BlokSygnalowy.hh inc/ListaBlokow.hh inc/BlokDyskryminacji.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/BlokSygnalowy.o: src/BlokSygnalowy.cpp inc/BlokSygnalowy.hh
	g++ ${CPPFLAGS} -o obj/BlokSygnalowy.o src/BlokSygnalowy.cpp

obj/BlokDyskryminacji.o: src/BlokDyskryminacji.cpp inc/BlokDyskryminacji.hh
	g++ ${CPPFLAGS} -o obj/BlokDyskryminacji.o src/BlokDyskryminacji.cpp

obj/BlokPotegujacy.o: src/BlokPotegujacy.cpp inc/BlokPotegujacy.hh
	g++ ${CPPFLAGS} -o obj/BlokPotegujacy.o src/BlokPotegujacy.cpp

obj/BlokProstujacy.o: src/BlokProstujacy.cpp inc/BlokProstujacy.hh
	g++ ${CPPFLAGS} -o obj/BlokProstujacy.o src/BlokProstujacy.cpp

obj/ListaBlokow.o: src/ListaBlokow.cpp inc/ListaBlokow.hh inc/BlokSygnalowy.hh
	g++ ${CPPFLAGS} -o obj/ListaBlokow.o src/ListaBlokow.cpp

clean:
	rm -f przetwarzanie_sygnalu obj/* core*


doc: __generuj_doc__

__generuj_doc__:
	cd ../dox;  make

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean - usuwa produkty kompilacji oraz program"
	@echo "  doc   - powoduje generowanie dokumentacji"
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo "  make doc       # generuje dokumentacje w doc/html"
	@echo
 
