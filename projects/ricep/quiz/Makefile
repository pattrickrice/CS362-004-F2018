CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme.o: testme.c
	gcc -c testme.c -g  $(CFLAGS)

testme: testme.o
	gcc -o testme testme.o -g  $(CFLAGS)

run: testme
	./testme

clean:
	rm *.o *.gcno testme