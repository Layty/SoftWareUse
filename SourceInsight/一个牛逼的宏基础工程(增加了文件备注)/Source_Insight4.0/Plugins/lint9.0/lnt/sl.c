/*lint

    Standard Library Definitions -- Generic Version

    With this variation of the standard library description,
    library headers are assumed to NOT contain prototypes.
    (If your compiler supports prototypes use a file similar
    to those having names of the form: sl-xxx.lnt).

    This file contains declarations of standard library functions
    for use with PC-Lint.  When provided to PC-Lint along with
    other modules, the functions declared here are considered
    defined with the properties given.

    This file may not be complete.  Your compiler may contain
    many other functions not declared here.
    You may modify or augment this file so that it more
    closely conforms to the library provided with your compiler.

    The include file "stdio.h" is provided with your compiler.

 */


/*lint -e746  don't insist on a prototype for each call */

/*lint -save  save the current error suppression state */
/*lint -library  library flag -- Don't get upset if these externals
              are not referenced or defined */


#include "stdio.h"

typedef char *UNIV;     /* universal pointer */
typedef char *STRING;   /* string */
typedef const char *CSTRING;   /* constant string */

#define VOID void       /* compiler-independent void */
typedef FILE *STREAM;   /* a universal file designator */


/*lint +fvr
  The following functions exhibit variable return modes.
  That is, they may equally-usefully be called for a value
  as called just for their effects.
 */


int     close(int);
int     creat( CSTRING, int );
int     fclose(STREAM);
int     fputc( int, STREAM );
int     fputs( STRING, STREAM );
int     fseek( STREAM, long, int );
int     fwrite( UNIV, int, int, STREAM );
long    lseek( int, long, int );
int     puts( STRING );
STRING  strcat( STRING, STRING );
STRING  strcpy( STRING, STRING );
STRING  strncat( STRING, STRING, int);
STRING  strncpy( STRING, STRING, int);
int     unlink( STRING );
int     write( int, UNIV, int);

/*lint +fva1  arguments vary after the first */
int     printf(STRING);
int     scanf(STRING);
/*lint +fva2  arguments vary after the second */
int     fprintf(STREAM, CSTRING);
int     fscanf(STREAM, STRING);
int     sprintf(STRING, STRING);
int     sscanf(STRING, STRING);
/*lint -fva  end of varying arguments */




double  atof(STRING);
/* atoi returns long in some libraries and int in others;
   In the latter case, atol is also supplied.
   Choose the one correct for your system.
long    atoi(STRING);
int     atoi(STRING);
long    atol(STRING);
 */
UNIV    calloc(unsigned, unsigned);
VOID    exit(int);
int     fgetc(STREAM);
STRING  fgets( STRING, int, STREAM );
STREAM  fopen( STRING, STRING );
int     fread( UNIV, int, int, STREAM );
VOID    free(UNIV);
long    ftell( STREAM );
STRING  gets( UNIV );
int     isalnum(char);
int     isalpha(char);
int     isascii(char);
int     isdigit(char);
int     islower(char);
int     isprint(char);
int     isspace(char);
int     isupper(char);
VOID    main( int, char**);
UNIV    malloc(unsigned);
int     open( STRING, int );
int     read( int, UNIV, int );
int     strcmp( STRING, STRING );
int     strlen( STRING );
int     strncmp( STRING, STRING, int );
int     tolower(char);
int     toupper(char);

/*  Math functions; if you need them, #define math 1  */

#define math 0
#if math
double  acos(double);
double  asin(double);
double  atan(double);
double  ceil(double);
double  cos(double);
double  exp(double);
double  exp10(double);
double  fabs(double);
double  floor(double);
double  log(double);
double  log10(double);
double  pow(double, double);
double  sin(double);
double  sqrt(double);
double  tan(double);
#endif


/*lint -restore Restore error messages to state last "-save"d
       This option is only necessary if flags of the form
       -e... appear after the -save above and to inhibit their
       propogation to later files */

