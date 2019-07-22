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
  int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {ambassador, embargo, village, minion, mine, cutpurse,
			baron, tribute, smithy, council_room};



  printf("----------------- Testing Function: %s ----------------\n", TESTCARD);


  printf("TEST 1:\n");

  numPlayers = 1;

  memcpy(&testG, &G, sizeof(struct gameState));

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &testG);

  printf("number of players = %d, expected = %d\n", testG.numPlayers, G.numPlayers);
  assertTrue(testG.numPlayers, G.numPlayers);
  printf("\n");


  printf("TEST 2:\n");

  numPlayers = 5;

  memcpy(&testG, &G, sizeof(struct gameState));

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &testG);

  printf("number of players = %d, expected = %d\n", testG.numPlayers, G.numPlayers);
  assertTrue(testG.numPlayers, G.numPlayers);
  printf("\n");


  printf("TEST 3:\n");

  k[2] = ambassador;
  numPlayers = 2;

  memcpy(&testG, &G, sizeof(struct gameState));

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &testG);

  printf("number of players = %d, expected = %d\n", testG.numPlayers, G.numPlayers);
  assertTrue(testG.numPlayers, G.numPlayers + numPlayers);
  printf("\n");


  printf("TEST 4:\n");

  numPlayers = 2;
  k[2] = village;

  memcpy(&testG, &G, sizeof(struct gameState));

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &testG);

  printf("number of players = %d, expected = %d\n", testG.numPlayers, G.numPlayers);
  assertTrue(testG.numPlayers, G.numPlayers + numPlayers);
  printf("Supply count victory = %d, expected = %d\n", testG.supplyCount[estate], victoryCards);
  printf("supply count regular = %d, expected = %d\n",  testG.supplyCount[tribute], regularCards);
  printf("supply count copper = %d, expected = %d\n", testG.supplyCount[copper], copperCards);
  printf("supply count silver = %d, expected = %d\n",  testG.supplyCount[silver], silverCards);
  printf("supply count gold = %d, expected = %d\n", testG.supplyCount[gold], goldCards);
  printf("\n");

}
