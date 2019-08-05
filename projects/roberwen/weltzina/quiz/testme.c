#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
  char alpha[] = "[](){} ax";

  char result = alpha[(rand()%14)];
    // TODO: rewrite this function
    return result;
}

char *inputString()
{
  int length = 6;
  char charset[] = "rest";
  char *randstr;
  randstr = malloc(sizeof(char)*(length));

  for(int n = 0; n < length-1; n++){
    int key = rand() %(int)(sizeof (charset)-1);
    randstr[n] = charset[key];
  }
  randstr[length] = '\0';

  return randstr;
/*
  char *str = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']', 'r', 's', 't', 'e', '9'};
  char str2[5];
  char *result;

    // TODO: rewrite this function
    for(int i = 0; i < 5; i++){
      //str2 = null;
      str2[i] = str[(rand()%15)];
      //result = str2;
    }
    return str2;*/
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
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
