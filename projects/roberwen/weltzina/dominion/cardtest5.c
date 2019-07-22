#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "draw card"

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
      initializeGame(numPlayers, k, seed, &G);

  printf("----------------- Testing Function: %s ----------------\n", TESTCARD);


  printf("TEST 1:\n");

  memcpy(&testG, &G, sizeof(struct gameState));

  drawCard(thisPlayer, &testG);

  printf("card 6 = %d, expected = %d\n", testG.hand[thisPlayer][testG.handCount[thisPlayer]-1], G.deck[thisPlayer][G.deckCount[thisPlayer]-1]);
  assertTrue(testG.hand[thisPlayer][testG.handCount[thisPlayer]-1], G.deck[thisPlayer][G.deckCount[thisPlayer]-1]);
  printf("\n");


  printf("TEST 2:\n");

  G.discardCount[thisPlayer] = 0;
  G.deckCount[thisPlayer] = 0;

  memcpy(&testG, &G, sizeof(struct gameState));

  drawCard(thisPlayer, &testG);

  printf("card 6 = %d, expected = %d\n", testG.hand[thisPlayer][testG.handCount[thisPlayer]-1], null);
  assertTrue(testG.hand[thisPlayer][testG.handCount[thisPlayer]-1], null);
  printf("\n");

}
