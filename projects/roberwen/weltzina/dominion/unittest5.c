#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "mine"

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
  int trashed = 0;

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

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);


    G.hand[thisPlayer][0] = mine;
    G.hand[thisPlayer][1] = ambassador;
    G.hand[thisPlayer][2] = copper;
    G.hand[thisPlayer][4] = estate;
    G.hand[thisPlayer][3] = tribute;

    G.coins = 1;


  	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);


    printf("TEST 1: copper @ 2, silver..... tribute @ 0\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 2;
    choice2 = 5;
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    discarded = 1;
    newCards = 0;
    shuffledCards = 0;
    gainedCards = 1;
    xtraCoins = 1;
    buyincrease = 0;
    actionincrease = 0;
    actionsPlayed = 1;
    returnCards = 0;
    OppDiscard = 0;
    trashed = 1;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded - trashed + gainedCards);
    assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded - trashed + gainedCards);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assertTrue(testG.coins, G.coins + xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions - actionsPlayed + actionincrease);
    assertTrue(testG.numActions, G.numActions - actionsPlayed + actionincrease);
    printf("\n");
    printf("Opponent state test--------------------------------\n");
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer] - OppDiscard);
    assertTrue(testG.handCount[thisPlayer+1], G.handCount[thisPlayer] - OppDiscard);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
    assertTrue(testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer] + OppDiscard);
    assertTrue(testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer] + OppDiscard);



    printf("TEST 2: copper @ 2, gold..... tribute @ 0\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 2;
    choice2 = 6;
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    discarded = 0;
    newCards = 0;
    shuffledCards = 0;
    gainedCards = 1;
    xtraCoins = 0;
    buyincrease = 0;
    actionincrease = 0;
    actionsPlayed = 0;
    returnCards = 0;
    OppDiscard = 0;
    trashed = 0;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded - trashed + gainedCards);
    assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded - trashed + gainedCards);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assertTrue(testG.coins, G.coins + xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions - actionsPlayed + actionincrease);
    assertTrue(testG.numActions, G.numActions - actionsPlayed + actionincrease);
    printf("\n");
    printf("Opponent state test--------------------------------\n");
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer] - OppDiscard);
    assertTrue(testG.handCount[thisPlayer+1], G.handCount[thisPlayer] - OppDiscard);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
    assertTrue(testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer] + OppDiscard);
    assertTrue(testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer] + OppDiscard);



    printf("TEST 3: copper @ 2, copper..... tribute @ 0\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 2;
    choice2 = 4;
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    discarded = 1;
    newCards = 0;
    shuffledCards = 0;
    gainedCards = 1;
    xtraCoins = 0;
    buyincrease = 0;
    actionincrease = 0;
    actionsPlayed = 1;
    returnCards = 0;
    OppDiscard = 0;
    trashed = 1;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded - trashed + gainedCards);
    assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded - trashed + gainedCards);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assertTrue(testG.coins, G.coins + xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions - actionsPlayed + actionincrease);
    assertTrue(testG.numActions, G.numActions - actionsPlayed + actionincrease);
    printf("\n");
    printf("Opponent state test--------------------------------\n");
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer] - OppDiscard);
    assertTrue(testG.handCount[thisPlayer+1], G.handCount[thisPlayer] - OppDiscard);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
    assertTrue(testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer] + OppDiscard);
    assertTrue(testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer] + OppDiscard);



    printf("TEST 4: silver @ 2, gold..... tribute @ 0\n");


    G.hand[thisPlayer][2] = silver;

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 2;
    choice2 = 6;
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    discarded = 0;
    newCards = 0;
    shuffledCards = 0;
    gainedCards = 0;
    xtraCoins = 0;
    buyincrease = 0;
    actionincrease = 0;
    actionsPlayed = 0;
    returnCards = 0;
    OppDiscard = 0;
    trashed = 0;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded - trashed + gainedCards);
    assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded - trashed + gainedCards);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assertTrue(testG.coins, G.coins + xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions - actionsPlayed + actionincrease);
    assertTrue(testG.numActions, G.numActions - actionsPlayed + actionincrease);
    printf("\n");
    printf("Opponent state test--------------------------------\n");
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer] - OppDiscard);
    assertTrue(testG.handCount[thisPlayer+1], G.handCount[thisPlayer] - OppDiscard);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
    assertTrue(testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer]);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer] + OppDiscard);
    assertTrue(testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer] + OppDiscard);

}
