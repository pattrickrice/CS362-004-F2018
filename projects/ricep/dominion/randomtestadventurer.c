#include "dominion.h"
#include "utils.h"
#include "dominion_helpers.h"

int testDrawTreasure();
int isTreasure(int card);


/******************************************************************************
 * UnitTest for the adventurer card function
 *****************************************************************************/
int main()
{
    logV("[Starting cardtest3] - Testing the adventurer card in Dominion.c");
    int testsPassed = testDrawTreasure();

    logV("[cardtest3 RESULTS] ---------------------------------------------");
    printResults(2, testsPassed);
    logV("[Ending cardtest3] - Testing the adventurer card in Dominion.c\n\n");
}

int random_treasure(){
    int number = random_number(0, 3);
    if (number % 3 == 0) {
        return copper;
    } else if (number % 2 == 0){
        return silver;
    } else {
        return gold;
    }
}
int testDrawTreasure()
{
    int totalTests = 0;
    int passedTests = 0;
    int range = 1000000;

    for(int i=0; i < range; i++) {
        int buffer_size = 100;
        char *buffer = malloc(buffer_size * sizeof(char));

        printf("\n");
        sprintf(buffer, "test number: %d", i);
        logV(buffer);
        // initalize variables needed for the card effect function
        int card = adventurer;
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
        int numPlayer = 2;
        int starting_handcount = random_number(6, MAX_HAND);
        int ending_handcount = starting_handcount + 2;

        int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
        struct gameState state = *newGame();
        int seed = random_number(1, 10);

        initializeGame(numPlayer, k, seed, &state); // initialize a new game

        int handPos = 0;
        int *bonus = malloc(sizeof(int));
        *bonus = 0;
        int player = 0;

        // make the current card being played the smithy
        state.whoseTurn = player;
        state.hand[player][handPos] = card;

        int random_pos = random_number(2, MAX_DECK);
        state.deck[player][random_pos] = random_treasure();
        state.deck[player][random_pos+1] = random_treasure();
        state.deckCount[player] = random_number(0, MAX_DECK);
        if (state.deckCount[player] == 0){
            logW("*** This test will seg fault *** "
                 "run make with '-i' for full results past seg fault");
        }
        state.handCount[player] = starting_handcount;

        // assume the handcount from our set up is correct
        totalTests++;
        sprintf(buffer,
                "{before} Player Hand count is %d",
                starting_handcount);
        passedTests += assertEqual(
                (state.handCount[player]),
                starting_handcount,
                buffer);

        // test the function for the correct return code
        totalTests++;
        passedTests += assertTrue(
                cardEffect(card,
                           choice1,
                           choice2,
                           choice3,
                           &state,
                           handPos,
                           bonus) == 0,
                "cardEffect returns correct return code of 0");

        // check the state of the game is altered.
        totalTests++;
        passedTests += assertEqual(
                isTreasure(state.hand[player][state.handCount[player] - 1]),
                1,
                "Top Card is treasure");

        totalTests++;
        passedTests += assertEqual(
                isTreasure(state.hand[player][state.handCount[player] - 2]),
                1,
                "2nd Top Card is treasure");

        // assume the handcount from our set up is correct
        // assume the handcount from our set up is correct
        totalTests++;
        sprintf(buffer,
                "{after} Player Hand count is %d",
                ending_handcount);
        passedTests += assertEqual(
                (state.handCount[player]),
                ending_handcount,
                buffer);
    }
    return printResults(totalTests, passedTests);
}

int isTreasure(int card){
    if (card == copper || card == silver || card == gold){
        return 1;
    }
    return 0;
}
