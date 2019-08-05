/*
Author: Alec Weltzin
Date: 7/28/2019
Description: random test for minionEffect functiom found in dominion.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

//my own version of assert which doesn't halt test.
int assertTrue(int var1, int var2){
  if(var1 != var2){
    printf("FALSE--------------------------------------------------------------\n");
    return 0;
  }else{
    printf("TRUE---------------------------------------------------------------\n\n\n\n");
    return 1;
  }
}


/*
function called by main random test function to take copy of random state, alter to expected results, and check against actual minionEffect results.
*/
int checkPlayMinion(int choice1, int choice2, struct gameState *state, int currentPlayer, int handPos){
  struct gameState pre;
  memcpy(&pre, state, sizeof(struct gameState));

  int players[pre.numPlayers];
  int r;
  int bonus = 0;

  if(choice1){
    pre.coins += 2;
  }else if(choice2){
    for(int i = 0; i < pre.handCount[pre.whoseTurn]; i++){
      pre.discard[pre.whoseTurn][pre.discardCount[pre.whoseTurn]] = pre.hand[pre.whoseTurn][pre.handCount[pre.whoseTurn]];
      pre.discardCount[pre.whoseTurn]++;
      pre.handCount[pre.whoseTurn]--;
    }
    for(int j = 0; j < 4; j++){
      drawCard(pre.whoseTurn, &pre);
    }
    for(int f = 0; f < pre.numPlayers; f++){
      if(pre.handCount[f] > 4){
        for(int k = 0; k < pre.handCount[f]; k++){
          pre.discard[f][pre.discardCount[f]] = pre.hand[f][pre.handCount[f]];
          pre.discardCount[f]++;
          pre.handCount[f]--;
          players[f] = 1;
        }
        for(int g = 0; g < 4; g++){
          drawCard(f, &pre);
        }
      }
    }
  }else{
    pre.coins += 2;
  }
  pre.numActions++;

  r = playMinion(minion, choice1, choice2, 0, state, handPos, &bonus, currentPlayer);

  if(!assertTrue(memcmp(&pre, state, sizeof(struct gameState)), 0)){
    printf("DiscardCount = %d, expected %d\n", state->discardCount[currentPlayer], pre.discardCount[currentPlayer]);
    printf("Hand Count = %d, expected %d\n", state->handCount[currentPlayer], pre.handCount[currentPlayer]);
    printf("Deck Count = %d, expected %d\n", state->deckCount[currentPlayer], pre.deckCount[currentPlayer]);
    printf("coins = %d, expected %d\n", state->coins, pre.coins);
    for(int q = 0; q < pre.numPlayers; q++){
      if(players[q] == 1){
        printf("player %d discard = %d, expected %d\n", q, state->discardCount[q], pre.discardCount[q]);
        printf("player %d deck = %d, expected %d\n", q, state->deckCount[q], pre.deckCount[q]);
        printf("player %d hand = %d, expected %d\n\n\n\n", q, state->handCount[q], pre.handCount[q]);
      }
    }
  }

  return 0;

}

/*
Main function that sets random gameStae(within certain parameters) and checks the minionEffect method of dominion.c for each random gamestate
*/
int main(){

  int currentPlayer;
  int choice1;
  int r;
  int playerCount;

  struct gameState G;

  SelectStream(2);
  PutSeed(3);

  for(int n = 0; n < 750; n++){
    /*for(int i = 0; i < sizeof(struct gameState); i++){
      ((char*)&G)[i] = floor(Random() * 256);
    }*/
    for(int t = 0; t <= treasure_map; t++){
      G.supplyCount[t] = floor(Random() * (treasure_map+2))-1;
    }
    G.numPlayers = floor(Random() * (MAX_PLAYERS-1))+2;
    G.whoseTurn = floor(Random() * G.numPlayers);
    G.playedCardCount = floor(Random() * MAX_DECK);
    for(int j = 0; j < G.numPlayers; j++){
      G.deckCount[j] = floor(Random() * MAX_DECK *1.2)-1;
      G.discardCount[j] = floor(Random() * MAX_DECK *1.2)-1;
      G.handCount[j] = floor(Random() * MAX_HAND *1.2)-1;
      for(int f = 0; f < G.deckCount[j]; f++){
        G.deck[j][f] = floor(Random() * (treasure_map + 2))-1;
      }
      for(int f = 0; f < G.discardCount[j]; f++){
        G.discard[j][f] = floor(Random() * (treasure_map +2))-1;
      }
      for(int f = 0; f < G.handCount[j]; f++){
        G.hand[j][f] = floor(Random() * (treasure_map +2))-1;
      }
    }
    for(int q = 0; q < G.playedCardCount; q++){
      G.playedCards[q] = floor(Random() * (treasure_map + 2))-1;
    }
    G.outpostPlayed = floor(Random() * 8) - 2;
    G.outpostTurn = floor(Random() * 8) - 2;
    G.phase = floor(Random() * 15) - 2;
    G.numActions = floor(Random() * 6) - 2;
    G.coins = floor(Random() * 55) - 4;
    G.numBuys = floor(Random() * 12) - 2;
    checkPlayMinion(floor(Random() * 4)-1, floor(Random() * 4)-1, &G, G.whoseTurn, floor(Random() *G.handCount[G.whoseTurn]));
  }

return 0;

}
