#include "utils.h"
#include "dominion.h"

int testNoProvince();
int testThreeSupplyPilesAtZero();
/******************************************************************************
 * UnitTest for the isGameOver function
 *****************************************************************************/
int main(){
    int totalTests = 2;
    int totalPassed = 0;
    logV("[Starting unittest2] - Testing the isGameOver Function in Dominion.c");
    totalPassed += testNoProvince();
    totalPassed += testThreeSupplyPilesAtZero();
    logV("[RESULTS unittest2] ----------------------------------------------");
    printResults(totalTests, totalPassed);
    logV("[Ending unittest2] - Testing the isGameOver Function in Dominion.c\n\n");
}

int testNoProvince(){
    struct gameState *state = newGame();
    state->supplyCount[province] = 1;
    int total = 0;
    int testsPassed = 0;

    // set supply counts to 1
    int i = 0;
    for (i = 0; i < 25; i++)
    {
        state->supplyCount[i] = 1;
    }

    char *message = "All supply piles at 1 returns a 0";
    total++;
    testsPassed += assertTrue((isGameOver(state) == 0), message);

    message = "No provinces left returns a 1";
    state->supplyCount[province] = 0;

    total++;
    testsPassed += assertTrue((isGameOver(state) == 1), message);
    free(state);

    return printResults(total, testsPassed);
}

int testThreeSupplyPilesAtZero(){
    struct gameState *state = newGame();
    int total = 0, testsPassed = 0;
    // set supply counts to 1
    int i = 0;
    for (i = 0; i < 25; i++)
    {
        state->supplyCount[i] = 1;
    }

    char *message = "All supply piles at 1 returns a 0";
    total++;
    testsPassed += assertTrue((isGameOver(state) == 0), message);

    state->supplyCount[0] = 0;
    state->supplyCount[1] = 0;
    state->supplyCount[2] = 0;

    message = "Three supply Piles at 0 returns a 1";

    total++;
    testsPassed += assertTrue((isGameOver(state) == 1), message);
    free(state);
    return printResults(total, testsPassed);

}

