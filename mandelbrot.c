/**
 @file mandelbrot.c
 @author John Poulos (jnpoulos)
 
 This progam generates a Mandelbrot fractal based on user
 given paremeters.
 */

#include <stdio.h>
#include <stdlib.h>

/** Dwell cut-off for drawing with ' ' */
#define LEVEL_1 10

/** Dwell cut-off for drawing with '.' */
#define LEVEL_2 20

/** Dwell cut-off for drawing with ':' */
#define LEVEL_3 30

/** Dwell cut-off for drawing with '-' */
#define LEVEL_4 40

/** Dwell cut-off for drawing with '=' */
#define LEVEL_5 50

/** Dwell cut-off for drawing with '+' */
#define LEVEL_6 60

/** Dwell cut-off for drawing with '*' */
#define LEVEL_7 70

/** Dwell cut-off for drawing with '#' */
#define LEVEL_8 80

/** Dwell cut-off for drawing with '%' */
#define LEVEL_9 90

/** Width of the mandelbrot set */
#define WIDTH 70

/** Height of the mandelbrot set */
#define HEIGHT 35

/** Maximum magnitude */
#define MAX_MAG 4

/**
 Given a complex number this function calculates
 the dwell for each point of the set.

 @param cReal real part of the complex number
 @param cImag imaginary part of the complex number
 */
int testPoint( double cReal, double cImag )
{
    double zReal = cReal;
    double zImag = cImag;
    int dwell = 0;
    
    while ( dwell < LEVEL_9 ) {
        double tempReal = ( zReal * zReal ) - ( zImag * zImag ) + cReal;
        double tempImag = 2 * zReal * zImag + cImag;
        zReal = tempReal;
        zImag = tempImag;
        if ( ( zReal * zReal + zImag * zImag ) > MAX_MAG ){
            break;
        }
        dwell = dwell + 1;
    }
    return dwell;
}

/**
 This function accepts the value of a dwell and returns the
 appropriate char for that dwell value.
 
 @param dwell value to decide which char is returned
 
 @return char symbol for the appropriate dwell value
 */
char dwellSymbol( int dwell )
{
    if ( dwell < LEVEL_1 ){
        return ' ';
    } else if ( dwell < LEVEL_2 ){
        return '.';
    } else if ( dwell < LEVEL_3 ){
        return ':';
    } else if ( dwell < LEVEL_4 ){
        return '-';
    } else if ( dwell < LEVEL_5 ){
        return '=';
    } else if ( dwell < LEVEL_6 ){
        return '+';
    } else if ( dwell < LEVEL_7 ){
        return '*';
    } else if ( dwell < LEVEL_8 ){
        return '#';
    } else if ( dwell < LEVEL_9 ){
        return '%';
    } else {
        return '@';
    }
}

/**
 This funciton prints the final set, given the users
 parameters for the size.
 
 @param minReal left edge of the set
 @param minImag right edge of the set
 @param size helps calculate the width and height
 */
void drawFigure( double minReal, double minImag, double size )
{
    //nested loops for rows and columns
    long double xMax = minReal + size;
    long double yMax = minImag + size;
    
    long double xInc = size / ( WIDTH - 1 );
    long double yInc = size / ( HEIGHT - 1 );
    
    for ( long double y = yMax; y >= minImag - yInc/2; y -= yInc ){
        //print row
        for ( long double x = minReal; x <= xMax + xInc/2; x += xInc ){
            //printf( "%c", dwellSymbol( testPoint(minReal, minImag) ) );
            putchar(dwellSymbol(testPoint(x, y)));
        }
        putchar('\n');
    }
}

/**
 Helper function to check that the inputs were properly
 parsed as doubles.
 
 @param matches Integer value from scanf
 */
void checkInputs( int check )
{
    if ( check == 1 ){
        return;
    } else {
        printf( "Invalid input\n" );
    }
    exit(EXIT_FAILURE);
}

/**
 Starting point of the program. It takes the users input
 and passes it to the other functions.
 */
int main()
{
    double minReal;
    double minImag;
    double size;
    
    printf( "Minimum real: ");
    int check1 = scanf( "%lf", &minReal );
    checkInputs( check1 );
    
    printf( "Minimum imaginary: ");
    int check2 = scanf( "%lf", &minImag );
    checkInputs( check2 );
    
    printf( "Size: ");
    int check3 = scanf( "%lf", &size );
    checkInputs( check3 );
    
    drawFigure( minReal, minImag, size );
    
    return 0;
    
}
