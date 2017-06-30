#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan

uklad_rownan: obj/main.o obj/UkladRownanLiniowych.o obj/Macierz.o obj/Wektor.o obj/Lzespolona.o obj/Symbol.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/Wektor.o\
                                      obj/Symbol.o obj/Lzespolona.o obj/Macierz.o obj/UkladRownanLiniowych.o

obj/main.o: src/main.cpp inc/UkladRownanLiniowych.hh inc/Macierz.hh inc/Wektor.hh inc/Lzespolona.hh\
        inc/rozmiar.h inc/Symbol.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/UkladRownanLiniowych.o: src/UkladRownanLiniowych.cpp inc/UkladRownanLiniowych.hh
	g++ ${CPPFLAGS} -o obj/UkladRownanLiniowych.o src/UkladRownanLiniowych.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh 
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/Lzespolona.o: src/Lzespolona.cpp inc/Lzespolona.hh
	g++ ${CPPFLAGS} -o obj/Lzespolona.o src/Lzespolona.cpp

obj/Symbol.o: src/Symbol.cpp inc/Symbol.hh
	g++ ${CPPFLAGS} -o obj/Symbol.o src/Symbol.cpp

clean:
	rm -f obj/*.o uklad_rownan
