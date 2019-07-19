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
    int j, it;
    int k[10] = {ambassador, council_room, minion, gardens, mine
               , tribute, smithy, village, baron, great_hall};

    struct gameState save;
    //struct gameState G;

    int maxHandCount = 5;


    save->outpostPlayed = 0;
    save->phase = 0;
    save->numActions[0] = 1;
    save->numBuys[0] = 1;
    save->playedCardCount = 0;
    save->whoseTurn = 0;

    save->supplyCount[estate] = 10;
    save->discardCount[0] = 0;
    save->discard[0];

    save->hand[0] = [15, 1, 6, 6, 6];
    save->handCount[0] = 4;
    //G->coins = 9;

    printf("TESTING playBaron():\n");
    playBaron(1, save, 0);

    #if (NOISY_TEST == 1)
      printf("save.numBuys = %d, expected = %d\n", save->numBuys, save->numBuys + 1);
    #endif
      assert(save.numBuys == save->numBuys + 1);

      printf("save.numActions = %d, expected = %d\n", save.numActions, 0);
      assert(save.numActions == 0);

      printf("save.coins = %d, expected = %d\n", save.coins, 13);
      assert(save.coins == 13);

      printf("save.supplyCount[estate] = %d, expected = 10\n", save.supplyCount[estate]);
      assert(save.supplyCount[estate] == 10);

      printf("save.discardCount = %d, expected = 1\n", save.discardCount);
      assert(save.discardCount == 1);

    return 0;
}
