TASKNO=5
APP=przetwarzanie_sygnalu
TASKDIR=${HOME}/edu/po/zad/z${TASKNO}

__start__: obj ./${APP}
	rm -f core.* core; ./${APP}

# Tworzy katalog "obj" gdy go nie ma
# 
obj:
	mkdir -p obj

./${APP}: obj/main.o obj/main.o obj/lacze_do_gnuplota.o
	g++ -o ./${APP} obj/main.o obj/lacze_do_gnuplota.o


obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh 
	g++  -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

obj/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp


clean:
	rm -f obj/* ./${APP} core.* core
	rmdir obj

${TASKDIR}:
	mkdir -p ${TASKDIR}/bin.diablo ${TASKDIR}/bin.panamint

__TARGET__:
	if [ ! "${HOST}" = "diablo" ] && [ ! "${HOST}" = "panamint" ]; then exit 1; fi

help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo " make help   - wyswietla niniejsza informacje"
	@echo
