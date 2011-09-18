#include <stdio.h>
#include <stdlib.h>

typedef struct _list list;
struct _list
{
	int n;
	list *next;
};

typedef struct _header header;
struct _header
{
	int length;
	int from_square;
	int from_column;
	int from_row;
};

typedef struct _mini_square mini_square;
struct _mini_square
{
	header info;
	list *first;
};

mini_square * mini_square_cons ( mini_square * );
mini_square * mini_square_cons_filled ( mini_square *, int );

void mini_square_remove ( mini_square *, int );

void mini_square_fill ( mini_square *, int, int );

int has_no ( mini_square *, int );