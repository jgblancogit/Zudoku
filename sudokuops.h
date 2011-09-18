#include <stdio.h>
#include "framework.h"

#define MAXSOLVED 80

typedef struct _fill fill;
struct _fill
{
	int index;
	int n;
};

int solved ( mini_square * );
int square_find ( mini_square *, int, int *, int * );

void square_remove ( mini_square *, int , int );
void column_remove ( mini_square *, int, int );
void row_remove ( mini_square *, int, int );

int square_occurences ( mini_square *, int, int, int * );
int square_isolated ( mini_square *, int , int * );

int column_occurences ( mini_square *, int, int, int * );
int column_isolated ( mini_square *, int, int * );

int row_occurences ( mini_square *, int, int, int * );
int column_isolated ( mini_square *, int, int * );

void sudoku_clean ( mini_square * );
void squares_clean ( mini_square * );
void columns_clean ( mini_square * );
void rows_clean ( mini_square * );

mini_square * sudoku_cons ( fill [], int );
mini_square * sudoku_cons_from_file ( char * );
void sudoku_print ( mini_square * );
void sudoku_print_in_file ( mini_square *, char * );

void sudoku_solve_from_file ( char *, char * );
