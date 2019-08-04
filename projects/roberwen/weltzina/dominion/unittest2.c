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
  int discarded = 0;
  int xtraCoins = 0;
  int shuffledCards = 0;
  int gainedCards = 0;
  int buyincrease = 0;
  int actionsPlayed = 0;
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


    G.hand[thisPlayer][0] = minion;
    G.hand[thisPlayer][1] = copper;
    G.hand[thisPlayer][2] = duchy;
    G.hand[thisPlayer][4] = estate;
    G.hand[thisPlayer][3] = copper;

    G.hand[thisPlayer+1][0] = G.deck[thisPlayer+1][9];
    G.hand[thisPlayer+1][1] = G.deck[thisPlayer+1][8];
    G.hand[thisPlayer+1][2] = G.deck[thisPlayer+1][7];
    G.hand[thisPlayer+1][3] = G.deck[thisPlayer+1][6];
    G.hand[thisPlayer+1][4] = G.deck[thisPlayer+1][5];
    G.deckCount[thisPlayer+1] = 5;
    G.handCount[thisPlayer+1] = 5;
    G.discardCount[thisPlayer+1] = 0;

  	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);


  	printf("TEST 1: choice1 = 0 && choice2 = 0.... Chose none. Nothing should happen. minion @ 0\n");

  	// copy the game state to a test case
  	memcpy(&testG, &G, sizeof(struct gameState));
  	choice1 = 0;
    choice2 = 0;

    playMinion(minion, choice1, choice2, 0, testG, handPos, &bonus, thisPlayer);

    discarded = 0;
    newCards = 0;
    shuffledCards = 0;
    gainedCards = 0;
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
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1]);
    assertTrue(testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1]);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer+1]);
  	assertTrue(testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer+1]);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer+1]);
    assertTrue(testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer+1]);
    printf("\n");


    printf("TEST 2: choice1 = 0 && choice2 = 1.... +1 action && discard hand && draw 4 cards from deck && both happen to other players with > 4 cards in hand. minion @ 0\n");

  	// copy the game state to a test case
  	memcpy(&testG, &G, sizeof(struct gameState));
  	choice1 = 0;
    choice2 = 1;

  	playMinion(minion, choice1, choice2, 0, testG, handPos, &bonus, thisPlayer);

    discarded = 5;
    newCards = 4;
    shuffledCards = 0;
    gainedCards = 0;
    xtraCoins = 0;
    buyincrease = 0;
    actionincrease = 1;
    actionsPlayed = 0;

  	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded + newCards);
  	assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded + newCards);
  	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
  	assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded - shuffledCards);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded - shuffledCards);
  	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
  	assertTrue(testG.coins, G.coins +xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions + actionincrease - actionsPlayed);
    assertTrue(testG.numActions, G.numActions + actionincrease - actionsPlayed);
    printf("Opponent state test--------------------------------\n");
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1] - discarded + newCards);
    assertTrue(testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1] - discarded + newCards);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount - newCards);
  	assertTrue(testG.deckCount[thisPlayer+1], G.deckCount - newCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer+1] + discarded);
    assertTrue(testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer+1] + discarded);
    printf("\n");


    printf("TEST 3: choice1 = 1 && choice2 = 0.... +2 coins && +1 action..... minion @ 0\n");

  	// copy the game state to a test case
  	memcpy(&testG, &G, sizeof(struct gameState));
  	choice1 = 1;
    choice2 = 0;

  	playMinion(minion, choice1, choice2, 0, testG, handPos, &bonus, thisPlayer);

    discarded = 0;
    newCards = 0;
    shuffledCards = 0;
    gainedCards = 0;
    xtraCoins = 2;
    buyincrease = 0;
    actionincrease = 1;
    actionsPlayed = 0;

  	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded + newCards);
  	assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded + newCards);
  	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
  	assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded - shuffledCards);
    assertTrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded - shuffledCards);
  	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
  	assertTrue(testG.coins, G.coins +xtraCoins);
    printf("buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + buyincrease);
    assertTrue(testG.numBuys, G.numBuys + buyincrease);
    printf("action count = %d, expected = %d\n", testG.numActions, G.numActions + actionincrease - actionsPlayed);
    assertTrue(testG.numActions, G.numActions + actionincrease - actionsPlayed);
    printf("Opponent state test--------------------------------\n");
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1]);
    assertTrue(testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1]);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer+1]);
  	assertTrue(testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer+1]);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer+1]);
    assertTrue(testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer+1]);
    printf("\n");


    printf("TEST 4: choice1 = 1 && choice2 = 1.... Nothing should happen..... minion @ 0\n");

    // copy the game state to a test case
  	memcpy(&testG, &G, sizeof(struct gameState));
  	choice1 = 1;
    choice2 = 1;

    playMinion(minion, choice1, choice2, 0, testG, handPos, &bonus, thisPlayer);

    discarded = 0;
    newCards = 0;
    shuffledCards = 0;
    gainedCards = 0;
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
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1]);
    assertTrue(testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1]);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer+1]);
  	assertTrue(testG.deckCount[thisPlayer+1], G.deckCount[thisPlayer+1]);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer+1]);
    assertTrue(testG.discardCount[thisPlayer+1], G.discardCount[thisPlayer+1]);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

}
