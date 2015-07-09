SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .cc .o

BOOSTDIR = /usr/lib# was: /home/julian/software/boost_1_57_0

INCLUDEDIR = -I. -I$(BOOSTDIR)
LIBDIR = -L$(BOOSTDIR)/lib
LIBS = -lboost_unit_test_framework
CFLAGS = -Wall -Wextra -Wpedantic -std=c++1y -O3 -g
CC = g++

test_orbits: test_orbits.o
	$(CC) $(LIBDIR) $(CFLAGS) $< $(LIBS) -o $@

test_orbits.o: test_orbits.cc orbit.h
	$(CC) $(INCLUDEDIR) $(CFLAGS) -c $< -o $@


main: main.o
	$(CC) $(CFLAGS) $< -o $@

main.o: main.cc orbit.h
	$(CC) $(CFLAGS) -c $< -o $@


main2: main2.o
	$(CC) $(CFLAGS) $< -o $@

main2.o: main2.cc orbit.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o test_orbits main main2
