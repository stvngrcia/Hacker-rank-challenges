#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main -
 * @void: No arguments neededs
 * Description: this function takes a string which represents time
 * in the format HH:MM:SSPM/AM and then converts it into military time.
 */
int main(void){
    char* time = (char *)malloc(10240 * sizeof(char));
    char *token;
    char *hour;
    char *minute;
    char *second;
    char *sec;
    char *t;
    int i;
    int h;

    scanf("%s",time);
    /*parse time and split the string using the ":" */
    token = strtok(time, ":");
    hour = token;
    for (i = 0; token != NULL; i++)
    {
      token = strtok(NULL, ":");
      if (i == 0)
      {
        minute = token;
      }
      else if (i == 1)
      {
        second = token;
      }
    }
    /*parse and split the second using token "P"*/
    second = strtok(second, "P");
    t = second;
    /*storing the actual seconds*/
    sec = second;
    for (i = 0 ; second != NULL; i++)
    {
      second = strtok(NULL, "P");
      /*if second is NULL it means that is am*/
      if (i == 0 && second == NULL)
      {
        t = second;
      }
    }
    /*if pm convert the string to number and print the military time*/
    if (t != NULL)
    {
      /*converting string to number*/
      h = atoi(hour);
      /*checking if is mid day in which case I want it to be 12*/
      if(h != 12)
      {
        h += 12;
      }
    /*printing military time*/
      printf("%d:%s:%s\n", h, minute, sec);
    }
    else
    {
      /*if am just print h m and s*/
      sec = strtok(sec,"A");
      /*checking if is midnight if it is change to 00 */
      if(strcmp(hour, "12") == 0)
      {
        hour = "00";
      }
      printf("%s:%s:%s\n", hour, minute, sec);
    }
    return 0;
}
