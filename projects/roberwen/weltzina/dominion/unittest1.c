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
  int k[10] = {ambassador, minion, feast, gardens, mine
             , tribute, smithy, village, baron, great_hall};
  struct gameState G;
  int maxHandCount = 5;

  initializeGame(2, k, 22, G);

  G.hand[0][0] = 15;//Add card to the hand
  G.hand[0][0] = 1;
  G.hand[0][0] = 6;
  G.hand[0][0] = 6;
  G.hand[0][0] = 6;

    printf("TESTING playBaron():\n");
     r = playCard(0, 1, 0, 0, G);

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
