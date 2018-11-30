/*
 *  csvfold.c, version 001, 05-september-2016
 *
 *  fold a set of lines into CSV compatible format
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 8192

char *progname;

/************************************************************/

void removenewline(s)
  char *s;
{
  int   lens;

  lens = strlen(s);

  if (lens > 0) {
    if (s[lens - 1] == '\n') {
      s[lens - 1] = '\0';
    }
  }

  return;
}

/************************************************************/

int main(argc, argv)
  int   argc;
  char *argv[];
{
  int   fieldcount;
  int   linecount;
  char  line[MAX_LINE_LENGTH];
  int   i;
  char  c;

  if (argc >= 2) {
    fieldcount = atoi(argv[1]);
  } else {
    fieldcount = 2;
  }

  linecount = 0;

  while (fgets(line, MAX_LINE_LENGTH - 1, stdin) != NULL) {
    linecount++; 

    removenewline(line);

    putchar('"');

    for (i = 0; i < strlen(line); i++) {
      c = line[i];

      if (c == '"') {
        printf("\"\"");
      } else {
        putchar(c);
      }
    }

    putchar('"');

    if ((linecount % fieldcount) == 0) {
      putchar('\n');
    } else {
      putchar(',');
    }
  }

  return(0);
}
