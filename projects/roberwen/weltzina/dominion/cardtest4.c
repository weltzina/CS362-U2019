#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "get Winners"

void assertTrue(int var1, int var2){
  if(var1 == var2)
    printf("TRUE\n");
  else
    printf("FALSE\n");
}

int main() {

  int i, j, m;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int remove1, remove2;
  int seed = 1000;
  int numPlayers = 2;
  int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {ambassador, embargo, village, minion, mine, cutpurse,
			baron, tribute, smithy, gardens};



      // initialize a game state and player cards
      initializeGame(numPlayers, k, seed, &testG);

  printf("----------------- Testing Function: %s ----------------\n", TESTCARD);


  printf("TEST 1:\n");

  memcpy(&testG, &G, sizeof(struct gameState));

  getWinners(&testG);

  printf("%d\n",players[1]);
/*
  printf("highest score = %d, expected = %d\n", testG.deckCount[thisPlayer], 5);
  assertTrue(testG.deckCount[thisPlayer], 5);
  printf("discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], 5);
  assertTrue(testG.discardCount[thisPlayer], 5);
  printf("whose turn = %d, expected = %d\n", testG.whoseTurn, G.whoseTurn+1);
  assertTrue(testG.whoseTurn, G.whoseTurn+1);
  printf("Opponent-----------------------\n");
  printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
  assertTrue(testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
  printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer]);
  assertTrue(testG.handCount[thisPlayer+1], G.handCount[thisPlayer]);
  printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer]);
  assertTrue(testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer]);
  printf("\n");
*/

}
