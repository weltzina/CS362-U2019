/*
 * cardtest4.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "baron"

void assertTrue(int var1, int var2){
  if(var1 == var2)
    printf("TRUE\n");
  else
    printf("FALSE\n");
}

int main() {
  int newCards = 0;
  int discarded = 1;
  int xtraCoins = 0;
  int shuffledCards = 0;
  int gainedCards = 0;
  int buyincrease = 1;
  int actionsPlayed = 1;

  int i, j, m;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int remove1, remove2;
  int seed = 1000;
  int numPlayers = 2;
  int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {ambassador, embargo, village, minion, mine, cutpurse,
			baron, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);


    G.hand[thisPlayer][0] = baron;
    G.hand[thisPlayer][1] = copper;
    G.hand[thisPlayer][2] = duchy;
    G.hand[thisPlayer][4] = estate;
    G.hand[thisPlayer][3] = copper;

  	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    printf("Has %d estates\n", i);


  	printf("TEST 1: choice1 = 0 = gain +1 buy && estate card... Baron @ 0 && estate @ 4\n");

  	// copy the game state to a test case
  	memcpy(&testG, &G, sizeof(struct gameState));
  	choice1 = 0;
  	cardEffect(baron, choice1, choice2, choice3, &testG, handpos, &bonus);

    gainedCards = 1;

  	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
  	assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
  	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
  	assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
  	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
  	assertTrue(testG.coins, G.coins + xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions - actionsPlayed);
    assertTrue(testG.numActions, G.numActions - actionsPlayed);
    printf("estate supply = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    assertTrue(testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    printf("\n");


    printf("TEST 2: choice1 = 1 = gain +1 buy && discard estate && +4 coins..... Baron @ 0 && estate @ 4\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    cardEffect(baron, choice1, choice2, choice3, &testG, handpos, &bonus);

    gainedCards = 0;
    discarded = 2;
    xtraCoins = 4;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assertTrue(testG.coins, G.coins + xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions - actionsPlayed);
    assertTrue(testG.numActions, G.numActions - actionsPlayed);
    printf("estate supply = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    assertTrue(testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    printf("\n");

    G.hand[thisPlayer][4] = baron;
    G.hand[thisPlayer][2] = copper;
    G.hand[thisPlayer][1] = duchy;
    G.hand[thisPlayer][0] = estate;
    G.hand[thisPlayer][3] = copper;


    printf("TEST 3: choice1 = 0 = gain +1 buy && estate card... Baron @ 4 && estate @ 0\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0;
    cardEffect(baron, choice1, choice2, choice3, &testG, handpos, &bonus);

    gainedCards = 1;
    discarded = 1;
    xtraCoins = 0;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assertTrue(testG.coins, G.coins + xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions - actionsPlayed);
    assertTrue(testG.numActions, G.numActions - actionsPlayed);
    printf("estate supply = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    assertTrue(testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    printf("\n");


    // ----------- TEST 1: choice1 = 1 = +2 cards --------------
    printf("TEST 4: choice1 = 1 = gain +1 buy && discard estate && +4 coins..... Baron @ 4 && estate @ 0\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    printf("TEST FAILED. RUNAWAY PROGRAM.\n");
    printf("\n");
    /*
    cardEffect(baron, choice1, choice2, choice3, &testG, handpos, &bonus);

    gainedCards = 0;
    discarded = 2;
    xtraCoins = 4;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assertTrue(testG.coins, G.coins + xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions - actionsPlayed);
    assertTrue(testG.numActions, G.numActions - actionsPlayed);
    printf("estate supply = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    assertTrue(testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    printf("\n");
    */


    G.hand[thisPlayer][4] = baron;
    G.hand[thisPlayer][2] = copper;
    G.hand[thisPlayer][1] = duchy;
    G.hand[thisPlayer][0] = copper;
    G.hand[thisPlayer][3] = copper;


    printf("TEST 5: choice1 = 0 = gain +1 buy && estate card... Baron @ 4 && estate @ null\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0;
    cardEffect(baron, choice1, choice2, choice3, &testG, handpos, &bonus);

    gainedCards = 1;
    xtraCoins = 0;
    discarded = 1;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assertTrue(testG.coins, G.coins + xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions - actionsPlayed);
    assertTrue(testG.numActions, G.numActions - actionsPlayed);
    printf("estate supply = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    assertTrue(testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    printf("\n");

    printf("TEST 6: choice1 = 1 = gain +1 buy && discard estate && +4 coins... Baron @ 4 && estate @ null\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    printf("TEST FAILED. RUNAWAY PROGRAM.\n");
    printf("\n");
    /*
    cardEffect(baron, choice1, choice2, choice3, &testG, handpos, &bonus);

    gainedCards = 1;
    xtraCoins = 4;
    discarded = 1;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + gainedCards + discarded - shuffledCards);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assertTrue(testG.coins, G.coins + xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions - actionsPlayed);
    assertTrue(testG.numActions, G.numActions - actionsPlayed);
    printf("estate supply = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    assertTrue(testG.supplyCount[estate], G.supplyCount[estate] - gainedCards);
    printf("\n");
    */


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
