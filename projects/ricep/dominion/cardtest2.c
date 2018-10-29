#include "utils.h"
#include "dominion.h"

int testDraw2Copper();
int testDraw2Silver();
int testDraw2Gold();
int testCorrectHandCount();


/******************************************************************************
 * UnitTest for the smithy card function
 *****************************************************************************/
int main()
{
    logV("[Starting cardtest2] - Testing the adventurer card in Dominion.c");
    int testsPassed = testDraw2Copper();
    testsPassed += testDraw2Silver();
    testsPassed += testDraw2Gold();
    testsPassed += testCorrectHandCount();

    logV("[cardtest2 RESULTS] ---------------------------------------------");
    printResults(4, testsPassed);
    logV("[Ending cardtest2] - Testing the adventurer card in Dominion.c\n\n");
}

/******************************************************************************
 * Test the adventurer card through the card effect function. The card effect
 * should return the desired return code and the smithy card should alter the
 * state of the game.
 *****************************************************************************/
int testDraw2Copper()
{
    int totalTests = 0;
    int passedTests = 0;

    // initalize variables needed for the card effect function
    int card = adventurer;
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
    state->hand[player][handPos] = card;
    state->handCount[player]++;
    state->deckCount[player] = MAX_DECK;

    state->deck[player][1] = copper;
    state->deck[player][2] = copper;

    // assume the handcount from our set up is correct
    totalTests++;
    passedTests += assertTrue((state->handCount[player] == 1), "Player Hand count is 1");

    // test the function for the correct return code
    totalTests++;
    passedTests += assertTrue(
            cardEffect(card,
                       choice1,
                       choice2,
                       choice3,
                       state,
                       handPos,
                       bonus) == 0,
            "cardEffect returns correct return code of 0");

    // check the state of the game is altered.
    totalTests++;
    passedTests += assertEqual(
            state->hand[player][state->handCount[player] - 1], copper,
            "Top Card is Copper");

    totalTests++;
    passedTests += assertEqual(
            state->hand[player][state->handCount[player] - 2], copper,
            "Top Card is Copper");
    free(state);
    return printResults(totalTests, passedTests);
}

int testDraw2Silver()
{
    int totalTests = 0;
    int passedTests = 0;

    // initalize variables needed for the card effect function
    int card = adventurer;
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
    state->hand[player][handPos] = card;
    state->handCount[player]++;
    state->deckCount[player] = MAX_DECK;

    state->deck[player][1] = silver;
    state->deck[player][2] = silver;

    // assume the handcount from our set up is correct
    totalTests++;
    passedTests += assertTrue((state->handCount[player] == 1), "Player Hand count is 1");

    // test the function for the correct return code
    totalTests++;
    passedTests += assertTrue(
            cardEffect(card,
                       choice1,
                       choice2,
                       choice3,
                       state,
                       handPos,
                       bonus) == 0,
            "cardEffect returns correct return code of 0");

    // check the state of the game is altered.
    totalTests++;
    passedTests += assertEqual(
            state->hand[player][state->handCount[player] - 1], silver,
            "Top Card is silver");

    totalTests++;
    passedTests += assertEqual(
            state->hand[player][state->handCount[player] - 2], silver,
            "Top Card is silver");

    free(state);

    return printResults(totalTests, passedTests);
}

int testDraw2Gold()
{
    int totalTests = 0;
    int passedTests = 0;

    // initalize variables needed for the card effect function
    int card = adventurer;
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
    state->hand[player][handPos] = card;
    state->handCount[player]++;
    state->deckCount[player] = MAX_DECK;

    state->deck[player][1] = gold;
    state->deck[player][2] = gold;

    // assume the handcount from our set up is correct
    totalTests++;
    passedTests += assertTrue((state->handCount[player] == 1), "Player Hand count is 1");

    // test the function for the correct return code
    totalTests++;
    passedTests += assertTrue(
            cardEffect(card,
                       choice1,
                       choice2,
                       choice3,
                       state,
                       handPos,
                       bonus) == 0,
            "cardEffect returns correct return code of 0");

    // check the state of the game is altered.
    totalTests++;
    passedTests += assertEqual(
            state->hand[player][state->handCount[player] - 1], gold,
            "Top Card is silver");

    totalTests++;
    passedTests += assertEqual(
            state->hand[player][state->handCount[player] - 2], gold,
            "Top Card is silver");
    free(state);
    return printResults(totalTests, passedTests);
}

int testCorrectHandCount()
{
    int totalTests = 0;
    int passedTests = 0;

    // initalize variables needed for the card effect function
    int card = adventurer;
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
    state->hand[player][handPos] = card;
    state->handCount[player]++;
    state->deckCount[player] = MAX_DECK;

    state->deck[player][1] = 0;
    state->deck[player][2] = 0;
    state->deck[player][4] = gold;
    state->deck[player][5] = gold;

    // assume the handcount from our set up is correct
    totalTests++;
    passedTests += assertTrue((state->handCount[player] == 1), "Player Hand count is 1");

    // test the function for the correct return code
    totalTests++;
    passedTests += assertTrue(
            cardEffect(card,
                       choice1,
                       choice2,
                       choice3,
                       state,
                       handPos,
                       bonus) == 0,
            "cardEffect returns correct return code of 0");

    // check the state of the game is altered.
    totalTests++;
    passedTests += assertEqual(
            state->handCount[player], 2,
            "Player should only have 2 cards (the treasure cards drawn)");

    free(state);
    return printResults(totalTests, passedTests);
}
