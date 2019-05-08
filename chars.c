/*
 *  @(!--#) @(#) chars.c, version 004, 17-june-1999
 *
 *  Analyse files/stdin and produce a report of the number of
 *  different characters that were encountered
 *
 */

/*
 *  include directives
 */

#include <stdio.h>

/*
 *  define directives
 */

#define OK_RETCODE    0
#define ERROR_RETCODE 1

/*
 *  global declarations
 */

char *prog_name;

/*
 *  function: char_a_file
 *
 *  report on character usage on a file
 *
 */
void char_a_file(file)
  FILE  *file;
{
  /* local declarations */
  int  count[256];
  int  i;
  int  c;
  char ch;

  /* for each array element in count */
  for ( i=0 ; i<=255 ; i++ )
  {
    /* set current element to zero */
    count[i] = 0;
  }

  /* while there are characters in the file */
  while ( (c=getc(file)) != EOF )
  {
    /* increment the relevant array element */
    count[c] = count[c] + 1;
  }

  /* for each array element */
  for ( i=0 ; i<256 ; i++ )
  {
    /* is the count non-zero */
    if ( count[i] > 0 )
    {
      /* yes so output the character code */
      printf("%4d  ", i);

      /* coerce character code to type char */
      ch = (char) i;

      /* is the character printable */
      if ( (i>=32) && (i<=126) )
      {
        /* yes so print it */
        putchar(ch);

        /* and a padding space */
        putchar(' ');
      }
      /* is the character a newline */
      else if ( ch == '\n' )
      {
        /* yes so output \n */
        printf("\\n");
      }
      /* is the character a carriage return */
      else if ( ch == '\r' )
      {
        /* yes so output \r */
        printf("\\r");
      }
      /* is the character a tab */
      else if ( ch == '\t' )
      {
        /* yes so output \t */
        printf("\\t");
      }
      /* is the character a formfeed */
      else if ( ch == '\f' )
      {
        /* yes so output \f */
        printf("\\f");
      }
      else
      {
        /* so so output two spaces */
        printf("  ");
      }
      /* output the count */
      printf(" %d\n", count[i]);
    }
  }

  /* return */
  return;
}

/*
 *  function: main
 *
 *
 */

int main(argc, argv)
  int   argc;
  char *argv[];
{
  /* local declarations */
  int   ret_code;
  int   arg;
  char *file_name;
  FILE *file;

  /* set program name */
  prog_name = argv[0];

  /* assume all will be hunky dory */
  ret_code = OK_RETCODE;

  /* are there any file name arguments */
  if ( argc <= 1 )
  {
    /* no, so char stdin */
    char_a_file(stdin);
  }
  else
  {
    /* no, there are file arguments to process */
    for ( arg=1 ; arg<argc ; arg++ )
    {
      /* set the file name */
      file_name = argv[arg];

      /* is there more than one file */
      if ( argc >= 3 )
      {
        /* yes, identify this file from the others */
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("%s: file \"%s\"\n", prog_name, file_name);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      }

      /* can the file be opended for reading */
      if ( (file = fopen(file_name, "r")) == NULL )
      {
        /* no, so error message */
        fprintf(stderr, "%s: cannot find/access file \"%s\" for reading\n", prog_name, file_name);

        /* make return code indicate an error occurred */
        ret_code = ERROR_RETCODE;
      }
      else
      {
        /* file opened OK, process it */
        char_a_file(file);

        /* and close it */
        fclose(file);
      }
    }
  }

  /* return the return code */
  return(ret_code);
}
