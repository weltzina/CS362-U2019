#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


int checkPlayBaron(int choice1, struct gameState *state, int currentPlayer){
  struct gameState pre;
  memcpy(&pre, state, sizeof(struct gameState));

  int r;
  int card_not_discarded = 1;

  pre.numBuys++;
  printf("%d\n", pre.numBuys);

  r = playbaron(choice1, state, currentPlayer);
  printf("%d\n", state->numBuys);

/*  if(choice1 > 0){
      for(int i = 0; i < pre.handCount[currentPlayer]; i++){
        if(pre.hand[currentPlayer][i] == estate){
          card_not_discarded = 0;
          pre.coins +=4;
        }
      }
      if(card_not_discarded){
        if(pre.supplyCount[estate] > 0){
          pre.discard[currentPlayer][pre.discardCount[currentPlayer]] = estate;
          pre.discardCount[currentPlayer]++;
          pre.supplyCount[estate]--;
        }
      }
  }else{
    if(pre.supplyCount[estate] > 0){
      pre.discard[currentPlayer][pre.discardCount[currentPlayer]] = estate;
      pre.discardCount[currentPlayer]++;
      pre.supplyCount[estate]--;
    }
  }
*/
  assert(r==0);

  assert(memcmp(&pre, state, sizeof(struct gameState)) == 0);

  return 0;

}


int main(){

  int currentPlayer;
  int choice1;
  int r;
  int playerCount;

  struct gameState G;

  SelectStream(2);
  PutSeed(3);

  for(int n = 0; n < 2000; n++){
    for(int i = 0; i < sizeof(struct gameState); i++){
      ((char*)&G)[i] = floor(Random() * 128);
    }
    G.numPlayers = floor(Random() * 3)+2;
    G.whoseTurn = floor(Random() * G.numPlayers);
    for(int j = 0; j < G.numPlayers; j++){
      G.deckCount[j] = floor(Random() * MAX_DECK)+1;
      G.discardCount[j] = floor(Random() * MAX_DECK)+1;
      G.handCount[j] = floor(Random() * MAX_HAND)+1;
      for(int f = 0; f < G.deckCount[j]; f++){
        G.deck[j][f] = floor(Random() * (treasure_map +1));
      }
      for(int f = 0; f < G.discardCount[j]; f++){
        G.discard[j][f] = floor(Random() * (treasure_map +1));
      }
      for(int f = 0; f < G.handCount[j]; f++){
        G.hand[j][f] = floor(Random() * (treasure_map +1));
      }
    }
    checkPlayBaron(floor(Random()*2), &G, G.whoseTurn);
  }

return 0;

}
