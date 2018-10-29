#include "utils.h"
#include "dominion.h"

int testGardens();

/******************************************************************************
 * UnitTest for the gardens card function
 *****************************************************************************/
int main()
{
    logV("[Starting cardtest4] - Testing the Gardens card in Dominion.c");
    int testsPassed = testGardens();
    logV("[cardtest4 RESULTS] ---------------------------------------------");
    printResults(1, testsPassed);
    logV("[Ending cardtest4] - Testing the Gardens card in Dominion.c\n\n");
}

/******************************************************************************
 * Test the council room card through the card effect function. The card effect
 * should return the desired return code and the smithy card should alter the
 * state of the game.
 *****************************************************************************/
int testGardens()
{
    int totalTests = 0;
    int passedTests = 0;

    // initalize variables needed for the card effect function
    int card = gardens;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    struct gameState *state = newGame();
    int handPos = 0;
    int *bonus = malloc(sizeof(int));
    *bonus = 0;
    int player = 0;

    // make the current card being played the smithy
    state->whoseTurn = player;
    state->hand[player][handPos] = gardens;
    state->handCount[player]++;
    state->deckCount[player] = MAX_DECK;

    // assume the handcount from our set up is correct
    totalTests++;
    passedTests += assertTrue((state->handCount[player] == 1), "Player Hand count is 1");


    totalTests++;
    passedTests += assertEqual(
            cardEffect(card,
                       choice1,
                       choice2,
                       choice3,
                       state,
                       handPos,
                       bonus),
            -1,
            "cardEffect returns correct return code of -1");
    free(state);
    return printResults(totalTests, passedTests);
}