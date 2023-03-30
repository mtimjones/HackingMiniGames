#include "hack.h"

card_t deck[14]={
    { "Denial of Service",   0,  0, 0.192 },
    { "Social Engineering",  0,  1, 0.154 },
    { "Honeypot",            1,  0, 0.154 },
    { "Firewall",           -1,  1, 0.058 },
    { "Connection Lag",      1, -1, 0.058 },
    { "Backtrace",           1,  1, 0.038 },
    { "SQL Injection",      -1, -1, 0.038 },
    { "Stack Overflow",      1,  2, 0.038 },
    { "Fuzzing",             2,  1, 0.038 },
    { "Worm",               -1,  2, 0.038 },
    { "Trojan",              2, -1, 0.038 },
    { "Phishing",            2,  2, 0.038 },
    { "Malware Injection",   2,  3, 0.058 },
    { "Keylogger",           3,  2, 0.058 }
};

int hand[ 3 ];

int pick_a_card( )
{
    float limit = getSRand( );
    float sum = 0.0;
    int   i;

    for ( i = 0 ; i < 14 ; i++ )
    {
        sum += deck[ i ].prob;
        if ( limit < sum ) break;
    }

    return i;
}

void print_card( int i, int card )
{
    printf("\t%1d: %-18s [heat %2d / hack %2d]\n", i, deck[ card ].name, deck[ card ].heat, deck[ card ].hack );
}

void print_stats( int heat, int hack, int moves )
{
    printf("\tMoves |");
    for ( int i = 0 ; i < 8 ; i++ )
    {
       if ( i < (8-moves) ) printf("#");
       else printf(" ");
    }
    printf("|   (%2d)\n", (8-moves ));

    printf("\tHeat  |");
    for ( int i = 0 ; i < 10 ; i++ )
    {
       if ( i < heat ) printf("#");
       else printf(" ");
    }
    printf("| (%2d)\n", heat);

    printf("\tHack  |");
    for ( int i = 0 ; i < 10 ; i++ )
    {
       if ( i < hack ) printf("#");
       else printf(" ");
    }
    printf("| (%2d)\n", hack);

    for ( int i = 0 ; i < 3 ; i++ )
    {
       print_card( i, hand[ i ] );
    }
}

void main( void )
{
    int heat = 0;
    int hack = 0;
    int selection;
    char ch[5];
    int moves = 0;

    seedRand( );

    while ( heat < 10 && hack < 10 && moves < 8)
    {

       hand[ 0 ] = pick_a_card( );
       hand[ 1 ] = pick_a_card( );
       hand[ 2 ] = pick_a_card( );

       print_stats( heat, hack, moves );

       printf("\n\tSelect a card (0, 1, 2):");
       scanf("%s", ch);
       selection = atoi(ch);
       printf("\n");

       heat += deck[ hand[ selection ] ].heat;
       hack += deck[ hand[ selection ] ].hack;

       if ( heat < 0 ) heat = 0;
       if ( hack < 0 ) hack = 0;
       if ( hack > 10 ) hack = 10;
       if ( heat > 10 ) heat = 10;

       moves++;
    }

    print_stats( heat, hack, moves );

    if ( hack == 10 ) 
    {
        printf("You win (score %d).\n", ( hack - heat ) + ( 8 - moves ) );
    }
    else if ( heat == 10 )
    {
        printf("You lose.\n");
    }
    else
    {
        printf("You lose (out of moves).\n");
    }

}

