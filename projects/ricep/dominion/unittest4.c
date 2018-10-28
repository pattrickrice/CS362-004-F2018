#include "utils.h"
#include "dominion.h"

int testHandCard();

/******************************************************************************
 * UnitTest for the  function
 *****************************************************************************/
int main()
{
    int total = 1, passed = 0;
    logV("[Starting unittest4] - Testing the  Function in Dominion.c");
    passed += testHandCard();

    logV("[RESULTS unittest4] ----------------------------------------------");
    printResults(total, passed);
    logV("[Ending unittest4] - Testing the  Function in Dominion.c\n\n");
}

/******************************************************************************
 * Test that if we set the
 *****************************************************************************/
int testHandCard()
{
    int total = 0, passed = 0;
    struct gameState *state = newGame();

    for (int currentPlayer = 0; currentPlayer < MAX_PLAYERS; currentPlayer++)
    {
        for (int handPos = 0; handPos < MAX_HAND; handPos++)
        {
            char message[100];
            sprintf(message,
                    "Player %d card in position %d is 1",
                    currentPlayer,
                    handPos);
            state->whoseTurn = currentPlayer;
            state->hand[currentPlayer][handPos] = 1;
            total++;
            passed += assertTrue((handCard(handPos, state) == 1), message);

        }
    }
    return printResults(total, passed);
}
