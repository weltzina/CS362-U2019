#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


int assertTrue(int var1, int var2){
  if(var1 != var2){
    printf("FALSE---------------------------------------------------------\n");
    return 0;
  }else{
    return 1;
  }
}



int checkPlayBaron(int choice1, struct gameState *state, int currentPlayer){
  struct gameState pre;
  memcpy(&pre, state, sizeof(struct gameState));

  int r;
  int card_not_discarded = 1;

  pre.numBuys++;

  r = playbaron(choice1, state, currentPlayer);

  if(choice1 > 0){
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


  if(!assertTrue(memcmp(&pre, state, sizeof(struct gameState)), 0) || r != 0){
      printf("Estate SupplyCount = %d, expected %d\n");
      printf("DiscardCount = %d, expected %d\n");
      printf("Coins = %d, expected %d\n");
      printf("Buys = %d, expected %d\n");

      /*
      int numPlayers; //number of players
      int supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
      int embargoTokens[treasure_map+1];
      int outpostPlayed;
      int outpostTurn;
      int whoseTurn;
      int phase;
      int numActions; /* Starts at 1 each turn */
      //int coins; /* Use as you see fit! */
      //int numBuys; /* Starts at 1 each turn */
      /*int hand[MAX_PLAYERS][MAX_HAND];
      int handCount[MAX_PLAYERS];
      int deck[MAX_PLAYERS][MAX_DECK];
      int deckCount[MAX_PLAYERS];
      int discard[MAX_PLAYERS][MAX_DECK];
      int discardCount[MAX_PLAYERS];
      int playedCards[MAX_DECK];
      int playedCardCount;*/
  }
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

  for(int n = 0; n < 10; n++){
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
