#include "utils.h"

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
        char buffer[size + resultSize];
        sprintf(buffer, "%s - %s", "[FAILED]", testName);
        logE(buffer);
        return 0;
    } else
    {
        size_t resultSize = strlen(" - [PASSED]");
        char buffer[size + resultSize];
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
    char *timeStamp;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeStamp = asctime(timeinfo);

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
