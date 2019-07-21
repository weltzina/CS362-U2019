#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "initializeGame"

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
  int returnCards = 0;
  int thisPlayer = 0;
  int OppDiscard = 0;
	struct gameState G, testG;
	int k[10] = {ambassador, embargo, village, minion, mine, cutpurse,
			baron, tribute, smithy, council_room};



  printf("----------------- Testing Function: %s ----------------\n", TESTCARD);


  printf("TEST 1:\n");

  numPlayers = 1;

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &G);

  printf("number of players = %d, expected = null\n", G.numPlayers);
  assertTrue(G.numPlayers, 0);
  printf("\n");

}
