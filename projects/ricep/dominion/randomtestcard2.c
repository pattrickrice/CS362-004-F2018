#include "dominion.h"
#include "utils.h"
#include "dominion_helpers.h"

int testCouncilRoom();

int main() {
    srand((unsigned int) time(0));

    logV("[Starting cardtest2] - Testing the council room card in Dominion.c");
    int testsPassed = testCouncilRoom();
    logV("[cardtest2 RESULTS] ---------------------------------------------");
    printResults(1, testsPassed);
    logV("[Ending cardtest2] - Testing the council room  cardin Dominion.c\n\n");
    return 0;
}

/******************************************************************************
 * Test the council room card through the card effect function. The card effect
 * should return the desired return code and the smithy card should alter the
 * state of the game.
 *****************************************************************************/
int testCouncilRoom() {
    int totalTests = 0;
    int passedTests = 0;



    int range = 1000;
    int numPlayer = 2;
    int seed = 1;

    int k[10] = {adventurer, council_room, feast, gardens, mine
            , remodel, smithy, village, baron, great_hall};

    for (int i = 0; i < range; i++) {
        struct gameState state = *newGame();

        initializeGame(numPlayer, k, seed, &state); // initialize a new game

        // initalize variables needed for the card effect function
        int card = council_room;
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
        int number_of_buys = 0;
        int player_1_deckcount = 0;
        int player_2_deckcount = 0;


        char *buffer = malloc(buffer_size * sizeof(char));
        memset(buffer, 0, (size_t) buffer_size);

        printf("\n");
        sprintf(buffer, "Test number: %d", i + 1);
        logV(buffer);

        // random test data
        player = random_number(0, 4);
        correct_handsize = random_number(0, 50);
        correct_number_of_cards = correct_handsize + 3;
        number_of_buys = random_number(0, range);
        player_1_deckcount = random_number(4, MAX_DECK);
        player_2_deckcount = random_number(4, MAX_DECK);

        state.deckCount[player] = player_1_deckcount;
        state.deckCount[player+1] = player_2_deckcount;

        sprintf(buffer, "Player Deck count is %d", state.deckCount[player]);
        logV(buffer);

        sprintf(buffer, "numPlayers is %d", state.numPlayers);
        logV(buffer);

        sprintf(buffer,
                "Player 2 deck count is %d",
                state.deckCount[player+1]);
        logV(buffer);

        state.whoseTurn = player;
        // make the current card being played the smithy
        state.hand[player][handPos] = smithy;
        state.handCount[player] = correct_handsize;
        state.playedCardCount = 0;

        state.handCount[player+1] = correct_handsize;
        totalTests++;
        sprintf(buffer, "{before} Player 2 Hand count is %d", correct_handsize);

        passedTests += assertEqual(
                state.handCount[player+1],
                correct_handsize,
                buffer);

        state.numBuys = number_of_buys;
        totalTests++;
        sprintf(buffer,
                "{before} Player num buys count is %d",
                correct_handsize);

        passedTests += assertEqual(
                state.numBuys,
                number_of_buys,
                buffer);

        // assume the handcount from our set up is correct
        totalTests++;
        sprintf(buffer, "{before} Player Hand 1 count is %d", correct_handsize);

        passedTests += assertEqual(
                state.handCount[player],
                correct_handsize,
                buffer);

        // test the function for the correct return code
        totalTests++;
        passedTests += assertEqual(
                cardEffect(card,
                           choice1,
                           choice2,
                           choice3,
                           &state,
                           handPos,
                           bonus),
                0,
                "cardEffect returns correct return code of 0");

        // check the state of the game is altered.
        totalTests++;
        sprintf(buffer, "{after} Player Hand count is %d", correct_number_of_cards);
        passedTests += assertEqual(
                state.handCount[player],
                correct_number_of_cards,
                buffer);

        totalTests++;
        sprintf(buffer,
                "{after} Player 1 Hand count is %d",
                correct_number_of_cards);
        passedTests += assertEqual(
                state.handCount[player],
                correct_number_of_cards,
                buffer);

        totalTests++;
        sprintf(buffer,
                "{after} Player 2 Hand count is %d",
                correct_handsize + 1);
        passedTests += assertEqual(
                state.handCount[player+1],
                correct_handsize + 1,
                buffer);

        totalTests++;
        sprintf(buffer,
                "{after} Player 1 deckCount is %d",
                player_1_deckcount - 4);
        passedTests += assertEqual(
                state.deckCount[player],
                player_1_deckcount - 4,
                buffer);

        totalTests++;
        sprintf(buffer,
                "{after} Player 2 deckCount is %d",
                player_2_deckcount - 1);
        passedTests += assertEqual(
                state.deckCount[player+1],
                player_2_deckcount - 1,
                buffer);

        totalTests++;
        sprintf(buffer,
                "{after} Player num buys count is %d",
                number_of_buys + 1);

        passedTests += assertEqual(
                state.numBuys,
                number_of_buys + 1,
                buffer);

        free(buffer);
        free(bonus);
    }

    return printResults(totalTests, passedTests);
}


