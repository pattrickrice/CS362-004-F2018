#include "dominion.h"
#include "utils.h"
#include "dominion_helpers.h"

int testSmithy();

int main() {
    srand((unsigned int) time(0));

    logV("[Starting cardtest1] - Testing the smithy card in Dominion.c");
    int testsPassed = testSmithy();
    logV("[cardtest1 RESULTS] ---------------------------------------------");
    printResults(1, testsPassed);
    logV("[Ending cardtest1] - Testing the smithy cardin Dominion.c\n\n");
    return 0;
}

/******************************************************************************
 * Test the smithy card through the card effect function. The card effect
 * should return the desired return code and the smithy card should alter the
 * state of the game.
 *****************************************************************************/
int testSmithy() {
    int totalTests = 0;
    int passedTests = 0;



    int range = 1000;
    for (int i = 0; i < range; i++) {
        struct gameState *state = newGame();

        // initalize variables needed for the card effect function
        int card = smithy;
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
        int handPos = 0;
        int player = 0;
        int *bonus = malloc(sizeof(int));
        *bonus = 0;
        int correct_number_of_cards = 0;
        int correct_handsize = 0;
        int buffer_size = 100;


        char *buffer = malloc(buffer_size * sizeof(char));
        memset(buffer, 0, (size_t) buffer_size);

        // random test data
        player = random_number(0, 4);
        correct_handsize = random_number(0, 50);
        correct_number_of_cards = correct_handsize + 3;
        state->deckCount[player] = random_number(0, MAX_DECK);


        logV(buffer);

        state->whoseTurn = player;
        // make the current card being played the smithy
        state->hand[player][handPos] = smithy;
        state->handCount[player] = correct_handsize;
        state->playedCardCount = 0;

        // assume the handcount from our set up is correct
        totalTests++;
        sprintf(buffer, "{before} Player Hand count is %d", correct_handsize);

        passedTests += assertEqual(
                state->handCount[player],
                correct_handsize,
                buffer);

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
        sprintf(buffer, "{after} Player Hand count is %d", correct_number_of_cards);
        passedTests += assertEqual(
                state->handCount[player],
                correct_number_of_cards,
                buffer);
        free(buffer);
        free(bonus);
    }

    return printResults(totalTests, passedTests);
}



/*
int cardSmithy(int handPos, int currentPlayer, struct gameState *state){
    // +3 Cards
    int index = 0;
    for (index = 0; index < 4; index++) {
        drawCard(currentPlayer, state);
    }

    // discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}*/
