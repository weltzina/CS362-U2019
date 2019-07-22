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

  int players[MAX_PLAYERS];

  int winner;

      // initialize a game state and player cards
      initializeGame(numPlayers, k, seed, &G);

  printf("----------------- Testing Function: %s ----------------\n", TESTCARD);


  printf("TEST 1:\n");

  memcpy(&testG, &G, sizeof(struct gameState));

  getWinners(players, &testG);

  for(i = 0; i < MAX_PLAYERS; i++){
    if(players[i] > 0)
      winner = i;
  }
  int expected = 1;

  printf("winner = %d, expected = %d\n", winner, expected);
  assertTrue(winner, expected);
  printf("\n");



  printf("TEST 2:\n");

  G.deck[thisPlayer][0] = gold;
  G.deck[thisPlayer+1][0] = estate;

  memcpy(&testG, &G, sizeof(struct gameState));

  getWinners(players, &testG);

  for(i = 0; i < MAX_PLAYERS; i++){
    if(players[i] > 0)
      winner = i;
  }
  int expected = 1;

  printf("winner = %d, expected = %d\n", winner, expected);
  assertTrue(winner, expected);
  printf("\n");


  printf("TEST 3:\n");

  G.deck[thisPlayer+1][0] = province;
  G.deck[thisPlayer+1][1] = province;
  G.deck[thisPlayer+1][2] = province;
  G.deck[thisPlayer+1][3] = province;
  G.deck[thisPlayer+1][4] = province;
  G.deck[thisPlayer+1][5] = province;
  G.deckCount[thisPlayer+1] = 6;

  memcpy(&testG, &G, sizeof(struct gameState));

  getWinners(players, &testG);

  for(i = 0; i < MAX_PLAYERS; i++){
    if(players[i] > 0)
      winner = i;
  }
  int expected = 1;

  printf("winner = %d, expected = %d\n", winner, expected);
  assertTrue(winner, expected);
  printf("\n");

}
