#ifndef DOMINION_UTILS_H
#define DOMINION_UTILS_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// Define console colors
// SOURCE: https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int assertTrue(int result, char testName[]);
int assertEqual(int value1, int value2, char *message);
void logV(char message[]);
void logS(char message[]);
void logE(char message[]);
void logW(char message[]);
int printResults(int total, int passed);
char* random_string(int length);
int random_number(int lower, int upper);


#endif