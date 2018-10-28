#include "utils.h"
#include "dominion.h"

int testPlayerTurn();

/******************************************************************************
 * UnitTest for the smithy card function
 *****************************************************************************/
int main(){
    logV("[Starting cardtest1] - Testing the smithy card in Dominion.c");
    int testsPassed = testPlayerTurn();
    logV("[cardtest1 RESULTS] ---------------------------------------------");
    printResults(1, testsPassed);
    logV("[Ending cardtest1] - Testing the smithy cardin Dominion.c\n\n");
}

/******************************************************************************
 * Loop though maximum recommended number of players for the game, and check
 * that the function returns that it is their turn.
 *****************************************************************************/
int testPlayerTurn(){
    return 0;
}