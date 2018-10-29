#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int max_number = 10;
    int minimum_number = 0;
    int random_number = (char) rand() % (max_number + 1 - minimum_number) + minimum_number;
    char *array = "[({ ax})]";
    char chosen = array[random_number];
    return chosen;
}

char *inputString()
{
    int max_number = 5;
    int minimum_number = 0;
    int length = 6;
    char letters[5] = "rste\0";

    char *input = malloc(length * sizeof(char));
    for (int i = 0; i < length; i ++){
        int random_number = (char) rand() % (max_number + 1 - minimum_number) + minimum_number;
        input[i] = letters[random_number];
    }
    return input;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
    free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
