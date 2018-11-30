static char *version = "@(!--#) @(#) linesbefore.c, version 001, 28 July 2018";

/*
 * linesbefore.c
 *
 * simple filter that prints all lines before one that matches a string
 *
 */

/********************************************************************/

/*
 *  includes
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/********************************************************************/

/*
 *  defines
 */

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define MAX_LINE_LENGTH 8191

/********************************************************************/

/*
 *  rtrim
 *
 *  trim whitespace fron right hand side of a string
 *
 */

void rtrim(s)
  char *s;
{
  int   lenstring;
  int   c;

  lenstring = strlen(s);

  while (lenstring > 0) {
    lenstring--;

    c = s[lenstring];

    if ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\r')) {
      s[lenstring] = '\0';
    } else {
      break;
    }
  }

  return;
}

/********************************************************************/

/*
 *  main
 */

int main(argc, argv)
  int   argc;
  char *argv[];
{
  char *progname;
  char *pattern;
  char  line[MAX_LINE_LENGTH + sizeof(char)];

  progname = argv[0];

  if (argc < 2) {
    fprintf(stderr, "%s: must specify pattern", progname);
    exit(2);
  }

  pattern = argv[1];

  while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
    rtrim(line);

    if (strstr(line, pattern) != NULL) {
      break;
    }

    printf("%s\n", line);
  }

 exit(0);
}

/* end of file */
