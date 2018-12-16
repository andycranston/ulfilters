/*
 *  linefold.c, version 002, 30-november-2018
 *
 *  fold lines from stdin into fewer lines
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 8192

#define DEFAULT_DELIMITER ' '
#define DEFAULT_FOLD_COUNT 2

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
  char  delim;
  int   foldcount;
  int   i;
  char *arg;
  int   linecount;
  char  line[MAX_LINE_LENGTH];

  delim = DEFAULT_DELIMITER;
  foldcount = DEFAULT_FOLD_COUNT;

  i = 1;
  while (i < argc) {
    arg = argv[i];

    i++;

    if (strcmp(arg, "-d") == 0) {
      if (i >= argc) {
        break;
      }

      arg = argv[i];

      delim = arg[0];
 
      if (delim == '\0') {
        delim = DEFAULT_DELIMITER;
      }

      i++;
    } else if (strcmp(arg, "-n") == 0) {
      if (i >= argc) {
        break;
      }

      arg = argv[i];

      foldcount = atoi(arg);
 
      if (foldcount < 1) {
        foldcount = DEFAULT_FOLD_COUNT;
      }

      i++;
    } else {
      /* ignore unrecognised arguments */
      ;
    }
  }
    
  linecount = 0;

  while (fgets(line, MAX_LINE_LENGTH - 1, stdin) != NULL) {
    linecount++; 

    removenewline(line);

    if (linecount > 1) {
      putchar(delim);
    }

    printf("%s", line);

    if (linecount == foldcount) {
      putchar('\n');

      linecount = 0;
    }
  }

  if (linecount != 0) {
    putchar('\n');
  }

  return(0);
}
