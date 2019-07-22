#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "shuffle"

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


  printf("TEST 1: no result\n");

  memcpy(&testG, &G, sizeof(struct gameState));

  shuffle(thisPlayer, &testG);

  printf("deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
  assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
  printf("discardCount = %d, expected = 0\n", testG.discardCount[thisPlayer], 0);
  assertTrue(testG.discardCount[thisPlayer], 0);
  printf("\n");


  printf("TEST 2: shuffle\n");

  G.discard[thisPlayer][0] = 1;
  G.discard[thisPlayer][1] = 2;
  G.discard[thisPlayer][0] = 3;
  G.discard[thisPlayer][1] = 4;
  G.discard[thisPlayer][0] = 5;
  G.discardCount[thisPlayer] = 5;
  G.deck[thisPlayer][0] = 0;
  G.deck[thisPlayer][0] = 0;
  G.deck[thisPlayer][0] = 0;
  G.deck[thisPlayer][0] = 0;
  G.deck[thisPlayer][0] = 0;
  G.deckCount[thisPlayer] = 0;

  memcpy(&testG, &G, sizeof(struct gameState));

  shuffle(thisPlayer, &testG);

  printf("deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
  assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
  printf("discardCount = %d, expected = 0\n", testG.discardCount[thisPlayer], 0);
  assertTrue(testG.discardCount[thisPlayer], 0);
  printf("\n");


}
