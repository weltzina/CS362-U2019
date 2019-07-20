#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "minion"

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
  int actionincrease = 0;

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


    G.hand[thisPlayer][0] = ambassador;
    G.hand[thisPlayer][1] = copper;
    G.hand[thisPlayer][2] = duchy;
    G.hand[thisPlayer][4] = estate;
    G.hand[thisPlayer][3] = copper;

  	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);


    for(i=-1; i <= 5; i++){
      for(j=-1; j <= 4){

        printf("TEST %d,%d: choice1 = %d && choice2 = %d.... ambassador @ 0\n", i, j, i, j);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = i;
        choice2 = j;
        cardEffect(minion, choice1, choice2, choice3, &testG, handpos, &bonus);

        discarded = 0;
        newCards = 0;
        shuffledCards = 0;
        gainedCards = 1;
        xtraCoins = 0;
        buyincrease = 0;
        actionincrease = 0;
        actionsPlayed = 0;

        printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
        assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer]);
        printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
        assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
        printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
        assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
        printf("coins = %d, expected = %d\n", testG.coins, G.coins);
        assertTrue(testG.coins, G.coins);
        printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys);
        assertTrue(testG.numBuys, G.numBuys);
        printf("action count = %d, expected = %d\n", testG.numActions, G.numActions);
        assertTrue(testG.numActions, G.numActions);
        printf("\n");
        printf("Opponent state test--------------------------------\n");
        printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer]);
        assertTrue(testG.handCount[thisPlayer+1], G.handCount[thisPlayer]);
        printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
        assertTrue(testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
        printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer]);
        assertTrue(testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer]);
        printf("\n");
      }




    }


}
