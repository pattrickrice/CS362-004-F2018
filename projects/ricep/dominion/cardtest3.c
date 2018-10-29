#include "utils.h"
#include "dominion.h"

int testCouncilRoom();

/******************************************************************************
 * UnitTest for the council room card function
 *****************************************************************************/
int main()
{
    logV("[Starting cardtest3] - Testing the council room card in Dominion.c");
    int testsPassed = testCouncilRoom();
    logV("[cardtest3 RESULTS] ---------------------------------------------");
    printResults(1, testsPassed);
    logV("[Ending cardtest3] - Testing the council room card in Dominion.c\n\n");
}

/******************************************************************************
 * Test the council room card through the card effect function. The card effect
 * should return the desired return code and the smithy card should alter the
 * state of the game.
 *****************************************************************************/
int testCouncilRoom()
{
    int totalTests = 0;
    int passedTests = 0;

    // initalize variables needed for the card effect function
    int card = council_room;
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
    state->hand[player][handPos] = council_room;
    state->handCount[player]++;
    state->numBuys = 0;
    state->numPlayers = 4;
    state->deckCount[player] = MAX_DECK;
    state->deckCount[player + 1] = MAX_DECK;
    state->deckCount[player + 2] = MAX_DECK;
    state->deckCount[player + 3] = MAX_DECK;


    // assume the handcount from our set up is correct
    totalTests++;
    passedTests += assertTrue((state->handCount[player] == 1), "Player Hand count is 1");

    // test the function for the correct return code
    totalTests++;
    passedTests += assertEqual(state->numBuys, 0, "State numbuy is 0 before card");

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
    passedTests += assertEqual(state->numBuys, 1, "State numbuy is 1 after card");

    totalTests++;
    passedTests += assertEqual(state->handCount[player], 4, "Player Hand count is 0");

    totalTests++;
    passedTests += assertEqual(state->handCount[player + 1], 1, "Player2 Hand count is 1");

    totalTests++;
    passedTests += assertEqual(state->handCount[player + 2], 1, "Player3 Hand count is 1");

    totalTests++;
    passedTests += assertEqual(state->handCount[player + 3], 1, "Player4 Hand count is 1");
    return printResults(totalTests, passedTests);
}