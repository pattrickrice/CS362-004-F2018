#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/******************************************************************************
 * Prints whether the result is true or false along with the test name
 * @param result value we are checking
 * @param testName name of the test.
 *****************************************************************************/
int assertTrue(int result, char testName[])
{
    // false
    size_t size = strlen(testName);
    if (result == 0)
    {
        size_t resultSize = strlen(" - [FAILED]");
        char buffer[size + resultSize + 100];
        sprintf(buffer, "%s - %s", "[FAILED]", testName);
        logE(buffer);
        return 0;
    } else
    {
        size_t resultSize = strlen(" - [PASSED]");
        char buffer[size + resultSize + 100];
        sprintf(buffer, "%s - %s", "[PASSED]", testName);
        logS(buffer);
        return 1;
    }
};

/******************************************************************************
 * Get a string of the current time
 * SOURCE:
 * https://stackoverflow.com/questions/5141960/get-the-current-time-in-c
 *****************************************************************************/
char * timeStamp(){
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char *timeStamp = malloc(100 * sizeof(char));
    strcpy(timeStamp, asctime(timeinfo));

    // remove newline character
    timeStamp[strlen(timeStamp) -1] = '\0';
    return timeStamp;
}

/******************************************************************************
 * Print a verbose message to STDOUT
 * @param message message to be printed
 *****************************************************************************/
void logV(char message[])
{
    char * timeString = timeStamp();
    printf("[%s] %s\n", timeString, message);
    free(timeString);
}

/******************************************************************************
 * Print a success message to STDOUT
 * @param message message to be printed
 *****************************************************************************/
void logS(char message[]){
    char * timeString = timeStamp();
    printf("%s[%s] %s%s\n",
           ANSI_COLOR_GREEN,
           timeString,
           message,
           ANSI_COLOR_RESET);
    free(timeString);

}

/******************************************************************************
 * Print a error message to STDOUT
 * @param message message to be printed
 *****************************************************************************/
void logE(char message[]){
    char * timeString = timeStamp();
    printf("%s[%s] %s%s\n",
           ANSI_COLOR_RED,
           timeString,
           message,
           ANSI_COLOR_RESET);
}

/******************************************************************************
 * Print a warning message to STDOUT
 * @param message message to be printed
 *****************************************************************************/
void logW(char message[]){
    char * timeString = timeStamp();
    printf("%s[%s] %s%s\n",
           ANSI_COLOR_YELLOW,
           timeString,
           message,
           ANSI_COLOR_RESET);
    free(timeString);

}

int printResults(int total, int passed){
    char buffer[100];
    sprintf(buffer, "Total tests %d; total passed %d\n", total, passed);
    assertTrue((total == passed), buffer);
    if (total == passed){
        return 1;
    }
    return 0;
}

int assertEqual(int value1, int value2, char *message){
    char *buffer = malloc((sizeof(message) + 10) + sizeof(int) * 2);
    int result = -1;
    if (value1 == value2){
        result =  assertTrue(1, message);
    } else{
        sprintf(buffer, "%d != %d %s", value1, value2, message);
        result =  assertTrue(0, buffer);
    }
    free(buffer);
    return result;
}

int random_number(int lower, int upper){
    int number = rand() % (upper + 1 - lower) + lower;
    return number;
}

char* random_string(int length){
    char *random_string = malloc(length * sizeof(char));
    for (int i =0; i< length -1; i++){
        random_string[i] = (char) random_number(97, 122);
    }
    random_string[length - 1] = '\0';
    return random_string;
}