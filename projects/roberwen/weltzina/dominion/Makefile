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


testResults: randomtestcard1.c randomtestcard2.c randomtestcard3.c unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c dominion.c rngs.c
	echo "Results for testing group mates refactored functions:" > testresults.out
	echo "randomtestcard1.c:" >> testresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> testresults.out
	gcov dominion.c -f -b >> testresults.out

	echo "randomtestcard2.c:" >> testresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> testresults.out
	gcov dominion.c -f -b >> testresults.out

	echo "randomtestcard3.c:" >> testresults.out
	gcc -o randomtestcard3 dominion.c rngs.c randomtestcard3.c $(CFLAGS)
	./randomtestcard3 >> testresults.out
	gcov dominion.c -f -b >> testresults.out

	echo "unittest1.c:" >> testresults.out
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	./unittest1 >> testresults.out
	gcov dominion.c -f -b >> testresults.out

	echo "unittest2.c:" >> testresults.out
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	./unittest2 >> testresults.out
	gcov dominion.c -f -b >> testresults.out

	echo "unittest3.c:" >> testresults.out
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	./unittest3 >> testresults.out
	gcov dominion.c -f -b >> testresults.out

	echo "unittest4.c:" >> testresults.out
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	./unittest4 >> testresults.out
	gcov dominion.c -f -b >> testresults.out

	echo "unittest5.c:" >> testresults.out
	gcc -o unittest5 dominion.c rngs.c unittest5.c $(CFLAGS)
	./unittest5 >> testresults.out
	gcov dominion.c -f -b >> testresults.out

unit1: unittest1.c dominion.c rngs.c
	echo "Result for running unit Dominion tests:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out

unit2: unittest2.c dominion.c rngs.c
	echo "Result for running unit Dominion tests:" > unittestresults.out
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out

unit3: unittest3.c dominion.c rngs.c
	echo "Result for running unit Dominion tests:" > unittestresults.out
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out

unit4: unittest4.c dominion.c rngs.c
	echo "Result for running unit Dominion tests:" > unittestresults.out
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out

unit5: unittest5.c dominion.c rngs.c
	echo "Result for running unit Dominion tests:" > unittestresults.out
	echo "unittest5.c:" >> unittestresults.out
	gcc -o unittest5 dominion.c rngs.c unittest5.c $(CFLAGS)
	./unittest5 >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out

randomtestresults: randomtestcard1.c randomtestcard2.c randomtestcard3.c dominion.c rngs.c
	echo "Result for running random Dominion tests:" > randomtestresults.out
	echo "randomtestcard1.c:" >> randomtestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	gcov dominion.c -f -b >> randomtestresults.out

	echo "randomtestcard2.c:" >> randomtestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	gcov dominion.c -f -b >> randomtestresults.out

	echo "randomtestcard3.c:" >> randomtestresults.out
	gcc -o randomtestcard3 dominion.c rngs.c randomtestcard3.c $(CFLAGS)
	./randomtestcard3 >> randomtestresults.out
	gcov dominion.c -f -b >> randomtestresults.out

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

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)


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


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 unittest5 cardtest1 cardtest2 cardtest3 cardtest4 cardtest5
