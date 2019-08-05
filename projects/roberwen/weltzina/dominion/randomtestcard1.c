/*
Author: Alec Weltzin
Date: 7/28/2019
Description: random test for baronEffect functiom found in dominion.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

/*
my own assert statement that doesn't cause halt of entire test.
*/
int assertTrue(int var1, int var2){
  if(var1 != var2){
    printf("FALSE--------------------------------------------------------------\n");
    return 0;
  }else{
    printf("TRUE---------------------------------------------------------------\n");
    return 1;
  }
}


/*
The function that the main function calls to save a copy of gamestate, alter to expected results and check against the actual results of baronEffect function
*/
int checkPlayBaron(int choice1, struct gameState *state, int currentPlayer){
  struct gameState pre;
  memcpy(&pre, state, sizeof(struct gameState));

  int r;
  int card_not_discarded = 1;
  int infinite = 1;
  int bonus = 0;

//Testers assumption of how baronEffect should function. Assumes it does not effect discarding played baron card or reduces actions due to the play. Does not allow infinite loop as was current 7/28/2019
  if(choice1 > 0){
      for(int i = 0; i < pre.handCount[currentPlayer]; i++){
        if(pre.hand[currentPlayer][i] == estate){
          if(pre.hand[currentPlayer][i] == estate && i != 0){
            infinite = 0;
          }
          card_not_discarded = 0;
        }
      }
      if(card_not_discarded){
        if(pre.supplyCount[estate] > 0){
          pre.discard[currentPlayer][pre.discardCount[currentPlayer]] = estate;
          pre.discardCount[currentPlayer]++;
          pre.supplyCount[estate]--;
        }
      }else{
        pre.coins +=4;
      }
  }else{
    if(pre.supplyCount[estate] > 0){
      pre.discard[currentPlayer][pre.discardCount[currentPlayer]] = estate;
      pre.discardCount[currentPlayer]++;
      pre.supplyCount[estate]--;
    }
    infinite = 0;
  }
  pre.numBuys++;
//if infinite loop fixed comment out if condition, leaving what is inside. Comment out ALL of else
//  if(!infinite){

  int handPos = floor(Random() * (state->handCount[currentPlayer]));

    r = playBaron(baron, choice1, 0, 0, state, handPos, &bonus, currentPlayer);

  /*  if(!assertTrue(memcmp(&pre, state, sizeof(struct gameState)), 0) || r != 0){
        printf("Estate SupplyCount = %d, expected %d\n", state->supplyCount[estate], pre.supplyCount[estate]);
        printf("DiscardCount = %d, expected %d\n", state->discardCount[state->whoseTurn], pre.discardCount[currentPlayer]);
        printf("Coins = %d, expected %d\n", state->coins, pre.coins);
        printf("Buys = %d, expected %d\n", state->numBuys, pre.numBuys);
    }
/*  }else{
    printf("FALSE--------------------------------------------------------------\nInfinite Loop----------------------------------------------------------------------------------\n");
  }*/

  return 0;

}

/*
Main function that sets random gameStae(within certain parameters) and checks the baronEffect method of dominion.c for each random gamestate.
*/
int main(){

  int currentPlayer;
  int choice1;
  int r;
  int playerCount;

  struct gameState G;

  SelectStream(2);
  PutSeed(3);
//Tests n times. sets random gamestate and calls checkPlayBaron
  for(int n = 0; n < 150; n++){
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
    checkPlayBaron(floor(Random()*4)-1, &G, G.whoseTurn);
  }

return 0;

}
