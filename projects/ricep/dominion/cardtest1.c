#include "utils.h"
#include "dominion.h"

int testSmithy();

/******************************************************************************
 * UnitTest for the smithy card function
 *****************************************************************************/
int main()
{
    logV("[Starting cardtest1] - Testing the smithy card in Dominion.c");
    int testsPassed = testSmithy();
    logV("[cardtest1 RESULTS] ---------------------------------------------");
    printResults(1, testsPassed);
    logV("[Ending cardtest1] - Testing the smithy cardin Dominion.c\n\n");
}

/******************************************************************************
 * Test the smithy card through the card effect function. The card effect
 * should return the desired return code and the smithy card should alter the
 * state of the game.
 *****************************************************************************/
int testSmithy()
{
    int totalTests = 0;
    int passedTests = 0;

    // initalize variables needed for the card effect function
    int card = smithy;
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
    state->hand[player][handPos] = smithy;
    state->handCount[player]++;
    state->deckCount[player] = MAX_DECK;

    // assume the handcount from our set up is correct
    totalTests++;
    passedTests += assertTrue((state->handCount[player] == 1), "Player Hand count is 1");

    // test the function for the correct return code
    totalTests++;
    passedTests += assertEqual(
            cardEffect(card,
                       choice1,
                       choice2,
                       choice3,
                       state,
                       handPos,
                       bonus),
            0,
            "cardEffect returns correct return code of 0");

    // check the state of the game is altered.
    totalTests++;
    passedTests += assertEqual(state->handCount[player], 2, "Player Hand count is 2");

    return printResults(totalTests, passedTests);
}