#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
   char *name;
   int  heat;
   int  hack;
   float prob;
} card_t;

#define getSRand( )     ( ( double ) rand( ) / ( double ) RAND_MAX )
#define getRand( x )    ( int ) ( ( x ) * getSRand( ) )
#define seedRand( )     ( srand( time( NULL ) ) )

