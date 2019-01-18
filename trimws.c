/*
 *  trimws.c, version 001, 18-january-2019
 *
 *  trim leading and trailing white space from each line
 *  of standard input before then sending the line to
 *  standard output
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 8192

/************************************************************/

char *trimws(line)
  char *line;
{
  int   lenline;

  lenline = strlen(line);

  while (lenline > 0) {
    lenline--;

    if isspace(line[lenline]) {
      line[lenline] = '\0';
    } else {
      lenline = 0;
    }
  }

  while (isspace(*line)) {
    line++;
  }

  return line;
}

/************************************************************/

int main(argc, argv)
  int   argc;
  char *argv[];
{
  char  line[MAX_LINE_LENGTH];

  while (fgets(line, MAX_LINE_LENGTH - 1, stdin) != NULL) {
    printf("%s\n", trimws(line));
  }

  return(0);
}
