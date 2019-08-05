/*
Author: Alec Weltzin
Date: 7/28/2019
Description: random test for tributeEffect functiom found in dominion.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

//My own version of assert function that doesn't cause test halt.
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
function called by main random test function to take copy of random state, alter to expected results, and check against actual tributeEffect results.
*/
int checkPlayTribute(int currentPlayer, int nextPlayer, struct gameState *state){
  struct gameState pre;
  memcpy(&pre, state, sizeof(struct gameState));

  int players[pre.numPlayers];
  int r;
  int tributeRevealedCards[2] = {-1,-1};
  int bonus = 0;

  for(int i = 0; i < 2; i++){
    if(pre.deckCount[nextPlayer] <= 0){
      for(int k = 0; k < pre.discardCount[nextPlayer]; k++){
        pre.deck[nextPlayer][k] = pre.discard[nextPlayer][k];//Move to deck
        pre.deckCount[nextPlayer]++;
        pre.discard[nextPlayer][k] = -1;
        pre.discardCount[nextPlayer]--;
      }
      shuffle(nextPlayer, state);
    }
    if(pre.discardCount[nextPlayer] > 0){
      pre.discard[nextPlayer][pre.discardCount[nextPlayer]] = pre.deck[nextPlayer][pre.deckCount[nextPlayer]-1];
      tributeRevealedCards[i] = pre.deck[nextPlayer][pre.deckCount[nextPlayer]-1];
      pre.discardCount[nextPlayer]++;
      pre.deckCount[nextPlayer]--;
    }
  }

  if(tributeRevealedCards[0] == tributeRevealedCards[1]){
    tributeRevealedCards[1] = -1;
  }

  for (int i = 0; i < 2; i ++){
    if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
      pre.coins += 2;
    }

    else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
      drawCard(currentPlayer, &pre);
      drawCard(currentPlayer, &pre);
    }
    else if(tributeRevealedCards[i] >= curse || tributeRevealedCards[i] <= treasure_map){//Action Card
      pre.numActions = pre.numActions + 2;
    }
  }


    int handPos = floor(Random() * testG.handCount[currentPlayer]);

  r = playTribute(tribute, 0, 0, 0, &testG, handPos, &bonus, currentPlayer, state->whoseTurn+1);

  if(!assertTrue(memcmp(&pre, state, sizeof(struct gameState)), 0)){
    printf("DiscardCount = %d, expected %d\n", state->discardCount[currentPlayer], pre.discardCount[currentPlayer]);
    printf("Hand Count = %d, expected %d\n", state->handCount[currentPlayer], pre.handCount[currentPlayer]);
    printf("Deck Count = %d, expected %d\n", state->deckCount[currentPlayer], pre.deckCount[currentPlayer]);
    printf("coins = %d, expected %d\n", state->coins, pre.coins);
    printf("actions = %d, expected %d\n", state->numActions, pre.numActions);

    printf("Next player discard = %d, expected %d\n", state->discardCount[state->whoseTurn + 1], pre.discardCount[pre.whoseTurn +1]);
    printf("Next player deck = %d, expected %d\n", state->deckCount[state->whoseTurn + 1], pre.deckCount[pre.whoseTurn +1]);
    printf("Next player hand = %d, expected %d\n\n\n\n", state->handCount[state->whoseTurn + 1], pre.handCount[pre.whoseTurn +1]);
  }
  return 0;

}

/*
Main function that sets random gameState(within certain parameters) and checks the tributeEffect method of dominion.c for each random gamestate
*/
int main(){

  int currentPlayer;
  int choice1;
  int r;
  int playerCount;

  struct gameState G;

  SelectStream(2);
  PutSeed(3);

  for(int n = 0; n < 3550; n++){
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
    checkPlayTribute(G.whoseTurn, G.whoseTurn+1, &G);
  }

return 0;

}
