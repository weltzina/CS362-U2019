/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
  int i;
  int seed = 1000;
  int numPlayer = 2;
  int maxBonus = 10;
  int p, r, handCount;
  int bonus;
  int it[5];
  int k[10] = {ambassador, minion, feast, gardens, mine
             , tribute, smithy, village, baron, great_hall};
  struct gameState G;
  int maxHandCount = 5;




    G.outpostPlayed = 0;
    G.phase = 0;
    G.numActions = 1;
    G.numBuys = 1;
    G.playedCardCount = 0;
    G.whoseTurn = 0;

    G.supplyCount[estate] = 10;
    G.discardCount[0] = 0;

    G.hand[0] = it[15, 1, 6, 6, 6];
    G.handCount[0] = 4;
    G.coins = 9;

    printf("TESTING playBaron():\n");
    playBaron(1, G, 0);

    #if (NOISY_TEST == 1)
      printf("G.numBuys = %d, expected = %d\n", G.numBuys, 2);
    #endif
      assert(G.numBuys == 2);

      printf("G.numActions = %d, expected = %d\n", G.numActions, 0);
      assert(G.numActions == 0);

      printf("G.coins = %d, expected = %d\n", G.coins, 13);
      assert(G.coins == 13);

      printf("G.supplyCount[estate] = %d, expected = %d\n", G.supplyCount[estate], 10);
      assert(G.supplyCount[estate] == 10);

      printf("G.discardCount = %d, expected = %d\n", G.discardCount, 1);
      assert(G.discardCount == 1);

    return 0;
}
