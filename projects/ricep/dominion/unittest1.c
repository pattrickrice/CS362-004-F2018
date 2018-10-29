#include "utils.h"
#include "dominion.h"

int testPlayerTurn();

/******************************************************************************
 * UnitTest for the whoseTurn function
 *****************************************************************************/
int main(){
    logV("[Starting unittest1] - Testing the whoseTurn Function in Dominion.c");
    int testsPassed = testPlayerTurn();
    logV("[UNITTEST 1 RESULTS] ---------------------------------------------");
    printResults(1, testsPassed);
    logV("[Ending unittest1] - Testing the whoseTurn Function in Dominion.c\n\n");

}

/******************************************************************************
 * Loop though maximum recommended number of players for the game, and check
 * that the function returns that it is their turn.
 *****************************************************************************/
int testPlayerTurn(){
    struct gameState state;
    int totalTests = 0;
    int passedTests = 0;
    for (int i = 0; i < MAX_PLAYERS; i ++){
        char message[100];
        sprintf(message, "Testing that is is player %d's turn", i);
        state.whoseTurn = i;
        totalTests++;
        passedTests += assertTrue((whoseTurn(&state) == i), message);
    }
    return printResults(totalTests, passedTests);
}