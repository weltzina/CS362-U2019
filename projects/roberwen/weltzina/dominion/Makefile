CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)


#########

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

random: randomtestcard1.c dominion.o rngs.o
	gcc -o random1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtestresults: 

random1: randomtestcard1.c dominion.c rngs.c
	echo "Result for running Random Dominion tests:" > unittestresults.out
	echo "randomtestcard1.c:" >> unittestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out

random2: randomtestcard2.c dominion.c rngs.c
	echo "Result for running Random Dominion tests:" > unittestresults.out
	echo "randomtestcard2.c:" >> unittestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out

random3: randomtestcard3.c dominion.c rngs.c
	echo "Result for running Random Dominion tests:" > unittestresults.out
	echo "randomtestcard3.c:" >> unittestresults.out
	gcc -o randomtestcard3 dominion.c rngs.c randomtestcard3.c $(CFLAGS)
	./randomtestcard3 >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
