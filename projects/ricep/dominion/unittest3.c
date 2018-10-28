#include "utils.h"
#include "dominion.h"

int testFullDeckCount();

/******************************************************************************
 * UnitTest for the fullDeckCount function
 *****************************************************************************/
int main()
{
    int total = 1, passed = 0;
    logV("[Starting unittest3] - Testing the fullDeckCount Function in Dominion.c");
    passed += testFullDeckCount();
    logV("[RESULTS unittest3] -----------------------------------------------");
    printResults(total, passed);

    logV("[Ending unittest3] - Testing the fullDeckCount Function in Dominion.c\n\n");
}

/******************************************************************************
 *  Test that the count of a particular card in the deck changes if we add
 *  or subtract them.
 *****************************************************************************/
int testFullDeckCount()
{
    struct gameState *state = newGame();
    int i;
    int player = 0;
    int totalTests = 0, passed = 0;

    int uniqueNumberOfCardsInGame = 28; // different cards that can be played
    state->deckCount[player] = uniqueNumberOfCardsInGame;
    state->handCount[player] = uniqueNumberOfCardsInGame;
    state->discardCount[player] = uniqueNumberOfCardsInGame;

    for (int card = 1; card <= uniqueNumberOfCardsInGame; card++){
        state->deckCount[player] = card;
        state->handCount[player] = card;
        state->discardCount[player] = card;
        int total = 3 * card;
        char message[100];
        sprintf(message, "There are %d cards in the deck", total);
        for (i = 0; i < state->deckCount[player]; i++)
        {
            state->deck[player][i] = card;
        }

        for (i = 0; i < state->handCount[player]; i++)
        {
            state->hand[player][i] = card;
        }

        for (i = 0; i < state->discardCount[player]; i++)
        {
            state->discard[player][i] = card;
        }

        totalTests++;
        passed += assertTrue((fullDeckCount(player, card, state) == total), message);

        // confirm that removing a card from any deck decrements the count
        state->discard[player][0] = -1; // obvious invalid number
        total--;
        sprintf(message, "There are %d cards in the deck", total);
        totalTests++;
        passed += assertTrue((fullDeckCount(player, card, state) == total), message);

        state->deck[player][0] = -1; // obvious invalid number
        total--;
        sprintf(message, "There are %d cards in the deck", total);
        totalTests++;
        passed += assertTrue((fullDeckCount(player, card, state) == total), message);

        state->hand[player][0] = -1; // obvious invalid number
        total--;
        sprintf(message, "There are %d cards in the deck", total);
        totalTests++;
        passed += assertTrue((fullDeckCount(player, card, state) == total), message);
    }
    return printResults(totalTests, passed);
}
